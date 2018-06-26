#ifndef __c5_CTRNNSLSF_h__
#define __c5_CTRNNSLSF_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc5_CTRNNSLSFInstanceStruct
#define typedef_SFc5_CTRNNSLSFInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c5_sfEvent;
  uint8_T c5_tp_Falling;
  boolean_T c5_stateChanged;
  real_T c5_lastMajorTime;
  boolean_T c5_doneDoubleBufferReInit;
  uint8_T c5_is_active_c5_CTRNNSLSF;
  uint8_T c5_is_c5_CTRNNSLSF;
  boolean_T c5_dataWrittenToVector[10];
  uint8_T c5_doSetSimStateSideEffects;
  const mxArray *c5_setSimStateSideEffectsInfo;
  void *c5_fEmlrtCtx;
  real_T *c5_x1;
  real_T *c5_x2;
  real_T *c5_x3;
  real_T *c5_x4;
  real_T *c5_x5;
  real_T *c5_x1_out;
  real_T *c5_x2_out;
  real_T *c5_x3_out;
  real_T *c5_x4_out;
  real_T *c5_x5_out;
  real_T *c5_x10;
  real_T *c5_x20;
} SFc5_CTRNNSLSFInstanceStruct;

#endif                                 /*typedef_SFc5_CTRNNSLSFInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c5_CTRNNSLSF_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c5_CTRNNSLSF_get_check_sum(mxArray *plhs[]);
extern void c5_CTRNNSLSF_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
