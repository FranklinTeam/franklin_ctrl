//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ObstacleControl_types.h
//
// Code generated for Simulink model 'ObstacleControl'.
//
// Model version                  : 1.22
// Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
// C/C++ source code generated on : Wed May 20 14:25:19 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_ObstacleControl_types_h_
#define RTW_HEADER_ObstacleControl_types_h_
#include "rtwtypes.h"

// Model Code Variants
#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ObstacleControl_geometry_msgs_Vector3_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ObstacleControl_geometry_msgs_Vector3_

// MsgType=geometry_msgs/Vector3
typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
} SL_Bus_ObstacleControl_geometry_msgs_Vector3;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ObstacleControl_geometry_msgs_Twist_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ObstacleControl_geometry_msgs_Twist_

// MsgType=geometry_msgs/Twist
typedef struct {
  // MsgType=geometry_msgs/Vector3
  SL_Bus_ObstacleControl_geometry_msgs_Vector3 Linear;

  // MsgType=geometry_msgs/Vector3
  SL_Bus_ObstacleControl_geometry_msgs_Vector3 Angular;
} SL_Bus_ObstacleControl_geometry_msgs_Twist;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_

typedef struct {
  uint32_T CurrentLength;
  uint32_T ReceivedLength;
} SL_Bus_ROSVariableLengthArrayInfo;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ObstacleControl_ros_time_Time_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ObstacleControl_ros_time_Time_

// MsgType=ros_time/Time
typedef struct {
  real_T Sec;
  real_T Nsec;
} SL_Bus_ObstacleControl_ros_time_Time;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ObstacleControl_std_msgs_Header_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ObstacleControl_std_msgs_Header_

// MsgType=std_msgs/Header
typedef struct {
  uint32_T Seq;

  // PrimitiveROSType=string:IsVarLen=1:VarLenCategory=data:VarLenElem=FrameId_SL_Info:TruncateAction=warn 
  uint8_T FrameId[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=FrameId
  SL_Bus_ROSVariableLengthArrayInfo FrameId_SL_Info;

  // MsgType=ros_time/Time
  SL_Bus_ObstacleControl_ros_time_Time Stamp;
} SL_Bus_ObstacleControl_std_msgs_Header;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ObstacleControl_geometry_msgs_Point_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ObstacleControl_geometry_msgs_Point_

// MsgType=geometry_msgs/Point
typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
} SL_Bus_ObstacleControl_geometry_msgs_Point;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ObstacleControl_geometry_msgs_Quaternion_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ObstacleControl_geometry_msgs_Quaternion_

// MsgType=geometry_msgs/Quaternion
typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
  real_T W;
} SL_Bus_ObstacleControl_geometry_msgs_Quaternion;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ObstacleControl_geometry_msgs_Pose_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ObstacleControl_geometry_msgs_Pose_

// MsgType=geometry_msgs/Pose
typedef struct {
  // MsgType=geometry_msgs/Point
  SL_Bus_ObstacleControl_geometry_msgs_Point Position;

  // MsgType=geometry_msgs/Quaternion
  SL_Bus_ObstacleControl_geometry_msgs_Quaternion Orientation;
} SL_Bus_ObstacleControl_geometry_msgs_Pose;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ObstacleControl_geometry_msgs_PoseWithCovariance_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ObstacleControl_geometry_msgs_PoseWithCovariance_

// MsgType=geometry_msgs/PoseWithCovariance
typedef struct {
  real_T Covariance[36];

  // MsgType=geometry_msgs/Pose
  SL_Bus_ObstacleControl_geometry_msgs_Pose Pose;
} SL_Bus_ObstacleControl_geometry_msgs_PoseWithCovariance;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ObstacleControl_geometry_msgs_TwistWithCovariance_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ObstacleControl_geometry_msgs_TwistWithCovariance_

// MsgType=geometry_msgs/TwistWithCovariance
typedef struct {
  real_T Covariance[36];

  // MsgType=geometry_msgs/Twist
  SL_Bus_ObstacleControl_geometry_msgs_Twist Twist;
} SL_Bus_ObstacleControl_geometry_msgs_TwistWithCovariance;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ObstacleControl_nav_msgs_Odometry_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ObstacleControl_nav_msgs_Odometry_

// MsgType=nav_msgs/Odometry
typedef struct {
  // PrimitiveROSType=string:IsVarLen=1:VarLenCategory=data:VarLenElem=ChildFrameId_SL_Info:TruncateAction=warn 
  uint8_T ChildFrameId[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=ChildFrameId
  SL_Bus_ROSVariableLengthArrayInfo ChildFrameId_SL_Info;

  // MsgType=std_msgs/Header
  SL_Bus_ObstacleControl_std_msgs_Header Header;

  // MsgType=geometry_msgs/PoseWithCovariance
  SL_Bus_ObstacleControl_geometry_msgs_PoseWithCovariance Pose;

  // MsgType=geometry_msgs/TwistWithCovariance
  SL_Bus_ObstacleControl_geometry_msgs_TwistWithCovariance Twist;
} SL_Bus_ObstacleControl_nav_msgs_Odometry;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ObstacleControl_std_msgs_Bool_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ObstacleControl_std_msgs_Bool_

// MsgType=std_msgs/Bool
typedef struct {
  boolean_T Data;
} SL_Bus_ObstacleControl_std_msgs_Bool;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ObstacleControl_sensor_msgs_LaserScan_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ObstacleControl_sensor_msgs_LaserScan_

// MsgType=sensor_msgs/LaserScan
typedef struct {
  real32_T AngleMin;
  real32_T AngleMax;
  real32_T AngleIncrement;
  real32_T TimeIncrement;
  real32_T ScanTime;
  real32_T RangeMin;
  real32_T RangeMax;

  // IsVarLen=1:VarLenCategory=data:VarLenElem=Ranges_SL_Info:TruncateAction=warn 
  real32_T Ranges[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=Ranges
  SL_Bus_ROSVariableLengthArrayInfo Ranges_SL_Info;

  // IsVarLen=1:VarLenCategory=data:VarLenElem=Intensities_SL_Info:TruncateAction=warn 
  real32_T Intensities[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=Intensities
  SL_Bus_ROSVariableLengthArrayInfo Intensities_SL_Info;

  // MsgType=std_msgs/Header
  SL_Bus_ObstacleControl_std_msgs_Header Header;
} SL_Bus_ObstacleControl_sensor_msgs_LaserScan;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ObstacleControl_geometry_msgs_Pose2D_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ObstacleControl_geometry_msgs_Pose2D_

// MsgType=geometry_msgs/Pose2D
typedef struct {
  real_T X;
  real_T Y;
  real_T Theta;
} SL_Bus_ObstacleControl_geometry_msgs_Pose2D;

#endif

#ifndef struct_tag_vxHWSOYrO9xtYchIOe7EKG
#define struct_tag_vxHWSOYrO9xtYchIOe7EKG

struct tag_vxHWSOYrO9xtYchIOe7EKG
{
  int32_T isInitialized;
};

#endif                                 //struct_tag_vxHWSOYrO9xtYchIOe7EKG

#ifndef typedef_robotics_slcore_internal_bloc_T
#define typedef_robotics_slcore_internal_bloc_T

typedef struct tag_vxHWSOYrO9xtYchIOe7EKG robotics_slcore_internal_bloc_T;

#endif                                 //typedef_robotics_slcore_internal_bloc_T

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

#ifndef struct_emxArray_real_T_180x1
#define struct_emxArray_real_T_180x1

struct emxArray_real_T_180x1
{
  real_T data[180];
  int32_T size[2];
};

#endif                                 //struct_emxArray_real_T_180x1

#ifndef typedef_emxArray_real_T_180x1_Obstacl_T
#define typedef_emxArray_real_T_180x1_Obstacl_T

typedef struct emxArray_real_T_180x1 emxArray_real_T_180x1_Obstacl_T;

#endif                                 //typedef_emxArray_real_T_180x1_Obstacl_T

#ifndef struct_emxArray_real32_T_180x1
#define struct_emxArray_real32_T_180x1

struct emxArray_real32_T_180x1
{
  real32_T data[180];
  int32_T size[2];
};

#endif                                 //struct_emxArray_real32_T_180x1

#ifndef typedef_emxArray_real32_T_180x1_Obsta_T
#define typedef_emxArray_real32_T_180x1_Obsta_T

typedef struct emxArray_real32_T_180x1 emxArray_real32_T_180x1_Obsta_T;

#endif                                 //typedef_emxArray_real32_T_180x1_Obsta_T

#ifndef struct_tag_PMfBDzoakfdM9QAdfx2o6D
#define struct_tag_PMfBDzoakfdM9QAdfx2o6D

struct tag_PMfBDzoakfdM9QAdfx2o6D
{
  uint32_T f1[8];
};

#endif                                 //struct_tag_PMfBDzoakfdM9QAdfx2o6D

#ifndef typedef_cell_wrap_ObstacleControl_T
#define typedef_cell_wrap_ObstacleControl_T

typedef struct tag_PMfBDzoakfdM9QAdfx2o6D cell_wrap_ObstacleControl_T;

#endif                                 //typedef_cell_wrap_ObstacleControl_T

#ifndef struct_tag_zBOhIRcmHpKCxB9N10gIf
#define struct_tag_zBOhIRcmHpKCxB9N10gIf

struct tag_zBOhIRcmHpKCxB9N10gIf
{
  real32_T f1[2];
};

#endif                                 //struct_tag_zBOhIRcmHpKCxB9N10gIf

#ifndef typedef_d_cell_wrap_ObstacleControl_T
#define typedef_d_cell_wrap_ObstacleControl_T

typedef struct tag_zBOhIRcmHpKCxB9N10gIf d_cell_wrap_ObstacleControl_T;

#endif                                 //typedef_d_cell_wrap_ObstacleControl_T

#ifndef struct_tag_nSkGirwcn0SPvHvZ5ch93C
#define struct_tag_nSkGirwcn0SPvHvZ5ch93C

struct tag_nSkGirwcn0SPvHvZ5ch93C
{
  int32_T isInitialized;
  cell_wrap_ObstacleControl_T inputVarSize[3];
  boolean_T CacheInputSizes;
  real_T NarrowOpeningThreshold;
  real_T DistanceLimits[2];
  real_T RobotRadius;
  real_T SafetyDistance;
  real_T MinTurningRadius;
  real_T TargetDirectionWeight;
  real_T CurrentDirectionWeight;
  real_T PreviousDirectionWeight;
  real_T HistogramThresholds[2];
  real32_T PolarObstacleDensity[36];
  boolean_T BinaryHistogram[36];
  boolean_T MaskedHistogram[36];
  real32_T PreviousDirection;
  real32_T AngularSectorMidPoints[36];
  real32_T AngularDifference;
  real32_T AngularSectorStartPoints[36];
  real_T AngularLimits[2];
};

#endif                                 //struct_tag_nSkGirwcn0SPvHvZ5ch93C

#ifndef typedef_nav_slalgs_internal_VectorFie_T
#define typedef_nav_slalgs_internal_VectorFie_T

typedef struct tag_nSkGirwcn0SPvHvZ5ch93C nav_slalgs_internal_VectorFie_T;

#endif                                 //typedef_nav_slalgs_internal_VectorFie_T

#ifndef struct_tag_8vhy7GD0X9BqGBwplXl5nC
#define struct_tag_8vhy7GD0X9BqGBwplXl5nC

struct tag_8vhy7GD0X9BqGBwplXl5nC
{
  int32_T isInitialized;
  cell_wrap_ObstacleControl_T inputVarSize[2];
  real_T MaxAngularVelocity;
  real_T LookaheadDistance;
  real_T DesiredLinearVelocity;
  real_T ProjectionPoint[2];
  real_T ProjectionLineIndex;
  real_T LookaheadPoint[2];
  real_T LastPose[3];
  real_T WaypointsInternal[4];
};

#endif                                 //struct_tag_8vhy7GD0X9BqGBwplXl5nC

#ifndef typedef_nav_slalgs_internal_PurePursu_T
#define typedef_nav_slalgs_internal_PurePursu_T

typedef struct tag_8vhy7GD0X9BqGBwplXl5nC nav_slalgs_internal_PurePursu_T;

#endif                                 //typedef_nav_slalgs_internal_PurePursu_T

// Parameters (default storage)
typedef struct P_ObstacleControl_T_ P_ObstacleControl_T;

// Forward declaration for rtModel
typedef struct tag_RTM_ObstacleControl_T RT_MODEL_ObstacleControl_T;

#endif                                 // RTW_HEADER_ObstacleControl_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
