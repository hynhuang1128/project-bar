


//
// COPYRIGHT KaileSoft Corporation.
// All rights reserved.
// 版权所有：广州凯乐软件技术有限公司
// 保留所有权利
//

#ifndef __VUNIT_H__
#define __VUNIT_H__

#undef  _VUNIT
#define _VUNIT

#ifdef __cplusplus
//#define private public
//#define protected public
#endif

#include "VuxDef.h"
#include "VuxSetting.h"
#include "VuxOptions.h"
#include "VuxImport.h"
#include "VuxIgnore.h"
#include "VuxLibStub.h"
#include "VuxInit.h"
#include "VuxPlus.h"
#include "VuxCase.h"
#include "VuxGrid.h"
#include "VuxtDeclare.h"
#include "VuxStubOptions.h"

//将原项目的main函数改名
#ifdef VUX_REDEFINE_MAIN
#define main     vux_user_main
#define wmain    vux_user_main
#endif

#endif //__VUNIT_H__