/* Include files */

#include "CTRNNSLSF_sfun.h"
#include "c5_CTRNNSLSF.h"
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
#define c5_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c5_IN_Falling                  ((uint8_T)1U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c5_debug_family_names[2] = { "nargin", "nargout" };

static const char * c5_b_debug_family_names[2] = { "nargin", "nargout" };

/* Function Declarations */
static void initialize_c5_CTRNNSLSF(SFc5_CTRNNSLSFInstanceStruct *chartInstance);
static void initialize_params_c5_CTRNNSLSF(SFc5_CTRNNSLSFInstanceStruct
  *chartInstance);
static void enable_c5_CTRNNSLSF(SFc5_CTRNNSLSFInstanceStruct *chartInstance);
static void disable_c5_CTRNNSLSF(SFc5_CTRNNSLSFInstanceStruct *chartInstance);
static void c5_update_debugger_state_c5_CTRNNSLSF(SFc5_CTRNNSLSFInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c5_CTRNNSLSF(SFc5_CTRNNSLSFInstanceStruct
  *chartInstance);
static void set_sim_state_c5_CTRNNSLSF(SFc5_CTRNNSLSFInstanceStruct
  *chartInstance, const mxArray *c5_st);
static void c5_set_sim_state_side_effects_c5_CTRNNSLSF
  (SFc5_CTRNNSLSFInstanceStruct *chartInstance);
static void finalize_c5_CTRNNSLSF(SFc5_CTRNNSLSFInstanceStruct *chartInstance);
static void sf_gateway_c5_CTRNNSLSF(SFc5_CTRNNSLSFInstanceStruct *chartInstance);
static void mdl_start_c5_CTRNNSLSF(SFc5_CTRNNSLSFInstanceStruct *chartInstance);
static void zeroCrossings_c5_CTRNNSLSF(SFc5_CTRNNSLSFInstanceStruct
  *chartInstance);
static void derivatives_c5_CTRNNSLSF(SFc5_CTRNNSLSFInstanceStruct *chartInstance);
static void outputs_c5_CTRNNSLSF(SFc5_CTRNNSLSFInstanceStruct *chartInstance);
static void initSimStructsc5_CTRNNSLSF(SFc5_CTRNNSLSFInstanceStruct
  *chartInstance);
static void c5_eml_ini_fcn_to_be_inlined_60(SFc5_CTRNNSLSFInstanceStruct
  *chartInstance);
static void c5_eml_term_fcn_to_be_inlined_60(SFc5_CTRNNSLSFInstanceStruct
  *chartInstance);
static real_T c5_mpower(SFc5_CTRNNSLSFInstanceStruct *chartInstance, real_T c5_a);
static real_T c5_power(SFc5_CTRNNSLSFInstanceStruct *chartInstance, real_T c5_a);
static real_T c5_fltpower(SFc5_CTRNNSLSFInstanceStruct *chartInstance, real_T
  c5_a);
static real_T c5_applyScalarFunction(SFc5_CTRNNSLSFInstanceStruct *chartInstance,
  real_T c5_x);
static real_T c5_scalar_float_power(SFc5_CTRNNSLSFInstanceStruct *chartInstance,
  real_T c5_a);
static boolean_T c5_fltpower_domain_error(SFc5_CTRNNSLSFInstanceStruct
  *chartInstance, real_T c5_a, real_T c5_b);
static boolean_T c5_isnan(SFc5_CTRNNSLSFInstanceStruct *chartInstance, real_T
  c5_x);
static real_T c5_floor(SFc5_CTRNNSLSFInstanceStruct *chartInstance, real_T c5_x);
static real_T c5_applyScalarFunctionInPlace(SFc5_CTRNNSLSFInstanceStruct
  *chartInstance, real_T c5_x);
static real_T c5_b_floor(SFc5_CTRNNSLSFInstanceStruct *chartInstance, real_T
  c5_x);
static void c5_error(SFc5_CTRNNSLSFInstanceStruct *chartInstance);
static real_T c5_tanh(SFc5_CTRNNSLSFInstanceStruct *chartInstance, real_T c5_x);
static real_T c5_b_applyScalarFunctionInPlace(SFc5_CTRNNSLSFInstanceStruct
  *chartInstance, real_T c5_x);
static real_T c5_b_tanh(SFc5_CTRNNSLSFInstanceStruct *chartInstance, real_T c5_x);
static real_T c5_b_mpower(SFc5_CTRNNSLSFInstanceStruct *chartInstance, real_T
  c5_a);
static real_T c5_b_power(SFc5_CTRNNSLSFInstanceStruct *chartInstance, real_T
  c5_a);
static real_T c5_b_fltpower(SFc5_CTRNNSLSFInstanceStruct *chartInstance, real_T
  c5_a);
static real_T c5_b_applyScalarFunction(SFc5_CTRNNSLSFInstanceStruct
  *chartInstance, real_T c5_x);
static real_T c5_b_scalar_float_power(SFc5_CTRNNSLSFInstanceStruct
  *chartInstance, real_T c5_a);
static real_T c5_c_mpower(SFc5_CTRNNSLSFInstanceStruct *chartInstance, real_T
  c5_a);
static real_T c5_c_power(SFc5_CTRNNSLSFInstanceStruct *chartInstance, real_T
  c5_a);
static real_T c5_c_fltpower(SFc5_CTRNNSLSFInstanceStruct *chartInstance, real_T
  c5_a);
static real_T c5_c_applyScalarFunction(SFc5_CTRNNSLSFInstanceStruct
  *chartInstance, real_T c5_x);
static real_T c5_c_scalar_float_power(SFc5_CTRNNSLSFInstanceStruct
  *chartInstance, real_T c5_a);
static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber, uint32_T c5_instanceNumber);
static const mxArray *c5_emlrt_marshallOut(SFc5_CTRNNSLSFInstanceStruct
  *chartInstance, const char_T c5_u[31]);
static const mxArray *c5_b_emlrt_marshallOut(SFc5_CTRNNSLSFInstanceStruct
  *chartInstance, const real_T c5_u);
static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData);
static real_T c5_emlrt_marshallIn(SFc5_CTRNNSLSFInstanceStruct *chartInstance,
  const mxArray *c5_nargout, const char_T *c5_identifier);
static real_T c5_b_emlrt_marshallIn(SFc5_CTRNNSLSFInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_c_emlrt_marshallOut(SFc5_CTRNNSLSFInstanceStruct
  *chartInstance, const int32_T c5_u);
static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static int32_T c5_c_emlrt_marshallIn(SFc5_CTRNNSLSFInstanceStruct *chartInstance,
  const mxArray *c5_b_sfEvent, const char_T *c5_identifier);
static int32_T c5_d_emlrt_marshallIn(SFc5_CTRNNSLSFInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_d_emlrt_marshallOut(SFc5_CTRNNSLSFInstanceStruct
  *chartInstance, const uint8_T c5_u);
static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static uint8_T c5_e_emlrt_marshallIn(SFc5_CTRNNSLSFInstanceStruct *chartInstance,
  const mxArray *c5_b_tp_Falling, const char_T *c5_identifier);
static uint8_T c5_f_emlrt_marshallIn(SFc5_CTRNNSLSFInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_e_emlrt_marshallOut(SFc5_CTRNNSLSFInstanceStruct
  *chartInstance);
static const mxArray *c5_f_emlrt_marshallOut(SFc5_CTRNNSLSFInstanceStruct
  *chartInstance, const boolean_T c5_u[10]);
static void c5_g_emlrt_marshallIn(SFc5_CTRNNSLSFInstanceStruct *chartInstance,
  const mxArray *c5_u);
static void c5_h_emlrt_marshallIn(SFc5_CTRNNSLSFInstanceStruct *chartInstance,
  const mxArray *c5_b_dataWrittenToVector, const char_T *c5_identifier,
  boolean_T c5_y[10]);
static void c5_i_emlrt_marshallIn(SFc5_CTRNNSLSFInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, boolean_T c5_y[10]);
static const mxArray *c5_j_emlrt_marshallIn(SFc5_CTRNNSLSFInstanceStruct
  *chartInstance, const mxArray *c5_b_setSimStateSideEffectsInfo, const char_T
  *c5_identifier);
static const mxArray *c5_k_emlrt_marshallIn(SFc5_CTRNNSLSFInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static const mxArray *sf_get_hover_data_for_msg(SFc5_CTRNNSLSFInstanceStruct
  *chartInstance, int32_T c5_ssid);
static void c5_init_sf_message_store_memory(SFc5_CTRNNSLSFInstanceStruct
  *chartInstance);
static void c5_c_floor(SFc5_CTRNNSLSFInstanceStruct *chartInstance, real_T *c5_x);
static void c5_c_applyScalarFunctionInPlace(SFc5_CTRNNSLSFInstanceStruct
  *chartInstance, real_T *c5_x);
static void c5_d_floor(SFc5_CTRNNSLSFInstanceStruct *chartInstance, real_T *c5_x);
static void c5_c_tanh(SFc5_CTRNNSLSFInstanceStruct *chartInstance, real_T *c5_x);
static void c5_d_applyScalarFunctionInPlace(SFc5_CTRNNSLSFInstanceStruct
  *chartInstance, real_T *c5_x);
static void c5_d_tanh(SFc5_CTRNNSLSFInstanceStruct *chartInstance, real_T *c5_x);
static void init_dsm_address_info(SFc5_CTRNNSLSFInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc5_CTRNNSLSFInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c5_CTRNNSLSF(SFc5_CTRNNSLSFInstanceStruct *chartInstance)
{
  uint32_T c5_debug_family_var_map[2];
  real_T c5_nargin = 0.0;
  real_T c5_nargout = 0.0;
  if (sf_is_first_init_cond(chartInstance->S)) {
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c5_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c5_doSetSimStateSideEffects = 0U;
  chartInstance->c5_setSimStateSideEffectsInfo = NULL;
  chartInstance->c5_tp_Falling = 0U;
  chartInstance->c5_is_active_c5_CTRNNSLSF = 0U;
  chartInstance->c5_is_c5_CTRNNSLSF = c5_IN_NO_ACTIVE_CHILD;
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  chartInstance->c5_stateChanged = true;
  chartInstance->c5_is_active_c5_CTRNNSLSF = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c5_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c5_b_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 0U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 1U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  *chartInstance->c5_x1 = *chartInstance->c5_x10;
  chartInstance->c5_dataWrittenToVector[0U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c5_x1, 0U, 5U, 0U,
                        chartInstance->c5_sfEvent, false);
  *chartInstance->c5_x2 = *chartInstance->c5_x20;
  chartInstance->c5_dataWrittenToVector[1U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c5_x2, 1U, 5U, 0U,
                        chartInstance->c5_sfEvent, false);
  *chartInstance->c5_x3 = (1.2146 * *chartInstance->c5_x10 - 0.105 *
    *chartInstance->c5_x20) - 7.5649 * c5_b_mpower(chartInstance, 10.0);
  chartInstance->c5_dataWrittenToVector[2U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c5_x3, 2U, 5U, 0U,
                        chartInstance->c5_sfEvent, false);
  *chartInstance->c5_x4 = (0.1202 * *chartInstance->c5_x10 + 0.1939 *
    *chartInstance->c5_x20) + 1.34708 * c5_c_mpower(chartInstance, 10.0);
  chartInstance->c5_dataWrittenToVector[3U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c5_x4, 3U, 5U, 0U,
                        chartInstance->c5_sfEvent, false);
  *chartInstance->c5_x5 = (-1.367 * *chartInstance->c5_x10 + 0.122 *
    *chartInstance->c5_x20) - 6.24925 * c5_mpower(chartInstance, 10.0);
  chartInstance->c5_dataWrittenToVector[4U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c5_x5, 4U, 5U, 0U,
                        chartInstance->c5_sfEvent, false);
  if (!chartInstance->c5_dataWrittenToVector[4U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 5U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  sf_mex_printf("%s =\\n", "x5");
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                    c5_b_emlrt_marshallOut(chartInstance, *chartInstance->c5_x5));
  _SFD_SYMBOL_SCOPE_POP();
  chartInstance->c5_stateChanged = true;
  chartInstance->c5_is_c5_CTRNNSLSF = c5_IN_Falling;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c5_sfEvent);
  chartInstance->c5_tp_Falling = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_CTRNNSLSFMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initialize_params_c5_CTRNNSLSF(SFc5_CTRNNSLSFInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c5_CTRNNSLSF(SFc5_CTRNNSLSFInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c5_CTRNNSLSF(SFc5_CTRNNSLSFInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c5_update_debugger_state_c5_CTRNNSLSF(SFc5_CTRNNSLSFInstanceStruct
  *chartInstance)
{
  uint32_T c5_prevAniVal;
  c5_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c5_is_active_c5_CTRNNSLSF == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 4U, chartInstance->c5_sfEvent);
  }

  if (chartInstance->c5_is_c5_CTRNNSLSF == c5_IN_Falling) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c5_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c5_sfEvent);
  }

  _SFD_SET_ANIMATION(c5_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c5_CTRNNSLSF(SFc5_CTRNNSLSFInstanceStruct
  *chartInstance)
{
  const mxArray *c5_st = NULL;
  c5_st = NULL;
  sf_mex_assign(&c5_st, c5_e_emlrt_marshallOut(chartInstance), false);
  return c5_st;
}

static void set_sim_state_c5_CTRNNSLSF(SFc5_CTRNNSLSFInstanceStruct
  *chartInstance, const mxArray *c5_st)
{
  chartInstance->c5_doneDoubleBufferReInit = true;
  c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_st));
  chartInstance->c5_doSetSimStateSideEffects = 1U;
  c5_update_debugger_state_c5_CTRNNSLSF(chartInstance);
  sf_mex_destroy(&c5_st);
}

static void c5_set_sim_state_side_effects_c5_CTRNNSLSF
  (SFc5_CTRNNSLSFInstanceStruct *chartInstance)
{
  if (chartInstance->c5_doSetSimStateSideEffects != 0) {
    chartInstance->c5_tp_Falling = (uint8_T)(chartInstance->c5_is_c5_CTRNNSLSF ==
      c5_IN_Falling);
    chartInstance->c5_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c5_CTRNNSLSF(SFc5_CTRNNSLSFInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c5_setSimStateSideEffectsInfo);
}

static void sf_gateway_c5_CTRNNSLSF(SFc5_CTRNNSLSFInstanceStruct *chartInstance)
{
  uint32_T c5_debug_family_var_map[2];
  real_T c5_nargin = 0.0;
  real_T c5_nargout = 0.0;
  c5_set_sim_state_side_effects_c5_CTRNNSLSF(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  if (ssIsMajorTimeStep(chartInstance->S) != 0U) {
    chartInstance->c5_lastMajorTime = _sfTime_;
    chartInstance->c5_stateChanged = (boolean_T)0;
    _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c5_x20, 6U, 1U, 0U,
                          chartInstance->c5_sfEvent, false);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c5_x10, 5U, 1U, 0U,
                          chartInstance->c5_sfEvent, false);
    chartInstance->c5_sfEvent = CALL_EVENT;
    *chartInstance->c5_x1_out = 0.0;
    chartInstance->c5_dataWrittenToVector[5U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c5_x1_out, 7U, 1U, 4U,
                          chartInstance->c5_sfEvent, false);
    *chartInstance->c5_x2_out = 0.0;
    chartInstance->c5_dataWrittenToVector[6U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c5_x2_out, 8U, 1U, 4U,
                          chartInstance->c5_sfEvent, false);
    *chartInstance->c5_x3_out = 0.0;
    chartInstance->c5_dataWrittenToVector[7U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c5_x3_out, 9U, 1U, 4U,
                          chartInstance->c5_sfEvent, false);
    *chartInstance->c5_x4_out = 0.0;
    chartInstance->c5_dataWrittenToVector[8U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c5_x4_out, 10U, 1U, 4U,
                          chartInstance->c5_sfEvent, false);
    *chartInstance->c5_x5_out = 0.0;
    chartInstance->c5_dataWrittenToVector[9U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c5_x5_out, 11U, 1U, 4U,
                          chartInstance->c5_sfEvent, false);
    _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c5_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c5_sfEvent);
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
    if (chartInstance->c5_stateChanged) {
      ssSetSolverNeedsReset(chartInstance->S);
    }
  }

  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c5_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c5_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 0U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 1U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  if (!chartInstance->c5_dataWrittenToVector[0U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  if (!chartInstance->c5_dataWrittenToVector[2U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  if (!chartInstance->c5_dataWrittenToVector[3U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  if (!chartInstance->c5_dataWrittenToVector[4U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  if (!chartInstance->c5_dataWrittenToVector[1U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  if (!chartInstance->c5_dataWrittenToVector[2U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  if (!chartInstance->c5_dataWrittenToVector[3U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  if (!chartInstance->c5_dataWrittenToVector[4U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  if (!chartInstance->c5_dataWrittenToVector[2U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  if (!chartInstance->c5_dataWrittenToVector[3U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  if (!chartInstance->c5_dataWrittenToVector[4U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  chartInstance->c5_dataWrittenToVector[2U] = true;
  if (!chartInstance->c5_dataWrittenToVector[3U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  if (!chartInstance->c5_dataWrittenToVector[2U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  if (!chartInstance->c5_dataWrittenToVector[4U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  chartInstance->c5_dataWrittenToVector[3U] = true;
  if (!chartInstance->c5_dataWrittenToVector[4U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  if (!chartInstance->c5_dataWrittenToVector[2U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  if (!chartInstance->c5_dataWrittenToVector[3U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  chartInstance->c5_dataWrittenToVector[4U] = true;
  if (!chartInstance->c5_dataWrittenToVector[0U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  *chartInstance->c5_x1_out = *chartInstance->c5_x1;
  chartInstance->c5_dataWrittenToVector[5U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c5_x1_out, 7U, 4U, 0U,
                        chartInstance->c5_sfEvent, false);
  if (!chartInstance->c5_dataWrittenToVector[1U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  *chartInstance->c5_x2_out = *chartInstance->c5_x2;
  chartInstance->c5_dataWrittenToVector[6U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c5_x2_out, 8U, 4U, 0U,
                        chartInstance->c5_sfEvent, false);
  if (!chartInstance->c5_dataWrittenToVector[2U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  *chartInstance->c5_x3_out = *chartInstance->c5_x3;
  chartInstance->c5_dataWrittenToVector[7U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c5_x3_out, 9U, 4U, 0U,
                        chartInstance->c5_sfEvent, false);
  if (!chartInstance->c5_dataWrittenToVector[3U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  *chartInstance->c5_x4_out = *chartInstance->c5_x4;
  chartInstance->c5_dataWrittenToVector[8U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c5_x4_out, 10U, 4U, 0U,
                        chartInstance->c5_sfEvent, false);
  if (!chartInstance->c5_dataWrittenToVector[4U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  *chartInstance->c5_x5_out = *chartInstance->c5_x5;
  chartInstance->c5_dataWrittenToVector[9U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c5_x5_out, 11U, 4U, 0U,
                        chartInstance->c5_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c5_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_CTRNNSLSFMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c5_CTRNNSLSF(SFc5_CTRNNSLSFInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void zeroCrossings_c5_CTRNNSLSF(SFc5_CTRNNSLSFInstanceStruct
  *chartInstance)
{
  real_T *c5_zcVar;
  c5_zcVar = (real_T *)(ssGetNonsampledZCs_wrapper(chartInstance->S) + 0);
  _sfTime_ = sf_get_time(chartInstance->S);
  if (chartInstance->c5_lastMajorTime == _sfTime_) {
    *c5_zcVar = -1.0;
  } else {
    chartInstance->c5_stateChanged = (boolean_T)0;
    if (chartInstance->c5_stateChanged) {
      *c5_zcVar = 1.0;
    } else {
      *c5_zcVar = -1.0;
    }
  }
}

static void derivatives_c5_CTRNNSLSF(SFc5_CTRNNSLSFInstanceStruct *chartInstance)
{
  uint32_T c5_debug_family_var_map[2];
  real_T c5_nargin = 0.0;
  real_T c5_nargout = 0.0;
  real_T c5_d0;
  real_T c5_d1;
  real_T c5_d2;
  real_T c5_d3;
  real_T c5_d4;
  real_T c5_d5;
  real_T c5_d6;
  real_T c5_d7;
  real_T c5_d8;
  real_T c5_d9;
  real_T c5_d10;
  real_T c5_d11;
  real_T c5_d12;
  real_T c5_d13;
  real_T c5_d14;
  real_T *c5_x1_dot;
  real_T *c5_x2_dot;
  real_T *c5_x3_dot;
  real_T *c5_x4_dot;
  real_T *c5_x5_dot;
  c5_x5_dot = (real_T *)(ssGetdX_wrapper(chartInstance->S) + 4);
  c5_x4_dot = (real_T *)(ssGetdX_wrapper(chartInstance->S) + 3);
  c5_x3_dot = (real_T *)(ssGetdX_wrapper(chartInstance->S) + 2);
  c5_x2_dot = (real_T *)(ssGetdX_wrapper(chartInstance->S) + 1);
  c5_x1_dot = (real_T *)(ssGetdX_wrapper(chartInstance->S) + 0);
  *c5_x1_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c5_x1_dot, 0U, 1U, 4U, chartInstance->c5_sfEvent, false);
  *c5_x2_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c5_x2_dot, 1U, 1U, 4U, chartInstance->c5_sfEvent, false);
  *c5_x3_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c5_x3_dot, 2U, 1U, 4U, chartInstance->c5_sfEvent, false);
  *c5_x4_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c5_x4_dot, 3U, 1U, 4U, chartInstance->c5_sfEvent, false);
  *c5_x5_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c5_x5_dot, 4U, 1U, 4U, chartInstance->c5_sfEvent, false);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c5_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c5_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 0U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 1U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  if (!chartInstance->c5_dataWrittenToVector[0U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  if (!chartInstance->c5_dataWrittenToVector[2U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  if (!chartInstance->c5_dataWrittenToVector[3U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  if (!chartInstance->c5_dataWrittenToVector[4U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  c5_d0 = *chartInstance->c5_x3;
  c5_c_tanh(chartInstance, &c5_d0);
  c5_d1 = *chartInstance->c5_x4;
  c5_c_tanh(chartInstance, &c5_d1);
  c5_d2 = *chartInstance->c5_x5;
  c5_c_tanh(chartInstance, &c5_d2);
  *c5_x1_dot = ((-c5_mpower(chartInstance, 10.0) * *chartInstance->c5_x1 -
                 1.2033 * c5_d0) - 0.072 * c5_d1) - 0.9364 * c5_d2;
  _SFD_DATA_RANGE_CHECK(*c5_x1_dot, 0U, 4U, 0U, chartInstance->c5_sfEvent, false);
  if (!chartInstance->c5_dataWrittenToVector[1U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  if (!chartInstance->c5_dataWrittenToVector[2U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  if (!chartInstance->c5_dataWrittenToVector[3U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  if (!chartInstance->c5_dataWrittenToVector[4U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  c5_d3 = *chartInstance->c5_x3;
  c5_c_tanh(chartInstance, &c5_d3);
  c5_d4 = *chartInstance->c5_x4;
  c5_c_tanh(chartInstance, &c5_d4);
  c5_d5 = *chartInstance->c5_x5;
  c5_c_tanh(chartInstance, &c5_d5);
  *c5_x2_dot = ((-c5_mpower(chartInstance, 10.0) * *chartInstance->c5_x2 +
                 1.1881 * c5_d3) - 1.5002 * c5_d4) + 0.9352 * c5_d5;
  _SFD_DATA_RANGE_CHECK(*c5_x2_dot, 1U, 4U, 0U, chartInstance->c5_sfEvent, false);
  if (!chartInstance->c5_dataWrittenToVector[2U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  if (!chartInstance->c5_dataWrittenToVector[3U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  if (!chartInstance->c5_dataWrittenToVector[4U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  c5_d6 = *chartInstance->c5_x3;
  c5_c_tanh(chartInstance, &c5_d6);
  c5_d7 = *chartInstance->c5_x4;
  c5_c_tanh(chartInstance, &c5_d7);
  c5_d8 = *chartInstance->c5_x5;
  c5_c_tanh(chartInstance, &c5_d8);
  *c5_x3_dot = ((-c5_mpower(chartInstance, 10.0) * *chartInstance->c5_x3 -
                 1.5863 * c5_d6) + 0.0701 * c5_d7) - 1.2355 * c5_d8;
  chartInstance->c5_dataWrittenToVector[2U] = true;
  _SFD_DATA_RANGE_CHECK(*c5_x3_dot, 2U, 4U, 0U, chartInstance->c5_sfEvent, false);
  if (!chartInstance->c5_dataWrittenToVector[3U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  if (!chartInstance->c5_dataWrittenToVector[2U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  if (!chartInstance->c5_dataWrittenToVector[4U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  c5_d9 = *chartInstance->c5_x3;
  c5_c_tanh(chartInstance, &c5_d9);
  c5_d10 = *chartInstance->c5_x4;
  c5_c_tanh(chartInstance, &c5_d10);
  c5_d11 = *chartInstance->c5_x5;
  c5_c_tanh(chartInstance, &c5_d11);
  *c5_x4_dot = ((-c5_mpower(chartInstance, 10.0) * *chartInstance->c5_x4 +
                 0.0857 * c5_d9) - 0.2995 * c5_d10) + 0.0687 * c5_d11;
  chartInstance->c5_dataWrittenToVector[3U] = true;
  _SFD_DATA_RANGE_CHECK(*c5_x4_dot, 3U, 4U, 0U, chartInstance->c5_sfEvent, false);
  if (!chartInstance->c5_dataWrittenToVector[4U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  if (!chartInstance->c5_dataWrittenToVector[2U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  if (!chartInstance->c5_dataWrittenToVector[3U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  c5_d12 = *chartInstance->c5_x3;
  c5_c_tanh(chartInstance, &c5_d12);
  c5_d13 = *chartInstance->c5_x4;
  c5_c_tanh(chartInstance, &c5_d13);
  c5_d14 = *chartInstance->c5_x5;
  c5_c_tanh(chartInstance, &c5_d14);
  *c5_x5_dot = ((-c5_mpower(chartInstance, 10.0) * *chartInstance->c5_x5 +
                 1.7898 * c5_d12) - 0.0846 * c5_d13) + 1.394 * c5_d14;
  chartInstance->c5_dataWrittenToVector[4U] = true;
  _SFD_DATA_RANGE_CHECK(*c5_x5_dot, 4U, 4U, 0U, chartInstance->c5_sfEvent, false);
  if (!chartInstance->c5_dataWrittenToVector[0U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  chartInstance->c5_dataWrittenToVector[5U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c5_x1_out, 7U, 4U, 0U,
                        chartInstance->c5_sfEvent, false);
  if (!chartInstance->c5_dataWrittenToVector[1U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  chartInstance->c5_dataWrittenToVector[6U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c5_x2_out, 8U, 4U, 0U,
                        chartInstance->c5_sfEvent, false);
  if (!chartInstance->c5_dataWrittenToVector[2U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  chartInstance->c5_dataWrittenToVector[7U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c5_x3_out, 9U, 4U, 0U,
                        chartInstance->c5_sfEvent, false);
  if (!chartInstance->c5_dataWrittenToVector[3U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  chartInstance->c5_dataWrittenToVector[8U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c5_x4_out, 10U, 4U, 0U,
                        chartInstance->c5_sfEvent, false);
  if (!chartInstance->c5_dataWrittenToVector[4U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  chartInstance->c5_dataWrittenToVector[9U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c5_x5_out, 11U, 4U, 0U,
                        chartInstance->c5_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c5_sfEvent);
}

static void outputs_c5_CTRNNSLSF(SFc5_CTRNNSLSFInstanceStruct *chartInstance)
{
  uint32_T c5_debug_family_var_map[2];
  real_T c5_nargin = 0.0;
  real_T c5_nargout = 0.0;
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c5_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c5_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 0U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 1U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  if (!chartInstance->c5_dataWrittenToVector[0U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  if (!chartInstance->c5_dataWrittenToVector[2U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  if (!chartInstance->c5_dataWrittenToVector[3U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  if (!chartInstance->c5_dataWrittenToVector[4U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  if (!chartInstance->c5_dataWrittenToVector[1U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  if (!chartInstance->c5_dataWrittenToVector[2U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  if (!chartInstance->c5_dataWrittenToVector[3U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  if (!chartInstance->c5_dataWrittenToVector[4U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  if (!chartInstance->c5_dataWrittenToVector[2U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  if (!chartInstance->c5_dataWrittenToVector[3U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  if (!chartInstance->c5_dataWrittenToVector[4U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  chartInstance->c5_dataWrittenToVector[2U] = true;
  if (!chartInstance->c5_dataWrittenToVector[3U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  if (!chartInstance->c5_dataWrittenToVector[2U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  if (!chartInstance->c5_dataWrittenToVector[4U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  chartInstance->c5_dataWrittenToVector[3U] = true;
  if (!chartInstance->c5_dataWrittenToVector[4U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  if (!chartInstance->c5_dataWrittenToVector[2U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  if (!chartInstance->c5_dataWrittenToVector[3U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  chartInstance->c5_dataWrittenToVector[4U] = true;
  if (!chartInstance->c5_dataWrittenToVector[0U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  *chartInstance->c5_x1_out = *chartInstance->c5_x1;
  chartInstance->c5_dataWrittenToVector[5U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c5_x1_out, 7U, 4U, 0U,
                        chartInstance->c5_sfEvent, false);
  if (!chartInstance->c5_dataWrittenToVector[1U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  *chartInstance->c5_x2_out = *chartInstance->c5_x2;
  chartInstance->c5_dataWrittenToVector[6U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c5_x2_out, 8U, 4U, 0U,
                        chartInstance->c5_sfEvent, false);
  if (!chartInstance->c5_dataWrittenToVector[2U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  *chartInstance->c5_x3_out = *chartInstance->c5_x3;
  chartInstance->c5_dataWrittenToVector[7U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c5_x3_out, 9U, 4U, 0U,
                        chartInstance->c5_sfEvent, false);
  if (!chartInstance->c5_dataWrittenToVector[3U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  *chartInstance->c5_x4_out = *chartInstance->c5_x4;
  chartInstance->c5_dataWrittenToVector[8U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c5_x4_out, 10U, 4U, 0U,
                        chartInstance->c5_sfEvent, false);
  if (!chartInstance->c5_dataWrittenToVector[4U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 0U, chartInstance->c5_sfEvent,
      false);
  }

  *chartInstance->c5_x5_out = *chartInstance->c5_x5;
  chartInstance->c5_dataWrittenToVector[9U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c5_x5_out, 11U, 4U, 0U,
                        chartInstance->c5_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c5_sfEvent);
}

static void initSimStructsc5_CTRNNSLSF(SFc5_CTRNNSLSFInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c5_eml_ini_fcn_to_be_inlined_60(SFc5_CTRNNSLSFInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c5_eml_term_fcn_to_be_inlined_60(SFc5_CTRNNSLSFInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static real_T c5_mpower(SFc5_CTRNNSLSFInstanceStruct *chartInstance, real_T c5_a)
{
  return c5_power(chartInstance, c5_a);
}

static real_T c5_power(SFc5_CTRNNSLSFInstanceStruct *chartInstance, real_T c5_a)
{
  return c5_fltpower(chartInstance, c5_a);
}

static real_T c5_fltpower(SFc5_CTRNNSLSFInstanceStruct *chartInstance, real_T
  c5_a)
{
  real_T c5_y;
  c5_y = c5_applyScalarFunction(chartInstance, c5_a);
  if (c5_fltpower_domain_error(chartInstance, c5_a, -6.0)) {
    c5_error(chartInstance);
  }

  return c5_y;
}

static real_T c5_applyScalarFunction(SFc5_CTRNNSLSFInstanceStruct *chartInstance,
  real_T c5_x)
{
  return c5_scalar_float_power(chartInstance, c5_x);
}

static real_T c5_scalar_float_power(SFc5_CTRNNSLSFInstanceStruct *chartInstance,
  real_T c5_a)
{
  (void)chartInstance;
  return muDoubleScalarPower(c5_a, -6.0);
}

static boolean_T c5_fltpower_domain_error(SFc5_CTRNNSLSFInstanceStruct
  *chartInstance, real_T c5_a, real_T c5_b)
{
  boolean_T c5_p;
  real_T c5_d15;
  boolean_T c5_b_p;
  boolean_T c5_b0;
  c5_p = false;
  if (c5_a < 0.0) {
    if (c5_p) {
      c5_b_p = true;
    } else {
      if (c5_isnan(chartInstance, c5_b)) {
        c5_b0 = true;
      } else {
        c5_d15 = c5_b;
        c5_c_floor(chartInstance, &c5_d15);
        if (c5_d15 == c5_b) {
          c5_b0 = true;
        } else {
          c5_b0 = false;
        }
      }

      if (!c5_b0) {
        c5_b_p = true;
      } else {
        c5_b_p = false;
      }
    }

    c5_p = c5_b_p;
  }

  return c5_p;
}

static boolean_T c5_isnan(SFc5_CTRNNSLSFInstanceStruct *chartInstance, real_T
  c5_x)
{
  (void)chartInstance;
  return muDoubleScalarIsNaN(c5_x);
}

static real_T c5_floor(SFc5_CTRNNSLSFInstanceStruct *chartInstance, real_T c5_x)
{
  real_T c5_b_x;
  c5_b_x = c5_x;
  c5_c_floor(chartInstance, &c5_b_x);
  return c5_b_x;
}

static real_T c5_applyScalarFunctionInPlace(SFc5_CTRNNSLSFInstanceStruct
  *chartInstance, real_T c5_x)
{
  real_T c5_b_x;
  c5_b_x = c5_x;
  c5_c_applyScalarFunctionInPlace(chartInstance, &c5_b_x);
  return c5_b_x;
}

static real_T c5_b_floor(SFc5_CTRNNSLSFInstanceStruct *chartInstance, real_T
  c5_x)
{
  real_T c5_b_x;
  c5_b_x = c5_x;
  c5_d_floor(chartInstance, &c5_b_x);
  return c5_b_x;
}

static void c5_error(SFc5_CTRNNSLSFInstanceStruct *chartInstance)
{
  static char_T c5_cv0[31] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'p', 'o', 'w', 'e', 'r', '_', 'd', 'o', 'm', 'a', 'i',
    'n', 'E', 'r', 'r', 'o', 'r' };

  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c5_emlrt_marshallOut(chartInstance, c5_cv0)));
}

static real_T c5_tanh(SFc5_CTRNNSLSFInstanceStruct *chartInstance, real_T c5_x)
{
  real_T c5_b_x;
  c5_b_x = c5_x;
  c5_c_tanh(chartInstance, &c5_b_x);
  return c5_b_x;
}

static real_T c5_b_applyScalarFunctionInPlace(SFc5_CTRNNSLSFInstanceStruct
  *chartInstance, real_T c5_x)
{
  real_T c5_b_x;
  c5_b_x = c5_x;
  c5_d_applyScalarFunctionInPlace(chartInstance, &c5_b_x);
  return c5_b_x;
}

static real_T c5_b_tanh(SFc5_CTRNNSLSFInstanceStruct *chartInstance, real_T c5_x)
{
  real_T c5_b_x;
  c5_b_x = c5_x;
  c5_d_tanh(chartInstance, &c5_b_x);
  return c5_b_x;
}

static real_T c5_b_mpower(SFc5_CTRNNSLSFInstanceStruct *chartInstance, real_T
  c5_a)
{
  return c5_b_power(chartInstance, c5_a);
}

static real_T c5_b_power(SFc5_CTRNNSLSFInstanceStruct *chartInstance, real_T
  c5_a)
{
  return c5_b_fltpower(chartInstance, c5_a);
}

static real_T c5_b_fltpower(SFc5_CTRNNSLSFInstanceStruct *chartInstance, real_T
  c5_a)
{
  real_T c5_y;
  c5_y = c5_b_applyScalarFunction(chartInstance, c5_a);
  if (c5_fltpower_domain_error(chartInstance, c5_a, -5.0)) {
    c5_error(chartInstance);
  }

  return c5_y;
}

static real_T c5_b_applyScalarFunction(SFc5_CTRNNSLSFInstanceStruct
  *chartInstance, real_T c5_x)
{
  return c5_b_scalar_float_power(chartInstance, c5_x);
}

static real_T c5_b_scalar_float_power(SFc5_CTRNNSLSFInstanceStruct
  *chartInstance, real_T c5_a)
{
  (void)chartInstance;
  return muDoubleScalarPower(c5_a, -5.0);
}

static real_T c5_c_mpower(SFc5_CTRNNSLSFInstanceStruct *chartInstance, real_T
  c5_a)
{
  return c5_c_power(chartInstance, c5_a);
}

static real_T c5_c_power(SFc5_CTRNNSLSFInstanceStruct *chartInstance, real_T
  c5_a)
{
  return c5_c_fltpower(chartInstance, c5_a);
}

static real_T c5_c_fltpower(SFc5_CTRNNSLSFInstanceStruct *chartInstance, real_T
  c5_a)
{
  real_T c5_y;
  c5_y = c5_c_applyScalarFunction(chartInstance, c5_a);
  if (c5_fltpower_domain_error(chartInstance, c5_a, -4.0)) {
    c5_error(chartInstance);
  }

  return c5_y;
}

static real_T c5_c_applyScalarFunction(SFc5_CTRNNSLSFInstanceStruct
  *chartInstance, real_T c5_x)
{
  return c5_c_scalar_float_power(chartInstance, c5_x);
}

static real_T c5_c_scalar_float_power(SFc5_CTRNNSLSFInstanceStruct
  *chartInstance, real_T c5_a)
{
  (void)chartInstance;
  return muDoubleScalarPower(c5_a, -4.0);
}

static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber, uint32_T c5_instanceNumber)
{
  (void)(c5_machineNumber);
  (void)(c5_chartNumber);
  (void)(c5_instanceNumber);
}

static const mxArray *c5_emlrt_marshallOut(SFc5_CTRNNSLSFInstanceStruct
  *chartInstance, const char_T c5_u[31])
{
  const mxArray *c5_y = NULL;
  (void)chartInstance;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 10, 0U, 1U, 0U, 2, 1, 31), false);
  return c5_y;
}

static const mxArray *c5_b_emlrt_marshallOut(SFc5_CTRNNSLSFInstanceStruct
  *chartInstance, const real_T c5_u)
{
  const mxArray *c5_y = NULL;
  (void)chartInstance;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), false);
  return c5_y;
}

static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  SFc5_CTRNNSLSFInstanceStruct *chartInstance;
  chartInstance = (SFc5_CTRNNSLSFInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  sf_mex_assign(&c5_mxArrayOutData, c5_b_emlrt_marshallOut(chartInstance,
    *(real_T *)c5_inData), false);
  return c5_mxArrayOutData;
}

static real_T c5_emlrt_marshallIn(SFc5_CTRNNSLSFInstanceStruct *chartInstance,
  const mxArray *c5_nargout, const char_T *c5_identifier)
{
  real_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = (const char *)c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_y = c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_nargout), &c5_thisId);
  sf_mex_destroy(&c5_nargout);
  return c5_y;
}

static real_T c5_b_emlrt_marshallIn(SFc5_CTRNNSLSFInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  real_T c5_y;
  real_T c5_d16;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_d16, 1, 0, 0U, 0, 0U, 0);
  c5_y = c5_d16;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  SFc5_CTRNNSLSFInstanceStruct *chartInstance;
  chartInstance = (SFc5_CTRNNSLSFInstanceStruct *)chartInstanceVoid;
  *(real_T *)c5_outData = c5_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c5_mxArrayInData), c5_varName);
  sf_mex_destroy(&c5_mxArrayInData);
}

const mxArray *sf_c5_CTRNNSLSF_get_eml_resolved_functions_info(void)
{
  const mxArray *c5_nameCaptureInfo = NULL;
  c5_nameCaptureInfo = NULL;
  sf_mex_assign(&c5_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c5_nameCaptureInfo;
}

static const mxArray *c5_c_emlrt_marshallOut(SFc5_CTRNNSLSFInstanceStruct
  *chartInstance, const int32_T c5_u)
{
  const mxArray *c5_y = NULL;
  (void)chartInstance;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 6, 0U, 0U, 0U, 0), false);
  return c5_y;
}

static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  SFc5_CTRNNSLSFInstanceStruct *chartInstance;
  chartInstance = (SFc5_CTRNNSLSFInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  sf_mex_assign(&c5_mxArrayOutData, c5_c_emlrt_marshallOut(chartInstance,
    *(int32_T *)c5_inData), false);
  return c5_mxArrayOutData;
}

static int32_T c5_c_emlrt_marshallIn(SFc5_CTRNNSLSFInstanceStruct *chartInstance,
  const mxArray *c5_b_sfEvent, const char_T *c5_identifier)
{
  int32_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = (const char *)c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_y = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_sfEvent),
    &c5_thisId);
  sf_mex_destroy(&c5_b_sfEvent);
  return c5_y;
}

static int32_T c5_d_emlrt_marshallIn(SFc5_CTRNNSLSFInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  int32_T c5_y;
  int32_T c5_i0;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_i0, 1, 6, 0U, 0, 0U, 0);
  c5_y = c5_i0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  SFc5_CTRNNSLSFInstanceStruct *chartInstance;
  chartInstance = (SFc5_CTRNNSLSFInstanceStruct *)chartInstanceVoid;
  *(int32_T *)c5_outData = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c5_mxArrayInData), c5_varName);
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_d_emlrt_marshallOut(SFc5_CTRNNSLSFInstanceStruct
  *chartInstance, const uint8_T c5_u)
{
  const mxArray *c5_y = NULL;
  (void)chartInstance;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 3, 0U, 0U, 0U, 0), false);
  return c5_y;
}

static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  SFc5_CTRNNSLSFInstanceStruct *chartInstance;
  chartInstance = (SFc5_CTRNNSLSFInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  sf_mex_assign(&c5_mxArrayOutData, c5_d_emlrt_marshallOut(chartInstance,
    *(uint8_T *)c5_inData), false);
  return c5_mxArrayOutData;
}

static uint8_T c5_e_emlrt_marshallIn(SFc5_CTRNNSLSFInstanceStruct *chartInstance,
  const mxArray *c5_b_tp_Falling, const char_T *c5_identifier)
{
  uint8_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = (const char *)c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_y = c5_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_tp_Falling),
    &c5_thisId);
  sf_mex_destroy(&c5_b_tp_Falling);
  return c5_y;
}

static uint8_T c5_f_emlrt_marshallIn(SFc5_CTRNNSLSFInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  uint8_T c5_y;
  uint8_T c5_u0;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_u0, 1, 3, 0U, 0, 0U, 0);
  c5_y = c5_u0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  SFc5_CTRNNSLSFInstanceStruct *chartInstance;
  chartInstance = (SFc5_CTRNNSLSFInstanceStruct *)chartInstanceVoid;
  *(uint8_T *)c5_outData = c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c5_mxArrayInData), c5_varName);
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_e_emlrt_marshallOut(SFc5_CTRNNSLSFInstanceStruct
  *chartInstance)
{
  const mxArray *c5_y;
  int32_T c5_i1;
  boolean_T c5_bv0[10];
  c5_y = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_createcellmatrix(13, 1), false);
  sf_mex_setcell(c5_y, 0, c5_b_emlrt_marshallOut(chartInstance,
    *chartInstance->c5_x1_out));
  sf_mex_setcell(c5_y, 1, c5_b_emlrt_marshallOut(chartInstance,
    *chartInstance->c5_x2_out));
  sf_mex_setcell(c5_y, 2, c5_b_emlrt_marshallOut(chartInstance,
    *chartInstance->c5_x3_out));
  sf_mex_setcell(c5_y, 3, c5_b_emlrt_marshallOut(chartInstance,
    *chartInstance->c5_x4_out));
  sf_mex_setcell(c5_y, 4, c5_b_emlrt_marshallOut(chartInstance,
    *chartInstance->c5_x5_out));
  sf_mex_setcell(c5_y, 5, c5_b_emlrt_marshallOut(chartInstance,
    *chartInstance->c5_x1));
  sf_mex_setcell(c5_y, 6, c5_b_emlrt_marshallOut(chartInstance,
    *chartInstance->c5_x2));
  sf_mex_setcell(c5_y, 7, c5_b_emlrt_marshallOut(chartInstance,
    *chartInstance->c5_x3));
  sf_mex_setcell(c5_y, 8, c5_b_emlrt_marshallOut(chartInstance,
    *chartInstance->c5_x4));
  sf_mex_setcell(c5_y, 9, c5_b_emlrt_marshallOut(chartInstance,
    *chartInstance->c5_x5));
  sf_mex_setcell(c5_y, 10, c5_d_emlrt_marshallOut(chartInstance,
    chartInstance->c5_is_active_c5_CTRNNSLSF));
  sf_mex_setcell(c5_y, 11, c5_d_emlrt_marshallOut(chartInstance,
    chartInstance->c5_is_c5_CTRNNSLSF));
  for (c5_i1 = 0; c5_i1 < 10; c5_i1++) {
    c5_bv0[c5_i1] = chartInstance->c5_dataWrittenToVector[c5_i1];
  }

  sf_mex_setcell(c5_y, 12, c5_f_emlrt_marshallOut(chartInstance, c5_bv0));
  return c5_y;
}

static const mxArray *c5_f_emlrt_marshallOut(SFc5_CTRNNSLSFInstanceStruct
  *chartInstance, const boolean_T c5_u[10])
{
  const mxArray *c5_y = NULL;
  (void)chartInstance;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 11, 0U, 1U, 0U, 1, 10), false);
  return c5_y;
}

static void c5_g_emlrt_marshallIn(SFc5_CTRNNSLSFInstanceStruct *chartInstance,
  const mxArray *c5_u)
{
  boolean_T c5_bv1[10];
  int32_T c5_i2;
  *chartInstance->c5_x1_out = c5_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("x1_out", c5_u, 0)), "x1_out");
  *chartInstance->c5_x2_out = c5_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("x2_out", c5_u, 1)), "x2_out");
  *chartInstance->c5_x3_out = c5_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("x3_out", c5_u, 2)), "x3_out");
  *chartInstance->c5_x4_out = c5_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("x4_out", c5_u, 3)), "x4_out");
  *chartInstance->c5_x5_out = c5_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("x5_out", c5_u, 4)), "x5_out");
  *chartInstance->c5_x1 = c5_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("x1", c5_u, 5)), "x1");
  *chartInstance->c5_x2 = c5_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("x2", c5_u, 6)), "x2");
  *chartInstance->c5_x3 = c5_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("x3", c5_u, 7)), "x3");
  *chartInstance->c5_x4 = c5_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("x4", c5_u, 8)), "x4");
  *chartInstance->c5_x5 = c5_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("x5", c5_u, 9)), "x5");
  chartInstance->c5_is_active_c5_CTRNNSLSF = c5_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_active_c5_CTRNNSLSF", c5_u, 10)),
    "is_active_c5_CTRNNSLSF");
  chartInstance->c5_is_c5_CTRNNSLSF = c5_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_c5_CTRNNSLSF", c5_u, 11)), "is_c5_CTRNNSLSF");
  c5_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "dataWrittenToVector", c5_u, 12)), "dataWrittenToVector", c5_bv1);
  for (c5_i2 = 0; c5_i2 < 10; c5_i2++) {
    chartInstance->c5_dataWrittenToVector[c5_i2] = c5_bv1[c5_i2];
  }

  sf_mex_assign(&chartInstance->c5_setSimStateSideEffectsInfo,
                c5_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "setSimStateSideEffectsInfo", c5_u, 13)), "setSimStateSideEffectsInfo"),
                true);
  sf_mex_destroy(&c5_u);
}

static void c5_h_emlrt_marshallIn(SFc5_CTRNNSLSFInstanceStruct *chartInstance,
  const mxArray *c5_b_dataWrittenToVector, const char_T *c5_identifier,
  boolean_T c5_y[10])
{
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = (const char *)c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_dataWrittenToVector),
                        &c5_thisId, c5_y);
  sf_mex_destroy(&c5_b_dataWrittenToVector);
}

static void c5_i_emlrt_marshallIn(SFc5_CTRNNSLSFInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, boolean_T c5_y[10])
{
  boolean_T c5_bv2[10];
  int32_T c5_i3;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_bv2, 1, 11, 0U, 1, 0U, 1, 10);
  for (c5_i3 = 0; c5_i3 < 10; c5_i3++) {
    c5_y[c5_i3] = c5_bv2[c5_i3];
  }

  sf_mex_destroy(&c5_u);
}

static const mxArray *c5_j_emlrt_marshallIn(SFc5_CTRNNSLSFInstanceStruct
  *chartInstance, const mxArray *c5_b_setSimStateSideEffectsInfo, const char_T
  *c5_identifier)
{
  const mxArray *c5_y = NULL;
  emlrtMsgIdentifier c5_thisId;
  c5_y = NULL;
  c5_thisId.fIdentifier = (const char *)c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  sf_mex_assign(&c5_y, c5_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c5_b_setSimStateSideEffectsInfo), &c5_thisId), false);
  sf_mex_destroy(&c5_b_setSimStateSideEffectsInfo);
  return c5_y;
}

static const mxArray *c5_k_emlrt_marshallIn(SFc5_CTRNNSLSFInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  const mxArray *c5_y = NULL;
  (void)chartInstance;
  (void)c5_parentId;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_duplicatearraysafe(&c5_u), false);
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static const mxArray *sf_get_hover_data_for_msg(SFc5_CTRNNSLSFInstanceStruct
  *chartInstance, int32_T c5_ssid)
{
  const mxArray *c5_msgInfo;
  (void)chartInstance;
  (void)c5_ssid;
  c5_msgInfo = NULL;
  return NULL;
}

static void c5_init_sf_message_store_memory(SFc5_CTRNNSLSFInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c5_c_floor(SFc5_CTRNNSLSFInstanceStruct *chartInstance, real_T *c5_x)
{
  c5_c_applyScalarFunctionInPlace(chartInstance, c5_x);
}

static void c5_c_applyScalarFunctionInPlace(SFc5_CTRNNSLSFInstanceStruct
  *chartInstance, real_T *c5_x)
{
  c5_d_floor(chartInstance, c5_x);
}

static void c5_d_floor(SFc5_CTRNNSLSFInstanceStruct *chartInstance, real_T *c5_x)
{
  (void)chartInstance;
  *c5_x = muDoubleScalarFloor(*c5_x);
}

static void c5_c_tanh(SFc5_CTRNNSLSFInstanceStruct *chartInstance, real_T *c5_x)
{
  c5_d_applyScalarFunctionInPlace(chartInstance, c5_x);
}

static void c5_d_applyScalarFunctionInPlace(SFc5_CTRNNSLSFInstanceStruct
  *chartInstance, real_T *c5_x)
{
  c5_d_tanh(chartInstance, c5_x);
}

static void c5_d_tanh(SFc5_CTRNNSLSFInstanceStruct *chartInstance, real_T *c5_x)
{
  (void)chartInstance;
  *c5_x = muDoubleScalarTanh(*c5_x);
}

static void init_dsm_address_info(SFc5_CTRNNSLSFInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc5_CTRNNSLSFInstanceStruct *chartInstance)
{
  chartInstance->c5_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c5_x1 = (real_T *)(ssGetContStates_wrapper(chartInstance->S) +
    0);
  chartInstance->c5_x2 = (real_T *)(ssGetContStates_wrapper(chartInstance->S) +
    1);
  chartInstance->c5_x3 = (real_T *)(ssGetContStates_wrapper(chartInstance->S) +
    2);
  chartInstance->c5_x4 = (real_T *)(ssGetContStates_wrapper(chartInstance->S) +
    3);
  chartInstance->c5_x5 = (real_T *)(ssGetContStates_wrapper(chartInstance->S) +
    4);
  chartInstance->c5_x1_out = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c5_x2_out = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c5_x3_out = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c5_x4_out = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c5_x5_out = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c5_x10 = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c5_x20 = (real_T *)ssGetInputPortSignal_wrapper
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

void sf_c5_CTRNNSLSF_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2379508610U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3915820851U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1120413599U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3857389381U);
}

mxArray* sf_c5_CTRNNSLSF_get_post_codegen_info(void);
mxArray *sf_c5_CTRNNSLSF_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("NQDkDCxGMc1GBg3Y2cxaGC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
    mxArray* mxPostCodegenInfo = sf_c5_CTRNNSLSF_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c5_CTRNNSLSF_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c5_CTRNNSLSF_jit_fallback_info(void)
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

mxArray *sf_c5_CTRNNSLSF_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c5_CTRNNSLSF_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c5_CTRNNSLSF(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[17],T\"x1_out\",},{M[1],M[18],T\"x2_out\",},{M[1],M[19],T\"x3_out\",},{M[1],M[20],T\"x4_out\",},{M[1],M[21],T\"x5_out\",},{M[5],M[12],T\"x1\",},{M[5],M[13],T\"x2\",},{M[5],M[14],T\"x3\",},{M[5],M[15],T\"x4\",},{M[5],M[16],T\"x5\",}}",
    "100 S1x3'type','srcId','name','auxInfo'{{M[8],M[0],T\"is_active_c5_CTRNNSLSF\",},{M[9],M[0],T\"is_c5_CTRNNSLSF\",},{M[15],M[0],T\"dataWrittenToVector\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 13, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_CTRNNSLSF_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const mxArray* sf_opaque_get_hover_data_for_msg(void* chartInstance,
  int32_T msgSSID)
{
  return sf_get_hover_data_for_msg( (SFc5_CTRNNSLSFInstanceStruct *)
    chartInstance, msgSSID);
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc5_CTRNNSLSFInstanceStruct *chartInstance = (SFc5_CTRNNSLSFInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _CTRNNSLSFMachineNumber_,
           5,
           1,
           1,
           0,
           12,
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
          _SFD_SET_DATA_PROPS(5,1,1,0,"x10");
          _SFD_SET_DATA_PROPS(6,1,1,0,"x20");
          _SFD_SET_DATA_PROPS(7,2,0,1,"x1_out");
          _SFD_SET_DATA_PROPS(8,2,0,1,"x2_out");
          _SFD_SET_DATA_PROPS(9,2,0,1,"x3_out");
          _SFD_SET_DATA_PROPS(10,2,0,1,"x4_out");
          _SFD_SET_DATA_PROPS(11,2,0,1,"x5_out");
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
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
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
    SFc5_CTRNNSLSFInstanceStruct *chartInstance = (SFc5_CTRNNSLSFInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)chartInstance->c5_x1);
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)chartInstance->c5_x2);
        _SFD_SET_DATA_VALUE_PTR(2U, (void *)chartInstance->c5_x3);
        _SFD_SET_DATA_VALUE_PTR(3U, (void *)chartInstance->c5_x4);
        _SFD_SET_DATA_VALUE_PTR(4U, (void *)chartInstance->c5_x5);
        _SFD_SET_DATA_VALUE_PTR(7U, (void *)chartInstance->c5_x1_out);
        _SFD_SET_DATA_VALUE_PTR(8U, (void *)chartInstance->c5_x2_out);
        _SFD_SET_DATA_VALUE_PTR(9U, (void *)chartInstance->c5_x3_out);
        _SFD_SET_DATA_VALUE_PTR(10U, (void *)chartInstance->c5_x4_out);
        _SFD_SET_DATA_VALUE_PTR(11U, (void *)chartInstance->c5_x5_out);
        _SFD_SET_DATA_VALUE_PTR(5U, (void *)chartInstance->c5_x10);
        _SFD_SET_DATA_VALUE_PTR(6U, (void *)chartInstance->c5_x20);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sk7tJY7x9lgpg4F8HWx3GiD";
}

static void sf_opaque_initialize_c5_CTRNNSLSF(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc5_CTRNNSLSFInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c5_CTRNNSLSF((SFc5_CTRNNSLSFInstanceStruct*)
    chartInstanceVar);
  initialize_c5_CTRNNSLSF((SFc5_CTRNNSLSFInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c5_CTRNNSLSF(void *chartInstanceVar)
{
  enable_c5_CTRNNSLSF((SFc5_CTRNNSLSFInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c5_CTRNNSLSF(void *chartInstanceVar)
{
  disable_c5_CTRNNSLSF((SFc5_CTRNNSLSFInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_zeroCrossings_c5_CTRNNSLSF(void *chartInstanceVar)
{
  zeroCrossings_c5_CTRNNSLSF((SFc5_CTRNNSLSFInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_derivatives_c5_CTRNNSLSF(void *chartInstanceVar)
{
  derivatives_c5_CTRNNSLSF((SFc5_CTRNNSLSFInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_outputs_c5_CTRNNSLSF(void *chartInstanceVar)
{
  outputs_c5_CTRNNSLSF((SFc5_CTRNNSLSFInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c5_CTRNNSLSF(void *chartInstanceVar)
{
  sf_gateway_c5_CTRNNSLSF((SFc5_CTRNNSLSFInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c5_CTRNNSLSF(SimStruct* S)
{
  return get_sim_state_c5_CTRNNSLSF((SFc5_CTRNNSLSFInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c5_CTRNNSLSF(SimStruct* S, const mxArray *st)
{
  set_sim_state_c5_CTRNNSLSF((SFc5_CTRNNSLSFInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c5_CTRNNSLSF(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_CTRNNSLSFInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_CTRNNSLSF_optimization_info();
    }

    finalize_c5_CTRNNSLSF((SFc5_CTRNNSLSFInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc5_CTRNNSLSF((SFc5_CTRNNSLSFInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_CTRNNSLSF(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c5_CTRNNSLSF((SFc5_CTRNNSLSFInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c5_CTRNNSLSF(SimStruct *S)
{
  ssSetStatesModifiedOnlyInUpdate(S, 0);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_CTRNNSLSF_optimization_info(sim_mode_is_rtw_gen(S),
      sim_mode_is_modelref_sim(S), sim_mode_is_external(S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,5);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,5,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 5);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,5);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,5,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,5,5);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=5; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,5);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetCallsOutputInInitFcn(S,1);
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(330836568U));
  ssSetChecksum1(S,(259962893U));
  ssSetChecksum2(S,(2449017953U));
  ssSetChecksum3(S,(102981126U));
  ssSetNumContStates(S,5);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c5_CTRNNSLSF(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c5_CTRNNSLSF(SimStruct *S)
{
  SFc5_CTRNNSLSFInstanceStruct *chartInstance;
  chartInstance = (SFc5_CTRNNSLSFInstanceStruct *)utMalloc(sizeof
    (SFc5_CTRNNSLSFInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc5_CTRNNSLSFInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c5_CTRNNSLSF;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c5_CTRNNSLSF;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c5_CTRNNSLSF;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c5_CTRNNSLSF;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c5_CTRNNSLSF;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c5_CTRNNSLSF;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c5_CTRNNSLSF;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c5_CTRNNSLSF;
  chartInstance->chartInfo.zeroCrossings = sf_opaque_zeroCrossings_c5_CTRNNSLSF;
  chartInstance->chartInfo.outputs = sf_opaque_outputs_c5_CTRNNSLSF;
  chartInstance->chartInfo.derivatives = sf_opaque_derivatives_c5_CTRNNSLSF;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c5_CTRNNSLSF;
  chartInstance->chartInfo.mdlStart = mdlStart_c5_CTRNNSLSF;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c5_CTRNNSLSF;
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
  mdl_start_c5_CTRNNSLSF(chartInstance);
}

void c5_CTRNNSLSF_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c5_CTRNNSLSF(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_CTRNNSLSF(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_CTRNNSLSF(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_CTRNNSLSF_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
