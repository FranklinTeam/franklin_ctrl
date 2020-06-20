#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

#include <string>
#include <std_msgs/String.h>
#include <std_msgs/Bool.h>
#include <std_msgs/Int16.h>
#include <franklin/CmdRobot.h>
#include <franklin/PackageRobot.h>

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int STATE = 0;
int const STATE_PARKING = 1;
int const STATE_ATTENTE = 2;
int const STATE_DEPLACEMENT_LIV = 3;
int const STATE_DEPLACEMENT_REC = 4;
int const STATE_LIVRAISON = 5;
int const STATE_RECEPTION = 6;

ros::Publisher pub_to_voisin_1;
ros::Publisher pub_to_voisin_2;
ros::Publisher pub_to_voisin_3;
ros::Publisher pub_to_ctrl;

std::string robot_name;
std::string voisin_name_1;
std::string voisin_name_2;
std::string voisin_name_3;
double foyer_x;
double foyer_y;
double foyer_voisin_1_x;
double foyer_voisin_1_y;
double foyer_voisin_2_x;
double foyer_voisin_2_y;
double foyer_voisin_3_x;
double foyer_voisin_3_y;

bool absolute_dest = false;
double abs_x;
double abs_y;
std::string target_voisin;
bool got_package = false;
bool handshake = false;
int package_id = 0;

void com1_Callback(const std_msgs::Int16 msg){
  if(target_voisin.compare(voisin_name_1) == 0){
    if(msg.data == 1 && STATE == STATE_LIVRAISON){
      std_msgs::Int16 msgBack;
      msgBack.data = 1;
      pub_to_voisin_1.publish(msgBack);
    }else if(msg.data == 1 && STATE == STATE_RECEPTION){
      std_msgs::Int16 msgBack;
      msgBack.data = 2;
      handshake = true;
      pub_to_voisin_1.publish(msgBack);
    }else if(msg.data == 2 && STATE == STATE_LIVRAISON){
      handshake = true;
    }
  }
}
void com2_Callback(const std_msgs::Int16 msg){
  if(target_voisin.compare(voisin_name_2) == 0){
    if(msg.data == 1 && STATE == STATE_LIVRAISON){
      std_msgs::Int16 msgBack;
      msgBack.data = 1;
      pub_to_voisin_2.publish(msgBack);
    }else if(msg.data == 1 && STATE == STATE_RECEPTION){
      std_msgs::Int16 msgBack;
      msgBack.data = 2;
      handshake = true;
      pub_to_voisin_2.publish(msgBack);
    }else if(msg.data == 2 && STATE == STATE_LIVRAISON){
      handshake = true;
    }
  }
}
void com3_Callback(const std_msgs::Int16 msg){
  if(target_voisin.compare(voisin_name_3) == 0){
    if(msg.data == 1 && STATE == STATE_LIVRAISON){
      std_msgs::Int16 msgBack;
      msgBack.data = 1;
      pub_to_voisin_3.publish(msgBack);
    }else if(msg.data == 1 && STATE == STATE_RECEPTION){
      std_msgs::Int16 msgBack;
      msgBack.data = 2;
      handshake = true;
      pub_to_voisin_3.publish(msgBack);
    }else if(msg.data == 2 && STATE == STATE_LIVRAISON){
      handshake = true;
    }
  }
}
void comCtrl_Callback(const franklin::CmdRobot msg){
    bool isReception = msg.reception;
    bool isFromRobot = msg.from_robot;

    //check if get command or give command
    if(isReception){
      STATE = STATE_DEPLACEMENT_REC;
    }else{
      STATE = STATE_DEPLACEMENT_LIV;
    }

    //check if get/give to a robot or to the ground
    if(isFromRobot){
      const char * msg_char = msg.robot_name.c_str();
      std::string str(msg_char);
      target_voisin = msg.robot_name;
      ROS_INFO("callback controleur to robot : (%s)", msg_char);
    }else{
      abs_x = msg.obj_x;
      abs_y = msg.obj_y;
    }
    absolute_dest = !isFromRobot;

}

double calculate_meeting_pointX(std::string voisin_name){
  double foyer_voisin_x;
  if(voisin_name.compare(voisin_name_1) == 0){
    foyer_voisin_x = foyer_voisin_1_x;
  }else if(voisin_name.compare(voisin_name_2) == 0){
    foyer_voisin_x = foyer_voisin_2_x;
  }else if(voisin_name.compare(voisin_name_3) == 0){
    foyer_voisin_x = foyer_voisin_3_x;
  }else{
    foyer_voisin_x = 0;
    ROS_ERROR("Error foyer voisin not found");
  }

  return foyer_voisin_x;
}
double calculate_meeting_pointY(std::string voisin_name){
  double foyer_voisin_y;
  if(voisin_name.compare(voisin_name_1) == 0){
    foyer_voisin_y = foyer_voisin_1_y;
  }else if(voisin_name.compare(voisin_name_2) == 0){
    foyer_voisin_y = foyer_voisin_2_y;
  }else if(voisin_name.compare(voisin_name_3) == 0){
    foyer_voisin_y = foyer_voisin_3_y;
  }else{
    foyer_voisin_y = 0;
    ROS_ERROR("Error foyer voisin not found");
  }

  return foyer_voisin_y;
}

int main(int argc, char** argv){

  ros::init(argc, argv, "frkl_statechart");
  ros::NodeHandle nh("~");

  nh.getParam("robot_name", robot_name);
  nh.getParam("voisin_name_1", voisin_name_1);
  nh.getParam("voisin_name_2", voisin_name_2);
  nh.getParam("voisin_name_3", voisin_name_3);
  nh.getParam("foyer_x", foyer_x);
  nh.getParam("foyer_y", foyer_y);
  nh.getParam("v1_foyer_x", foyer_voisin_1_x);
  nh.getParam("v1_foyer_y", foyer_voisin_1_y);
  nh.getParam("v2_foyer_x", foyer_voisin_2_x);
  nh.getParam("v2_foyer_y", foyer_voisin_2_y);
  nh.getParam("v3_foyer_x", foyer_voisin_3_x);
  nh.getParam("v3_foyer_y", foyer_voisin_3_y);

  ros::Subscriber sub_from_voisin_1 = nh.subscribe("/COM_" + voisin_name_1 + "_to_" + robot_name, 1, com1_Callback);
  ros::Subscriber sub_from_voisin_2 = nh.subscribe("/COM_" + voisin_name_2 + "_to_" + robot_name, 1, com2_Callback);
  ros::Subscriber sub_from_voisin_3 = nh.subscribe("/COM_" + voisin_name_3 + "_to_" + robot_name, 1, com3_Callback);
  ros::Subscriber sub_from_ctrl = nh.subscribe("/COM_ctrl_to_" + robot_name, 1, comCtrl_Callback);

  pub_to_voisin_1 = nh.advertise<std_msgs::Int16>("/COM_" + robot_name + "_to_" + voisin_name_1, 1);
  pub_to_voisin_2 = nh.advertise<std_msgs::Int16>("/COM_" + robot_name + "_to_" + voisin_name_2, 1);
  pub_to_voisin_3 = nh.advertise<std_msgs::Int16>("/COM_" + robot_name + "_to_" + voisin_name_3, 1);
  pub_to_ctrl = nh.advertise<franklin::PackageRobot>("/COM_" + robot_name + "_to_ctrl", 1);

  //tell the action client that we want to spin a thread by default
  MoveBaseClient ac("/" + robot_name + "/move_base", true);

  //wait for the action server to come up
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }

  move_base_msgs::MoveBaseGoal goal;

  //we'll send a goal to the robot to move 1 meter forward
  goal.target_pose.header.frame_id = "/map";
  goal.target_pose.header.stamp = ros::Time::now();

  STATE = STATE_PARKING;

//Boucle infini
  ros::Rate loop_rate(30);

  while(1){
      ros::spinOnce();
      //Pub state to gui controller
      franklin::PackageRobot msg;
      std::stringstream ss;
      switch (STATE) {
        case STATE_PARKING:
          ss << "Parking";
          break;
        case STATE_ATTENTE:
          ss << "Waiting";
          break;
        case STATE_DEPLACEMENT_LIV:
          ss << "Moving to delivery";
          break;
        case STATE_DEPLACEMENT_REC:
          ss << "Moving to reception";
          break;
        case STATE_LIVRAISON:
          ss << "Delivering";
          break;
        case STATE_RECEPTION:
          ss << "Recepting";
          break;
        default:
          ss << "State error !?";
      }
      msg.state = ss.str();
      msg.package = got_package;
      msg.id = package_id;
      pub_to_ctrl.publish(msg);

      //statechart handler
      switch (STATE) {
        case STATE_PARKING:
          goal.target_pose.pose.position.x = foyer_x;
          goal.target_pose.pose.position.y = foyer_y;
          goal.target_pose.pose.orientation.w = 1;

          ROS_INFO("Returning to Foyer");
          ac.sendGoal(goal);
          ac.waitForResult();

          if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
            ROS_INFO("FOYER OK");
            STATE = STATE_ATTENTE;
          }else{
            ROS_INFO("ERROR, NOT IN FOYER");
            STATE = STATE_PARKING;
          }
          break;

        case STATE_DEPLACEMENT_LIV:
          if(absolute_dest){
            goal.target_pose.pose.position.x = abs_x;
            goal.target_pose.pose.position.y = abs_y;
            goal.target_pose.pose.orientation.w = 1;

            ROS_INFO("Delivery to a specific position");
            ac.sendGoal(goal);
            ac.waitForResult();

            if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
              ROS_INFO("Delivered !");
              got_package = false;
              package_id = 0;
              STATE = STATE_PARKING;
            }else{
              ROS_INFO("ERROR, NOT IN SPECIFIC POSITION");
            }
          }else{
            double sx = calculate_meeting_pointX(target_voisin);
            double sy = calculate_meeting_pointY(target_voisin);

            ROS_ERROR("POS x : %lf, POS y : %lf", sx, sy);

            goal.target_pose.pose.position.x = sx;
            goal.target_pose.pose.position.y = sy;
            goal.target_pose.pose.orientation.w = 1;

            ROS_INFO("Delivery to (robot)");
            ac.sendGoal(goal);
            ac.waitForResult();

            if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
              ROS_INFO("Arrived !");
              STATE = STATE_LIVRAISON;
            }else{
              ROS_INFO("ERROR, NOT IN SPECIFIC POSITION");
            }
          }
          break;
        case STATE_DEPLACEMENT_REC:
          if(absolute_dest){
            goal.target_pose.pose.position.x = abs_x;
            goal.target_pose.pose.position.y = abs_y;
            goal.target_pose.pose.orientation.w = 1;

            ROS_INFO("Reception to a specific position");
            ac.sendGoal(goal);
            ac.waitForResult();

            if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
              ROS_INFO("Recepted !");
              got_package = true;
              STATE = STATE_PARKING;
            }else{
              ROS_INFO("ERROR, NOT IN SPECIFIC POSITION");
            }
          }else{
            double sx = calculate_meeting_pointX(target_voisin);
            double sy = calculate_meeting_pointY(target_voisin);

            ROS_ERROR("POS x : %lf, POS y : %lf", sx, sy);

            goal.target_pose.pose.position.x = sx;
            goal.target_pose.pose.position.y = sy;
            goal.target_pose.pose.orientation.w = 1;

            ROS_INFO("Reception to (robot)");
            ac.sendGoal(goal);
            ac.waitForResult();

            if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
              ROS_INFO("Arrived !");
              STATE = STATE_RECEPTION;
            }else{
              ROS_INFO("ERROR, NOT IN SPECIFIC POSITION");
            }
          }
          break;
        case STATE_LIVRAISON:
          if(handshake){
            got_package = false;
            STATE = STATE_PARKING;
            handshake = false;
          }
          break;
        case STATE_RECEPTION:
          if(handshake){
            got_package = true;
            STATE = STATE_PARKING;
            handshake = false;
          }else{
            std_msgs::Int16 msg3w;
            msg3w.data = 1;
            if(target_voisin.compare(voisin_name_1) == 0){
              pub_to_voisin_1.publish(msg3w);
            }else if(target_voisin.compare(voisin_name_2) == 0){
              pub_to_voisin_2.publish(msg3w);
            }else if(target_voisin.compare(voisin_name_3) == 0){
              pub_to_voisin_3.publish(msg3w);
            }
          }
          break;
        case STATE_ATTENTE:
          break;
      }

      loop_rate.sleep();
  }

  return 0;
}
