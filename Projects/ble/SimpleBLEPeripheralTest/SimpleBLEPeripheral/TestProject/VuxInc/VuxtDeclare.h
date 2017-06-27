
#ifndef __VUXDECLARE_H__
#define __VUXDECLARE_H__

extern unsigned int addr_SCS_BASE[0x00F00/4]; 
extern unsigned int addr_ITM_BASE[0x00F00/4];  
#define SCS_BASE            (char*)addr_SCS_BASE
#define ITM_BASE            (char*)addr_ITM_BASE

extern unsigned int addr_FLASH_BASE[0x70800/4];
extern unsigned int addr_SRAM_BASE[0x70800/4];
extern unsigned int addr_PERIPH_BASE[0x70800/4];
extern unsigned int addr_SRAM_BB_BASE[0x70800/4];
extern unsigned int addr_PERIPH_BB_BASE[0x70800/4];
extern unsigned int addr_FSMC_R_BASE[0x70800/4];
extern unsigned int addr_DBGMCU_BASE[0x70800/4];
#define FLASH_BASE          (char*)addr_FLASH_BASE
#define SRAM_BASE           (char*)addr_SRAM_BASE
#define PERIPH_BASE         (char*)addr_PERIPH_BASE
#define SRAM_BB_BASE        (char*)addr_SRAM_BB_BASE
#define PERIPH_BB_BASE      (char*)addr_PERIPH_BB_BASE
#define FSMC_R_BASE         (char*)addr_FSMC_R_BASE
#define DBGMCU_BASE         (char*)addr_DBGMCU_BASE

#endif