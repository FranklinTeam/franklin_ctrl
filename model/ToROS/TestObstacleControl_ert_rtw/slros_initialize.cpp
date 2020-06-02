#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "TestObstacleControl";

// For Block TestObstacleControl/Subscribe1
SimulinkSubscriber<sensor_msgs::LaserScan, SL_Bus_TestObstacleControl_sensor_msgs_LaserScan> Sub_TestObstacleControl_328;

// For Block TestObstacleControl/Subscribe4
SimulinkSubscriber<nav_msgs::Odometry, SL_Bus_TestObstacleControl_nav_msgs_Odometry> Sub_TestObstacleControl_325;

// For Block TestObstacleControl/Publish1
SimulinkPublisher<geometry_msgs::Twist, SL_Bus_TestObstacleControl_geometry_msgs_Twist> Pub_TestObstacleControl_309;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

