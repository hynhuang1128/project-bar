

//
// COPYRIGHT KaileSoft Corporation.
// All rights reserved.
// 版权所有：广州凯乐软件技术有限公司
// 保留所有权利
//

#ifndef __VUXIMPORT_H__
#define __VUXIMPORT_H__

#include "VuxInit.h"

//引入函数
/////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
extern "C" {
#endif

extern long vux_var[16];

void   VuxInit(const char* dir);
void   VuxFinish(void);
void   VuxRunFuncTestBegin(void);
void   VuxRunFuncTestEnd(void);
void   VuxBeforeTest(void);
void   VuxTestBegin();
void   VuxTestEnd(long stop);
void   VuxCaseBegin(void);
void   VuxCaseEnd(void);
void   VuxRateTestBegin(long times);
void   VuxRateTestEnd(void);
void   VuxBVTestBegin();
void   VuxBVTestEnd();
long   VuxGetDebugTimes(void);
long   VuxIsDebugPlugCode(void);
long   VuxIsIgnoreAutoDiscroctException(void);
long   VuxNextFile(long* pIndex);
long   VuxNextFunc(long* pIndex);
void   VuxTestAssert(long exp, const char* str, const char* file, long line);
void   VuxSetFunctionInfo(const char* path, const char* key, const char* cls, const char* func, void* fpi, void* fpn, void* fpc);
void   VuxResetRunTimes(void);
void   VuxIncRunTimes(void);
long   VuxIsRepeatRun(void);
long   VuxRunCondition(long i, long v);
long   VuxConditionValue(long i, long v);
long   VuxRunBlock(long i);
long   VuxRunBranch(long i);
long   VuxRunLine(long i, long f);
long   VuxRunLineB(long i, long f);
long   VuxIsRunBVTest(void);
long   VuxIsRunRTest(void);
long   VuxRateTesting();
void   VuxDumpMsg(const char* msg, ...);
long   VuxNextTestCase(void);
long   VuxStrLen(char* pStr);
long   VuxWStrLen(short* pStr);
void*  VuxStrCpy(void* dst, const void* src, long size);
void*  VuxWStrCpy(unsigned short* pdst, unsigned short* psrc, long size);
long   VuxStrEqual(const void* dst, const void* src);
long   VuxWStrEqual(const void* dst, const void* src);
double VuxGetFloatLeft(void);
double VuxGetFloatRight(void);
void   VuxBeforeCase(void);
void   VuxAfterCase(void);
void   VuxBeginFunctionTest(void);
void   VuxEndFunctionTest(void);
void   VuxReadGrid(const char* name, long ac);
void   VuxOutputAuto(void);
void   VuxOutputReturn(const char* retType, const void* ret);
void   VuxOutputVar(const char* type, const char* name, const void* var);
void   VuxResetTemplType(void* pcbd, const char* text);
void   VuxCallbackGridInput(const char* type, const char* name, void* pDes, void* pcbd);
void   VuxCallbackGridOutput(const char* type, const char* name, void* pDes, void* pcbd, long order);
void*  VtdCbInit(const char* type, const char* name, void* pDes, char scope, void* pcbd);
void*  VuxLocalInput(const char* type, const char* name, void* pDes, char scope, long init);
void   VuxLocalOutput(const char* type, const char* name, const void* pDes, char scope);
void   VuxLocalOutputR(const char* type, const char* name, char scope,...);
void*  VtdInitGrid(const char* type, const char* name, const char* arr, char scope, void* pDes, long arg, void* fpi, void* fpn, void* fpc);
void*  VtdInitFore(const char* type, const char* name, const char* arr, char scope, void* pDes, void* fpi, void* fpn, void* fpc);
void*  VtdInit(const char* type, char scope, void* fpi, void* fpn, void* fpc, const char* path);
void*  VtdConsParamInit(const char* type, const char* name, void* pGridValue, char scope, void* fpi, void* fpn, void* fpc);
long   VuxMock(const char* fn, void** prt, void* data, long count);
void*  VuxNewObjectFailed(long size, const char* name);
void   VuxStubContructorInit();

const char* VuxDataPathNameA(const char* path);
const unsigned short* VuxDataPathNameW(const unsigned short* path);
#ifndef _UNICODE
#define VuxDataPathName VuxDataPathNameA
#else
#define VuxDataPathName VuxDataPathNameW
#endif

#ifdef __cplusplus
}
#endif

#endif
