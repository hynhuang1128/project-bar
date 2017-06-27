
//#begin
//#type:QString,QString
//#flag:5
//#data:char*,char*
//#templ:
//#header:
//#end


#ifndef __VCB_QSTRING_H__
#define __VCB_QSTRING_H__


static void VUCALLBACK vcb_QString(void* pcbd)
{
    QString** ppData = (QString**)pcbd;
    QString* pData = *ppData;
    char* vcbData; TDCB_INIT("char*", vcbData);

    if(IS_VCB_INPUT())
    {
        TDCB_INPUT("char*", vcbData, pcbd);
_INPUT_CODE_BEGIN_
        *pData = vcbData;
_INPUT_CODE_END_
    }
    else
    {
_OUTPUT_CODE_BEGIN_
        vcbData = (char*)(const char*)((QString)(*pData)).toLocal8Bit();
_OUTPUT_CODE_END_
        TDCB_OUTPUT("char*", vcbData, pcbd, 0);
    }
}


#endif