//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: DestinationControl.h
//
// Code generated for Simulink model 'DestinationControl'.
//
// Model version                  : 1.8
// Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
// C/C++ source code generated on : Wed May 13 20:14:40 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_DestinationControl_h_
#define RTW_HEADER_DestinationControl_h_
#include <math.h>
#include <stddef.h>
#include "rtwtypes.h"
#include "slros_initialize.h"
#include "DestinationControl_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"
#include "rtGetInf.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

// Block signals (default storage)
typedef struct {
  SL_Bus_DestinationControl_nav_msgs_Odometry b_varargout_2;
  SL_Bus_DestinationControl_geometry_msgs_Twist BusAssignment1;// '<Root>/Bus Assignment1' 
  real_T u[4];                         // '<S10>/MATLAB Function'
  real_T waypoints_data[4];
  SL_Bus_DestinationControl_geometry_msgs_Pose2D In1_o;// '<S9>/In1'
  SL_Bus_DestinationControl_geometry_msgs_Pose2D b_varargout_2_m;
  real_T dv[3];
  real_T unusedU0[2];
  real_T lookaheadStartPt[2];
  real_T waypoints[2];
  real_T waypoints_c[2];
  real_T waypoints_k[2];
  real_T refPt[2];
  int32_T f_data[2];
  real_T DataTypeConversion2;          // '<S2>/Data Type Conversion2'
  real_T DataTypeConversion;           // '<S2>/Data Type Conversion'
  real_T DataTypeConversion1;          // '<S2>/Data Type Conversion1'
  real_T posDiff_idx_0;
  real_T posDiff_idx_1;
  real_T b_z1_idx_0;
  real_T b_z1_idx_1;
  real_T minDistance;
  real_T dist;
  real_T overshootDist;
  real_T lookaheadIdx;
  real_T b;
  real_T lookaheadEndPt_idx_1;
  real_T alpha;
  real_T v12;
  real_T v12_c;
} B_DestinationControl_T;

// Block states (default storage) for system '<Root>'
typedef struct {
  nav_slalgs_internal_PurePursu_T obj; // '<Root>/Pure Pursuit'
  ros_slros_internal_block_Publ_T obj_d;// '<S4>/SinkBlock'
  ros_slros_internal_block_Subs_T obj_c;// '<S6>/SourceBlock'
  ros_slros_internal_block_Subs_T obj_n;// '<S5>/SourceBlock'
} DW_DestinationControl_T;

// Parameters (default storage)
struct P_DestinationControl_T_ {
  SL_Bus_DestinationControl_nav_msgs_Odometry Out1_Y0;// Computed Parameter: Out1_Y0
                                                         //  Referenced by: '<S8>/Out1'

  SL_Bus_DestinationControl_nav_msgs_Odometry Constant_Value;// Computed Parameter: Constant_Value
                                                                //  Referenced by: '<S5>/Constant'

  SL_Bus_DestinationControl_geometry_msgs_Twist Constant_Value_d;// Computed Parameter: Constant_Value_d
                                                                    //  Referenced by: '<S1>/Constant'

  SL_Bus_DestinationControl_geometry_msgs_Pose2D Out1_Y0_e;// Computed Parameter: Out1_Y0_e
                                                              //  Referenced by: '<S9>/Out1'

  SL_Bus_DestinationControl_geometry_msgs_Pose2D Constant_Value_c;// Computed Parameter: Constant_Value_c
                                                                     //  Referenced by: '<S6>/Constant'

  real_T PurePursuit_DesiredLinearVeloci;// Expression: 0.1
                                            //  Referenced by: '<Root>/Pure Pursuit'

  real_T PurePursuit_MaxAngularVelocity;// Expression: 1.0
                                           //  Referenced by: '<Root>/Pure Pursuit'

  real_T PurePursuit_LookaheadDistance;// Expression: 1.0
                                          //  Referenced by: '<Root>/Pure Pursuit'

  real_T X_Y0;                         // Computed Parameter: X_Y0
                                          //  Referenced by: '<S2>/X'

  real_T Y_Y0;                         // Computed Parameter: Y_Y0
                                          //  Referenced by: '<S2>/Y'

  real_T Theta_Y0;                     // Computed Parameter: Theta_Y0
                                          //  Referenced by: '<S2>/Theta'

  real_T waypoints_Y0;                 // Computed Parameter: waypoints_Y0
                                          //  Referenced by: '<S7>/waypoints'

  real_T Constant1_Value;              // Expression: 0
                                          //  Referenced by: '<Root>/Constant1'

  real_T Constant_Value_g;             // Expression: 0.1
                                          //  Referenced by: '<Root>/Constant'

  real_T Switch_Threshold;             // Expression: 0
                                          //  Referenced by: '<Root>/Switch'

  real_T Switch1_Threshold;            // Expression: 0
                                          //  Referenced by: '<Root>/Switch1'

};

// Real-time Model Data Structure
struct tag_RTM_DestinationControl_T {
  const char_T *errorStatus;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_DestinationControl_T DestinationControl_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern B_DestinationControl_T DestinationControl_B;

#ifdef __cplusplus

}
#endif

// Block states (default storage)
extern DW_DestinationControl_T DestinationControl_DW;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void DestinationControl_initialize(void);
  extern void DestinationControl_step(void);
  extern void DestinationControl_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_DestinationControl_T *const DestinationControl_M;

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
//  '<Root>' : 'DestinationControl'
//  '<S1>'   : 'DestinationControl/Blank Message'
//  '<S2>'   : 'DestinationControl/Decode ROS msg'
//  '<S3>'   : 'DestinationControl/MATLAB Function'
//  '<S4>'   : 'DestinationControl/Publish'
//  '<S5>'   : 'DestinationControl/Subscribe'
//  '<S6>'   : 'DestinationControl/Subscribe3'
//  '<S7>'   : 'DestinationControl/Subsystem'
//  '<S8>'   : 'DestinationControl/Subscribe/Enabled Subsystem'
//  '<S9>'   : 'DestinationControl/Subscribe3/Enabled Subsystem'
//  '<S10>'  : 'DestinationControl/Subsystem/Create path with destination'
//  '<S11>'  : 'DestinationControl/Subsystem/Create path with destination/MATLAB Function'

#endif                                 // RTW_HEADER_DestinationControl_h_

//
// File trailer for generated code.
//
// [EOF]
//
