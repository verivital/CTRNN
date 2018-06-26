#ifndef __c1_CTRNNSLSF_h__
#define __c1_CTRNNSLSF_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc1_CTRNNSLSFInstanceStruct
#define typedef_SFc1_CTRNNSLSFInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  uint8_T c1_tp_Pendulum;
  boolean_T c1_stateChanged;
  real_T c1_lastMajorTime;
  boolean_T c1_doneDoubleBufferReInit;
  uint8_T c1_is_active_c1_CTRNNSLSF;
  uint8_T c1_is_c1_CTRNNSLSF;
  boolean_T c1_dataWrittenToVector[3];
  uint8_T c1_doSetSimStateSideEffects;
  const mxArray *c1_setSimStateSideEffectsInfo;
  void *c1_fEmlrtCtx;
  real_T *c1_u;
  real_T *c1_x1;
  real_T *c1_x2;
  real_T *c1_x1_out;
} SFc1_CTRNNSLSFInstanceStruct;

#endif                                 /*typedef_SFc1_CTRNNSLSFInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c1_CTRNNSLSF_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_CTRNNSLSF_get_check_sum(mxArray *plhs[]);
extern void c1_CTRNNSLSF_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
