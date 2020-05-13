#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "DestinationControl";

// For Block DestinationControl/Subscribe
SimulinkSubscriber<nav_msgs::Odometry, SL_Bus_DestinationControl_nav_msgs_Odometry> Sub_DestinationControl_7;

// For Block DestinationControl/Subscribe1
SimulinkSubscriber<std_msgs::Bool, SL_Bus_DestinationControl_std_msgs_Bool> Sub_DestinationControl_196;

// For Block DestinationControl/Subscribe3
SimulinkSubscriber<geometry_msgs::Pose2D, SL_Bus_DestinationControl_geometry_msgs_Pose2D> Sub_DestinationControl_61;

// For Block DestinationControl/Publish
SimulinkPublisher<geometry_msgs::Twist, SL_Bus_DestinationControl_geometry_msgs_Twist> Pub_DestinationControl_5;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

