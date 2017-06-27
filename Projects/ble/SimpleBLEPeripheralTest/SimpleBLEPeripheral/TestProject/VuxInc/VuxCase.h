
#ifndef __VUXCASE_H__
#define __VUXCASE_H__

#define SEND_ASSERT(exp, msg, file, line) \
    if(!VuxRateTesting() == 0)\
    {\
        VuxTestAssert(exp, msg, (const char*)file, line);\
    }

#define VUX_EQUAL_EXP(expected, catual)    expected == catual
#define VUX_EQUAL_FLOAT(expected, catual)  FLTEQUAL(expected, catual)
#define VUX_EQUAL_STRING(expected, catual) STREQUAL(expected, catual)
#define VUX_EQUAL_WSTRING(expected, catual) WSTREQUAL(expected, catual)

#define SEND_FAILED(exp, msg, file, line) \
        VuxTestAssert(exp, msg, (const char*)file, line);

#define STRCOPY(name, value)               VuxStrCpy(name,   value, -1)
#define WSTRCOPY(name, value)              VuxWStrCpy(name,  value, -1)
#define STREQUAL(name, value)              VuxStrEqual(name, value)
#define WSTREQUAL(name, value)             VuxWStrEqual(name, value)
#define FLTEQUAL(name, value)              (name) >= ((value)-(VuxGetFloatLeft())) && (name) <= ((value)+(VuxGetFloatRight()))

//²âÊÔÇý¶¯´úÂë
/////////////////////////////////////////////////////////////////////

#ifdef _CATCH_EXCEPTION
#define CATCH_EXCEPTION_BEGIN() VUXTRY{
#else 
#define CATCH_EXCEPTION_BEGIN()
#endif

#ifdef _CATCH_EXCEPTION
#define CATCH_EXCEPTION_END() } VUXCATCHALL() SEND_EXCEPTION_MSG()
#define CATCH_EXCEPTION_END2() } VUXCATCHALL()\
{if(!vux_case_runed) SEND_EXCEPTION_MSG_INPUT() \
    else SEND_EXCEPTION_MSG_AUTODIS()}
#define CATCH_EXCEPTION_END_BEGIN_CASE() } VUXCATCHALL() SEND_EXCEPTION_MSG_BEGIN_CASE()
#else 
#define CATCH_EXCEPTION_END()
#define CATCH_EXCEPTION_END2()
#define CATCH_EXCEPTION_END_BEGIN_CASE()
#endif

#define VUXFPS  (void*)VuxInit, (void*)VuxSetOffPtr, (void*)VuxCallBack

#define TEST_BEGIN(path,key,cls,func) \
    int vux_debug_times = 0; \
    int vux_rate_test   = 0; \
    int vux_rate_runed  = 0; \
    int vux_rate_times  = 0; \
    int vux_case_index  = -1; \
    int vux_debuging    = 0; \
    int vux_exception   = 0; \
    int vux_run_curr_case  = 0;\
    int vux_exception_value = 0; \
    int vux_case_runed  = 0;\
    int vux_run_bvtest  ; \
    int vux_run_rtest   ;  \
	VuxSetFunctionInfo(path,key,cls,func, VUXFPS); \
    VuxBeginFunctionTest();\
    vux_run_bvtest  = VuxIsRunBVTest(); \
    vux_run_rtest   = VuxIsRunRTest();  \
    _VUX_TEST_BEGIN: {\

#define TEST_BEGING(path,key,cls,func) \
    int vux_rate_test   = 0; \
    int vux_rate_runed  = 0; \
    int vux_rate_times  = 0; \
    int vux_case_index  = -1; \
    int vux_exception   = 0; \
    int vux_exception_value = 0; \
    int vux_case_runed  = 0;\
    int vux_run_bvtest  ; \
    int vux_run_rtest   ;  \
    VuxSetFunctionInfo(path,key,cls,func, VUXFPS); \
	VuxBeginFunctionTest();\
    vux_run_bvtest  = VuxIsRunBVTest(); \
    vux_run_rtest   = VuxIsRunRTest();  \
    _VUX_TEST_BEGIN: {\

#define TEST_END() \
    if( vux_rate_test && vux_rate_runed < vux_rate_times){\
        vux_case_index = -1;\
        goto _VUX_TEST_BEGIN;}\
    if( vux_run_bvtest){\
        vux_run_bvtest = 0;\
		VuxBVTestBegin();\
        goto _VUX_TEST_BEGIN;}\
    }VuxEndFunctionTest();\

#define _TEST_CASE_BEGINO(arg) \
{VuxReadGrid(arg, 0); while(VuxNextTestCase()){\
    TEST_CASE_RUN_BEGIN()\
    CATCH_EXCEPTION_BEGIN() \
    vtest_case_begin(arg, pVuxObj);\
    CATCH_EXCEPTION_END_BEGIN_CASE()\
    CATCH_EXCEPTION_BEGIN() \

#define TEST_CASE_BEGINO(arg) _TEST_CASE_BEGINO(arg)

#define _TEST_CASE_BEGING(arg) \
{VuxReadGrid(arg, 0); while(VuxNextTestCase()){\
    TEST_CASE_RUN_BEGIN()\
    CATCH_EXCEPTION_BEGIN()\
	vtest_case_begin_global(arg); VUXSCOPEBEGIN()

#define TEST_CASE_BEGING(arg) _TEST_CASE_BEGING(arg)

#define TEST_CASE_BEGINAG(arg) \
if(0) {_TEST_CASE_BEGING(arg)

#define TEST_CASE_BEGINAO(arg) \
{if(0) {_TEST_CASE_BEGINO(arg)

#define TEST_CASE_ENDO() \
    vtest_case_end(pVuxObj); \
    ; VUXSCOPEEND() \
    CATCH_EXCEPTION_END();\
    CATCH_EXCEPTION_END2() \
    TEST_CASE_RUN_END()\
}}

#define TEST_CASE_ENDG() \
        ;VUXSCOPEEND() VUXSCOPEEND() \
		vtest_case_end_global();\
        CATCH_EXCEPTION_END() \
        CATCH_EXCEPTION_END2() \
    TEST_CASE_RUN_END() \
}}

#define TEST_CASE_ENDAG() TEST_CASE_ENDG()}

#define TEST_CASE_ENDAO() TEST_CASE_ENDO()}


#define TEST_RATE(times) \
    if(vux_run_rtest) \
    {\
        if(vux_rate_test == 0)\
        {\
            vux_rate_test = 1; \
            vux_rate_runed = 0; \
            vux_rate_times = times;\
            VuxRateTestBegin(times);\
        }\
        else if(vux_rate_runed >= vux_rate_times)\
        {\
            VuxRateTestEnd();\
        }\
    }

#define TEST_ASSERT(exp) SEND_ASSERT(exp, VUXTEXT(#exp), __FILE__, __LINE__);
#define TEST_FAILED()    SEND_FAILED(0,   VUXTEXT("Test Failed"), __FILE__, __LINE__);
#define TEST_ASSERT_LOCAL(exp) SEND_ASSERT_LOCAL(VUXTEXT(#exp), __FILE__, __LINE__);
#define MY_ASSERT(exp) SEND_ASSERT(exp, VUXTEXT(#exp), __FILE__, __LINE__);
#define MY_ERROR(exp) SEND_ASSERT(0, VUXTEXT(#exp), VUXTEXT(#exp), __LINE__);
#define TEST_MSG(msg) VuxDumpMsg(msg);
#define TEST_MSG0(msg) VuxDumpMsg(msg);
#define TEST_MSG1(msg, arg1) VuxDumpMsg(msg, arg1);
#define TEST_MSG2(msg, arg1, arg2) VuxDumpMsg(msg, arg1, arg2);
#define TEST_MSG3(msg, arg1, arg2, arg3) VuxDumpMsg(msg, arg1, arg2, arg3);
#define TEST_MSG4(msg, arg1, arg2, arg3, arg4) VuxDumpMsg(msg, arg1, arg2, arg3, arg4);
#define TEST_MSG5(msg, arg1, arg2, arg3, arg4, arg5) VuxDumpMsg(msg, arg1, arg2, arg3, arg4, arg5);

#define TEST_ASSERT_EQUAL_CHAR(actual, expected)   SEND_ASSERT_EQUAL_CHAR(actual, expected, __FILE__, __LINE__);
#define TEST_ASSERT_EQUAL_UCHAR(actual, expected)  SEND_ASSERT_EQUAL_UCHAR(actual, expected, __FILE__, __LINE__);
#define TEST_ASSERT_EQUAL_SHORT(actual, expected)  SEND_ASSERT_EQUAL_SHORT(actual, expected, __FILE__, __LINE__);
#define TEST_ASSERT_EQUAL_USHORT(actual, expected) SEND_ASSERT_EQUAL_USHORT(actual, expected, __FILE__, __LINE__);
#define TEST_ASSERT_EQUAL_INT(actual, expected)    SEND_ASSERT_EQUAL_INT(actual, expected, __FILE__, __LINE__);
#define TEST_ASSERT_EQUAL_UINT(actual, expected)   SEND_ASSERT_EQUAL_UINT(actual, expected, __FILE__, __LINE__);
#define TEST_ASSERT_EQUAL_LONG(actual, expected)   SEND_ASSERT_EQUAL_LONG(actual, expected, __FILE__, __LINE__);
#define TEST_ASSERT_EQUAL_ULONG(actual, expected)  SEND_ASSERT_EQUAL_ULONG(actual, expected, __FILE__, __LINE__);
#define TEST_ASSERT_EQUAL_INT64(actual, expected)  SEND_ASSERT_EQUAL_INT64(actual, expected, __FILE__, __LINE__);
#define TEST_ASSERT_EQUAL_UINT64(actual, expected) SEND_ASSERT_EQUAL_UINT64(actual, expected, __FILE__, __LINE__);
#define TEST_ASSERT_EQUAL_FLOAT(actual, expected)  SEND_ASSERT_EQUAL_FLOAT(actual, expected, __FILE__, __LINE__);
#define TEST_ASSERT_EQUAL_DOUBLE(actual, expected) SEND_ASSERT_EQUAL_DOUBLE(actual, expected, __FILE__, __LINE__);
#define TEST_ASSERT_EQUAL_LDOUBLE(actual, expected) SEND_ASSERT_EQUAL_LDOUBLE(actual, expected, __FILE__, __LINE__);
#define TEST_ASSERT_EQUAL_STRING(actual, expected) SEND_ASSERT_EQUAL_STRING(actual, expected, __FILE__, __LINE__);
#define TEST_ASSERT_EQUAL_WSTRING(actual, expected) SEND_ASSERT_EQUAL_WSTRING(actual, expected, __FILE__, __LINE__);
#define TEST_ASSERT_EQUAL_BOOL(actual, expected) SEND_ASSERT_EQUAL_BOOL(actual, expected, __FILE__, __LINE__);

#define TEST_EXCEPTION() \
    vux_exception = 0;\
    vux_exception_value = 0;\
    try {\


#define TEST_THROW(type) \
    VUXSCOPEEND() } \
    catch(type)\
    {\
        vux_exception = 1;\
    } \
    SEND_ASSERT(vux_exception, VUXTEXT(#type), __FILE__, __LINE__)\
    VuxResetRunTimes();\
    if(vux_exception==1)VuxCaseEnd();
        
#define TEST_THROW_VALUE(type, value) \
    VUXSCOPEEND() } \
    catch(type e)\
    {\
        vux_exception = 1; \
        if(e == value) \
        {\
            vux_exception_value = 1;\
        }\
    } \
    SEND_ASSERT(vux_exception_value, VUXTEXT(#value), __FILE__, __LINE__)\
    VuxResetRunTimes();\
if(vux_exception==1)VuxCaseEnd();

#define TEST_THROW_EXP(type, value) \
    VUXSCOPEEND() } \
    catch(type e)\
    {\
        vux_exception = 1; \
        if(value) \
        {\
            vux_exception_value = 1;\
        }\
    } \
    SEND_ASSERT(vux_exception_value, VUXTEXT(#value), __FILE__, __LINE__)\
    VuxResetRunTimes();\
if(vux_exception==1)VuxCaseEnd();

#ifdef __cplusplus
#define TEST_RUN\
	     VUXSCOPEBEGIN()\
         vux_case_runed = 1; \
         CATCH_EXCEPTION_BEGIN()
#else
#define TEST_RUN\
	     VUXSCOPEBEGIN() \
         CATCH_EXCEPTION_BEGIN()
#endif

#define TEST_CASE_RUN_BEGIN() \
	VuxBeforeCase();\
	VuxCaseBegin();\

#define TEST_CASE_RUN_END() \
    if(vux_rate_test == 1 && vux_rate_runed < vux_rate_times) \
        vux_rate_runed++;  \
	VuxCaseEnd(); \
	VuxAfterCase();\
    vux_case_runed = 0;


#endif __VUXCASE_H__