
#include "VuxInc/VUnit.h"
#include "VuxAddi/VuxRunTest.h"
#include "VuxInc/VuxtImp.h"
#include "VuxStub/__Customize.h"
#undef main

int main(int argc, char *argv[])
{
    VuxInit(VUX_INIT_PATH);
    VuxTestBegin();
    VuxRunTest();
    VuxTestEnd(0);
    VuxFinish();
    return 0;
}
