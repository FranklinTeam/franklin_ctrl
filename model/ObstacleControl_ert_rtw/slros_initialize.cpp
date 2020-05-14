#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "ObstacleControl";

// For Block ObstacleControl/Subscribe
SimulinkSubscriber<nav_msgs::Odometry, SL_Bus_ObstacleControl_nav_msgs_Odometry> Sub_ObstacleControl_7;

// For Block ObstacleControl/Subscribe1
SimulinkSubscriber<std_msgs::Bool, SL_Bus_ObstacleControl_std_msgs_Bool> Sub_ObstacleControl_196;

// For Block ObstacleControl/Subscribe2
SimulinkSubscriber<sensor_msgs::LaserScan, SL_Bus_ObstacleControl_sensor_msgs_LaserScan> Sub_ObstacleControl_208;

// For Block ObstacleControl/Subscribe3
SimulinkSubscriber<geometry_msgs::Pose2D, SL_Bus_ObstacleControl_geometry_msgs_Pose2D> Sub_ObstacleControl_61;

// For Block ObstacleControl/Publish
SimulinkPublisher<geometry_msgs::Twist, SL_Bus_ObstacleControl_geometry_msgs_Twist> Pub_ObstacleControl_5;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

