//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: testConnexion.cpp
//
// Code generated for Simulink model 'testConnexion'.
//
// Model version                  : 1.1
// Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
// C/C++ source code generated on : Thu May  7 16:24:36 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "testConnexion.h"
#include "testConnexion_private.h"
#include "testConnexion_dt.h"

// Block states (default storage)
DW_testConnexion_T testConnexion_DW;

// Real-time model
RT_MODEL_testConnexion_T testConnexion_M_ = RT_MODEL_testConnexion_T();
RT_MODEL_testConnexion_T *const testConnexion_M = &testConnexion_M_;

// Forward declaration for local functions
static void matlabCodegenHandle_matlabCodeg(ros_slros_internal_block_Publ_T *obj);
static void matlabCodegenHandle_matlabCodeg(ros_slros_internal_block_Publ_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

// Model step function
void testConnexion_step(void)
{
  SL_Bus_testConnexion_geometry_msgs_Point rtb_BusAssignment;

  // BusAssignment: '<Root>/Bus Assignment' incorporates:
  //   Constant: '<Root>/Constant'
  //   Constant: '<Root>/Constant1'
  //   Constant: '<Root>/Constant2'

  rtb_BusAssignment.X = testConnexion_P.Constant_Value_f;
  rtb_BusAssignment.Y = testConnexion_P.Constant1_Value;
  rtb_BusAssignment.Z = testConnexion_P.Constant2_Value;

  // Outputs for Atomic SubSystem: '<Root>/Publish'
  // MATLABSystem: '<S2>/SinkBlock'
  Pub_testConnexion_2.publish(&rtb_BusAssignment);

  // End of Outputs for SubSystem: '<Root>/Publish'

  // External mode
  rtExtModeUploadCheckTrigger(1);

  {                                    // Sample time: [1.0s, 0.0s]
    rtExtModeUpload(0, (real_T)testConnexion_M->Timing.taskTime0);
  }

  // signal main to stop simulation
  {                                    // Sample time: [1.0s, 0.0s]
    if ((rtmGetTFinal(testConnexion_M)!=-1) &&
        !((rtmGetTFinal(testConnexion_M)-testConnexion_M->Timing.taskTime0) >
          testConnexion_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(testConnexion_M, "Simulation finished");
    }

    if (rtmGetStopRequested(testConnexion_M)) {
      rtmSetErrorStatus(testConnexion_M, "Simulation finished");
    }
  }

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  testConnexion_M->Timing.taskTime0 =
    ((time_T)(++testConnexion_M->Timing.clockTick0)) *
    testConnexion_M->Timing.stepSize0;
}

// Model initialize function
void testConnexion_initialize(void)
{
  // Registration code
  rtmSetTFinal(testConnexion_M, 10.0);
  testConnexion_M->Timing.stepSize0 = 1.0;

  // External mode info
  testConnexion_M->Sizes.checksums[0] = (3426549828U);
  testConnexion_M->Sizes.checksums[1] = (730753911U);
  testConnexion_M->Sizes.checksums[2] = (3954507093U);
  testConnexion_M->Sizes.checksums[3] = (2454990301U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    testConnexion_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(testConnexion_M->extModeInfo,
      &testConnexion_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(testConnexion_M->extModeInfo,
                        testConnexion_M->Sizes.checksums);
    rteiSetTPtr(testConnexion_M->extModeInfo, rtmGetTPtr(testConnexion_M));
  }

  // data type transition information
  {
    static DataTypeTransInfo dtInfo;
    testConnexion_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    // Block I/O transition table
    dtInfo.BTransTable = &rtBTransTable;

    // Parameters transition table
    dtInfo.PTransTable = &rtPTransTable;
  }

  {
    char_T tmp[10];
    int32_T i;
    static const char_T tmp_0[9] = { '/', 'm', 'y', '_', 't', 'o', 'p', 'i', 'c'
    };

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish'
    // Start for MATLABSystem: '<S2>/SinkBlock'
    testConnexion_DW.obj.matlabCodegenIsDeleted = false;
    testConnexion_DW.obj.isInitialized = 1;
    for (i = 0; i < 9; i++) {
      tmp[i] = tmp_0[i];
    }

    tmp[9] = '\x00';
    Pub_testConnexion_2.createPublisher(tmp, 1);
    testConnexion_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S2>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish'
  }
}

// Model terminate function
void testConnexion_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Publish'
  // Terminate for MATLABSystem: '<S2>/SinkBlock'
  matlabCodegenHandle_matlabCodeg(&testConnexion_DW.obj);

  // End of Terminate for SubSystem: '<Root>/Publish'
}

//
// File trailer for generated code.
//
// [EOF]
//
