//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: DestinationControl.h
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
  SL_Bus_DestinationControl_nav_msgs_Odometry In1;// '<S4>/In1'
  SL_Bus_DestinationControl_nav_msgs_Odometry b_varargout_2;
  SL_Bus_DestinationControl_geometry_msgs_Twist BusAssignment1;// '<Root>/Bus Assignment1' 
  real_T waypoints_data[6];
  real_T dv[3];
  real_T unusedU0[2];
  real_T lookaheadStartPt[2];
  real_T waypoints[2];
  real_T waypoints_m[2];
  real_T waypoints_c[2];
  real_T refPt[2];
  int32_T f_data[3];
  real_T v;
  real_T w;
  real_T targetDir;
  real_T minDistance;
  real_T dist;
  real_T overshootDist;
  real_T lookaheadIdx;
  real_T b;
  real_T lookaheadEndPt_idx_1;
  real_T alpha;
  real_T v12;
  real_T v12_k;
} B_DestinationControl_T;

// Block states (default storage) for system '<Root>'
typedef struct {
  nav_slalgs_internal_PurePursu_T obj; // '<Root>/Pure Pursuit'
  ros_slros_internal_block_Publ_T obj_d;// '<S2>/SinkBlock'
  ros_slros_internal_block_Subs_T obj_n;// '<S3>/SourceBlock'
} DW_DestinationControl_T;

// Parameters (default storage)
struct P_DestinationControl_T_ {
  SL_Bus_DestinationControl_nav_msgs_Odometry Out1_Y0;// Computed Parameter: Out1_Y0
                                                         //  Referenced by: '<S4>/Out1'

  SL_Bus_DestinationControl_nav_msgs_Odometry Constant_Value;// Computed Parameter: Constant_Value
                                                                //  Referenced by: '<S3>/Constant'

  SL_Bus_DestinationControl_geometry_msgs_Twist Constant_Value_d;// Computed Parameter: Constant_Value_d
                                                                    //  Referenced by: '<S1>/Constant'

  real_T PurePursuit_DesiredLinearVeloci;// Expression: 0.1
                                            //  Referenced by: '<Root>/Pure Pursuit'

  real_T PurePursuit_MaxAngularVelocity;// Expression: 1.0
                                           //  Referenced by: '<Root>/Pure Pursuit'

  real_T PurePursuit_LookaheadDistance;// Expression: 1.0
                                          //  Referenced by: '<Root>/Pure Pursuit'

  real_T Waypoints_Value[6];           // Expression: [0,0; 1,1; 0,0]
                                          //  Referenced by: '<Root>/Waypoints'

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
//  '<S2>'   : 'DestinationControl/Publish'
//  '<S3>'   : 'DestinationControl/Subscribe'
//  '<S4>'   : 'DestinationControl/Subscribe/Enabled Subsystem'

#endif                                 // RTW_HEADER_DestinationControl_h_

//
// File trailer for generated code.
//
// [EOF]
//
