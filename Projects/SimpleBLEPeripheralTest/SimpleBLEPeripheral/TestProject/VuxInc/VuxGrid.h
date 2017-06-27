


//
// COPYRIGHT KaileSoft Corporation.
// All rights reserved.
// 版权所有：广州凯乐软件技术有限公司
// 保留所有权利
//

#ifndef __VUXGRID_H__
#define __VUXGRID_H__

#define VUXFPS  (void*)VuxInit, (void*)VuxSetOffPtr, (void*)VuxCallBack

#define VURSTT(t)  VuxResetTemplType(pcbd, VUXTEXT(t))

#ifdef __cplusplus
#define VTD_DEFINE_INIT_GRID(t, n1, n2, a, s)   t n1;                VUXTRY{VtdInitGrid(VUXTEXT(#t), VUXTEXT(#n2), VUXTEXT(#n1), s, (void*)(&n2), a, VUXFPS);}VUXCATCHALL(){}
#define VTD_INIT_GRID(t, n1, n2, a, s)                               VUXTRY{VtdInitGrid(VUXTEXT(t),  VUXTEXT(#n2), VUXTEXT(#n1), s, (void*)(&n2), a, VUXFPS);}VUXCATCHALL(){}
#define VTD_INIT_GRIDM(t, n1, n2, a, s)                              VUXTRY{VtdInitGrid(VUXTEXT(t),  VUXTEXT("."), VUXTEXT("."), s, (void*)(&n2), a, VUXFPS);}VUXCATCHALL(){}
#define VTD_DEFINE_INIT(t, n1, n2, a, s)        t n1;                VUXTRY{VtdInitFore(VUXTEXT(#t), VUXTEXT(#n2), VUXTEXT(#n1), s, (void*)(&n2), VUXFPS);}VUXCATCHALL(){}  
#define VTD_INIT(t, n1, n2, s)                                       VUXTRY{VtdInitFore(VUXTEXT(t),  VUXTEXT(#n2), VUXTEXT(#n1), s, (void*)(&n2), VUXFPS);}VUXCATCHALL(){}  
#define VCB_INIT(t, n, s)                                            VUXTRY{VtdCbInit(VUXTEXT(t), VUXTEXT(#n), (void*)(&n), s, pcbd);}VUXCATCHALL(){}
#define _VARDEFINE_(t, n, s)                                         t* vp_##n = *(t**)VuxLocalInput(#t, #n, 0, s, 1); t& n=*vp_##n;       
#else
#define VTD_DEFINE_INIT_GRID(t, n1, n2, a, s)   t n1; void* vt##n2 = VtdInitGrid(VUXTEXT(#t), VUXTEXT(#n2), VUXTEXT(#n1), s, (void*)(&n2), a, VUXFPS)         
#define VTD_INIT_GRID(t, n1, n2, a, s)                void* vt##n2 = VtdInitGrid(VUXTEXT(t),  VUXTEXT(#n2), VUXTEXT(#n1), s, (void*)(&n2), a, VUXFPS)
#define VTD_INIT_GRIDM(t, n1, n2, a, s)               void* vt##n2 = VtdInitGrid(VUXTEXT(t),  VUXTEXT("."), VUXTEXT("."), s, (void*)(&n2), a, VUXFPS)
#define VTD_DEFINE_INIT(t, n1, n2, a, s)        t n1; void* vt##n2 = VtdInitFore(VUXTEXT(#t), VUXTEXT(#n2), VUXTEXT(#n1), s, (void*)(&n2), VUXFPS)  
#define VTD_INIT(t, n1, n2, s)                        void* vt##n2 = VtdInitFore(VUXTEXT(t),  VUXTEXT(#n2), VUXTEXT(#n1), s, (void*)(&n2), VUXFPS)  
#define VCB_INIT(t, n, s)                             void* vt##n  = VtdCbInit(VUXTEXT(t), VUXTEXT(#n), (void*)(&n), s, pcbd);
#define _VARDEFINE_(t, n, s)                          t* vp_##n = *(t**)VuxLocalInput(#t, #n, 0, s, 1); t n=*vp_##n;   
#endif

#define VCDS_PARAMETER            'U'
#define VCDS_CUSTOMIZE            'V'
#define VCDS_MEMBER               'W'
#define VCDS_GLOBAL               'G'
#define VCDS_OTHER                'z'
#define IS_VCB_INPUT()             ((*(long*)(((long*)pcbd) +1)) == 1)

#define TDP_DEFINE_INIT_GRID(t, n1, n2, a)             VTD_DEFINE_INIT_GRID(t, n1, n2, a, VCDS_PARAMETER)
#define TDP_INIT_GRID(t, n1, n2, a)                    VTD_INIT_GRID(t, n1, n2, a, VCDS_PARAMETER)       
#define TDC_DEFINE_INIT_GRID(t, n1, n2, a)             VTD_DEFINE_INIT_GRID(t, n1, n2, a, VCDS_CUSTOMIZE)
#define TDC_INIT_GRID(t, n1, n2, a)                    VTD_INIT_GRID(t, n1, n2, a, VCDS_CUSTOMIZE)    
#define TDM_INIT_GRID(t, n1, n2, a)                    VTD_INIT_GRIDM(t, n1, n2, a, VCDS_MEMBER)     
#define TDG_DEFINE_INIT_GRID(t, n1, n2, a)             VTD_DEFINE_INIT_GRID(t, n1, n2, a, VCDS_GLOBAL)
#define TDG_INIT_GRID(t, n1, n2, a)                    VTD_INIT_GRID(t, n1, n2, a, VCDS_GLOBAL)       
#define TDG_DEFINE_INIT(t, n1, n2, a)                  VTD_DEFINE_INIT(t, n1, n2, a, VCDS_GLOBAL)  
#define TDG_INIT(t, n1, n2)                            VTD_INIT(t, n1, n2, VCDS_GLOBAL)    
#define TDCB_INIT(t, n)                                VCB_INIT(t, n, VCDS_OTHER)
#define TDZ_OBJECT_INIT(t)                             *(t*)VtdInit(VUXTEXT(#t), VCDS_OTHER, VUXFPS, VUX_INIT_PATH)
#define TDZ_OBJECT_INIT2(t)                            VtdInit(VUXTEXT(t), VCDS_OTHER, VUXFPS, VUX_INIT_PATH)
#define TDZ_VARIABLE_INIT(t,n)                         *(t*)VtdInit(VUXTEXT(#t), VCDS_OTHER, VUXFPS, VUX_INIT_PATH)
#define TDZ_VARIABLE_INIT2(t,n)                        VtdInit(VUXTEXT(t), VCDS_OTHER, VUXFPS, VUX_INIT_PATH)
#define TDZ_CONSPARAM_INIT(t, n)                       *(t*)VtdConsParamInit(VUXTEXT(#t), VUXTEXT(#n), pValue, VCDS_OTHER, VUXFPS)
#define TDZ_CONSPARAM_INIT2(t,n)                       VtdConsParamInit(VUXTEXT(t), VUXTEXT(#n), pValue, VCDS_OTHER, VUXFPS)

#define _VALUE_(t, n, s, i)                            *(t*)VuxLocalInput(#t, #n, 0, s, i)
#define _ASSIGNI_(t, n, s, i)                          VuxLocalInput(#t, #n, (void*)&n, s, i)
#define _ASSIGNIA_(t, n, s, i)                         VuxLocalInput(#t, #n, n, s, i)
#define _ASSIGNR_(t, n, s, i)                          VuxLocalInput(#t, #n,(void*)&n, s, i)
#define _INTERRUPT_(t, n, s, i)                        VuxLocalInput(#t, #n,(void*)&n, s, i)
#define _OUTPUT_(t, n, s)                              VuxLocalOutput(#t, #n,(void*)&n, s) 
#define _OUTPUTA_(t, n, s)                             VuxLocalOutput(#t, #n, n, s) 
#define _OUTPUTC_(t, n, s)                             VuxLocalOutput(#t, #n, (void*)&n, s) 
#define _OUTPUTCA_(t, n, s)                            VuxLocalOutput(#t, #n, n, s) 
#define _OUTPUTR_(t, n, s)                             VuxLocalOutputR(#t,#n, s, n) 


#define TDCB_INPUT(t, n, v)                            VuxCallbackGridInput(VUXTEXT(t), VUXTEXT(#n), (void*)(&n), v)
#define TDCB_OUTPUT(t, n, v, o)                        VuxCallbackGridOutput(VUXTEXT(t), VUXTEXT(#n), (void*)(&n), v, o)
#define TEST_ASSERT_AUTO()                             VuxOutputAuto();
#define TEST_ASSERT_RETURN(t,ret)                      VuxOutputReturn(t, (const void*)ret);
#define TEST_ASSERT_VAR(t,n)                           VuxOutputVar(t, VUXTEXT(#n), (const void*)(&n));

#define _STATIC_ 
#define _REPLACE_(c)           c
#define _INSERT_(c)            c
#define _SWAP16_(x) ((((x)& 0xFF00)>>8) |  (((x) & 0x00FF)<<8))
#define _SWAP32_(x) ((((x) & 0xFF000000)>>24) | (((x) & 0x00FF0000)>>8)  |\
                     (((x) & 0x0000FF00)<<8 ) | (((x) & 0x000000FF)<<24) )

#endif