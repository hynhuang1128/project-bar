
//#begin
//#type:CStringList,CStringList
//#flag:5
//#data:CString*[16],CString*[16]
//#templ:
//#header:
//#end


#ifndef __VCB_CSTRINGLIST_H__
#define __VCB_CSTRINGLIST_H__


#define count_vcbData (*(long*)((long*)pcbd+2))
static void VUCALLBACK vcb_CStringList(void* pcbd)
{
    CStringList** ppData = (CStringList**)pcbd;
    CStringList* pData = *ppData;
    CString* vcbData[16]; TDCB_INIT("CString*[16]", vcbData);

    if(IS_VCB_INPUT())
    {
        TDCB_INPUT("CString*[16]", vcbData, pcbd);
_INPUT_CODE_BEGIN_
        for(int i=0; i<count_vcbData; i++)
            pData->AddTail(*vcbData[i]);
_INPUT_CODE_END_
    }
    else
    {
_OUTPUT_CODE_BEGIN_
        POSITION pos = pData->GetHeadPosition();
        while(pos != NULL)
            *vcbData[count_vcbData++] = pData->GetNext(pos);
_OUTPUT_CODE_END_
        TDCB_OUTPUT("CString*[16]", vcbData, pcbd, 0);
    }
}


#endif