#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block ObstacleControl/Subscribe
extern SimulinkSubscriber<nav_msgs::Odometry, SL_Bus_ObstacleControl_nav_msgs_Odometry> Sub_ObstacleControl_7;

// For Block ObstacleControl/Subscribe1
extern SimulinkSubscriber<std_msgs::Bool, SL_Bus_ObstacleControl_std_msgs_Bool> Sub_ObstacleControl_196;

// For Block ObstacleControl/Subscribe2
extern SimulinkSubscriber<sensor_msgs::LaserScan, SL_Bus_ObstacleControl_sensor_msgs_LaserScan> Sub_ObstacleControl_208;

// For Block ObstacleControl/Subscribe3
extern SimulinkSubscriber<geometry_msgs::Pose2D, SL_Bus_ObstacleControl_geometry_msgs_Pose2D> Sub_ObstacleControl_61;

// For Block ObstacleControl/Publish
extern SimulinkPublisher<geometry_msgs::Twist, SL_Bus_ObstacleControl_geometry_msgs_Twist> Pub_ObstacleControl_5;

void slros_node_init(int argc, char** argv);

#endif
