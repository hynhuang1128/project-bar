
//#begin
//#type:CTokenList,CTokenList
//#flag:13
//#data:{LPCTSTR code;CToken* pTokens[16];},{LPCTSTR code;CToken* pTokens[16];},LPCTSTR|code|4||CToken*[16]|pTokens|64
//#templ:
//#header:Source/Parser/TokenReader.h
//#end


#ifndef __VCB_CTOKENLIST_H__
#define __VCB_CTOKENLIST_H__


#include "Source/Parser/TokenReader.h"

#define count_pTokens (*(long*)((long*)pcbd+2))
static void VUCALLBACK vcb_CTokenList(void* pcbd)
{
    CTokenList** ppData = (CTokenList**)pcbd;
    CTokenList* pData = *ppData;
    struct vcbType {LPCTSTR code;CToken* pTokens[16];} vcbData; TDCB_INIT("{LPCTSTR code;CToken* pTokens[16];}", vcbData);

    if(IS_VCB_INPUT())
    {
        TDCB_INPUT("{LPCTSTR code;CToken* pTokens[16];}", vcbData, pcbd);
_INPUT_CODE_BEGIN_
        CTokenReader reader;
        reader.ReadTokenList(*pData, vcbData.code);
_INPUT_CODE_END_
    }
    else
    {
_OUTPUT_CODE_BEGIN_
        VString code;
        CTokenReader::TokenListToCode(code, *pData);
        vcbData.code = code;
        POSITION pos = pData->GetHeadPosition();
        while(pos != NULL && count_pTokens < 16)
            vcbData.pTokens[count_pTokens++] = pData->GetNext(pos);
_OUTPUT_CODE_END_
        TDCB_OUTPUT("{LPCTSTR code;CToken* pTokens[16];}", vcbData, pcbd, 0);
    }
}


#endif