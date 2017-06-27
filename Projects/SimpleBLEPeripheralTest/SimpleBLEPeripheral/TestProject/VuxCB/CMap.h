
//#begin
//#type:CMap,CMap
//#flag:77
//#data:{KEY key;VALUE value;}*[16],{KEY key;VALUE value;}*[16],KEY|key|0||VALUE|value|0
//#templ:class|KEY||class|ARG_KEY||class|VALUE||class|ARG_VALUE||
//#header:
//#end


#ifndef __VCB_CMAP_H__
#define __VCB_CMAP_H__


#define count_vcbData (*(long*)((long*)pcbd+2))
template<class KEY,class ARG_KEY,class VALUE,class ARG_VALUE>
class vcb_CMap_t { public:
static void VUCALLBACK vcb_CMap(void* pcbd)
{
    CMap<KEY,ARG_KEY,VALUE,ARG_VALUE>** ppData = (CMap<KEY,ARG_KEY,VALUE,ARG_VALUE>**)pcbd;
    CMap<KEY,ARG_KEY,VALUE,ARG_VALUE>* pData = *ppData;
    struct {KEY key;VALUE value;}* vcbData[16]; TDCB_INIT("{KEY key;VALUE value;}*[16]", vcbData);

    if(IS_VCB_INPUT())
    {
        TDCB_INPUT("{KEY key;VALUE value;}*[16]", vcbData, pcbd);
_INPUT_CODE_BEGIN_
        if(pData->IsEmpty()) pData->InitHashTable(17);
        for(int i=0; i<count_vcbData; i++)
            pData->SetAt(vcbData[i]->key, vcbData[i]->value);
_INPUT_CODE_END_
    }
    else
    {
_OUTPUT_CODE_BEGIN_
        KEY key;
        VALUE value;
        for(POSITION pos = pData->GetStartPosition(); pos != NULL;)
        {
            pData->GetNextAssoc(pos, key, (VALUE&)value);
            vcbData[count_vcbData]->key = key;
            vcbData[count_vcbData]->value = value;
            count_vcbData++;
        }
_OUTPUT_CODE_END_
        TDCB_OUTPUT("{KEY key;VALUE value;}*[16]", vcbData, pcbd, 0);
    }
}
};

template<class KEY,class ARG_KEY,class VALUE,class ARG_VALUE>
static void VUCALLBACK vcb_CMap(void* pcbd)
{
    vcb_CMap_t<KEY,ARG_KEY,VALUE,ARG_VALUE>::vcb_CMap(pcbd);
}


#endif