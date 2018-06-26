/* Include files */

#include "CTRNNSLSF_sfun.h"
#include "CTRNNSLSF_sfun_debug_macros.h"
#include "c1_CTRNNSLSF.h"
#include "c2_CTRNNSLSF.h"
#include "c3_CTRNNSLSF.h"
#include "c4_CTRNNSLSF.h"
#include "c5_CTRNNSLSF.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _CTRNNSLSFMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void CTRNNSLSF_initializer(void)
{
}

void CTRNNSLSF_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_CTRNNSLSF_method_dispatcher(SimStruct *simstructPtr, unsigned
  int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_CTRNNSLSF_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_CTRNNSLSF_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_CTRNNSLSF_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_CTRNNSLSF_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_CTRNNSLSF_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_CTRNNSLSF_process_check_sum_call( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(746854116U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2604883438U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2514797205U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3201696966U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_CTRNNSLSF_get_check_sum(mxArray *plhs[]);
          sf_c1_CTRNNSLSF_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_CTRNNSLSF_get_check_sum(mxArray *plhs[]);
          sf_c2_CTRNNSLSF_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_CTRNNSLSF_get_check_sum(mxArray *plhs[]);
          sf_c3_CTRNNSLSF_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_CTRNNSLSF_get_check_sum(mxArray *plhs[]);
          sf_c4_CTRNNSLSF_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_CTRNNSLSF_get_check_sum(mxArray *plhs[]);
          sf_c5_CTRNNSLSF_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(97065511U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(908675992U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3299048847U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(546220334U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3669337301U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3828240615U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3648700201U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1733257581U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_CTRNNSLSF_autoinheritance_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(aiChksum, "w6VaORY0hML30xhGiBSY8G") == 0) {
          extern mxArray *sf_c1_CTRNNSLSF_get_autoinheritance_info(void);
          plhs[0] = sf_c1_CTRNNSLSF_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "7IfDhBfQ817GH1J7Oc8KnH") == 0) {
          extern mxArray *sf_c2_CTRNNSLSF_get_autoinheritance_info(void);
          plhs[0] = sf_c2_CTRNNSLSF_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "EkNmo02n5Ry3vd1JVe4CtD") == 0) {
          extern mxArray *sf_c3_CTRNNSLSF_get_autoinheritance_info(void);
          plhs[0] = sf_c3_CTRNNSLSF_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "w6VaORY0hML30xhGiBSY8G") == 0) {
          extern mxArray *sf_c4_CTRNNSLSF_get_autoinheritance_info(void);
          plhs[0] = sf_c4_CTRNNSLSF_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "NQDkDCxGMc1GBg3Y2cxaGC") == 0) {
          extern mxArray *sf_c5_CTRNNSLSF_get_autoinheritance_info(void);
          plhs[0] = sf_c5_CTRNNSLSF_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_CTRNNSLSF_get_eml_resolved_functions_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern const mxArray *sf_c1_CTRNNSLSF_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_CTRNNSLSF_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray *sf_c2_CTRNNSLSF_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_CTRNNSLSF_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray *sf_c3_CTRNNSLSF_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_CTRNNSLSF_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray *sf_c4_CTRNNSLSF_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_CTRNNSLSF_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray *sf_c5_CTRNNSLSF_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_CTRNNSLSF_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_CTRNNSLSF_third_party_uses_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "ssgVr6IAOaGJ0ipVzgwHi2E") == 0) {
          extern mxArray *sf_c1_CTRNNSLSF_third_party_uses_info(void);
          plhs[0] = sf_c1_CTRNNSLSF_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "su0lzTC9WHgvXsdP8tbZh3C") == 0) {
          extern mxArray *sf_c2_CTRNNSLSF_third_party_uses_info(void);
          plhs[0] = sf_c2_CTRNNSLSF_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "syxBOvQuUDi1W3syRK4zbH") == 0) {
          extern mxArray *sf_c3_CTRNNSLSF_third_party_uses_info(void);
          plhs[0] = sf_c3_CTRNNSLSF_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "sEv4M3cmsakjkIpAKNTNeGF") == 0) {
          extern mxArray *sf_c4_CTRNNSLSF_third_party_uses_info(void);
          plhs[0] = sf_c4_CTRNNSLSF_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "sk7tJY7x9lgpg4F8HWx3GiD") == 0) {
          extern mxArray *sf_c5_CTRNNSLSF_third_party_uses_info(void);
          plhs[0] = sf_c5_CTRNNSLSF_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_CTRNNSLSF_jit_fallback_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the jit_fallback_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_jit_fallback_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "ssgVr6IAOaGJ0ipVzgwHi2E") == 0) {
          extern mxArray *sf_c1_CTRNNSLSF_jit_fallback_info(void);
          plhs[0] = sf_c1_CTRNNSLSF_jit_fallback_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "su0lzTC9WHgvXsdP8tbZh3C") == 0) {
          extern mxArray *sf_c2_CTRNNSLSF_jit_fallback_info(void);
          plhs[0] = sf_c2_CTRNNSLSF_jit_fallback_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "syxBOvQuUDi1W3syRK4zbH") == 0) {
          extern mxArray *sf_c3_CTRNNSLSF_jit_fallback_info(void);
          plhs[0] = sf_c3_CTRNNSLSF_jit_fallback_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "sEv4M3cmsakjkIpAKNTNeGF") == 0) {
          extern mxArray *sf_c4_CTRNNSLSF_jit_fallback_info(void);
          plhs[0] = sf_c4_CTRNNSLSF_jit_fallback_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "sk7tJY7x9lgpg4F8HWx3GiD") == 0) {
          extern mxArray *sf_c5_CTRNNSLSF_jit_fallback_info(void);
          plhs[0] = sf_c5_CTRNNSLSF_jit_fallback_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_CTRNNSLSF_updateBuildInfo_args_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the updateBuildInfo_args_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_updateBuildInfo_args_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "ssgVr6IAOaGJ0ipVzgwHi2E") == 0) {
          extern mxArray *sf_c1_CTRNNSLSF_updateBuildInfo_args_info(void);
          plhs[0] = sf_c1_CTRNNSLSF_updateBuildInfo_args_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "su0lzTC9WHgvXsdP8tbZh3C") == 0) {
          extern mxArray *sf_c2_CTRNNSLSF_updateBuildInfo_args_info(void);
          plhs[0] = sf_c2_CTRNNSLSF_updateBuildInfo_args_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "syxBOvQuUDi1W3syRK4zbH") == 0) {
          extern mxArray *sf_c3_CTRNNSLSF_updateBuildInfo_args_info(void);
          plhs[0] = sf_c3_CTRNNSLSF_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "sEv4M3cmsakjkIpAKNTNeGF") == 0) {
          extern mxArray *sf_c4_CTRNNSLSF_updateBuildInfo_args_info(void);
          plhs[0] = sf_c4_CTRNNSLSF_updateBuildInfo_args_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "sk7tJY7x9lgpg4F8HWx3GiD") == 0) {
          extern mxArray *sf_c5_CTRNNSLSF_updateBuildInfo_args_info(void);
          plhs[0] = sf_c5_CTRNNSLSF_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void CTRNNSLSF_debug_initialize(struct SfDebugInstanceStruct* debugInstance)
{
  _CTRNNSLSFMachineNumber_ = sf_debug_initialize_machine(debugInstance,
    "CTRNNSLSF","sfun",0,5,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,_CTRNNSLSFMachineNumber_,0,
    0);
  sf_debug_set_machine_data_thresholds(debugInstance,_CTRNNSLSFMachineNumber_,0);
}

void CTRNNSLSF_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
typedef struct SfOptimizationInfoFlagsTag {
  boolean_T isRtwGen;
  boolean_T isModelRef;
  boolean_T isExternal;
} SfOptimizationInfoFlags;

static SfOptimizationInfoFlags sOptimizationInfoFlags;
void unload_CTRNNSLSF_optimization_info(void);
mxArray* load_CTRNNSLSF_optimization_info(boolean_T isRtwGen, boolean_T
  isModelRef, boolean_T isExternal)
{
  if (sOptimizationInfoFlags.isRtwGen != isRtwGen ||
      sOptimizationInfoFlags.isModelRef != isModelRef ||
      sOptimizationInfoFlags.isExternal != isExternal) {
    unload_CTRNNSLSF_optimization_info();
  }

  sOptimizationInfoFlags.isRtwGen = isRtwGen;
  sOptimizationInfoFlags.isModelRef = isModelRef;
  sOptimizationInfoFlags.isExternal = isExternal;
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("CTRNNSLSF",
      "CTRNNSLSF");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_CTRNNSLSF_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
