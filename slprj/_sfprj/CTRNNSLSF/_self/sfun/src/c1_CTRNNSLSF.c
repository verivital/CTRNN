/* Include files */

#include "CTRNNSLSF_sfun.h"
#include "c1_CTRNNSLSF.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "CTRNNSLSF_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c_with_debugger(S, sfGlobalDebugInstanceStruct);

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);
static const mxArray* sf_opaque_get_hover_data_for_msg(void *chartInstance,
  int32_T msgSSID);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c1_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c1_IN_Pendulum                 ((uint8_T)1U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c1_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_b_debug_family_names[2] = { "nargin", "nargout" };

/* Function Declarations */
static void initialize_c1_CTRNNSLSF(SFc1_CTRNNSLSFInstanceStruct *chartInstance);
static void initialize_params_c1_CTRNNSLSF(SFc1_CTRNNSLSFInstanceStruct
  *chartInstance);
static void enable_c1_CTRNNSLSF(SFc1_CTRNNSLSFInstanceStruct *chartInstance);
static void disable_c1_CTRNNSLSF(SFc1_CTRNNSLSFInstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_CTRNNSLSF(SFc1_CTRNNSLSFInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c1_CTRNNSLSF(SFc1_CTRNNSLSFInstanceStruct
  *chartInstance);
static void set_sim_state_c1_CTRNNSLSF(SFc1_CTRNNSLSFInstanceStruct
  *chartInstance, const mxArray *c1_st);
static void c1_set_sim_state_side_effects_c1_CTRNNSLSF
  (SFc1_CTRNNSLSFInstanceStruct *chartInstance);
static void finalize_c1_CTRNNSLSF(SFc1_CTRNNSLSFInstanceStruct *chartInstance);
static void sf_gateway_c1_CTRNNSLSF(SFc1_CTRNNSLSFInstanceStruct *chartInstance);
static void mdl_start_c1_CTRNNSLSF(SFc1_CTRNNSLSFInstanceStruct *chartInstance);
static void zeroCrossings_c1_CTRNNSLSF(SFc1_CTRNNSLSFInstanceStruct
  *chartInstance);
static void derivatives_c1_CTRNNSLSF(SFc1_CTRNNSLSFInstanceStruct *chartInstance);
static void outputs_c1_CTRNNSLSF(SFc1_CTRNNSLSFInstanceStruct *chartInstance);
static void initSimStructsc1_CTRNNSLSF(SFc1_CTRNNSLSFInstanceStruct
  *chartInstance);
static void c1_eml_ini_fcn_to_be_inlined_22(SFc1_CTRNNSLSFInstanceStruct
  *chartInstance);
static void c1_eml_term_fcn_to_be_inlined_22(SFc1_CTRNNSLSFInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber);
static const mxArray *c1_emlrt_marshallOut(SFc1_CTRNNSLSFInstanceStruct
  *chartInstance, const real_T c1_b_u);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static real_T c1_emlrt_marshallIn(SFc1_CTRNNSLSFInstanceStruct *chartInstance,
  const mxArray *c1_nargout, const char_T *c1_identifier);
static real_T c1_b_emlrt_marshallIn(SFc1_CTRNNSLSFInstanceStruct *chartInstance,
  const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_emlrt_marshallOut(SFc1_CTRNNSLSFInstanceStruct
  *chartInstance, const int32_T c1_b_u);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_c_emlrt_marshallIn(SFc1_CTRNNSLSFInstanceStruct *chartInstance,
  const mxArray *c1_b_sfEvent, const char_T *c1_identifier);
static int32_T c1_d_emlrt_marshallIn(SFc1_CTRNNSLSFInstanceStruct *chartInstance,
  const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_c_emlrt_marshallOut(SFc1_CTRNNSLSFInstanceStruct
  *chartInstance, const uint8_T c1_b_u);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static uint8_T c1_e_emlrt_marshallIn(SFc1_CTRNNSLSFInstanceStruct *chartInstance,
  const mxArray *c1_b_tp_Pendulum, const char_T *c1_identifier);
static uint8_T c1_f_emlrt_marshallIn(SFc1_CTRNNSLSFInstanceStruct *chartInstance,
  const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_d_emlrt_marshallOut(SFc1_CTRNNSLSFInstanceStruct
  *chartInstance);
static const mxArray *c1_e_emlrt_marshallOut(SFc1_CTRNNSLSFInstanceStruct
  *chartInstance, const boolean_T c1_b_u[3]);
static void c1_g_emlrt_marshallIn(SFc1_CTRNNSLSFInstanceStruct *chartInstance,
  const mxArray *c1_b_u);
static void c1_h_emlrt_marshallIn(SFc1_CTRNNSLSFInstanceStruct *chartInstance,
  const mxArray *c1_b_dataWrittenToVector, const char_T *c1_identifier,
  boolean_T c1_y[3]);
static void c1_i_emlrt_marshallIn(SFc1_CTRNNSLSFInstanceStruct *chartInstance,
  const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId, boolean_T c1_y[3]);
static const mxArray *c1_j_emlrt_marshallIn(SFc1_CTRNNSLSFInstanceStruct
  *chartInstance, const mxArray *c1_b_setSimStateSideEffectsInfo, const char_T
  *c1_identifier);
static const mxArray *c1_k_emlrt_marshallIn(SFc1_CTRNNSLSFInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId);
static const mxArray *sf_get_hover_data_for_msg(SFc1_CTRNNSLSFInstanceStruct
  *chartInstance, int32_T c1_ssid);
static void c1_init_sf_message_store_memory(SFc1_CTRNNSLSFInstanceStruct
  *chartInstance);
static void init_dsm_address_info(SFc1_CTRNNSLSFInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc1_CTRNNSLSFInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c1_CTRNNSLSF(SFc1_CTRNNSLSFInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[2];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 0.0;
  if (sf_is_first_init_cond(chartInstance->S)) {
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c1_doSetSimStateSideEffects = 0U;
  chartInstance->c1_setSimStateSideEffectsInfo = NULL;
  chartInstance->c1_tp_Pendulum = 0U;
  chartInstance->c1_is_active_c1_CTRNNSLSF = 0U;
  chartInstance->c1_is_c1_CTRNNSLSF = c1_IN_NO_ACTIVE_CHILD;
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  chartInstance->c1_stateChanged = true;
  chartInstance->c1_is_active_c1_CTRNNSLSF = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_b_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  *chartInstance->c1_x1 = 0.0;
  chartInstance->c1_dataWrittenToVector[0U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c1_x1, 0U, 5U, 0U,
                        chartInstance->c1_sfEvent, false);
  *chartInstance->c1_x2 = 0.0;
  chartInstance->c1_dataWrittenToVector[1U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c1_x2, 1U, 5U, 0U,
                        chartInstance->c1_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  chartInstance->c1_stateChanged = true;
  chartInstance->c1_is_c1_CTRNNSLSF = c1_IN_Pendulum;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  chartInstance->c1_tp_Pendulum = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_CTRNNSLSFMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initialize_params_c1_CTRNNSLSF(SFc1_CTRNNSLSFInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c1_CTRNNSLSF(SFc1_CTRNNSLSFInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c1_CTRNNSLSF(SFc1_CTRNNSLSFInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c1_update_debugger_state_c1_CTRNNSLSF(SFc1_CTRNNSLSFInstanceStruct
  *chartInstance)
{
  uint32_T c1_prevAniVal;
  c1_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c1_is_active_c1_CTRNNSLSF == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_c1_CTRNNSLSF == c1_IN_Pendulum) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  }

  _SFD_SET_ANIMATION(c1_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c1_CTRNNSLSF(SFc1_CTRNNSLSFInstanceStruct
  *chartInstance)
{
  const mxArray *c1_st = NULL;
  c1_st = NULL;
  sf_mex_assign(&c1_st, c1_d_emlrt_marshallOut(chartInstance), false);
  return c1_st;
}

static void set_sim_state_c1_CTRNNSLSF(SFc1_CTRNNSLSFInstanceStruct
  *chartInstance, const mxArray *c1_st)
{
  chartInstance->c1_doneDoubleBufferReInit = true;
  c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_st));
  chartInstance->c1_doSetSimStateSideEffects = 1U;
  c1_update_debugger_state_c1_CTRNNSLSF(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void c1_set_sim_state_side_effects_c1_CTRNNSLSF
  (SFc1_CTRNNSLSFInstanceStruct *chartInstance)
{
  if (chartInstance->c1_doSetSimStateSideEffects != 0) {
    chartInstance->c1_tp_Pendulum = (uint8_T)(chartInstance->c1_is_c1_CTRNNSLSF ==
      c1_IN_Pendulum);
    chartInstance->c1_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c1_CTRNNSLSF(SFc1_CTRNNSLSFInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c1_setSimStateSideEffectsInfo);
}

static void sf_gateway_c1_CTRNNSLSF(SFc1_CTRNNSLSFInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[2];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 0.0;
  c1_set_sim_state_side_effects_c1_CTRNNSLSF(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  if (ssIsMajorTimeStep(chartInstance->S) != 0U) {
    chartInstance->c1_lastMajorTime = _sfTime_;
    chartInstance->c1_stateChanged = (boolean_T)0;
    _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c1_u, 2U, 1U, 0U,
                          chartInstance->c1_sfEvent, false);
    chartInstance->c1_sfEvent = CALL_EVENT;
    *chartInstance->c1_x1_out = 0.0;
    chartInstance->c1_dataWrittenToVector[2U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c1_x1_out, 3U, 1U, 0U,
                          chartInstance->c1_sfEvent, false);
    _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    if (chartInstance->c1_stateChanged) {
      ssSetSolverNeedsReset(chartInstance->S);
    }
  }

  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  if (!chartInstance->c1_dataWrittenToVector[1U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 0U, chartInstance->c1_sfEvent,
      false);
  }

  if (!chartInstance->c1_dataWrittenToVector[0U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 0U, chartInstance->c1_sfEvent,
      false);
  }

  if (!chartInstance->c1_dataWrittenToVector[1U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 0U, chartInstance->c1_sfEvent,
      false);
  }

  if (!chartInstance->c1_dataWrittenToVector[0U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 0U, chartInstance->c1_sfEvent,
      false);
  }

  *chartInstance->c1_x1_out = *chartInstance->c1_x1;
  chartInstance->c1_dataWrittenToVector[2U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c1_x1_out, 3U, 4U, 0U,
                        chartInstance->c1_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_CTRNNSLSFMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c1_CTRNNSLSF(SFc1_CTRNNSLSFInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void zeroCrossings_c1_CTRNNSLSF(SFc1_CTRNNSLSFInstanceStruct
  *chartInstance)
{
  real_T *c1_zcVar;
  c1_zcVar = (real_T *)(ssGetNonsampledZCs_wrapper(chartInstance->S) + 0);
  _sfTime_ = sf_get_time(chartInstance->S);
  if (chartInstance->c1_lastMajorTime == _sfTime_) {
    *c1_zcVar = -1.0;
  } else {
    chartInstance->c1_stateChanged = (boolean_T)0;
    if (chartInstance->c1_stateChanged) {
      *c1_zcVar = 1.0;
    } else {
      *c1_zcVar = -1.0;
    }
  }
}

static void derivatives_c1_CTRNNSLSF(SFc1_CTRNNSLSFInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[2];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 0.0;
  real_T *c1_x1_dot;
  real_T *c1_x2_dot;
  c1_x2_dot = (real_T *)(ssGetdX_wrapper(chartInstance->S) + 1);
  c1_x1_dot = (real_T *)(ssGetdX_wrapper(chartInstance->S) + 0);
  *c1_x1_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c1_x1_dot, 0U, 1U, 0U, chartInstance->c1_sfEvent, false);
  *c1_x2_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c1_x2_dot, 1U, 1U, 0U, chartInstance->c1_sfEvent, false);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  if (!chartInstance->c1_dataWrittenToVector[1U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 0U, chartInstance->c1_sfEvent,
      false);
  }

  *c1_x1_dot = *chartInstance->c1_x2;
  _SFD_DATA_RANGE_CHECK(*c1_x1_dot, 0U, 4U, 0U, chartInstance->c1_sfEvent, false);
  if (!chartInstance->c1_dataWrittenToVector[0U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 0U, chartInstance->c1_sfEvent,
      false);
  }

  if (!chartInstance->c1_dataWrittenToVector[1U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 0U, chartInstance->c1_sfEvent,
      false);
  }

  *c1_x2_dot = (-9.81 * *chartInstance->c1_x1 - 0.5 * *chartInstance->c1_x2) +
    0.5 * *chartInstance->c1_u;
  _SFD_DATA_RANGE_CHECK(*c1_x2_dot, 1U, 4U, 0U, chartInstance->c1_sfEvent, false);
  if (!chartInstance->c1_dataWrittenToVector[0U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 0U, chartInstance->c1_sfEvent,
      false);
  }

  chartInstance->c1_dataWrittenToVector[2U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c1_x1_out, 3U, 4U, 0U,
                        chartInstance->c1_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
}

static void outputs_c1_CTRNNSLSF(SFc1_CTRNNSLSFInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[2];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 0.0;
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  if (!chartInstance->c1_dataWrittenToVector[1U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 0U, chartInstance->c1_sfEvent,
      false);
  }

  if (!chartInstance->c1_dataWrittenToVector[0U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 0U, chartInstance->c1_sfEvent,
      false);
  }

  if (!chartInstance->c1_dataWrittenToVector[1U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 0U, chartInstance->c1_sfEvent,
      false);
  }

  if (!chartInstance->c1_dataWrittenToVector[0U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 0U, chartInstance->c1_sfEvent,
      false);
  }

  *chartInstance->c1_x1_out = *chartInstance->c1_x1;
  chartInstance->c1_dataWrittenToVector[2U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c1_x1_out, 3U, 4U, 0U,
                        chartInstance->c1_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
}

static void initSimStructsc1_CTRNNSLSF(SFc1_CTRNNSLSFInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c1_eml_ini_fcn_to_be_inlined_22(SFc1_CTRNNSLSFInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c1_eml_term_fcn_to_be_inlined_22(SFc1_CTRNNSLSFInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber)
{
  (void)(c1_machineNumber);
  (void)(c1_chartNumber);
  (void)(c1_instanceNumber);
}

static const mxArray *c1_emlrt_marshallOut(SFc1_CTRNNSLSFInstanceStruct
  *chartInstance, const real_T c1_b_u)
{
  const mxArray *c1_y = NULL;
  (void)chartInstance;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0), false);
  return c1_y;
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  SFc1_CTRNNSLSFInstanceStruct *chartInstance;
  chartInstance = (SFc1_CTRNNSLSFInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  sf_mex_assign(&c1_mxArrayOutData, c1_emlrt_marshallOut(chartInstance, *(real_T
    *)c1_inData), false);
  return c1_mxArrayOutData;
}

static real_T c1_emlrt_marshallIn(SFc1_CTRNNSLSFInstanceStruct *chartInstance,
  const mxArray *c1_nargout, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nargout), &c1_thisId);
  sf_mex_destroy(&c1_nargout);
  return c1_y;
}

static real_T c1_b_emlrt_marshallIn(SFc1_CTRNNSLSFInstanceStruct *chartInstance,
  const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_b_u);
  return c1_y;
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  SFc1_CTRNNSLSFInstanceStruct *chartInstance;
  chartInstance = (SFc1_CTRNNSLSFInstanceStruct *)chartInstanceVoid;
  *(real_T *)c1_outData = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_mxArrayInData), c1_varName);
  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_CTRNNSLSF_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c1_nameCaptureInfo;
}

static const mxArray *c1_b_emlrt_marshallOut(SFc1_CTRNNSLSFInstanceStruct
  *chartInstance, const int32_T c1_b_u)
{
  const mxArray *c1_y = NULL;
  (void)chartInstance;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_b_u, 6, 0U, 0U, 0U, 0), false);
  return c1_y;
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  SFc1_CTRNNSLSFInstanceStruct *chartInstance;
  chartInstance = (SFc1_CTRNNSLSFInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  sf_mex_assign(&c1_mxArrayOutData, c1_b_emlrt_marshallOut(chartInstance,
    *(int32_T *)c1_inData), false);
  return c1_mxArrayOutData;
}

static int32_T c1_c_emlrt_marshallIn(SFc1_CTRNNSLSFInstanceStruct *chartInstance,
  const mxArray *c1_b_sfEvent, const char_T *c1_identifier)
{
  int32_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  return c1_y;
}

static int32_T c1_d_emlrt_marshallIn(SFc1_CTRNNSLSFInstanceStruct *chartInstance,
  const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), &c1_i0, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i0;
  sf_mex_destroy(&c1_b_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  SFc1_CTRNNSLSFInstanceStruct *chartInstance;
  chartInstance = (SFc1_CTRNNSLSFInstanceStruct *)chartInstanceVoid;
  *(int32_T *)c1_outData = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_mxArrayInData), c1_varName);
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_c_emlrt_marshallOut(SFc1_CTRNNSLSFInstanceStruct
  *chartInstance, const uint8_T c1_b_u)
{
  const mxArray *c1_y = NULL;
  (void)chartInstance;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_b_u, 3, 0U, 0U, 0U, 0), false);
  return c1_y;
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  SFc1_CTRNNSLSFInstanceStruct *chartInstance;
  chartInstance = (SFc1_CTRNNSLSFInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  sf_mex_assign(&c1_mxArrayOutData, c1_c_emlrt_marshallOut(chartInstance,
    *(uint8_T *)c1_inData), false);
  return c1_mxArrayOutData;
}

static uint8_T c1_e_emlrt_marshallIn(SFc1_CTRNNSLSFInstanceStruct *chartInstance,
  const mxArray *c1_b_tp_Pendulum, const char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_tp_Pendulum),
    &c1_thisId);
  sf_mex_destroy(&c1_b_tp_Pendulum);
  return c1_y;
}

static uint8_T c1_f_emlrt_marshallIn(SFc1_CTRNNSLSFInstanceStruct *chartInstance,
  const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_b_u);
  return c1_y;
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  SFc1_CTRNNSLSFInstanceStruct *chartInstance;
  chartInstance = (SFc1_CTRNNSLSFInstanceStruct *)chartInstanceVoid;
  *(uint8_T *)c1_outData = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_mxArrayInData), c1_varName);
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_d_emlrt_marshallOut(SFc1_CTRNNSLSFInstanceStruct
  *chartInstance)
{
  const mxArray *c1_y;
  int32_T c1_i1;
  boolean_T c1_bv0[3];
  c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellmatrix(6, 1), false);
  sf_mex_setcell(c1_y, 0, c1_emlrt_marshallOut(chartInstance,
    *chartInstance->c1_x1_out));
  sf_mex_setcell(c1_y, 1, c1_emlrt_marshallOut(chartInstance,
    *chartInstance->c1_x1));
  sf_mex_setcell(c1_y, 2, c1_emlrt_marshallOut(chartInstance,
    *chartInstance->c1_x2));
  sf_mex_setcell(c1_y, 3, c1_c_emlrt_marshallOut(chartInstance,
    chartInstance->c1_is_active_c1_CTRNNSLSF));
  sf_mex_setcell(c1_y, 4, c1_c_emlrt_marshallOut(chartInstance,
    chartInstance->c1_is_c1_CTRNNSLSF));
  for (c1_i1 = 0; c1_i1 < 3; c1_i1++) {
    c1_bv0[c1_i1] = chartInstance->c1_dataWrittenToVector[c1_i1];
  }

  sf_mex_setcell(c1_y, 5, c1_e_emlrt_marshallOut(chartInstance, c1_bv0));
  return c1_y;
}

static const mxArray *c1_e_emlrt_marshallOut(SFc1_CTRNNSLSFInstanceStruct
  *chartInstance, const boolean_T c1_b_u[3])
{
  const mxArray *c1_y = NULL;
  (void)chartInstance;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_b_u, 11, 0U, 1U, 0U, 1, 3), false);
  return c1_y;
}

static void c1_g_emlrt_marshallIn(SFc1_CTRNNSLSFInstanceStruct *chartInstance,
  const mxArray *c1_b_u)
{
  boolean_T c1_bv1[3];
  int32_T c1_i2;
  *chartInstance->c1_x1_out = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("x1_out", c1_b_u, 0)), "x1_out");
  *chartInstance->c1_x1 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("x1", c1_b_u, 1)), "x1");
  *chartInstance->c1_x2 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("x2", c1_b_u, 2)), "x2");
  chartInstance->c1_is_active_c1_CTRNNSLSF = c1_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_active_c1_CTRNNSLSF", c1_b_u, 3)),
    "is_active_c1_CTRNNSLSF");
  chartInstance->c1_is_c1_CTRNNSLSF = c1_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_c1_CTRNNSLSF", c1_b_u, 4)), "is_c1_CTRNNSLSF");
  c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "dataWrittenToVector", c1_b_u, 5)), "dataWrittenToVector", c1_bv1);
  for (c1_i2 = 0; c1_i2 < 3; c1_i2++) {
    chartInstance->c1_dataWrittenToVector[c1_i2] = c1_bv1[c1_i2];
  }

  sf_mex_assign(&chartInstance->c1_setSimStateSideEffectsInfo,
                c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "setSimStateSideEffectsInfo", c1_b_u, 6)), "setSimStateSideEffectsInfo"),
                true);
  sf_mex_destroy(&c1_b_u);
}

static void c1_h_emlrt_marshallIn(SFc1_CTRNNSLSFInstanceStruct *chartInstance,
  const mxArray *c1_b_dataWrittenToVector, const char_T *c1_identifier,
  boolean_T c1_y[3])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_dataWrittenToVector),
                        &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_dataWrittenToVector);
}

static void c1_i_emlrt_marshallIn(SFc1_CTRNNSLSFInstanceStruct *chartInstance,
  const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId, boolean_T c1_y[3])
{
  boolean_T c1_bv2[3];
  int32_T c1_i3;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), c1_bv2, 1, 11, 0U, 1, 0U, 1, 3);
  for (c1_i3 = 0; c1_i3 < 3; c1_i3++) {
    c1_y[c1_i3] = c1_bv2[c1_i3];
  }

  sf_mex_destroy(&c1_b_u);
}

static const mxArray *c1_j_emlrt_marshallIn(SFc1_CTRNNSLSFInstanceStruct
  *chartInstance, const mxArray *c1_b_setSimStateSideEffectsInfo, const char_T
  *c1_identifier)
{
  const mxArray *c1_y = NULL;
  emlrtMsgIdentifier c1_thisId;
  c1_y = NULL;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  sf_mex_assign(&c1_y, c1_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_setSimStateSideEffectsInfo), &c1_thisId), false);
  sf_mex_destroy(&c1_b_setSimStateSideEffectsInfo);
  return c1_y;
}

static const mxArray *c1_k_emlrt_marshallIn(SFc1_CTRNNSLSFInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId)
{
  const mxArray *c1_y = NULL;
  (void)chartInstance;
  (void)c1_parentId;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_duplicatearraysafe(&c1_b_u), false);
  sf_mex_destroy(&c1_b_u);
  return c1_y;
}

static const mxArray *sf_get_hover_data_for_msg(SFc1_CTRNNSLSFInstanceStruct
  *chartInstance, int32_T c1_ssid)
{
  const mxArray *c1_msgInfo;
  (void)chartInstance;
  (void)c1_ssid;
  c1_msgInfo = NULL;
  return NULL;
}

static void c1_init_sf_message_store_memory(SFc1_CTRNNSLSFInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_dsm_address_info(SFc1_CTRNNSLSFInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc1_CTRNNSLSFInstanceStruct *chartInstance)
{
  chartInstance->c1_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c1_u = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    0);
  chartInstance->c1_x1 = (real_T *)(ssGetContStates_wrapper(chartInstance->S) +
    0);
  chartInstance->c1_x2 = (real_T *)(ssGetContStates_wrapper(chartInstance->S) +
    1);
  chartInstance->c1_x1_out = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c1_CTRNNSLSF_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(759033345U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2239981212U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1556103489U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2049202365U);
}

mxArray* sf_c1_CTRNNSLSF_get_post_codegen_info(void);
mxArray *sf_c1_CTRNNSLSF_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("w6VaORY0hML30xhGiBSY8G");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxData);
  }

  {
    mxArray* mxPostCodegenInfo = sf_c1_CTRNNSLSF_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c1_CTRNNSLSF_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c1_CTRNNSLSF_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("early");
  mxArray *fallbackReason = mxCreateString("plant_model_chart");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c1_CTRNNSLSF_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c1_CTRNNSLSF_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c1_CTRNNSLSF(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x6'type','srcId','name','auxInfo'{{M[1],M[12],T\"x1_out\",},{M[5],M[10],T\"x1\",},{M[5],M[11],T\"x2\",},{M[8],M[0],T\"is_active_c1_CTRNNSLSF\",},{M[9],M[0],T\"is_c1_CTRNNSLSF\",},{M[15],M[0],T\"dataWrittenToVector\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 6, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_CTRNNSLSF_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const mxArray* sf_opaque_get_hover_data_for_msg(void* chartInstance,
  int32_T msgSSID)
{
  return sf_get_hover_data_for_msg( (SFc1_CTRNNSLSFInstanceStruct *)
    chartInstance, msgSSID);
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_CTRNNSLSFInstanceStruct *chartInstance = (SFc1_CTRNNSLSFInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _CTRNNSLSFMachineNumber_,
           1,
           1,
           1,
           0,
           4,
           0,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_CTRNNSLSFMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_CTRNNSLSFMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _CTRNNSLSFMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,0,0,0,"x1");
          _SFD_SET_DATA_PROPS(1,0,0,0,"x2");
          _SFD_SET_DATA_PROPS(2,1,1,0,"u");
          _SFD_SET_DATA_PROPS(3,2,0,1,"x1_out");
          _SFD_STATE_INFO(0,0,0);
          _SFD_CH_SUBSTATE_COUNT(1);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_ST_SUBSTATE_COUNT(0,0);
        }

        _SFD_CV_INIT_CHART(1,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(0,0,0,0,0,0,0,0,0,0,0,0);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _CTRNNSLSFMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_CTRNNSLSFInstanceStruct *chartInstance = (SFc1_CTRNNSLSFInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(2U, (void *)chartInstance->c1_u);
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)chartInstance->c1_x1);
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)chartInstance->c1_x2);
        _SFD_SET_DATA_VALUE_PTR(3U, (void *)chartInstance->c1_x1_out);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "ssgVr6IAOaGJ0ipVzgwHi2E";
}

static void sf_opaque_initialize_c1_CTRNNSLSF(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_CTRNNSLSFInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c1_CTRNNSLSF((SFc1_CTRNNSLSFInstanceStruct*)
    chartInstanceVar);
  initialize_c1_CTRNNSLSF((SFc1_CTRNNSLSFInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_CTRNNSLSF(void *chartInstanceVar)
{
  enable_c1_CTRNNSLSF((SFc1_CTRNNSLSFInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_CTRNNSLSF(void *chartInstanceVar)
{
  disable_c1_CTRNNSLSF((SFc1_CTRNNSLSFInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_zeroCrossings_c1_CTRNNSLSF(void *chartInstanceVar)
{
  zeroCrossings_c1_CTRNNSLSF((SFc1_CTRNNSLSFInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_derivatives_c1_CTRNNSLSF(void *chartInstanceVar)
{
  derivatives_c1_CTRNNSLSF((SFc1_CTRNNSLSFInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_outputs_c1_CTRNNSLSF(void *chartInstanceVar)
{
  outputs_c1_CTRNNSLSF((SFc1_CTRNNSLSFInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_CTRNNSLSF(void *chartInstanceVar)
{
  sf_gateway_c1_CTRNNSLSF((SFc1_CTRNNSLSFInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c1_CTRNNSLSF(SimStruct* S)
{
  return get_sim_state_c1_CTRNNSLSF((SFc1_CTRNNSLSFInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c1_CTRNNSLSF(SimStruct* S, const mxArray *st)
{
  set_sim_state_c1_CTRNNSLSF((SFc1_CTRNNSLSFInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c1_CTRNNSLSF(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_CTRNNSLSFInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_CTRNNSLSF_optimization_info();
    }

    finalize_c1_CTRNNSLSF((SFc1_CTRNNSLSFInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_CTRNNSLSF((SFc1_CTRNNSLSFInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_CTRNNSLSF(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_CTRNNSLSF((SFc1_CTRNNSLSFInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c1_CTRNNSLSF(SimStruct *S)
{
  ssSetStatesModifiedOnlyInUpdate(S, 0);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_CTRNNSLSF_optimization_info(sim_mode_is_rtw_gen(S),
      sim_mode_is_modelref_sim(S), sim_mode_is_external(S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,1,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 1);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,1);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetCallsOutputInInitFcn(S,1);
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2670586667U));
  ssSetChecksum1(S,(2214567379U));
  ssSetChecksum2(S,(2293231307U));
  ssSetChecksum3(S,(1082895282U));
  ssSetNumContStates(S,2);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_CTRNNSLSF(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c1_CTRNNSLSF(SimStruct *S)
{
  SFc1_CTRNNSLSFInstanceStruct *chartInstance;
  chartInstance = (SFc1_CTRNNSLSFInstanceStruct *)utMalloc(sizeof
    (SFc1_CTRNNSLSFInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc1_CTRNNSLSFInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c1_CTRNNSLSF;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c1_CTRNNSLSF;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c1_CTRNNSLSF;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_CTRNNSLSF;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_CTRNNSLSF;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c1_CTRNNSLSF;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c1_CTRNNSLSF;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c1_CTRNNSLSF;
  chartInstance->chartInfo.zeroCrossings = sf_opaque_zeroCrossings_c1_CTRNNSLSF;
  chartInstance->chartInfo.outputs = sf_opaque_outputs_c1_CTRNNSLSF;
  chartInstance->chartInfo.derivatives = sf_opaque_derivatives_c1_CTRNNSLSF;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_CTRNNSLSF;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_CTRNNSLSF;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_CTRNNSLSF;
  chartInstance->chartInfo.callGetHoverDataForMsg =
    sf_opaque_get_hover_data_for_msg;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  chart_debug_initialization(S,1);
  mdl_start_c1_CTRNNSLSF(chartInstance);
}

void c1_CTRNNSLSF_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_CTRNNSLSF(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_CTRNNSLSF(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_CTRNNSLSF(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_CTRNNSLSF_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
