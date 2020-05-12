#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "testConnexion";

// For Block testConnexion/Publish
SimulinkPublisher<geometry_msgs::Point, SL_Bus_testConnexion_geometry_msgs_Point> Pub_testConnexion_2;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

