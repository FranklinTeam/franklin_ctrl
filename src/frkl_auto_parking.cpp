#define _USE_MATH_DEFINES

#include <string>
#include <std_msgs/String.h>
#include <std_msgs/Float32.h>
#include <ros/ros.h>
#include <tf/tf.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Pose2D.h>
#include <nav_msgs/Odometry.h>
#include <turtlebot3_msgs/Sound.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <std_msgs/Bool.h>
#include <franklin/Camera.h>

ros::Publisher cmd_pub;
ros::Publisher info_pub;
ros::Publisher sound_pub;

double targetX = 1;
double targetY = 1;
double targetZ = 0;

double realX = 0;
double realY = 0;
double realZ = 0;

double initX = 0;
double initY = 0;
double initZ = 0;

double angleZ = 0.45;

int ids;
float MarksX = 0.0;
float MarksY = 0.0;
float MarksZ = 0.0;

double BURGER_MAX_LIN_VEL = 0.22; //double BURGER_MAX_LIN_VEL = 0.22;
double BURGER_MAX_ANG_VEL = 1.5; //double BURGER_MAX_ANG_VEL = 2.84;
double LIN_VEL_STEP_SIZE = 0.01;
double ANG_VEL_STEP_SIZE = 0.1;

float angular_speed = 1;
float linear_speed = 1;

const double PI = 3.14159265358979323846;

bool working = false;
bool find_marker = false;
int state = 0;
double initial_path_distance = 1;

void pubPercentage(float value){
  std_msgs::Float32 msg;
  msg.data = value;
  info_pub.publish(msg);
}

void stop_Callback(const std_msgs::Bool b){
  if(b.data){
    working = false;
    geometry_msgs::Twist twist;
    twist.angular.z = 0;
    twist.linear.x = 0;
    cmd_pub.publish(twist);

    ROS_INFO("EMERG STOP");

    //turtlebot3_msgs::Sound msg;
    //msg.value = 3;
    //sound_pub.publish(msg);
  }else{

  }

}

void park_Callback(const std_msgs::Bool b){
    if(b.data){
	//targetX = MarksX;
    	//targetY = MarksY;
	//targetZ = MarksZ;
	targetX = 1.0;
    	targetY = 1.0;
	targetZ = 0.5;
    //if (Id = 2){
//	targetZ=0.35;
    	initX = realX;
    	initY = realY;
    	initZ = realZ;
    	working = true;
    	state = 0;
    	ros::Rate loop_rate(10);
	//path_distance = sqrt((targetX - posX)*(targetX - posX)  + (targetY - posY)*(targetY - posY));

    	while(working){
           ros::spinOnce();
           if(working){
          	//float posT = realT;
          	//float posX = realX;
          	//float posY = realY;
          	geometry_msgs::Twist twist;

          	if(state == 0){ 
//Détecter s'il y a des obstacles sur la trajectoire du robot
//Déterminer la position du parking et ce mettre dans l'axe.
//Se rendre au parking
			//while(find_marker==false){
				
			//}		
			ROS_INFO("State 0 \n");	
			twist.linear.x= 0;		 
			twist.angular.z = angular_speed;
			ROS_INFO("z = %0.2f \n, realZ");
		
            		if(std::abs(targetZ-realZ) <= 0.4){
              			state = 1;
	      			twist.angular.z = 0;
            		}

          	}else if(state == 1){  //Avancer de x-x' (on avance jusqu'à avoir la longueur)
			ROS_INFO("State 1 \n");	    		
			twist.angular.z = 0;
            		twist.linear.x = linear_speed * std::abs(targetX-realX);
            		twist.linear.x = std::min(twist.linear.x, BURGER_MAX_LIN_VEL);

            		if(std::abs(targetX-realX) <= 0.01){
              			state = 2;
	      			twist.linear.x = 0;
            		}
          	}else if(state == 2){ //Tourner de 45° en fonction de y positif ou négatif
			ROS_INFO("State 2 \n");	    		
			twist.linear.x = 0;
	    		twist.angular.z = angular_speed * ((targetY-realY)/std::abs(targetY-realY));

            		if(std::abs(angleZ+targetZ-realZ) <= 0.01){
              			state = 3;
	      			twist.angular.z = 0;
            		}
	  	}else if(state == 3){ //Avancer de y-y'
			ROS_INFO("State 3 \n");            		
			twist.angular.z = 0;
            		twist.linear.x = linear_speed * std::abs(targetY-realY);
            		twist.linear.x = std::min(twist.linear.x, BURGER_MAX_LIN_VEL);

            		if(std::abs(targetY-realY) <= 0.01){
             			state = 4;
	      			twist.linear.x = 0;
              			working = false;
				find_marker = false;
				ROS_INFO("Fin \n");
            		}
          	}
          	cmd_pub.publish(twist);
           }
           loop_rate.sleep();
  	}
   }else{

   }
}

void odom_Callback(const nav_msgs::Odometry odom){
  /** TODO : CAMERA : get data from frkl_poscalc node**/

    // linear position
    realX = odom.pose.pose.position.x;
    realY = odom.pose.pose.position.y;

    // quaternion to RPY conversion
    tf::Quaternion q(
        odom.pose.pose.orientation.x,
        odom.pose.pose.orientation.y,
        odom.pose.pose.orientation.z,
        odom.pose.pose.orientation.w);
    tf::Matrix3x3 m(q);
    double roll, pitch, yaw;
    m.getRPY(roll, pitch, yaw);

    // angular position
    realZ = yaw;

    //ROS_INFO("LECTURE ODOM \n- %0.2f\n- %0.2f\n- %0.2f", realX, realY, realT);
}

void markers_Callback(const franklin::Camera markers_pos){

    // position markers
    MarksX = markers_pos.x;
    MarksY = markers_pos.y;
    MarksZ = markers_pos.z;

    // markers identity
    ids = markers_pos.identity;

    find_marker = true;

}

int main(int argc, char** argv) {

    ros::init(argc, argv, "frkl_auto_parking");
    ros::NodeHandle n;

    //pubs
    cmd_pub = n.advertise<geometry_msgs::Twist>("cmd_vel", 1);
    info_pub = n.advertise<std_msgs::Float32>("f_info_dest", 1);
    sound_pub = n.advertise<turtlebot3_msgs::Sound>("sound", 1);

    //subs
    ros::Subscriber mark_sub = n.subscribe("markers_pos",1, markers_Callback);
    ros::Subscriber park_sub = n.subscribe("parking", 1, park_Callback);
    ros::Subscriber odom_sub = n.subscribe("odom", 1, odom_Callback);
    ros::Subscriber stop_sub = n.subscribe("destination/stop", 1, stop_Callback);

    ros::spin();

    return 0;
}
