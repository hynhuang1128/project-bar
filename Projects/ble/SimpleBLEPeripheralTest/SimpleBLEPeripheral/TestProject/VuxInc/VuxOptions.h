


//
// COPYRIGHT KaileSoft Corporation.
// All rights reserved.
// 版权所有：广州凯乐软件技术有限公司
// 保留所有权利
//


#ifndef __VUXOPTIONS_H__
#define __VUXOPTIONS_H__

#include "VuxSetting.h"
#include "VuxCompiler.h"

#define MAX_DEBUG_TIMES           VuxGetDebugTimes()

#define SEND_ASSERT_FAILD(exp, msg, file, line) {VuxTestAssert(exp, msg, (const char*)file, line);}
#define DUMP_ASSERT_FAILED(exp) if(!(exp)){SEND_ASSERT_FAILD(0, "Assert Failed", __FILE__, __LINE__);}
#ifdef ASSERT_TO_TESTASSERT
#undef ASSERT
#define ASSERT(exp) DUMP_ASSERT_FAILED(exp)

//#undef _assert
//#define _assert(exp) DUMP_ASSERT_FAILED(exp)
#endif

#ifdef ASSERT_TO_IGNORE
#undef ASSERT
#define ASSERT(exp)
#undef VERIFY
#define VERIFY(exp) exp
//#undef _assert
//#define _assert(exp) 
#endif

#ifndef IGNORE_AUTO_BREAKPOINT

#if (VUX_COMPILE_BC || VUX_COMPILE_GCC)
#define BREAKPOINT_CODE() VuxSetBreakPoint();
#else
#define BREAKPOINT_CODE() __asm { __asm _EMIT 0xCC}
#endif
 
#define AUTO_BREAKPOINT() \
    static int vux_debug_first = 0; \
    if(VuxIsDebugging() && VuxGetOperateType()==VUX_OT_DEBUG){ \
        VuxResetOperateType(VUX_OT_TEST); \
        if(vux_debug_first++ == 0){ \
        BREAKPOINT_CODE()}}

#else
#define AUTO_BREAKPOINT()
#endif


#endif