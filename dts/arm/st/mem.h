#ifndef __DT_BINDING_ST_MEM_H
#define __DT_BINDING_ST_MEM_H

#define __SIZE_K(x) (x * 1024)

#if defined(CONFIG_SOC_STM32F103XB)
#define DT_FLASH_SIZE		__SIZE_K(128)
#define DT_SRAM_SIZE		__SIZE_K(20)
#elif defined(CONFIG_SOC_STM32F103XE)
#define DT_FLASH_SIZE		__SIZE_K(512)
#define DT_SRAM_SIZE		__SIZE_K(64)
#elif defined(CONFIG_SOC_STM32F107XC)
#define DT_FLASH_SIZE		__SIZE_K(256)
#define DT_SRAM_SIZE		__SIZE_K(64)
#elif defined(CONFIG_SOC_STM32F303XC)
#define DT_FLASH_SIZE		__SIZE_K(256)
#define DT_SRAM_SIZE		__SIZE_K(40)
#elif defined(CONFIG_SOC_STM32F334X8)
#define DT_FLASH_SIZE		__SIZE_K(64)
#define DT_SRAM_SIZE		__SIZE_K(12)
#elif defined(CONFIG_SOC_STM32F373XC)
#define DT_FLASH_SIZE		__SIZE_K(256)
#define DT_SRAM_SIZE		__SIZE_K(32)
#elif defined(CONFIG_SOC_STM32F401XE)
#define DT_FLASH_SIZE		__SIZE_K(512)
#define DT_SRAM_SIZE		__SIZE_K(96)
#elif defined(CONFIG_SOC_STM32F407XG)
#define DT_FLASH_SIZE		__SIZE_K(1024)
#define DT_SRAM_SIZE		__SIZE_K(192)
#elif defined(CONFIG_SOC_STM32F411XE)
#define DT_FLASH_SIZE		__SIZE_K(512)
#define DT_SRAM_SIZE		__SIZE_K(128)
#elif defined(CONFIG_SOC_STM32F429XI)
#define DT_FLASH_SIZE		__SIZE_K(2048)
#define DT_SRAM_SIZE		__SIZE_K(256)
#elif defined(CONFIG_SOC_STM32L475XG)
#define DT_FLASH_SIZE		__SIZE_K(1024)
#define DT_SRAM_SIZE		__SIZE_K(96)
#elif defined(CONFIG_SOC_STM32L476XG)
#define DT_FLASH_SIZE		__SIZE_K(1024)
#define DT_SRAM_SIZE		__SIZE_K(96)
#elif defined(CONFIG_SOC_STM32L432XC)
#define DT_FLASH_SIZE		__SIZE_K(256)
#define DT_SRAM_SIZE		__SIZE_K(64)
#else
#error "Flash and RAM sizes not defined for this chip"
#endif

#endif /* __DT_BINDING_ST_MEM_H */
