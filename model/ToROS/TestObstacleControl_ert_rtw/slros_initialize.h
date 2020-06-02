#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block TestObstacleControl/Subscribe1
extern SimulinkSubscriber<sensor_msgs::LaserScan, SL_Bus_TestObstacleControl_sensor_msgs_LaserScan> Sub_TestObstacleControl_328;

// For Block TestObstacleControl/Subscribe4
extern SimulinkSubscriber<nav_msgs::Odometry, SL_Bus_TestObstacleControl_nav_msgs_Odometry> Sub_TestObstacleControl_325;

// For Block TestObstacleControl/Publish1
extern SimulinkPublisher<geometry_msgs::Twist, SL_Bus_TestObstacleControl_geometry_msgs_Twist> Pub_TestObstacleControl_309;

void slros_node_init(int argc, char** argv);

#endif
