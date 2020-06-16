#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

#include <string>
#include <std_msgs/String.h>
#include <std_msgs/Bool.h>

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int STATE = 0;
int STATE_PARKING = 1;
int STATE_ATTENTE = 2;
int STATE_DEPLACEMENT = 3;
int STATE_LIVRAISON = 4;
int STATE_RECEPTION = 5;

ros::Publisher pub_to_voisin_1;
ros::Publisher pub_to_voisin_2;
ros::Publisher pub_to_voisin_3;
ros::Publisher pub_to_ctrl;

void com1_Callback(const std_msgs::String msg){
    const char * msg_char = msg.data.c_str();
    std::string str(msg_char);

    ROS_INFO("callback (%s)", msg_char);

}
void com2_Callback(const std_msgs::String msg){
    const char * msg_char = msg.data.c_str();
    std::string str(msg_char);

    ROS_INFO("callback (%s)", msg_char);

}
void com3_Callback(const std_msgs::String msg){
    const char * msg_char = msg.data.c_str();
    std::string str(msg_char);

    ROS_INFO("callback (%s)", msg_char);

}
void comCtrl_Callback(const std_msgs::String msg){
    const char * msg_char = msg.data.c_str();
    std::string str(msg_char);

    ROS_INFO("callback (%s)", msg_char);

}

int main(int argc, char** argv){

  ros::init(argc, argv, "frkl_statechart");
  ros::NodeHandle nh("~");

  std::string robot_name;
  std::string voisin_name_1;
  std::string voisin_name_2;
  std::string voisin_name_3;
  int foyer_x;
  int foyer_y;

  nh.getParam("robot_name", robot_name);
  nh.getParam("voisin_name_1", voisin_name_1);
  nh.getParam("voisin_name_2", voisin_name_2);
  nh.getParam("voisin_name_3", voisin_name_3);
  nh.getParam("foyer_x", foyer_x);
  nh.getParam("foyer_y", foyer_y);

  ros::Subscriber sub_from_voisin_1 = nh.subscribe("/COM_" + voisin_name_1 + "_to_" + robot_name, 1, com1_Callback);
  ros::Subscriber sub_from_voisin_2 = nh.subscribe("/COM_" + voisin_name_2 + "_to_" + robot_name, 1, com2_Callback);
  ros::Subscriber sub_from_voisin_3 = nh.subscribe("/COM_" + voisin_name_3 + "_to_" + robot_name, 1, com3_Callback);
  ros::Subscriber sub_from_ctrl = nh.subscribe("/COM_ctrl_to_" + robot_name, 1, comCtrl_Callback);

  pub_to_voisin_1 = nh.advertise<std_msgs::Bool>("/COM_" + robot_name + "_to_" + voisin_name_1, 1);
  pub_to_voisin_2 = nh.advertise<std_msgs::Bool>("/COM_" + robot_name + "_to_" + voisin_name_2, 1);
  pub_to_voisin_3 = nh.advertise<std_msgs::Bool>("/COM_" + robot_name + "_to_" + voisin_name_3, 1);
  pub_to_ctrl = nh.advertise<std_msgs::Bool>("/COM_" + robot_name + "_to_ctrl", 1);

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

  goal.target_pose.pose.position.x = foyer_x;
  goal.target_pose.pose.position.y = foyer_y;
  goal.target_pose.pose.orientation.w = 1.0;

  ROS_INFO("Sending goal");
  ac.sendGoal(goal);

  ac.waitForResult();

  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("Hooray, the base moved 1 meter forward");
  else
    ROS_INFO("The base failed to move forward 1 meter for some reason");


//Boucle infini
  ros::Rate loop_rate(30);

  while(1){
      ros::spinOnce();
      loop_rate.sleep();
  }

  return 0;
}
