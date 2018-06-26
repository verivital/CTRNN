#ifndef __c3_CTRNNSLSF_h__
#define __c3_CTRNNSLSF_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc3_CTRNNSLSFInstanceStruct
#define typedef_SFc3_CTRNNSLSFInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c3_sfEvent;
  uint8_T c3_tp_Falling;
  boolean_T c3_stateChanged;
  real_T c3_lastMajorTime;
  boolean_T c3_doneDoubleBufferReInit;
  uint8_T c3_is_active_c3_CTRNNSLSF;
  uint8_T c3_is_c3_CTRNNSLSF;
  boolean_T c3_dataWrittenToVector[6];
  uint8_T c3_doSetSimStateSideEffects;
  const mxArray *c3_setSimStateSideEffectsInfo;
  void *c3_fEmlrtCtx;
  real_T *c3_u;
  real_T *c3_x1;
  real_T *c3_x2;
  real_T *c3_x3;
  real_T *c3_x4;
  real_T *c3_x5;
  real_T *c3_x1_out;
} SFc3_CTRNNSLSFInstanceStruct;

#endif                                 /*typedef_SFc3_CTRNNSLSFInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_CTRNNSLSF_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_CTRNNSLSF_get_check_sum(mxArray *plhs[]);
extern void c3_CTRNNSLSF_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
