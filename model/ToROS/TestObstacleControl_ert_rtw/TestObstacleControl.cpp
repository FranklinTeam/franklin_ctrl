//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: TestObstacleControl.cpp
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
#include "TestObstacleControl.h"
#include "TestObstacleControl_private.h"

// Block signals (default storage)
B_TestObstacleControl_T TestObstacleControl_B;

// Block states (default storage)
DW_TestObstacleControl_T TestObstacleControl_DW;

// Real-time model
RT_MODEL_TestObstacleControl_T TestObstacleControl_M_ =
  RT_MODEL_TestObstacleControl_T();
RT_MODEL_TestObstacleControl_T *const TestObstacleControl_M =
  &TestObstacleControl_M_;

// Forward declaration for local functions
static real_T TestObstacleControl_norm(const real_T x[2]);
static void TestObstacle_closestPointOnLine(const real_T pt1[2], const real_T
  pt2[2], const real_T refPt[2], real_T closestPoint[2], real_T *distance);
static void Te_PurePursuitBase_stepInternal(nav_slalgs_internal_PurePursu_T *obj,
  const real_T currentPose[3], const real_T wayptsIn[8], real_T *v, real_T *w,
  real_T lookaheadPoint[2], real_T *targetDir);
static void SystemCore_initializeInputSizes(nav_slalgs_internal_VectorFie_T *obj,
  const int32_T *varargin_1_size, const int32_T *varargin_2_size);
static void SystemCore_systemblock_prestep(nav_slalgs_internal_VectorFie_T *obj,
  const int32_T *varargin_1_size, const int32_T *varargin_2_size);
static boolean_T SystemCore_detectInputSizeChang(nav_slalgs_internal_VectorFie_T
  *obj, const int32_T *varargin_1_size, const int32_T *varargin_2_size);
static real32_T TestObstacleControl_floatmod(real32_T x);
static void TestObstacleContro_wrapToPi_ov2(real32_T theta_data[], const int32_T
  *theta_size);
static void TestObsta_lidarScan_lidarScan_o(const real32_T varargin_2_data[],
  const int32_T *varargin_2_size, real32_T obj_InternalAngles_data[], int32_T
  *obj_InternalAngles_size, boolean_T *obj_ContainsOnlyFiniteData);
static real32_T TestObstacleControl_wrapToPi_o(real32_T theta);
static void TestObstacleControl_sort(const real32_T x[2], real32_T b_x[2]);
static void TestObstacleControl_isfinite(const real32_T x_data[], const int32_T *
  x_size, boolean_T b_data[], int32_T *b_size);
static void TestObstacleCo_nullAssignment_o(real32_T x_data[], int32_T *x_size,
  const boolean_T idx_data[], const int32_T *idx_size);
static boolean_T T_lidarScan_removeInvalidData_o(real32_T
  objIn_InternalRanges_data[], int32_T *objIn_InternalRanges_size, real32_T
  objIn_InternalAngles_data[], int32_T *objIn_InternalAngles_size, const
  real32_T varargin_2[2]);
static boolean_T TestObstacleControl_isequal(void);
static void TestObstacleControl_asin(const real32_T x_data[], const int32_T
  *x_size, real32_T b_x_data[], int32_T *b_x_size);
static void TestObstacleControl_cos(const real32_T x_data[], const int32_T
  *x_size, real32_T b_x_data[], int32_T *b_x_size);
static void TestObstacleControl_sin(const real32_T x_data[], const int32_T
  *x_size, real32_T b_x_data[], int32_T *b_x_size);
static void TestObstacleControl_cross(const real32_T a_data[], const int32_T
  a_size[2], const real32_T b_data[], real32_T c_data[], int32_T c_size[2]);
static void TestObstacleControl_repmat(const real32_T a[3], real_T varargin_1,
  real32_T b_data[], int32_T b_size[2]);
static void TestObstacleControl_sign_o(real32_T x_data[], const int32_T *x_size);
static void TestObstacleControl_abs(const real32_T x_data[], const int32_T
  *x_size, real32_T y_data[], int32_T *y_size);
static void TestObstacleControl_histc(const real32_T X_data[], const int32_T
  *X_size, const real32_T edges[36], real_T N[36], real_T BIN_data[], int32_T
  *BIN_size);
static void VectorFieldHistogramBase_buildP(nav_slalgs_internal_VectorFie_T *obj,
  const real32_T scan_InternalRanges_data[], const int32_T
  *scan_InternalRanges_size, const real32_T scan_InternalAngles_data[], const
  int32_T *scan_InternalAngles_size);
static void TestObstacleControl_power(const real32_T a_data[], const int32_T
  *a_size, real32_T y_data[], int32_T *y_size);
static void TestObstacleControl_sqrt_o(real32_T x_data[], const int32_T *x_size);
static void VectorFieldHistogramBase_buildM(nav_slalgs_internal_VectorFie_T *obj,
  const real32_T scan_InternalRanges_data[], const int32_T
  *scan_InternalRanges_size, const real32_T scan_InternalAngles_data[], const
  int32_T *scan_InternalAngles_size);
static void TestObstacleControl_diff(const real_T x[38], real_T y[37]);
static boolean_T TestObstacleControl_any(const real32_T x[37]);
static void TestObstacleControl_diff_o(const real32_T x_data[], const int32_T
  x_size[2], real32_T y_data[], int32_T y_size[2]);
static void TestObstacleControl_wrapToPi_ov(const real32_T theta_data[], const
  int32_T theta_size[2], real32_T b_theta_data[], int32_T b_theta_size[2]);
static void TestObstacleContro_bisectAngles(real32_T theta1_data[], int32_T
  theta1_size[2], real32_T theta2_data[], const int32_T theta2_size[2], real32_T
  bisect_data[], int32_T bisect_size[2]);
static void TestObstacleControl_bsxfun(const real32_T a[36], const real32_T
  b_data[], const int32_T *b_size, real32_T c_data[], int32_T c_size[2]);
static void TestObstacleControl_abs_o(const real32_T x_data[], const int32_T
  x_size[2], real32_T y_data[], int32_T y_size[2]);
static void TestObstacleControl_bsxfun_o(const real32_T a_data[], const int32_T
  a_size[2], const real32_T b_data[], const int32_T *b_size, real32_T c_data[],
  int32_T c_size[2]);
static boolean_T TestObstacleControl_any_o(const boolean_T x_data[], const
  int32_T x_size[2]);
static void VectorFieldHistogramBase_comput(const
  nav_slalgs_internal_VectorFie_T *obj, const real32_T c_data[], const int32_T
  c_size[2], real32_T targetDir, real32_T prevDir, real32_T cost_data[], int32_T
  cost_size[2]);
static real32_T VectorFieldHistogramBase_select(nav_slalgs_internal_VectorFie_T *
  obj, real32_T targetDir);
static real32_T VectorFieldHistogramBase_stepIm(nav_slalgs_internal_VectorFie_T *
  obj, const real32_T varargin_1_data[], const int32_T *varargin_1_size, const
  real_T varargin_2_data[], const int32_T *varargin_2_size, real32_T varargin_3);
static real32_T TestObstacleCon_SystemCore_step(nav_slalgs_internal_VectorFie_T *
  obj, const real32_T varargin_1_data[], const int32_T *varargin_1_size, const
  real_T varargin_2_data[], const int32_T *varargin_2_size, real32_T varargin_3);
static void matlabCodegenHandle_matlabCod_o(ros_slros_internal_block_Subs_T *obj);
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

static real_T TestObstacleControl_norm(const real_T x[2])
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

static void TestObstacle_closestPointOnLine(const real_T pt1[2], const real_T
  pt2[2], const real_T refPt[2], real_T closestPoint[2], real_T *distance)
{
  boolean_T p;
  boolean_T p_0;
  int32_T b_k;
  real_T v12;
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
    TestObstacleControl_B.refPt[0] = refPt[0] - pt1[0];
    closestPoint[1] = pt1[1];
    TestObstacleControl_B.refPt[1] = refPt[1] - pt1[1];
    *distance = TestObstacleControl_norm(TestObstacleControl_B.refPt);
  } else {
    TestObstacleControl_B.alpha = pt2[0] - pt1[0];
    TestObstacleControl_B.v12 = (pt2[0] - refPt[0]) *
      TestObstacleControl_B.alpha;
    v12 = TestObstacleControl_B.alpha * TestObstacleControl_B.alpha;
    TestObstacleControl_B.alpha = pt2[1] - pt1[1];
    TestObstacleControl_B.v12 += (pt2[1] - refPt[1]) *
      TestObstacleControl_B.alpha;
    v12 += TestObstacleControl_B.alpha * TestObstacleControl_B.alpha;
    TestObstacleControl_B.alpha = TestObstacleControl_B.v12 / v12;
    p = (TestObstacleControl_B.alpha > 1.0);
    p_0 = (TestObstacleControl_B.alpha < 0.0);
    if (p) {
      TestObstacleControl_B.v12 = pt1[0];
    } else if (p_0) {
      TestObstacleControl_B.v12 = pt2[0];
    } else {
      TestObstacleControl_B.v12 = (1.0 - TestObstacleControl_B.alpha) * pt2[0] +
        TestObstacleControl_B.alpha * pt1[0];
    }

    TestObstacleControl_B.refPt[0] = refPt[0] - TestObstacleControl_B.v12;
    closestPoint[0] = TestObstacleControl_B.v12;
    if (p) {
      TestObstacleControl_B.v12 = pt1[1];
    } else if (p_0) {
      TestObstacleControl_B.v12 = pt2[1];
    } else {
      TestObstacleControl_B.v12 = (1.0 - TestObstacleControl_B.alpha) * pt2[1] +
        TestObstacleControl_B.alpha * pt1[1];
    }

    TestObstacleControl_B.refPt[1] = refPt[1] - TestObstacleControl_B.v12;
    closestPoint[1] = TestObstacleControl_B.v12;
    *distance = TestObstacleControl_norm(TestObstacleControl_B.refPt);
  }
}

static void Te_PurePursuitBase_stepInternal(nav_slalgs_internal_PurePursu_T *obj,
  const real_T currentPose[3], const real_T wayptsIn[8], real_T *v, real_T *w,
  real_T lookaheadPoint[2], real_T *targetDir)
{
  int32_T trueCount;
  int32_T i;
  int32_T partialTrueCount;
  boolean_T searchFlag;
  int32_T i_tmp;
  int32_T i_tmp_0;
  boolean_T exitg1;
  for (i = 0; i < 8; i++) {
    TestObstacleControl_B.b[i] = !rtIsNaN(wayptsIn[i]);
  }

  trueCount = 0;
  partialTrueCount = 0;
  for (i = 0; i < 4; i++) {
    if (TestObstacleControl_B.b[i] && TestObstacleControl_B.b[i + 4]) {
      trueCount++;
      TestObstacleControl_B.f_data[partialTrueCount] = i + 1;
      partialTrueCount++;
    }
  }

  for (i = 0; i < trueCount; i++) {
    TestObstacleControl_B.waypoints_data[i] =
      wayptsIn[TestObstacleControl_B.f_data[i] - 1];
    TestObstacleControl_B.waypoints_data[i + trueCount] =
      wayptsIn[TestObstacleControl_B.f_data[i] + 3];
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
      obj->ProjectionPoint[0] = TestObstacleControl_B.waypoints_data[0];
      obj->ProjectionPoint[1] = TestObstacleControl_B.waypoints_data[trueCount];
      obj->ProjectionLineIndex = 1.0;
    }

    if (trueCount == 1) {
      obj->ProjectionPoint[0] = TestObstacleControl_B.waypoints_data[0];
      obj->ProjectionPoint[1] = TestObstacleControl_B.waypoints_data[trueCount];
      TestObstacleControl_B.lookaheadStartPt[0] =
        TestObstacleControl_B.waypoints_data[0];
      TestObstacleControl_B.lookaheadStartPt[1] =
        TestObstacleControl_B.waypoints_data[trueCount];
    } else {
      i = static_cast<int32_T>(obj->ProjectionLineIndex + 1.0);
      TestObstacleControl_B.waypoints[0] =
        TestObstacleControl_B.waypoints_data[i - 1];
      TestObstacleControl_B.waypoints[1] = TestObstacleControl_B.waypoints_data
        [(i + trueCount) - 1];
      for (i = 0; i < 2; i++) {
        TestObstacleControl_B.lookaheadStartPt[i] = obj->ProjectionPoint[i];
      }

      TestObstacle_closestPointOnLine(TestObstacleControl_B.lookaheadStartPt,
        TestObstacleControl_B.waypoints, &currentPose[0], obj->ProjectionPoint,
        &TestObstacleControl_B.minDistance);
      i = static_cast<int32_T>(obj->ProjectionLineIndex + 1.0);
      TestObstacleControl_B.lookaheadStartPt[0] = obj->ProjectionPoint[0] -
        TestObstacleControl_B.waypoints_data[i - 1];
      TestObstacleControl_B.lookaheadStartPt[1] = obj->ProjectionPoint[1] -
        TestObstacleControl_B.waypoints_data[(i + trueCount) - 1];
      TestObstacleControl_B.dist = TestObstacleControl_norm
        (TestObstacleControl_B.lookaheadStartPt);
      TestObstacleControl_B.lookaheadEndPt_idx_1 = obj->ProjectionLineIndex +
        1.0;
      i = static_cast<int32_T>((1.0 - (obj->ProjectionLineIndex + 1.0)) + (
        static_cast<real_T>(trueCount) - 1.0)) - 1;
      partialTrueCount = 0;
      exitg1 = false;
      while ((!exitg1) && (partialTrueCount <= i)) {
        TestObstacleControl_B.overshootDist =
          TestObstacleControl_B.lookaheadEndPt_idx_1 + static_cast<real_T>
          (partialTrueCount);
        if ((!searchFlag) && (TestObstacleControl_B.dist >
                              obj->LookaheadDistance)) {
          exitg1 = true;
        } else {
          i_tmp = static_cast<int32_T>(TestObstacleControl_B.overshootDist);
          i_tmp_0 = static_cast<int32_T>(TestObstacleControl_B.overshootDist +
            1.0);
          TestObstacleControl_B.waypoints[0] =
            TestObstacleControl_B.waypoints_data[i_tmp - 1] -
            TestObstacleControl_B.waypoints_data[i_tmp_0 - 1];
          TestObstacleControl_B.waypoints_d[0] =
            TestObstacleControl_B.waypoints_data[i_tmp - 1];
          TestObstacleControl_B.waypoints_l[0] =
            TestObstacleControl_B.waypoints_data[i_tmp_0 - 1];
          TestObstacleControl_B.waypoints[1] =
            TestObstacleControl_B.waypoints_data[(i_tmp + trueCount) - 1] -
            TestObstacleControl_B.waypoints_data[(i_tmp_0 + trueCount) - 1];
          TestObstacleControl_B.waypoints_d[1] =
            TestObstacleControl_B.waypoints_data[(i_tmp + trueCount) - 1];
          TestObstacleControl_B.waypoints_l[1] =
            TestObstacleControl_B.waypoints_data[(i_tmp_0 + trueCount) - 1];
          TestObstacleControl_B.dist += TestObstacleControl_norm
            (TestObstacleControl_B.waypoints);
          TestObstacle_closestPointOnLine(TestObstacleControl_B.waypoints_d,
            TestObstacleControl_B.waypoints_l, &currentPose[0],
            TestObstacleControl_B.lookaheadStartPt,
            &TestObstacleControl_B.lookaheadIdx);
          if (TestObstacleControl_B.lookaheadIdx <
              TestObstacleControl_B.minDistance) {
            TestObstacleControl_B.minDistance =
              TestObstacleControl_B.lookaheadIdx;
            obj->ProjectionPoint[0] = TestObstacleControl_B.lookaheadStartPt[0];
            obj->ProjectionPoint[1] = TestObstacleControl_B.lookaheadStartPt[1];
            obj->ProjectionLineIndex = TestObstacleControl_B.overshootDist;
          }

          partialTrueCount++;
        }
      }

      i = static_cast<int32_T>(obj->ProjectionLineIndex + 1.0);
      TestObstacleControl_B.lookaheadStartPt[0] = obj->ProjectionPoint[0] -
        TestObstacleControl_B.waypoints_data[i - 1];
      TestObstacleControl_B.lookaheadStartPt[1] = obj->ProjectionPoint[1] -
        TestObstacleControl_B.waypoints_data[(i + trueCount) - 1];
      TestObstacleControl_B.dist = TestObstacleControl_norm
        (TestObstacleControl_B.lookaheadStartPt);
      i = static_cast<int32_T>(obj->ProjectionLineIndex + 1.0);
      TestObstacleControl_B.lookaheadStartPt[0] = obj->ProjectionPoint[0];
      TestObstacleControl_B.minDistance = TestObstacleControl_B.waypoints_data[i
        - 1];
      TestObstacleControl_B.lookaheadStartPt[1] = obj->ProjectionPoint[1];
      TestObstacleControl_B.lookaheadEndPt_idx_1 =
        TestObstacleControl_B.waypoints_data[(i + trueCount) - 1];
      TestObstacleControl_B.overshootDist = TestObstacleControl_B.dist -
        obj->LookaheadDistance;
      TestObstacleControl_B.lookaheadIdx = obj->ProjectionLineIndex;
      while ((TestObstacleControl_B.overshootDist < 0.0) &&
             (TestObstacleControl_B.lookaheadIdx < static_cast<real_T>(trueCount)
              - 1.0)) {
        TestObstacleControl_B.lookaheadIdx++;
        i = static_cast<int32_T>(TestObstacleControl_B.lookaheadIdx);
        partialTrueCount = static_cast<int32_T>
          (TestObstacleControl_B.lookaheadIdx + 1.0);
        TestObstacleControl_B.lookaheadStartPt[0] =
          TestObstacleControl_B.waypoints_data[i - 1];
        TestObstacleControl_B.lookaheadEndPt_idx_1 =
          TestObstacleControl_B.waypoints_data[partialTrueCount - 1];
        TestObstacleControl_B.waypoints[0] =
          TestObstacleControl_B.waypoints_data[i - 1] -
          TestObstacleControl_B.lookaheadEndPt_idx_1;
        TestObstacleControl_B.minDistance =
          TestObstacleControl_B.lookaheadEndPt_idx_1;
        TestObstacleControl_B.lookaheadStartPt[1] =
          TestObstacleControl_B.waypoints_data[(i + trueCount) - 1];
        TestObstacleControl_B.lookaheadEndPt_idx_1 =
          TestObstacleControl_B.waypoints_data[(partialTrueCount + trueCount) -
          1];
        TestObstacleControl_B.waypoints[1] =
          TestObstacleControl_B.waypoints_data[(i + trueCount) - 1] -
          TestObstacleControl_B.lookaheadEndPt_idx_1;
        TestObstacleControl_B.dist += TestObstacleControl_norm
          (TestObstacleControl_B.waypoints);
        TestObstacleControl_B.overshootDist = TestObstacleControl_B.dist -
          obj->LookaheadDistance;
      }

      TestObstacleControl_B.waypoints[0] =
        TestObstacleControl_B.lookaheadStartPt[0] -
        TestObstacleControl_B.minDistance;
      TestObstacleControl_B.waypoints[1] =
        TestObstacleControl_B.lookaheadStartPt[1] -
        TestObstacleControl_B.lookaheadEndPt_idx_1;
      TestObstacleControl_B.dist = TestObstacleControl_B.overshootDist /
        TestObstacleControl_norm(TestObstacleControl_B.waypoints);
      if (TestObstacleControl_B.dist > 0.0) {
        TestObstacleControl_B.lookaheadStartPt[0] = (1.0 -
          TestObstacleControl_B.dist) * TestObstacleControl_B.minDistance +
          TestObstacleControl_B.dist * TestObstacleControl_B.lookaheadStartPt[0];
        TestObstacleControl_B.lookaheadStartPt[1] = (1.0 -
          TestObstacleControl_B.dist) *
          TestObstacleControl_B.lookaheadEndPt_idx_1 +
          TestObstacleControl_B.dist * TestObstacleControl_B.lookaheadStartPt[1];
      } else {
        TestObstacleControl_B.lookaheadStartPt[0] =
          TestObstacleControl_B.minDistance;
        TestObstacleControl_B.lookaheadStartPt[1] =
          TestObstacleControl_B.lookaheadEndPt_idx_1;
      }
    }

    obj->LookaheadPoint[0] = TestObstacleControl_B.lookaheadStartPt[0];
    obj->LookaheadPoint[1] = TestObstacleControl_B.lookaheadStartPt[1];
    *targetDir = rt_atan2d_snf(obj->LookaheadPoint[1] - currentPose[1],
      obj->LookaheadPoint[0] - currentPose[0]) - currentPose[2];
    if (fabs(*targetDir) > 3.1415926535897931) {
      if (rtIsNaN(*targetDir + 3.1415926535897931) || rtIsInf(*targetDir +
           3.1415926535897931)) {
        TestObstacleControl_B.dist = (rtNaN);
      } else if (*targetDir + 3.1415926535897931 == 0.0) {
        TestObstacleControl_B.dist = 0.0;
      } else {
        TestObstacleControl_B.dist = fmod(*targetDir + 3.1415926535897931,
          6.2831853071795862);
        searchFlag = (TestObstacleControl_B.dist == 0.0);
        if (!searchFlag) {
          TestObstacleControl_B.minDistance = fabs((*targetDir +
            3.1415926535897931) / 6.2831853071795862);
          searchFlag = !(fabs(TestObstacleControl_B.minDistance - floor
                              (TestObstacleControl_B.minDistance + 0.5)) >
                         2.2204460492503131E-16 *
                         TestObstacleControl_B.minDistance);
        }

        if (searchFlag) {
          TestObstacleControl_B.dist = 0.0;
        } else {
          if (*targetDir + 3.1415926535897931 < 0.0) {
            TestObstacleControl_B.dist += 6.2831853071795862;
          }
        }
      }

      TestObstacleControl_B.b_l = TestObstacleControl_B.dist;
      if ((TestObstacleControl_B.dist == 0.0) && (*targetDir +
           3.1415926535897931 > 0.0)) {
        TestObstacleControl_B.b_l = 6.2831853071795862;
      }

      *targetDir = TestObstacleControl_B.b_l - 3.1415926535897931;
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

static real32_T TestObstacleControl_floatmod(real32_T x)
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

static void TestObstacleContro_wrapToPi_ov2(real32_T theta_data[], const int32_T
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
    TestObstacleControl_B.y_data[b_k] = static_cast<real32_T>(fabs
      (static_cast<real_T>(theta_data[b_k])));
  }

  for (b_k = 0; b_k < y_size_idx_0; b_k++) {
    TestObstacleControl_B.pos_data[b_k] = (TestObstacleControl_B.y_data[b_k] >
      3.1415926535897931);
  }

  y = false;
  b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (b_k + 1 <= *theta_size)) {
    if (!TestObstacleControl_B.pos_data[b_k]) {
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
      TestObstacleControl_B.y_data[b_k] = theta_data[b_k] + 3.14159274F;
    }

    for (b_k = 0; b_k < y_size_idx_0; b_k++) {
      TestObstacleControl_B.pos_data[b_k] = (TestObstacleControl_B.y_data[b_k] >
        0.0F);
    }

    nx = *theta_size - 1;
    for (b_k = 0; b_k <= nx; b_k++) {
      theta_data[b_k] = TestObstacleControl_floatmod
        (TestObstacleControl_B.y_data[b_k]);
    }

    nx = *theta_size;
    for (b_k = 0; b_k < nx; b_k++) {
      TestObstacleControl_B.b_data[b_k] = (theta_data[b_k] == 0.0F);
    }

    b_k = *theta_size - 1;
    for (y_size_idx_0 = 0; y_size_idx_0 <= b_k; y_size_idx_0++) {
      if (TestObstacleControl_B.b_data[y_size_idx_0] &&
          TestObstacleControl_B.pos_data[y_size_idx_0]) {
        theta_data[y_size_idx_0] = 6.28318548F;
      }
    }

    nx = *theta_size;
    for (b_k = 0; b_k < nx; b_k++) {
      theta_data[b_k] -= 3.14159274F;
    }
  }
}

static void TestObsta_lidarScan_lidarScan_o(const real32_T varargin_2_data[],
  const int32_T *varargin_2_size, real32_T obj_InternalAngles_data[], int32_T
  *obj_InternalAngles_size, boolean_T *obj_ContainsOnlyFiniteData)
{
  *obj_ContainsOnlyFiniteData = false;
  *obj_InternalAngles_size = *varargin_2_size;
  if (0 <= *varargin_2_size - 1) {
    memcpy(&obj_InternalAngles_data[0], &varargin_2_data[0], *varargin_2_size *
           sizeof(real32_T));
  }

  TestObstacleContro_wrapToPi_ov2(obj_InternalAngles_data,
    obj_InternalAngles_size);
}

static real32_T TestObstacleControl_wrapToPi_o(real32_T theta)
{
  real32_T b_theta;
  real32_T thetaWrap;
  b_theta = theta;
  if (static_cast<real32_T>(fabs(static_cast<real_T>(theta))) >
      3.1415926535897931) {
    thetaWrap = TestObstacleControl_floatmod(theta + 3.14159274F);
    if ((thetaWrap == 0.0F) && (theta + 3.14159274F > 0.0F)) {
      thetaWrap = 6.28318548F;
    }

    b_theta = thetaWrap - 3.14159274F;
  }

  return b_theta;
}

static void TestObstacleControl_sort(const real32_T x[2], real32_T b_x[2])
{
  b_x[0] = x[0];
  b_x[1] = x[1];
  if ((x[0] <= x[1]) || rtIsNaNF(x[1])) {
  } else {
    b_x[0] = x[1];
    b_x[1] = x[0];
  }
}

static void TestObstacleControl_isfinite(const real32_T x_data[], const int32_T *
  x_size, boolean_T b_data[], int32_T *b_size)
{
  int32_T i;
  int32_T loop_ub;
  *b_size = *x_size;
  loop_ub = *x_size;
  for (i = 0; i < loop_ub; i++) {
    b_data[i] = rtIsInfF(x_data[i]);
  }

  for (i = 0; i < loop_ub; i++) {
    TestObstacleControl_B.tmp_data_l[i] = rtIsNaNF(x_data[i]);
  }

  for (i = 0; i < loop_ub; i++) {
    b_data[i] = ((!b_data[i]) && (!TestObstacleControl_B.tmp_data_l[i]));
  }
}

static void TestObstacleCo_nullAssignment_o(real32_T x_data[], int32_T *x_size,
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

static boolean_T T_lidarScan_removeInvalidData_o(real32_T
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
    TestObstacleControl_B.validRangeLimitIndices_data[b_k] = true;
    TestObstacleControl_B.validAngleLimitIndices_data[b_k] = true;
  }

  TestObstacleControl_B.d.f1[0] = -3.14159274F;
  TestObstacleControl_B.d.f1[1] = 3.14159274F;
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
      TestObstacleControl_B.validRangeLimitIndices_data[b_k] =
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
          TestObstacleControl_B.d.f1[b_k])) {
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
    TestObstacleControl_B.b_z1[0] = TestObstacleControl_floatmod(0.0F);
    TestObstacleControl_B.b_z1[1] = TestObstacleControl_floatmod(6.28318548F);
    for (b_k = 0; b_k < 2; b_k++) {
      b_z1 = TestObstacleControl_B.b_z1[b_k];
      if ((TestObstacleControl_B.b_z1[b_k] == 0.0F) && pos[b_k]) {
        b_z1 = 6.28318548F;
      }

      TestObstacleControl_B.b_z1[b_k] = b_z1;
    }

    TestObstacleControl_B.b_z1[0] -= 3.14159274F;
    TestObstacleControl_B.b_z1[1] -= 3.14159274F;
    TestObstacleControl_sort(TestObstacleControl_B.b_z1,
      TestObstacleControl_B.parsedAngleLimits);
    loop_ub = *objIn_InternalAngles_size;
    for (b_k = 0; b_k < loop_ub; b_k++) {
      TestObstacleControl_B.validAngleLimitIndices_data[b_k] =
        ((objIn_InternalAngles_data[b_k] >=
          TestObstacleControl_B.parsedAngleLimits[0]) &&
         (objIn_InternalAngles_data[b_k] <=
          TestObstacleControl_B.parsedAngleLimits[1]));
    }
  }

  TestObstacleControl_isfinite(objIn_InternalRanges_data,
    objIn_InternalRanges_size, TestObstacleControl_B.tmp_data_m, &tmp_size);
  loop_ub = *objIn_InternalAngles_size;
  for (b_k = 0; b_k < loop_ub; b_k++) {
    TestObstacleControl_B.tmp_data_n[b_k] = rtIsInfF
      (objIn_InternalAngles_data[b_k]);
  }

  for (b_k = 0; b_k < loop_ub; b_k++) {
    TestObstacleControl_B.tmp_data_pp[b_k] = rtIsNaNF
      (objIn_InternalAngles_data[b_k]);
  }

  for (b_k = 0; b_k < tmp_size; b_k++) {
    TestObstacleControl_B.validRangeLimitIndices_data[b_k] =
      (TestObstacleControl_B.tmp_data_m[b_k] &&
       ((!TestObstacleControl_B.tmp_data_n[b_k]) &&
        (!TestObstacleControl_B.tmp_data_pp[b_k])) &&
       TestObstacleControl_B.validRangeLimitIndices_data[b_k] &&
       TestObstacleControl_B.validAngleLimitIndices_data[b_k]);
  }

  p = true;
  b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (b_k + 1 <= tmp_size)) {
    if (!TestObstacleControl_B.validRangeLimitIndices_data[b_k]) {
      p = false;
      exitg1 = true;
    } else {
      b_k++;
    }
  }

  if (!p) {
    for (b_k = 0; b_k < tmp_size; b_k++) {
      TestObstacleControl_B.validAngleLimitIndices_data[b_k] =
        !TestObstacleControl_B.validRangeLimitIndices_data[b_k];
    }

    TestObstacleCo_nullAssignment_o(objIn_InternalRanges_data,
      objIn_InternalRanges_size,
      TestObstacleControl_B.validAngleLimitIndices_data, &tmp_size);
    if (0 <= *objIn_InternalAngles_size - 1) {
      memcpy(&TestObstacleControl_B.tmp_data_cx[0], &objIn_InternalAngles_data[0],
             *objIn_InternalAngles_size * sizeof(real32_T));
    }

    for (b_k = 0; b_k < tmp_size; b_k++) {
      TestObstacleControl_B.validAngleLimitIndices_data[b_k] =
        !TestObstacleControl_B.validRangeLimitIndices_data[b_k];
    }

    TestObstacleCo_nullAssignment_o(TestObstacleControl_B.tmp_data_cx, &loop_ub,
      TestObstacleControl_B.validAngleLimitIndices_data, &tmp_size);
    TestObsta_lidarScan_lidarScan_o(TestObstacleControl_B.tmp_data_cx, &loop_ub,
      objIn_InternalAngles_data, objIn_InternalAngles_size,
      &objOut_ContainsOnlyFiniteData);
    objOut_ContainsOnlyFiniteData = true;
  } else {
    objOut_ContainsOnlyFiniteData = true;
  }

  return objOut_ContainsOnlyFiniteData;
}

static boolean_T TestObstacleControl_isequal(void)
{
  return false;
}

static void TestObstacleControl_asin(const real32_T x_data[], const int32_T
  *x_size, real32_T b_x_data[], int32_T *b_x_size)
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

static void TestObstacleControl_cos(const real32_T x_data[], const int32_T
  *x_size, real32_T b_x_data[], int32_T *b_x_size)
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

static void TestObstacleControl_sin(const real32_T x_data[], const int32_T
  *x_size, real32_T b_x_data[], int32_T *b_x_size)
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

static void TestObstacleControl_cross(const real32_T a_data[], const int32_T
  a_size[2], const real32_T b_data[], real32_T c_data[], int32_T c_size[2])
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

static void TestObstacleControl_repmat(const real32_T a[3], real_T varargin_1,
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

static void TestObstacleControl_sign_o(real32_T x_data[], const int32_T *x_size)
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

static void TestObstacleControl_abs(const real32_T x_data[], const int32_T
  *x_size, real32_T y_data[], int32_T *y_size)
{
  int32_T nx;
  int32_T b_k;
  nx = *x_size - 1;
  *y_size = *x_size;
  for (b_k = 0; b_k <= nx; b_k++) {
    y_data[b_k] = static_cast<real32_T>(fabs(static_cast<real_T>(x_data[b_k])));
  }
}

static void TestObstacleControl_histc(const real32_T X_data[], const int32_T
  *X_size, const real32_T edges[36], real_T N[36], real_T BIN_data[], int32_T
  *BIN_size)
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
  TestObstacleControl_B.sinOfEnlargement_size = *scan_InternalRanges_size;
  TestObstacleControl_B.loop_ub_j = *scan_InternalRanges_size;
  if (0 <= TestObstacleControl_B.loop_ub_j - 1) {
    memcpy(&TestObstacleControl_B.sinOfEnlargement_data[0],
           &scan_InternalRanges_data[0], TestObstacleControl_B.loop_ub_j *
           sizeof(real32_T));
  }

  TestObstacleControl_B.lowerAng_size = *scan_InternalAngles_size;
  TestObstacleControl_B.loop_ub_j = *scan_InternalAngles_size;
  if (0 <= TestObstacleControl_B.loop_ub_j - 1) {
    memcpy(&TestObstacleControl_B.lowerAng_data[0], &scan_InternalAngles_data[0],
           TestObstacleControl_B.loop_ub_j * sizeof(real32_T));
  }

  TestObstacleControl_B.obj[0] = static_cast<real32_T>(obj->DistanceLimits[0]);
  TestObstacleControl_B.obj[1] = static_cast<real32_T>(obj->DistanceLimits[1]);
  T_lidarScan_removeInvalidData_o(TestObstacleControl_B.sinOfEnlargement_data,
    &TestObstacleControl_B.sinOfEnlargement_size,
    TestObstacleControl_B.lowerAng_data, &TestObstacleControl_B.lowerAng_size,
    TestObstacleControl_B.obj);
  TestObstacleControl_B.loop_ub_j = TestObstacleControl_B.sinOfEnlargement_size;
  for (TestObstacleControl_B.e_i = 0; TestObstacleControl_B.e_i <
       TestObstacleControl_B.loop_ub_j; TestObstacleControl_B.e_i++) {
    TestObstacleControl_B.weightedRanges_data[TestObstacleControl_B.e_i] =
      static_cast<real32_T>(obj->DistanceLimits[1]) -
      TestObstacleControl_B.sinOfEnlargement_data[TestObstacleControl_B.e_i];
  }

  if (TestObstacleControl_isequal()) {
    memset(&obj->PolarObstacleDensity[0], 0, 36U * sizeof(real32_T));
  } else {
    TestObstacleControl_B.d_b = obj->RobotRadius + obj->SafetyDistance;
    if (TestObstacleControl_B.d_b == 0.0) {
      TestObstacleControl_histc(TestObstacleControl_B.lowerAng_data,
        &TestObstacleControl_B.lowerAng_size, obj->AngularSectorMidPoints,
        TestObstacleControl_B.unusedU4, TestObstacleControl_B.bin_data,
        &TestObstacleControl_B.sinOfEnlargement_size);
      memset(&TestObstacleControl_B.obstacleDensity[0], 0, 36U * sizeof(real32_T));
      TestObstacleControl_B.end = TestObstacleControl_B.sinOfEnlargement_size -
        1;
      for (TestObstacleControl_B.e_i = 0; TestObstacleControl_B.e_i <=
           TestObstacleControl_B.end; TestObstacleControl_B.e_i++) {
        TestObstacleControl_B.validWeights_size_idx_1 = static_cast<int32_T>
          (TestObstacleControl_B.bin_data[TestObstacleControl_B.e_i]) - 1;
        TestObstacleControl_B.obstacleDensity[TestObstacleControl_B.validWeights_size_idx_1]
          += TestObstacleControl_B.weightedRanges_data[TestObstacleControl_B.e_i];
      }

      memcpy(&obj->PolarObstacleDensity[0],
             &TestObstacleControl_B.obstacleDensity[0], 36U * sizeof(real32_T));
    } else {
      TestObstacleControl_B.loop_ub_j =
        TestObstacleControl_B.sinOfEnlargement_size;
      for (TestObstacleControl_B.e_i = 0; TestObstacleControl_B.e_i <
           TestObstacleControl_B.loop_ub_j; TestObstacleControl_B.e_i++) {
        TestObstacleControl_B.sinOfEnlargement_data[TestObstacleControl_B.e_i] =
          static_cast<real32_T>(TestObstacleControl_B.d_b) /
          TestObstacleControl_B.sinOfEnlargement_data[TestObstacleControl_B.e_i];
      }

      TestObstacleControl_B.end = TestObstacleControl_B.sinOfEnlargement_size -
        1;
      for (TestObstacleControl_B.e_i = 0; TestObstacleControl_B.e_i <=
           TestObstacleControl_B.end; TestObstacleControl_B.e_i++) {
        TestObstacleControl_B.sinOfEnlargement_data_e =
          TestObstacleControl_B.sinOfEnlargement_data[TestObstacleControl_B.e_i];
        if (TestObstacleControl_B.sinOfEnlargement_data[TestObstacleControl_B.e_i]
            >= 1.0F) {
          TestObstacleControl_B.sinOfEnlargement_data_e = 0.999999881F;
        }

        TestObstacleControl_B.sinOfEnlargement_data[TestObstacleControl_B.e_i] =
          TestObstacleControl_B.sinOfEnlargement_data_e;
      }

      TestObstacleControl_asin(TestObstacleControl_B.sinOfEnlargement_data,
        &TestObstacleControl_B.sinOfEnlargement_size,
        TestObstacleControl_B.enlargementAngle_data,
        &TestObstacleControl_B.enlargementAngle_size);
      TestObstacleControl_B.sinOfEnlargement_size =
        TestObstacleControl_B.lowerAng_size;
      TestObstacleControl_B.loop_ub_j = TestObstacleControl_B.lowerAng_size;
      for (TestObstacleControl_B.e_i = 0; TestObstacleControl_B.e_i <
           TestObstacleControl_B.loop_ub_j; TestObstacleControl_B.e_i++) {
        TestObstacleControl_B.sinOfEnlargement_data[TestObstacleControl_B.e_i] =
          TestObstacleControl_B.lowerAng_data[TestObstacleControl_B.e_i] +
          TestObstacleControl_B.enlargementAngle_data[TestObstacleControl_B.e_i];
      }

      TestObstacleControl_B.loop_ub_j = TestObstacleControl_B.lowerAng_size;
      for (TestObstacleControl_B.e_i = 0; TestObstacleControl_B.e_i <
           TestObstacleControl_B.loop_ub_j; TestObstacleControl_B.e_i++) {
        TestObstacleControl_B.lowerAng_data[TestObstacleControl_B.e_i] -=
          TestObstacleControl_B.enlargementAngle_data[TestObstacleControl_B.e_i];
      }

      TestObstacleControl_cos(TestObstacleControl_B.lowerAng_data,
        &TestObstacleControl_B.lowerAng_size, TestObstacleControl_B.tmp_data_c,
        &TestObstacleControl_B.tmp_size_a);
      TestObstacleControl_sin(TestObstacleControl_B.lowerAng_data,
        &TestObstacleControl_B.lowerAng_size, TestObstacleControl_B.tmp_data_k,
        &TestObstacleControl_B.enlargementAngle_size);
      TestObstacleControl_B.lowerVec_size[0] = TestObstacleControl_B.tmp_size_a;
      TestObstacleControl_B.lowerVec_size[1] = 3;
      TestObstacleControl_B.loop_ub_j = TestObstacleControl_B.tmp_size_a;
      if (0 <= TestObstacleControl_B.loop_ub_j - 1) {
        memcpy(&TestObstacleControl_B.lowerVec_data[0],
               &TestObstacleControl_B.tmp_data_c[0],
               TestObstacleControl_B.loop_ub_j * sizeof(real32_T));
      }

      TestObstacleControl_B.loop_ub_j =
        TestObstacleControl_B.enlargementAngle_size;
      for (TestObstacleControl_B.e_i = 0; TestObstacleControl_B.e_i <
           TestObstacleControl_B.loop_ub_j; TestObstacleControl_B.e_i++) {
        TestObstacleControl_B.lowerVec_data[TestObstacleControl_B.e_i +
          TestObstacleControl_B.tmp_size_a] =
          TestObstacleControl_B.tmp_data_k[TestObstacleControl_B.e_i];
      }

      TestObstacleControl_B.loop_ub_j = TestObstacleControl_B.lowerAng_size;
      if (0 <= TestObstacleControl_B.loop_ub_j - 1) {
        memset
          (&TestObstacleControl_B.lowerVec_data[TestObstacleControl_B.tmp_size_a
           + TestObstacleControl_B.enlargementAngle_size], 0,
           ((((TestObstacleControl_B.loop_ub_j +
               TestObstacleControl_B.tmp_size_a) +
              TestObstacleControl_B.enlargementAngle_size) -
             TestObstacleControl_B.tmp_size_a) -
            TestObstacleControl_B.enlargementAngle_size) * sizeof(real32_T));
      }

      TestObstacleControl_cos(TestObstacleControl_B.sinOfEnlargement_data,
        &TestObstacleControl_B.sinOfEnlargement_size,
        TestObstacleControl_B.tmp_data_c, &TestObstacleControl_B.tmp_size_a);
      TestObstacleControl_sin(TestObstacleControl_B.sinOfEnlargement_data,
        &TestObstacleControl_B.sinOfEnlargement_size,
        TestObstacleControl_B.tmp_data_k,
        &TestObstacleControl_B.enlargementAngle_size);
      TestObstacleControl_B.loop_ub_j = TestObstacleControl_B.tmp_size_a;
      if (0 <= TestObstacleControl_B.loop_ub_j - 1) {
        memcpy(&TestObstacleControl_B.higherVec_data[0],
               &TestObstacleControl_B.tmp_data_c[0],
               TestObstacleControl_B.loop_ub_j * sizeof(real32_T));
      }

      TestObstacleControl_B.loop_ub_j =
        TestObstacleControl_B.enlargementAngle_size;
      for (TestObstacleControl_B.e_i = 0; TestObstacleControl_B.e_i <
           TestObstacleControl_B.loop_ub_j; TestObstacleControl_B.e_i++) {
        TestObstacleControl_B.higherVec_data[TestObstacleControl_B.e_i +
          TestObstacleControl_B.tmp_size_a] =
          TestObstacleControl_B.tmp_data_k[TestObstacleControl_B.e_i];
      }

      TestObstacleControl_B.loop_ub_j = TestObstacleControl_B.lowerAng_size;
      if (0 <= TestObstacleControl_B.loop_ub_j - 1) {
        memset
          (&TestObstacleControl_B.higherVec_data[TestObstacleControl_B.tmp_size_a
           + TestObstacleControl_B.enlargementAngle_size], 0,
           ((((TestObstacleControl_B.loop_ub_j +
               TestObstacleControl_B.tmp_size_a) +
              TestObstacleControl_B.enlargementAngle_size) -
             TestObstacleControl_B.tmp_size_a) -
            TestObstacleControl_B.enlargementAngle_size) * sizeof(real32_T));
      }

      TestObstacleControl_B.validWeights_size_idx_1 =
        TestObstacleControl_B.lowerVec_size[0];
      TestObstacleControl_B.loop_ub_j = 36 *
        TestObstacleControl_B.lowerVec_size[0] - 1;
      for (TestObstacleControl_B.e_i = 0; TestObstacleControl_B.e_i <=
           TestObstacleControl_B.loop_ub_j; TestObstacleControl_B.e_i++) {
        TestObstacleControl_B.validWeights_data[TestObstacleControl_B.e_i] =
          true;
      }

      TestObstacleControl_cross(TestObstacleControl_B.lowerVec_data,
        TestObstacleControl_B.lowerVec_size,
        TestObstacleControl_B.higherVec_data, TestObstacleControl_B.lh_data,
        TestObstacleControl_B.lh_size);
      for (TestObstacleControl_B.e_i = 0; TestObstacleControl_B.e_i < 36;
           TestObstacleControl_B.e_i++) {
        TestObstacleControl_B.kalpha[TestObstacleControl_B.e_i] =
          static_cast<real32_T>(cos(static_cast<real_T>
          (obj->AngularSectorMidPoints[TestObstacleControl_B.e_i])));
        TestObstacleControl_B.kalpha[TestObstacleControl_B.e_i + 36] =
          static_cast<real32_T>(sin(static_cast<real_T>
          (obj->AngularSectorMidPoints[TestObstacleControl_B.e_i])));
        TestObstacleControl_B.kalpha[TestObstacleControl_B.e_i + 72] = 0.0F;
      }

      TestObstacleControl_B.loop_ub_j = TestObstacleControl_B.lh_size[0];
      for (TestObstacleControl_B.end = 0; TestObstacleControl_B.end < 36;
           TestObstacleControl_B.end++) {
        TestObstacleControl_B.kalpha_o[0] =
          TestObstacleControl_B.kalpha[TestObstacleControl_B.end];
        TestObstacleControl_B.kalpha_o[1] =
          TestObstacleControl_B.kalpha[TestObstacleControl_B.end + 36];
        TestObstacleControl_B.kalpha_o[2] =
          TestObstacleControl_B.kalpha[TestObstacleControl_B.end + 72];
        TestObstacleControl_repmat(TestObstacleControl_B.kalpha_o,
          static_cast<real_T>(TestObstacleControl_B.lowerVec_size[0]),
          TestObstacleControl_B.kalphaVec_data,
          TestObstacleControl_B.kalphaVec_size);
        TestObstacleControl_cross(TestObstacleControl_B.lowerVec_data,
          TestObstacleControl_B.lowerVec_size,
          TestObstacleControl_B.kalphaVec_data, TestObstacleControl_B.lk_data,
          TestObstacleControl_B.lk_size);
        TestObstacleControl_cross(TestObstacleControl_B.kalphaVec_data,
          TestObstacleControl_B.kalphaVec_size,
          TestObstacleControl_B.higherVec_data, TestObstacleControl_B.kh_data,
          TestObstacleControl_B.kh_size);
        TestObstacleControl_B.loop_ub_f = TestObstacleControl_B.lk_size[0];
        TestObstacleControl_B.tmp_size_a = TestObstacleControl_B.lk_size[0];
        for (TestObstacleControl_B.e_i = 0; TestObstacleControl_B.e_i <
             TestObstacleControl_B.loop_ub_f; TestObstacleControl_B.e_i++) {
          TestObstacleControl_B.tmp_data_c[TestObstacleControl_B.e_i] =
            TestObstacleControl_B.lk_data[(TestObstacleControl_B.lk_size[0] << 1)
            + TestObstacleControl_B.e_i];
        }

        TestObstacleControl_sign_o(TestObstacleControl_B.tmp_data_c,
          &TestObstacleControl_B.tmp_size_a);
        TestObstacleControl_B.loop_ub_f = TestObstacleControl_B.kh_size[0];
        TestObstacleControl_B.enlargementAngle_size =
          TestObstacleControl_B.kh_size[0];
        for (TestObstacleControl_B.e_i = 0; TestObstacleControl_B.e_i <
             TestObstacleControl_B.loop_ub_f; TestObstacleControl_B.e_i++) {
          TestObstacleControl_B.tmp_data_k[TestObstacleControl_B.e_i] =
            TestObstacleControl_B.kh_data[(TestObstacleControl_B.kh_size[0] << 1)
            + TestObstacleControl_B.e_i];
        }

        TestObstacleControl_sign_o(TestObstacleControl_B.tmp_data_k,
          &TestObstacleControl_B.enlargementAngle_size);
        TestObstacleControl_B.enlargementAngle_size =
          TestObstacleControl_B.lh_size[0];
        for (TestObstacleControl_B.e_i = 0; TestObstacleControl_B.e_i <
             TestObstacleControl_B.loop_ub_j; TestObstacleControl_B.e_i++) {
          TestObstacleControl_B.enlargementAngle_data[TestObstacleControl_B.e_i]
            = TestObstacleControl_B.lh_data[(TestObstacleControl_B.lh_size[0] <<
            1) + TestObstacleControl_B.e_i];
        }

        TestObstacleControl_sign_o(TestObstacleControl_B.enlargementAngle_data,
          &TestObstacleControl_B.enlargementAngle_size);
        TestObstacleControl_B.enlargementAngle_size =
          TestObstacleControl_B.tmp_size_a;
        TestObstacleControl_B.loop_ub_f = TestObstacleControl_B.tmp_size_a;
        for (TestObstacleControl_B.e_i = 0; TestObstacleControl_B.e_i <
             TestObstacleControl_B.loop_ub_f; TestObstacleControl_B.e_i++) {
          TestObstacleControl_B.sinOfEnlargement_data[TestObstacleControl_B.e_i]
            = (TestObstacleControl_B.tmp_data_c[TestObstacleControl_B.e_i] +
               TestObstacleControl_B.tmp_data_k[TestObstacleControl_B.e_i]) +
            TestObstacleControl_B.enlargementAngle_data[TestObstacleControl_B.e_i];
        }

        TestObstacleControl_abs(TestObstacleControl_B.sinOfEnlargement_data,
          &TestObstacleControl_B.enlargementAngle_size,
          TestObstacleControl_B.tmp_data_c, &TestObstacleControl_B.tmp_size_a);
        for (TestObstacleControl_B.e_i = 0; TestObstacleControl_B.e_i <
             TestObstacleControl_B.validWeights_size_idx_1;
             TestObstacleControl_B.e_i++) {
          TestObstacleControl_B.validWeights_data[TestObstacleControl_B.end + 36
            * TestObstacleControl_B.e_i] =
            (TestObstacleControl_B.tmp_data_c[TestObstacleControl_B.e_i] > 1.0F);
        }
      }

      for (TestObstacleControl_B.e_i = 0; TestObstacleControl_B.e_i < 36;
           TestObstacleControl_B.e_i++) {
        obj->PolarObstacleDensity[TestObstacleControl_B.e_i] = 0.0F;
        for (TestObstacleControl_B.end = 0; TestObstacleControl_B.end <
             TestObstacleControl_B.validWeights_size_idx_1;
             TestObstacleControl_B.end++) {
          obj->PolarObstacleDensity[TestObstacleControl_B.e_i] +=
            static_cast<real32_T>(TestObstacleControl_B.validWeights_data[36 *
            TestObstacleControl_B.end + TestObstacleControl_B.e_i]) *
            TestObstacleControl_B.weightedRanges_data[TestObstacleControl_B.end];
        }
      }
    }
  }
}

static void TestObstacleControl_power(const real32_T a_data[], const int32_T
  *a_size, real32_T y_data[], int32_T *y_size)
{
  int32_T nx;
  int32_T b_k;
  *y_size = *a_size;
  nx = *a_size - 1;
  for (b_k = 0; b_k <= nx; b_k++) {
    y_data[b_k] = a_data[b_k] * a_data[b_k];
  }
}

static void TestObstacleControl_sqrt_o(real32_T x_data[], const int32_T *x_size)
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
  TestObstacleControl_B.validScan_InternalRanges_size =
    *scan_InternalRanges_size;
  TestObstacleControl_B.idx_o = *scan_InternalRanges_size;
  if (0 <= TestObstacleControl_B.idx_o - 1) {
    memcpy(&TestObstacleControl_B.validScan_InternalRanges_data[0],
           &scan_InternalRanges_data[0], TestObstacleControl_B.idx_o * sizeof
           (real32_T));
  }

  TestObstacleControl_B.ii_data_j = *scan_InternalAngles_size;
  TestObstacleControl_B.idx_o = *scan_InternalAngles_size;
  if (0 <= TestObstacleControl_B.idx_o - 1) {
    memcpy(&TestObstacleControl_B.validScan_InternalAngles_data[0],
           &scan_InternalAngles_data[0], TestObstacleControl_B.idx_o * sizeof
           (real32_T));
  }

  TestObstacleControl_B.obj_b[0] = static_cast<real32_T>(obj->DistanceLimits[0]);
  TestObstacleControl_B.obj_b[1] = static_cast<real32_T>(obj->DistanceLimits[1]);
  T_lidarScan_removeInvalidData_o
    (TestObstacleControl_B.validScan_InternalRanges_data,
     &TestObstacleControl_B.validScan_InternalRanges_size,
     TestObstacleControl_B.validScan_InternalAngles_data,
     &TestObstacleControl_B.ii_data_j, TestObstacleControl_B.obj_b);
  TestObstacleControl_sin(TestObstacleControl_B.validScan_InternalAngles_data,
    &TestObstacleControl_B.ii_data_j, TestObstacleControl_B.DYj_data,
    &TestObstacleControl_B.DYj_size);
  TestObstacleControl_B.DYj_size =
    TestObstacleControl_B.validScan_InternalRanges_size;
  TestObstacleControl_B.idx_o =
    TestObstacleControl_B.validScan_InternalRanges_size;
  for (TestObstacleControl_B.k = 0; TestObstacleControl_B.k <
       TestObstacleControl_B.idx_o; TestObstacleControl_B.k++) {
    TestObstacleControl_B.DYj_data[TestObstacleControl_B.k] *=
      TestObstacleControl_B.validScan_InternalRanges_data[TestObstacleControl_B.k];
  }

  TestObstacleControl_cos(TestObstacleControl_B.validScan_InternalAngles_data,
    &TestObstacleControl_B.ii_data_j, TestObstacleControl_B.tmp_data_b,
    &TestObstacleControl_B.tmp_size_n);
  TestObstacleControl_B.tmp_size_i =
    TestObstacleControl_B.validScan_InternalRanges_size;
  TestObstacleControl_B.idx_o =
    TestObstacleControl_B.validScan_InternalRanges_size;
  for (TestObstacleControl_B.k = 0; TestObstacleControl_B.k <
       TestObstacleControl_B.idx_o; TestObstacleControl_B.k++) {
    TestObstacleControl_B.tmp_data_p[TestObstacleControl_B.k] = 0.0F -
      TestObstacleControl_B.validScan_InternalRanges_data[TestObstacleControl_B.k]
      * TestObstacleControl_B.tmp_data_b[TestObstacleControl_B.k];
  }

  TestObstacleControl_power(TestObstacleControl_B.tmp_data_p,
    &TestObstacleControl_B.tmp_size_i,
    TestObstacleControl_B.validScan_InternalRanges_data,
    &TestObstacleControl_B.validScan_InternalRanges_size);
  TestObstacleControl_B.obj_size_o = TestObstacleControl_B.DYj_size;
  TestObstacleControl_B.idx_o = TestObstacleControl_B.DYj_size;
  for (TestObstacleControl_B.k = 0; TestObstacleControl_B.k <
       TestObstacleControl_B.idx_o; TestObstacleControl_B.k++) {
    TestObstacleControl_B.tmp_data_p[TestObstacleControl_B.k] =
      static_cast<real32_T>(-obj->MinTurningRadius) -
      TestObstacleControl_B.DYj_data[TestObstacleControl_B.k];
  }

  TestObstacleControl_power(TestObstacleControl_B.tmp_data_p,
    &TestObstacleControl_B.obj_size_o, TestObstacleControl_B.tmp_data_b,
    &TestObstacleControl_B.tmp_size_n);
  TestObstacleControl_B.tmp_size_n =
    TestObstacleControl_B.validScan_InternalRanges_size;
  TestObstacleControl_B.idx_o =
    TestObstacleControl_B.validScan_InternalRanges_size;
  for (TestObstacleControl_B.k = 0; TestObstacleControl_B.k <
       TestObstacleControl_B.idx_o; TestObstacleControl_B.k++) {
    TestObstacleControl_B.tmp_data_b[TestObstacleControl_B.k] +=
      TestObstacleControl_B.validScan_InternalRanges_data[TestObstacleControl_B.k];
  }

  TestObstacleControl_sqrt_o(TestObstacleControl_B.tmp_data_b,
    &TestObstacleControl_B.tmp_size_n);
  TestObstacleControl_B.obj_tmp = (obj->MinTurningRadius + obj->RobotRadius) +
    obj->SafetyDistance;
  TestObstacleControl_B.k_j = TestObstacleControl_B.tmp_size_n;
  TestObstacleControl_B.idx_o = TestObstacleControl_B.tmp_size_n;
  for (TestObstacleControl_B.k = 0; TestObstacleControl_B.k <
       TestObstacleControl_B.idx_o; TestObstacleControl_B.k++) {
    TestObstacleControl_B.blockedR_data[TestObstacleControl_B.k] =
      ((TestObstacleControl_B.tmp_data_b[TestObstacleControl_B.k] <
        TestObstacleControl_B.obj_tmp) &&
       (TestObstacleControl_B.validScan_InternalAngles_data[TestObstacleControl_B.k]
        <= 0.0F));
  }

  TestObstacleControl_B.obj_size_n = TestObstacleControl_B.DYj_size;
  TestObstacleControl_B.idx_o = TestObstacleControl_B.DYj_size;
  for (TestObstacleControl_B.k = 0; TestObstacleControl_B.k <
       TestObstacleControl_B.idx_o; TestObstacleControl_B.k++) {
    TestObstacleControl_B.tmp_data_p[TestObstacleControl_B.k] =
      static_cast<real32_T>(obj->MinTurningRadius) -
      TestObstacleControl_B.DYj_data[TestObstacleControl_B.k];
  }

  TestObstacleControl_power(TestObstacleControl_B.tmp_data_p,
    &TestObstacleControl_B.obj_size_n, TestObstacleControl_B.tmp_data_b,
    &TestObstacleControl_B.tmp_size_n);
  TestObstacleControl_B.idx_o =
    TestObstacleControl_B.validScan_InternalRanges_size;
  for (TestObstacleControl_B.k = 0; TestObstacleControl_B.k <
       TestObstacleControl_B.idx_o; TestObstacleControl_B.k++) {
    TestObstacleControl_B.validScan_InternalRanges_data[TestObstacleControl_B.k]
      += TestObstacleControl_B.tmp_data_b[TestObstacleControl_B.k];
  }

  TestObstacleControl_sqrt_o(TestObstacleControl_B.validScan_InternalRanges_data,
    &TestObstacleControl_B.validScan_InternalRanges_size);
  TestObstacleControl_B.idx_o =
    TestObstacleControl_B.validScan_InternalRanges_size;
  for (TestObstacleControl_B.k = 0; TestObstacleControl_B.k <
       TestObstacleControl_B.idx_o; TestObstacleControl_B.k++) {
    TestObstacleControl_B.blockedL_data[TestObstacleControl_B.k] =
      ((TestObstacleControl_B.validScan_InternalRanges_data[TestObstacleControl_B.k]
        < TestObstacleControl_B.obj_tmp) &&
       (TestObstacleControl_B.validScan_InternalAngles_data[TestObstacleControl_B.k]
        >= 0.0F));
  }

  TestObstacleControl_B.k = (1 <= TestObstacleControl_B.k_j);
  TestObstacleControl_B.idx_o = 0;
  exitg1 = false;
  while ((!exitg1) && (TestObstacleControl_B.k_j > 0)) {
    if (TestObstacleControl_B.blockedR_data[TestObstacleControl_B.k_j - 1]) {
      TestObstacleControl_B.idx_o = 1;
      TestObstacleControl_B.ii_data_j = TestObstacleControl_B.k_j;
      exitg1 = true;
    } else {
      TestObstacleControl_B.k_j--;
    }
  }

  if (TestObstacleControl_B.k == 1) {
    if (TestObstacleControl_B.idx_o == 0) {
      TestObstacleControl_B.k = 0;
    }
  } else {
    TestObstacleControl_B.k = (1 <= TestObstacleControl_B.idx_o);
  }

  if (0 <= TestObstacleControl_B.k - 1) {
    TestObstacleControl_B.phiR_data =
      TestObstacleControl_B.validScan_InternalAngles_data[TestObstacleControl_B.ii_data_j
      - 1];
  }

  TestObstacleControl_B.k_j = (1 <=
    TestObstacleControl_B.validScan_InternalRanges_size);
  TestObstacleControl_B.idx_o = 0;
  TestObstacleControl_B.b_ii = 1;
  exitg1 = false;
  while ((!exitg1) && (TestObstacleControl_B.b_ii - 1 <=
                       TestObstacleControl_B.validScan_InternalRanges_size - 1))
  {
    if (TestObstacleControl_B.blockedL_data[TestObstacleControl_B.b_ii - 1]) {
      TestObstacleControl_B.idx_o = 1;
      TestObstacleControl_B.ii_data_j = TestObstacleControl_B.b_ii;
      exitg1 = true;
    } else {
      TestObstacleControl_B.b_ii++;
    }
  }

  if (TestObstacleControl_B.k_j == 1) {
    if (TestObstacleControl_B.idx_o == 0) {
      TestObstacleControl_B.k_j = 0;
    }
  } else {
    TestObstacleControl_B.k_j = (1 <= TestObstacleControl_B.idx_o);
  }

  if (0 <= TestObstacleControl_B.k_j - 1) {
    TestObstacleControl_B.phiL_data =
      TestObstacleControl_B.validScan_InternalAngles_data[TestObstacleControl_B.ii_data_j
      - 1];
  }

  if (TestObstacleControl_B.k == 0) {
    TestObstacleControl_B.phiR_data = obj->AngularSectorMidPoints[0];
  } else {
    if (TestObstacleControl_B.phiR_data <= obj->AngularSectorMidPoints[0]) {
      TestObstacleControl_B.phiR_data = obj->AngularSectorMidPoints[1];
    }
  }

  if (TestObstacleControl_B.k_j == 0) {
    TestObstacleControl_B.phiL_data = obj->AngularSectorMidPoints[35];
  } else {
    if (TestObstacleControl_B.phiL_data >= obj->AngularSectorMidPoints[35]) {
      TestObstacleControl_B.phiL_data = obj->AngularSectorMidPoints[34];
    }
  }

  for (TestObstacleControl_B.k = 0; TestObstacleControl_B.k < 36;
       TestObstacleControl_B.k++) {
    obj->MaskedHistogram[TestObstacleControl_B.k] = (obj->
      BinaryHistogram[TestObstacleControl_B.k] || ((obj->
      AngularSectorMidPoints[TestObstacleControl_B.k] <
      TestObstacleControl_B.phiR_data) || (obj->
      AngularSectorMidPoints[TestObstacleControl_B.k] >
      TestObstacleControl_B.phiL_data)));
  }
}

static void TestObstacleControl_diff(const real_T x[38], real_T y[37])
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

static boolean_T TestObstacleControl_any(const real32_T x[37])
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

static void TestObstacleControl_diff_o(const real32_T x_data[], const int32_T
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
      TestObstacleControl_B.b_y1_data[iyStart] = x_data[ixStart + 1] -
        x_data[ixStart];
      ixStart += 2;
      iyStart++;
    }
  }

  y_size[0] = 1;
  y_size[1] = x_size[1];
  r = x_size[1] - 1;
  if (0 <= r) {
    memcpy(&y_data[0], &TestObstacleControl_B.b_y1_data[0], (r + 1) * sizeof
           (real32_T));
  }
}

static void TestObstacleControl_wrapToPi_ov(const real32_T theta_data[], const
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
    TestObstacleControl_B.y_data_g[b_k] = static_cast<real32_T>(fabs(
      static_cast<real_T>(theta_data[b_k])));
  }

  nx = theta_size[1] - 1;
  for (b_k = 0; b_k <= nx; b_k++) {
    TestObstacleControl_B.pos_data_g[b_k] = (TestObstacleControl_B.y_data_g[b_k]
      > 3.1415926535897931);
  }

  y = false;
  b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (b_k + 1 <= theta_size[1])) {
    if (!TestObstacleControl_B.pos_data_g[b_k]) {
      b_k++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  if (y) {
    for (b_k = 0; b_k <= loop_ub_tmp; b_k++) {
      TestObstacleControl_B.y_data_g[b_k] = theta_data[b_k] + 3.14159274F;
    }

    nx = theta_size[1] - 1;
    for (b_k = 0; b_k <= nx; b_k++) {
      TestObstacleControl_B.pos_data_g[b_k] =
        (TestObstacleControl_B.y_data_g[b_k] > 0.0F);
    }

    nx = theta_size[1] - 1;
    if (0 <= nx) {
      memcpy(&TestObstacleControl_B.b_z1_data[0],
             &TestObstacleControl_B.y_data_g[0], (nx + 1) * sizeof(real32_T));
    }

    nx = theta_size[1] - 1;
    for (b_k = 0; b_k <= nx; b_k++) {
      TestObstacleControl_B.b_z1_data[b_k] = TestObstacleControl_floatmod
        (TestObstacleControl_B.y_data_g[b_k]);
    }

    nx = theta_size[1] - 1;
    if (0 <= nx) {
      memcpy(&TestObstacleControl_B.y_data_g[0],
             &TestObstacleControl_B.b_z1_data[0], (nx + 1) * sizeof(real32_T));
    }

    nx = theta_size[1] - 1;
    for (b_k = 0; b_k <= nx; b_k++) {
      TestObstacleControl_B.b_data_l[b_k] = (TestObstacleControl_B.b_z1_data[b_k]
        == 0.0F);
    }

    b_k = theta_size[1] - 1;
    for (loop_ub_tmp = 0; loop_ub_tmp <= b_k; loop_ub_tmp++) {
      if (TestObstacleControl_B.b_data_l[loop_ub_tmp] &&
          TestObstacleControl_B.pos_data_g[loop_ub_tmp]) {
        TestObstacleControl_B.y_data_g[loop_ub_tmp] = 6.28318548F;
      }
    }

    b_theta_size[0] = 1;
    b_theta_size[1] = theta_size[1];
    nx = theta_size[1] - 1;
    for (b_k = 0; b_k <= nx; b_k++) {
      b_theta_data[b_k] = TestObstacleControl_B.y_data_g[b_k] - 3.14159274F;
    }
  }
}

static void TestObstacleContro_bisectAngles(real32_T theta1_data[], int32_T
  theta1_size[2], real32_T theta2_data[], const int32_T theta2_size[2], real32_T
  bisect_data[], int32_T bisect_size[2])
{
  int32_T theta1_size_0[2];
  int32_T loop_ub_tmp;
  int32_T loop_ub;
  TestObstacleControl_wrapToPi_ov(theta1_data, theta1_size,
    TestObstacleControl_B.tmp_data_g, TestObstacleControl_B.tmp_size_b);
  theta1_size[1] = TestObstacleControl_B.tmp_size_b[1];
  loop_ub_tmp = TestObstacleControl_B.tmp_size_b[0] *
    TestObstacleControl_B.tmp_size_b[1];
  if (0 <= loop_ub_tmp - 1) {
    memcpy(&theta1_data[0], &TestObstacleControl_B.tmp_data_g[0], loop_ub_tmp *
           sizeof(real32_T));
  }

  TestObstacleControl_wrapToPi_ov(theta2_data, theta2_size,
    TestObstacleControl_B.tmp_data_g, TestObstacleControl_B.tmp_size_b);
  loop_ub = TestObstacleControl_B.tmp_size_b[0] *
    TestObstacleControl_B.tmp_size_b[1];
  if (0 <= loop_ub - 1) {
    memcpy(&theta2_data[0], &TestObstacleControl_B.tmp_data_g[0], loop_ub *
           sizeof(real32_T));
  }

  theta1_size_0[0] = 1;
  theta1_size_0[1] = theta1_size[1];
  loop_ub = theta1_size[1];
  for (loop_ub_tmp = 0; loop_ub_tmp < loop_ub; loop_ub_tmp++) {
    TestObstacleControl_B.theta1_data[loop_ub_tmp] = theta1_data[loop_ub_tmp] -
      (theta1_data[loop_ub_tmp] - theta2_data[loop_ub_tmp]) / 2.0F;
  }

  TestObstacleControl_wrapToPi_ov(TestObstacleControl_B.theta1_data,
    theta1_size_0, TestObstacleControl_B.tmp_data_g,
    TestObstacleControl_B.tmp_size_b);
  bisect_size[0] = 1;
  bisect_size[1] = TestObstacleControl_B.tmp_size_b[1];
  loop_ub = TestObstacleControl_B.tmp_size_b[0] *
    TestObstacleControl_B.tmp_size_b[1];
  if (0 <= loop_ub - 1) {
    memcpy(&bisect_data[0], &TestObstacleControl_B.tmp_data_g[0], loop_ub *
           sizeof(real32_T));
  }
}

static void TestObstacleControl_bsxfun(const real32_T a[36], const real32_T
  b_data[], const int32_T *b_size, real32_T c_data[], int32_T c_size[2])
{
  int32_T k;
  int32_T k_0;
  int32_T csz_idx_0;
  csz_idx_0 = *b_size;
  c_size[0] = *b_size;
  c_size[1] = 36;
  for (k = 0; k < 36; k++) {
    for (k_0 = 0; k_0 < csz_idx_0; k_0++) {
      c_data[k_0 + *b_size * k] = TestObstacleControl_wrapToPi_o(b_data[k_0] -
        a[k]);
    }
  }
}

static void TestObstacleControl_abs_o(const real32_T x_data[], const int32_T
  x_size[2], real32_T y_data[], int32_T y_size[2])
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

static void TestObstacleControl_bsxfun_o(const real32_T a_data[], const int32_T
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

static boolean_T TestObstacleControl_any_o(const boolean_T x_data[], const
  int32_T x_size[2])
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
  TestObstacleControl_B.targetDir_size[0] = 1;
  TestObstacleControl_B.targetDir_size[1] = c_size[1];
  for (b_k = 0; b_k < nx; b_k++) {
    TestObstacleControl_B.cost_data[b_k] = targetDir - c_data[b_k];
  }

  TestObstacleControl_wrapToPi_ov(TestObstacleControl_B.cost_data,
    TestObstacleControl_B.targetDir_size, TestObstacleControl_B.delta_data,
    TestObstacleControl_B.delta_size);
  nx = TestObstacleControl_B.delta_size[1] - 1;
  cost_size_idx_1 = TestObstacleControl_B.delta_size[1];
  for (b_k = 0; b_k <= nx; b_k++) {
    TestObstacleControl_B.cost_data[b_k] = static_cast<real32_T>(fabs(
      static_cast<real_T>(TestObstacleControl_B.delta_data[b_k])));
  }

  nx = c_size[1];
  TestObstacleControl_B.tmp_size[0] = 1;
  TestObstacleControl_B.tmp_size[1] = c_size[1];
  for (b_k = 0; b_k < nx; b_k++) {
    TestObstacleControl_B.cost_data_c[b_k] = 0.0F - c_data[b_k];
  }

  TestObstacleControl_wrapToPi_ov(TestObstacleControl_B.cost_data_c,
    TestObstacleControl_B.tmp_size, TestObstacleControl_B.delta_data,
    TestObstacleControl_B.delta_size);
  nx = TestObstacleControl_B.delta_size[1] - 1;
  for (b_k = 0; b_k <= nx; b_k++) {
    TestObstacleControl_B.cost_data_c[b_k] = static_cast<real32_T>(fabs(
      static_cast<real_T>(TestObstacleControl_B.delta_data[b_k])));
  }

  nx = c_size[1];
  TestObstacleControl_B.prevDir_size[0] = 1;
  TestObstacleControl_B.prevDir_size[1] = c_size[1];
  for (b_k = 0; b_k < nx; b_k++) {
    TestObstacleControl_B.cost_data_f[b_k] = prevDir - c_data[b_k];
  }

  TestObstacleControl_wrapToPi_ov(TestObstacleControl_B.cost_data_f,
    TestObstacleControl_B.prevDir_size, TestObstacleControl_B.delta_data,
    TestObstacleControl_B.delta_size);
  nx = TestObstacleControl_B.delta_size[1] - 1;
  for (b_k = 0; b_k <= nx; b_k++) {
    TestObstacleControl_B.cost_data_f[b_k] = static_cast<real32_T>(fabs(
      static_cast<real_T>(TestObstacleControl_B.delta_data[b_k])));
  }

  cost_size[0] = 1;
  cost_size[1] = cost_size_idx_1;
  cost_size_idx_1--;
  for (b_k = 0; b_k <= cost_size_idx_1; b_k++) {
    cost_data[b_k] = ((static_cast<real32_T>(obj->TargetDirectionWeight) *
                       TestObstacleControl_B.cost_data[b_k] +
                       static_cast<real32_T>(obj->CurrentDirectionWeight) *
                       TestObstacleControl_B.cost_data_c[b_k]) +
                      static_cast<real32_T>(obj->PreviousDirectionWeight) *
                      TestObstacleControl_B.cost_data_f[b_k]) / 3.0F *
      totalWeight;
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
  TestObstacleControl_B.dv[0] = 0.0;
  for (n = 0; n < 36; n++) {
    TestObstacleControl_B.dv[n + 1] = !obj->MaskedHistogram[n];
  }

  TestObstacleControl_B.dv[37] = 0.0;
  TestObstacleControl_diff(TestObstacleControl_B.dv, TestObstacleControl_B.dv1);
  for (n = 0; n < 37; n++) {
    TestObstacleControl_B.changes[n] = static_cast<real32_T>
      (TestObstacleControl_B.dv1[n]);
  }

  if (!TestObstacleControl_any(TestObstacleControl_B.changes)) {
    thetaSteer = (rtNaNF);
    obj->PreviousDirection = (rtNaNF);
  } else {
    TestObstacleControl_B.idx = 0;
    n = 1;
    exitg1 = false;
    while ((!exitg1) && (n - 1 < 37)) {
      if (TestObstacleControl_B.changes[n - 1] != 0.0F) {
        TestObstacleControl_B.idx++;
        TestObstacleControl_B.ii_data[TestObstacleControl_B.idx - 1] = n;
        if (TestObstacleControl_B.idx >= 37) {
          exitg1 = true;
        } else {
          n++;
        }
      } else {
        n++;
      }
    }

    if (1 > TestObstacleControl_B.idx) {
      TestObstacleControl_B.idx = 0;
    }

    loop_ub = TestObstacleControl_B.idx - 1;
    for (n = 0; n <= loop_ub; n++) {
      TestObstacleControl_B.changes[n] = static_cast<real32_T>
        (TestObstacleControl_B.ii_data[n]);
    }

    TestObstacleControl_B.sectors_size[0] = 2;
    TestObstacleControl_B.idx >>= 1;
    TestObstacleControl_B.sectors_size[1] = TestObstacleControl_B.idx;
    loop_ub = (TestObstacleControl_B.idx << 1) - 1;
    if (0 <= loop_ub) {
      memcpy(&TestObstacleControl_B.sectors_data[0],
             &TestObstacleControl_B.changes[0], (loop_ub + 1) * sizeof(real32_T));
    }

    if (1 > TestObstacleControl_B.idx) {
      loop_ub = -1;
    } else {
      loop_ub = TestObstacleControl_B.idx - 1;
    }

    for (n = 0; n <= loop_ub; n++) {
      b_idx = (n << 1) + 1;
      TestObstacleControl_B.sectors_data[b_idx] =
        TestObstacleControl_B.changes[b_idx] - 1.0F;
    }

    loop_ub = (TestObstacleControl_B.idx << 1) - 1;
    if (0 <= loop_ub) {
      memset(&TestObstacleControl_B.angles_data[0], 0, (loop_ub + 1) * sizeof
             (real32_T));
    }

    if (1 > TestObstacleControl_B.idx) {
      loop_ub = -1;
      TestObstacleControl_B.idx = -1;
    } else {
      loop_ub = TestObstacleControl_B.idx - 1;
      TestObstacleControl_B.idx--;
    }

    for (n = 0; n <= loop_ub; n++) {
      b_idx = n << 1;
      TestObstacleControl_B.angles_data[b_idx] = obj->AngularSectorMidPoints[
        static_cast<int32_T>(TestObstacleControl_B.sectors_data[b_idx]) - 1];
    }

    for (n = 0; n <= TestObstacleControl_B.idx; n++) {
      b_idx = (n << 1) + 1;
      TestObstacleControl_B.angles_data[b_idx] = obj->AngularSectorMidPoints[
        static_cast<int32_T>(TestObstacleControl_B.sectors_data[b_idx]) - 1];
    }

    TestObstacleControl_diff_o(TestObstacleControl_B.sectors_data,
      TestObstacleControl_B.sectors_size, TestObstacleControl_B.sectorSizes_data,
      TestObstacleControl_B.sectorSizes_size);
    loop_ub = TestObstacleControl_B.sectorSizes_size[0] *
      TestObstacleControl_B.sectorSizes_size[1] - 1;
    for (n = 0; n <= loop_ub; n++) {
      TestObstacleControl_B.sectorSizes_data[n] *= obj->AngularDifference;
    }

    loop_ub = TestObstacleControl_B.sectorSizes_size[1] - 1;
    for (n = 0; n <= loop_ub; n++) {
      TestObstacleControl_B.ab_data[n] = static_cast<real32_T>
        (obj->NarrowOpeningThreshold);
    }

    loop_ub = TestObstacleControl_B.sectorSizes_size[1] - 1;
    TestObstacleControl_B.idx = 0;
    b_idx = 0;
    for (n = 0; n <= loop_ub; n++) {
      if (TestObstacleControl_B.sectorSizes_data[n] <
          TestObstacleControl_B.ab_data[n]) {
        TestObstacleControl_B.idx++;
        TestObstacleControl_B.ob_data[b_idx] = n + 1;
        b_idx++;
      }
    }

    TestObstacleControl_B.angles_size[0] = 1;
    TestObstacleControl_B.angles_size[1] = TestObstacleControl_B.idx;
    TestObstacleControl_B.angles_size_h[0] = 1;
    TestObstacleControl_B.angles_size_h[1] = TestObstacleControl_B.idx;
    for (n = 0; n < TestObstacleControl_B.idx; n++) {
      b_idx = (TestObstacleControl_B.ob_data[n] - 1) << 1;
      TestObstacleControl_B.angles_data_j[n] =
        TestObstacleControl_B.angles_data[b_idx];
      TestObstacleControl_B.angles_data_d[n] =
        TestObstacleControl_B.angles_data[b_idx + 1];
    }

    TestObstacleContro_bisectAngles(TestObstacleControl_B.angles_data_j,
      TestObstacleControl_B.angles_size, TestObstacleControl_B.angles_data_d,
      TestObstacleControl_B.angles_size_h, TestObstacleControl_B.narrowDirs_data,
      TestObstacleControl_B.sectors_size);
    loop_ub = TestObstacleControl_B.sectorSizes_size[1] - 1;
    TestObstacleControl_B.idx = 0;
    b_idx = 0;
    for (n = 0; n <= loop_ub; n++) {
      if (!(TestObstacleControl_B.sectorSizes_data[n] <
            TestObstacleControl_B.ab_data[n])) {
        TestObstacleControl_B.idx++;
        TestObstacleControl_B.tb_data[b_idx] = n + 1;
        b_idx++;
      }
    }

    b_idx = TestObstacleControl_B.idx + TestObstacleControl_B.idx;
    for (n = 0; n < TestObstacleControl_B.idx; n++) {
      loop_ub = (TestObstacleControl_B.tb_data[n] - 1) << 1;
      nonNarrowDirs_data_tmp = static_cast<real32_T>(obj->NarrowOpeningThreshold)
        / 2.0F;
      TestObstacleControl_B.sectors_data[n] =
        TestObstacleControl_B.angles_data[loop_ub] + nonNarrowDirs_data_tmp;
      TestObstacleControl_B.sectors_data[n + TestObstacleControl_B.idx] =
        TestObstacleControl_B.angles_data[loop_ub + 1] - nonNarrowDirs_data_tmp;
    }

    if (rtIsNaNF(obj->PreviousDirection)) {
      obj->PreviousDirection = 0.0F;
    }

    loop_ub = TestObstacleControl_B.sectors_size[1];
    TestObstacleControl_B.idx = b_idx + TestObstacleControl_B.sectors_size[1];
    TestObstacleControl_B.candidateDirs_size[1] = TestObstacleControl_B.idx + 3;
    if (0 <= b_idx - 1) {
      memcpy(&TestObstacleControl_B.candidateDirs_data[0],
             &TestObstacleControl_B.sectors_data[0], b_idx * sizeof(real32_T));
    }

    for (n = 0; n < loop_ub; n++) {
      TestObstacleControl_B.candidateDirs_data[n + b_idx] =
        TestObstacleControl_B.narrowDirs_data[n];
    }

    TestObstacleControl_B.candidateDirs_data[TestObstacleControl_B.idx] =
      targetDir;
    TestObstacleControl_B.candidateDirs_data[TestObstacleControl_B.idx + 1] =
      0.0F;
    TestObstacleControl_B.candidateDirs_data[TestObstacleControl_B.idx + 2] =
      obj->PreviousDirection;
    n = TestObstacleControl_B.candidateDirs_size[1];
    loop_ub = TestObstacleControl_B.candidateDirs_size[1];
    if (0 <= loop_ub - 1) {
      memcpy(&TestObstacleControl_B.cDiff_data[0],
             &TestObstacleControl_B.candidateDirs_data[0], loop_ub * sizeof
             (real32_T));
    }

    TestObstacleControl_bsxfun(obj->AngularSectorMidPoints,
      TestObstacleControl_B.cDiff_data, &n, TestObstacleControl_B.tmp_data,
      TestObstacleControl_B.sectorSizes_size);
    TestObstacleControl_abs_o(TestObstacleControl_B.tmp_data,
      TestObstacleControl_B.sectorSizes_size,
      TestObstacleControl_B.candToSectDiff_data,
      TestObstacleControl_B.angles_size);
    loop_ub = TestObstacleControl_B.angles_size[0] - 1;
    minval_size = TestObstacleControl_B.angles_size[0];
    if (0 <= loop_ub) {
      memcpy(&TestObstacleControl_B.cDiff_data[0],
             &TestObstacleControl_B.candToSectDiff_data[0], (loop_ub + 1) *
             sizeof(real32_T));
    }

    for (n = 0; n < 35; n++) {
      for (TestObstacleControl_B.idx = 0; TestObstacleControl_B.idx <= loop_ub;
           TestObstacleControl_B.idx++) {
        nonNarrowDirs_data_tmp =
          TestObstacleControl_B.cDiff_data[TestObstacleControl_B.idx];
        b_idx = (n + 1) * TestObstacleControl_B.angles_size[0] +
          TestObstacleControl_B.idx;
        if (rtIsNaNF(TestObstacleControl_B.candToSectDiff_data[b_idx])) {
          tmp = false;
        } else {
          tmp = (rtIsNaNF
                 (TestObstacleControl_B.cDiff_data[TestObstacleControl_B.idx]) ||
                 (TestObstacleControl_B.cDiff_data[TestObstacleControl_B.idx] >
                  TestObstacleControl_B.candToSectDiff_data[b_idx]));
        }

        if (tmp) {
          nonNarrowDirs_data_tmp =
            TestObstacleControl_B.candToSectDiff_data[b_idx];
        }

        TestObstacleControl_B.cDiff_data[TestObstacleControl_B.idx] =
          nonNarrowDirs_data_tmp;
      }
    }

    TestObstacleControl_bsxfun_o(TestObstacleControl_B.candToSectDiff_data,
      TestObstacleControl_B.angles_size, TestObstacleControl_B.cDiff_data,
      &minval_size, TestObstacleControl_B.tmp_data,
      TestObstacleControl_B.sectorSizes_size);
    loop_ub = TestObstacleControl_B.sectorSizes_size[0] *
      TestObstacleControl_B.sectorSizes_size[1];
    for (n = 0; n < loop_ub; n++) {
      TestObstacleControl_B.nearIdx_data[n] = (TestObstacleControl_B.tmp_data[n]
        < 0.000345266977F);
    }

    loop_ub = TestObstacleControl_B.sectorSizes_size[0] - 1;
    for (n = 0; n <= loop_ub; n++) {
      TestObstacleControl_B.freeDirs_data[n] = true;
    }

    loop_ub = TestObstacleControl_B.sectorSizes_size[0] - 1;
    if (0 <= loop_ub) {
      TestObstacleControl_B.obj_size[0] = 1;
    }

    for (TestObstacleControl_B.idx = 0; TestObstacleControl_B.idx <= loop_ub;
         TestObstacleControl_B.idx++) {
      b_idx = 0;
      TestObstacleControl_B.h_partialTrueCount = 0;
      for (n = 0; n < 36; n++) {
        if (TestObstacleControl_B.nearIdx_data[TestObstacleControl_B.sectorSizes_size
            [0] * n + TestObstacleControl_B.idx]) {
          b_idx++;
          TestObstacleControl_B.ub_data[TestObstacleControl_B.h_partialTrueCount]
            = static_cast<int8_T>(n + 1);
          TestObstacleControl_B.h_partialTrueCount++;
        }
      }

      TestObstacleControl_B.obj_size[1] = b_idx;
      for (n = 0; n < b_idx; n++) {
        TestObstacleControl_B.obj_data[n] = obj->
          MaskedHistogram[TestObstacleControl_B.ub_data[n] - 1];
      }

      TestObstacleControl_B.freeDirs_data[TestObstacleControl_B.idx] =
        !TestObstacleControl_any_o(TestObstacleControl_B.obj_data,
        TestObstacleControl_B.obj_size);
    }

    TestObstacleControl_B.idx = TestObstacleControl_B.sectorSizes_size[0] - 1;
    loop_ub = 0;
    TestObstacleControl_B.candidateDirections_size[0] = 1;
    b_idx = 0;
    for (n = 0; n <= TestObstacleControl_B.idx; n++) {
      if (TestObstacleControl_B.freeDirs_data[n]) {
        loop_ub++;
        TestObstacleControl_B.candidateDirections_data[b_idx] =
          TestObstacleControl_B.candidateDirs_data[n];
        b_idx++;
      }
    }

    TestObstacleControl_B.candidateDirections_size[1] = loop_ub;
    VectorFieldHistogramBase_comput(obj,
      TestObstacleControl_B.candidateDirections_data,
      TestObstacleControl_B.candidateDirections_size, targetDir,
      obj->PreviousDirection, TestObstacleControl_B.candidateDirs_data,
      TestObstacleControl_B.candidateDirs_size);
    n = TestObstacleControl_B.candidateDirs_size[1];
    if (TestObstacleControl_B.candidateDirs_size[1] <= 2) {
      if (TestObstacleControl_B.candidateDirs_size[1] == 1) {
        TestObstacleControl_B.cVal = TestObstacleControl_B.candidateDirs_data[0];
      } else if ((TestObstacleControl_B.candidateDirs_data[0] >
                  TestObstacleControl_B.candidateDirs_data[1]) || (rtIsNaNF
                  (TestObstacleControl_B.candidateDirs_data[0]) && (!rtIsNaNF
                   (TestObstacleControl_B.candidateDirs_data[1])))) {
        TestObstacleControl_B.cVal = TestObstacleControl_B.candidateDirs_data[1];
      } else {
        TestObstacleControl_B.cVal = TestObstacleControl_B.candidateDirs_data[0];
      }
    } else {
      if (!rtIsNaNF(TestObstacleControl_B.candidateDirs_data[0])) {
        b_idx = 1;
      } else {
        b_idx = 0;
        loop_ub = 2;
        exitg1 = false;
        while ((!exitg1) && (loop_ub <=
                             TestObstacleControl_B.candidateDirs_size[1])) {
          if (!rtIsNaNF(TestObstacleControl_B.candidateDirs_data[loop_ub - 1]))
          {
            b_idx = loop_ub;
            exitg1 = true;
          } else {
            loop_ub++;
          }
        }
      }

      if (b_idx == 0) {
        TestObstacleControl_B.cVal = TestObstacleControl_B.candidateDirs_data[0];
      } else {
        TestObstacleControl_B.cVal =
          TestObstacleControl_B.candidateDirs_data[b_idx - 1];
        for (loop_ub = b_idx + 1; loop_ub <= n; loop_ub++) {
          nonNarrowDirs_data_tmp =
            TestObstacleControl_B.candidateDirs_data[loop_ub - 1];
          if (TestObstacleControl_B.cVal > nonNarrowDirs_data_tmp) {
            TestObstacleControl_B.cVal = nonNarrowDirs_data_tmp;
          }
        }
      }
    }

    loop_ub = TestObstacleControl_B.candidateDirs_size[0] *
      TestObstacleControl_B.candidateDirs_size[1] - 1;
    for (n = 0; n <= loop_ub; n++) {
      TestObstacleControl_B.cDiff_data[n] =
        TestObstacleControl_B.candidateDirs_data[n] - TestObstacleControl_B.cVal;
    }

    loop_ub = TestObstacleControl_B.candidateDirs_size[1] - 1;
    TestObstacleControl_B.idx = 0;
    b_idx = 0;
    for (n = 0; n <= loop_ub; n++) {
      if (TestObstacleControl_B.cDiff_data[n] < 0.000345266977F) {
        TestObstacleControl_B.idx++;
        TestObstacleControl_B.vb_data[b_idx] = n + 1;
        b_idx++;
      }
    }

    if (TestObstacleControl_B.idx <= 2) {
      if (TestObstacleControl_B.idx == 1) {
        thetaSteer =
          TestObstacleControl_B.candidateDirections_data[TestObstacleControl_B.vb_data
          [0] - 1];
      } else {
        nonNarrowDirs_data_tmp =
          TestObstacleControl_B.candidateDirections_data[TestObstacleControl_B.vb_data
          [1] - 1];
        thetaSteer =
          TestObstacleControl_B.candidateDirections_data[TestObstacleControl_B.vb_data
          [0] - 1];
        if ((thetaSteer > nonNarrowDirs_data_tmp) || (rtIsNaNF
             (TestObstacleControl_B.candidateDirections_data[TestObstacleControl_B.vb_data
              [0] - 1]) && (!rtIsNaNF(nonNarrowDirs_data_tmp)))) {
          thetaSteer = nonNarrowDirs_data_tmp;
        }
      }
    } else {
      thetaSteer =
        TestObstacleControl_B.candidateDirections_data[TestObstacleControl_B.vb_data
        [0] - 1];
      if (!rtIsNaNF(thetaSteer)) {
        b_idx = 1;
      } else {
        b_idx = 0;
        loop_ub = 2;
        exitg1 = false;
        while ((!exitg1) && (loop_ub <= TestObstacleControl_B.idx)) {
          if (!rtIsNaNF
              (TestObstacleControl_B.candidateDirections_data[TestObstacleControl_B.vb_data
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
          TestObstacleControl_B.candidateDirections_data[TestObstacleControl_B.vb_data
          [b_idx - 1] - 1];
        for (loop_ub = b_idx + 1; loop_ub <= TestObstacleControl_B.idx; loop_ub
             ++) {
          n = TestObstacleControl_B.vb_data[loop_ub - 1] - 1;
          if (thetaSteer > TestObstacleControl_B.candidateDirections_data[n]) {
            thetaSteer = TestObstacleControl_B.candidateDirections_data[n];
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
  TestObstacleControl_B.scan_InternalRanges_size = *varargin_1_size;
  TestObstacleControl_B.loop_ub = *varargin_1_size;
  if (0 <= TestObstacleControl_B.loop_ub - 1) {
    memcpy(&TestObstacleControl_B.scan_InternalRanges_data[0], &varargin_1_data
           [0], TestObstacleControl_B.loop_ub * sizeof(real32_T));
  }

  TestObstacleControl_B.varargin_2_size = *varargin_2_size;
  TestObstacleControl_B.loop_ub = *varargin_2_size;
  for (TestObstacleControl_B.i_b = 0; TestObstacleControl_B.i_b <
       TestObstacleControl_B.loop_ub; TestObstacleControl_B.i_b++) {
    TestObstacleControl_B.varargin_2_data[TestObstacleControl_B.i_b] =
      static_cast<real32_T>(varargin_2_data[TestObstacleControl_B.i_b]);
  }

  TestObsta_lidarScan_lidarScan_o(TestObstacleControl_B.varargin_2_data,
    &TestObstacleControl_B.varargin_2_size,
    TestObstacleControl_B.scan_InternalAngles_data,
    &TestObstacleControl_B.scan_InternalAngles_size,
    &scan_ContainsOnlyFiniteData);
  TestObstacleControl_B.target = varargin_3;
  if (static_cast<real32_T>(fabs(static_cast<real_T>(varargin_3))) >
      3.1415926535897931) {
    TestObstacleControl_B.target = TestObstacleControl_wrapToPi_o(varargin_3);
  }

  VectorFieldHistogramBase_buildP(obj,
    TestObstacleControl_B.scan_InternalRanges_data,
    &TestObstacleControl_B.scan_InternalRanges_size,
    TestObstacleControl_B.scan_InternalAngles_data,
    &TestObstacleControl_B.scan_InternalAngles_size);
  TestObstacleControl_B.loop_ub = 0;
  TestObstacleControl_B.partialTrueCount = 0;
  for (TestObstacleControl_B.i_b = 0; TestObstacleControl_B.i_b < 36;
       TestObstacleControl_B.i_b++) {
    if (obj->PolarObstacleDensity[TestObstacleControl_B.i_b] >
        obj->HistogramThresholds[1]) {
      TestObstacleControl_B.loop_ub++;
      TestObstacleControl_B.b_data_d[TestObstacleControl_B.partialTrueCount] =
        static_cast<int8_T>(TestObstacleControl_B.i_b + 1);
      TestObstacleControl_B.partialTrueCount++;
    }
  }

  for (TestObstacleControl_B.i_b = 0; TestObstacleControl_B.i_b <
       TestObstacleControl_B.loop_ub; TestObstacleControl_B.i_b++) {
    obj->
      BinaryHistogram[TestObstacleControl_B.b_data_d[TestObstacleControl_B.i_b]
      - 1] = true;
  }

  TestObstacleControl_B.loop_ub = 0;
  TestObstacleControl_B.partialTrueCount = 0;
  for (TestObstacleControl_B.i_b = 0; TestObstacleControl_B.i_b < 36;
       TestObstacleControl_B.i_b++) {
    if (obj->PolarObstacleDensity[TestObstacleControl_B.i_b] <
        obj->HistogramThresholds[0]) {
      TestObstacleControl_B.loop_ub++;
      TestObstacleControl_B.c_data[TestObstacleControl_B.partialTrueCount] =
        static_cast<int8_T>(TestObstacleControl_B.i_b + 1);
      TestObstacleControl_B.partialTrueCount++;
    }
  }

  for (TestObstacleControl_B.i_b = 0; TestObstacleControl_B.i_b <
       TestObstacleControl_B.loop_ub; TestObstacleControl_B.i_b++) {
    obj->BinaryHistogram[TestObstacleControl_B.c_data[TestObstacleControl_B.i_b]
      - 1] = false;
  }

  VectorFieldHistogramBase_buildM(obj,
    TestObstacleControl_B.scan_InternalRanges_data,
    &TestObstacleControl_B.scan_InternalRanges_size,
    TestObstacleControl_B.scan_InternalAngles_data,
    &TestObstacleControl_B.scan_InternalAngles_size);
  steeringDir = VectorFieldHistogramBase_select(obj,
    TestObstacleControl_B.target);
  return steeringDir;
}

static real32_T TestObstacleCon_SystemCore_step(nav_slalgs_internal_VectorFie_T *
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

static void matlabCodegenHandle_matlabCod_o(ros_slros_internal_block_Subs_T *obj)
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
    (TestObstacleControl_wrapToPi_o(obj->AngularSectorMidPoints[1] -
    obj->AngularSectorMidPoints[0]))));
  angularLimits_idx_0 = obj->AngularDifference / 2.0F;
  for (d_k = 0; d_k < 36; d_k++) {
    obj->AngularSectorStartPoints[d_k] = obj->AngularSectorMidPoints[d_k] -
      angularLimits_idx_0;
    obj->BinaryHistogram[d_k] = false;
  }
}

// Model step function
void TestObstacleControl_step(void)
{
  boolean_T p;
  boolean_T b_varargout_1;
  boolean_T exitg1;

  // Outputs for Atomic SubSystem: '<Root>/Subscribe1'
  // MATLABSystem: '<S5>/SourceBlock' incorporates:
  //   Inport: '<S11>/In1'

  b_varargout_1 = Sub_TestObstacleControl_328.getLatestMessage
    (&TestObstacleControl_B.b_varargout_2);

  // Outputs for Enabled SubSystem: '<S5>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S11>/Enable'

  if (b_varargout_1) {
    TestObstacleControl_B.In1 = TestObstacleControl_B.b_varargout_2;
  }

  // End of MATLABSystem: '<S5>/SourceBlock'
  // End of Outputs for SubSystem: '<S5>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe1'

  // MATLAB Function: '<Root>/angles_and_dists1'
  if (TestObstacleControl_B.In1.Ranges_SL_Info.ReceivedLength > 0U) {
    for (TestObstacleControl_B.i = 0; TestObstacleControl_B.i < 128;
         TestObstacleControl_B.i++) {
      TestObstacleControl_B.ranges_d =
        TestObstacleControl_B.In1.Ranges[TestObstacleControl_B.i];
      if (TestObstacleControl_B.In1.Ranges[TestObstacleControl_B.i] >
          TestObstacleControl_B.In1.RangeMax) {
        TestObstacleControl_B.ranges_d = (rtNaNF);
      }

      if (TestObstacleControl_B.ranges_d < TestObstacleControl_B.In1.RangeMin) {
        TestObstacleControl_B.ranges_d = (rtNaNF);
      }

      TestObstacleControl_B.ranges[TestObstacleControl_B.i] =
        TestObstacleControl_B.ranges_d;
    }

    TestObstacleControl_DW.SFunction_DIMS2[0] = static_cast<int32_T>
      (TestObstacleControl_B.In1.Ranges_SL_Info.ReceivedLength);
    TestObstacleControl_DW.SFunction_DIMS2[1] = 1;
    TestObstacleControl_B.i = static_cast<int32_T>
      (TestObstacleControl_B.In1.Ranges_SL_Info.ReceivedLength);
    if (0 <= TestObstacleControl_B.i - 1) {
      memset(&TestObstacleControl_B.angles[0], 0, TestObstacleControl_B.i *
             sizeof(real_T));
    }

    TestObstacleControl_B.i = 0;
    while (TestObstacleControl_B.i <= static_cast<int32_T>
           (TestObstacleControl_B.In1.Ranges_SL_Info.ReceivedLength) - 1) {
      TestObstacleControl_B.ii = TestObstacleControl_B.i + 1U;
      TestObstacleControl_B.qY = TestObstacleControl_B.ii - /*MW:OvSatOk*/ 1U;
      if (TestObstacleControl_B.qY > TestObstacleControl_B.ii) {
        TestObstacleControl_B.qY = 0U;
      }

      TestObstacleControl_B.angles[static_cast<int32_T>(TestObstacleControl_B.ii)
        - 1] = static_cast<real_T>(TestObstacleControl_B.qY) *
        TestObstacleControl_B.In1.AngleIncrement +
        TestObstacleControl_B.In1.AngleMin;
      TestObstacleControl_B.i++;
    }

    TestObstacleControl_DW.SFunction_DIMS3[0] = 128;
    TestObstacleControl_DW.SFunction_DIMS3[1] = 1;
    memcpy(&TestObstacleControl_B.dists[0], &TestObstacleControl_B.ranges[0],
           sizeof(real32_T) << 7U);
  } else {
    TestObstacleControl_B.angles[0] = 0.0;
    TestObstacleControl_DW.SFunction_DIMS2[0] = 1;
    TestObstacleControl_DW.SFunction_DIMS3[0] = 1;
    TestObstacleControl_DW.SFunction_DIMS2[1] = 1;
    TestObstacleControl_DW.SFunction_DIMS3[1] = 1;
    TestObstacleControl_B.dists[0] = 0.0F;
  }

  // End of MATLAB Function: '<Root>/angles_and_dists1'

  // Outputs for Atomic SubSystem: '<Root>/Subscribe4'
  // MATLABSystem: '<S6>/SourceBlock'
  b_varargout_1 = Sub_TestObstacleControl_325.getLatestMessage
    (&TestObstacleControl_B.b_varargout_2_m);

  // Outputs for Enabled SubSystem: '<Root>/Decode ROS msg1' incorporates:
  //   EnablePort: '<S2>/Enable'

  // Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S12>/Enable'

  if (b_varargout_1) {
    // MATLABSystem: '<S2>/Coordinate Transformation Conversion' incorporates:
    //   SignalConversion generated from: '<S2>/Coordinate Transformation Conversion'

    TestObstacleControl_B.b_n = 1.0 / sqrt
      (((TestObstacleControl_B.b_varargout_2_m.Pose.Pose.Orientation.W *
         TestObstacleControl_B.b_varargout_2_m.Pose.Pose.Orientation.W +
         TestObstacleControl_B.b_varargout_2_m.Pose.Pose.Orientation.X *
         TestObstacleControl_B.b_varargout_2_m.Pose.Pose.Orientation.X) +
        TestObstacleControl_B.b_varargout_2_m.Pose.Pose.Orientation.Y *
        TestObstacleControl_B.b_varargout_2_m.Pose.Pose.Orientation.Y) +
       TestObstacleControl_B.b_varargout_2_m.Pose.Pose.Orientation.Z *
       TestObstacleControl_B.b_varargout_2_m.Pose.Pose.Orientation.Z);
    TestObstacleControl_B.b_z1_idx_0 =
      TestObstacleControl_B.b_varargout_2_m.Pose.Pose.Orientation.W *
      TestObstacleControl_B.b_n;
    TestObstacleControl_B.b_z1_idx_1 =
      TestObstacleControl_B.b_varargout_2_m.Pose.Pose.Orientation.X *
      TestObstacleControl_B.b_n;
    TestObstacleControl_B.b_z1_idx_2 =
      TestObstacleControl_B.b_varargout_2_m.Pose.Pose.Orientation.Y *
      TestObstacleControl_B.b_n;
    TestObstacleControl_B.b_n *=
      TestObstacleControl_B.b_varargout_2_m.Pose.Pose.Orientation.Z;

    // DataTypeConversion: '<S2>/Data Type Conversion2' incorporates:
    //   MATLABSystem: '<S2>/Coordinate Transformation Conversion'

    TestObstacleControl_B.DataTypeConversion2 = rt_atan2d_snf
      ((TestObstacleControl_B.b_z1_idx_1 * TestObstacleControl_B.b_z1_idx_2 -
        TestObstacleControl_B.b_n * TestObstacleControl_B.b_z1_idx_0) * -2.0,
       ((TestObstacleControl_B.b_z1_idx_0 * TestObstacleControl_B.b_z1_idx_0 +
         TestObstacleControl_B.b_z1_idx_1 * TestObstacleControl_B.b_z1_idx_1) -
        TestObstacleControl_B.b_z1_idx_2 * TestObstacleControl_B.b_z1_idx_2) -
       TestObstacleControl_B.b_n * TestObstacleControl_B.b_n);

    // DataTypeConversion: '<S2>/Data Type Conversion'
    TestObstacleControl_B.DataTypeConversion =
      TestObstacleControl_B.b_varargout_2_m.Pose.Pose.Position.X;

    // DataTypeConversion: '<S2>/Data Type Conversion1'
    TestObstacleControl_B.DataTypeConversion1 =
      TestObstacleControl_B.b_varargout_2_m.Pose.Pose.Position.Y;
  }

  // End of MATLABSystem: '<S6>/SourceBlock'
  // End of Outputs for SubSystem: '<S6>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Decode ROS msg1'
  // End of Outputs for SubSystem: '<Root>/Subscribe4'

  // MATLABSystem: '<S3>/Pure Pursuit' incorporates:
  //   Constant: '<Root>/Waypoints'
  //   SignalConversion generated from: '<S3>/Pure Pursuit'

  if (TestObstacleControl_DW.obj_f.DesiredLinearVelocity !=
      TestObstacleControl_P.PurePursuit_DesiredLinearVeloci) {
    TestObstacleControl_DW.obj_f.DesiredLinearVelocity =
      TestObstacleControl_P.PurePursuit_DesiredLinearVeloci;
  }

  if (TestObstacleControl_DW.obj_f.MaxAngularVelocity !=
      TestObstacleControl_P.PurePursuit_MaxAngularVelocity) {
    TestObstacleControl_DW.obj_f.MaxAngularVelocity =
      TestObstacleControl_P.PurePursuit_MaxAngularVelocity;
  }

  if (TestObstacleControl_DW.obj_f.LookaheadDistance !=
      TestObstacleControl_P.PurePursuit_LookaheadDistance) {
    TestObstacleControl_DW.obj_f.LookaheadDistance =
      TestObstacleControl_P.PurePursuit_LookaheadDistance;
  }

  b_varargout_1 = false;
  p = true;
  TestObstacleControl_B.i = 0;
  exitg1 = false;
  while ((!exitg1) && (TestObstacleControl_B.i < 8)) {
    if ((TestObstacleControl_DW.obj_f.WaypointsInternal[TestObstacleControl_B.i]
         == TestObstacleControl_P.Waypoints_Value[TestObstacleControl_B.i]) ||
        (rtIsNaN
         (TestObstacleControl_DW.obj_f.WaypointsInternal[TestObstacleControl_B.i])
         && rtIsNaN
         (TestObstacleControl_P.Waypoints_Value[TestObstacleControl_B.i]))) {
      TestObstacleControl_B.i++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (p) {
    b_varargout_1 = true;
  }

  if (!b_varargout_1) {
    memcpy(&TestObstacleControl_DW.obj_f.WaypointsInternal[0],
           &TestObstacleControl_P.Waypoints_Value[0], sizeof(real_T) << 3U);
    TestObstacleControl_DW.obj_f.ProjectionLineIndex = 0.0;
  }

  TestObstacleControl_B.dv2[0] = TestObstacleControl_B.DataTypeConversion;
  TestObstacleControl_B.dv2[1] = TestObstacleControl_B.DataTypeConversion1;
  TestObstacleControl_B.dv2[2] = TestObstacleControl_B.DataTypeConversion2;
  Te_PurePursuitBase_stepInternal(&TestObstacleControl_DW.obj_f,
    TestObstacleControl_B.dv2, TestObstacleControl_P.Waypoints_Value,
    &TestObstacleControl_B.b_z1_idx_0, &TestObstacleControl_B.b_z1_idx_1,
    TestObstacleControl_B.unusedU0, &TestObstacleControl_B.b_z1_idx_2);

  // MATLABSystem: '<S3>/Vector Field Histogram' incorporates:
  //   DataTypeConversion: '<S3>/Cast To Single'
  //   MATLABSystem: '<S3>/Pure Pursuit'

  b_varargout_1 = false;
  p = true;
  TestObstacleControl_B.i = 0;
  exitg1 = false;
  while ((!exitg1) && (TestObstacleControl_B.i < 2)) {
    if (!(TestObstacleControl_DW.obj.DistanceLimits[TestObstacleControl_B.i] ==
          TestObstacleControl_P.VectorFieldHistogram_DistanceLi[TestObstacleControl_B.i]))
    {
      p = false;
      exitg1 = true;
    } else {
      TestObstacleControl_B.i++;
    }
  }

  if (p) {
    b_varargout_1 = true;
  }

  if (!b_varargout_1) {
    if ((TestObstacleControl_P.VectorFieldHistogram_DistanceLi[0] >
         TestObstacleControl_P.VectorFieldHistogram_DistanceLi[1]) || (rtIsNaN
         (TestObstacleControl_P.VectorFieldHistogram_DistanceLi[0]) && (!rtIsNaN
          (TestObstacleControl_P.VectorFieldHistogram_DistanceLi[1])))) {
      TestObstacleControl_DW.obj.DistanceLimits[0] =
        TestObstacleControl_P.VectorFieldHistogram_DistanceLi[1];
    } else {
      TestObstacleControl_DW.obj.DistanceLimits[0] =
        TestObstacleControl_P.VectorFieldHistogram_DistanceLi[0];
    }

    if ((TestObstacleControl_P.VectorFieldHistogram_DistanceLi[0] <
         TestObstacleControl_P.VectorFieldHistogram_DistanceLi[1]) || (rtIsNaN
         (TestObstacleControl_P.VectorFieldHistogram_DistanceLi[0]) && (!rtIsNaN
          (TestObstacleControl_P.VectorFieldHistogram_DistanceLi[1])))) {
      TestObstacleControl_DW.obj.DistanceLimits[1] =
        TestObstacleControl_P.VectorFieldHistogram_DistanceLi[1];
    } else {
      TestObstacleControl_DW.obj.DistanceLimits[1] =
        TestObstacleControl_P.VectorFieldHistogram_DistanceLi[0];
    }
  }

  b_varargout_1 = false;
  p = true;
  TestObstacleControl_B.i = 0;
  exitg1 = false;
  while ((!exitg1) && (TestObstacleControl_B.i < 2)) {
    if (!(TestObstacleControl_DW.obj.HistogramThresholds[TestObstacleControl_B.i]
          ==
          TestObstacleControl_P.VectorFieldHistogram_HistogramT[TestObstacleControl_B.i]))
    {
      p = false;
      exitg1 = true;
    } else {
      TestObstacleControl_B.i++;
    }
  }

  if (p) {
    b_varargout_1 = true;
  }

  if (!b_varargout_1) {
    if ((TestObstacleControl_P.VectorFieldHistogram_HistogramT[0] >
         TestObstacleControl_P.VectorFieldHistogram_HistogramT[1]) || (rtIsNaN
         (TestObstacleControl_P.VectorFieldHistogram_HistogramT[0]) && (!rtIsNaN
          (TestObstacleControl_P.VectorFieldHistogram_HistogramT[1])))) {
      TestObstacleControl_DW.obj.HistogramThresholds[0] =
        TestObstacleControl_P.VectorFieldHistogram_HistogramT[1];
    } else {
      TestObstacleControl_DW.obj.HistogramThresholds[0] =
        TestObstacleControl_P.VectorFieldHistogram_HistogramT[0];
    }

    if ((TestObstacleControl_P.VectorFieldHistogram_HistogramT[0] <
         TestObstacleControl_P.VectorFieldHistogram_HistogramT[1]) || (rtIsNaN
         (TestObstacleControl_P.VectorFieldHistogram_HistogramT[0]) && (!rtIsNaN
          (TestObstacleControl_P.VectorFieldHistogram_HistogramT[1])))) {
      TestObstacleControl_DW.obj.HistogramThresholds[1] =
        TestObstacleControl_P.VectorFieldHistogram_HistogramT[1];
    } else {
      TestObstacleControl_DW.obj.HistogramThresholds[1] =
        TestObstacleControl_P.VectorFieldHistogram_HistogramT[0];
    }
  }

  if (TestObstacleControl_DW.obj.RobotRadius != TestObstacleControl_P.L) {
    TestObstacleControl_DW.obj.RobotRadius = TestObstacleControl_P.L;
  }

  if (TestObstacleControl_DW.obj.SafetyDistance != TestObstacleControl_P.L) {
    TestObstacleControl_DW.obj.SafetyDistance = TestObstacleControl_P.L;
  }

  if (TestObstacleControl_DW.obj.MinTurningRadius !=
      TestObstacleControl_P.VectorFieldHistogram_MinTurning) {
    TestObstacleControl_DW.obj.MinTurningRadius =
      TestObstacleControl_P.VectorFieldHistogram_MinTurning;
  }

  if (TestObstacleControl_DW.obj.TargetDirectionWeight !=
      TestObstacleControl_P.VectorFieldHistogram_TargetDire) {
    TestObstacleControl_DW.obj.TargetDirectionWeight =
      TestObstacleControl_P.VectorFieldHistogram_TargetDire;
  }

  if (TestObstacleControl_DW.obj.CurrentDirectionWeight !=
      TestObstacleControl_P.VectorFieldHistogram_CurrentDir) {
    TestObstacleControl_DW.obj.CurrentDirectionWeight =
      TestObstacleControl_P.VectorFieldHistogram_CurrentDir;
  }

  if (TestObstacleControl_DW.obj.PreviousDirectionWeight !=
      TestObstacleControl_P.VectorFieldHistogram_PreviousDi) {
    TestObstacleControl_DW.obj.PreviousDirectionWeight =
      TestObstacleControl_P.VectorFieldHistogram_PreviousDi;
  }

  TestObstacleControl_B.SFunction_DIMS3 =
    TestObstacleControl_DW.SFunction_DIMS3[0];
  TestObstacleControl_B.SFunction_DIMS2 =
    TestObstacleControl_DW.SFunction_DIMS2[0];
  TestObstacleControl_B.ranges_d = TestObstacleCon_SystemCore_step
    (&TestObstacleControl_DW.obj, TestObstacleControl_B.dists,
     &TestObstacleControl_B.SFunction_DIMS3, TestObstacleControl_B.angles,
     &TestObstacleControl_B.SFunction_DIMS2, static_cast<real32_T>
     (TestObstacleControl_B.b_z1_idx_2));

  // BusAssignment: '<Root>/Bus Assignment2' incorporates:
  //   Constant: '<S1>/Constant'
  //   MATLABSystem: '<S3>/Pure Pursuit'

  TestObstacleControl_B.BusAssignment2 = TestObstacleControl_P.Constant_Value_k;
  TestObstacleControl_B.BusAssignment2.Linear.X =
    TestObstacleControl_B.b_z1_idx_0;

  // Switch: '<S8>/Switch' incorporates:
  //   Abs: '<S8>/Abs'
  //   Constant: '<S10>/Constant'
  //   Constant: '<S9>/Constant'
  //   Logic: '<S8>/Logical Operator'
  //   MATLABSystem: '<S3>/Pure Pursuit'
  //   MATLABSystem: '<S3>/Vector Field Histogram'
  //   RelationalOperator: '<S10>/Compare'
  //   RelationalOperator: '<S9>/Compare'
  //   Sum: '<S8>/Subtract'

  if ((fabs(TestObstacleControl_B.b_z1_idx_2 - TestObstacleControl_B.ranges_d) <=
       TestObstacleControl_P.CompareToConstant1_const) ||
      (TestObstacleControl_B.ranges_d ==
       TestObstacleControl_P.CompareToConstant_const)) {
    // BusAssignment: '<Root>/Bus Assignment2'
    TestObstacleControl_B.BusAssignment2.Angular.Z =
      TestObstacleControl_B.b_z1_idx_1;
  } else {
    // BusAssignment: '<Root>/Bus Assignment2' incorporates:
    //   Gain: '<S8>/Steering Gain'

    TestObstacleControl_B.BusAssignment2.Angular.Z =
      TestObstacleControl_P.SteeringGain_Gain * TestObstacleControl_B.ranges_d;
  }

  // End of Switch: '<S8>/Switch'

  // Outputs for Atomic SubSystem: '<Root>/Publish1'
  // MATLABSystem: '<S4>/SinkBlock'
  Pub_TestObstacleControl_309.publish(&TestObstacleControl_B.BusAssignment2);

  // End of Outputs for SubSystem: '<Root>/Publish1'
}

// Model initialize function
void TestObstacleControl_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // non-finite (run-time) assignments
  TestObstacleControl_P.CompareToConstant_const = rtNaNF;

  {
    char_T tmp[6];
    char_T tmp_0[9];
    int32_T i;
    static const char_T tmp_1[5] = { '/', 's', 'c', 'a', 'n' };

    static const char_T tmp_2[5] = { '/', 'o', 'd', 'o', 'm' };

    static const char_T tmp_3[8] = { '/', 'c', 'm', 'd', '_', 'v', 'e', 'l' };

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe1'
    // SystemInitialize for Enabled SubSystem: '<S5>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S11>/Out1'
    TestObstacleControl_B.In1 = TestObstacleControl_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S5>/Enabled Subsystem'

    // Start for MATLABSystem: '<S5>/SourceBlock'
    TestObstacleControl_DW.obj_d.matlabCodegenIsDeleted = false;
    TestObstacleControl_DW.obj_d.isInitialized = 1;
    for (i = 0; i < 5; i++) {
      tmp[i] = tmp_1[i];
    }

    tmp[5] = '\x00';
    Sub_TestObstacleControl_328.createSubscriber(tmp, 1);
    TestObstacleControl_DW.obj_d.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe1'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe4'
    // Start for MATLABSystem: '<S6>/SourceBlock'
    TestObstacleControl_DW.obj_h.matlabCodegenIsDeleted = false;
    TestObstacleControl_DW.obj_h.isInitialized = 1;
    for (i = 0; i < 5; i++) {
      tmp[i] = tmp_2[i];
    }

    tmp[5] = '\x00';
    Sub_TestObstacleControl_325.createSubscriber(tmp, 1);
    TestObstacleControl_DW.obj_h.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S6>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe4'

    // SystemInitialize for Enabled SubSystem: '<Root>/Decode ROS msg1'
    // SystemInitialize for Outport: '<S2>/X'
    TestObstacleControl_B.DataTypeConversion = TestObstacleControl_P.X_Y0;

    // SystemInitialize for Outport: '<S2>/Y'
    TestObstacleControl_B.DataTypeConversion1 = TestObstacleControl_P.Y_Y0;

    // SystemInitialize for Outport: '<S2>/Theta'
    TestObstacleControl_B.DataTypeConversion2 = TestObstacleControl_P.Theta_Y0;

    // End of SystemInitialize for SubSystem: '<Root>/Decode ROS msg1'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish1'
    // Start for MATLABSystem: '<S4>/SinkBlock'
    TestObstacleControl_DW.obj_g.matlabCodegenIsDeleted = false;
    TestObstacleControl_DW.obj_g.isInitialized = 1;
    for (i = 0; i < 8; i++) {
      tmp_0[i] = tmp_3[i];
    }

    tmp_0[8] = '\x00';
    Pub_TestObstacleControl_309.createPublisher(tmp_0, 1);
    TestObstacleControl_DW.obj_g.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S4>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish1'

    // Start for MATLABSystem: '<S3>/Pure Pursuit'
    TestObstacleControl_DW.obj_f.DesiredLinearVelocity =
      TestObstacleControl_P.PurePursuit_DesiredLinearVeloci;
    TestObstacleControl_DW.obj_f.MaxAngularVelocity =
      TestObstacleControl_P.PurePursuit_MaxAngularVelocity;
    TestObstacleControl_DW.obj_f.LookaheadDistance =
      TestObstacleControl_P.PurePursuit_LookaheadDistance;
    TestObstacleControl_DW.obj_f.isInitialized = 1;
    for (i = 0; i < 8; i++) {
      TestObstacleControl_DW.obj_f.WaypointsInternal[i] = (rtNaN);
    }

    TestObstacleControl_DW.obj_f.LookaheadPoint[0] = 0.0;
    TestObstacleControl_DW.obj_f.LookaheadPoint[1] = 0.0;
    TestObstacleControl_DW.obj_f.LastPose[0] = 0.0;
    TestObstacleControl_DW.obj_f.LastPose[1] = 0.0;
    TestObstacleControl_DW.obj_f.LastPose[2] = 0.0;
    TestObstacleControl_DW.obj_f.ProjectionLineIndex = 0.0;

    // End of Start for MATLABSystem: '<S3>/Pure Pursuit'

    // InitializeConditions for MATLABSystem: '<S3>/Pure Pursuit'
    TestObstacleControl_DW.obj_f.LookaheadPoint[0] *= 0.0;
    TestObstacleControl_DW.obj_f.LookaheadPoint[1] *= 0.0;
    TestObstacleControl_DW.obj_f.LastPose[0] *= 0.0;
    TestObstacleControl_DW.obj_f.LastPose[1] *= 0.0;
    TestObstacleControl_DW.obj_f.LastPose[2] *= 0.0;
    TestObstacleControl_DW.obj_f.ProjectionLineIndex *= 0.0;

    // Start for MATLABSystem: '<S3>/Vector Field Histogram'
    TestObstacleControl_DW.obj.NarrowOpeningThreshold = 0.8;

    // InitializeConditions for MATLABSystem: '<S3>/Pure Pursuit'
    TestObstacleControl_DW.obj_f.ProjectionPoint[0] = (rtNaN);

    // Start for MATLABSystem: '<S3>/Vector Field Histogram'
    TestObstacleControl_DW.obj.AngularLimits[0] = -3.1415926535897931;

    // InitializeConditions for MATLABSystem: '<S3>/Pure Pursuit'
    TestObstacleControl_DW.obj_f.ProjectionPoint[1] = (rtNaN);

    // Start for MATLABSystem: '<S3>/Vector Field Histogram'
    TestObstacleControl_DW.obj.AngularLimits[1] = 3.1415926535897931;
    TestObstacleControl_DW.obj.CacheInputSizes = false;
    if ((TestObstacleControl_P.VectorFieldHistogram_DistanceLi[0] >
         TestObstacleControl_P.VectorFieldHistogram_DistanceLi[1]) || (rtIsNaN
         (TestObstacleControl_P.VectorFieldHistogram_DistanceLi[0]) && (!rtIsNaN
          (TestObstacleControl_P.VectorFieldHistogram_DistanceLi[1])))) {
      TestObstacleControl_DW.obj.DistanceLimits[0] =
        TestObstacleControl_P.VectorFieldHistogram_DistanceLi[1];
    } else {
      TestObstacleControl_DW.obj.DistanceLimits[0] =
        TestObstacleControl_P.VectorFieldHistogram_DistanceLi[0];
    }

    if ((TestObstacleControl_P.VectorFieldHistogram_DistanceLi[0] <
         TestObstacleControl_P.VectorFieldHistogram_DistanceLi[1]) || (rtIsNaN
         (TestObstacleControl_P.VectorFieldHistogram_DistanceLi[0]) && (!rtIsNaN
          (TestObstacleControl_P.VectorFieldHistogram_DistanceLi[1])))) {
      TestObstacleControl_DW.obj.DistanceLimits[1] =
        TestObstacleControl_P.VectorFieldHistogram_DistanceLi[1];
    } else {
      TestObstacleControl_DW.obj.DistanceLimits[1] =
        TestObstacleControl_P.VectorFieldHistogram_DistanceLi[0];
    }

    if ((TestObstacleControl_P.VectorFieldHistogram_HistogramT[0] >
         TestObstacleControl_P.VectorFieldHistogram_HistogramT[1]) || (rtIsNaN
         (TestObstacleControl_P.VectorFieldHistogram_HistogramT[0]) && (!rtIsNaN
          (TestObstacleControl_P.VectorFieldHistogram_HistogramT[1])))) {
      TestObstacleControl_DW.obj.HistogramThresholds[0] =
        TestObstacleControl_P.VectorFieldHistogram_HistogramT[1];
    } else {
      TestObstacleControl_DW.obj.HistogramThresholds[0] =
        TestObstacleControl_P.VectorFieldHistogram_HistogramT[0];
    }

    if ((TestObstacleControl_P.VectorFieldHistogram_HistogramT[0] <
         TestObstacleControl_P.VectorFieldHistogram_HistogramT[1]) || (rtIsNaN
         (TestObstacleControl_P.VectorFieldHistogram_HistogramT[0]) && (!rtIsNaN
          (TestObstacleControl_P.VectorFieldHistogram_HistogramT[1])))) {
      TestObstacleControl_DW.obj.HistogramThresholds[1] =
        TestObstacleControl_P.VectorFieldHistogram_HistogramT[1];
    } else {
      TestObstacleControl_DW.obj.HistogramThresholds[1] =
        TestObstacleControl_P.VectorFieldHistogram_HistogramT[0];
    }

    TestObstacleControl_DW.obj.RobotRadius = TestObstacleControl_P.L;
    TestObstacleControl_DW.obj.SafetyDistance = TestObstacleControl_P.L;
    TestObstacleControl_DW.obj.MinTurningRadius =
      TestObstacleControl_P.VectorFieldHistogram_MinTurning;
    TestObstacleControl_DW.obj.TargetDirectionWeight =
      TestObstacleControl_P.VectorFieldHistogram_TargetDire;
    TestObstacleControl_DW.obj.CurrentDirectionWeight =
      TestObstacleControl_P.VectorFieldHistogram_CurrentDir;
    TestObstacleControl_DW.obj.PreviousDirectionWeight =
      TestObstacleControl_P.VectorFieldHistogram_PreviousDi;
    TestObstacleControl_DW.obj.isInitialized = 1;
    i = TestObstacleControl_DW.SFunction_DIMS3[0];
    if (TestObstacleControl_DW.SFunction_DIMS3[0] < 0) {
      i = 0;
    }

    TestObstacleControl_DW.obj.inputVarSize[0].f1[0] = static_cast<uint32_T>(i);
    TestObstacleControl_DW.obj.inputVarSize[0].f1[1] = 1U;
    i = TestObstacleControl_DW.SFunction_DIMS2[0];
    if (TestObstacleControl_DW.SFunction_DIMS2[0] < 0) {
      i = 0;
    }

    TestObstacleControl_DW.obj.inputVarSize[1].f1[0] = static_cast<uint32_T>(i);
    TestObstacleControl_DW.obj.inputVarSize[1].f1[1] = 1U;
    for (i = 0; i < 6; i++) {
      TestObstacleControl_DW.obj.inputVarSize[0].f1[i + 2] = 1U;
      TestObstacleControl_DW.obj.inputVarSize[1].f1[i + 2] = 1U;
    }

    for (i = 0; i < 8; i++) {
      TestObstacleControl_DW.obj.inputVarSize[2].f1[i] = 1U;
    }

    VectorFieldHistogramBase_setupI(&TestObstacleControl_DW.obj);

    // InitializeConditions for MATLABSystem: '<S3>/Vector Field Histogram'
    for (i = 0; i < 36; i++) {
      TestObstacleControl_DW.obj.BinaryHistogram[i] = false;
    }

    TestObstacleControl_DW.obj.PreviousDirection *= 0.0F;

    // End of InitializeConditions for MATLABSystem: '<S3>/Vector Field Histogram' 
  }
}

// Model terminate function
void TestObstacleControl_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe1'
  // Terminate for MATLABSystem: '<S5>/SourceBlock'
  matlabCodegenHandle_matlabCod_o(&TestObstacleControl_DW.obj_d);

  // End of Terminate for SubSystem: '<Root>/Subscribe1'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe4'
  // Terminate for MATLABSystem: '<S6>/SourceBlock'
  matlabCodegenHandle_matlabCod_o(&TestObstacleControl_DW.obj_h);

  // End of Terminate for SubSystem: '<Root>/Subscribe4'

  // Terminate for Atomic SubSystem: '<Root>/Publish1'
  // Terminate for MATLABSystem: '<S4>/SinkBlock'
  matlabCodegenHandle_matlabCodeg(&TestObstacleControl_DW.obj_g);

  // End of Terminate for SubSystem: '<Root>/Publish1'
}

//
// File trailer for generated code.
//
// [EOF]
//
