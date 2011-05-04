################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Documents\ and\ Settings/a0133022/My\ Documents/Joshi/MSP430/Projects/Capacitive_Touch/Getting_Started_Cap_Sense/SLAA491/Library/CTS_HAL.c \
C:/Documents\ and\ Settings/a0133022/My\ Documents/Joshi/MSP430/Projects/Capacitive_Touch/Getting_Started_Cap_Sense/SLAA491/Library/CTS_Layer.c 

OBJS += \
./Library/CTS_HAL.obj \
./Library/CTS_Layer.obj 

C_DEPS += \
./Library/CTS_HAL.pp \
./Library/CTS_Layer.pp 

OBJS__QTD += \
".\Library\CTS_HAL.obj" \
".\Library\CTS_Layer.obj" 

C_DEPS__QTD += \
".\Library\CTS_HAL.pp" \
".\Library\CTS_Layer.pp" 

C_SRCS_QUOTED += \
"C:/Documents and Settings/a0133022/My Documents/Joshi/MSP430/Projects/Capacitive_Touch/Getting_Started_Cap_Sense/SLAA491/Library/CTS_HAL.c" \
"C:/Documents and Settings/a0133022/My Documents/Joshi/MSP430/Projects/Capacitive_Touch/Getting_Started_Cap_Sense/SLAA491/Library/CTS_Layer.c" 


# Each subdirectory must supply rules for building sources it contributes
Library/CTS_HAL.obj: C:/Documents\ and\ Settings/a0133022/My\ Documents/Joshi/MSP430/Projects/Capacitive_Touch/Getting_Started_Cap_Sense/SLAA491/Library/CTS_HAL.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/CCS_4.2.1.00004/ccsv4/tools/compiler/MSP430 Code Generation Tools 3.3.3/bin/cl430" -vmsp -g -O0 --gcc --define=__MSP430G2452__ --include_path="C:/Documents and Settings/a0133022/My Documents/Joshi/MSP430/Projects/Capacitive_Touch/Getting_Started_Cap_Sense/SLAA491/Library" --include_path="C:/Documents and Settings/a0133022/My Documents/Joshi/MSP430/Projects/Capacitive_Touch/Getting_Started_Cap_Sense/SLAA491/Examples/RO_PINOSC_TA0_WDTp_One_Button_Compact" --include_path="C:/Program Files/Texas Instruments/CCS_4.2.1.00004/ccsv4/msp430/include" --include_path="C:/Program Files/Texas Instruments/CCS_4.2.1.00004/ccsv4/tools/compiler/MSP430 Code Generation Tools 3.3.3/include" --diag_warning=225 --printf_support=minimal --preproc_with_compile --preproc_dependency="Library/CTS_HAL.pp" --obj_directory="Library" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

Library/CTS_Layer.obj: C:/Documents\ and\ Settings/a0133022/My\ Documents/Joshi/MSP430/Projects/Capacitive_Touch/Getting_Started_Cap_Sense/SLAA491/Library/CTS_Layer.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/CCS_4.2.1.00004/ccsv4/tools/compiler/MSP430 Code Generation Tools 3.3.3/bin/cl430" -vmsp -g -O0 --gcc --define=__MSP430G2452__ --include_path="C:/Documents and Settings/a0133022/My Documents/Joshi/MSP430/Projects/Capacitive_Touch/Getting_Started_Cap_Sense/SLAA491/Library" --include_path="C:/Documents and Settings/a0133022/My Documents/Joshi/MSP430/Projects/Capacitive_Touch/Getting_Started_Cap_Sense/SLAA491/Examples/RO_PINOSC_TA0_WDTp_One_Button_Compact" --include_path="C:/Program Files/Texas Instruments/CCS_4.2.1.00004/ccsv4/msp430/include" --include_path="C:/Program Files/Texas Instruments/CCS_4.2.1.00004/ccsv4/tools/compiler/MSP430 Code Generation Tools 3.3.3/include" --diag_warning=225 --printf_support=minimal --preproc_with_compile --preproc_dependency="Library/CTS_Layer.pp" --obj_directory="Library" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


