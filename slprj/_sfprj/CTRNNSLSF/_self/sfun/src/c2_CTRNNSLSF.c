/* Include files */

#include "CTRNNSLSF_sfun.h"
#include "c2_CTRNNSLSF.h"
#include "mwmathutil.h"
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
#define c2_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c2_IN_RNN                      ((uint8_T)1U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c2_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_b_debug_family_names[2] = { "nargin", "nargout" };

/* Function Declarations */
static void initialize_c2_CTRNNSLSF(SFc2_CTRNNSLSFInstanceStruct *chartInstance);
static void initialize_params_c2_CTRNNSLSF(SFc2_CTRNNSLSFInstanceStruct
  *chartInstance);
static void enable_c2_CTRNNSLSF(SFc2_CTRNNSLSFInstanceStruct *chartInstance);
static void disable_c2_CTRNNSLSF(SFc2_CTRNNSLSFInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_CTRNNSLSF(SFc2_CTRNNSLSFInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c2_CTRNNSLSF(SFc2_CTRNNSLSFInstanceStruct
  *chartInstance);
static void set_sim_state_c2_CTRNNSLSF(SFc2_CTRNNSLSFInstanceStruct
  *chartInstance, const mxArray *c2_st);
static void c2_set_sim_state_side_effects_c2_CTRNNSLSF
  (SFc2_CTRNNSLSFInstanceStruct *chartInstance);
static void finalize_c2_CTRNNSLSF(SFc2_CTRNNSLSFInstanceStruct *chartInstance);
static void sf_gateway_c2_CTRNNSLSF(SFc2_CTRNNSLSFInstanceStruct *chartInstance);
static void mdl_start_c2_CTRNNSLSF(SFc2_CTRNNSLSFInstanceStruct *chartInstance);
static void zeroCrossings_c2_CTRNNSLSF(SFc2_CTRNNSLSFInstanceStruct
  *chartInstance);
static void derivatives_c2_CTRNNSLSF(SFc2_CTRNNSLSFInstanceStruct *chartInstance);
static void outputs_c2_CTRNNSLSF(SFc2_CTRNNSLSFInstanceStruct *chartInstance);
static void initSimStructsc2_CTRNNSLSF(SFc2_CTRNNSLSFInstanceStruct
  *chartInstance);
static void c2_eml_ini_fcn_to_be_inlined_29(SFc2_CTRNNSLSFInstanceStruct
  *chartInstance);
static void c2_eml_term_fcn_to_be_inlined_29(SFc2_CTRNNSLSFInstanceStruct
  *chartInstance);
static real_T c2_tanh(SFc2_CTRNNSLSFInstanceStruct *chartInstance, real_T c2_x);
static real_T c2_applyScalarFunctionInPlace(SFc2_CTRNNSLSFInstanceStruct
  *chartInstance, real_T c2_x);
static real_T c2_b_tanh(SFc2_CTRNNSLSFInstanceStruct *chartInstance, real_T c2_x);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber);
static const mxArray *c2_emlrt_marshallOut(SFc2_CTRNNSLSFInstanceStruct
  *chartInstance, const real_T c2_b_u);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static real_T c2_emlrt_marshallIn(SFc2_CTRNNSLSFInstanceStruct *chartInstance,
  const mxArray *c2_nargout, const char_T *c2_identifier);
static real_T c2_b_emlrt_marshallIn(SFc2_CTRNNSLSFInstanceStruct *chartInstance,
  const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_emlrt_marshallOut(SFc2_CTRNNSLSFInstanceStruct
  *chartInstance, const int32_T c2_b_u);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_c_emlrt_marshallIn(SFc2_CTRNNSLSFInstanceStruct *chartInstance,
  const mxArray *c2_b_sfEvent, const char_T *c2_identifier);
static int32_T c2_d_emlrt_marshallIn(SFc2_CTRNNSLSFInstanceStruct *chartInstance,
  const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_emlrt_marshallOut(SFc2_CTRNNSLSFInstanceStruct
  *chartInstance, const uint8_T c2_b_u);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static uint8_T c2_e_emlrt_marshallIn(SFc2_CTRNNSLSFInstanceStruct *chartInstance,
  const mxArray *c2_b_tp_RNN, const char_T *c2_identifier);
static uint8_T c2_f_emlrt_marshallIn(SFc2_CTRNNSLSFInstanceStruct *chartInstance,
  const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_d_emlrt_marshallOut(SFc2_CTRNNSLSFInstanceStruct
  *chartInstance);
static const mxArray *c2_e_emlrt_marshallOut(SFc2_CTRNNSLSFInstanceStruct
  *chartInstance, const boolean_T c2_b_u[10]);
static void c2_g_emlrt_marshallIn(SFc2_CTRNNSLSFInstanceStruct *chartInstance,
  const mxArray *c2_b_u);
static void c2_h_emlrt_marshallIn(SFc2_CTRNNSLSFInstanceStruct *chartInstance,
  const mxArray *c2_b_dataWrittenToVector, const char_T *c2_identifier,
  boolean_T c2_y[10]);
static void c2_i_emlrt_marshallIn(SFc2_CTRNNSLSFInstanceStruct *chartInstance,
  const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId, boolean_T c2_y
  [10]);
static const mxArray *c2_j_emlrt_marshallIn(SFc2_CTRNNSLSFInstanceStruct
  *chartInstance, const mxArray *c2_b_setSimStateSideEffectsInfo, const char_T
  *c2_identifier);
static const mxArray *c2_k_emlrt_marshallIn(SFc2_CTRNNSLSFInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId);
static const mxArray *sf_get_hover_data_for_msg(SFc2_CTRNNSLSFInstanceStruct
  *chartInstance, int32_T c2_ssid);
static void c2_init_sf_message_store_memory(SFc2_CTRNNSLSFInstanceStruct
  *chartInstance);
static void c2_c_tanh(SFc2_CTRNNSLSFInstanceStruct *chartInstance, real_T *c2_x);
static void c2_b_applyScalarFunctionInPlace(SFc2_CTRNNSLSFInstanceStruct
  *chartInstance, real_T *c2_x);
static void c2_d_tanh(SFc2_CTRNNSLSFInstanceStruct *chartInstance, real_T *c2_x);
static void init_dsm_address_info(SFc2_CTRNNSLSFInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc2_CTRNNSLSFInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_CTRNNSLSF(SFc2_CTRNNSLSFInstanceStruct *chartInstance)
{
  uint32_T c2_debug_family_var_map[2];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 0.0;
  if (sf_is_first_init_cond(chartInstance->S)) {
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c2_doSetSimStateSideEffects = 0U;
  chartInstance->c2_setSimStateSideEffectsInfo = NULL;
  chartInstance->c2_tp_RNN = 0U;
  chartInstance->c2_is_active_c2_CTRNNSLSF = 0U;
  chartInstance->c2_is_c2_CTRNNSLSF = c2_IN_NO_ACTIVE_CHILD;
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  chartInstance->c2_stateChanged = true;
  chartInstance->c2_is_active_c2_CTRNNSLSF = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_b_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  *chartInstance->c2_x1 = -0.0097;
  chartInstance->c2_dataWrittenToVector[0U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_x1, 0U, 5U, 0U,
                        chartInstance->c2_sfEvent, false);
  *chartInstance->c2_x2 = -0.0065;
  chartInstance->c2_dataWrittenToVector[1U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_x2, 1U, 5U, 0U,
                        chartInstance->c2_sfEvent, false);
  *chartInstance->c2_x3 = 0.0171;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_x3, 2U, 5U, 0U,
                        chartInstance->c2_sfEvent, false);
  *chartInstance->c2_x4 = -0.0097;
  chartInstance->c2_dataWrittenToVector[3U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_x4, 3U, 5U, 0U,
                        chartInstance->c2_sfEvent, false);
  *chartInstance->c2_x5 = 0.0025;
  chartInstance->c2_dataWrittenToVector[4U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_x5, 4U, 5U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  chartInstance->c2_stateChanged = true;
  chartInstance->c2_is_c2_CTRNNSLSF = c2_IN_RNN;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_RNN = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_CTRNNSLSFMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initialize_params_c2_CTRNNSLSF(SFc2_CTRNNSLSFInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c2_CTRNNSLSF(SFc2_CTRNNSLSFInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c2_CTRNNSLSF(SFc2_CTRNNSLSFInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c2_update_debugger_state_c2_CTRNNSLSF(SFc2_CTRNNSLSFInstanceStruct
  *chartInstance)
{
  uint32_T c2_prevAniVal;
  c2_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c2_is_active_c2_CTRNNSLSF == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_CTRNNSLSF == c2_IN_RNN) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
  }

  _SFD_SET_ANIMATION(c2_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c2_CTRNNSLSF(SFc2_CTRNNSLSFInstanceStruct
  *chartInstance)
{
  const mxArray *c2_st = NULL;
  c2_st = NULL;
  sf_mex_assign(&c2_st, c2_d_emlrt_marshallOut(chartInstance), false);
  return c2_st;
}

static void set_sim_state_c2_CTRNNSLSF(SFc2_CTRNNSLSFInstanceStruct
  *chartInstance, const mxArray *c2_st)
{
  chartInstance->c2_doneDoubleBufferReInit = true;
  c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_st));
  chartInstance->c2_doSetSimStateSideEffects = 1U;
  c2_update_debugger_state_c2_CTRNNSLSF(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void c2_set_sim_state_side_effects_c2_CTRNNSLSF
  (SFc2_CTRNNSLSFInstanceStruct *chartInstance)
{
  if (chartInstance->c2_doSetSimStateSideEffects != 0) {
    chartInstance->c2_tp_RNN = (uint8_T)(chartInstance->c2_is_c2_CTRNNSLSF ==
      c2_IN_RNN);
    chartInstance->c2_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c2_CTRNNSLSF(SFc2_CTRNNSLSFInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c2_setSimStateSideEffectsInfo);
}

static void sf_gateway_c2_CTRNNSLSF(SFc2_CTRNNSLSFInstanceStruct *chartInstance)
{
  uint32_T c2_debug_family_var_map[2];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 0.0;
  c2_set_sim_state_side_effects_c2_CTRNNSLSF(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  if (ssIsMajorTimeStep(chartInstance->S) != 0U) {
    chartInstance->c2_lastMajorTime = _sfTime_;
    chartInstance->c2_stateChanged = (boolean_T)0;
    _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c2_u, 5U, 1U, 0U,
                          chartInstance->c2_sfEvent, false);
    chartInstance->c2_sfEvent = CALL_EVENT;
    *chartInstance->c2_x1_out = 0.0;
    chartInstance->c2_dataWrittenToVector[5U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c2_x1_out, 6U, 1U, 1U,
                          chartInstance->c2_sfEvent, false);
    *chartInstance->c2_x2_out = 0.0;
    chartInstance->c2_dataWrittenToVector[6U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c2_x2_out, 7U, 1U, 1U,
                          chartInstance->c2_sfEvent, false);
    *chartInstance->c2_x3_out = 0.0;
    chartInstance->c2_dataWrittenToVector[7U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c2_x3_out, 8U, 1U, 1U,
                          chartInstance->c2_sfEvent, false);
    *chartInstance->c2_x4_out = 0.0;
    chartInstance->c2_dataWrittenToVector[8U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c2_x4_out, 9U, 1U, 1U,
                          chartInstance->c2_sfEvent, false);
    *chartInstance->c2_x5_out = 0.0;
    chartInstance->c2_dataWrittenToVector[9U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c2_x5_out, 10U, 1U, 1U,
                          chartInstance->c2_sfEvent, false);
    _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
    if (chartInstance->c2_stateChanged) {
      ssSetSolverNeedsReset(chartInstance->S);
    }
  }

  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  if (!chartInstance->c2_dataWrittenToVector[0U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[1U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[2U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[3U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[4U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  chartInstance->c2_dataWrittenToVector[0U] = true;
  if (!chartInstance->c2_dataWrittenToVector[1U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[0U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[2U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[3U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[4U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  chartInstance->c2_dataWrittenToVector[1U] = true;
  if (!chartInstance->c2_dataWrittenToVector[2U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[0U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[1U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[3U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[4U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  chartInstance->c2_dataWrittenToVector[2U] = true;
  if (!chartInstance->c2_dataWrittenToVector[3U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[0U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[1U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[2U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[4U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  chartInstance->c2_dataWrittenToVector[3U] = true;
  if (!chartInstance->c2_dataWrittenToVector[4U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[0U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[1U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[2U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[3U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  chartInstance->c2_dataWrittenToVector[4U] = true;
  if (!chartInstance->c2_dataWrittenToVector[0U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  *chartInstance->c2_x1_out = *chartInstance->c2_x1;
  chartInstance->c2_dataWrittenToVector[5U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_x1_out, 6U, 4U, 0U,
                        chartInstance->c2_sfEvent, false);
  if (!chartInstance->c2_dataWrittenToVector[1U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  *chartInstance->c2_x2_out = *chartInstance->c2_x2;
  chartInstance->c2_dataWrittenToVector[6U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_x2_out, 7U, 4U, 0U,
                        chartInstance->c2_sfEvent, false);
  if (!chartInstance->c2_dataWrittenToVector[2U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  *chartInstance->c2_x3_out = *chartInstance->c2_x3;
  chartInstance->c2_dataWrittenToVector[7U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_x3_out, 8U, 4U, 0U,
                        chartInstance->c2_sfEvent, false);
  if (!chartInstance->c2_dataWrittenToVector[3U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  *chartInstance->c2_x4_out = *chartInstance->c2_x4;
  chartInstance->c2_dataWrittenToVector[8U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_x4_out, 9U, 4U, 0U,
                        chartInstance->c2_sfEvent, false);
  if (!chartInstance->c2_dataWrittenToVector[4U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  *chartInstance->c2_x5_out = *chartInstance->c2_x5;
  chartInstance->c2_dataWrittenToVector[9U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_x5_out, 10U, 4U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_CTRNNSLSFMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c2_CTRNNSLSF(SFc2_CTRNNSLSFInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void zeroCrossings_c2_CTRNNSLSF(SFc2_CTRNNSLSFInstanceStruct
  *chartInstance)
{
  real_T *c2_zcVar;
  c2_zcVar = (real_T *)(ssGetNonsampledZCs_wrapper(chartInstance->S) + 0);
  _sfTime_ = sf_get_time(chartInstance->S);
  if (chartInstance->c2_lastMajorTime == _sfTime_) {
    *c2_zcVar = -1.0;
  } else {
    chartInstance->c2_stateChanged = (boolean_T)0;
    if (chartInstance->c2_stateChanged) {
      *c2_zcVar = 1.0;
    } else {
      *c2_zcVar = -1.0;
    }
  }
}

static void derivatives_c2_CTRNNSLSF(SFc2_CTRNNSLSFInstanceStruct *chartInstance)
{
  uint32_T c2_debug_family_var_map[2];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 0.0;
  real_T c2_d0;
  real_T c2_d1;
  real_T c2_d2;
  real_T c2_d3;
  real_T c2_d4;
  real_T c2_d5;
  real_T c2_d6;
  real_T c2_d7;
  real_T c2_d8;
  real_T c2_d9;
  real_T c2_d10;
  real_T c2_d11;
  real_T c2_d12;
  real_T c2_d13;
  real_T c2_d14;
  real_T c2_d15;
  real_T c2_d16;
  real_T c2_d17;
  real_T c2_d18;
  real_T c2_d19;
  real_T c2_d20;
  real_T c2_d21;
  real_T c2_d22;
  real_T c2_d23;
  real_T c2_d24;
  real_T *c2_x1_dot;
  real_T *c2_x2_dot;
  real_T *c2_x3_dot;
  real_T *c2_x4_dot;
  real_T *c2_x5_dot;
  c2_x5_dot = (real_T *)(ssGetdX_wrapper(chartInstance->S) + 4);
  c2_x4_dot = (real_T *)(ssGetdX_wrapper(chartInstance->S) + 3);
  c2_x3_dot = (real_T *)(ssGetdX_wrapper(chartInstance->S) + 2);
  c2_x2_dot = (real_T *)(ssGetdX_wrapper(chartInstance->S) + 1);
  c2_x1_dot = (real_T *)(ssGetdX_wrapper(chartInstance->S) + 0);
  *c2_x1_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c2_x1_dot, 0U, 1U, 1U, chartInstance->c2_sfEvent, false);
  *c2_x2_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c2_x2_dot, 1U, 1U, 1U, chartInstance->c2_sfEvent, false);
  *c2_x3_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c2_x3_dot, 2U, 1U, 1U, chartInstance->c2_sfEvent, false);
  *c2_x4_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c2_x4_dot, 3U, 1U, 1U, chartInstance->c2_sfEvent, false);
  *c2_x5_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c2_x5_dot, 4U, 1U, 1U, chartInstance->c2_sfEvent, false);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  if (!chartInstance->c2_dataWrittenToVector[0U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[1U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[2U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[3U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[4U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  c2_d0 = *chartInstance->c2_x1;
  c2_c_tanh(chartInstance, &c2_d0);
  c2_d1 = *chartInstance->c2_x2;
  c2_c_tanh(chartInstance, &c2_d1);
  c2_d2 = *chartInstance->c2_x3;
  c2_c_tanh(chartInstance, &c2_d2);
  c2_d3 = *chartInstance->c2_x4;
  c2_c_tanh(chartInstance, &c2_d3);
  c2_d4 = *chartInstance->c2_x5;
  c2_c_tanh(chartInstance, &c2_d4);
  *c2_x1_dot = (((((-*chartInstance->c2_x1 + 0.4684 * c2_d0) - 2.4995 * c2_d1) +
                  0.4211 * c2_d2) - 0.2848 * c2_d3) + 0.1995 * c2_d4) + 0.005 * *
    chartInstance->c2_u;
  chartInstance->c2_dataWrittenToVector[0U] = true;
  _SFD_DATA_RANGE_CHECK(*c2_x1_dot, 0U, 4U, 0U, chartInstance->c2_sfEvent, false);
  if (!chartInstance->c2_dataWrittenToVector[1U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[0U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[2U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[3U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[4U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  c2_d5 = *chartInstance->c2_x1;
  c2_c_tanh(chartInstance, &c2_d5);
  c2_d6 = *chartInstance->c2_x2;
  c2_c_tanh(chartInstance, &c2_d6);
  c2_d7 = *chartInstance->c2_x3;
  c2_c_tanh(chartInstance, &c2_d7);
  c2_d8 = *chartInstance->c2_x4;
  c2_c_tanh(chartInstance, &c2_d8);
  c2_d9 = *chartInstance->c2_x5;
  c2_c_tanh(chartInstance, &c2_d9);
  *c2_x2_dot = (((((-*chartInstance->c2_x2 + 1.3615 * c2_d5) + 0.0642 * c2_d6) +
                  0.0413 * c2_d7) - 1.8925 * c2_d8) - 1.6608 * c2_d9) - 0.2111 *
    *chartInstance->c2_u;
  chartInstance->c2_dataWrittenToVector[1U] = true;
  _SFD_DATA_RANGE_CHECK(*c2_x2_dot, 1U, 4U, 0U, chartInstance->c2_sfEvent, false);
  if (!chartInstance->c2_dataWrittenToVector[2U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[0U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[1U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[3U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[4U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  c2_d10 = *chartInstance->c2_x1;
  c2_c_tanh(chartInstance, &c2_d10);
  c2_d11 = *chartInstance->c2_x2;
  c2_c_tanh(chartInstance, &c2_d11);
  c2_d12 = *chartInstance->c2_x3;
  c2_c_tanh(chartInstance, &c2_d12);
  c2_d13 = *chartInstance->c2_x4;
  c2_c_tanh(chartInstance, &c2_d13);
  c2_d14 = *chartInstance->c2_x5;
  c2_c_tanh(chartInstance, &c2_d14);
  *c2_x3_dot = (((((-*chartInstance->c2_x3 - 0.8185 * c2_d10) - 0.9241 * c2_d11)
                  - 0.0743 * c2_d12) - 0.1264 * c2_d13) + 0.1484 * c2_d14) +
    0.1689 * *chartInstance->c2_u;
  chartInstance->c2_dataWrittenToVector[2U] = true;
  _SFD_DATA_RANGE_CHECK(*c2_x3_dot, 2U, 4U, 0U, chartInstance->c2_sfEvent, false);
  if (!chartInstance->c2_dataWrittenToVector[3U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[0U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[1U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[2U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[4U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  c2_d15 = *chartInstance->c2_x1;
  c2_c_tanh(chartInstance, &c2_d15);
  c2_d16 = *chartInstance->c2_x2;
  c2_c_tanh(chartInstance, &c2_d16);
  c2_d17 = *chartInstance->c2_x3;
  c2_c_tanh(chartInstance, &c2_d17);
  c2_d18 = *chartInstance->c2_x4;
  c2_c_tanh(chartInstance, &c2_d18);
  c2_d19 = *chartInstance->c2_x5;
  c2_c_tanh(chartInstance, &c2_d19);
  *c2_x4_dot = (((((-*chartInstance->c2_x4 - 0.3257 * c2_d15) + 1.2319 * c2_d16)
                  - 1.0997 * c2_d17) + 0.2192 * c2_d18) - 0.8547 * c2_d19) +
    0.0645 * *chartInstance->c2_u;
  chartInstance->c2_dataWrittenToVector[3U] = true;
  _SFD_DATA_RANGE_CHECK(*c2_x4_dot, 3U, 4U, 0U, chartInstance->c2_sfEvent, false);
  if (!chartInstance->c2_dataWrittenToVector[4U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[0U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[1U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[2U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[3U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  c2_d20 = *chartInstance->c2_x1;
  c2_c_tanh(chartInstance, &c2_d20);
  c2_d21 = *chartInstance->c2_x2;
  c2_c_tanh(chartInstance, &c2_d21);
  c2_d22 = *chartInstance->c2_x3;
  c2_c_tanh(chartInstance, &c2_d22);
  c2_d23 = *chartInstance->c2_x4;
  c2_c_tanh(chartInstance, &c2_d23);
  c2_d24 = *chartInstance->c2_x5;
  c2_c_tanh(chartInstance, &c2_d24);
  *c2_x5_dot = (((((-*chartInstance->c2_x5 - 1.2444 * c2_d20) + 0.4396 * c2_d21)
                  - 0.5466 * c2_d22) + 1.7342 * c2_d23) - 0.5953 * c2_d24) -
    0.0413 * *chartInstance->c2_u;
  chartInstance->c2_dataWrittenToVector[4U] = true;
  _SFD_DATA_RANGE_CHECK(*c2_x5_dot, 4U, 4U, 0U, chartInstance->c2_sfEvent, false);
  if (!chartInstance->c2_dataWrittenToVector[0U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  chartInstance->c2_dataWrittenToVector[5U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_x1_out, 6U, 4U, 0U,
                        chartInstance->c2_sfEvent, false);
  if (!chartInstance->c2_dataWrittenToVector[1U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  chartInstance->c2_dataWrittenToVector[6U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_x2_out, 7U, 4U, 0U,
                        chartInstance->c2_sfEvent, false);
  if (!chartInstance->c2_dataWrittenToVector[2U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  chartInstance->c2_dataWrittenToVector[7U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_x3_out, 8U, 4U, 0U,
                        chartInstance->c2_sfEvent, false);
  if (!chartInstance->c2_dataWrittenToVector[3U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  chartInstance->c2_dataWrittenToVector[8U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_x4_out, 9U, 4U, 0U,
                        chartInstance->c2_sfEvent, false);
  if (!chartInstance->c2_dataWrittenToVector[4U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  chartInstance->c2_dataWrittenToVector[9U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_x5_out, 10U, 4U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
}

static void outputs_c2_CTRNNSLSF(SFc2_CTRNNSLSFInstanceStruct *chartInstance)
{
  uint32_T c2_debug_family_var_map[2];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 0.0;
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  if (!chartInstance->c2_dataWrittenToVector[0U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[1U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[2U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[3U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[4U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  chartInstance->c2_dataWrittenToVector[0U] = true;
  if (!chartInstance->c2_dataWrittenToVector[1U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[0U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[2U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[3U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[4U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  chartInstance->c2_dataWrittenToVector[1U] = true;
  if (!chartInstance->c2_dataWrittenToVector[2U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[0U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[1U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[3U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[4U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  chartInstance->c2_dataWrittenToVector[2U] = true;
  if (!chartInstance->c2_dataWrittenToVector[3U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[0U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[1U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[2U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[4U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  chartInstance->c2_dataWrittenToVector[3U] = true;
  if (!chartInstance->c2_dataWrittenToVector[4U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[0U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[1U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[2U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  if (!chartInstance->c2_dataWrittenToVector[3U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  chartInstance->c2_dataWrittenToVector[4U] = true;
  if (!chartInstance->c2_dataWrittenToVector[0U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  *chartInstance->c2_x1_out = *chartInstance->c2_x1;
  chartInstance->c2_dataWrittenToVector[5U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_x1_out, 6U, 4U, 0U,
                        chartInstance->c2_sfEvent, false);
  if (!chartInstance->c2_dataWrittenToVector[1U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  *chartInstance->c2_x2_out = *chartInstance->c2_x2;
  chartInstance->c2_dataWrittenToVector[6U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_x2_out, 7U, 4U, 0U,
                        chartInstance->c2_sfEvent, false);
  if (!chartInstance->c2_dataWrittenToVector[2U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  *chartInstance->c2_x3_out = *chartInstance->c2_x3;
  chartInstance->c2_dataWrittenToVector[7U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_x3_out, 8U, 4U, 0U,
                        chartInstance->c2_sfEvent, false);
  if (!chartInstance->c2_dataWrittenToVector[3U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  *chartInstance->c2_x4_out = *chartInstance->c2_x4;
  chartInstance->c2_dataWrittenToVector[8U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_x4_out, 9U, 4U, 0U,
                        chartInstance->c2_sfEvent, false);
  if (!chartInstance->c2_dataWrittenToVector[4U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 0U, chartInstance->c2_sfEvent,
      false);
  }

  *chartInstance->c2_x5_out = *chartInstance->c2_x5;
  chartInstance->c2_dataWrittenToVector[9U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_x5_out, 10U, 4U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_CTRNNSLSF(SFc2_CTRNNSLSFInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c2_eml_ini_fcn_to_be_inlined_29(SFc2_CTRNNSLSFInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c2_eml_term_fcn_to_be_inlined_29(SFc2_CTRNNSLSFInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static real_T c2_tanh(SFc2_CTRNNSLSFInstanceStruct *chartInstance, real_T c2_x)
{
  real_T c2_b_x;
  c2_b_x = c2_x;
  c2_c_tanh(chartInstance, &c2_b_x);
  return c2_b_x;
}

static real_T c2_applyScalarFunctionInPlace(SFc2_CTRNNSLSFInstanceStruct
  *chartInstance, real_T c2_x)
{
  real_T c2_b_x;
  c2_b_x = c2_x;
  c2_b_applyScalarFunctionInPlace(chartInstance, &c2_b_x);
  return c2_b_x;
}

static real_T c2_b_tanh(SFc2_CTRNNSLSFInstanceStruct *chartInstance, real_T c2_x)
{
  real_T c2_b_x;
  c2_b_x = c2_x;
  c2_d_tanh(chartInstance, &c2_b_x);
  return c2_b_x;
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber)
{
  (void)(c2_machineNumber);
  (void)(c2_chartNumber);
  (void)(c2_instanceNumber);
}

static const mxArray *c2_emlrt_marshallOut(SFc2_CTRNNSLSFInstanceStruct
  *chartInstance, const real_T c2_b_u)
{
  const mxArray *c2_y = NULL;
  (void)chartInstance;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0), false);
  return c2_y;
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  SFc2_CTRNNSLSFInstanceStruct *chartInstance;
  chartInstance = (SFc2_CTRNNSLSFInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  sf_mex_assign(&c2_mxArrayOutData, c2_emlrt_marshallOut(chartInstance, *(real_T
    *)c2_inData), false);
  return c2_mxArrayOutData;
}

static real_T c2_emlrt_marshallIn(SFc2_CTRNNSLSFInstanceStruct *chartInstance,
  const mxArray *c2_nargout, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nargout), &c2_thisId);
  sf_mex_destroy(&c2_nargout);
  return c2_y;
}

static real_T c2_b_emlrt_marshallIn(SFc2_CTRNNSLSFInstanceStruct *chartInstance,
  const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d25;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), &c2_d25, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d25;
  sf_mex_destroy(&c2_b_u);
  return c2_y;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  SFc2_CTRNNSLSFInstanceStruct *chartInstance;
  chartInstance = (SFc2_CTRNNSLSFInstanceStruct *)chartInstanceVoid;
  *(real_T *)c2_outData = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_mxArrayInData), c2_varName);
  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_CTRNNSLSF_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c2_nameCaptureInfo;
}

static const mxArray *c2_b_emlrt_marshallOut(SFc2_CTRNNSLSFInstanceStruct
  *chartInstance, const int32_T c2_b_u)
{
  const mxArray *c2_y = NULL;
  (void)chartInstance;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_b_u, 6, 0U, 0U, 0U, 0), false);
  return c2_y;
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  SFc2_CTRNNSLSFInstanceStruct *chartInstance;
  chartInstance = (SFc2_CTRNNSLSFInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  sf_mex_assign(&c2_mxArrayOutData, c2_b_emlrt_marshallOut(chartInstance,
    *(int32_T *)c2_inData), false);
  return c2_mxArrayOutData;
}

static int32_T c2_c_emlrt_marshallIn(SFc2_CTRNNSLSFInstanceStruct *chartInstance,
  const mxArray *c2_b_sfEvent, const char_T *c2_identifier)
{
  int32_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  return c2_y;
}

static int32_T c2_d_emlrt_marshallIn(SFc2_CTRNNSLSFInstanceStruct *chartInstance,
  const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), &c2_i0, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i0;
  sf_mex_destroy(&c2_b_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  SFc2_CTRNNSLSFInstanceStruct *chartInstance;
  chartInstance = (SFc2_CTRNNSLSFInstanceStruct *)chartInstanceVoid;
  *(int32_T *)c2_outData = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_mxArrayInData), c2_varName);
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_c_emlrt_marshallOut(SFc2_CTRNNSLSFInstanceStruct
  *chartInstance, const uint8_T c2_b_u)
{
  const mxArray *c2_y = NULL;
  (void)chartInstance;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0), false);
  return c2_y;
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  SFc2_CTRNNSLSFInstanceStruct *chartInstance;
  chartInstance = (SFc2_CTRNNSLSFInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  sf_mex_assign(&c2_mxArrayOutData, c2_c_emlrt_marshallOut(chartInstance,
    *(uint8_T *)c2_inData), false);
  return c2_mxArrayOutData;
}

static uint8_T c2_e_emlrt_marshallIn(SFc2_CTRNNSLSFInstanceStruct *chartInstance,
  const mxArray *c2_b_tp_RNN, const char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_tp_RNN),
    &c2_thisId);
  sf_mex_destroy(&c2_b_tp_RNN);
  return c2_y;
}

static uint8_T c2_f_emlrt_marshallIn(SFc2_CTRNNSLSFInstanceStruct *chartInstance,
  const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_b_u);
  return c2_y;
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  SFc2_CTRNNSLSFInstanceStruct *chartInstance;
  chartInstance = (SFc2_CTRNNSLSFInstanceStruct *)chartInstanceVoid;
  *(uint8_T *)c2_outData = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_mxArrayInData), c2_varName);
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_d_emlrt_marshallOut(SFc2_CTRNNSLSFInstanceStruct
  *chartInstance)
{
  const mxArray *c2_y;
  int32_T c2_i1;
  boolean_T c2_bv0[10];
  c2_y = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellmatrix(13, 1), false);
  sf_mex_setcell(c2_y, 0, c2_emlrt_marshallOut(chartInstance,
    *chartInstance->c2_x1_out));
  sf_mex_setcell(c2_y, 1, c2_emlrt_marshallOut(chartInstance,
    *chartInstance->c2_x2_out));
  sf_mex_setcell(c2_y, 2, c2_emlrt_marshallOut(chartInstance,
    *chartInstance->c2_x3_out));
  sf_mex_setcell(c2_y, 3, c2_emlrt_marshallOut(chartInstance,
    *chartInstance->c2_x4_out));
  sf_mex_setcell(c2_y, 4, c2_emlrt_marshallOut(chartInstance,
    *chartInstance->c2_x5_out));
  sf_mex_setcell(c2_y, 5, c2_emlrt_marshallOut(chartInstance,
    *chartInstance->c2_x1));
  sf_mex_setcell(c2_y, 6, c2_emlrt_marshallOut(chartInstance,
    *chartInstance->c2_x2));
  sf_mex_setcell(c2_y, 7, c2_emlrt_marshallOut(chartInstance,
    *chartInstance->c2_x3));
  sf_mex_setcell(c2_y, 8, c2_emlrt_marshallOut(chartInstance,
    *chartInstance->c2_x4));
  sf_mex_setcell(c2_y, 9, c2_emlrt_marshallOut(chartInstance,
    *chartInstance->c2_x5));
  sf_mex_setcell(c2_y, 10, c2_c_emlrt_marshallOut(chartInstance,
    chartInstance->c2_is_active_c2_CTRNNSLSF));
  sf_mex_setcell(c2_y, 11, c2_c_emlrt_marshallOut(chartInstance,
    chartInstance->c2_is_c2_CTRNNSLSF));
  for (c2_i1 = 0; c2_i1 < 10; c2_i1++) {
    c2_bv0[c2_i1] = chartInstance->c2_dataWrittenToVector[c2_i1];
  }

  sf_mex_setcell(c2_y, 12, c2_e_emlrt_marshallOut(chartInstance, c2_bv0));
  return c2_y;
}

static const mxArray *c2_e_emlrt_marshallOut(SFc2_CTRNNSLSFInstanceStruct
  *chartInstance, const boolean_T c2_b_u[10])
{
  const mxArray *c2_y = NULL;
  (void)chartInstance;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_b_u, 11, 0U, 1U, 0U, 1, 10), false);
  return c2_y;
}

static void c2_g_emlrt_marshallIn(SFc2_CTRNNSLSFInstanceStruct *chartInstance,
  const mxArray *c2_b_u)
{
  boolean_T c2_bv1[10];
  int32_T c2_i2;
  *chartInstance->c2_x1_out = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("x1_out", c2_b_u, 0)), "x1_out");
  *chartInstance->c2_x2_out = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("x2_out", c2_b_u, 1)), "x2_out");
  *chartInstance->c2_x3_out = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("x3_out", c2_b_u, 2)), "x3_out");
  *chartInstance->c2_x4_out = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("x4_out", c2_b_u, 3)), "x4_out");
  *chartInstance->c2_x5_out = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("x5_out", c2_b_u, 4)), "x5_out");
  *chartInstance->c2_x1 = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("x1", c2_b_u, 5)), "x1");
  *chartInstance->c2_x2 = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("x2", c2_b_u, 6)), "x2");
  *chartInstance->c2_x3 = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("x3", c2_b_u, 7)), "x3");
  *chartInstance->c2_x4 = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("x4", c2_b_u, 8)), "x4");
  *chartInstance->c2_x5 = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("x5", c2_b_u, 9)), "x5");
  chartInstance->c2_is_active_c2_CTRNNSLSF = c2_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_active_c2_CTRNNSLSF", c2_b_u, 10)),
    "is_active_c2_CTRNNSLSF");
  chartInstance->c2_is_c2_CTRNNSLSF = c2_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_c2_CTRNNSLSF", c2_b_u, 11)), "is_c2_CTRNNSLSF");
  c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "dataWrittenToVector", c2_b_u, 12)), "dataWrittenToVector", c2_bv1);
  for (c2_i2 = 0; c2_i2 < 10; c2_i2++) {
    chartInstance->c2_dataWrittenToVector[c2_i2] = c2_bv1[c2_i2];
  }

  sf_mex_assign(&chartInstance->c2_setSimStateSideEffectsInfo,
                c2_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "setSimStateSideEffectsInfo", c2_b_u, 13)), "setSimStateSideEffectsInfo"),
                true);
  sf_mex_destroy(&c2_b_u);
}

static void c2_h_emlrt_marshallIn(SFc2_CTRNNSLSFInstanceStruct *chartInstance,
  const mxArray *c2_b_dataWrittenToVector, const char_T *c2_identifier,
  boolean_T c2_y[10])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_dataWrittenToVector),
                        &c2_thisId, c2_y);
  sf_mex_destroy(&c2_b_dataWrittenToVector);
}

static void c2_i_emlrt_marshallIn(SFc2_CTRNNSLSFInstanceStruct *chartInstance,
  const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId, boolean_T c2_y
  [10])
{
  boolean_T c2_bv2[10];
  int32_T c2_i3;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), c2_bv2, 1, 11, 0U, 1, 0U, 1, 10);
  for (c2_i3 = 0; c2_i3 < 10; c2_i3++) {
    c2_y[c2_i3] = c2_bv2[c2_i3];
  }

  sf_mex_destroy(&c2_b_u);
}

static const mxArray *c2_j_emlrt_marshallIn(SFc2_CTRNNSLSFInstanceStruct
  *chartInstance, const mxArray *c2_b_setSimStateSideEffectsInfo, const char_T
  *c2_identifier)
{
  const mxArray *c2_y = NULL;
  emlrtMsgIdentifier c2_thisId;
  c2_y = NULL;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  sf_mex_assign(&c2_y, c2_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_setSimStateSideEffectsInfo), &c2_thisId), false);
  sf_mex_destroy(&c2_b_setSimStateSideEffectsInfo);
  return c2_y;
}

static const mxArray *c2_k_emlrt_marshallIn(SFc2_CTRNNSLSFInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId)
{
  const mxArray *c2_y = NULL;
  (void)chartInstance;
  (void)c2_parentId;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_duplicatearraysafe(&c2_b_u), false);
  sf_mex_destroy(&c2_b_u);
  return c2_y;
}

static const mxArray *sf_get_hover_data_for_msg(SFc2_CTRNNSLSFInstanceStruct
  *chartInstance, int32_T c2_ssid)
{
  const mxArray *c2_msgInfo;
  (void)chartInstance;
  (void)c2_ssid;
  c2_msgInfo = NULL;
  return NULL;
}

static void c2_init_sf_message_store_memory(SFc2_CTRNNSLSFInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c2_c_tanh(SFc2_CTRNNSLSFInstanceStruct *chartInstance, real_T *c2_x)
{
  c2_b_applyScalarFunctionInPlace(chartInstance, c2_x);
}

static void c2_b_applyScalarFunctionInPlace(SFc2_CTRNNSLSFInstanceStruct
  *chartInstance, real_T *c2_x)
{
  c2_d_tanh(chartInstance, c2_x);
}

static void c2_d_tanh(SFc2_CTRNNSLSFInstanceStruct *chartInstance, real_T *c2_x)
{
  (void)chartInstance;
  *c2_x = muDoubleScalarTanh(*c2_x);
}

static void init_dsm_address_info(SFc2_CTRNNSLSFInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc2_CTRNNSLSFInstanceStruct *chartInstance)
{
  chartInstance->c2_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c2_u = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    0);
  chartInstance->c2_x1 = (real_T *)(ssGetContStates_wrapper(chartInstance->S) +
    0);
  chartInstance->c2_x2 = (real_T *)(ssGetContStates_wrapper(chartInstance->S) +
    1);
  chartInstance->c2_x3 = (real_T *)(ssGetContStates_wrapper(chartInstance->S) +
    2);
  chartInstance->c2_x4 = (real_T *)(ssGetContStates_wrapper(chartInstance->S) +
    3);
  chartInstance->c2_x5 = (real_T *)(ssGetContStates_wrapper(chartInstance->S) +
    4);
  chartInstance->c2_x1_out = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c2_x2_out = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c2_x3_out = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c2_x4_out = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c2_x5_out = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 5);
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

void sf_c2_CTRNNSLSF_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2037015569U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3531465851U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2852459919U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1834645869U);
}

mxArray* sf_c2_CTRNNSLSF_get_post_codegen_info(void);
mxArray *sf_c2_CTRNNSLSF_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("7IfDhBfQ817GH1J7Oc8KnH");
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

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxData);
  }

  {
    mxArray* mxPostCodegenInfo = sf_c2_CTRNNSLSF_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c2_CTRNNSLSF_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c2_CTRNNSLSF_jit_fallback_info(void)
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

mxArray *sf_c2_CTRNNSLSF_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c2_CTRNNSLSF_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c2_CTRNNSLSF(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[17],T\"x1_out\",},{M[1],M[19],T\"x2_out\",},{M[1],M[20],T\"x3_out\",},{M[1],M[21],T\"x4_out\",},{M[1],M[22],T\"x5_out\",},{M[5],M[12],T\"x1\",},{M[5],M[13],T\"x2\",},{M[5],M[14],T\"x3\",},{M[5],M[15],T\"x4\",},{M[5],M[16],T\"x5\",}}",
    "100 S1x3'type','srcId','name','auxInfo'{{M[8],M[0],T\"is_active_c2_CTRNNSLSF\",},{M[9],M[0],T\"is_c2_CTRNNSLSF\",},{M[15],M[0],T\"dataWrittenToVector\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 13, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_CTRNNSLSF_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const mxArray* sf_opaque_get_hover_data_for_msg(void* chartInstance,
  int32_T msgSSID)
{
  return sf_get_hover_data_for_msg( (SFc2_CTRNNSLSFInstanceStruct *)
    chartInstance, msgSSID);
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_CTRNNSLSFInstanceStruct *chartInstance = (SFc2_CTRNNSLSFInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _CTRNNSLSFMachineNumber_,
           2,
           1,
           1,
           0,
           11,
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
          _SFD_SET_DATA_PROPS(2,0,0,0,"x3");
          _SFD_SET_DATA_PROPS(3,0,0,0,"x4");
          _SFD_SET_DATA_PROPS(4,0,0,0,"x5");
          _SFD_SET_DATA_PROPS(5,1,1,0,"u");
          _SFD_SET_DATA_PROPS(6,2,0,1,"x1_out");
          _SFD_SET_DATA_PROPS(7,2,0,1,"x2_out");
          _SFD_SET_DATA_PROPS(8,2,0,1,"x3_out");
          _SFD_SET_DATA_PROPS(9,2,0,1,"x4_out");
          _SFD_SET_DATA_PROPS(10,2,0,1,"x5_out");
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
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
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
    SFc2_CTRNNSLSFInstanceStruct *chartInstance = (SFc2_CTRNNSLSFInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(5U, (void *)chartInstance->c2_u);
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)chartInstance->c2_x1);
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)chartInstance->c2_x2);
        _SFD_SET_DATA_VALUE_PTR(2U, (void *)chartInstance->c2_x3);
        _SFD_SET_DATA_VALUE_PTR(3U, (void *)chartInstance->c2_x4);
        _SFD_SET_DATA_VALUE_PTR(4U, (void *)chartInstance->c2_x5);
        _SFD_SET_DATA_VALUE_PTR(6U, (void *)chartInstance->c2_x1_out);
        _SFD_SET_DATA_VALUE_PTR(7U, (void *)chartInstance->c2_x2_out);
        _SFD_SET_DATA_VALUE_PTR(8U, (void *)chartInstance->c2_x3_out);
        _SFD_SET_DATA_VALUE_PTR(9U, (void *)chartInstance->c2_x4_out);
        _SFD_SET_DATA_VALUE_PTR(10U, (void *)chartInstance->c2_x5_out);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "su0lzTC9WHgvXsdP8tbZh3C";
}

static void sf_opaque_initialize_c2_CTRNNSLSF(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_CTRNNSLSFInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c2_CTRNNSLSF((SFc2_CTRNNSLSFInstanceStruct*)
    chartInstanceVar);
  initialize_c2_CTRNNSLSF((SFc2_CTRNNSLSFInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_CTRNNSLSF(void *chartInstanceVar)
{
  enable_c2_CTRNNSLSF((SFc2_CTRNNSLSFInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_CTRNNSLSF(void *chartInstanceVar)
{
  disable_c2_CTRNNSLSF((SFc2_CTRNNSLSFInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_zeroCrossings_c2_CTRNNSLSF(void *chartInstanceVar)
{
  zeroCrossings_c2_CTRNNSLSF((SFc2_CTRNNSLSFInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_derivatives_c2_CTRNNSLSF(void *chartInstanceVar)
{
  derivatives_c2_CTRNNSLSF((SFc2_CTRNNSLSFInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_outputs_c2_CTRNNSLSF(void *chartInstanceVar)
{
  outputs_c2_CTRNNSLSF((SFc2_CTRNNSLSFInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_CTRNNSLSF(void *chartInstanceVar)
{
  sf_gateway_c2_CTRNNSLSF((SFc2_CTRNNSLSFInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c2_CTRNNSLSF(SimStruct* S)
{
  return get_sim_state_c2_CTRNNSLSF((SFc2_CTRNNSLSFInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c2_CTRNNSLSF(SimStruct* S, const mxArray *st)
{
  set_sim_state_c2_CTRNNSLSF((SFc2_CTRNNSLSFInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c2_CTRNNSLSF(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_CTRNNSLSFInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_CTRNNSLSF_optimization_info();
    }

    finalize_c2_CTRNNSLSF((SFc2_CTRNNSLSFInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_CTRNNSLSF((SFc2_CTRNNSLSFInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_CTRNNSLSF(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_CTRNNSLSF((SFc2_CTRNNSLSFInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c2_CTRNNSLSF(SimStruct *S)
{
  ssSetStatesModifiedOnlyInUpdate(S, 0);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_CTRNNSLSF_optimization_info(sim_mode_is_rtw_gen(S),
      sim_mode_is_modelref_sim(S), sim_mode_is_external(S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,2,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 2);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,5);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=5; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetCallsOutputInInitFcn(S,1);
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(468326886U));
  ssSetChecksum1(S,(2134874448U));
  ssSetChecksum2(S,(3066515647U));
  ssSetChecksum3(S,(459946628U));
  ssSetNumContStates(S,5);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_CTRNNSLSF(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c2_CTRNNSLSF(SimStruct *S)
{
  SFc2_CTRNNSLSFInstanceStruct *chartInstance;
  chartInstance = (SFc2_CTRNNSLSFInstanceStruct *)utMalloc(sizeof
    (SFc2_CTRNNSLSFInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc2_CTRNNSLSFInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_CTRNNSLSF;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c2_CTRNNSLSF;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_CTRNNSLSF;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_CTRNNSLSF;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_CTRNNSLSF;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c2_CTRNNSLSF;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c2_CTRNNSLSF;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c2_CTRNNSLSF;
  chartInstance->chartInfo.zeroCrossings = sf_opaque_zeroCrossings_c2_CTRNNSLSF;
  chartInstance->chartInfo.outputs = sf_opaque_outputs_c2_CTRNNSLSF;
  chartInstance->chartInfo.derivatives = sf_opaque_derivatives_c2_CTRNNSLSF;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_CTRNNSLSF;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_CTRNNSLSF;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_CTRNNSLSF;
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
  mdl_start_c2_CTRNNSLSF(chartInstance);
}

void c2_CTRNNSLSF_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_CTRNNSLSF(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_CTRNNSLSF(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_CTRNNSLSF(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_CTRNNSLSF_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
