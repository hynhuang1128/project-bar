
//#begin
//#type:CString,CString
//#flag:5
//#data:LPCTSTR,LPCTSTR
//#templ:
//#header:
//#end


#ifndef __VCB_CSTRING_H__
#define __VCB_CSTRING_H__


static void VUCALLBACK vcb_CString(void* pcbd)
{
    CString** ppData = (CString**)pcbd;
    CString* pData = *ppData;
    LPCTSTR vcbData; TDCB_INIT("LPCTSTR", vcbData);

    if(IS_VCB_INPUT())
    {
        TDCB_INPUT("LPCTSTR", vcbData, pcbd);
_INPUT_CODE_BEGIN_
        *pData = vcbData;
_INPUT_CODE_END_
    }
    else
    {
_OUTPUT_CODE_BEGIN_
        vcbData = (LPCTSTR)(*pData);
_OUTPUT_CODE_END_
        TDCB_OUTPUT("LPCTSTR", vcbData, pcbd, 0);
    }
}


#endif