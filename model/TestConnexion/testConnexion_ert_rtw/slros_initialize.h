#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block testConnexion/Publish
extern SimulinkPublisher<geometry_msgs::Point, SL_Bus_testConnexion_geometry_msgs_Point> Pub_testConnexion_2;

void slros_node_init(int argc, char** argv);

#endif
