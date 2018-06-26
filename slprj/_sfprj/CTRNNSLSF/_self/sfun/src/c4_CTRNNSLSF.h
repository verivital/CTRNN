#ifndef __c4_CTRNNSLSF_h__
#define __c4_CTRNNSLSF_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc4_CTRNNSLSFInstanceStruct
#define typedef_SFc4_CTRNNSLSFInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c4_sfEvent;
  uint8_T c4_tp_Falling;
  boolean_T c4_stateChanged;
  real_T c4_lastMajorTime;
  boolean_T c4_doneDoubleBufferReInit;
  uint8_T c4_is_active_c4_CTRNNSLSF;
  uint8_T c4_is_c4_CTRNNSLSF;
  boolean_T c4_dataWrittenToVector[3];
  uint8_T c4_doSetSimStateSideEffects;
  const mxArray *c4_setSimStateSideEffectsInfo;
  void *c4_fEmlrtCtx;
  real_T *c4_u;
  real_T *c4_x1;
  real_T *c4_x2;
  real_T *c4_x1_out;
} SFc4_CTRNNSLSFInstanceStruct;

#endif                                 /*typedef_SFc4_CTRNNSLSFInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c4_CTRNNSLSF_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c4_CTRNNSLSF_get_check_sum(mxArray *plhs[]);
extern void c4_CTRNNSLSF_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
