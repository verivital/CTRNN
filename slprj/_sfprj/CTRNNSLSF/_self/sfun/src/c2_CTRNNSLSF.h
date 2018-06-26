#ifndef __c2_CTRNNSLSF_h__
#define __c2_CTRNNSLSF_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc2_CTRNNSLSFInstanceStruct
#define typedef_SFc2_CTRNNSLSFInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c2_sfEvent;
  uint8_T c2_tp_RNN;
  boolean_T c2_stateChanged;
  real_T c2_lastMajorTime;
  boolean_T c2_doneDoubleBufferReInit;
  uint8_T c2_is_active_c2_CTRNNSLSF;
  uint8_T c2_is_c2_CTRNNSLSF;
  boolean_T c2_dataWrittenToVector[10];
  uint8_T c2_doSetSimStateSideEffects;
  const mxArray *c2_setSimStateSideEffectsInfo;
  void *c2_fEmlrtCtx;
  real_T *c2_u;
  real_T *c2_x1;
  real_T *c2_x2;
  real_T *c2_x3;
  real_T *c2_x4;
  real_T *c2_x5;
  real_T *c2_x1_out;
  real_T *c2_x2_out;
  real_T *c2_x3_out;
  real_T *c2_x4_out;
  real_T *c2_x5_out;
} SFc2_CTRNNSLSFInstanceStruct;

#endif                                 /*typedef_SFc2_CTRNNSLSFInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c2_CTRNNSLSF_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c2_CTRNNSLSF_get_check_sum(mxArray *plhs[]);
extern void c2_CTRNNSLSF_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
