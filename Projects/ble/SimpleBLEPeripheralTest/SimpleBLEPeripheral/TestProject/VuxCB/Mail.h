
//#begin
//#type:Mail,Mail
//#flag:52
//#data:Mail*[16],Mail*[16]
//#templ:
//#header:
//#end


#ifndef __VCB_MAIL_H__
#define __VCB_MAIL_H__


#define count_vcbData (*(long*)((long*)pcbd+2))
static void VUCALLBACK vcb_Mail(void* pcbd)
{
    Mail** ppData = (Mail**)pcbd;
    Mail* pData = *ppData;
    Mail* vcbData[16]; TDCB_INIT("Mail*[16]", vcbData);

    if(IS_VCB_INPUT())
    {
        TDCB_INPUT("Mail*[16]", vcbData, pcbd);
_INPUT_CODE_BEGIN_
        int i;
        Mail* pPrev = NULL;
        for(i=0; i<count_vcbData; i++)
        {
            pData = vcbData[i];
            if(pPrev != NULL)
                pPrev->p_next = pData;
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
        TDCB_OUTPUT("Mail*[16]", vcbData, pcbd, 0);
    }
}


#endif