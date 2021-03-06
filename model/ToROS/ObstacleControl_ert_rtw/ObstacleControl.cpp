//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ObstacleControl.cpp
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
#include "ObstacleControl.h"
#include "ObstacleControl_private.h"

// Block signals (default storage)
B_ObstacleControl_T ObstacleControl_B;

// Block states (default storage)
DW_ObstacleControl_T ObstacleControl_DW;

// Real-time model
RT_MODEL_ObstacleControl_T ObstacleControl_M_ = RT_MODEL_ObstacleControl_T();
RT_MODEL_ObstacleControl_T *const ObstacleControl_M = &ObstacleControl_M_;

// Forward declaration for local functions
static real_T ObstacleControl_norm(const real_T x[2]);
static void ObstacleCont_closestPointOnLine(const real_T pt1[2], const real_T
  pt2[2], const real_T refPt[2], real_T closestPoint[2], real_T *distance);
static void Ob_PurePursuitBase_stepInternal(nav_slalgs_internal_PurePursu_T *obj,
  const real_T currentPose[3], const real_T wayptsIn[4], real_T *v, real_T *w,
  real_T lookaheadPoint[2], real_T *targetDir);
static void SystemCore_initializeInputSizes(nav_slalgs_internal_VectorFie_T *obj,
  const int32_T *varargin_1_size, const int32_T *varargin_2_size);
static void SystemCore_systemblock_prestep(nav_slalgs_internal_VectorFie_T *obj,
  const int32_T *varargin_1_size, const int32_T *varargin_2_size);
static boolean_T SystemCore_detectInputSizeChang(nav_slalgs_internal_VectorFie_T
  *obj, const int32_T *varargin_1_size, const int32_T *varargin_2_size);
static real32_T ObstacleControl_floatmod(real32_T x);
static void ObstacleControl_wrapToPi_ngg(real32_T theta_data[], const int32_T
  *theta_size);
static void ObstacleC_lidarScan_lidarScan_n(const real32_T varargin_2_data[],
  const int32_T *varargin_2_size, real32_T obj_InternalAngles_data[], int32_T
  *obj_InternalAngles_size, boolean_T *obj_ContainsOnlyFiniteData);
static real32_T ObstacleControl_wrapToPi_n(real32_T theta);
static void ObstacleControl_sort(const real32_T x[2], real32_T b_x[2]);
static void ObstacleControl_isfinite(const real32_T x_data[], const int32_T
  *x_size, boolean_T b_data[], int32_T *b_size);
static void ObstacleContro_nullAssignment_n(real32_T x_data[], int32_T *x_size,
  const boolean_T idx_data[], const int32_T *idx_size);
static boolean_T O_lidarScan_removeInvalidData_n(real32_T
  objIn_InternalRanges_data[], int32_T *objIn_InternalRanges_size, real32_T
  objIn_InternalAngles_data[], int32_T *objIn_InternalAngles_size, const
  real32_T varargin_2[2]);
static boolean_T ObstacleControl_isequal(void);
static void ObstacleControl_asin(const real32_T x_data[], const int32_T *x_size,
  real32_T b_x_data[], int32_T *b_x_size);
static void ObstacleControl_cos(const real32_T x_data[], const int32_T *x_size,
  real32_T b_x_data[], int32_T *b_x_size);
static void ObstacleControl_sin(const real32_T x_data[], const int32_T *x_size,
  real32_T b_x_data[], int32_T *b_x_size);
static void ObstacleControl_cross(const real32_T a_data[], const int32_T a_size
  [2], const real32_T b_data[], real32_T c_data[], int32_T c_size[2]);
static void ObstacleControl_repmat(const real32_T a[3], real_T varargin_1,
  real32_T b_data[], int32_T b_size[2]);
static void ObstacleControl_sign_n(real32_T x_data[], const int32_T *x_size);
static void ObstacleControl_abs(const real32_T x_data[], const int32_T *x_size,
  real32_T y_data[], int32_T *y_size);
static void ObstacleControl_histc(const real32_T X_data[], const int32_T *X_size,
  const real32_T edges[36], real_T N[36], real_T BIN_data[], int32_T *BIN_size);
static void VectorFieldHistogramBase_buildP(nav_slalgs_internal_VectorFie_T *obj,
  const real32_T scan_InternalRanges_data[], const int32_T
  *scan_InternalRanges_size, const real32_T scan_InternalAngles_data[], const
  int32_T *scan_InternalAngles_size);
static void ObstacleControl_power(const real32_T a_data[], const int32_T *a_size,
  real32_T y_data[], int32_T *y_size);
static void ObstacleControl_sqrt_n(real32_T x_data[], const int32_T *x_size);
static void VectorFieldHistogramBase_buildM(nav_slalgs_internal_VectorFie_T *obj,
  const real32_T scan_InternalRanges_data[], const int32_T
  *scan_InternalRanges_size, const real32_T scan_InternalAngles_data[], const
  int32_T *scan_InternalAngles_size);
static void ObstacleControl_diff(const real_T x[38], real_T y[37]);
static boolean_T ObstacleControl_any(const real32_T x[37]);
static void ObstacleControl_diff_n(const real32_T x_data[], const int32_T
  x_size[2], real32_T y_data[], int32_T y_size[2]);
static void ObstacleControl_wrapToPi_ng(const real32_T theta_data[], const
  int32_T theta_size[2], real32_T b_theta_data[], int32_T b_theta_size[2]);
static void ObstacleControl_bisectAngles(real32_T theta1_data[], int32_T
  theta1_size[2], real32_T theta2_data[], const int32_T theta2_size[2], real32_T
  bisect_data[], int32_T bisect_size[2]);
static void ObstacleControl_bsxfun(const real32_T a[36], const real32_T b_data[],
  const int32_T *b_size, real32_T c_data[], int32_T c_size[2]);
static void ObstacleControl_abs_n(const real32_T x_data[], const int32_T x_size
  [2], real32_T y_data[], int32_T y_size[2]);
static void ObstacleControl_bsxfun_n(const real32_T a_data[], const int32_T
  a_size[2], const real32_T b_data[], const int32_T *b_size, real32_T c_data[],
  int32_T c_size[2]);
static boolean_T ObstacleControl_any_n(const boolean_T x_data[], const int32_T
  x_size[2]);
static void VectorFieldHistogramBase_comput(const
  nav_slalgs_internal_VectorFie_T *obj, const real32_T c_data[], const int32_T
  c_size[2], real32_T targetDir, real32_T prevDir, real32_T cost_data[], int32_T
  cost_size[2]);
static real32_T VectorFieldHistogramBase_select(nav_slalgs_internal_VectorFie_T *
  obj, real32_T targetDir);
static real32_T VectorFieldHistogramBase_stepIm(nav_slalgs_internal_VectorFie_T *
  obj, const real32_T varargin_1_data[], const int32_T *varargin_1_size, const
  real_T varargin_2_data[], const int32_T *varargin_2_size, real32_T varargin_3);
static real32_T ObstacleControl_SystemCore_step(nav_slalgs_internal_VectorFie_T *
  obj, const real32_T varargin_1_data[], const int32_T *varargin_1_size, const
  real_T varargin_2_data[], const int32_T *varargin_2_size, real32_T varargin_3);
static void matlabCodegenHandle_matlabCod_n(ros_slros_internal_block_Subs_T *obj);
static void matlabCodegenHandle_matlabCodeg(ros_slros_internal_block_Publ_T *obj);
static void VectorFieldHistogramBase_setupI(nav_slalgs_internal_VectorFie_T *obj);
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

static real_T ObstacleControl_norm(const real_T x[2])
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

static void ObstacleCont_closestPointOnLine(const real_T pt1[2], const real_T
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
    ObstacleControl_B.refPt[0] = refPt[0] - pt1[0];
    closestPoint[1] = pt1[1];
    ObstacleControl_B.refPt[1] = refPt[1] - pt1[1];
    *distance = ObstacleControl_norm(ObstacleControl_B.refPt);
  } else {
    ObstacleControl_B.alpha = pt2[0] - pt1[0];
    ObstacleControl_B.v12 = (pt2[0] - refPt[0]) * ObstacleControl_B.alpha;
    ObstacleControl_B.v12_h = ObstacleControl_B.alpha * ObstacleControl_B.alpha;
    ObstacleControl_B.alpha = pt2[1] - pt1[1];
    ObstacleControl_B.v12 += (pt2[1] - refPt[1]) * ObstacleControl_B.alpha;
    ObstacleControl_B.v12_h += ObstacleControl_B.alpha * ObstacleControl_B.alpha;
    ObstacleControl_B.alpha = ObstacleControl_B.v12 / ObstacleControl_B.v12_h;
    p = (ObstacleControl_B.alpha > 1.0);
    p_0 = (ObstacleControl_B.alpha < 0.0);
    if (p) {
      ObstacleControl_B.v12 = pt1[0];
    } else if (p_0) {
      ObstacleControl_B.v12 = pt2[0];
    } else {
      ObstacleControl_B.v12 = (1.0 - ObstacleControl_B.alpha) * pt2[0] +
        ObstacleControl_B.alpha * pt1[0];
    }

    ObstacleControl_B.refPt[0] = refPt[0] - ObstacleControl_B.v12;
    closestPoint[0] = ObstacleControl_B.v12;
    if (p) {
      ObstacleControl_B.v12 = pt1[1];
    } else if (p_0) {
      ObstacleControl_B.v12 = pt2[1];
    } else {
      ObstacleControl_B.v12 = (1.0 - ObstacleControl_B.alpha) * pt2[1] +
        ObstacleControl_B.alpha * pt1[1];
    }

    ObstacleControl_B.refPt[1] = refPt[1] - ObstacleControl_B.v12;
    closestPoint[1] = ObstacleControl_B.v12;
    *distance = ObstacleControl_norm(ObstacleControl_B.refPt);
  }
}

static void Ob_PurePursuitBase_stepInternal(nav_slalgs_internal_PurePursu_T *obj,
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
      ObstacleControl_B.f_data[partialTrueCount] = i + 1;
      partialTrueCount++;
    }
  }

  for (i = 0; i < trueCount; i++) {
    ObstacleControl_B.waypoints_data[i] = wayptsIn[ObstacleControl_B.f_data[i] -
      1];
    ObstacleControl_B.waypoints_data[i + trueCount] =
      wayptsIn[ObstacleControl_B.f_data[i] + 1];
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
      obj->ProjectionPoint[0] = ObstacleControl_B.waypoints_data[0];
      obj->ProjectionPoint[1] = ObstacleControl_B.waypoints_data[trueCount];
      obj->ProjectionLineIndex = 1.0;
    }

    if (trueCount == 1) {
      obj->ProjectionPoint[0] = ObstacleControl_B.waypoints_data[0];
      obj->ProjectionPoint[1] = ObstacleControl_B.waypoints_data[trueCount];
      ObstacleControl_B.lookaheadStartPt[0] = ObstacleControl_B.waypoints_data[0];
      ObstacleControl_B.lookaheadStartPt[1] =
        ObstacleControl_B.waypoints_data[trueCount];
    } else {
      i = static_cast<int32_T>(obj->ProjectionLineIndex + 1.0);
      ObstacleControl_B.waypoints[0] = ObstacleControl_B.waypoints_data[i - 1];
      ObstacleControl_B.waypoints[1] = ObstacleControl_B.waypoints_data[(i +
        trueCount) - 1];
      for (i = 0; i < 2; i++) {
        ObstacleControl_B.lookaheadStartPt[i] = obj->ProjectionPoint[i];
      }

      ObstacleCont_closestPointOnLine(ObstacleControl_B.lookaheadStartPt,
        ObstacleControl_B.waypoints, &currentPose[0], obj->ProjectionPoint,
        &ObstacleControl_B.minDistance);
      i = static_cast<int32_T>(obj->ProjectionLineIndex + 1.0);
      ObstacleControl_B.lookaheadStartPt[0] = obj->ProjectionPoint[0] -
        ObstacleControl_B.waypoints_data[i - 1];
      ObstacleControl_B.lookaheadStartPt[1] = obj->ProjectionPoint[1] -
        ObstacleControl_B.waypoints_data[(i + trueCount) - 1];
      ObstacleControl_B.dist = ObstacleControl_norm
        (ObstacleControl_B.lookaheadStartPt);
      ObstacleControl_B.lookaheadEndPt_idx_1 = obj->ProjectionLineIndex + 1.0;
      partialTrueCount = static_cast<int32_T>((1.0 - (obj->ProjectionLineIndex +
        1.0)) + (static_cast<real_T>(trueCount) - 1.0)) - 1;
      b_i = 0;
      exitg1 = false;
      while ((!exitg1) && (b_i <= partialTrueCount)) {
        ObstacleControl_B.overshootDist = ObstacleControl_B.lookaheadEndPt_idx_1
          + static_cast<real_T>(b_i);
        if ((!searchFlag) && (ObstacleControl_B.dist > obj->LookaheadDistance))
        {
          exitg1 = true;
        } else {
          i_tmp = static_cast<int32_T>(ObstacleControl_B.overshootDist);
          i = static_cast<int32_T>(ObstacleControl_B.overshootDist + 1.0);
          ObstacleControl_B.waypoints[0] =
            ObstacleControl_B.waypoints_data[i_tmp - 1] -
            ObstacleControl_B.waypoints_data[i - 1];
          ObstacleControl_B.waypoints_l[0] =
            ObstacleControl_B.waypoints_data[i_tmp - 1];
          ObstacleControl_B.waypoints_o[0] = ObstacleControl_B.waypoints_data[1];
          ObstacleControl_B.waypoints[1] = ObstacleControl_B.waypoints_data
            [(i_tmp + trueCount) - 1] - ObstacleControl_B.waypoints_data[(i +
            trueCount) - 1];
          ObstacleControl_B.waypoints_l[1] = ObstacleControl_B.waypoints_data
            [(i_tmp + trueCount) - 1];
          ObstacleControl_B.waypoints_o[1] =
            ObstacleControl_B.waypoints_data[trueCount + 1];
          ObstacleControl_B.dist += ObstacleControl_norm
            (ObstacleControl_B.waypoints);
          ObstacleCont_closestPointOnLine(ObstacleControl_B.waypoints_l,
            ObstacleControl_B.waypoints_o, &currentPose[0],
            ObstacleControl_B.lookaheadStartPt, &ObstacleControl_B.lookaheadIdx);
          if (ObstacleControl_B.lookaheadIdx < ObstacleControl_B.minDistance) {
            ObstacleControl_B.minDistance = ObstacleControl_B.lookaheadIdx;
            obj->ProjectionPoint[0] = ObstacleControl_B.lookaheadStartPt[0];
            obj->ProjectionPoint[1] = ObstacleControl_B.lookaheadStartPt[1];
            obj->ProjectionLineIndex = ObstacleControl_B.overshootDist;
          }

          b_i++;
        }
      }

      i = static_cast<int32_T>(obj->ProjectionLineIndex + 1.0);
      ObstacleControl_B.lookaheadStartPt[0] = obj->ProjectionPoint[0] -
        ObstacleControl_B.waypoints_data[i - 1];
      ObstacleControl_B.lookaheadStartPt[1] = obj->ProjectionPoint[1] -
        ObstacleControl_B.waypoints_data[(i + trueCount) - 1];
      ObstacleControl_B.dist = ObstacleControl_norm
        (ObstacleControl_B.lookaheadStartPt);
      i = static_cast<int32_T>(obj->ProjectionLineIndex + 1.0);
      ObstacleControl_B.lookaheadStartPt[0] = obj->ProjectionPoint[0];
      ObstacleControl_B.minDistance = ObstacleControl_B.waypoints_data[i - 1];
      ObstacleControl_B.lookaheadStartPt[1] = obj->ProjectionPoint[1];
      ObstacleControl_B.lookaheadEndPt_idx_1 = ObstacleControl_B.waypoints_data
        [(i + trueCount) - 1];
      ObstacleControl_B.overshootDist = ObstacleControl_B.dist -
        obj->LookaheadDistance;
      ObstacleControl_B.lookaheadIdx = obj->ProjectionLineIndex;
      while ((ObstacleControl_B.overshootDist < 0.0) &&
             (ObstacleControl_B.lookaheadIdx < static_cast<real_T>(trueCount) -
              1.0)) {
        ObstacleControl_B.lookaheadIdx++;
        i = static_cast<int32_T>(ObstacleControl_B.lookaheadIdx);
        ObstacleControl_B.lookaheadStartPt[0] =
          ObstacleControl_B.waypoints_data[i - 1];
        ObstacleControl_B.waypoints[0] = ObstacleControl_B.waypoints_data[i - 1]
          - ObstacleControl_B.waypoints_data[1];
        ObstacleControl_B.minDistance = ObstacleControl_B.waypoints_data[1];
        ObstacleControl_B.lookaheadStartPt[1] =
          ObstacleControl_B.waypoints_data[(i + trueCount) - 1];
        ObstacleControl_B.lookaheadEndPt_idx_1 =
          ObstacleControl_B.waypoints_data[trueCount + 1];
        ObstacleControl_B.waypoints[1] = ObstacleControl_B.waypoints_data[(i +
          trueCount) - 1] - ObstacleControl_B.lookaheadEndPt_idx_1;
        ObstacleControl_B.dist += ObstacleControl_norm
          (ObstacleControl_B.waypoints);
        ObstacleControl_B.overshootDist = ObstacleControl_B.dist -
          obj->LookaheadDistance;
      }

      ObstacleControl_B.waypoints[0] = ObstacleControl_B.lookaheadStartPt[0] -
        ObstacleControl_B.minDistance;
      ObstacleControl_B.waypoints[1] = ObstacleControl_B.lookaheadStartPt[1] -
        ObstacleControl_B.lookaheadEndPt_idx_1;
      ObstacleControl_B.dist = ObstacleControl_B.overshootDist /
        ObstacleControl_norm(ObstacleControl_B.waypoints);
      if (ObstacleControl_B.dist > 0.0) {
        ObstacleControl_B.lookaheadStartPt[0] = (1.0 - ObstacleControl_B.dist) *
          ObstacleControl_B.minDistance + ObstacleControl_B.dist *
          ObstacleControl_B.lookaheadStartPt[0];
        ObstacleControl_B.lookaheadStartPt[1] = (1.0 - ObstacleControl_B.dist) *
          ObstacleControl_B.lookaheadEndPt_idx_1 + ObstacleControl_B.dist *
          ObstacleControl_B.lookaheadStartPt[1];
      } else {
        ObstacleControl_B.lookaheadStartPt[0] = ObstacleControl_B.minDistance;
        ObstacleControl_B.lookaheadStartPt[1] =
          ObstacleControl_B.lookaheadEndPt_idx_1;
      }
    }

    obj->LookaheadPoint[0] = ObstacleControl_B.lookaheadStartPt[0];
    obj->LookaheadPoint[1] = ObstacleControl_B.lookaheadStartPt[1];
    *targetDir = rt_atan2d_snf(obj->LookaheadPoint[1] - currentPose[1],
      obj->LookaheadPoint[0] - currentPose[0]) - currentPose[2];
    if (fabs(*targetDir) > 3.1415926535897931) {
      if (rtIsNaN(*targetDir + 3.1415926535897931) || rtIsInf(*targetDir +
           3.1415926535897931)) {
        ObstacleControl_B.dist = (rtNaN);
      } else if (*targetDir + 3.1415926535897931 == 0.0) {
        ObstacleControl_B.dist = 0.0;
      } else {
        ObstacleControl_B.dist = fmod(*targetDir + 3.1415926535897931,
          6.2831853071795862);
        searchFlag = (ObstacleControl_B.dist == 0.0);
        if (!searchFlag) {
          ObstacleControl_B.minDistance = fabs((*targetDir + 3.1415926535897931)
            / 6.2831853071795862);
          searchFlag = !(fabs(ObstacleControl_B.minDistance - floor
                              (ObstacleControl_B.minDistance + 0.5)) >
                         2.2204460492503131E-16 * ObstacleControl_B.minDistance);
        }

        if (searchFlag) {
          ObstacleControl_B.dist = 0.0;
        } else {
          if (*targetDir + 3.1415926535897931 < 0.0) {
            ObstacleControl_B.dist += 6.2831853071795862;
          }
        }
      }

      ObstacleControl_B.b_l = ObstacleControl_B.dist;
      if ((ObstacleControl_B.dist == 0.0) && (*targetDir + 3.1415926535897931 >
           0.0)) {
        ObstacleControl_B.b_l = 6.2831853071795862;
      }

      *targetDir = ObstacleControl_B.b_l - 3.1415926535897931;
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

static void SystemCore_initializeInputSizes(nav_slalgs_internal_VectorFie_T *obj,
  const int32_T *varargin_1_size, const int32_T *varargin_2_size)
{
  int32_T i;
  i = *varargin_1_size;
  if (*varargin_1_size < 0) {
    i = 0;
  }

  obj->inputVarSize[0].f1[0] = static_cast<uint32_T>(i);
  obj->inputVarSize[0].f1[1] = 1U;
  i = *varargin_2_size;
  if (*varargin_2_size < 0) {
    i = 0;
  }

  obj->inputVarSize[1].f1[0] = static_cast<uint32_T>(i);
  obj->inputVarSize[1].f1[1] = 1U;
  for (i = 0; i < 6; i++) {
    obj->inputVarSize[0].f1[i + 2] = 1U;
    obj->inputVarSize[1].f1[i + 2] = 1U;
  }

  for (i = 0; i < 8; i++) {
    obj->inputVarSize[2].f1[i] = 1U;
  }
}

static void SystemCore_systemblock_prestep(nav_slalgs_internal_VectorFie_T *obj,
  const int32_T *varargin_1_size, const int32_T *varargin_2_size)
{
  if (!obj->CacheInputSizes) {
    obj->CacheInputSizes = true;
    SystemCore_initializeInputSizes(obj, varargin_1_size, varargin_2_size);
  }
}

static boolean_T SystemCore_detectInputSizeChang(nav_slalgs_internal_VectorFie_T
  *obj, const int32_T *varargin_1_size, const int32_T *varargin_2_size)
{
  boolean_T anyInputSizeChanged;
  uint32_T inSize[8];
  int32_T b_k;
  boolean_T exitg1;
  anyInputSizeChanged = false;
  b_k = *varargin_1_size;
  if (*varargin_1_size < 0) {
    b_k = 0;
  }

  inSize[0] = static_cast<uint32_T>(b_k);
  inSize[1] = 1U;
  for (b_k = 0; b_k < 6; b_k++) {
    inSize[b_k + 2] = 1U;
  }

  b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (b_k < 8)) {
    if (obj->inputVarSize[0].f1[b_k] != inSize[b_k]) {
      anyInputSizeChanged = true;
      for (b_k = 0; b_k < 8; b_k++) {
        obj->inputVarSize[0].f1[b_k] = inSize[b_k];
      }

      exitg1 = true;
    } else {
      b_k++;
    }
  }

  b_k = *varargin_2_size;
  if (*varargin_2_size < 0) {
    b_k = 0;
  }

  inSize[0] = static_cast<uint32_T>(b_k);
  inSize[1] = 1U;
  for (b_k = 0; b_k < 6; b_k++) {
    inSize[b_k + 2] = 1U;
  }

  b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (b_k < 8)) {
    if (obj->inputVarSize[1].f1[b_k] != inSize[b_k]) {
      anyInputSizeChanged = true;
      for (b_k = 0; b_k < 8; b_k++) {
        obj->inputVarSize[1].f1[b_k] = inSize[b_k];
      }

      exitg1 = true;
    } else {
      b_k++;
    }
  }

  return anyInputSizeChanged;
}

static real32_T ObstacleControl_floatmod(real32_T x)
{
  real32_T r;
  boolean_T rEQ0;
  real32_T q;
  if (rtIsNaNF(x) || rtIsInfF(x)) {
    r = (rtNaNF);
  } else if (x == 0.0F) {
    r = 0.0F;
  } else {
    r = static_cast<real32_T>(fmod(static_cast<real_T>(x), 6.2831854820251465));
    rEQ0 = (r == 0.0F);
    if (!rEQ0) {
      q = static_cast<real32_T>(fabs(static_cast<real_T>(x / 6.28318548F)));
      rEQ0 = !(static_cast<real32_T>(fabs(static_cast<real_T>(q -
                  static_cast<real32_T>(floor(static_cast<real_T>(q + 0.5F))))))
               > 1.1920929E-7F * q);
    }

    if (rEQ0) {
      r = 0.0F;
    } else {
      if (x < 0.0F) {
        r += 6.28318548F;
      }
    }
  }

  return r;
}

static void ObstacleControl_wrapToPi_ngg(real32_T theta_data[], const int32_T
  *theta_size)
{
  boolean_T y;
  int32_T nx;
  int32_T b_k;
  int32_T y_size_idx_0;
  boolean_T exitg1;
  nx = *theta_size - 1;
  y_size_idx_0 = *theta_size;
  for (b_k = 0; b_k <= nx; b_k++) {
    ObstacleControl_B.y_data[b_k] = static_cast<real32_T>(fabs
      (static_cast<real_T>(theta_data[b_k])));
  }

  for (b_k = 0; b_k < y_size_idx_0; b_k++) {
    ObstacleControl_B.pos_data[b_k] = (ObstacleControl_B.y_data[b_k] >
      3.1415926535897931);
  }

  y = false;
  b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (b_k + 1 <= *theta_size)) {
    if (!ObstacleControl_B.pos_data[b_k]) {
      b_k++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    y_size_idx_0 = *theta_size;
    nx = *theta_size;
    for (b_k = 0; b_k < nx; b_k++) {
      ObstacleControl_B.y_data[b_k] = theta_data[b_k] + 3.14159274F;
    }

    for (b_k = 0; b_k < y_size_idx_0; b_k++) {
      ObstacleControl_B.pos_data[b_k] = (ObstacleControl_B.y_data[b_k] > 0.0F);
    }

    nx = *theta_size - 1;
    for (b_k = 0; b_k <= nx; b_k++) {
      theta_data[b_k] = ObstacleControl_floatmod(ObstacleControl_B.y_data[b_k]);
    }

    nx = *theta_size;
    for (b_k = 0; b_k < nx; b_k++) {
      ObstacleControl_B.b_data[b_k] = (theta_data[b_k] == 0.0F);
    }

    b_k = *theta_size - 1;
    for (y_size_idx_0 = 0; y_size_idx_0 <= b_k; y_size_idx_0++) {
      if (ObstacleControl_B.b_data[y_size_idx_0] &&
          ObstacleControl_B.pos_data[y_size_idx_0]) {
        theta_data[y_size_idx_0] = 6.28318548F;
      }
    }

    nx = *theta_size;
    for (b_k = 0; b_k < nx; b_k++) {
      theta_data[b_k] -= 3.14159274F;
    }
  }
}

static void ObstacleC_lidarScan_lidarScan_n(const real32_T varargin_2_data[],
  const int32_T *varargin_2_size, real32_T obj_InternalAngles_data[], int32_T
  *obj_InternalAngles_size, boolean_T *obj_ContainsOnlyFiniteData)
{
  *obj_ContainsOnlyFiniteData = false;
  *obj_InternalAngles_size = *varargin_2_size;
  if (0 <= *varargin_2_size - 1) {
    memcpy(&obj_InternalAngles_data[0], &varargin_2_data[0], *varargin_2_size *
           sizeof(real32_T));
  }

  ObstacleControl_wrapToPi_ngg(obj_InternalAngles_data, obj_InternalAngles_size);
}

static real32_T ObstacleControl_wrapToPi_n(real32_T theta)
{
  real32_T b_theta;
  real32_T thetaWrap;
  b_theta = theta;
  if (static_cast<real32_T>(fabs(static_cast<real_T>(theta))) >
      3.1415926535897931) {
    thetaWrap = ObstacleControl_floatmod(theta + 3.14159274F);
    if ((thetaWrap == 0.0F) && (theta + 3.14159274F > 0.0F)) {
      thetaWrap = 6.28318548F;
    }

    b_theta = thetaWrap - 3.14159274F;
  }

  return b_theta;
}

static void ObstacleControl_sort(const real32_T x[2], real32_T b_x[2])
{
  b_x[0] = x[0];
  b_x[1] = x[1];
  if ((x[0] <= x[1]) || rtIsNaNF(x[1])) {
  } else {
    b_x[0] = x[1];
    b_x[1] = x[0];
  }
}

static void ObstacleControl_isfinite(const real32_T x_data[], const int32_T
  *x_size, boolean_T b_data[], int32_T *b_size)
{
  int32_T i;
  int32_T loop_ub;
  *b_size = *x_size;
  loop_ub = *x_size;
  for (i = 0; i < loop_ub; i++) {
    b_data[i] = rtIsInfF(x_data[i]);
  }

  for (i = 0; i < loop_ub; i++) {
    ObstacleControl_B.tmp_data_l[i] = rtIsNaNF(x_data[i]);
  }

  for (i = 0; i < loop_ub; i++) {
    b_data[i] = ((!b_data[i]) && (!ObstacleControl_B.tmp_data_l[i]));
  }
}

static void ObstacleContro_nullAssignment_n(real32_T x_data[], int32_T *x_size,
  const boolean_T idx_data[], const int32_T *idx_size)
{
  int32_T nxin;
  int32_T nxout;
  int32_T k0;
  int32_T b_k;
  nxin = *x_size - 1;
  nxout = 0;
  k0 = *idx_size - 1;
  for (b_k = 0; b_k <= k0; b_k++) {
    nxout += idx_data[b_k];
  }

  nxout = *x_size - nxout;
  k0 = -1;
  for (b_k = 0; b_k <= nxin; b_k++) {
    if ((b_k + 1 > *idx_size) || (!idx_data[b_k])) {
      k0++;
      x_data[k0] = x_data[b_k];
    }
  }

  if (1 > nxout) {
    nxout = 0;
  }

  *x_size = nxout;
}

static boolean_T O_lidarScan_removeInvalidData_n(real32_T
  objIn_InternalRanges_data[], int32_T *objIn_InternalRanges_size, real32_T
  objIn_InternalAngles_data[], int32_T *objIn_InternalAngles_size, const
  real32_T varargin_2[2])
{
  boolean_T objOut_ContainsOnlyFiniteData;
  boolean_T p;
  boolean_T pos[2];
  boolean_T p_0;
  int32_T b_k;
  int32_T loop_ub;
  int32_T tmp_size;
  real32_T b_z1;
  static real32_T tmp[2] = { 0.0F, 0.0F };

  boolean_T exitg1;
  tmp[1U] = (rtInfF);
  for (b_k = 0; b_k < *objIn_InternalRanges_size; b_k++) {
    ObstacleControl_B.validRangeLimitIndices_data[b_k] = true;
    ObstacleControl_B.validAngleLimitIndices_data[b_k] = true;
  }

  ObstacleControl_B.d.f1[0] = -3.14159274F;
  ObstacleControl_B.d.f1[1] = 3.14159274F;
  p = false;
  p_0 = true;
  b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (b_k < 2)) {
    if (!(varargin_2[b_k] == tmp[b_k])) {
      p_0 = false;
      exitg1 = true;
    } else {
      b_k++;
    }
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    loop_ub = *objIn_InternalRanges_size;
    for (b_k = 0; b_k < loop_ub; b_k++) {
      ObstacleControl_B.validRangeLimitIndices_data[b_k] =
        ((objIn_InternalRanges_data[b_k] >= varargin_2[0]) &&
         (objIn_InternalRanges_data[b_k] <= varargin_2[1]));
    }
  }

  p = false;
  p_0 = true;
  b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (b_k < 2)) {
    if (!(6.28318548F * static_cast<real32_T>(b_k) + -3.14159274F ==
          ObstacleControl_B.d.f1[b_k])) {
      p_0 = false;
      exitg1 = true;
    } else {
      b_k++;
    }
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    pos[0] = false;
    pos[1] = true;
    ObstacleControl_B.b_z1[0] = ObstacleControl_floatmod(0.0F);
    ObstacleControl_B.b_z1[1] = ObstacleControl_floatmod(6.28318548F);
    for (b_k = 0; b_k < 2; b_k++) {
      b_z1 = ObstacleControl_B.b_z1[b_k];
      if ((ObstacleControl_B.b_z1[b_k] == 0.0F) && pos[b_k]) {
        b_z1 = 6.28318548F;
      }

      ObstacleControl_B.b_z1[b_k] = b_z1;
    }

    ObstacleControl_B.b_z1[0] -= 3.14159274F;
    ObstacleControl_B.b_z1[1] -= 3.14159274F;
    ObstacleControl_sort(ObstacleControl_B.b_z1,
                         ObstacleControl_B.parsedAngleLimits);
    loop_ub = *objIn_InternalAngles_size;
    for (b_k = 0; b_k < loop_ub; b_k++) {
      ObstacleControl_B.validAngleLimitIndices_data[b_k] =
        ((objIn_InternalAngles_data[b_k] >= ObstacleControl_B.parsedAngleLimits
          [0]) && (objIn_InternalAngles_data[b_k] <=
                   ObstacleControl_B.parsedAngleLimits[1]));
    }
  }

  ObstacleControl_isfinite(objIn_InternalRanges_data, objIn_InternalRanges_size,
    ObstacleControl_B.tmp_data_m, &tmp_size);
  loop_ub = *objIn_InternalAngles_size;
  for (b_k = 0; b_k < loop_ub; b_k++) {
    ObstacleControl_B.tmp_data_n[b_k] = rtIsInfF(objIn_InternalAngles_data[b_k]);
  }

  for (b_k = 0; b_k < loop_ub; b_k++) {
    ObstacleControl_B.tmp_data_pp[b_k] = rtIsNaNF(objIn_InternalAngles_data[b_k]);
  }

  for (b_k = 0; b_k < tmp_size; b_k++) {
    ObstacleControl_B.validRangeLimitIndices_data[b_k] =
      (ObstacleControl_B.tmp_data_m[b_k] && ((!ObstacleControl_B.tmp_data_n[b_k])
        && (!ObstacleControl_B.tmp_data_pp[b_k])) &&
       ObstacleControl_B.validRangeLimitIndices_data[b_k] &&
       ObstacleControl_B.validAngleLimitIndices_data[b_k]);
  }

  p = true;
  b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (b_k + 1 <= tmp_size)) {
    if (!ObstacleControl_B.validRangeLimitIndices_data[b_k]) {
      p = false;
      exitg1 = true;
    } else {
      b_k++;
    }
  }

  if (!p) {
    for (b_k = 0; b_k < tmp_size; b_k++) {
      ObstacleControl_B.validAngleLimitIndices_data[b_k] =
        !ObstacleControl_B.validRangeLimitIndices_data[b_k];
    }

    ObstacleContro_nullAssignment_n(objIn_InternalRanges_data,
      objIn_InternalRanges_size, ObstacleControl_B.validAngleLimitIndices_data,
      &tmp_size);
    if (0 <= *objIn_InternalAngles_size - 1) {
      memcpy(&ObstacleControl_B.tmp_data_cx[0], &objIn_InternalAngles_data[0],
             *objIn_InternalAngles_size * sizeof(real32_T));
    }

    for (b_k = 0; b_k < tmp_size; b_k++) {
      ObstacleControl_B.validAngleLimitIndices_data[b_k] =
        !ObstacleControl_B.validRangeLimitIndices_data[b_k];
    }

    ObstacleContro_nullAssignment_n(ObstacleControl_B.tmp_data_cx, &loop_ub,
      ObstacleControl_B.validAngleLimitIndices_data, &tmp_size);
    ObstacleC_lidarScan_lidarScan_n(ObstacleControl_B.tmp_data_cx, &loop_ub,
      objIn_InternalAngles_data, objIn_InternalAngles_size,
      &objOut_ContainsOnlyFiniteData);
    objOut_ContainsOnlyFiniteData = true;
  } else {
    objOut_ContainsOnlyFiniteData = true;
  }

  return objOut_ContainsOnlyFiniteData;
}

static boolean_T ObstacleControl_isequal(void)
{
  return false;
}

static void ObstacleControl_asin(const real32_T x_data[], const int32_T *x_size,
  real32_T b_x_data[], int32_T *b_x_size)
{
  int32_T nx;
  int32_T loop_ub;
  *b_x_size = *x_size;
  if (0 <= *x_size - 1) {
    memcpy(&b_x_data[0], &x_data[0], *x_size * sizeof(real32_T));
  }

  nx = *x_size - 1;
  for (loop_ub = 0; loop_ub <= nx; loop_ub++) {
    b_x_data[loop_ub] = static_cast<real32_T>(asin(static_cast<real_T>
      (b_x_data[loop_ub])));
  }
}

static void ObstacleControl_cos(const real32_T x_data[], const int32_T *x_size,
  real32_T b_x_data[], int32_T *b_x_size)
{
  int32_T nx;
  int32_T loop_ub;
  *b_x_size = *x_size;
  if (0 <= *x_size - 1) {
    memcpy(&b_x_data[0], &x_data[0], *x_size * sizeof(real32_T));
  }

  nx = *x_size - 1;
  for (loop_ub = 0; loop_ub <= nx; loop_ub++) {
    b_x_data[loop_ub] = static_cast<real32_T>(cos(static_cast<real_T>
      (b_x_data[loop_ub])));
  }
}

static void ObstacleControl_sin(const real32_T x_data[], const int32_T *x_size,
  real32_T b_x_data[], int32_T *b_x_size)
{
  int32_T nx;
  int32_T loop_ub;
  *b_x_size = *x_size;
  if (0 <= *x_size - 1) {
    memcpy(&b_x_data[0], &x_data[0], *x_size * sizeof(real32_T));
  }

  nx = *x_size - 1;
  for (loop_ub = 0; loop_ub <= nx; loop_ub++) {
    b_x_data[loop_ub] = static_cast<real32_T>(sin(static_cast<real_T>
      (b_x_data[loop_ub])));
  }
}

static void ObstacleControl_cross(const real32_T a_data[], const int32_T a_size
  [2], const real32_T b_data[], real32_T c_data[], int32_T c_size[2])
{
  int32_T stride;
  int32_T stridem1;
  int32_T iNext;
  int32_T nHigh;
  int32_T iEnd;
  int32_T i2;
  int32_T i3;
  int32_T dim;
  int32_T i1;
  real32_T c_data_tmp;
  real32_T c_data_tmp_0;
  boolean_T exitg1;
  c_size[0] = a_size[0];
  c_size[1] = 3;
  if (a_size[0] != 0) {
    dim = 0;
    stride = 1;
    exitg1 = false;
    while ((!exitg1) && (stride - 1 < 2)) {
      if (a_size[stride - 1] == 3) {
        dim = stride;
        exitg1 = true;
      } else {
        stride++;
      }
    }

    if (dim >= 2) {
      stride = a_size[0];
      stridem1 = a_size[0];
    } else {
      stride = 1;
      stridem1 = 1;
    }

    iNext = stride * 3;
    if (dim >= 2) {
      nHigh = 0;
    } else {
      nHigh = iNext << 1;
    }

    for (dim = 1; iNext < 0 ? dim >= nHigh + 1 : dim <= nHigh + 1; dim += iNext)
    {
      iEnd = (dim + stridem1) - 1;
      for (i1 = dim; i1 <= iEnd; i1++) {
        i2 = (i1 + stride) - 1;
        i3 = i2 + stride;
        c_data[i1 - 1] = a_data[i2] * b_data[i3] - a_data[i3] * b_data[i2];
        c_data_tmp = a_data[i1 - 1];
        c_data_tmp_0 = b_data[i1 - 1];
        c_data[i2] = c_data_tmp_0 * a_data[i3] - c_data_tmp * b_data[i3];
        c_data[i3] = c_data_tmp * b_data[i2] - c_data_tmp_0 * a_data[i2];
      }
    }
  }
}

static void ObstacleControl_repmat(const real32_T a[3], real_T varargin_1,
  real32_T b_data[], int32_T b_size[2])
{
  int32_T ibmat;
  int32_T b_jcol;
  int32_T b_itilerow;
  int32_T b_size_tmp;
  b_size_tmp = static_cast<int32_T>(varargin_1);
  b_size[0] = b_size_tmp;
  b_size[1] = 3;
  for (b_jcol = 0; b_jcol < 3; b_jcol++) {
    ibmat = b_jcol * b_size_tmp;
    for (b_itilerow = 0; b_itilerow < b_size_tmp; b_itilerow++) {
      b_data[ibmat + b_itilerow] = a[b_jcol];
    }
  }
}

static void ObstacleControl_sign_n(real32_T x_data[], const int32_T *x_size)
{
  int32_T nx;
  int32_T b_k;
  nx = *x_size - 1;
  for (b_k = 0; b_k <= nx; b_k++) {
    if (x_data[b_k] < 0.0F) {
      x_data[b_k] = -1.0F;
    } else if (x_data[b_k] > 0.0F) {
      x_data[b_k] = 1.0F;
    } else if (x_data[b_k] == 0.0F) {
      x_data[b_k] = 0.0F;
    } else {
      x_data[b_k] = (rtNaNF);
    }
  }
}

static void ObstacleControl_abs(const real32_T x_data[], const int32_T *x_size,
  real32_T y_data[], int32_T *y_size)
{
  int32_T nx;
  int32_T b_k;
  nx = *x_size - 1;
  *y_size = *x_size;
  for (b_k = 0; b_k <= nx; b_k++) {
    y_data[b_k] = static_cast<real32_T>(fabs(static_cast<real_T>(x_data[b_k])));
  }
}

static void ObstacleControl_histc(const real32_T X_data[], const int32_T *X_size,
  const real32_T edges[36], real_T N[36], real_T BIN_data[], int32_T *BIN_size)
{
  int32_T xind;
  int32_T c;
  int32_T low_i;
  int32_T low_ip1;
  int32_T high_i;
  int32_T mid_i;
  int32_T b_idx_0;
  memset(&N[0], 0, 36U * sizeof(real_T));
  *BIN_size = *X_size;
  if (0 <= *X_size - 1) {
    memset(&BIN_data[0], 0, *X_size * sizeof(real_T));
  }

  xind = 0;
  c = *X_size - 1;
  for (b_idx_0 = 0; b_idx_0 <= c; b_idx_0++) {
    low_i = 0;
    if (!rtIsNaNF(X_data[xind])) {
      if ((X_data[xind] >= edges[0]) && (X_data[xind] < edges[35])) {
        low_i = 1;
        low_ip1 = 1;
        high_i = 36;
        while (high_i > low_ip1 + 1) {
          mid_i = (low_i + high_i) >> 1;
          if (X_data[xind] >= edges[mid_i - 1]) {
            low_i = mid_i;
            low_ip1 = mid_i;
          } else {
            high_i = mid_i;
          }
        }
      }

      if (X_data[xind] == edges[35]) {
        low_i = 36;
      }
    }

    if (low_i > 0) {
      N[low_i - 1]++;
    }

    BIN_data[xind] = low_i;
    xind++;
  }
}

static void VectorFieldHistogramBase_buildP(nav_slalgs_internal_VectorFie_T *obj,
  const real32_T scan_InternalRanges_data[], const int32_T
  *scan_InternalRanges_size, const real32_T scan_InternalAngles_data[], const
  int32_T *scan_InternalAngles_size)
{
  ObstacleControl_B.sinOfEnlargement_size = *scan_InternalRanges_size;
  ObstacleControl_B.loop_ub_f = *scan_InternalRanges_size;
  if (0 <= ObstacleControl_B.loop_ub_f - 1) {
    memcpy(&ObstacleControl_B.sinOfEnlargement_data[0],
           &scan_InternalRanges_data[0], ObstacleControl_B.loop_ub_f * sizeof
           (real32_T));
  }

  ObstacleControl_B.lowerAng_size = *scan_InternalAngles_size;
  ObstacleControl_B.loop_ub_f = *scan_InternalAngles_size;
  if (0 <= ObstacleControl_B.loop_ub_f - 1) {
    memcpy(&ObstacleControl_B.lowerAng_data[0], &scan_InternalAngles_data[0],
           ObstacleControl_B.loop_ub_f * sizeof(real32_T));
  }

  ObstacleControl_B.obj[0] = static_cast<real32_T>(obj->DistanceLimits[0]);
  ObstacleControl_B.obj[1] = static_cast<real32_T>(obj->DistanceLimits[1]);
  O_lidarScan_removeInvalidData_n(ObstacleControl_B.sinOfEnlargement_data,
    &ObstacleControl_B.sinOfEnlargement_size, ObstacleControl_B.lowerAng_data,
    &ObstacleControl_B.lowerAng_size, ObstacleControl_B.obj);
  ObstacleControl_B.loop_ub_f = ObstacleControl_B.sinOfEnlargement_size;
  for (ObstacleControl_B.e_i = 0; ObstacleControl_B.e_i <
       ObstacleControl_B.loop_ub_f; ObstacleControl_B.e_i++) {
    ObstacleControl_B.weightedRanges_data[ObstacleControl_B.e_i] =
      static_cast<real32_T>(obj->DistanceLimits[1]) -
      ObstacleControl_B.sinOfEnlargement_data[ObstacleControl_B.e_i];
  }

  if (ObstacleControl_isequal()) {
    memset(&obj->PolarObstacleDensity[0], 0, 36U * sizeof(real32_T));
  } else {
    ObstacleControl_B.d_b = obj->RobotRadius + obj->SafetyDistance;
    if (ObstacleControl_B.d_b == 0.0) {
      ObstacleControl_histc(ObstacleControl_B.lowerAng_data,
                            &ObstacleControl_B.lowerAng_size,
                            obj->AngularSectorMidPoints,
                            ObstacleControl_B.unusedU4,
                            ObstacleControl_B.bin_data,
                            &ObstacleControl_B.sinOfEnlargement_size);
      memset(&ObstacleControl_B.obstacleDensity[0], 0, 36U * sizeof(real32_T));
      ObstacleControl_B.end = ObstacleControl_B.sinOfEnlargement_size - 1;
      for (ObstacleControl_B.e_i = 0; ObstacleControl_B.e_i <=
           ObstacleControl_B.end; ObstacleControl_B.e_i++) {
        ObstacleControl_B.validWeights_size_idx_1 = static_cast<int32_T>
          (ObstacleControl_B.bin_data[ObstacleControl_B.e_i]) - 1;
        ObstacleControl_B.obstacleDensity[ObstacleControl_B.validWeights_size_idx_1]
          += ObstacleControl_B.weightedRanges_data[ObstacleControl_B.e_i];
      }

      memcpy(&obj->PolarObstacleDensity[0], &ObstacleControl_B.obstacleDensity[0],
             36U * sizeof(real32_T));
    } else {
      ObstacleControl_B.loop_ub_f = ObstacleControl_B.sinOfEnlargement_size;
      for (ObstacleControl_B.e_i = 0; ObstacleControl_B.e_i <
           ObstacleControl_B.loop_ub_f; ObstacleControl_B.e_i++) {
        ObstacleControl_B.sinOfEnlargement_data[ObstacleControl_B.e_i] =
          static_cast<real32_T>(ObstacleControl_B.d_b) /
          ObstacleControl_B.sinOfEnlargement_data[ObstacleControl_B.e_i];
      }

      ObstacleControl_B.end = ObstacleControl_B.sinOfEnlargement_size - 1;
      for (ObstacleControl_B.e_i = 0; ObstacleControl_B.e_i <=
           ObstacleControl_B.end; ObstacleControl_B.e_i++) {
        ObstacleControl_B.sinOfEnlargement_data_b =
          ObstacleControl_B.sinOfEnlargement_data[ObstacleControl_B.e_i];
        if (ObstacleControl_B.sinOfEnlargement_data[ObstacleControl_B.e_i] >=
            1.0F) {
          ObstacleControl_B.sinOfEnlargement_data_b = 0.999999881F;
        }

        ObstacleControl_B.sinOfEnlargement_data[ObstacleControl_B.e_i] =
          ObstacleControl_B.sinOfEnlargement_data_b;
      }

      ObstacleControl_asin(ObstacleControl_B.sinOfEnlargement_data,
                           &ObstacleControl_B.sinOfEnlargement_size,
                           ObstacleControl_B.enlargementAngle_data,
                           &ObstacleControl_B.enlargementAngle_size);
      ObstacleControl_B.sinOfEnlargement_size = ObstacleControl_B.lowerAng_size;
      ObstacleControl_B.loop_ub_f = ObstacleControl_B.lowerAng_size;
      for (ObstacleControl_B.e_i = 0; ObstacleControl_B.e_i <
           ObstacleControl_B.loop_ub_f; ObstacleControl_B.e_i++) {
        ObstacleControl_B.sinOfEnlargement_data[ObstacleControl_B.e_i] =
          ObstacleControl_B.lowerAng_data[ObstacleControl_B.e_i] +
          ObstacleControl_B.enlargementAngle_data[ObstacleControl_B.e_i];
      }

      ObstacleControl_B.loop_ub_f = ObstacleControl_B.lowerAng_size;
      for (ObstacleControl_B.e_i = 0; ObstacleControl_B.e_i <
           ObstacleControl_B.loop_ub_f; ObstacleControl_B.e_i++) {
        ObstacleControl_B.lowerAng_data[ObstacleControl_B.e_i] -=
          ObstacleControl_B.enlargementAngle_data[ObstacleControl_B.e_i];
      }

      ObstacleControl_cos(ObstacleControl_B.lowerAng_data,
                          &ObstacleControl_B.lowerAng_size,
                          ObstacleControl_B.tmp_data_c,
                          &ObstacleControl_B.tmp_size_j);
      ObstacleControl_sin(ObstacleControl_B.lowerAng_data,
                          &ObstacleControl_B.lowerAng_size,
                          ObstacleControl_B.tmp_data_k,
                          &ObstacleControl_B.enlargementAngle_size);
      ObstacleControl_B.lowerVec_size[0] = ObstacleControl_B.tmp_size_j;
      ObstacleControl_B.lowerVec_size[1] = 3;
      ObstacleControl_B.loop_ub_f = ObstacleControl_B.tmp_size_j;
      if (0 <= ObstacleControl_B.loop_ub_f - 1) {
        memcpy(&ObstacleControl_B.lowerVec_data[0],
               &ObstacleControl_B.tmp_data_c[0], ObstacleControl_B.loop_ub_f *
               sizeof(real32_T));
      }

      ObstacleControl_B.loop_ub_f = ObstacleControl_B.enlargementAngle_size;
      for (ObstacleControl_B.e_i = 0; ObstacleControl_B.e_i <
           ObstacleControl_B.loop_ub_f; ObstacleControl_B.e_i++) {
        ObstacleControl_B.lowerVec_data[ObstacleControl_B.e_i +
          ObstacleControl_B.tmp_size_j] =
          ObstacleControl_B.tmp_data_k[ObstacleControl_B.e_i];
      }

      ObstacleControl_B.loop_ub_f = ObstacleControl_B.lowerAng_size;
      if (0 <= ObstacleControl_B.loop_ub_f - 1) {
        memset(&ObstacleControl_B.lowerVec_data[ObstacleControl_B.tmp_size_j +
               ObstacleControl_B.enlargementAngle_size], 0,
               ((((ObstacleControl_B.loop_ub_f + ObstacleControl_B.tmp_size_j) +
                  ObstacleControl_B.enlargementAngle_size) -
                 ObstacleControl_B.tmp_size_j) -
                ObstacleControl_B.enlargementAngle_size) * sizeof(real32_T));
      }

      ObstacleControl_cos(ObstacleControl_B.sinOfEnlargement_data,
                          &ObstacleControl_B.sinOfEnlargement_size,
                          ObstacleControl_B.tmp_data_c,
                          &ObstacleControl_B.tmp_size_j);
      ObstacleControl_sin(ObstacleControl_B.sinOfEnlargement_data,
                          &ObstacleControl_B.sinOfEnlargement_size,
                          ObstacleControl_B.tmp_data_k,
                          &ObstacleControl_B.enlargementAngle_size);
      ObstacleControl_B.loop_ub_f = ObstacleControl_B.tmp_size_j;
      if (0 <= ObstacleControl_B.loop_ub_f - 1) {
        memcpy(&ObstacleControl_B.higherVec_data[0],
               &ObstacleControl_B.tmp_data_c[0], ObstacleControl_B.loop_ub_f *
               sizeof(real32_T));
      }

      ObstacleControl_B.loop_ub_f = ObstacleControl_B.enlargementAngle_size;
      for (ObstacleControl_B.e_i = 0; ObstacleControl_B.e_i <
           ObstacleControl_B.loop_ub_f; ObstacleControl_B.e_i++) {
        ObstacleControl_B.higherVec_data[ObstacleControl_B.e_i +
          ObstacleControl_B.tmp_size_j] =
          ObstacleControl_B.tmp_data_k[ObstacleControl_B.e_i];
      }

      ObstacleControl_B.loop_ub_f = ObstacleControl_B.lowerAng_size;
      if (0 <= ObstacleControl_B.loop_ub_f - 1) {
        memset(&ObstacleControl_B.higherVec_data[ObstacleControl_B.tmp_size_j +
               ObstacleControl_B.enlargementAngle_size], 0,
               ((((ObstacleControl_B.loop_ub_f + ObstacleControl_B.tmp_size_j) +
                  ObstacleControl_B.enlargementAngle_size) -
                 ObstacleControl_B.tmp_size_j) -
                ObstacleControl_B.enlargementAngle_size) * sizeof(real32_T));
      }

      ObstacleControl_B.validWeights_size_idx_1 =
        ObstacleControl_B.lowerVec_size[0];
      ObstacleControl_B.loop_ub_f = 36 * ObstacleControl_B.lowerVec_size[0] - 1;
      for (ObstacleControl_B.e_i = 0; ObstacleControl_B.e_i <=
           ObstacleControl_B.loop_ub_f; ObstacleControl_B.e_i++) {
        ObstacleControl_B.validWeights_data[ObstacleControl_B.e_i] = true;
      }

      ObstacleControl_cross(ObstacleControl_B.lowerVec_data,
                            ObstacleControl_B.lowerVec_size,
                            ObstacleControl_B.higherVec_data,
                            ObstacleControl_B.lh_data, ObstacleControl_B.lh_size);
      for (ObstacleControl_B.e_i = 0; ObstacleControl_B.e_i < 36;
           ObstacleControl_B.e_i++) {
        ObstacleControl_B.kalpha[ObstacleControl_B.e_i] = static_cast<real32_T>
          (cos(static_cast<real_T>(obj->
             AngularSectorMidPoints[ObstacleControl_B.e_i])));
        ObstacleControl_B.kalpha[ObstacleControl_B.e_i + 36] =
          static_cast<real32_T>(sin(static_cast<real_T>
          (obj->AngularSectorMidPoints[ObstacleControl_B.e_i])));
        ObstacleControl_B.kalpha[ObstacleControl_B.e_i + 72] = 0.0F;
      }

      ObstacleControl_B.loop_ub_f = ObstacleControl_B.lh_size[0];
      for (ObstacleControl_B.end = 0; ObstacleControl_B.end < 36;
           ObstacleControl_B.end++) {
        ObstacleControl_B.kalpha_b[0] =
          ObstacleControl_B.kalpha[ObstacleControl_B.end];
        ObstacleControl_B.kalpha_b[1] =
          ObstacleControl_B.kalpha[ObstacleControl_B.end + 36];
        ObstacleControl_B.kalpha_b[2] =
          ObstacleControl_B.kalpha[ObstacleControl_B.end + 72];
        ObstacleControl_repmat(ObstacleControl_B.kalpha_b, static_cast<real_T>
          (ObstacleControl_B.lowerVec_size[0]), ObstacleControl_B.kalphaVec_data,
          ObstacleControl_B.kalphaVec_size);
        ObstacleControl_cross(ObstacleControl_B.lowerVec_data,
                              ObstacleControl_B.lowerVec_size,
                              ObstacleControl_B.kalphaVec_data,
                              ObstacleControl_B.lk_data,
                              ObstacleControl_B.lk_size);
        ObstacleControl_cross(ObstacleControl_B.kalphaVec_data,
                              ObstacleControl_B.kalphaVec_size,
                              ObstacleControl_B.higherVec_data,
                              ObstacleControl_B.kh_data,
                              ObstacleControl_B.kh_size);
        ObstacleControl_B.loop_ub_a = ObstacleControl_B.lk_size[0];
        ObstacleControl_B.tmp_size_j = ObstacleControl_B.lk_size[0];
        for (ObstacleControl_B.e_i = 0; ObstacleControl_B.e_i <
             ObstacleControl_B.loop_ub_a; ObstacleControl_B.e_i++) {
          ObstacleControl_B.tmp_data_c[ObstacleControl_B.e_i] =
            ObstacleControl_B.lk_data[(ObstacleControl_B.lk_size[0] << 1) +
            ObstacleControl_B.e_i];
        }

        ObstacleControl_sign_n(ObstacleControl_B.tmp_data_c,
          &ObstacleControl_B.tmp_size_j);
        ObstacleControl_B.loop_ub_a = ObstacleControl_B.kh_size[0];
        ObstacleControl_B.enlargementAngle_size = ObstacleControl_B.kh_size[0];
        for (ObstacleControl_B.e_i = 0; ObstacleControl_B.e_i <
             ObstacleControl_B.loop_ub_a; ObstacleControl_B.e_i++) {
          ObstacleControl_B.tmp_data_k[ObstacleControl_B.e_i] =
            ObstacleControl_B.kh_data[(ObstacleControl_B.kh_size[0] << 1) +
            ObstacleControl_B.e_i];
        }

        ObstacleControl_sign_n(ObstacleControl_B.tmp_data_k,
          &ObstacleControl_B.enlargementAngle_size);
        ObstacleControl_B.enlargementAngle_size = ObstacleControl_B.lh_size[0];
        for (ObstacleControl_B.e_i = 0; ObstacleControl_B.e_i <
             ObstacleControl_B.loop_ub_f; ObstacleControl_B.e_i++) {
          ObstacleControl_B.enlargementAngle_data[ObstacleControl_B.e_i] =
            ObstacleControl_B.lh_data[(ObstacleControl_B.lh_size[0] << 1) +
            ObstacleControl_B.e_i];
        }

        ObstacleControl_sign_n(ObstacleControl_B.enlargementAngle_data,
          &ObstacleControl_B.enlargementAngle_size);
        ObstacleControl_B.enlargementAngle_size = ObstacleControl_B.tmp_size_j;
        ObstacleControl_B.loop_ub_a = ObstacleControl_B.tmp_size_j;
        for (ObstacleControl_B.e_i = 0; ObstacleControl_B.e_i <
             ObstacleControl_B.loop_ub_a; ObstacleControl_B.e_i++) {
          ObstacleControl_B.sinOfEnlargement_data[ObstacleControl_B.e_i] =
            (ObstacleControl_B.tmp_data_c[ObstacleControl_B.e_i] +
             ObstacleControl_B.tmp_data_k[ObstacleControl_B.e_i]) +
            ObstacleControl_B.enlargementAngle_data[ObstacleControl_B.e_i];
        }

        ObstacleControl_abs(ObstacleControl_B.sinOfEnlargement_data,
                            &ObstacleControl_B.enlargementAngle_size,
                            ObstacleControl_B.tmp_data_c,
                            &ObstacleControl_B.tmp_size_j);
        for (ObstacleControl_B.e_i = 0; ObstacleControl_B.e_i <
             ObstacleControl_B.validWeights_size_idx_1; ObstacleControl_B.e_i++)
        {
          ObstacleControl_B.validWeights_data[ObstacleControl_B.end + 36 *
            ObstacleControl_B.e_i] =
            (ObstacleControl_B.tmp_data_c[ObstacleControl_B.e_i] > 1.0F);
        }
      }

      for (ObstacleControl_B.e_i = 0; ObstacleControl_B.e_i < 36;
           ObstacleControl_B.e_i++) {
        obj->PolarObstacleDensity[ObstacleControl_B.e_i] = 0.0F;
        for (ObstacleControl_B.end = 0; ObstacleControl_B.end <
             ObstacleControl_B.validWeights_size_idx_1; ObstacleControl_B.end++)
        {
          obj->PolarObstacleDensity[ObstacleControl_B.e_i] +=
            static_cast<real32_T>(ObstacleControl_B.validWeights_data[36 *
            ObstacleControl_B.end + ObstacleControl_B.e_i]) *
            ObstacleControl_B.weightedRanges_data[ObstacleControl_B.end];
        }
      }
    }
  }
}

static void ObstacleControl_power(const real32_T a_data[], const int32_T *a_size,
  real32_T y_data[], int32_T *y_size)
{
  int32_T nx;
  int32_T b_k;
  *y_size = *a_size;
  nx = *a_size - 1;
  for (b_k = 0; b_k <= nx; b_k++) {
    y_data[b_k] = a_data[b_k] * a_data[b_k];
  }
}

static void ObstacleControl_sqrt_n(real32_T x_data[], const int32_T *x_size)
{
  int32_T nx;
  int32_T b_k;
  nx = *x_size - 1;
  for (b_k = 0; b_k <= nx; b_k++) {
    x_data[b_k] = static_cast<real32_T>(sqrt(static_cast<real_T>(x_data[b_k])));
  }
}

static void VectorFieldHistogramBase_buildM(nav_slalgs_internal_VectorFie_T *obj,
  const real32_T scan_InternalRanges_data[], const int32_T
  *scan_InternalRanges_size, const real32_T scan_InternalAngles_data[], const
  int32_T *scan_InternalAngles_size)
{
  boolean_T exitg1;
  ObstacleControl_B.validScan_InternalRanges_size = *scan_InternalRanges_size;
  ObstacleControl_B.idx_n = *scan_InternalRanges_size;
  if (0 <= ObstacleControl_B.idx_n - 1) {
    memcpy(&ObstacleControl_B.validScan_InternalRanges_data[0],
           &scan_InternalRanges_data[0], ObstacleControl_B.idx_n * sizeof
           (real32_T));
  }

  ObstacleControl_B.ii_data_j = *scan_InternalAngles_size;
  ObstacleControl_B.idx_n = *scan_InternalAngles_size;
  if (0 <= ObstacleControl_B.idx_n - 1) {
    memcpy(&ObstacleControl_B.validScan_InternalAngles_data[0],
           &scan_InternalAngles_data[0], ObstacleControl_B.idx_n * sizeof
           (real32_T));
  }

  ObstacleControl_B.obj_n[0] = static_cast<real32_T>(obj->DistanceLimits[0]);
  ObstacleControl_B.obj_n[1] = static_cast<real32_T>(obj->DistanceLimits[1]);
  O_lidarScan_removeInvalidData_n
    (ObstacleControl_B.validScan_InternalRanges_data,
     &ObstacleControl_B.validScan_InternalRanges_size,
     ObstacleControl_B.validScan_InternalAngles_data,
     &ObstacleControl_B.ii_data_j, ObstacleControl_B.obj_n);
  ObstacleControl_sin(ObstacleControl_B.validScan_InternalAngles_data,
                      &ObstacleControl_B.ii_data_j, ObstacleControl_B.DYj_data,
                      &ObstacleControl_B.DYj_size);
  ObstacleControl_B.DYj_size = ObstacleControl_B.validScan_InternalRanges_size;
  ObstacleControl_B.idx_n = ObstacleControl_B.validScan_InternalRanges_size;
  for (ObstacleControl_B.k = 0; ObstacleControl_B.k < ObstacleControl_B.idx_n;
       ObstacleControl_B.k++) {
    ObstacleControl_B.DYj_data[ObstacleControl_B.k] *=
      ObstacleControl_B.validScan_InternalRanges_data[ObstacleControl_B.k];
  }

  ObstacleControl_cos(ObstacleControl_B.validScan_InternalAngles_data,
                      &ObstacleControl_B.ii_data_j, ObstacleControl_B.tmp_data_b,
                      &ObstacleControl_B.tmp_size_i);
  ObstacleControl_B.tmp_size_o = ObstacleControl_B.validScan_InternalRanges_size;
  ObstacleControl_B.idx_n = ObstacleControl_B.validScan_InternalRanges_size;
  for (ObstacleControl_B.k = 0; ObstacleControl_B.k < ObstacleControl_B.idx_n;
       ObstacleControl_B.k++) {
    ObstacleControl_B.tmp_data_p[ObstacleControl_B.k] = 0.0F -
      ObstacleControl_B.validScan_InternalRanges_data[ObstacleControl_B.k] *
      ObstacleControl_B.tmp_data_b[ObstacleControl_B.k];
  }

  ObstacleControl_power(ObstacleControl_B.tmp_data_p,
                        &ObstacleControl_B.tmp_size_o,
                        ObstacleControl_B.validScan_InternalRanges_data,
                        &ObstacleControl_B.validScan_InternalRanges_size);
  ObstacleControl_B.obj_size_n = ObstacleControl_B.DYj_size;
  ObstacleControl_B.idx_n = ObstacleControl_B.DYj_size;
  for (ObstacleControl_B.k = 0; ObstacleControl_B.k < ObstacleControl_B.idx_n;
       ObstacleControl_B.k++) {
    ObstacleControl_B.tmp_data_p[ObstacleControl_B.k] = static_cast<real32_T>
      (-obj->MinTurningRadius) - ObstacleControl_B.DYj_data[ObstacleControl_B.k];
  }

  ObstacleControl_power(ObstacleControl_B.tmp_data_p,
                        &ObstacleControl_B.obj_size_n,
                        ObstacleControl_B.tmp_data_b,
                        &ObstacleControl_B.tmp_size_i);
  ObstacleControl_B.tmp_size_i = ObstacleControl_B.validScan_InternalRanges_size;
  ObstacleControl_B.idx_n = ObstacleControl_B.validScan_InternalRanges_size;
  for (ObstacleControl_B.k = 0; ObstacleControl_B.k < ObstacleControl_B.idx_n;
       ObstacleControl_B.k++) {
    ObstacleControl_B.tmp_data_b[ObstacleControl_B.k] +=
      ObstacleControl_B.validScan_InternalRanges_data[ObstacleControl_B.k];
  }

  ObstacleControl_sqrt_n(ObstacleControl_B.tmp_data_b,
    &ObstacleControl_B.tmp_size_i);
  ObstacleControl_B.obj_tmp = (obj->MinTurningRadius + obj->RobotRadius) +
    obj->SafetyDistance;
  ObstacleControl_B.k_o = ObstacleControl_B.tmp_size_i;
  ObstacleControl_B.idx_n = ObstacleControl_B.tmp_size_i;
  for (ObstacleControl_B.k = 0; ObstacleControl_B.k < ObstacleControl_B.idx_n;
       ObstacleControl_B.k++) {
    ObstacleControl_B.blockedR_data[ObstacleControl_B.k] =
      ((ObstacleControl_B.tmp_data_b[ObstacleControl_B.k] <
        ObstacleControl_B.obj_tmp) &&
       (ObstacleControl_B.validScan_InternalAngles_data[ObstacleControl_B.k] <=
        0.0F));
  }

  ObstacleControl_B.obj_size_m = ObstacleControl_B.DYj_size;
  ObstacleControl_B.idx_n = ObstacleControl_B.DYj_size;
  for (ObstacleControl_B.k = 0; ObstacleControl_B.k < ObstacleControl_B.idx_n;
       ObstacleControl_B.k++) {
    ObstacleControl_B.tmp_data_p[ObstacleControl_B.k] = static_cast<real32_T>
      (obj->MinTurningRadius) - ObstacleControl_B.DYj_data[ObstacleControl_B.k];
  }

  ObstacleControl_power(ObstacleControl_B.tmp_data_p,
                        &ObstacleControl_B.obj_size_m,
                        ObstacleControl_B.tmp_data_b,
                        &ObstacleControl_B.tmp_size_i);
  ObstacleControl_B.idx_n = ObstacleControl_B.validScan_InternalRanges_size;
  for (ObstacleControl_B.k = 0; ObstacleControl_B.k < ObstacleControl_B.idx_n;
       ObstacleControl_B.k++) {
    ObstacleControl_B.validScan_InternalRanges_data[ObstacleControl_B.k] +=
      ObstacleControl_B.tmp_data_b[ObstacleControl_B.k];
  }

  ObstacleControl_sqrt_n(ObstacleControl_B.validScan_InternalRanges_data,
    &ObstacleControl_B.validScan_InternalRanges_size);
  ObstacleControl_B.idx_n = ObstacleControl_B.validScan_InternalRanges_size;
  for (ObstacleControl_B.k = 0; ObstacleControl_B.k < ObstacleControl_B.idx_n;
       ObstacleControl_B.k++) {
    ObstacleControl_B.blockedL_data[ObstacleControl_B.k] =
      ((ObstacleControl_B.validScan_InternalRanges_data[ObstacleControl_B.k] <
        ObstacleControl_B.obj_tmp) &&
       (ObstacleControl_B.validScan_InternalAngles_data[ObstacleControl_B.k] >=
        0.0F));
  }

  ObstacleControl_B.k = (1 <= ObstacleControl_B.k_o);
  ObstacleControl_B.idx_n = 0;
  exitg1 = false;
  while ((!exitg1) && (ObstacleControl_B.k_o > 0)) {
    if (ObstacleControl_B.blockedR_data[ObstacleControl_B.k_o - 1]) {
      ObstacleControl_B.idx_n = 1;
      ObstacleControl_B.ii_data_j = ObstacleControl_B.k_o;
      exitg1 = true;
    } else {
      ObstacleControl_B.k_o--;
    }
  }

  if (ObstacleControl_B.k == 1) {
    if (ObstacleControl_B.idx_n == 0) {
      ObstacleControl_B.k = 0;
    }
  } else {
    ObstacleControl_B.k = (1 <= ObstacleControl_B.idx_n);
  }

  if (0 <= ObstacleControl_B.k - 1) {
    ObstacleControl_B.phiR_data =
      ObstacleControl_B.validScan_InternalAngles_data[ObstacleControl_B.ii_data_j
      - 1];
  }

  ObstacleControl_B.k_o = (1 <= ObstacleControl_B.validScan_InternalRanges_size);
  ObstacleControl_B.idx_n = 0;
  ObstacleControl_B.b_ii = 1;
  exitg1 = false;
  while ((!exitg1) && (ObstacleControl_B.b_ii - 1 <=
                       ObstacleControl_B.validScan_InternalRanges_size - 1)) {
    if (ObstacleControl_B.blockedL_data[ObstacleControl_B.b_ii - 1]) {
      ObstacleControl_B.idx_n = 1;
      ObstacleControl_B.ii_data_j = ObstacleControl_B.b_ii;
      exitg1 = true;
    } else {
      ObstacleControl_B.b_ii++;
    }
  }

  if (ObstacleControl_B.k_o == 1) {
    if (ObstacleControl_B.idx_n == 0) {
      ObstacleControl_B.k_o = 0;
    }
  } else {
    ObstacleControl_B.k_o = (1 <= ObstacleControl_B.idx_n);
  }

  if (0 <= ObstacleControl_B.k_o - 1) {
    ObstacleControl_B.phiL_data =
      ObstacleControl_B.validScan_InternalAngles_data[ObstacleControl_B.ii_data_j
      - 1];
  }

  if (ObstacleControl_B.k == 0) {
    ObstacleControl_B.phiR_data = obj->AngularSectorMidPoints[0];
  } else {
    if (ObstacleControl_B.phiR_data <= obj->AngularSectorMidPoints[0]) {
      ObstacleControl_B.phiR_data = obj->AngularSectorMidPoints[1];
    }
  }

  if (ObstacleControl_B.k_o == 0) {
    ObstacleControl_B.phiL_data = obj->AngularSectorMidPoints[35];
  } else {
    if (ObstacleControl_B.phiL_data >= obj->AngularSectorMidPoints[35]) {
      ObstacleControl_B.phiL_data = obj->AngularSectorMidPoints[34];
    }
  }

  for (ObstacleControl_B.k = 0; ObstacleControl_B.k < 36; ObstacleControl_B.k++)
  {
    obj->MaskedHistogram[ObstacleControl_B.k] = (obj->
      BinaryHistogram[ObstacleControl_B.k] || ((obj->
      AngularSectorMidPoints[ObstacleControl_B.k] < ObstacleControl_B.phiR_data)
      || (obj->AngularSectorMidPoints[ObstacleControl_B.k] >
          ObstacleControl_B.phiL_data)));
  }
}

static void ObstacleControl_diff(const real_T x[38], real_T y[37])
{
  real_T work;
  int32_T ixLead;
  int32_T iyLead;
  real_T tmp2;
  int32_T m;
  ixLead = 1;
  iyLead = 0;
  work = x[0];
  for (m = 0; m < 37; m++) {
    tmp2 = work;
    work = x[ixLead];
    y[iyLead] = x[ixLead] - tmp2;
    ixLead++;
    iyLead++;
  }
}

static boolean_T ObstacleControl_any(const real32_T x[37])
{
  boolean_T y;
  int32_T b_k;
  boolean_T exitg1;
  y = false;
  b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (b_k < 37)) {
    if ((x[b_k] == 0.0F) || rtIsNaNF(x[b_k])) {
      b_k++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  return y;
}

static void ObstacleControl_diff_n(const real32_T x_data[], const int32_T
  x_size[2], real32_T y_data[], int32_T y_size[2])
{
  int32_T nHigh;
  int32_T ixStart;
  int32_T iyStart;
  int32_T r;
  if (x_size[1] != 0) {
    nHigh = x_size[1] - 1;
    ixStart = 0;
    iyStart = 0;
    for (r = 0; r <= nHigh; r++) {
      ObstacleControl_B.b_y1_data[iyStart] = x_data[ixStart + 1] -
        x_data[ixStart];
      ixStart += 2;
      iyStart++;
    }
  }

  y_size[0] = 1;
  y_size[1] = x_size[1];
  r = x_size[1] - 1;
  if (0 <= r) {
    memcpy(&y_data[0], &ObstacleControl_B.b_y1_data[0], (r + 1) * sizeof
           (real32_T));
  }
}

static void ObstacleControl_wrapToPi_ng(const real32_T theta_data[], const
  int32_T theta_size[2], real32_T b_theta_data[], int32_T b_theta_size[2])
{
  boolean_T y;
  int32_T nx;
  int32_T b_k;
  int32_T loop_ub_tmp;
  boolean_T exitg1;
  b_theta_size[0] = 1;
  b_theta_size[1] = theta_size[1];
  loop_ub_tmp = theta_size[0] * theta_size[1] - 1;
  if (0 <= loop_ub_tmp) {
    memcpy(&b_theta_data[0], &theta_data[0], (loop_ub_tmp + 1) * sizeof(real32_T));
  }

  nx = theta_size[1] - 1;
  for (b_k = 0; b_k <= nx; b_k++) {
    ObstacleControl_B.y_data_g[b_k] = static_cast<real32_T>(fabs
      (static_cast<real_T>(theta_data[b_k])));
  }

  nx = theta_size[1] - 1;
  for (b_k = 0; b_k <= nx; b_k++) {
    ObstacleControl_B.pos_data_g[b_k] = (ObstacleControl_B.y_data_g[b_k] >
      3.1415926535897931);
  }

  y = false;
  b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (b_k + 1 <= theta_size[1])) {
    if (!ObstacleControl_B.pos_data_g[b_k]) {
      b_k++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    for (b_k = 0; b_k <= loop_ub_tmp; b_k++) {
      ObstacleControl_B.y_data_g[b_k] = theta_data[b_k] + 3.14159274F;
    }

    nx = theta_size[1] - 1;
    for (b_k = 0; b_k <= nx; b_k++) {
      ObstacleControl_B.pos_data_g[b_k] = (ObstacleControl_B.y_data_g[b_k] >
        0.0F);
    }

    nx = theta_size[1] - 1;
    if (0 <= nx) {
      memcpy(&ObstacleControl_B.b_z1_data[0], &ObstacleControl_B.y_data_g[0],
             (nx + 1) * sizeof(real32_T));
    }

    nx = theta_size[1] - 1;
    for (b_k = 0; b_k <= nx; b_k++) {
      ObstacleControl_B.b_z1_data[b_k] = ObstacleControl_floatmod
        (ObstacleControl_B.y_data_g[b_k]);
    }

    nx = theta_size[1] - 1;
    if (0 <= nx) {
      memcpy(&ObstacleControl_B.y_data_g[0], &ObstacleControl_B.b_z1_data[0],
             (nx + 1) * sizeof(real32_T));
    }

    nx = theta_size[1] - 1;
    for (b_k = 0; b_k <= nx; b_k++) {
      ObstacleControl_B.b_data_l[b_k] = (ObstacleControl_B.b_z1_data[b_k] ==
        0.0F);
    }

    b_k = theta_size[1] - 1;
    for (loop_ub_tmp = 0; loop_ub_tmp <= b_k; loop_ub_tmp++) {
      if (ObstacleControl_B.b_data_l[loop_ub_tmp] &&
          ObstacleControl_B.pos_data_g[loop_ub_tmp]) {
        ObstacleControl_B.y_data_g[loop_ub_tmp] = 6.28318548F;
      }
    }

    b_theta_size[0] = 1;
    b_theta_size[1] = theta_size[1];
    nx = theta_size[1] - 1;
    for (b_k = 0; b_k <= nx; b_k++) {
      b_theta_data[b_k] = ObstacleControl_B.y_data_g[b_k] - 3.14159274F;
    }
  }
}

static void ObstacleControl_bisectAngles(real32_T theta1_data[], int32_T
  theta1_size[2], real32_T theta2_data[], const int32_T theta2_size[2], real32_T
  bisect_data[], int32_T bisect_size[2])
{
  int32_T theta1_size_0[2];
  int32_T loop_ub_tmp;
  int32_T loop_ub;
  ObstacleControl_wrapToPi_ng(theta1_data, theta1_size,
    ObstacleControl_B.tmp_data_g, ObstacleControl_B.tmp_size_d);
  theta1_size[1] = ObstacleControl_B.tmp_size_d[1];
  loop_ub_tmp = ObstacleControl_B.tmp_size_d[0] * ObstacleControl_B.tmp_size_d[1];
  if (0 <= loop_ub_tmp - 1) {
    memcpy(&theta1_data[0], &ObstacleControl_B.tmp_data_g[0], loop_ub_tmp *
           sizeof(real32_T));
  }

  ObstacleControl_wrapToPi_ng(theta2_data, theta2_size,
    ObstacleControl_B.tmp_data_g, ObstacleControl_B.tmp_size_d);
  loop_ub = ObstacleControl_B.tmp_size_d[0] * ObstacleControl_B.tmp_size_d[1];
  if (0 <= loop_ub - 1) {
    memcpy(&theta2_data[0], &ObstacleControl_B.tmp_data_g[0], loop_ub * sizeof
           (real32_T));
  }

  theta1_size_0[0] = 1;
  theta1_size_0[1] = theta1_size[1];
  loop_ub = theta1_size[1];
  for (loop_ub_tmp = 0; loop_ub_tmp < loop_ub; loop_ub_tmp++) {
    ObstacleControl_B.theta1_data[loop_ub_tmp] = theta1_data[loop_ub_tmp] -
      (theta1_data[loop_ub_tmp] - theta2_data[loop_ub_tmp]) / 2.0F;
  }

  ObstacleControl_wrapToPi_ng(ObstacleControl_B.theta1_data, theta1_size_0,
    ObstacleControl_B.tmp_data_g, ObstacleControl_B.tmp_size_d);
  bisect_size[0] = 1;
  bisect_size[1] = ObstacleControl_B.tmp_size_d[1];
  loop_ub = ObstacleControl_B.tmp_size_d[0] * ObstacleControl_B.tmp_size_d[1];
  if (0 <= loop_ub - 1) {
    memcpy(&bisect_data[0], &ObstacleControl_B.tmp_data_g[0], loop_ub * sizeof
           (real32_T));
  }
}

static void ObstacleControl_bsxfun(const real32_T a[36], const real32_T b_data[],
  const int32_T *b_size, real32_T c_data[], int32_T c_size[2])
{
  int32_T k;
  int32_T k_0;
  int32_T csz_idx_0;
  csz_idx_0 = *b_size;
  c_size[0] = *b_size;
  c_size[1] = 36;
  for (k = 0; k < 36; k++) {
    for (k_0 = 0; k_0 < csz_idx_0; k_0++) {
      c_data[k_0 + *b_size * k] = ObstacleControl_wrapToPi_n(b_data[k_0] - a[k]);
    }
  }
}

static void ObstacleControl_abs_n(const real32_T x_data[], const int32_T x_size
  [2], real32_T y_data[], int32_T y_size[2])
{
  int32_T nx;
  int32_T b_k;
  nx = x_size[0] * 36 - 1;
  y_size[0] = x_size[0];
  y_size[1] = 36;
  for (b_k = 0; b_k <= nx; b_k++) {
    y_data[b_k] = static_cast<real32_T>(fabs(static_cast<real_T>(x_data[b_k])));
  }
}

static void ObstacleControl_bsxfun_n(const real32_T a_data[], const int32_T
  a_size[2], const real32_T b_data[], const int32_T *b_size, real32_T c_data[],
  int32_T c_size[2])
{
  int32_T k;
  int32_T k_0;
  int32_T csz_idx_0;
  if (a_size[0] == *b_size) {
    csz_idx_0 = a_size[0];
  } else if (*b_size < a_size[0]) {
    csz_idx_0 = *b_size;
  } else {
    csz_idx_0 = a_size[0];
  }

  c_size[0] = csz_idx_0;
  c_size[1] = 36;
  for (k = 0; k < 36; k++) {
    for (k_0 = 0; k_0 < csz_idx_0; k_0++) {
      c_data[k_0 + csz_idx_0 * k] = a_data[a_size[0] * k + k_0] - b_data[k_0];
    }
  }
}

static boolean_T ObstacleControl_any_n(const boolean_T x_data[], const int32_T
  x_size[2])
{
  boolean_T y;
  int32_T ix;
  boolean_T exitg1;
  y = false;
  ix = 0;
  exitg1 = false;
  while ((!exitg1) && (ix + 1 <= x_size[1])) {
    if (!x_data[ix]) {
      ix++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  return y;
}

static void VectorFieldHistogramBase_comput(const
  nav_slalgs_internal_VectorFie_T *obj, const real32_T c_data[], const int32_T
  c_size[2], real32_T targetDir, real32_T prevDir, real32_T cost_data[], int32_T
  cost_size[2])
{
  real32_T totalWeight;
  int32_T nx;
  int32_T b_k;
  int32_T cost_size_idx_1;
  totalWeight = (static_cast<real32_T>(obj->TargetDirectionWeight) +
                 static_cast<real32_T>(obj->CurrentDirectionWeight)) +
    static_cast<real32_T>(obj->PreviousDirectionWeight);
  nx = c_size[1];
  ObstacleControl_B.targetDir_size[0] = 1;
  ObstacleControl_B.targetDir_size[1] = c_size[1];
  for (b_k = 0; b_k < nx; b_k++) {
    ObstacleControl_B.cost_data[b_k] = targetDir - c_data[b_k];
  }

  ObstacleControl_wrapToPi_ng(ObstacleControl_B.cost_data,
    ObstacleControl_B.targetDir_size, ObstacleControl_B.delta_data,
    ObstacleControl_B.delta_size);
  nx = ObstacleControl_B.delta_size[1] - 1;
  cost_size_idx_1 = ObstacleControl_B.delta_size[1];
  for (b_k = 0; b_k <= nx; b_k++) {
    ObstacleControl_B.cost_data[b_k] = static_cast<real32_T>(fabs
      (static_cast<real_T>(ObstacleControl_B.delta_data[b_k])));
  }

  nx = c_size[1];
  ObstacleControl_B.tmp_size[0] = 1;
  ObstacleControl_B.tmp_size[1] = c_size[1];
  for (b_k = 0; b_k < nx; b_k++) {
    ObstacleControl_B.cost_data_c[b_k] = 0.0F - c_data[b_k];
  }

  ObstacleControl_wrapToPi_ng(ObstacleControl_B.cost_data_c,
    ObstacleControl_B.tmp_size, ObstacleControl_B.delta_data,
    ObstacleControl_B.delta_size);
  nx = ObstacleControl_B.delta_size[1] - 1;
  for (b_k = 0; b_k <= nx; b_k++) {
    ObstacleControl_B.cost_data_c[b_k] = static_cast<real32_T>(fabs
      (static_cast<real_T>(ObstacleControl_B.delta_data[b_k])));
  }

  nx = c_size[1];
  ObstacleControl_B.prevDir_size[0] = 1;
  ObstacleControl_B.prevDir_size[1] = c_size[1];
  for (b_k = 0; b_k < nx; b_k++) {
    ObstacleControl_B.cost_data_f[b_k] = prevDir - c_data[b_k];
  }

  ObstacleControl_wrapToPi_ng(ObstacleControl_B.cost_data_f,
    ObstacleControl_B.prevDir_size, ObstacleControl_B.delta_data,
    ObstacleControl_B.delta_size);
  nx = ObstacleControl_B.delta_size[1] - 1;
  for (b_k = 0; b_k <= nx; b_k++) {
    ObstacleControl_B.cost_data_f[b_k] = static_cast<real32_T>(fabs
      (static_cast<real_T>(ObstacleControl_B.delta_data[b_k])));
  }

  cost_size[0] = 1;
  cost_size[1] = cost_size_idx_1;
  cost_size_idx_1--;
  for (b_k = 0; b_k <= cost_size_idx_1; b_k++) {
    cost_data[b_k] = ((static_cast<real32_T>(obj->TargetDirectionWeight) *
                       ObstacleControl_B.cost_data[b_k] + static_cast<real32_T>
                       (obj->CurrentDirectionWeight) *
                       ObstacleControl_B.cost_data_c[b_k]) +
                      static_cast<real32_T>(obj->PreviousDirectionWeight) *
                      ObstacleControl_B.cost_data_f[b_k]) / 3.0F * totalWeight;
  }
}

static real32_T VectorFieldHistogramBase_select(nav_slalgs_internal_VectorFie_T *
  obj, real32_T targetDir)
{
  real32_T thetaSteer;
  int32_T n;
  int32_T b_idx;
  int32_T loop_ub;
  int32_T minval_size;
  boolean_T tmp;
  real32_T nonNarrowDirs_data_tmp;
  boolean_T exitg1;
  ObstacleControl_B.dv[0] = 0.0;
  for (n = 0; n < 36; n++) {
    ObstacleControl_B.dv[n + 1] = !obj->MaskedHistogram[n];
  }

  ObstacleControl_B.dv[37] = 0.0;
  ObstacleControl_diff(ObstacleControl_B.dv, ObstacleControl_B.dv1);
  for (n = 0; n < 37; n++) {
    ObstacleControl_B.changes[n] = static_cast<real32_T>(ObstacleControl_B.dv1[n]);
  }

  if (!ObstacleControl_any(ObstacleControl_B.changes)) {
    thetaSteer = (rtNaNF);
    obj->PreviousDirection = (rtNaNF);
  } else {
    ObstacleControl_B.idx = 0;
    n = 1;
    exitg1 = false;
    while ((!exitg1) && (n - 1 < 37)) {
      if (ObstacleControl_B.changes[n - 1] != 0.0F) {
        ObstacleControl_B.idx++;
        ObstacleControl_B.ii_data[ObstacleControl_B.idx - 1] = n;
        if (ObstacleControl_B.idx >= 37) {
          exitg1 = true;
        } else {
          n++;
        }
      } else {
        n++;
      }
    }

    if (1 > ObstacleControl_B.idx) {
      ObstacleControl_B.idx = 0;
    }

    loop_ub = ObstacleControl_B.idx - 1;
    for (n = 0; n <= loop_ub; n++) {
      ObstacleControl_B.changes[n] = static_cast<real32_T>
        (ObstacleControl_B.ii_data[n]);
    }

    ObstacleControl_B.sectors_size[0] = 2;
    ObstacleControl_B.idx >>= 1;
    ObstacleControl_B.sectors_size[1] = ObstacleControl_B.idx;
    loop_ub = (ObstacleControl_B.idx << 1) - 1;
    if (0 <= loop_ub) {
      memcpy(&ObstacleControl_B.sectors_data[0], &ObstacleControl_B.changes[0],
             (loop_ub + 1) * sizeof(real32_T));
    }

    if (1 > ObstacleControl_B.idx) {
      loop_ub = -1;
    } else {
      loop_ub = ObstacleControl_B.idx - 1;
    }

    for (n = 0; n <= loop_ub; n++) {
      b_idx = (n << 1) + 1;
      ObstacleControl_B.sectors_data[b_idx] = ObstacleControl_B.changes[b_idx] -
        1.0F;
    }

    loop_ub = (ObstacleControl_B.idx << 1) - 1;
    if (0 <= loop_ub) {
      memset(&ObstacleControl_B.angles_data[0], 0, (loop_ub + 1) * sizeof
             (real32_T));
    }

    if (1 > ObstacleControl_B.idx) {
      loop_ub = -1;
      ObstacleControl_B.idx = -1;
    } else {
      loop_ub = ObstacleControl_B.idx - 1;
      ObstacleControl_B.idx--;
    }

    for (n = 0; n <= loop_ub; n++) {
      b_idx = n << 1;
      ObstacleControl_B.angles_data[b_idx] = obj->AngularSectorMidPoints[
        static_cast<int32_T>(ObstacleControl_B.sectors_data[b_idx]) - 1];
    }

    for (n = 0; n <= ObstacleControl_B.idx; n++) {
      b_idx = (n << 1) + 1;
      ObstacleControl_B.angles_data[b_idx] = obj->AngularSectorMidPoints[
        static_cast<int32_T>(ObstacleControl_B.sectors_data[b_idx]) - 1];
    }

    ObstacleControl_diff_n(ObstacleControl_B.sectors_data,
      ObstacleControl_B.sectors_size, ObstacleControl_B.sectorSizes_data,
      ObstacleControl_B.sectorSizes_size);
    loop_ub = ObstacleControl_B.sectorSizes_size[0] *
      ObstacleControl_B.sectorSizes_size[1] - 1;
    for (n = 0; n <= loop_ub; n++) {
      ObstacleControl_B.sectorSizes_data[n] *= obj->AngularDifference;
    }

    loop_ub = ObstacleControl_B.sectorSizes_size[1] - 1;
    for (n = 0; n <= loop_ub; n++) {
      ObstacleControl_B.ab_data[n] = static_cast<real32_T>
        (obj->NarrowOpeningThreshold);
    }

    loop_ub = ObstacleControl_B.sectorSizes_size[1] - 1;
    ObstacleControl_B.idx = 0;
    b_idx = 0;
    for (n = 0; n <= loop_ub; n++) {
      if (ObstacleControl_B.sectorSizes_data[n] < ObstacleControl_B.ab_data[n])
      {
        ObstacleControl_B.idx++;
        ObstacleControl_B.ob_data[b_idx] = n + 1;
        b_idx++;
      }
    }

    ObstacleControl_B.angles_size[0] = 1;
    ObstacleControl_B.angles_size[1] = ObstacleControl_B.idx;
    ObstacleControl_B.angles_size_b[0] = 1;
    ObstacleControl_B.angles_size_b[1] = ObstacleControl_B.idx;
    for (n = 0; n < ObstacleControl_B.idx; n++) {
      b_idx = (ObstacleControl_B.ob_data[n] - 1) << 1;
      ObstacleControl_B.angles_data_j[n] = ObstacleControl_B.angles_data[b_idx];
      ObstacleControl_B.angles_data_d[n] = ObstacleControl_B.angles_data[b_idx +
        1];
    }

    ObstacleControl_bisectAngles(ObstacleControl_B.angles_data_j,
      ObstacleControl_B.angles_size, ObstacleControl_B.angles_data_d,
      ObstacleControl_B.angles_size_b, ObstacleControl_B.narrowDirs_data,
      ObstacleControl_B.sectors_size);
    loop_ub = ObstacleControl_B.sectorSizes_size[1] - 1;
    ObstacleControl_B.idx = 0;
    b_idx = 0;
    for (n = 0; n <= loop_ub; n++) {
      if (!(ObstacleControl_B.sectorSizes_data[n] < ObstacleControl_B.ab_data[n]))
      {
        ObstacleControl_B.idx++;
        ObstacleControl_B.tb_data[b_idx] = n + 1;
        b_idx++;
      }
    }

    b_idx = ObstacleControl_B.idx + ObstacleControl_B.idx;
    for (n = 0; n < ObstacleControl_B.idx; n++) {
      loop_ub = (ObstacleControl_B.tb_data[n] - 1) << 1;
      nonNarrowDirs_data_tmp = static_cast<real32_T>(obj->NarrowOpeningThreshold)
        / 2.0F;
      ObstacleControl_B.sectors_data[n] = ObstacleControl_B.angles_data[loop_ub]
        + nonNarrowDirs_data_tmp;
      ObstacleControl_B.sectors_data[n + ObstacleControl_B.idx] =
        ObstacleControl_B.angles_data[loop_ub + 1] - nonNarrowDirs_data_tmp;
    }

    if (rtIsNaNF(obj->PreviousDirection)) {
      obj->PreviousDirection = 0.0F;
    }

    loop_ub = ObstacleControl_B.sectors_size[1];
    ObstacleControl_B.idx = b_idx + ObstacleControl_B.sectors_size[1];
    ObstacleControl_B.candidateDirs_size[1] = ObstacleControl_B.idx + 3;
    if (0 <= b_idx - 1) {
      memcpy(&ObstacleControl_B.candidateDirs_data[0],
             &ObstacleControl_B.sectors_data[0], b_idx * sizeof(real32_T));
    }

    for (n = 0; n < loop_ub; n++) {
      ObstacleControl_B.candidateDirs_data[n + b_idx] =
        ObstacleControl_B.narrowDirs_data[n];
    }

    ObstacleControl_B.candidateDirs_data[ObstacleControl_B.idx] = targetDir;
    ObstacleControl_B.candidateDirs_data[ObstacleControl_B.idx + 1] = 0.0F;
    ObstacleControl_B.candidateDirs_data[ObstacleControl_B.idx + 2] =
      obj->PreviousDirection;
    n = ObstacleControl_B.candidateDirs_size[1];
    loop_ub = ObstacleControl_B.candidateDirs_size[1];
    if (0 <= loop_ub - 1) {
      memcpy(&ObstacleControl_B.cDiff_data[0],
             &ObstacleControl_B.candidateDirs_data[0], loop_ub * sizeof(real32_T));
    }

    ObstacleControl_bsxfun(obj->AngularSectorMidPoints,
      ObstacleControl_B.cDiff_data, &n, ObstacleControl_B.tmp_data,
      ObstacleControl_B.sectorSizes_size);
    ObstacleControl_abs_n(ObstacleControl_B.tmp_data,
                          ObstacleControl_B.sectorSizes_size,
                          ObstacleControl_B.candToSectDiff_data,
                          ObstacleControl_B.angles_size);
    loop_ub = ObstacleControl_B.angles_size[0] - 1;
    minval_size = ObstacleControl_B.angles_size[0];
    if (0 <= loop_ub) {
      memcpy(&ObstacleControl_B.cDiff_data[0],
             &ObstacleControl_B.candToSectDiff_data[0], (loop_ub + 1) * sizeof
             (real32_T));
    }

    for (n = 0; n < 35; n++) {
      for (ObstacleControl_B.idx = 0; ObstacleControl_B.idx <= loop_ub;
           ObstacleControl_B.idx++) {
        nonNarrowDirs_data_tmp =
          ObstacleControl_B.cDiff_data[ObstacleControl_B.idx];
        b_idx = (n + 1) * ObstacleControl_B.angles_size[0] +
          ObstacleControl_B.idx;
        if (rtIsNaNF(ObstacleControl_B.candToSectDiff_data[b_idx])) {
          tmp = false;
        } else {
          tmp = (rtIsNaNF(ObstacleControl_B.cDiff_data[ObstacleControl_B.idx]) ||
                 (ObstacleControl_B.cDiff_data[ObstacleControl_B.idx] >
                  ObstacleControl_B.candToSectDiff_data[b_idx]));
        }

        if (tmp) {
          nonNarrowDirs_data_tmp = ObstacleControl_B.candToSectDiff_data[b_idx];
        }

        ObstacleControl_B.cDiff_data[ObstacleControl_B.idx] =
          nonNarrowDirs_data_tmp;
      }
    }

    ObstacleControl_bsxfun_n(ObstacleControl_B.candToSectDiff_data,
      ObstacleControl_B.angles_size, ObstacleControl_B.cDiff_data, &minval_size,
      ObstacleControl_B.tmp_data, ObstacleControl_B.sectorSizes_size);
    loop_ub = ObstacleControl_B.sectorSizes_size[0] *
      ObstacleControl_B.sectorSizes_size[1];
    for (n = 0; n < loop_ub; n++) {
      ObstacleControl_B.nearIdx_data[n] = (ObstacleControl_B.tmp_data[n] <
        0.000345266977F);
    }

    loop_ub = ObstacleControl_B.sectorSizes_size[0] - 1;
    for (n = 0; n <= loop_ub; n++) {
      ObstacleControl_B.freeDirs_data[n] = true;
    }

    loop_ub = ObstacleControl_B.sectorSizes_size[0] - 1;
    if (0 <= loop_ub) {
      ObstacleControl_B.obj_size[0] = 1;
    }

    for (ObstacleControl_B.idx = 0; ObstacleControl_B.idx <= loop_ub;
         ObstacleControl_B.idx++) {
      b_idx = 0;
      ObstacleControl_B.h_partialTrueCount = 0;
      for (n = 0; n < 36; n++) {
        if (ObstacleControl_B.nearIdx_data[ObstacleControl_B.sectorSizes_size[0]
            * n + ObstacleControl_B.idx]) {
          b_idx++;
          ObstacleControl_B.ub_data[ObstacleControl_B.h_partialTrueCount] =
            static_cast<int8_T>(n + 1);
          ObstacleControl_B.h_partialTrueCount++;
        }
      }

      ObstacleControl_B.obj_size[1] = b_idx;
      for (n = 0; n < b_idx; n++) {
        ObstacleControl_B.obj_data[n] = obj->
          MaskedHistogram[ObstacleControl_B.ub_data[n] - 1];
      }

      ObstacleControl_B.freeDirs_data[ObstacleControl_B.idx] =
        !ObstacleControl_any_n(ObstacleControl_B.obj_data,
        ObstacleControl_B.obj_size);
    }

    ObstacleControl_B.idx = ObstacleControl_B.sectorSizes_size[0] - 1;
    loop_ub = 0;
    ObstacleControl_B.candidateDirections_size[0] = 1;
    b_idx = 0;
    for (n = 0; n <= ObstacleControl_B.idx; n++) {
      if (ObstacleControl_B.freeDirs_data[n]) {
        loop_ub++;
        ObstacleControl_B.candidateDirections_data[b_idx] =
          ObstacleControl_B.candidateDirs_data[n];
        b_idx++;
      }
    }

    ObstacleControl_B.candidateDirections_size[1] = loop_ub;
    VectorFieldHistogramBase_comput(obj,
      ObstacleControl_B.candidateDirections_data,
      ObstacleControl_B.candidateDirections_size, targetDir,
      obj->PreviousDirection, ObstacleControl_B.candidateDirs_data,
      ObstacleControl_B.candidateDirs_size);
    n = ObstacleControl_B.candidateDirs_size[1];
    if (ObstacleControl_B.candidateDirs_size[1] <= 2) {
      if (ObstacleControl_B.candidateDirs_size[1] == 1) {
        ObstacleControl_B.cVal = ObstacleControl_B.candidateDirs_data[0];
      } else if ((ObstacleControl_B.candidateDirs_data[0] >
                  ObstacleControl_B.candidateDirs_data[1]) || (rtIsNaNF
                  (ObstacleControl_B.candidateDirs_data[0]) && (!rtIsNaNF
                   (ObstacleControl_B.candidateDirs_data[1])))) {
        ObstacleControl_B.cVal = ObstacleControl_B.candidateDirs_data[1];
      } else {
        ObstacleControl_B.cVal = ObstacleControl_B.candidateDirs_data[0];
      }
    } else {
      if (!rtIsNaNF(ObstacleControl_B.candidateDirs_data[0])) {
        b_idx = 1;
      } else {
        b_idx = 0;
        loop_ub = 2;
        exitg1 = false;
        while ((!exitg1) && (loop_ub <= ObstacleControl_B.candidateDirs_size[1]))
        {
          if (!rtIsNaNF(ObstacleControl_B.candidateDirs_data[loop_ub - 1])) {
            b_idx = loop_ub;
            exitg1 = true;
          } else {
            loop_ub++;
          }
        }
      }

      if (b_idx == 0) {
        ObstacleControl_B.cVal = ObstacleControl_B.candidateDirs_data[0];
      } else {
        ObstacleControl_B.cVal = ObstacleControl_B.candidateDirs_data[b_idx - 1];
        for (loop_ub = b_idx + 1; loop_ub <= n; loop_ub++) {
          nonNarrowDirs_data_tmp = ObstacleControl_B.candidateDirs_data[loop_ub
            - 1];
          if (ObstacleControl_B.cVal > nonNarrowDirs_data_tmp) {
            ObstacleControl_B.cVal = nonNarrowDirs_data_tmp;
          }
        }
      }
    }

    loop_ub = ObstacleControl_B.candidateDirs_size[0] *
      ObstacleControl_B.candidateDirs_size[1] - 1;
    for (n = 0; n <= loop_ub; n++) {
      ObstacleControl_B.cDiff_data[n] = ObstacleControl_B.candidateDirs_data[n]
        - ObstacleControl_B.cVal;
    }

    loop_ub = ObstacleControl_B.candidateDirs_size[1] - 1;
    ObstacleControl_B.idx = 0;
    b_idx = 0;
    for (n = 0; n <= loop_ub; n++) {
      if (ObstacleControl_B.cDiff_data[n] < 0.000345266977F) {
        ObstacleControl_B.idx++;
        ObstacleControl_B.vb_data[b_idx] = n + 1;
        b_idx++;
      }
    }

    if (ObstacleControl_B.idx <= 2) {
      if (ObstacleControl_B.idx == 1) {
        thetaSteer =
          ObstacleControl_B.candidateDirections_data[ObstacleControl_B.vb_data[0]
          - 1];
      } else {
        nonNarrowDirs_data_tmp =
          ObstacleControl_B.candidateDirections_data[ObstacleControl_B.vb_data[1]
          - 1];
        thetaSteer =
          ObstacleControl_B.candidateDirections_data[ObstacleControl_B.vb_data[0]
          - 1];
        if ((thetaSteer > nonNarrowDirs_data_tmp) || (rtIsNaNF
             (ObstacleControl_B.candidateDirections_data[ObstacleControl_B.vb_data
              [0] - 1]) && (!rtIsNaNF(nonNarrowDirs_data_tmp)))) {
          thetaSteer = nonNarrowDirs_data_tmp;
        }
      }
    } else {
      thetaSteer =
        ObstacleControl_B.candidateDirections_data[ObstacleControl_B.vb_data[0]
        - 1];
      if (!rtIsNaNF(thetaSteer)) {
        b_idx = 1;
      } else {
        b_idx = 0;
        loop_ub = 2;
        exitg1 = false;
        while ((!exitg1) && (loop_ub <= ObstacleControl_B.idx)) {
          if (!rtIsNaNF
              (ObstacleControl_B.candidateDirections_data[ObstacleControl_B.vb_data
               [loop_ub - 1] - 1])) {
            b_idx = loop_ub;
            exitg1 = true;
          } else {
            loop_ub++;
          }
        }
      }

      if (b_idx != 0) {
        thetaSteer =
          ObstacleControl_B.candidateDirections_data[ObstacleControl_B.vb_data[b_idx
          - 1] - 1];
        for (loop_ub = b_idx + 1; loop_ub <= ObstacleControl_B.idx; loop_ub++) {
          n = ObstacleControl_B.vb_data[loop_ub - 1] - 1;
          if (thetaSteer > ObstacleControl_B.candidateDirections_data[n]) {
            thetaSteer = ObstacleControl_B.candidateDirections_data[n];
          }
        }
      }
    }

    obj->PreviousDirection = thetaSteer;
  }

  return thetaSteer;
}

static real32_T VectorFieldHistogramBase_stepIm(nav_slalgs_internal_VectorFie_T *
  obj, const real32_T varargin_1_data[], const int32_T *varargin_1_size, const
  real_T varargin_2_data[], const int32_T *varargin_2_size, real32_T varargin_3)
{
  real32_T steeringDir;
  boolean_T scan_ContainsOnlyFiniteData;
  ObstacleControl_B.scan_InternalRanges_size = *varargin_1_size;
  ObstacleControl_B.loop_ub = *varargin_1_size;
  if (0 <= ObstacleControl_B.loop_ub - 1) {
    memcpy(&ObstacleControl_B.scan_InternalRanges_data[0], &varargin_1_data[0],
           ObstacleControl_B.loop_ub * sizeof(real32_T));
  }

  ObstacleControl_B.varargin_2_size = *varargin_2_size;
  ObstacleControl_B.loop_ub = *varargin_2_size;
  for (ObstacleControl_B.i_j = 0; ObstacleControl_B.i_j <
       ObstacleControl_B.loop_ub; ObstacleControl_B.i_j++) {
    ObstacleControl_B.varargin_2_data[ObstacleControl_B.i_j] =
      static_cast<real32_T>(varargin_2_data[ObstacleControl_B.i_j]);
  }

  ObstacleC_lidarScan_lidarScan_n(ObstacleControl_B.varargin_2_data,
    &ObstacleControl_B.varargin_2_size,
    ObstacleControl_B.scan_InternalAngles_data,
    &ObstacleControl_B.scan_InternalAngles_size, &scan_ContainsOnlyFiniteData);
  ObstacleControl_B.target = varargin_3;
  if (static_cast<real32_T>(fabs(static_cast<real_T>(varargin_3))) >
      3.1415926535897931) {
    ObstacleControl_B.target = ObstacleControl_wrapToPi_n(varargin_3);
  }

  VectorFieldHistogramBase_buildP(obj,
    ObstacleControl_B.scan_InternalRanges_data,
    &ObstacleControl_B.scan_InternalRanges_size,
    ObstacleControl_B.scan_InternalAngles_data,
    &ObstacleControl_B.scan_InternalAngles_size);
  ObstacleControl_B.loop_ub = 0;
  ObstacleControl_B.partialTrueCount = 0;
  for (ObstacleControl_B.i_j = 0; ObstacleControl_B.i_j < 36;
       ObstacleControl_B.i_j++) {
    if (obj->PolarObstacleDensity[ObstacleControl_B.i_j] >
        obj->HistogramThresholds[1]) {
      ObstacleControl_B.loop_ub++;
      ObstacleControl_B.b_data_d[ObstacleControl_B.partialTrueCount] =
        static_cast<int8_T>(ObstacleControl_B.i_j + 1);
      ObstacleControl_B.partialTrueCount++;
    }
  }

  for (ObstacleControl_B.i_j = 0; ObstacleControl_B.i_j <
       ObstacleControl_B.loop_ub; ObstacleControl_B.i_j++) {
    obj->BinaryHistogram[ObstacleControl_B.b_data_d[ObstacleControl_B.i_j] - 1] =
      true;
  }

  ObstacleControl_B.loop_ub = 0;
  ObstacleControl_B.partialTrueCount = 0;
  for (ObstacleControl_B.i_j = 0; ObstacleControl_B.i_j < 36;
       ObstacleControl_B.i_j++) {
    if (obj->PolarObstacleDensity[ObstacleControl_B.i_j] <
        obj->HistogramThresholds[0]) {
      ObstacleControl_B.loop_ub++;
      ObstacleControl_B.c_data[ObstacleControl_B.partialTrueCount] =
        static_cast<int8_T>(ObstacleControl_B.i_j + 1);
      ObstacleControl_B.partialTrueCount++;
    }
  }

  for (ObstacleControl_B.i_j = 0; ObstacleControl_B.i_j <
       ObstacleControl_B.loop_ub; ObstacleControl_B.i_j++) {
    obj->BinaryHistogram[ObstacleControl_B.c_data[ObstacleControl_B.i_j] - 1] =
      false;
  }

  VectorFieldHistogramBase_buildM(obj,
    ObstacleControl_B.scan_InternalRanges_data,
    &ObstacleControl_B.scan_InternalRanges_size,
    ObstacleControl_B.scan_InternalAngles_data,
    &ObstacleControl_B.scan_InternalAngles_size);
  steeringDir = VectorFieldHistogramBase_select(obj, ObstacleControl_B.target);
  return steeringDir;
}

static real32_T ObstacleControl_SystemCore_step(nav_slalgs_internal_VectorFie_T *
  obj, const real32_T varargin_1_data[], const int32_T *varargin_1_size, const
  real_T varargin_2_data[], const int32_T *varargin_2_size, real32_T varargin_3)
{
  real32_T varargout_1;
  SystemCore_systemblock_prestep(obj, varargin_1_size, varargin_2_size);
  SystemCore_detectInputSizeChang(obj, varargin_1_size, varargin_2_size);
  varargout_1 = VectorFieldHistogramBase_stepIm(obj, varargin_1_data,
    varargin_1_size, varargin_2_data, varargin_2_size, varargin_3);
  return varargout_1;
}

static void matlabCodegenHandle_matlabCod_n(ros_slros_internal_block_Subs_T *obj)
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

static void VectorFieldHistogramBase_setupI(nav_slalgs_internal_VectorFie_T *obj)
{
  real32_T delta1;
  int32_T d_k;
  real32_T angularLimits_idx_0;
  real32_T angularLimits_idx_1;
  obj->PreviousDirection = 0.0F;
  angularLimits_idx_0 = static_cast<real32_T>(obj->AngularLimits[0]);
  angularLimits_idx_1 = static_cast<real32_T>(obj->AngularLimits[1]);
  obj->AngularSectorMidPoints[35] = static_cast<real32_T>(obj->AngularLimits[1])
    - 0.0872664675F;
  obj->AngularSectorMidPoints[0] = angularLimits_idx_0 + 0.0872664675F;
  if (angularLimits_idx_0 + 0.0872664675F == -(angularLimits_idx_1 -
       0.0872664675F)) {
    for (d_k = 0; d_k < 34; d_k++) {
      obj->AngularSectorMidPoints[d_k + 1] = (static_cast<real32_T>((d_k + 2) <<
        1) - 37.0F) / 35.0F * (angularLimits_idx_1 - 0.0872664675F);
    }
  } else if (((angularLimits_idx_0 + 0.0872664675F < 0.0F) !=
              (angularLimits_idx_1 - 0.0872664675F < 0.0F)) &&
             ((static_cast<real32_T>(fabs(static_cast<real_T>
      (angularLimits_idx_0 + 0.0872664675F))) > 1.70141173E+38F) || (
               static_cast<real32_T>(fabs(static_cast<real_T>
      (angularLimits_idx_1 - 0.0872664675F))) > 1.70141173E+38F))) {
    delta1 = (angularLimits_idx_0 + 0.0872664675F) / 35.0F;
    angularLimits_idx_1 = (angularLimits_idx_1 - 0.0872664675F) / 35.0F;
    for (d_k = 0; d_k < 34; d_k++) {
      obj->AngularSectorMidPoints[d_k + 1] = ((static_cast<real32_T>(d_k) + 1.0F)
        * angularLimits_idx_1 + (angularLimits_idx_0 + 0.0872664675F)) - (
        static_cast<real32_T>(d_k) + 1.0F) * delta1;
    }
  } else {
    delta1 = ((angularLimits_idx_1 - 0.0872664675F) - (angularLimits_idx_0 +
               0.0872664675F)) / 35.0F;
    for (d_k = 0; d_k < 34; d_k++) {
      obj->AngularSectorMidPoints[d_k + 1] = (static_cast<real32_T>(d_k) + 1.0F)
        * delta1 + (angularLimits_idx_0 + 0.0872664675F);
    }
  }

  obj->AngularDifference = static_cast<real32_T>(fabs(static_cast<real_T>
    (ObstacleControl_wrapToPi_n(obj->AngularSectorMidPoints[1] -
    obj->AngularSectorMidPoints[0]))));
  angularLimits_idx_0 = obj->AngularDifference / 2.0F;
  for (d_k = 0; d_k < 36; d_k++) {
    obj->AngularSectorStartPoints[d_k] = obj->AngularSectorMidPoints[d_k] -
      angularLimits_idx_0;
    obj->BinaryHistogram[d_k] = false;
  }
}

// Model step function
void ObstacleControl_step(void)
{
  boolean_T p;
  boolean_T b_varargout_1;
  SL_Bus_ObstacleControl_std_msgs_Bool b_varargout_2;
  boolean_T exitg1;

  // Outputs for Atomic SubSystem: '<Root>/Subscribe2'
  // MATLABSystem: '<S7>/SourceBlock' incorporates:
  //   Inport: '<S15>/In1'

  b_varargout_1 = Sub_ObstacleControl_208.getLatestMessage
    (&ObstacleControl_B.b_varargout_2);

  // Outputs for Enabled SubSystem: '<S7>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S15>/Enable'

  if (b_varargout_1) {
    ObstacleControl_B.In1 = ObstacleControl_B.b_varargout_2;
  }

  // End of MATLABSystem: '<S7>/SourceBlock'
  // End of Outputs for SubSystem: '<S7>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe2'

  // MATLAB Function: '<Root>/angles_and_dists'
  if (ObstacleControl_B.In1.Ranges_SL_Info.ReceivedLength > 0U) {
    for (ObstacleControl_B.i = 0; ObstacleControl_B.i < 128; ObstacleControl_B.i
         ++) {
      ObstacleControl_B.ranges_e =
        ObstacleControl_B.In1.Ranges[ObstacleControl_B.i];
      if (ObstacleControl_B.In1.Ranges[ObstacleControl_B.i] >
          ObstacleControl_B.In1.RangeMax) {
        ObstacleControl_B.ranges_e = (rtNaNF);
      }

      if (ObstacleControl_B.ranges_e < ObstacleControl_B.In1.RangeMin) {
        ObstacleControl_B.ranges_e = (rtNaNF);
      }

      ObstacleControl_B.ranges[ObstacleControl_B.i] = ObstacleControl_B.ranges_e;
    }

    ObstacleControl_DW.SFunction_DIMS2[0] = static_cast<int32_T>
      (ObstacleControl_B.In1.Ranges_SL_Info.ReceivedLength);
    ObstacleControl_DW.SFunction_DIMS2[1] = 1;
    ObstacleControl_B.i = static_cast<int32_T>
      (ObstacleControl_B.In1.Ranges_SL_Info.ReceivedLength);
    if (0 <= ObstacleControl_B.i - 1) {
      memset(&ObstacleControl_B.angles[0], 0, ObstacleControl_B.i * sizeof
             (real_T));
    }

    ObstacleControl_B.i = 0;
    while (ObstacleControl_B.i <= static_cast<int32_T>
           (ObstacleControl_B.In1.Ranges_SL_Info.ReceivedLength) - 1) {
      ObstacleControl_B.ii = ObstacleControl_B.i + 1U;
      ObstacleControl_B.qY = ObstacleControl_B.ii - /*MW:OvSatOk*/ 1U;
      if (ObstacleControl_B.qY > ObstacleControl_B.ii) {
        ObstacleControl_B.qY = 0U;
      }

      ObstacleControl_B.angles[static_cast<int32_T>(ObstacleControl_B.ii) - 1] =
        static_cast<real_T>(ObstacleControl_B.qY) *
        ObstacleControl_B.In1.AngleIncrement + ObstacleControl_B.In1.AngleMin;
      ObstacleControl_B.i++;
    }

    ObstacleControl_DW.SFunction_DIMS3[0] = 128;
    ObstacleControl_DW.SFunction_DIMS3[1] = 1;
    memcpy(&ObstacleControl_B.dists[0], &ObstacleControl_B.ranges[0], sizeof
           (real32_T) << 7U);
  } else {
    ObstacleControl_B.angles[0] = 0.0;
    ObstacleControl_DW.SFunction_DIMS2[0] = 1;
    ObstacleControl_DW.SFunction_DIMS3[0] = 1;
    ObstacleControl_DW.SFunction_DIMS2[1] = 1;
    ObstacleControl_DW.SFunction_DIMS3[1] = 1;
    ObstacleControl_B.dists[0] = 0.0F;
  }

  // End of MATLAB Function: '<Root>/angles_and_dists'

  // Outputs for Atomic SubSystem: '<Root>/Subscribe'
  // MATLABSystem: '<S5>/SourceBlock'
  b_varargout_1 = Sub_ObstacleControl_7.getLatestMessage
    (&ObstacleControl_B.b_varargout_2_m);

  // Outputs for Enabled SubSystem: '<Root>/Decode ROS msg' incorporates:
  //   EnablePort: '<S2>/Enable'

  // Outputs for Enabled SubSystem: '<S5>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S13>/Enable'

  if (b_varargout_1) {
    // MATLABSystem: '<S2>/Coordinate Transformation Conversion' incorporates:
    //   SignalConversion generated from: '<S2>/Coordinate Transformation Conversion'

    ObstacleControl_B.b = 1.0 / sqrt
      (((ObstacleControl_B.b_varargout_2_m.Pose.Pose.Orientation.W *
         ObstacleControl_B.b_varargout_2_m.Pose.Pose.Orientation.W +
         ObstacleControl_B.b_varargout_2_m.Pose.Pose.Orientation.X *
         ObstacleControl_B.b_varargout_2_m.Pose.Pose.Orientation.X) +
        ObstacleControl_B.b_varargout_2_m.Pose.Pose.Orientation.Y *
        ObstacleControl_B.b_varargout_2_m.Pose.Pose.Orientation.Y) +
       ObstacleControl_B.b_varargout_2_m.Pose.Pose.Orientation.Z *
       ObstacleControl_B.b_varargout_2_m.Pose.Pose.Orientation.Z);
    ObstacleControl_B.b_z1_idx_0 =
      ObstacleControl_B.b_varargout_2_m.Pose.Pose.Orientation.W *
      ObstacleControl_B.b;
    ObstacleControl_B.b_z1_idx_1 =
      ObstacleControl_B.b_varargout_2_m.Pose.Pose.Orientation.X *
      ObstacleControl_B.b;
    ObstacleControl_B.b_z1_idx_2 =
      ObstacleControl_B.b_varargout_2_m.Pose.Pose.Orientation.Y *
      ObstacleControl_B.b;
    ObstacleControl_B.b *=
      ObstacleControl_B.b_varargout_2_m.Pose.Pose.Orientation.Z;

    // DataTypeConversion: '<S2>/Data Type Conversion2' incorporates:
    //   MATLABSystem: '<S2>/Coordinate Transformation Conversion'

    ObstacleControl_B.DataTypeConversion2 = rt_atan2d_snf
      ((ObstacleControl_B.b_z1_idx_1 * ObstacleControl_B.b_z1_idx_2 -
        ObstacleControl_B.b * ObstacleControl_B.b_z1_idx_0) * -2.0,
       ((ObstacleControl_B.b_z1_idx_0 * ObstacleControl_B.b_z1_idx_0 +
         ObstacleControl_B.b_z1_idx_1 * ObstacleControl_B.b_z1_idx_1) -
        ObstacleControl_B.b_z1_idx_2 * ObstacleControl_B.b_z1_idx_2) -
       ObstacleControl_B.b * ObstacleControl_B.b);

    // DataTypeConversion: '<S2>/Data Type Conversion'
    ObstacleControl_B.DataTypeConversion =
      ObstacleControl_B.b_varargout_2_m.Pose.Pose.Position.X;

    // DataTypeConversion: '<S2>/Data Type Conversion1'
    ObstacleControl_B.DataTypeConversion1 =
      ObstacleControl_B.b_varargout_2_m.Pose.Pose.Position.Y;
  }

  // End of MATLABSystem: '<S5>/SourceBlock'
  // End of Outputs for SubSystem: '<S5>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Decode ROS msg'
  // End of Outputs for SubSystem: '<Root>/Subscribe'

  // Outputs for Atomic SubSystem: '<Root>/Subscribe3'
  // MATLABSystem: '<S8>/SourceBlock' incorporates:
  //   Inport: '<S16>/In1'

  b_varargout_1 = Sub_ObstacleControl_61.getLatestMessage
    (&ObstacleControl_B.b_varargout_2_d);

  // Outputs for Enabled SubSystem: '<Root>/Subsystem' incorporates:
  //   EnablePort: '<S9>/Enable'

  // Outputs for Enabled SubSystem: '<S8>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S16>/Enable'

  if (b_varargout_1) {
    ObstacleControl_B.In1_o = ObstacleControl_B.b_varargout_2_d;

    // MATLAB Function: '<S17>/MATLAB Function' incorporates:
    //   Inport: '<S16>/In1'

    ObstacleControl_B.u[0] = ObstacleControl_B.DataTypeConversion;
    ObstacleControl_B.u[2] = ObstacleControl_B.DataTypeConversion1;
    ObstacleControl_B.u[1] = ObstacleControl_B.In1_o.X;
    ObstacleControl_B.u[3] = ObstacleControl_B.In1_o.Y;
  }

  // End of MATLABSystem: '<S8>/SourceBlock'
  // End of Outputs for SubSystem: '<S8>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe3'

  // MATLABSystem: '<S19>/Pure Pursuit' incorporates:
  //   SignalConversion generated from: '<S19>/Pure Pursuit'

  if (ObstacleControl_DW.obj_n.DesiredLinearVelocity !=
      ObstacleControl_P.PurePursuit_DesiredLinearVeloci) {
    ObstacleControl_DW.obj_n.DesiredLinearVelocity =
      ObstacleControl_P.PurePursuit_DesiredLinearVeloci;
  }

  if (ObstacleControl_DW.obj_n.MaxAngularVelocity !=
      ObstacleControl_P.PurePursuit_MaxAngularVelocity) {
    ObstacleControl_DW.obj_n.MaxAngularVelocity =
      ObstacleControl_P.PurePursuit_MaxAngularVelocity;
  }

  if (ObstacleControl_DW.obj_n.LookaheadDistance !=
      ObstacleControl_P.PurePursuit_LookaheadDistance) {
    ObstacleControl_DW.obj_n.LookaheadDistance =
      ObstacleControl_P.PurePursuit_LookaheadDistance;
  }

  b_varargout_1 = false;
  p = true;
  ObstacleControl_B.i = 0;
  exitg1 = false;
  while ((!exitg1) && (ObstacleControl_B.i < 4)) {
    if ((ObstacleControl_DW.obj_n.WaypointsInternal[ObstacleControl_B.i] ==
         ObstacleControl_B.u[ObstacleControl_B.i]) || (rtIsNaN
         (ObstacleControl_DW.obj_n.WaypointsInternal[ObstacleControl_B.i]) &&
         rtIsNaN(ObstacleControl_B.u[ObstacleControl_B.i]))) {
      ObstacleControl_B.i++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (p) {
    b_varargout_1 = true;
  }

  if (!b_varargout_1) {
    ObstacleControl_DW.obj_n.WaypointsInternal[0] = ObstacleControl_B.u[0];
    ObstacleControl_DW.obj_n.WaypointsInternal[1] = ObstacleControl_B.u[1];
    ObstacleControl_DW.obj_n.WaypointsInternal[2] = ObstacleControl_B.u[2];
    ObstacleControl_DW.obj_n.WaypointsInternal[3] = ObstacleControl_B.u[3];
    ObstacleControl_DW.obj_n.ProjectionLineIndex = 0.0;
  }

  ObstacleControl_B.dv2[0] = ObstacleControl_B.DataTypeConversion;
  ObstacleControl_B.dv2[1] = ObstacleControl_B.DataTypeConversion1;
  ObstacleControl_B.dv2[2] = ObstacleControl_B.DataTypeConversion2;
  Ob_PurePursuitBase_stepInternal(&ObstacleControl_DW.obj_n,
    ObstacleControl_B.dv2, ObstacleControl_B.u, &ObstacleControl_B.b_z1_idx_0,
    &ObstacleControl_B.b_z1_idx_1, ObstacleControl_B.posDiff,
    &ObstacleControl_B.b_z1_idx_2);

  // MATLAB Function: '<Root>/MATLAB Function' incorporates:
  //   Constant: '<Root>/Constant'

  ObstacleControl_B.posDiff[0] = ObstacleControl_B.In1_o.X -
    ObstacleControl_B.DataTypeConversion;
  ObstacleControl_B.posDiff[1] = ObstacleControl_B.In1_o.Y -
    ObstacleControl_B.DataTypeConversion1;
  ObstacleControl_B.y_p = (sqrt(ObstacleControl_B.posDiff[0] *
    ObstacleControl_B.posDiff[0] + ObstacleControl_B.posDiff[1] *
    ObstacleControl_B.posDiff[1]) <= ObstacleControl_P.Constant_Value_g);

  // Outputs for Atomic SubSystem: '<Root>/Subscribe1'
  // MATLABSystem: '<S6>/SourceBlock' incorporates:
  //   Inport: '<S14>/In1'

  b_varargout_1 = Sub_ObstacleControl_196.getLatestMessage(&b_varargout_2);

  // Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S14>/Enable'

  if (b_varargout_1) {
    ObstacleControl_B.In1_l = b_varargout_2;
  }

  // End of MATLABSystem: '<S6>/SourceBlock'
  // End of Outputs for SubSystem: '<S6>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe1'

  // MATLABSystem: '<S19>/Vector Field Histogram' incorporates:
  //   DataTypeConversion: '<S19>/Cast To Single'
  //   MATLABSystem: '<S19>/Pure Pursuit'

  b_varargout_1 = false;
  p = true;
  ObstacleControl_B.i = 0;
  exitg1 = false;
  while ((!exitg1) && (ObstacleControl_B.i < 2)) {
    if (!(ObstacleControl_DW.obj.DistanceLimits[ObstacleControl_B.i] ==
          ObstacleControl_P.VectorFieldHistogram_DistanceLi[ObstacleControl_B.i]))
    {
      p = false;
      exitg1 = true;
    } else {
      ObstacleControl_B.i++;
    }
  }

  if (p) {
    b_varargout_1 = true;
  }

  if (!b_varargout_1) {
    if ((ObstacleControl_P.VectorFieldHistogram_DistanceLi[0] >
         ObstacleControl_P.VectorFieldHistogram_DistanceLi[1]) || (rtIsNaN
         (ObstacleControl_P.VectorFieldHistogram_DistanceLi[0]) && (!rtIsNaN
          (ObstacleControl_P.VectorFieldHistogram_DistanceLi[1])))) {
      ObstacleControl_DW.obj.DistanceLimits[0] =
        ObstacleControl_P.VectorFieldHistogram_DistanceLi[1];
    } else {
      ObstacleControl_DW.obj.DistanceLimits[0] =
        ObstacleControl_P.VectorFieldHistogram_DistanceLi[0];
    }

    if ((ObstacleControl_P.VectorFieldHistogram_DistanceLi[0] <
         ObstacleControl_P.VectorFieldHistogram_DistanceLi[1]) || (rtIsNaN
         (ObstacleControl_P.VectorFieldHistogram_DistanceLi[0]) && (!rtIsNaN
          (ObstacleControl_P.VectorFieldHistogram_DistanceLi[1])))) {
      ObstacleControl_DW.obj.DistanceLimits[1] =
        ObstacleControl_P.VectorFieldHistogram_DistanceLi[1];
    } else {
      ObstacleControl_DW.obj.DistanceLimits[1] =
        ObstacleControl_P.VectorFieldHistogram_DistanceLi[0];
    }
  }

  b_varargout_1 = false;
  p = true;
  ObstacleControl_B.i = 0;
  exitg1 = false;
  while ((!exitg1) && (ObstacleControl_B.i < 2)) {
    if (!(ObstacleControl_DW.obj.HistogramThresholds[ObstacleControl_B.i] ==
          ObstacleControl_P.VectorFieldHistogram_HistogramT[ObstacleControl_B.i]))
    {
      p = false;
      exitg1 = true;
    } else {
      ObstacleControl_B.i++;
    }
  }

  if (p) {
    b_varargout_1 = true;
  }

  if (!b_varargout_1) {
    if ((ObstacleControl_P.VectorFieldHistogram_HistogramT[0] >
         ObstacleControl_P.VectorFieldHistogram_HistogramT[1]) || (rtIsNaN
         (ObstacleControl_P.VectorFieldHistogram_HistogramT[0]) && (!rtIsNaN
          (ObstacleControl_P.VectorFieldHistogram_HistogramT[1])))) {
      ObstacleControl_DW.obj.HistogramThresholds[0] =
        ObstacleControl_P.VectorFieldHistogram_HistogramT[1];
    } else {
      ObstacleControl_DW.obj.HistogramThresholds[0] =
        ObstacleControl_P.VectorFieldHistogram_HistogramT[0];
    }

    if ((ObstacleControl_P.VectorFieldHistogram_HistogramT[0] <
         ObstacleControl_P.VectorFieldHistogram_HistogramT[1]) || (rtIsNaN
         (ObstacleControl_P.VectorFieldHistogram_HistogramT[0]) && (!rtIsNaN
          (ObstacleControl_P.VectorFieldHistogram_HistogramT[1])))) {
      ObstacleControl_DW.obj.HistogramThresholds[1] =
        ObstacleControl_P.VectorFieldHistogram_HistogramT[1];
    } else {
      ObstacleControl_DW.obj.HistogramThresholds[1] =
        ObstacleControl_P.VectorFieldHistogram_HistogramT[0];
    }
  }

  if (ObstacleControl_DW.obj.RobotRadius !=
      ObstacleControl_P.VectorFieldHistogram_RobotRadiu) {
    ObstacleControl_DW.obj.RobotRadius =
      ObstacleControl_P.VectorFieldHistogram_RobotRadiu;
  }

  if (ObstacleControl_DW.obj.SafetyDistance !=
      ObstacleControl_P.VectorFieldHistogram_SafetyDist) {
    ObstacleControl_DW.obj.SafetyDistance =
      ObstacleControl_P.VectorFieldHistogram_SafetyDist;
  }

  if (ObstacleControl_DW.obj.MinTurningRadius !=
      ObstacleControl_P.VectorFieldHistogram_MinTurning) {
    ObstacleControl_DW.obj.MinTurningRadius =
      ObstacleControl_P.VectorFieldHistogram_MinTurning;
  }

  if (ObstacleControl_DW.obj.TargetDirectionWeight !=
      ObstacleControl_P.VectorFieldHistogram_TargetDire) {
    ObstacleControl_DW.obj.TargetDirectionWeight =
      ObstacleControl_P.VectorFieldHistogram_TargetDire;
  }

  if (ObstacleControl_DW.obj.CurrentDirectionWeight !=
      ObstacleControl_P.VectorFieldHistogram_CurrentDir) {
    ObstacleControl_DW.obj.CurrentDirectionWeight =
      ObstacleControl_P.VectorFieldHistogram_CurrentDir;
  }

  if (ObstacleControl_DW.obj.PreviousDirectionWeight !=
      ObstacleControl_P.VectorFieldHistogram_PreviousDi) {
    ObstacleControl_DW.obj.PreviousDirectionWeight =
      ObstacleControl_P.VectorFieldHistogram_PreviousDi;
  }

  ObstacleControl_B.SFunction_DIMS3 = ObstacleControl_DW.SFunction_DIMS3[0];
  ObstacleControl_B.SFunction_DIMS2 = ObstacleControl_DW.SFunction_DIMS2[0];
  ObstacleControl_B.ranges_e = ObstacleControl_SystemCore_step
    (&ObstacleControl_DW.obj, ObstacleControl_B.dists,
     &ObstacleControl_B.SFunction_DIMS3, ObstacleControl_B.angles,
     &ObstacleControl_B.SFunction_DIMS2, static_cast<real32_T>
     (ObstacleControl_B.b_z1_idx_2));

  // BusAssignment: '<Root>/Bus Assignment1' incorporates:
  //   Constant: '<S1>/Constant'

  ObstacleControl_B.BusAssignment1 = ObstacleControl_P.Constant_Value_d;

  // Switch: '<Root>/Switch2' incorporates:
  //   MATLAB Function: '<S23>/MATLAB Function1'
  //   Switch: '<Root>/Switch'

  if (static_cast<real_T>(ObstacleControl_B.In1_l.Data) >
      ObstacleControl_P.Switch2_Threshold) {
    // BusAssignment: '<Root>/Bus Assignment1' incorporates:
    //   Constant: '<Root>/Constant1'

    ObstacleControl_B.BusAssignment1.Linear.X =
      ObstacleControl_P.Constant1_Value;
  } else if (ObstacleControl_B.y_p > ObstacleControl_P.Switch_Threshold) {
    // Switch: '<Root>/Switch' incorporates:
    //   BusAssignment: '<Root>/Bus Assignment1'
    //   Constant: '<Root>/Constant1'

    ObstacleControl_B.BusAssignment1.Linear.X =
      ObstacleControl_P.Constant1_Value;
  } else {
    // BusAssignment: '<Root>/Bus Assignment1' incorporates:
    //   MATLABSystem: '<S19>/Pure Pursuit'

    ObstacleControl_B.BusAssignment1.Linear.X = ObstacleControl_B.b_z1_idx_0;
  }

  // End of Switch: '<Root>/Switch2'

  // Switch: '<Root>/Switch3' incorporates:
  //   Abs: '<S20>/Abs'
  //   Constant: '<S21>/Constant'
  //   Constant: '<S22>/Constant'
  //   Logic: '<S20>/Logical Operator'
  //   MATLAB Function: '<S23>/MATLAB Function1'
  //   MATLABSystem: '<S19>/Pure Pursuit'
  //   MATLABSystem: '<S19>/Vector Field Histogram'
  //   RelationalOperator: '<S21>/Compare'
  //   RelationalOperator: '<S22>/Compare'
  //   Sum: '<S20>/Subtract'
  //   Switch: '<Root>/Switch1'
  //   Switch: '<S20>/Switch'

  if (static_cast<real_T>(ObstacleControl_B.In1_l.Data) >
      ObstacleControl_P.Switch3_Threshold) {
    // BusAssignment: '<Root>/Bus Assignment1' incorporates:
    //   Constant: '<Root>/Constant1'

    ObstacleControl_B.BusAssignment1.Angular.Z =
      ObstacleControl_P.Constant1_Value;
  } else if (ObstacleControl_B.y_p > ObstacleControl_P.Switch1_Threshold) {
    // Switch: '<Root>/Switch1' incorporates:
    //   BusAssignment: '<Root>/Bus Assignment1'
    //   Constant: '<Root>/Constant1'

    ObstacleControl_B.BusAssignment1.Angular.Z =
      ObstacleControl_P.Constant1_Value;
  } else if ((fabs(ObstacleControl_B.b_z1_idx_2 - ObstacleControl_B.ranges_e) <=
              ObstacleControl_P.CompareToConstant1_const) ||
             (ObstacleControl_B.ranges_e ==
              ObstacleControl_P.CompareToConstant_const)) {
    // Switch: '<S20>/Switch' incorporates:
    //   BusAssignment: '<Root>/Bus Assignment1'
    //   MATLABSystem: '<S19>/Pure Pursuit'
    //   Switch: '<Root>/Switch1'

    ObstacleControl_B.BusAssignment1.Angular.Z = ObstacleControl_B.b_z1_idx_1;
  } else {
    // BusAssignment: '<Root>/Bus Assignment1' incorporates:
    //   Gain: '<S20>/Steering Gain'
    //   MATLABSystem: '<S19>/Vector Field Histogram'
    //   Switch: '<Root>/Switch1'
    //   Switch: '<S20>/Switch'

    ObstacleControl_B.BusAssignment1.Angular.Z =
      ObstacleControl_P.SteeringGain_Gain * ObstacleControl_B.ranges_e;
  }

  // End of Switch: '<Root>/Switch3'

  // Outputs for Atomic SubSystem: '<Root>/Publish'
  // MATLABSystem: '<S4>/SinkBlock'
  Pub_ObstacleControl_5.publish(&ObstacleControl_B.BusAssignment1);

  // End of Outputs for SubSystem: '<Root>/Publish'
}

// Model initialize function
void ObstacleControl_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // non-finite (run-time) assignments
  ObstacleControl_P.CompareToConstant_const = rtNaNF;

  {
    char_T tmp[6];
    char_T tmp_0[13];
    char_T tmp_1[9];
    int32_T i;
    static const char_T tmp_2[5] = { '/', 's', 'c', 'a', 'n' };

    static const char_T tmp_3[5] = { '/', 'o', 'd', 'o', 'm' };

    static const char_T tmp_4[12] = { '/', 'd', 'e', 's', 't', 'i', 'n', 'a',
      't', 'i', 'o', 'n' };

    static const char_T tmp_5[17] = { '/', 'd', 'e', 's', 't', 'i', 'n', 'a',
      't', 'i', 'o', 'n', '/', 's', 't', 'o', 'p' };

    static const char_T tmp_6[8] = { '/', 'c', 'm', 'd', '_', 'v', 'e', 'l' };

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe2'
    // SystemInitialize for Enabled SubSystem: '<S7>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S15>/Out1'
    ObstacleControl_B.In1 = ObstacleControl_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S7>/Enabled Subsystem'

    // Start for MATLABSystem: '<S7>/SourceBlock'
    ObstacleControl_DW.obj_i.matlabCodegenIsDeleted = false;
    ObstacleControl_DW.obj_i.isInitialized = 1;
    for (i = 0; i < 5; i++) {
      tmp[i] = tmp_2[i];
    }

    tmp[5] = '\x00';
    Sub_ObstacleControl_208.createSubscriber(tmp, 1);
    ObstacleControl_DW.obj_i.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S7>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe2'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe'
    // Start for MATLABSystem: '<S5>/SourceBlock'
    ObstacleControl_DW.obj_nl.matlabCodegenIsDeleted = false;
    ObstacleControl_DW.obj_nl.isInitialized = 1;
    for (i = 0; i < 5; i++) {
      tmp[i] = tmp_3[i];
    }

    tmp[5] = '\x00';
    Sub_ObstacleControl_7.createSubscriber(tmp, 1);
    ObstacleControl_DW.obj_nl.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe'

    // SystemInitialize for Enabled SubSystem: '<Root>/Decode ROS msg'
    // SystemInitialize for Outport: '<S2>/X'
    ObstacleControl_B.DataTypeConversion = ObstacleControl_P.X_Y0;

    // SystemInitialize for Outport: '<S2>/Y'
    ObstacleControl_B.DataTypeConversion1 = ObstacleControl_P.Y_Y0;

    // SystemInitialize for Outport: '<S2>/Theta'
    ObstacleControl_B.DataTypeConversion2 = ObstacleControl_P.Theta_Y0;

    // End of SystemInitialize for SubSystem: '<Root>/Decode ROS msg'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe3'
    // SystemInitialize for Enabled SubSystem: '<S8>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S16>/Out1'
    ObstacleControl_B.In1_o = ObstacleControl_P.Out1_Y0_e;

    // End of SystemInitialize for SubSystem: '<S8>/Enabled Subsystem'

    // Start for MATLABSystem: '<S8>/SourceBlock'
    ObstacleControl_DW.obj_c.matlabCodegenIsDeleted = false;
    ObstacleControl_DW.obj_c.isInitialized = 1;
    for (i = 0; i < 12; i++) {
      tmp_0[i] = tmp_4[i];
    }

    tmp_0[12] = '\x00';
    Sub_ObstacleControl_61.createSubscriber(tmp_0, 1);
    ObstacleControl_DW.obj_c.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S8>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe3'

    // SystemInitialize for Enabled SubSystem: '<Root>/Subsystem'
    // SystemInitialize for Outport: '<S9>/waypoints'
    ObstacleControl_B.u[0] = ObstacleControl_P.waypoints_Y0;
    ObstacleControl_B.u[1] = ObstacleControl_P.waypoints_Y0;
    ObstacleControl_B.u[2] = ObstacleControl_P.waypoints_Y0;
    ObstacleControl_B.u[3] = ObstacleControl_P.waypoints_Y0;

    // End of SystemInitialize for SubSystem: '<Root>/Subsystem'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe1'
    // SystemInitialize for Enabled SubSystem: '<S6>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S14>/Out1'
    ObstacleControl_B.In1_l = ObstacleControl_P.Out1_Y0_ev;

    // End of SystemInitialize for SubSystem: '<S6>/Enabled Subsystem'

    // Start for MATLABSystem: '<S6>/SourceBlock'
    ObstacleControl_DW.obj_h.matlabCodegenIsDeleted = false;
    ObstacleControl_DW.obj_h.isInitialized = 1;
    for (i = 0; i < 17; i++) {
      ObstacleControl_B.cv[i] = tmp_5[i];
    }

    ObstacleControl_B.cv[17] = '\x00';
    Sub_ObstacleControl_196.createSubscriber(ObstacleControl_B.cv, 1);
    ObstacleControl_DW.obj_h.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S6>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe1'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish'
    // Start for MATLABSystem: '<S4>/SinkBlock'
    ObstacleControl_DW.obj_d.matlabCodegenIsDeleted = false;
    ObstacleControl_DW.obj_d.isInitialized = 1;
    for (i = 0; i < 8; i++) {
      tmp_1[i] = tmp_6[i];
    }

    tmp_1[8] = '\x00';
    Pub_ObstacleControl_5.createPublisher(tmp_1, 1);
    ObstacleControl_DW.obj_d.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S4>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish'

    // Start for MATLABSystem: '<S19>/Pure Pursuit'
    ObstacleControl_DW.obj_n.DesiredLinearVelocity =
      ObstacleControl_P.PurePursuit_DesiredLinearVeloci;
    ObstacleControl_DW.obj_n.MaxAngularVelocity =
      ObstacleControl_P.PurePursuit_MaxAngularVelocity;
    ObstacleControl_DW.obj_n.LookaheadDistance =
      ObstacleControl_P.PurePursuit_LookaheadDistance;
    ObstacleControl_DW.obj_n.isInitialized = 1;
    ObstacleControl_DW.obj_n.WaypointsInternal[0] = (rtNaN);
    ObstacleControl_DW.obj_n.WaypointsInternal[1] = (rtNaN);
    ObstacleControl_DW.obj_n.WaypointsInternal[2] = (rtNaN);
    ObstacleControl_DW.obj_n.WaypointsInternal[3] = (rtNaN);
    ObstacleControl_DW.obj_n.LookaheadPoint[0] = 0.0;
    ObstacleControl_DW.obj_n.LookaheadPoint[1] = 0.0;
    ObstacleControl_DW.obj_n.LastPose[0] = 0.0;
    ObstacleControl_DW.obj_n.LastPose[1] = 0.0;
    ObstacleControl_DW.obj_n.LastPose[2] = 0.0;
    ObstacleControl_DW.obj_n.ProjectionLineIndex = 0.0;

    // InitializeConditions for MATLABSystem: '<S19>/Pure Pursuit'
    ObstacleControl_DW.obj_n.LookaheadPoint[0] *= 0.0;
    ObstacleControl_DW.obj_n.LookaheadPoint[1] *= 0.0;
    ObstacleControl_DW.obj_n.LastPose[0] *= 0.0;
    ObstacleControl_DW.obj_n.LastPose[1] *= 0.0;
    ObstacleControl_DW.obj_n.LastPose[2] *= 0.0;
    ObstacleControl_DW.obj_n.ProjectionLineIndex *= 0.0;

    // Start for MATLABSystem: '<S19>/Vector Field Histogram'
    ObstacleControl_DW.obj.NarrowOpeningThreshold = 0.8;

    // InitializeConditions for MATLABSystem: '<S19>/Pure Pursuit'
    ObstacleControl_DW.obj_n.ProjectionPoint[0] = (rtNaN);

    // Start for MATLABSystem: '<S19>/Vector Field Histogram'
    ObstacleControl_DW.obj.AngularLimits[0] = -3.1415926535897931;

    // InitializeConditions for MATLABSystem: '<S19>/Pure Pursuit'
    ObstacleControl_DW.obj_n.ProjectionPoint[1] = (rtNaN);

    // Start for MATLABSystem: '<S19>/Vector Field Histogram'
    ObstacleControl_DW.obj.AngularLimits[1] = 3.1415926535897931;
    ObstacleControl_DW.obj.CacheInputSizes = false;
    if ((ObstacleControl_P.VectorFieldHistogram_DistanceLi[0] >
         ObstacleControl_P.VectorFieldHistogram_DistanceLi[1]) || (rtIsNaN
         (ObstacleControl_P.VectorFieldHistogram_DistanceLi[0]) && (!rtIsNaN
          (ObstacleControl_P.VectorFieldHistogram_DistanceLi[1])))) {
      ObstacleControl_DW.obj.DistanceLimits[0] =
        ObstacleControl_P.VectorFieldHistogram_DistanceLi[1];
    } else {
      ObstacleControl_DW.obj.DistanceLimits[0] =
        ObstacleControl_P.VectorFieldHistogram_DistanceLi[0];
    }

    if ((ObstacleControl_P.VectorFieldHistogram_DistanceLi[0] <
         ObstacleControl_P.VectorFieldHistogram_DistanceLi[1]) || (rtIsNaN
         (ObstacleControl_P.VectorFieldHistogram_DistanceLi[0]) && (!rtIsNaN
          (ObstacleControl_P.VectorFieldHistogram_DistanceLi[1])))) {
      ObstacleControl_DW.obj.DistanceLimits[1] =
        ObstacleControl_P.VectorFieldHistogram_DistanceLi[1];
    } else {
      ObstacleControl_DW.obj.DistanceLimits[1] =
        ObstacleControl_P.VectorFieldHistogram_DistanceLi[0];
    }

    if ((ObstacleControl_P.VectorFieldHistogram_HistogramT[0] >
         ObstacleControl_P.VectorFieldHistogram_HistogramT[1]) || (rtIsNaN
         (ObstacleControl_P.VectorFieldHistogram_HistogramT[0]) && (!rtIsNaN
          (ObstacleControl_P.VectorFieldHistogram_HistogramT[1])))) {
      ObstacleControl_DW.obj.HistogramThresholds[0] =
        ObstacleControl_P.VectorFieldHistogram_HistogramT[1];
    } else {
      ObstacleControl_DW.obj.HistogramThresholds[0] =
        ObstacleControl_P.VectorFieldHistogram_HistogramT[0];
    }

    if ((ObstacleControl_P.VectorFieldHistogram_HistogramT[0] <
         ObstacleControl_P.VectorFieldHistogram_HistogramT[1]) || (rtIsNaN
         (ObstacleControl_P.VectorFieldHistogram_HistogramT[0]) && (!rtIsNaN
          (ObstacleControl_P.VectorFieldHistogram_HistogramT[1])))) {
      ObstacleControl_DW.obj.HistogramThresholds[1] =
        ObstacleControl_P.VectorFieldHistogram_HistogramT[1];
    } else {
      ObstacleControl_DW.obj.HistogramThresholds[1] =
        ObstacleControl_P.VectorFieldHistogram_HistogramT[0];
    }

    ObstacleControl_DW.obj.RobotRadius =
      ObstacleControl_P.VectorFieldHistogram_RobotRadiu;
    ObstacleControl_DW.obj.SafetyDistance =
      ObstacleControl_P.VectorFieldHistogram_SafetyDist;
    ObstacleControl_DW.obj.MinTurningRadius =
      ObstacleControl_P.VectorFieldHistogram_MinTurning;
    ObstacleControl_DW.obj.TargetDirectionWeight =
      ObstacleControl_P.VectorFieldHistogram_TargetDire;
    ObstacleControl_DW.obj.CurrentDirectionWeight =
      ObstacleControl_P.VectorFieldHistogram_CurrentDir;
    ObstacleControl_DW.obj.PreviousDirectionWeight =
      ObstacleControl_P.VectorFieldHistogram_PreviousDi;
    ObstacleControl_DW.obj.isInitialized = 1;
    i = ObstacleControl_DW.SFunction_DIMS3[0];
    if (ObstacleControl_DW.SFunction_DIMS3[0] < 0) {
      i = 0;
    }

    ObstacleControl_DW.obj.inputVarSize[0].f1[0] = static_cast<uint32_T>(i);
    ObstacleControl_DW.obj.inputVarSize[0].f1[1] = 1U;
    i = ObstacleControl_DW.SFunction_DIMS2[0];
    if (ObstacleControl_DW.SFunction_DIMS2[0] < 0) {
      i = 0;
    }

    ObstacleControl_DW.obj.inputVarSize[1].f1[0] = static_cast<uint32_T>(i);
    ObstacleControl_DW.obj.inputVarSize[1].f1[1] = 1U;
    for (i = 0; i < 6; i++) {
      ObstacleControl_DW.obj.inputVarSize[0].f1[i + 2] = 1U;
      ObstacleControl_DW.obj.inputVarSize[1].f1[i + 2] = 1U;
    }

    for (i = 0; i < 8; i++) {
      ObstacleControl_DW.obj.inputVarSize[2].f1[i] = 1U;
    }

    VectorFieldHistogramBase_setupI(&ObstacleControl_DW.obj);

    // InitializeConditions for MATLABSystem: '<S19>/Vector Field Histogram'
    for (i = 0; i < 36; i++) {
      ObstacleControl_DW.obj.BinaryHistogram[i] = false;
    }

    ObstacleControl_DW.obj.PreviousDirection *= 0.0F;

    // End of InitializeConditions for MATLABSystem: '<S19>/Vector Field Histogram' 
  }
}

// Model terminate function
void ObstacleControl_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe2'
  // Terminate for MATLABSystem: '<S7>/SourceBlock'
  matlabCodegenHandle_matlabCod_n(&ObstacleControl_DW.obj_i);

  // End of Terminate for SubSystem: '<Root>/Subscribe2'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Terminate for MATLABSystem: '<S5>/SourceBlock'
  matlabCodegenHandle_matlabCod_n(&ObstacleControl_DW.obj_nl);

  // End of Terminate for SubSystem: '<Root>/Subscribe'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe3'
  // Terminate for MATLABSystem: '<S8>/SourceBlock'
  matlabCodegenHandle_matlabCod_n(&ObstacleControl_DW.obj_c);

  // End of Terminate for SubSystem: '<Root>/Subscribe3'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe1'
  // Terminate for MATLABSystem: '<S6>/SourceBlock'
  matlabCodegenHandle_matlabCod_n(&ObstacleControl_DW.obj_h);

  // End of Terminate for SubSystem: '<Root>/Subscribe1'

  // Terminate for Atomic SubSystem: '<Root>/Publish'
  // Terminate for MATLABSystem: '<S4>/SinkBlock'
  matlabCodegenHandle_matlabCodeg(&ObstacleControl_DW.obj_d);

  // End of Terminate for SubSystem: '<Root>/Publish'
}

//
// File trailer for generated code.
//
// [EOF]
//
