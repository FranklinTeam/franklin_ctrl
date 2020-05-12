//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: DestinationControl_types.h
//
// Code generated for Simulink model 'DestinationControl'.
//
// Model version                  : 1.4
// Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
// C/C++ source code generated on : Thu May  7 15:42:08 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_DestinationControl_types_h_
#define RTW_HEADER_DestinationControl_types_h_
#include "rtwtypes.h"

// Model Code Variants
#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_DestinationControl_geometry_msgs_Vector3_
#define DEFINED_TYPEDEF_FOR_SL_Bus_DestinationControl_geometry_msgs_Vector3_

// MsgType=geometry_msgs/Vector3
typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
} SL_Bus_DestinationControl_geometry_msgs_Vector3;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_DestinationControl_geometry_msgs_Twist_
#define DEFINED_TYPEDEF_FOR_SL_Bus_DestinationControl_geometry_msgs_Twist_

// MsgType=geometry_msgs/Twist
typedef struct {
  // MsgType=geometry_msgs/Vector3
  SL_Bus_DestinationControl_geometry_msgs_Vector3 Linear;

  // MsgType=geometry_msgs/Vector3
  SL_Bus_DestinationControl_geometry_msgs_Vector3 Angular;
} SL_Bus_DestinationControl_geometry_msgs_Twist;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_

typedef struct {
  uint32_T CurrentLength;
  uint32_T ReceivedLength;
} SL_Bus_ROSVariableLengthArrayInfo;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_DestinationControl_ros_time_Time_
#define DEFINED_TYPEDEF_FOR_SL_Bus_DestinationControl_ros_time_Time_

// MsgType=ros_time/Time
typedef struct {
  real_T Sec;
  real_T Nsec;
} SL_Bus_DestinationControl_ros_time_Time;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_DestinationControl_std_msgs_Header_
#define DEFINED_TYPEDEF_FOR_SL_Bus_DestinationControl_std_msgs_Header_

// MsgType=std_msgs/Header
typedef struct {
  uint32_T Seq;

  // PrimitiveROSType=string:IsVarLen=1:VarLenCategory=data:VarLenElem=FrameId_SL_Info:TruncateAction=warn 
  uint8_T FrameId[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=FrameId
  SL_Bus_ROSVariableLengthArrayInfo FrameId_SL_Info;

  // MsgType=ros_time/Time
  SL_Bus_DestinationControl_ros_time_Time Stamp;
} SL_Bus_DestinationControl_std_msgs_Header;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_DestinationControl_geometry_msgs_Point_
#define DEFINED_TYPEDEF_FOR_SL_Bus_DestinationControl_geometry_msgs_Point_

// MsgType=geometry_msgs/Point
typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
} SL_Bus_DestinationControl_geometry_msgs_Point;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_DestinationControl_geometry_msgs_Quaternion_
#define DEFINED_TYPEDEF_FOR_SL_Bus_DestinationControl_geometry_msgs_Quaternion_

// MsgType=geometry_msgs/Quaternion
typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
  real_T W;
} SL_Bus_DestinationControl_geometry_msgs_Quaternion;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_DestinationControl_geometry_msgs_Pose_
#define DEFINED_TYPEDEF_FOR_SL_Bus_DestinationControl_geometry_msgs_Pose_

// MsgType=geometry_msgs/Pose
typedef struct {
  // MsgType=geometry_msgs/Point
  SL_Bus_DestinationControl_geometry_msgs_Point Position;

  // MsgType=geometry_msgs/Quaternion
  SL_Bus_DestinationControl_geometry_msgs_Quaternion Orientation;
} SL_Bus_DestinationControl_geometry_msgs_Pose;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_DestinationControl_geometry_msgs_PoseWithCovariance_
#define DEFINED_TYPEDEF_FOR_SL_Bus_DestinationControl_geometry_msgs_PoseWithCovariance_

// MsgType=geometry_msgs/PoseWithCovariance
typedef struct {
  real_T Covariance[36];

  // MsgType=geometry_msgs/Pose
  SL_Bus_DestinationControl_geometry_msgs_Pose Pose;
} SL_Bus_DestinationControl_geometry_msgs_PoseWithCovariance;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_DestinationControl_geometry_msgs_TwistWithCovariance_
#define DEFINED_TYPEDEF_FOR_SL_Bus_DestinationControl_geometry_msgs_TwistWithCovariance_

// MsgType=geometry_msgs/TwistWithCovariance
typedef struct {
  real_T Covariance[36];

  // MsgType=geometry_msgs/Twist
  SL_Bus_DestinationControl_geometry_msgs_Twist Twist;
} SL_Bus_DestinationControl_geometry_msgs_TwistWithCovariance;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_DestinationControl_nav_msgs_Odometry_
#define DEFINED_TYPEDEF_FOR_SL_Bus_DestinationControl_nav_msgs_Odometry_

// MsgType=nav_msgs/Odometry
typedef struct {
  // PrimitiveROSType=string:IsVarLen=1:VarLenCategory=data:VarLenElem=ChildFrameId_SL_Info:TruncateAction=warn 
  uint8_T ChildFrameId[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=ChildFrameId
  SL_Bus_ROSVariableLengthArrayInfo ChildFrameId_SL_Info;

  // MsgType=std_msgs/Header
  SL_Bus_DestinationControl_std_msgs_Header Header;

  // MsgType=geometry_msgs/PoseWithCovariance
  SL_Bus_DestinationControl_geometry_msgs_PoseWithCovariance Pose;

  // MsgType=geometry_msgs/TwistWithCovariance
  SL_Bus_DestinationControl_geometry_msgs_TwistWithCovariance Twist;
} SL_Bus_DestinationControl_nav_msgs_Odometry;

#endif

#ifndef struct_tag_rkSooZHJZnr3Dpfu1LNqfH
#define struct_tag_rkSooZHJZnr3Dpfu1LNqfH

struct tag_rkSooZHJZnr3Dpfu1LNqfH
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                 //struct_tag_rkSooZHJZnr3Dpfu1LNqfH

#ifndef typedef_ros_slros_internal_block_Publ_T
#define typedef_ros_slros_internal_block_Publ_T

typedef struct tag_rkSooZHJZnr3Dpfu1LNqfH ros_slros_internal_block_Publ_T;

#endif                                 //typedef_ros_slros_internal_block_Publ_T

#ifndef struct_tag_9SewJ4y3IXNs5GrZti8qkG
#define struct_tag_9SewJ4y3IXNs5GrZti8qkG

struct tag_9SewJ4y3IXNs5GrZti8qkG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                 //struct_tag_9SewJ4y3IXNs5GrZti8qkG

#ifndef typedef_ros_slros_internal_block_Subs_T
#define typedef_ros_slros_internal_block_Subs_T

typedef struct tag_9SewJ4y3IXNs5GrZti8qkG ros_slros_internal_block_Subs_T;

#endif                                 //typedef_ros_slros_internal_block_Subs_T

#ifndef struct_tag_PMfBDzoakfdM9QAdfx2o6D
#define struct_tag_PMfBDzoakfdM9QAdfx2o6D

struct tag_PMfBDzoakfdM9QAdfx2o6D
{
  uint32_T f1[8];
};

#endif                                 //struct_tag_PMfBDzoakfdM9QAdfx2o6D

#ifndef typedef_cell_wrap_DestinationControl_T
#define typedef_cell_wrap_DestinationControl_T

typedef struct tag_PMfBDzoakfdM9QAdfx2o6D cell_wrap_DestinationControl_T;

#endif                                 //typedef_cell_wrap_DestinationControl_T

#ifndef struct_tag_wijVd1pZoObdN5hSCcVtcH
#define struct_tag_wijVd1pZoObdN5hSCcVtcH

struct tag_wijVd1pZoObdN5hSCcVtcH
{
  int32_T isInitialized;
  cell_wrap_DestinationControl_T inputVarSize[2];
  real_T MaxAngularVelocity;
  real_T LookaheadDistance;
  real_T DesiredLinearVelocity;
  real_T ProjectionPoint[2];
  real_T ProjectionLineIndex;
  real_T LookaheadPoint[2];
  real_T LastPose[3];
  real_T WaypointsInternal[6];
};

#endif                                 //struct_tag_wijVd1pZoObdN5hSCcVtcH

#ifndef typedef_nav_slalgs_internal_PurePursu_T
#define typedef_nav_slalgs_internal_PurePursu_T

typedef struct tag_wijVd1pZoObdN5hSCcVtcH nav_slalgs_internal_PurePursu_T;

#endif                                 //typedef_nav_slalgs_internal_PurePursu_T

// Parameters (default storage)
typedef struct P_DestinationControl_T_ P_DestinationControl_T;

// Forward declaration for rtModel
typedef struct tag_RTM_DestinationControl_T RT_MODEL_DestinationControl_T;

#endif                                // RTW_HEADER_DestinationControl_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
