
//#begin
//#type:CMapStringToPtr,CMapStringToPtr
//#flag:15
//#data:{CString key;void* ptr;}*[16],{CString key;void* ptr;}*[16],CString|key|12||void*|ptr|4
//#templ:
//#header:
//#end


#ifndef __VCB_CMAPSTRINGTOPTR_H__
#define __VCB_CMAPSTRINGTOPTR_H__


#define count_vcbData (*(long*)((long*)pcbd+2))
static void VUCALLBACK vcb_CMapStringToPtr(void* pcbd)
{
    CMapStringToPtr** ppData = (CMapStringToPtr**)pcbd;
    CMapStringToPtr* pData = *ppData;
    struct vcbType {CString key;void* ptr;}* vcbData[16]; TDCB_INIT("{CString key;void* ptr;}*[16]", vcbData);

    if(IS_VCB_INPUT())
    {
        TDCB_INPUT("{CString key;void* ptr;}*[16]", vcbData, pcbd);
_INPUT_CODE_BEGIN_
        if(pData->IsEmpty()) pData->InitHashTable(17);
        for(int i=0; i<count_vcbData; i++)
            pData->SetAt(vcbData[i]->key, vcbData[i]->ptr);
_INPUT_CODE_END_
    }
    else
    {
_OUTPUT_CODE_BEGIN_
        CString key;
        void* ptr = NULL;
        for(POSITION pos = pData->GetStartPosition(); pos != NULL;)
        {
            pData->GetNextAssoc(pos, key, (void*&)ptr);
            vcbData[count_vcbData]->key = key;
            vcbData[count_vcbData]->ptr = ptr;
            count_vcbData++;
        }
_OUTPUT_CODE_END_
        TDCB_OUTPUT("{CString key;void* ptr;}*[16]", vcbData, pcbd, 1);
    }
}


#endif