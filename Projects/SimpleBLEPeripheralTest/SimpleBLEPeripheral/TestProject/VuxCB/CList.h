
//#begin
//#type:CList,CList
//#flag:5
//#data:TYPE*[16],TYPE*[16]
//#templ:class|TYPE||class|ARG_TYPE||
//#header:
//#end


#ifndef __VCB_CLIST_H__
#define __VCB_CLIST_H__


#define count_vcbData (*(long*)((long*)pcbd+2))
template<class TYPE,class ARG_TYPE>
class vcb_CList_t { public:
static void VUCALLBACK vcb_CList(void* pcbd)
{
    CList<TYPE,ARG_TYPE>** ppData = (CList<TYPE,ARG_TYPE>**)pcbd;
    CList<TYPE,ARG_TYPE>* pData = *ppData;
    TYPE* vcbData[16]; TDCB_INIT("TYPE*[16]", vcbData);

    if(IS_VCB_INPUT())
    {
        TDCB_INPUT("TYPE*[16]", vcbData, pcbd);
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
        TDCB_OUTPUT("TYPE*[16]", vcbData, pcbd, 0);
    }
}
};

template<class TYPE,class ARG_TYPE>
static void VUCALLBACK vcb_CList(void* pcbd)
{
    vcb_CList_t<TYPE,ARG_TYPE>::vcb_CList(pcbd);
}


#endif