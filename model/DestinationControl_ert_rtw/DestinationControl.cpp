//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: DestinationControl.cpp
//
// Code generated for Simulink model 'DestinationControl'.
//
// Model version                  : 1.2
// Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
// C/C++ source code generated on : Wed May  6 23:43:58 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "DestinationControl.h"
#include "DestinationControl_private.h"

// Named constants for Chart: '<Root>/Waypoint Tracking Logic'
const uint8_T DestinationC_IN_FollowWaypoints = 1U;
const uint8_T DestinationContr_IN_ReachedGoal = 2U;

// Block signals (default storage)
B_DestinationControl_T DestinationControl_B;

// Block states (default storage)
DW_DestinationControl_T DestinationControl_DW;

// Real-time model
RT_MODEL_DestinationControl_T DestinationControl_M_ =
  RT_MODEL_DestinationControl_T();
RT_MODEL_DestinationControl_T *const DestinationControl_M =
  &DestinationControl_M_;

// Forward declaration for local functions
static void DestinationControl_trackGoal(const real_T goal[2], const real_T
  TmpSignalConversionAtSFunctionI[3], real_T *ang, real_T *dist);
static void matlabCodegenHandle_matlabCod_f(ros_slros_internal_block_Subs_T *obj);
static void matlabCodegenHandle_matlabCodeg(ros_slros_internal_block_Publ_T *obj);
real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(static_cast<real_T>(u0_0), static_cast<real_T>(u1_0));
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

// Function for Chart: '<Root>/Waypoint Tracking Logic'
static void DestinationControl_trackGoal(const real_T goal[2], const real_T
  TmpSignalConversionAtSFunctionI[3], real_T *ang, real_T *dist)
{
  real_T thetaWrap;
  boolean_T rEQ0;
  real_T q;
  real_T posDiff_idx_0;
  real_T posDiff_idx_1;
  posDiff_idx_0 = goal[0] - TmpSignalConversionAtSFunctionI[0];
  posDiff_idx_1 = goal[1] - TmpSignalConversionAtSFunctionI[1];
  *ang = rt_atan2d_snf(posDiff_idx_1, posDiff_idx_0) -
    TmpSignalConversionAtSFunctionI[2];
  if (fabs(*ang) > 3.1415926535897931) {
    if (rtIsNaN(*ang + 3.1415926535897931)) {
      thetaWrap = (rtNaN);
    } else if (rtIsInf(*ang + 3.1415926535897931)) {
      thetaWrap = (rtNaN);
    } else if (*ang + 3.1415926535897931 == 0.0) {
      thetaWrap = 0.0;
    } else {
      thetaWrap = fmod(*ang + 3.1415926535897931, 6.2831853071795862);
      rEQ0 = (thetaWrap == 0.0);
      if (!rEQ0) {
        q = fabs((*ang + 3.1415926535897931) / 6.2831853071795862);
        rEQ0 = !(fabs(q - floor(q + 0.5)) > 2.2204460492503131E-16 * q);
      }

      if (rEQ0) {
        thetaWrap = 0.0;
      } else {
        if (*ang + 3.1415926535897931 < 0.0) {
          thetaWrap += 6.2831853071795862;
        }
      }
    }

    if ((thetaWrap == 0.0) && (*ang + 3.1415926535897931 > 0.0)) {
      thetaWrap = 6.2831853071795862;
    }

    *ang = thetaWrap - 3.1415926535897931;
  }

  *dist = sqrt(posDiff_idx_0 * posDiff_idx_0 + posDiff_idx_1 * posDiff_idx_1);
}

static void matlabCodegenHandle_matlabCod_f(ros_slros_internal_block_Subs_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

static void matlabCodegenHandle_matlabCodeg(ros_slros_internal_block_Publ_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

// Model step function
void DestinationControl_step(void)
{
  real_T angle;
  boolean_T b_varargout_1;
  int32_T tmp;

  // Outputs for Atomic SubSystem: '<Root>/Subscribe'
  // MATLABSystem: '<S3>/SourceBlock' incorporates:
  //   Inport: '<S5>/In1'

  b_varargout_1 = Sub_DestinationControl_7.getLatestMessage
    (&DestinationControl_B.b_varargout_2);

  // Outputs for Enabled SubSystem: '<S3>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S5>/Enable'

  if (b_varargout_1) {
    DestinationControl_B.In1 = DestinationControl_B.b_varargout_2;
  }

  // End of MATLABSystem: '<S3>/SourceBlock'
  // End of Outputs for SubSystem: '<S3>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe'

  // SignalConversion generated from: '<S4>/ SFunction ' incorporates:
  //   Chart: '<Root>/Waypoint Tracking Logic'

  DestinationControl_B.TmpSignalConversionAtSFunctionI[0] =
    DestinationControl_B.In1.Pose.Pose.Position.X;
  DestinationControl_B.TmpSignalConversionAtSFunctionI[1] =
    DestinationControl_B.In1.Pose.Pose.Position.Y;
  DestinationControl_B.TmpSignalConversionAtSFunctionI[2] =
    DestinationControl_B.In1.Pose.Pose.Orientation.Z;

  // Chart: '<Root>/Waypoint Tracking Logic' incorporates:
  //   Constant: '<Root>/Waypoints'

  if (DestinationControl_DW.is_active_c3_DestinationControl == 0U) {
    DestinationControl_DW.is_active_c3_DestinationControl = 1U;
    DestinationControl_B.v = 0.5;
    DestinationControl_DW.idx = 1.0;
    DestinationControl_DW.numPts = 3.0;
    DestinationControl_DW.is_c3_DestinationControl =
      DestinationC_IN_FollowWaypoints;
    tmp = static_cast<int32_T>(DestinationControl_DW.idx);
    DestinationControl_DW.goalPoint[0] =
      DestinationControl_P.Waypoints_Value[tmp - 1];
    DestinationControl_DW.goalPoint[1] =
      DestinationControl_P.Waypoints_Value[tmp + 2];
    DestinationControl_trackGoal(DestinationControl_DW.goalPoint,
      DestinationControl_B.TmpSignalConversionAtSFunctionI, &angle,
      &DestinationControl_DW.range);
    if (fabs(angle) > 0.1308996938995747) {
      DestinationControl_B.w = 1.5 * angle;
    } else {
      DestinationControl_B.w = 0.0;
    }
  } else if (DestinationControl_DW.is_c3_DestinationControl ==
             DestinationC_IN_FollowWaypoints) {
    if (DestinationControl_DW.range < 0.1) {
      if (DestinationControl_DW.idx == DestinationControl_DW.numPts) {
        DestinationControl_DW.is_c3_DestinationControl =
          DestinationContr_IN_ReachedGoal;
        DestinationControl_B.v = 0.0;
        DestinationControl_B.w = 0.5;
      } else {
        DestinationControl_DW.idx++;
        DestinationControl_DW.is_c3_DestinationControl =
          DestinationC_IN_FollowWaypoints;
        tmp = static_cast<int32_T>(DestinationControl_DW.idx);
        DestinationControl_DW.goalPoint[0] =
          DestinationControl_P.Waypoints_Value[tmp - 1];
        DestinationControl_DW.goalPoint[1] =
          DestinationControl_P.Waypoints_Value[tmp + 2];
        DestinationControl_trackGoal(DestinationControl_DW.goalPoint,
          DestinationControl_B.TmpSignalConversionAtSFunctionI, &angle,
          &DestinationControl_DW.range);
        if (fabs(angle) > 0.1308996938995747) {
          DestinationControl_B.w = 1.5 * angle;
        } else {
          DestinationControl_B.w = 0.0;
        }
      }
    } else {
      DestinationControl_trackGoal(DestinationControl_DW.goalPoint,
        DestinationControl_B.TmpSignalConversionAtSFunctionI, &angle,
        &DestinationControl_DW.range);
      if (fabs(angle) > 0.1308996938995747) {
        DestinationControl_B.w = 1.5 * angle;
      } else {
        DestinationControl_B.w = 0.0;
      }
    }
  } else {
    // case IN_ReachedGoal:
  }

  // BusAssignment: '<Root>/Bus Assignment1' incorporates:
  //   Constant: '<S1>/Constant'

  DestinationControl_B.BusAssignment1 = DestinationControl_P.Constant_Value_d;
  DestinationControl_B.BusAssignment1.Linear.X = DestinationControl_B.v;
  DestinationControl_B.BusAssignment1.Angular.Z = DestinationControl_B.w;

  // Outputs for Atomic SubSystem: '<Root>/Publish'
  // MATLABSystem: '<S2>/SinkBlock'
  Pub_DestinationControl_5.publish(&DestinationControl_B.BusAssignment1);

  // End of Outputs for SubSystem: '<Root>/Publish'
}

// Model initialize function
void DestinationControl_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    char_T tmp[6];
    char_T tmp_0[9];
    int32_T i;
    static const char_T tmp_1[5] = { '/', 'o', 'd', 'o', 'm' };

    static const char_T tmp_2[8] = { '/', 'c', 'm', 'd', '_', 'v', 'e', 'l' };

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S3>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S5>/Out1'
    DestinationControl_B.In1 = DestinationControl_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S3>/Enabled Subsystem'

    // Start for MATLABSystem: '<S3>/SourceBlock'
    DestinationControl_DW.obj_n.matlabCodegenIsDeleted = false;
    DestinationControl_DW.obj_n.isInitialized = 1;
    for (i = 0; i < 5; i++) {
      tmp[i] = tmp_1[i];
    }

    tmp[5] = '\x00';
    Sub_DestinationControl_7.createSubscriber(tmp, 1);
    DestinationControl_DW.obj_n.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S3>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish'
    // Start for MATLABSystem: '<S2>/SinkBlock'
    DestinationControl_DW.obj.matlabCodegenIsDeleted = false;
    DestinationControl_DW.obj.isInitialized = 1;
    for (i = 0; i < 8; i++) {
      tmp_0[i] = tmp_2[i];
    }

    tmp_0[8] = '\x00';
    Pub_DestinationControl_5.createPublisher(tmp_0, 1);
    DestinationControl_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S2>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish'
  }
}

// Model terminate function
void DestinationControl_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Terminate for MATLABSystem: '<S3>/SourceBlock'
  matlabCodegenHandle_matlabCod_f(&DestinationControl_DW.obj_n);

  // End of Terminate for SubSystem: '<Root>/Subscribe'

  // Terminate for Atomic SubSystem: '<Root>/Publish'
  // Terminate for MATLABSystem: '<S2>/SinkBlock'
  matlabCodegenHandle_matlabCodeg(&DestinationControl_DW.obj);

  // End of Terminate for SubSystem: '<Root>/Publish'
}

//
// File trailer for generated code.
//
// [EOF]
//
