//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: TestObstacleControl.h
//
// Code generated for Simulink model 'TestObstacleControl'.
//
// Model version                  : 1.22
// Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
// C/C++ source code generated on : Wed May 20 15:31:20 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_TestObstacleControl_h_
#define RTW_HEADER_TestObstacleControl_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#include "rtwtypes.h"
#include "slros_initialize.h"
#include "TestObstacleControl_types.h"
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
  real_T angles[180];                  // '<Root>/angles_and_dists1'
  real_T bin_data[180];
  SL_Bus_TestObstacleControl_sensor_msgs_LaserScan In1;// '<S11>/In1'
  SL_Bus_TestObstacleControl_sensor_msgs_LaserScan b_varargout_2;
  SL_Bus_TestObstacleControl_nav_msgs_Odometry b_varargout_2_m;
  real32_T dists[180];                 // '<Root>/angles_and_dists1'
  real32_T scan_InternalRanges_data[180];
  real32_T scan_InternalAngles_data[180];
  real32_T varargin_2_data[180];
  real32_T weightedRanges_data[180];
  real32_T sinOfEnlargement_data[180];
  real32_T enlargementAngle_data[180];
  real32_T lowerAng_data[180];
  real32_T tmp_data_c[180];
  real32_T tmp_data_k[180];
  real32_T tmp_data_cx[180];
  real32_T y_data[180];
  real32_T validScan_InternalRanges_data[180];
  real32_T validScan_InternalAngles_data[180];
  real32_T DYj_data[180];
  real32_T tmp_data_b[180];
  real32_T tmp_data_p[180];
  real32_T ranges[128];
  real32_T kalpha[108];
  real_T dv[38];
  real_T dv1[37];
  real_T unusedU4[36];
  real32_T candidateDirs_data[60];
  real32_T candidateDirections_data[60];
  real32_T cDiff_data[60];
  int32_T vb_data[60];
  real32_T cost_data[60];
  real32_T cost_data_c[60];
  real32_T cost_data_f[60];
  real32_T delta_data[60];
  real32_T y_data_g[60];
  real32_T b_z1_data[60];
  real32_T tmp_data_g[60];
  boolean_T validRangeLimitIndices_data[180];
  boolean_T validAngleLimitIndices_data[180];
  boolean_T tmp_data_m[180];
  boolean_T tmp_data_n[180];
  boolean_T tmp_data_pp[180];
  boolean_T pos_data[180];
  boolean_T b_data[180];
  boolean_T blockedR_data[180];
  boolean_T blockedL_data[180];
  boolean_T tmp_data_l[180];
  real32_T sectors_data[38];
  real32_T angles_data[38];
  int32_T ii_data[37];
  real32_T changes[37];
  real32_T obstacleDensity[36];
  real32_T sectorSizes_data[19];
  real32_T narrowDirs_data[19];
  real32_T ab_data[19];
  int32_T ob_data[19];
  int32_T tb_data[19];
  real32_T angles_data_j[19];
  real32_T angles_data_d[19];
  real32_T theta1_data[19];
  real32_T b_y1_data[19];
  real_T waypoints_data[8];
  boolean_T freeDirs_data[60];
  boolean_T pos_data_g[60];
  boolean_T b_data_l[60];
  SL_Bus_TestObstacleControl_geometry_msgs_Twist BusAssignment2;// '<Root>/Bus Assignment2' 
  int8_T b_data_d[36];
  int8_T c_data[36];
  int8_T ub_data[36];
  boolean_T obj_data[36];
  real_T dv2[3];
  int32_T f_data[4];
  real_T unusedU0[2];
  real_T lookaheadStartPt[2];
  real_T waypoints[2];
  real_T waypoints_d[2];
  real_T waypoints_l[2];
  real_T refPt[2];
  real32_T kalpha_o[3];
  d_cell_wrap_TestObstacleContr_T d;
  boolean_T b[8];
  real_T DataTypeConversion2;          // '<S2>/Data Type Conversion2'
  real_T DataTypeConversion;           // '<S2>/Data Type Conversion'
  real_T DataTypeConversion1;          // '<S2>/Data Type Conversion1'
  real_T b_n;
  real_T b_z1_idx_0;
  real_T b_z1_idx_1;
  real_T b_z1_idx_2;
  real_T d_b;
  real_T obj_tmp;
  real_T minDistance;
  real_T dist;
  real_T overshootDist;
  real_T lookaheadIdx;
  real_T b_l;
  real_T lookaheadEndPt_idx_1;
  real_T alpha;
  real_T v12;
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
  int32_T angles_size_h[2];
  int32_T obj_size[2];
  int32_T delta_size[2];
  int32_T targetDir_size[2];
  int32_T tmp_size[2];
  int32_T prevDir_size[2];
  int32_T tmp_size_b[2];
  real32_T obj[2];
  real32_T parsedAngleLimits[2];
  real32_T b_z1[2];
  real32_T obj_b[2];
  real32_T ranges_d;
  real32_T target;
  real32_T sinOfEnlargement_data_e;
  real32_T cVal;
  real32_T phiR_data;
  real32_T phiL_data;
  int32_T i;
  int32_T SFunction_DIMS3;
  int32_T SFunction_DIMS2;
  int32_T partialTrueCount;
  int32_T loop_ub;
  int32_T i_b;
  int32_T scan_InternalRanges_size;
  int32_T scan_InternalAngles_size;
  int32_T varargin_2_size;
  int32_T end;
  int32_T e_i;
  int32_T loop_ub_j;
  int32_T loop_ub_f;
  int32_T sinOfEnlargement_size;
  int32_T enlargementAngle_size;
  int32_T lowerAng_size;
  int32_T tmp_size_a;
  int32_T validWeights_size_idx_1;
  int32_T h_partialTrueCount;
  int32_T idx;
  int32_T ii_data_j;
  int32_T k;
  int32_T k_j;
  int32_T idx_o;
  int32_T b_ii;
  int32_T validScan_InternalRanges_size;
  int32_T DYj_size;
  int32_T tmp_size_n;
  int32_T tmp_size_i;
  int32_T obj_size_o;
  int32_T obj_size_n;
  uint32_T ii;
  uint32_T qY;
} B_TestObstacleControl_T;

// Block states (default storage) for system '<Root>'
typedef struct {
  nav_slalgs_internal_VectorFie_T obj; // '<S3>/Vector Field Histogram'
  nav_slalgs_internal_PurePursu_T obj_f;// '<S3>/Pure Pursuit'
  ros_slros_internal_block_Publ_T obj_g;// '<S4>/SinkBlock'
  ros_slros_internal_block_Subs_T obj_h;// '<S6>/SourceBlock'
  ros_slros_internal_block_Subs_T obj_d;// '<S5>/SourceBlock'
  int32_T SFunction_DIMS2[2];          // '<Root>/angles_and_dists1'
  int32_T SFunction_DIMS3[2];          // '<Root>/angles_and_dists1'
} DW_TestObstacleControl_T;

// Parameters (default storage)
struct P_TestObstacleControl_T_ {
  real_T L;                            // Variable: L
                                          //  Referenced by: '<S3>/Vector Field Histogram'

  real_T CompareToConstant1_const;   // Mask Parameter: CompareToConstant1_const
                                        //  Referenced by: '<S10>/Constant'

  real32_T CompareToConstant_const;   // Mask Parameter: CompareToConstant_const
                                         //  Referenced by: '<S9>/Constant'

  SL_Bus_TestObstacleControl_sensor_msgs_LaserScan Out1_Y0;// Computed Parameter: Out1_Y0
                                                              //  Referenced by: '<S11>/Out1'

  SL_Bus_TestObstacleControl_sensor_msgs_LaserScan Constant_Value;// Computed Parameter: Constant_Value
                                                                     //  Referenced by: '<S5>/Constant'

  SL_Bus_TestObstacleControl_nav_msgs_Odometry Out1_Y0_b;// Computed Parameter: Out1_Y0_b
                                                            //  Referenced by: '<S12>/Out1'

  SL_Bus_TestObstacleControl_nav_msgs_Odometry Constant_Value_h;// Computed Parameter: Constant_Value_h
                                                                   //  Referenced by: '<S6>/Constant'

  SL_Bus_TestObstacleControl_geometry_msgs_Twist Constant_Value_k;// Computed Parameter: Constant_Value_k
                                                                     //  Referenced by: '<S1>/Constant'

  real_T X_Y0;                         // Computed Parameter: X_Y0
                                          //  Referenced by: '<S2>/X'

  real_T Y_Y0;                         // Computed Parameter: Y_Y0
                                          //  Referenced by: '<S2>/Y'

  real_T Theta_Y0;                     // Computed Parameter: Theta_Y0
                                          //  Referenced by: '<S2>/Theta'

  real_T VectorFieldHistogram_DistanceLi[2];// Expression: [ 0.05, 3 ]
                                               //  Referenced by: '<S3>/Vector Field Histogram'

  real_T VectorFieldHistogram_HistogramT[2];// Expression: [ 5, 10 ]
                                               //  Referenced by: '<S3>/Vector Field Histogram'

  real_T VectorFieldHistogram_MinTurning;// Expression: 0.25
                                            //  Referenced by: '<S3>/Vector Field Histogram'

  real_T VectorFieldHistogram_TargetDire;// Expression: 5
                                            //  Referenced by: '<S3>/Vector Field Histogram'

  real_T VectorFieldHistogram_CurrentDir;// Expression: 2
                                            //  Referenced by: '<S3>/Vector Field Histogram'

  real_T VectorFieldHistogram_PreviousDi;// Expression: 2
                                            //  Referenced by: '<S3>/Vector Field Histogram'

  real_T PurePursuit_DesiredLinearVeloci;// Expression: 0.75
                                            //  Referenced by: '<S3>/Pure Pursuit'

  real_T PurePursuit_MaxAngularVelocity;// Expression: 1.5
                                           //  Referenced by: '<S3>/Pure Pursuit'

  real_T PurePursuit_LookaheadDistance;// Expression: 0.5
                                          //  Referenced by: '<S3>/Pure Pursuit'

  real_T Waypoints_Value[8];           // Expression: [2 2;2 10;11 8;8 2]
                                          //  Referenced by: '<Root>/Waypoints'

  real32_T SteeringGain_Gain;          // Computed Parameter: SteeringGain_Gain
                                          //  Referenced by: '<S8>/Steering Gain'

};

// Real-time Model Data Structure
struct tag_RTM_TestObstacleControl_T {
  const char_T *errorStatus;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_TestObstacleControl_T TestObstacleControl_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern B_TestObstacleControl_T TestObstacleControl_B;

#ifdef __cplusplus

}
#endif

// Block states (default storage)
extern DW_TestObstacleControl_T TestObstacleControl_DW;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void TestObstacleControl_initialize(void);
  extern void TestObstacleControl_step(void);
  extern void TestObstacleControl_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_TestObstacleControl_T *const TestObstacleControl_M;

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
//  '<Root>' : 'TestObstacleControl'
//  '<S1>'   : 'TestObstacleControl/Blank Message1'
//  '<S2>'   : 'TestObstacleControl/Decode ROS msg1'
//  '<S3>'   : 'TestObstacleControl/Path Following with  Obstacle Avoidance'
//  '<S4>'   : 'TestObstacleControl/Publish1'
//  '<S5>'   : 'TestObstacleControl/Subscribe1'
//  '<S6>'   : 'TestObstacleControl/Subscribe4'
//  '<S7>'   : 'TestObstacleControl/angles_and_dists1'
//  '<S8>'   : 'TestObstacleControl/Path Following with  Obstacle Avoidance/Driving Logic'
//  '<S9>'   : 'TestObstacleControl/Path Following with  Obstacle Avoidance/Driving Logic/Compare To Constant'
//  '<S10>'  : 'TestObstacleControl/Path Following with  Obstacle Avoidance/Driving Logic/Compare To Constant1'
//  '<S11>'  : 'TestObstacleControl/Subscribe1/Enabled Subsystem'
//  '<S12>'  : 'TestObstacleControl/Subscribe4/Enabled Subsystem'

#endif                                 // RTW_HEADER_TestObstacleControl_h_

//
// File trailer for generated code.
//
// [EOF]
//
