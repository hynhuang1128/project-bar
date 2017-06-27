
//#begin
//#type:ListItem,ListItem
//#flag:52
//#data:ListItem*[16],ListItem*[16]
//#templ:
//#header:
//#end


#ifndef __VCB_LISTITEM_H__
#define __VCB_LISTITEM_H__


#define count_vcbData (*(long*)((long*)pcbd+2))
static void VUCALLBACK vcb_ListItem(void* pcbd)
{
    ListItem** ppData = (ListItem**)pcbd;
    ListItem* pData = *ppData;
    ListItem* vcbData[16]; TDCB_INIT("ListItem*[16]", vcbData);

    if(IS_VCB_INPUT())
    {
        TDCB_INPUT("ListItem*[16]", vcbData, pcbd);
_INPUT_CODE_BEGIN_
        int i;
        ListItem* pPrev = NULL;
        for(i=0; i<count_vcbData; i++)
        {
            pData = vcbData[i];
            if(pPrev != NULL)
			{
				pData->p_prev = pPrev;
                pPrev->p_next = pData;
			}
            else
                *ppData = pData;
            pPrev = pData;
        }
_INPUT_CODE_END_
    }
    else
    {
_OUTPUT_CODE_BEGIN_
        while(pData != NULL)
        {
            vcbData[count_vcbData++] = pData;
            pData = pData->p_next;
        }
_OUTPUT_CODE_END_
        TDCB_OUTPUT("ListItem*[16]", vcbData, pcbd, 0);
    }
}


#endif