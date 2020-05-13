//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: DestinationControl.cpp
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
#include "DestinationControl.h"
#include "DestinationControl_private.h"

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
static real_T DestinationControl_norm(const real_T x[2]);
static void DestinationC_closestPointOnLine(const real_T pt1[2], const real_T
  pt2[2], const real_T refPt[2], real_T closestPoint[2], real_T *distance);
static void De_PurePursuitBase_stepInternal(nav_slalgs_internal_PurePursu_T *obj,
  const real_T currentPose[3], const real_T wayptsIn[4], real_T *v, real_T *w,
  real_T lookaheadPoint[2], real_T *targetDir);
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

static real_T DestinationControl_norm(const real_T x[2])
{
  real_T y;
  real_T scale;
  real_T absxk;
  real_T t;
  scale = 3.3121686421112381E-170;
  absxk = fabs(x[0]);
  if (absxk > 3.3121686421112381E-170) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
  }

  absxk = fabs(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * sqrt(y);
}

static void DestinationC_closestPointOnLine(const real_T pt1[2], const real_T
  pt2[2], const real_T refPt[2], real_T closestPoint[2], real_T *distance)
{
  boolean_T p;
  boolean_T p_0;
  int32_T b_k;
  boolean_T exitg1;
  p = false;
  p_0 = true;
  b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (b_k < 2)) {
    if (!(pt1[b_k] == pt2[b_k])) {
      p_0 = false;
      exitg1 = true;
    } else {
      b_k++;
    }
  }

  if (p_0) {
    p = true;
  }

  if (p) {
    closestPoint[0] = pt1[0];
    DestinationControl_B.refPt[0] = refPt[0] - pt1[0];
    closestPoint[1] = pt1[1];
    DestinationControl_B.refPt[1] = refPt[1] - pt1[1];
    *distance = DestinationControl_norm(DestinationControl_B.refPt);
  } else {
    DestinationControl_B.alpha = pt2[0] - pt1[0];
    DestinationControl_B.v12 = (pt2[0] - refPt[0]) * DestinationControl_B.alpha;
    DestinationControl_B.v12_c = DestinationControl_B.alpha *
      DestinationControl_B.alpha;
    DestinationControl_B.alpha = pt2[1] - pt1[1];
    DestinationControl_B.v12 += (pt2[1] - refPt[1]) * DestinationControl_B.alpha;
    DestinationControl_B.v12_c += DestinationControl_B.alpha *
      DestinationControl_B.alpha;
    DestinationControl_B.alpha = DestinationControl_B.v12 /
      DestinationControl_B.v12_c;
    p = (DestinationControl_B.alpha > 1.0);
    p_0 = (DestinationControl_B.alpha < 0.0);
    if (p) {
      DestinationControl_B.v12 = pt1[0];
    } else if (p_0) {
      DestinationControl_B.v12 = pt2[0];
    } else {
      DestinationControl_B.v12 = (1.0 - DestinationControl_B.alpha) * pt2[0] +
        DestinationControl_B.alpha * pt1[0];
    }

    DestinationControl_B.refPt[0] = refPt[0] - DestinationControl_B.v12;
    closestPoint[0] = DestinationControl_B.v12;
    if (p) {
      DestinationControl_B.v12 = pt1[1];
    } else if (p_0) {
      DestinationControl_B.v12 = pt2[1];
    } else {
      DestinationControl_B.v12 = (1.0 - DestinationControl_B.alpha) * pt2[1] +
        DestinationControl_B.alpha * pt1[1];
    }

    DestinationControl_B.refPt[1] = refPt[1] - DestinationControl_B.v12;
    closestPoint[1] = DestinationControl_B.v12;
    *distance = DestinationControl_norm(DestinationControl_B.refPt);
  }
}

static void De_PurePursuitBase_stepInternal(nav_slalgs_internal_PurePursu_T *obj,
  const real_T currentPose[3], const real_T wayptsIn[4], real_T *v, real_T *w,
  real_T lookaheadPoint[2], real_T *targetDir)
{
  boolean_T b[4];
  int32_T trueCount;
  int32_T i;
  int32_T partialTrueCount;
  boolean_T searchFlag;
  int32_T b_i;
  int32_T i_tmp;
  boolean_T exitg1;
  b[0] = !rtIsNaN(wayptsIn[0]);
  b[1] = !rtIsNaN(wayptsIn[1]);
  b[2] = !rtIsNaN(wayptsIn[2]);
  b[3] = !rtIsNaN(wayptsIn[3]);
  trueCount = 0;
  partialTrueCount = 0;
  for (i = 0; i < 2; i++) {
    if (b[i] && b[i + 2]) {
      trueCount++;
      DestinationControl_B.f_data[partialTrueCount] = i + 1;
      partialTrueCount++;
    }
  }

  for (i = 0; i < trueCount; i++) {
    DestinationControl_B.waypoints_data[i] =
      wayptsIn[DestinationControl_B.f_data[i] - 1];
    DestinationControl_B.waypoints_data[i + trueCount] =
      wayptsIn[DestinationControl_B.f_data[i] + 1];
  }

  if (trueCount == 0) {
    *v = 0.0;
    *w = 0.0;
    *targetDir = 0.0;
    lookaheadPoint[0] = currentPose[0];
    lookaheadPoint[1] = currentPose[1];
  } else {
    searchFlag = false;
    if (obj->ProjectionLineIndex == 0.0) {
      searchFlag = true;
      obj->ProjectionPoint[0] = DestinationControl_B.waypoints_data[0];
      obj->ProjectionPoint[1] = DestinationControl_B.waypoints_data[trueCount];
      obj->ProjectionLineIndex = 1.0;
    }

    if (trueCount == 1) {
      obj->ProjectionPoint[0] = DestinationControl_B.waypoints_data[0];
      obj->ProjectionPoint[1] = DestinationControl_B.waypoints_data[trueCount];
      DestinationControl_B.lookaheadStartPt[0] =
        DestinationControl_B.waypoints_data[0];
      DestinationControl_B.lookaheadStartPt[1] =
        DestinationControl_B.waypoints_data[trueCount];
    } else {
      i = static_cast<int32_T>(obj->ProjectionLineIndex + 1.0);
      DestinationControl_B.waypoints[0] = DestinationControl_B.waypoints_data[i
        - 1];
      DestinationControl_B.waypoints[1] = DestinationControl_B.waypoints_data[(i
        + trueCount) - 1];
      for (i = 0; i < 2; i++) {
        DestinationControl_B.lookaheadStartPt[i] = obj->ProjectionPoint[i];
      }

      DestinationC_closestPointOnLine(DestinationControl_B.lookaheadStartPt,
        DestinationControl_B.waypoints, &currentPose[0], obj->ProjectionPoint,
        &DestinationControl_B.minDistance);
      i = static_cast<int32_T>(obj->ProjectionLineIndex + 1.0);
      DestinationControl_B.lookaheadStartPt[0] = obj->ProjectionPoint[0] -
        DestinationControl_B.waypoints_data[i - 1];
      DestinationControl_B.lookaheadStartPt[1] = obj->ProjectionPoint[1] -
        DestinationControl_B.waypoints_data[(i + trueCount) - 1];
      DestinationControl_B.dist = DestinationControl_norm
        (DestinationControl_B.lookaheadStartPt);
      DestinationControl_B.lookaheadEndPt_idx_1 = obj->ProjectionLineIndex + 1.0;
      partialTrueCount = static_cast<int32_T>((1.0 - (obj->ProjectionLineIndex +
        1.0)) + (static_cast<real_T>(trueCount) - 1.0)) - 1;
      b_i = 0;
      exitg1 = false;
      while ((!exitg1) && (b_i <= partialTrueCount)) {
        DestinationControl_B.overshootDist =
          DestinationControl_B.lookaheadEndPt_idx_1 + static_cast<real_T>(b_i);
        if ((!searchFlag) && (DestinationControl_B.dist > obj->LookaheadDistance))
        {
          exitg1 = true;
        } else {
          i_tmp = static_cast<int32_T>(DestinationControl_B.overshootDist);
          i = static_cast<int32_T>(DestinationControl_B.overshootDist + 1.0);
          DestinationControl_B.waypoints[0] =
            DestinationControl_B.waypoints_data[i_tmp - 1] -
            DestinationControl_B.waypoints_data[i - 1];
          DestinationControl_B.waypoints_c[0] =
            DestinationControl_B.waypoints_data[i_tmp - 1];
          DestinationControl_B.waypoints_k[0] =
            DestinationControl_B.waypoints_data[1];
          DestinationControl_B.waypoints[1] =
            DestinationControl_B.waypoints_data[(i_tmp + trueCount) - 1] -
            DestinationControl_B.waypoints_data[(i + trueCount) - 1];
          DestinationControl_B.waypoints_c[1] =
            DestinationControl_B.waypoints_data[(i_tmp + trueCount) - 1];
          DestinationControl_B.waypoints_k[1] =
            DestinationControl_B.waypoints_data[trueCount + 1];
          DestinationControl_B.dist += DestinationControl_norm
            (DestinationControl_B.waypoints);
          DestinationC_closestPointOnLine(DestinationControl_B.waypoints_c,
            DestinationControl_B.waypoints_k, &currentPose[0],
            DestinationControl_B.lookaheadStartPt,
            &DestinationControl_B.lookaheadIdx);
          if (DestinationControl_B.lookaheadIdx <
              DestinationControl_B.minDistance) {
            DestinationControl_B.minDistance = DestinationControl_B.lookaheadIdx;
            obj->ProjectionPoint[0] = DestinationControl_B.lookaheadStartPt[0];
            obj->ProjectionPoint[1] = DestinationControl_B.lookaheadStartPt[1];
            obj->ProjectionLineIndex = DestinationControl_B.overshootDist;
          }

          b_i++;
        }
      }

      i = static_cast<int32_T>(obj->ProjectionLineIndex + 1.0);
      DestinationControl_B.lookaheadStartPt[0] = obj->ProjectionPoint[0] -
        DestinationControl_B.waypoints_data[i - 1];
      DestinationControl_B.lookaheadStartPt[1] = obj->ProjectionPoint[1] -
        DestinationControl_B.waypoints_data[(i + trueCount) - 1];
      DestinationControl_B.dist = DestinationControl_norm
        (DestinationControl_B.lookaheadStartPt);
      i = static_cast<int32_T>(obj->ProjectionLineIndex + 1.0);
      DestinationControl_B.lookaheadStartPt[0] = obj->ProjectionPoint[0];
      DestinationControl_B.minDistance = DestinationControl_B.waypoints_data[i -
        1];
      DestinationControl_B.lookaheadStartPt[1] = obj->ProjectionPoint[1];
      DestinationControl_B.lookaheadEndPt_idx_1 =
        DestinationControl_B.waypoints_data[(i + trueCount) - 1];
      DestinationControl_B.overshootDist = DestinationControl_B.dist -
        obj->LookaheadDistance;
      DestinationControl_B.lookaheadIdx = obj->ProjectionLineIndex;
      while ((DestinationControl_B.overshootDist < 0.0) &&
             (DestinationControl_B.lookaheadIdx < static_cast<real_T>(trueCount)
              - 1.0)) {
        DestinationControl_B.lookaheadIdx++;
        i = static_cast<int32_T>(DestinationControl_B.lookaheadIdx);
        DestinationControl_B.lookaheadStartPt[0] =
          DestinationControl_B.waypoints_data[i - 1];
        DestinationControl_B.waypoints[0] =
          DestinationControl_B.waypoints_data[i - 1] -
          DestinationControl_B.waypoints_data[1];
        DestinationControl_B.minDistance = DestinationControl_B.waypoints_data[1];
        DestinationControl_B.lookaheadStartPt[1] =
          DestinationControl_B.waypoints_data[(i + trueCount) - 1];
        DestinationControl_B.lookaheadEndPt_idx_1 =
          DestinationControl_B.waypoints_data[trueCount + 1];
        DestinationControl_B.waypoints[1] = DestinationControl_B.waypoints_data
          [(i + trueCount) - 1] - DestinationControl_B.lookaheadEndPt_idx_1;
        DestinationControl_B.dist += DestinationControl_norm
          (DestinationControl_B.waypoints);
        DestinationControl_B.overshootDist = DestinationControl_B.dist -
          obj->LookaheadDistance;
      }

      DestinationControl_B.waypoints[0] = DestinationControl_B.lookaheadStartPt
        [0] - DestinationControl_B.minDistance;
      DestinationControl_B.waypoints[1] = DestinationControl_B.lookaheadStartPt
        [1] - DestinationControl_B.lookaheadEndPt_idx_1;
      DestinationControl_B.dist = DestinationControl_B.overshootDist /
        DestinationControl_norm(DestinationControl_B.waypoints);
      if (DestinationControl_B.dist > 0.0) {
        DestinationControl_B.lookaheadStartPt[0] = (1.0 -
          DestinationControl_B.dist) * DestinationControl_B.minDistance +
          DestinationControl_B.dist * DestinationControl_B.lookaheadStartPt[0];
        DestinationControl_B.lookaheadStartPt[1] = (1.0 -
          DestinationControl_B.dist) * DestinationControl_B.lookaheadEndPt_idx_1
          + DestinationControl_B.dist * DestinationControl_B.lookaheadStartPt[1];
      } else {
        DestinationControl_B.lookaheadStartPt[0] =
          DestinationControl_B.minDistance;
        DestinationControl_B.lookaheadStartPt[1] =
          DestinationControl_B.lookaheadEndPt_idx_1;
      }
    }

    obj->LookaheadPoint[0] = DestinationControl_B.lookaheadStartPt[0];
    obj->LookaheadPoint[1] = DestinationControl_B.lookaheadStartPt[1];
    *targetDir = rt_atan2d_snf(obj->LookaheadPoint[1] - currentPose[1],
      obj->LookaheadPoint[0] - currentPose[0]) - currentPose[2];
    if (fabs(*targetDir) > 3.1415926535897931) {
      if (rtIsNaN(*targetDir + 3.1415926535897931) || rtIsInf(*targetDir +
           3.1415926535897931)) {
        DestinationControl_B.dist = (rtNaN);
      } else if (*targetDir + 3.1415926535897931 == 0.0) {
        DestinationControl_B.dist = 0.0;
      } else {
        DestinationControl_B.dist = fmod(*targetDir + 3.1415926535897931,
          6.2831853071795862);
        searchFlag = (DestinationControl_B.dist == 0.0);
        if (!searchFlag) {
          DestinationControl_B.minDistance = fabs((*targetDir +
            3.1415926535897931) / 6.2831853071795862);
          searchFlag = !(fabs(DestinationControl_B.minDistance - floor
                              (DestinationControl_B.minDistance + 0.5)) >
                         2.2204460492503131E-16 *
                         DestinationControl_B.minDistance);
        }

        if (searchFlag) {
          DestinationControl_B.dist = 0.0;
        } else {
          if (*targetDir + 3.1415926535897931 < 0.0) {
            DestinationControl_B.dist += 6.2831853071795862;
          }
        }
      }

      DestinationControl_B.b = DestinationControl_B.dist;
      if ((DestinationControl_B.dist == 0.0) && (*targetDir + 3.1415926535897931
           > 0.0)) {
        DestinationControl_B.b = 6.2831853071795862;
      }

      *targetDir = DestinationControl_B.b - 3.1415926535897931;
    }

    *w = 2.0 * sin(*targetDir) / obj->LookaheadDistance;
    if (fabs(fabs(*targetDir) - 3.1415926535897931) < 1.4901161193847656E-8) {
      if (*w < 0.0) {
        *w = -1.0;
      } else if (*w > 0.0) {
        *w = 1.0;
      } else if (*w == 0.0) {
        *w = 0.0;
      } else {
        *w = (rtNaN);
      }
    }

    if (fabs(*w) > obj->MaxAngularVelocity) {
      if (*w < 0.0) {
        *w = -1.0;
      } else if (*w > 0.0) {
        *w = 1.0;
      } else if (*w == 0.0) {
        *w = 0.0;
      } else {
        *w = (rtNaN);
      }

      *w *= obj->MaxAngularVelocity;
    }

    *v = obj->DesiredLinearVelocity;
    lookaheadPoint[0] = obj->LookaheadPoint[0];
    lookaheadPoint[1] = obj->LookaheadPoint[1];
    obj->LastPose[0] = currentPose[0];
    obj->LastPose[1] = currentPose[1];
    obj->LastPose[2] = currentPose[2];
    if (rtIsNaN(*targetDir)) {
      *targetDir = 0.0;
    }
  }
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
  boolean_T p;
  boolean_T b_varargout_1;
  int32_T rtb_y;
  boolean_T exitg1;

  // Outputs for Atomic SubSystem: '<Root>/Subscribe'
  // MATLABSystem: '<S5>/SourceBlock'
  b_varargout_1 = Sub_DestinationControl_7.getLatestMessage
    (&DestinationControl_B.b_varargout_2);

  // Outputs for Enabled SubSystem: '<Root>/Decode ROS msg' incorporates:
  //   EnablePort: '<S2>/Enable'

  // Outputs for Enabled SubSystem: '<S5>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S8>/Enable'

  if (b_varargout_1) {
    // MATLABSystem: '<S2>/Coordinate Transformation Conversion' incorporates:
    //   SignalConversion generated from: '<S2>/Coordinate Transformation Conversion'

    DestinationControl_B.posDiff_idx_1 = 1.0 / sqrt
      (((DestinationControl_B.b_varargout_2.Pose.Pose.Orientation.W *
         DestinationControl_B.b_varargout_2.Pose.Pose.Orientation.W +
         DestinationControl_B.b_varargout_2.Pose.Pose.Orientation.X *
         DestinationControl_B.b_varargout_2.Pose.Pose.Orientation.X) +
        DestinationControl_B.b_varargout_2.Pose.Pose.Orientation.Y *
        DestinationControl_B.b_varargout_2.Pose.Pose.Orientation.Y) +
       DestinationControl_B.b_varargout_2.Pose.Pose.Orientation.Z *
       DestinationControl_B.b_varargout_2.Pose.Pose.Orientation.Z);
    DestinationControl_B.b_z1_idx_0 =
      DestinationControl_B.b_varargout_2.Pose.Pose.Orientation.W *
      DestinationControl_B.posDiff_idx_1;
    DestinationControl_B.b_z1_idx_1 =
      DestinationControl_B.b_varargout_2.Pose.Pose.Orientation.X *
      DestinationControl_B.posDiff_idx_1;
    DestinationControl_B.posDiff_idx_0 =
      DestinationControl_B.b_varargout_2.Pose.Pose.Orientation.Y *
      DestinationControl_B.posDiff_idx_1;
    DestinationControl_B.posDiff_idx_1 *=
      DestinationControl_B.b_varargout_2.Pose.Pose.Orientation.Z;

    // DataTypeConversion: '<S2>/Data Type Conversion2' incorporates:
    //   MATLABSystem: '<S2>/Coordinate Transformation Conversion'

    DestinationControl_B.DataTypeConversion2 = rt_atan2d_snf
      ((DestinationControl_B.b_z1_idx_1 * DestinationControl_B.posDiff_idx_0 -
        DestinationControl_B.posDiff_idx_1 * DestinationControl_B.b_z1_idx_0) *
       -2.0, ((DestinationControl_B.b_z1_idx_0 * DestinationControl_B.b_z1_idx_0
               + DestinationControl_B.b_z1_idx_1 *
               DestinationControl_B.b_z1_idx_1) -
              DestinationControl_B.posDiff_idx_0 *
              DestinationControl_B.posDiff_idx_0) -
       DestinationControl_B.posDiff_idx_1 * DestinationControl_B.posDiff_idx_1);

    // DataTypeConversion: '<S2>/Data Type Conversion'
    DestinationControl_B.DataTypeConversion =
      DestinationControl_B.b_varargout_2.Pose.Pose.Position.X;

    // DataTypeConversion: '<S2>/Data Type Conversion1'
    DestinationControl_B.DataTypeConversion1 =
      DestinationControl_B.b_varargout_2.Pose.Pose.Position.Y;
  }

  // End of MATLABSystem: '<S5>/SourceBlock'
  // End of Outputs for SubSystem: '<S5>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Decode ROS msg'
  // End of Outputs for SubSystem: '<Root>/Subscribe'

  // Outputs for Atomic SubSystem: '<Root>/Subscribe3'
  // MATLABSystem: '<S6>/SourceBlock' incorporates:
  //   Inport: '<S9>/In1'

  b_varargout_1 = Sub_DestinationControl_61.getLatestMessage
    (&DestinationControl_B.b_varargout_2_m);

  // Outputs for Enabled SubSystem: '<Root>/Subsystem' incorporates:
  //   EnablePort: '<S7>/Enable'

  // Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S9>/Enable'

  if (b_varargout_1) {
    DestinationControl_B.In1_o = DestinationControl_B.b_varargout_2_m;

    // MATLAB Function: '<S10>/MATLAB Function' incorporates:
    //   Inport: '<S9>/In1'

    DestinationControl_B.u[0] = DestinationControl_B.DataTypeConversion;
    DestinationControl_B.u[2] = DestinationControl_B.DataTypeConversion1;
    DestinationControl_B.u[1] = DestinationControl_B.In1_o.X;
    DestinationControl_B.u[3] = DestinationControl_B.In1_o.Y;
  }

  // End of MATLABSystem: '<S6>/SourceBlock'
  // End of Outputs for SubSystem: '<S6>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe3'

  // MATLABSystem: '<Root>/Pure Pursuit' incorporates:
  //   SignalConversion generated from: '<Root>/Pure Pursuit'

  if (DestinationControl_DW.obj.DesiredLinearVelocity !=
      DestinationControl_P.PurePursuit_DesiredLinearVeloci) {
    DestinationControl_DW.obj.DesiredLinearVelocity =
      DestinationControl_P.PurePursuit_DesiredLinearVeloci;
  }

  if (DestinationControl_DW.obj.MaxAngularVelocity !=
      DestinationControl_P.PurePursuit_MaxAngularVelocity) {
    DestinationControl_DW.obj.MaxAngularVelocity =
      DestinationControl_P.PurePursuit_MaxAngularVelocity;
  }

  if (DestinationControl_DW.obj.LookaheadDistance !=
      DestinationControl_P.PurePursuit_LookaheadDistance) {
    DestinationControl_DW.obj.LookaheadDistance =
      DestinationControl_P.PurePursuit_LookaheadDistance;
  }

  b_varargout_1 = false;
  p = true;
  rtb_y = 0;
  exitg1 = false;
  while ((!exitg1) && (rtb_y < 4)) {
    if ((DestinationControl_DW.obj.WaypointsInternal[rtb_y] ==
         DestinationControl_B.u[rtb_y]) || (rtIsNaN
         (DestinationControl_DW.obj.WaypointsInternal[rtb_y]) && rtIsNaN
         (DestinationControl_B.u[rtb_y]))) {
      rtb_y++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (p) {
    b_varargout_1 = true;
  }

  if (!b_varargout_1) {
    DestinationControl_DW.obj.WaypointsInternal[0] = DestinationControl_B.u[0];
    DestinationControl_DW.obj.WaypointsInternal[1] = DestinationControl_B.u[1];
    DestinationControl_DW.obj.WaypointsInternal[2] = DestinationControl_B.u[2];
    DestinationControl_DW.obj.WaypointsInternal[3] = DestinationControl_B.u[3];
    DestinationControl_DW.obj.ProjectionLineIndex = 0.0;
  }

  DestinationControl_B.dv[0] = DestinationControl_B.DataTypeConversion;
  DestinationControl_B.dv[1] = DestinationControl_B.DataTypeConversion1;
  DestinationControl_B.dv[2] = DestinationControl_B.DataTypeConversion2;
  De_PurePursuitBase_stepInternal(&DestinationControl_DW.obj,
    DestinationControl_B.dv, DestinationControl_B.u,
    &DestinationControl_B.b_z1_idx_0, &DestinationControl_B.b_z1_idx_1,
    DestinationControl_B.unusedU0, &DestinationControl_B.posDiff_idx_0);

  // MATLAB Function: '<Root>/MATLAB Function' incorporates:
  //   Constant: '<Root>/Constant'

  DestinationControl_B.posDiff_idx_0 = DestinationControl_B.In1_o.X -
    DestinationControl_B.DataTypeConversion;
  DestinationControl_B.posDiff_idx_1 = DestinationControl_B.In1_o.Y -
    DestinationControl_B.DataTypeConversion1;
  rtb_y = (sqrt(DestinationControl_B.posDiff_idx_0 *
                DestinationControl_B.posDiff_idx_0 +
                DestinationControl_B.posDiff_idx_1 *
                DestinationControl_B.posDiff_idx_1) <=
           DestinationControl_P.Constant_Value_g);

  // BusAssignment: '<Root>/Bus Assignment1' incorporates:
  //   Constant: '<S1>/Constant'

  DestinationControl_B.BusAssignment1 = DestinationControl_P.Constant_Value_d;

  // Switch: '<Root>/Switch'
  if (rtb_y > DestinationControl_P.Switch_Threshold) {
    // BusAssignment: '<Root>/Bus Assignment1' incorporates:
    //   Constant: '<Root>/Constant1'

    DestinationControl_B.BusAssignment1.Linear.X =
      DestinationControl_P.Constant1_Value;
  } else {
    // BusAssignment: '<Root>/Bus Assignment1' incorporates:
    //   MATLABSystem: '<Root>/Pure Pursuit'

    DestinationControl_B.BusAssignment1.Linear.X =
      DestinationControl_B.b_z1_idx_0;
  }

  // End of Switch: '<Root>/Switch'

  // Switch: '<Root>/Switch1'
  if (rtb_y > DestinationControl_P.Switch1_Threshold) {
    // BusAssignment: '<Root>/Bus Assignment1' incorporates:
    //   Constant: '<Root>/Constant1'

    DestinationControl_B.BusAssignment1.Angular.Z =
      DestinationControl_P.Constant1_Value;
  } else {
    // BusAssignment: '<Root>/Bus Assignment1' incorporates:
    //   MATLABSystem: '<Root>/Pure Pursuit'

    DestinationControl_B.BusAssignment1.Angular.Z =
      DestinationControl_B.b_z1_idx_1;
  }

  // End of Switch: '<Root>/Switch1'

  // Outputs for Atomic SubSystem: '<Root>/Publish'
  // MATLABSystem: '<S4>/SinkBlock'
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
    char_T tmp_0[13];
    char_T tmp_1[9];
    int32_T i;
    static const char_T tmp_2[5] = { '/', 'o', 'd', 'o', 'm' };

    static const char_T tmp_3[12] = { '/', 'd', 'e', 's', 't', 'i', 'n', 'a',
      't', 'i', 'o', 'n' };

    static const char_T tmp_4[8] = { '/', 'c', 'm', 'd', '_', 'v', 'e', 'l' };

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe'
    // Start for MATLABSystem: '<S5>/SourceBlock'
    DestinationControl_DW.obj_n.matlabCodegenIsDeleted = false;
    DestinationControl_DW.obj_n.isInitialized = 1;
    for (i = 0; i < 5; i++) {
      tmp[i] = tmp_2[i];
    }

    tmp[5] = '\x00';
    Sub_DestinationControl_7.createSubscriber(tmp, 1);
    DestinationControl_DW.obj_n.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe'

    // SystemInitialize for Enabled SubSystem: '<Root>/Decode ROS msg'
    // SystemInitialize for Outport: '<S2>/X'
    DestinationControl_B.DataTypeConversion = DestinationControl_P.X_Y0;

    // SystemInitialize for Outport: '<S2>/Y'
    DestinationControl_B.DataTypeConversion1 = DestinationControl_P.Y_Y0;

    // SystemInitialize for Outport: '<S2>/Theta'
    DestinationControl_B.DataTypeConversion2 = DestinationControl_P.Theta_Y0;

    // End of SystemInitialize for SubSystem: '<Root>/Decode ROS msg'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe3'
    // SystemInitialize for Enabled SubSystem: '<S6>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S9>/Out1'
    DestinationControl_B.In1_o = DestinationControl_P.Out1_Y0_e;

    // End of SystemInitialize for SubSystem: '<S6>/Enabled Subsystem'

    // Start for MATLABSystem: '<S6>/SourceBlock'
    DestinationControl_DW.obj_c.matlabCodegenIsDeleted = false;
    DestinationControl_DW.obj_c.isInitialized = 1;
    for (i = 0; i < 12; i++) {
      tmp_0[i] = tmp_3[i];
    }

    tmp_0[12] = '\x00';
    Sub_DestinationControl_61.createSubscriber(tmp_0, 1);
    DestinationControl_DW.obj_c.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S6>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe3'

    // SystemInitialize for Enabled SubSystem: '<Root>/Subsystem'
    // SystemInitialize for Outport: '<S7>/waypoints'
    DestinationControl_B.u[0] = DestinationControl_P.waypoints_Y0;
    DestinationControl_B.u[1] = DestinationControl_P.waypoints_Y0;
    DestinationControl_B.u[2] = DestinationControl_P.waypoints_Y0;
    DestinationControl_B.u[3] = DestinationControl_P.waypoints_Y0;

    // End of SystemInitialize for SubSystem: '<Root>/Subsystem'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish'
    // Start for MATLABSystem: '<S4>/SinkBlock'
    DestinationControl_DW.obj_d.matlabCodegenIsDeleted = false;
    DestinationControl_DW.obj_d.isInitialized = 1;
    for (i = 0; i < 8; i++) {
      tmp_1[i] = tmp_4[i];
    }

    tmp_1[8] = '\x00';
    Pub_DestinationControl_5.createPublisher(tmp_1, 1);
    DestinationControl_DW.obj_d.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S4>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish'

    // Start for MATLABSystem: '<Root>/Pure Pursuit'
    DestinationControl_DW.obj.DesiredLinearVelocity =
      DestinationControl_P.PurePursuit_DesiredLinearVeloci;
    DestinationControl_DW.obj.MaxAngularVelocity =
      DestinationControl_P.PurePursuit_MaxAngularVelocity;
    DestinationControl_DW.obj.LookaheadDistance =
      DestinationControl_P.PurePursuit_LookaheadDistance;
    DestinationControl_DW.obj.isInitialized = 1;
    DestinationControl_DW.obj.WaypointsInternal[0] = (rtNaN);
    DestinationControl_DW.obj.WaypointsInternal[1] = (rtNaN);
    DestinationControl_DW.obj.WaypointsInternal[2] = (rtNaN);
    DestinationControl_DW.obj.WaypointsInternal[3] = (rtNaN);
    DestinationControl_DW.obj.LookaheadPoint[0] = 0.0;
    DestinationControl_DW.obj.LookaheadPoint[1] = 0.0;
    DestinationControl_DW.obj.LastPose[0] = 0.0;
    DestinationControl_DW.obj.LastPose[1] = 0.0;
    DestinationControl_DW.obj.LastPose[2] = 0.0;
    DestinationControl_DW.obj.ProjectionLineIndex = 0.0;

    // InitializeConditions for MATLABSystem: '<Root>/Pure Pursuit'
    DestinationControl_DW.obj.LookaheadPoint[0] *= 0.0;
    DestinationControl_DW.obj.LookaheadPoint[1] *= 0.0;
    DestinationControl_DW.obj.LastPose[0] *= 0.0;
    DestinationControl_DW.obj.LastPose[1] *= 0.0;
    DestinationControl_DW.obj.LastPose[2] *= 0.0;
    DestinationControl_DW.obj.ProjectionPoint[0] = (rtNaN);
    DestinationControl_DW.obj.ProjectionPoint[1] = (rtNaN);
    DestinationControl_DW.obj.ProjectionLineIndex *= 0.0;
  }
}

// Model terminate function
void DestinationControl_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Terminate for MATLABSystem: '<S5>/SourceBlock'
  matlabCodegenHandle_matlabCod_f(&DestinationControl_DW.obj_n);

  // End of Terminate for SubSystem: '<Root>/Subscribe'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe3'
  // Terminate for MATLABSystem: '<S6>/SourceBlock'
  matlabCodegenHandle_matlabCod_f(&DestinationControl_DW.obj_c);

  // End of Terminate for SubSystem: '<Root>/Subscribe3'

  // Terminate for Atomic SubSystem: '<Root>/Publish'
  // Terminate for MATLABSystem: '<S4>/SinkBlock'
  matlabCodegenHandle_matlabCodeg(&DestinationControl_DW.obj_d);

  // End of Terminate for SubSystem: '<Root>/Publish'
}

//
// File trailer for generated code.
//
// [EOF]
//
