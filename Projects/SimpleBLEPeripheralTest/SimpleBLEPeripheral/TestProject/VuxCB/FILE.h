
//#begin
//#type:FILE,FILE
//#flag:44
//#data:{char* path;char* flag;},{char* path;char* flag;},char*|path|4||char*|flag|4
//#templ:
//#header:
//#end


#ifndef __VCB_FILE_H__
#define __VCB_FILE_H__


static void VUCALLBACK vcb_FILE(void* pcbd)
{
    FILE** ppData = (FILE**)pcbd;
    FILE* pData = *ppData;
    struct vcbType {char* path;char* flag;} vcbData; TDCB_INIT("{char* path;char* flag;}", vcbData);

    if(IS_VCB_INPUT())
    {
        TDCB_INPUT("{char* path;char* flag;}", vcbData, pcbd);
_INPUT_CODE_BEGIN_
        pData = fopen(VuxDataPathNameA(vcbData.path), vcbData.flag);
        *ppData = pData;
_INPUT_CODE_END_
    }
    else
    {
_OUTPUT_CODE_BEGIN_

_OUTPUT_CODE_END_
        TDCB_OUTPUT("{char* path;char* flag;}", vcbData, pcbd, 0);
    }
}


#endif