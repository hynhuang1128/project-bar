

#ifndef __VUXDEF_H__
#define __VUXDEF_H__

#define VUCALLBACK __stdcall
#define VUXTEXT(txt)  ((const char*)(txt))  

#ifdef __cplusplus
#define VUEXTERNC extern "C"
#else
#define VUEXTERNC
#endif

#ifndef VUMOCKDES_DEFINED
#define VUMOCKDES_DEFINED
typedef struct _tagVUMCKDS
{
	char index;
	const void* pDes;
}VUMCKDS;
#endif

#ifdef __cplusplus
#define VUXTRY               try
#define VUXCATCH(e)          catch(e)
#define VUXCATCHALL()        catch(...)
#define SEND_EXCEPTION_MSG() {SEND_ASSERT(0, VUXTEXT("Exception"), __FILE__, __LINE__); VuxCaseEnd(); VuxResetRunTimes();}
#define SEND_EXCEPTION_MSG_BEGIN_CASE() {SEND_ASSERT(0, VUXTEXT("Exception in BeginCase()"), __FILE__, __LINE__); }
#define SEND_EXCEPTION_MSG_INPUT()  {SEND_ASSERT(0, VUXTEXT("Exception by Case Input"), __FILE__, __LINE__); }
#define SEND_EXCEPTION_MSG_AUTODIS()  {if(!VuxIsIgnoreAutoDiscroctException()) SEND_ASSERT(0, VUXTEXT("Exception by Auto Distructor"), __FILE__, __LINE__); }
#define VUXSCOPEBEGIN()
#define VUXSCOPEEND()
#ifdef  CATCH_EXCEPTION
#define _CATCH_EXCEPTION
#endif
#else
#define VUXTRY        
#define VUXCATCH(e)   
#define VUXCATCHALL() 
#define SEND_EXCEPTION_MSG()
#define SEND_EXCEPTION_MSG_BEGIN_CASE()
#define SEND_EXCEPTION_MSG_INPUT()
#define SEND_EXCEPTION_MSG_AUTODIS()
#define VUXSCOPEBEGIN() {
#define VUXSCOPEEND()   }
#endif

#define VUX_CONSTR_INIT() VuxStubContructorInit()

#define _INPUT_CODE_BEGIN_  {
#define _INPUT_CODE_END_    }
#define _OUTPUT_CODE_BEGIN_ 
#define _OUTPUT_CODE_END_   

 static void VUCALLBACK VuxCallBack(int index, void* pcbd);
 static void* VUCALLBACK VuxSetOffPtr(long index, void* pValue);

#endif
