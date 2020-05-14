//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ObstacleControl.h
//
// Code generated for Simulink model 'ObstacleControl'.
//
// Model version                  : 1.17
// Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
// C/C++ source code generated on : Thu May 14 07:40:32 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_ObstacleControl_h_
#define RTW_HEADER_ObstacleControl_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#include "rtwtypes.h"
#include "slros_initialize.h"
#include "ObstacleControl_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rt_defines.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

// Block signals (default storage)
typedef struct {
  real32_T candToSectDiff_data[2160];
  real32_T tmp_data[2160];
  boolean_T validWeights_data[6480];
  real32_T lowerVec_data[540];
  real32_T higherVec_data[540];
  real32_T lh_data[540];
  real32_T kalphaVec_data[540];
  real32_T lk_data[540];
  real32_T kh_data[540];
  boolean_T nearIdx_data[2160];
  real_T angles[180];                  // '<Root>/angles_and_dists'
  real_T bin_data[180];
  SL_Bus_ObstacleControl_sensor_msgs_LaserScan In1;// '<S15>/In1'
  SL_Bus_ObstacleControl_sensor_msgs_LaserScan b_varargout_2;
  SL_Bus_ObstacleControl_nav_msgs_Odometry b_varargout_2_m;
  int32_T m_data[180];
  real32_T dists[180];                 // '<Root>/angles_and_dists'
  real32_T expl_temp_data[180];
  real32_T expl_temp_data_c[180];
  real32_T weightedRanges_data[180];
  real32_T sinOfEnlargement_data[180];
  real32_T enlargementAngle_data[180];
  real32_T lowerAng_data[180];
  real32_T tmp_data_k[180];
  real32_T tmp_data_c[180];
  real32_T tmp_data_b[180];
  real32_T tmp_data_p[180];
  real32_T y_data[180];
  real32_T validScan_InternalRanges_data[180];
  real32_T validScan_InternalAngles_data[180];
  real32_T DYj_data[180];
  real32_T tmp_data_cv[180];
  real32_T tmp_data_f[180];
  real32_T angles_data[180];
  real32_T ranges[128];
  real32_T kalpha[108];
  real_T dv[38];
  real_T dv1[37];
  real_T unusedU4[36];
  real32_T candidateDirs_data[60];
  real32_T candidateDirections_data[60];
  real32_T cDiff_data[60];
  int32_T td_data[60];
  real32_T cost_data[60];
  real32_T cost_data_g[60];
  real32_T cost_data_g1[60];
  real32_T delta_data[60];
  real32_T y_data_m[60];
  real32_T b_z1_data[60];
  real32_T tmp_data_n[60];
  boolean_T validIndices_data[180];
  boolean_T validRangeLimitIndices_data[180];
  boolean_T validAngleLimitIndices_data[180];
  boolean_T pos_data[180];
  boolean_T b_data[180];
  boolean_T blockedR_data[180];
  boolean_T blockedL_data[180];
  boolean_T tmp_data_pp[180];
  real32_T sectors_data[38];
  real32_T angles_data_l[38];
  int32_T ii_data[37];
  real32_T changes[37];
  real32_T obstacleDensity[36];
  real32_T sectorSizes_data[19];
  real32_T narrowDirs_data[19];
  real32_T gb_data[19];
  int32_T md_data[19];
  int32_T rd_data[19];
  real32_T angles_data_j[19];
  real32_T angles_data_d[19];
  real32_T theta1_data[19];
  real32_T b_y1_data[19];
  boolean_T freeDirs_data[60];
  boolean_T pos_data_g[60];
  boolean_T b_data_l[60];
  SL_Bus_ObstacleControl_geometry_msgs_Twist BusAssignment1;// '<Root>/Bus Assignment1' 
  int8_T b_data_d[36];
  int8_T c_data[36];
  int8_T sd_data[36];
  boolean_T d[36];
  boolean_T obj_data[36];
  real_T waypoints_data[4];
  uint32_T inSize[8];
  SL_Bus_ObstacleControl_geometry_msgs_Pose2D In1_o;// '<S16>/In1'
  SL_Bus_ObstacleControl_geometry_msgs_Pose2D b_varargout_2_d;
  real_T dv2[3];
  char_T cv[18];
  real_T posDiff[2];
  real_T lookaheadStartPt[2];
  real_T waypoints[2];
  real_T waypoints_l[2];
  real_T waypoints_o[2];
  real_T refPt[2];
  char_T cv1[13];
  real32_T kalpha_b[3];
  d_cell_wrap_ObstacleControl_T d_n;
  real_T Switch;                       // '<S20>/Switch'
  real_T PurePursuit_o1;               // '<S19>/Pure Pursuit'
  real_T u[4];                         // '<S17>/MATLAB Function'
  real_T DataTypeConversion2;          // '<S2>/Data Type Conversion2'
  real_T DataTypeConversion;           // '<S2>/Data Type Conversion'
  real_T DataTypeConversion1;          // '<S2>/Data Type Conversion1'
  real_T b;
  real_T b_z1_idx_0;
  real_T b_z1_idx_1;
  real_T b_z1_idx_2;
  real_T d_l;
  real_T obj_tmp;
  real_T minDistance;
  real_T dist;
  real_T overshootDist;
  real_T lookaheadIdx;
  real_T b_h;
  real_T lookaheadEndPt_idx_1;
  real_T alpha;
  real_T v12;
  real_T v12_b;
  real_T scale;
  SL_Bus_ObstacleControl_std_msgs_Bool In1_l;// '<S14>/In1'
  int32_T lowerVec_size[2];
  int32_T lh_size[2];
  int32_T kalphaVec_size[2];
  int32_T lk_size[2];
  int32_T kh_size[2];
  int32_T sectors_size[2];
  int32_T sectorSizes_size[2];
  int32_T candidateDirs_size[2];
  int32_T candidateDirections_size[2];
  int32_T angles_size[2];
  int32_T angles_size_d[2];
  int32_T obj_size[2];
  int32_T delta_size[2];
  int32_T targetDir_size[2];
  int32_T tmp_size[2];
  int32_T prevDir_size[2];
  int32_T tmp_size_e[2];
  int32_T f_data[2];
  real32_T obj[2];
  real32_T parsedAngleLimits[2];
  real32_T b_z1[2];
  real32_T obj_b[2];
  real32_T target;
  real32_T cVal;
  real32_T phiR_data;
  real32_T phiL_data;
  int32_T trueCount;
  int32_T partialTrueCount;
  int32_T i;
  int32_T SFunction_DIMS3;
  int32_T SFunction_DIMS2;
  int32_T SFunction_DIMS3_b;
  int32_T SFunction_DIMS2_j;
  int32_T end;
  int32_T e_i;
  int32_T n;
  int32_T loop_ub;
  int32_T loop_ub_f;
  int32_T sinOfEnlargement_size;
  int32_T enlargementAngle_size;
  int32_T lowerAng_size;
  int32_T tmp_size_a;
  int32_T i_j;
  int32_T validIndices_size;
  int32_T idx;
  int32_T b_ii;
  int32_T b_idx;
  int32_T m;
  int32_T ii_data_j;
  int32_T k;
  int32_T idx_o;
  int32_T b_ii_n;
  int32_T validScan_InternalRanges_size;
  int32_T DYj_size;
  int32_T tmp_size_i;
  int32_T tmp_size_o;
  int32_T obj_size_n;
  int32_T obj_size_m;
  uint32_T ii;
  uint32_T qY;
  uint32_T i_data;
} B_ObstacleControl_T;

// Block states (default storage) for system '<Root>'
typedef struct {
  nav_slalgs_internal_VectorFie_T obj; // '<S19>/Vector Field Histogram'
  nav_slalgs_internal_PurePursu_T obj_n;// '<S19>/Pure Pursuit'
  ros_slros_internal_block_Publ_T obj_d;// '<S4>/SinkBlock'
  ros_slros_internal_block_Subs_T obj_c;// '<S8>/SourceBlock'
  ros_slros_internal_block_Subs_T obj_i;// '<S7>/SourceBlock'
  ros_slros_internal_block_Subs_T obj_h;// '<S6>/SourceBlock'
  ros_slros_internal_block_Subs_T obj_nl;// '<S5>/SourceBlock'
  int32_T SFunction_DIMS2[2];          // '<Root>/angles_and_dists'
  int32_T SFunction_DIMS3[2];          // '<Root>/angles_and_dists'
} DW_ObstacleControl_T;

// Parameters (default storage)
struct P_ObstacleControl_T_ {
  real_T CompareToConstant1_const;   // Mask Parameter: CompareToConstant1_const
                                        //  Referenced by: '<S22>/Constant'

  real32_T CompareToConstant_const;   // Mask Parameter: CompareToConstant_const
                                         //  Referenced by: '<S21>/Constant'

  SL_Bus_ObstacleControl_sensor_msgs_LaserScan Out1_Y0;// Computed Parameter: Out1_Y0
                                                          //  Referenced by: '<S15>/Out1'

  SL_Bus_ObstacleControl_sensor_msgs_LaserScan Constant_Value;// Computed Parameter: Constant_Value
                                                                 //  Referenced by: '<S7>/Constant'

  SL_Bus_ObstacleControl_nav_msgs_Odometry Out1_Y0_m;// Computed Parameter: Out1_Y0_m
                                                        //  Referenced by: '<S13>/Out1'

  SL_Bus_ObstacleControl_nav_msgs_Odometry Constant_Value_a;// Computed Parameter: Constant_Value_a
                                                               //  Referenced by: '<S5>/Constant'

  SL_Bus_ObstacleControl_geometry_msgs_Twist Constant_Value_d;// Computed Parameter: Constant_Value_d
                                                                 //  Referenced by: '<S1>/Constant'

  SL_Bus_ObstacleControl_geometry_msgs_Pose2D Out1_Y0_e;// Computed Parameter: Out1_Y0_e
                                                           //  Referenced by: '<S16>/Out1'

  SL_Bus_ObstacleControl_geometry_msgs_Pose2D Constant_Value_c;// Computed Parameter: Constant_Value_c
                                                                  //  Referenced by: '<S8>/Constant'

  SL_Bus_ObstacleControl_std_msgs_Bool Out1_Y0_ev;// Computed Parameter: Out1_Y0_ev
                                                     //  Referenced by: '<S14>/Out1'

  SL_Bus_ObstacleControl_std_msgs_Bool Constant_Value_i;// Computed Parameter: Constant_Value_i
                                                           //  Referenced by: '<S6>/Constant'

  real_T Switch1_Threshold;            // Expression: 0
                                          //  Referenced by: '<Root>/Switch1'

  real_T Switch_Threshold;             // Expression: 0
                                          //  Referenced by: '<Root>/Switch'

  real_T X_Y0;                         // Computed Parameter: X_Y0
                                          //  Referenced by: '<S2>/X'

  real_T Y_Y0;                         // Computed Parameter: Y_Y0
                                          //  Referenced by: '<S2>/Y'

  real_T Theta_Y0;                     // Computed Parameter: Theta_Y0
                                          //  Referenced by: '<S2>/Theta'

  real_T waypoints_Y0;                 // Computed Parameter: waypoints_Y0
                                          //  Referenced by: '<S9>/waypoints'

  real_T VectorFieldHistogram_DistanceLi[2];// Expression: [ 0.05, 3 ]
                                               //  Referenced by: '<S19>/Vector Field Histogram'

  real_T VectorFieldHistogram_HistogramT[2];// Expression: [ 5, 10 ]
                                               //  Referenced by: '<S19>/Vector Field Histogram'

  real_T VectorFieldHistogram_RobotRadiu;// Expression: 0.1
                                            //  Referenced by: '<S19>/Vector Field Histogram'

  real_T VectorFieldHistogram_SafetyDist;// Expression: 0.2
                                            //  Referenced by: '<S19>/Vector Field Histogram'

  real_T VectorFieldHistogram_MinTurning;// Expression: 0.25
                                            //  Referenced by: '<S19>/Vector Field Histogram'

  real_T VectorFieldHistogram_TargetDire;// Expression: 5
                                            //  Referenced by: '<S19>/Vector Field Histogram'

  real_T VectorFieldHistogram_CurrentDir;// Expression: 2
                                            //  Referenced by: '<S19>/Vector Field Histogram'

  real_T VectorFieldHistogram_PreviousDi;// Expression: 2
                                            //  Referenced by: '<S19>/Vector Field Histogram'

  real_T PurePursuit_DesiredLinearVeloci;// Expression: 0.1
                                            //  Referenced by: '<S19>/Pure Pursuit'

  real_T PurePursuit_MaxAngularVelocity;// Expression: 1.5
                                           //  Referenced by: '<S19>/Pure Pursuit'

  real_T PurePursuit_LookaheadDistance;// Expression: 0.2
                                          //  Referenced by: '<S19>/Pure Pursuit'

  real_T w_Y0;                         // Computed Parameter: w_Y0
                                          //  Referenced by: '<S10>/w'

  real_T v_Y0;                         // Computed Parameter: v_Y0
                                          //  Referenced by: '<S10>/v'

  real_T Constant1_Value;              // Expression: 0
                                          //  Referenced by: '<Root>/Constant1'

  real_T Constant_Value_g;             // Expression: 0.1
                                          //  Referenced by: '<Root>/Constant'

  real_T Switch2_Threshold;            // Expression: 0
                                          //  Referenced by: '<Root>/Switch2'

  real_T Switch3_Threshold;            // Expression: 0
                                          //  Referenced by: '<Root>/Switch3'

  real32_T SteeringGain_Gain;          // Computed Parameter: SteeringGain_Gain
                                          //  Referenced by: '<S20>/Steering Gain'

};

// Real-time Model Data Structure
struct tag_RTM_ObstacleControl_T {
  const char_T *errorStatus;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_ObstacleControl_T ObstacleControl_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern B_ObstacleControl_T ObstacleControl_B;

#ifdef __cplusplus

}
#endif

// Block states (default storage)
extern DW_ObstacleControl_T ObstacleControl_DW;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void ObstacleControl_initialize(void);
  extern void ObstacleControl_step(void);
  extern void ObstacleControl_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_ObstacleControl_T *const ObstacleControl_M;

#ifdef __cplusplus

}
#endif

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'ObstacleControl'
//  '<S1>'   : 'ObstacleControl/Blank Message'
//  '<S2>'   : 'ObstacleControl/Decode ROS msg'
//  '<S3>'   : 'ObstacleControl/MATLAB Function'
//  '<S4>'   : 'ObstacleControl/Publish'
//  '<S5>'   : 'ObstacleControl/Subscribe'
//  '<S6>'   : 'ObstacleControl/Subscribe1'
//  '<S7>'   : 'ObstacleControl/Subscribe2'
//  '<S8>'   : 'ObstacleControl/Subscribe3'
//  '<S9>'   : 'ObstacleControl/Subsystem'
//  '<S10>'  : 'ObstacleControl/Subsystem1'
//  '<S11>'  : 'ObstacleControl/Subsystem2'
//  '<S12>'  : 'ObstacleControl/angles_and_dists'
//  '<S13>'  : 'ObstacleControl/Subscribe/Enabled Subsystem'
//  '<S14>'  : 'ObstacleControl/Subscribe1/Enabled Subsystem'
//  '<S15>'  : 'ObstacleControl/Subscribe2/Enabled Subsystem'
//  '<S16>'  : 'ObstacleControl/Subscribe3/Enabled Subsystem'
//  '<S17>'  : 'ObstacleControl/Subsystem/Create path with destination'
//  '<S18>'  : 'ObstacleControl/Subsystem/Create path with destination/MATLAB Function'
//  '<S19>'  : 'ObstacleControl/Subsystem1/Path Following with  Obstacle Avoidance'
//  '<S20>'  : 'ObstacleControl/Subsystem1/Path Following with  Obstacle Avoidance/Driving Logic'
//  '<S21>'  : 'ObstacleControl/Subsystem1/Path Following with  Obstacle Avoidance/Driving Logic/Compare To Constant'
//  '<S22>'  : 'ObstacleControl/Subsystem1/Path Following with  Obstacle Avoidance/Driving Logic/Compare To Constant1'
//  '<S23>'  : 'ObstacleControl/Subsystem2/Subsystem1'
//  '<S24>'  : 'ObstacleControl/Subsystem2/Subsystem1/MATLAB Function1'

#endif                                 // RTW_HEADER_ObstacleControl_h_

//
// File trailer for generated code.
//
// [EOF]
//
