#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block DestinationControl/Subscribe
extern SimulinkSubscriber<nav_msgs::Odometry, SL_Bus_DestinationControl_nav_msgs_Odometry> Sub_DestinationControl_7;

// For Block DestinationControl/Subscribe3
extern SimulinkSubscriber<geometry_msgs::Pose2D, SL_Bus_DestinationControl_geometry_msgs_Pose2D> Sub_DestinationControl_61;

// For Block DestinationControl/Publish
extern SimulinkPublisher<geometry_msgs::Twist, SL_Bus_DestinationControl_geometry_msgs_Twist> Pub_DestinationControl_5;

void slros_node_init(int argc, char** argv);

#endif
