################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Documents\ and\ Settings/a0133022/My\ Documents/Joshi/MSP430/Projects/Capacitive_Touch/Getting_Started_Cap_Sense/SLAA491/Examples/RO_PINOSC_TA0_WDTp_Wheel_Buttons/main.c \
C:/Documents\ and\ Settings/a0133022/My\ Documents/Joshi/MSP430/Projects/Capacitive_Touch/Getting_Started_Cap_Sense/SLAA491/Examples/RO_PINOSC_TA0_WDTp_Wheel_Buttons/structure.c 

OBJS += \
./Application/main.obj \
./Application/structure.obj 

C_DEPS += \
./Application/main.pp \
./Application/structure.pp 

OBJS__QTD += \
".\Application\main.obj" \
".\Application\structure.obj" 

C_DEPS__QTD += \
".\Application\main.pp" \
".\Application\structure.pp" 

C_SRCS_QUOTED += \
"C:/Documents and Settings/a0133022/My Documents/Joshi/MSP430/Projects/Capacitive_Touch/Getting_Started_Cap_Sense/SLAA491/Examples/RO_PINOSC_TA0_WDTp_Wheel_Buttons/main.c" \
"C:/Documents and Settings/a0133022/My Documents/Joshi/MSP430/Projects/Capacitive_Touch/Getting_Started_Cap_Sense/SLAA491/Examples/RO_PINOSC_TA0_WDTp_Wheel_Buttons/structure.c" 


# Each subdirectory must supply rules for building sources it contributes
Application/main.obj: C:/Documents\ and\ Settings/a0133022/My\ Documents/Joshi/MSP430/Projects/Capacitive_Touch/Getting_Started_Cap_Sense/SLAA491/Examples/RO_PINOSC_TA0_WDTp_Wheel_Buttons/main.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/CCS_4.2.1.00004/ccsv4/tools/compiler/MSP430 Code Generation Tools 3.3.3/bin/cl430" -vmsp -g -O0 --gcc --define=__MSP430G2452__ --include_path="C:/Documents and Settings/a0133022/My Documents/Joshi/MSP430/Projects/Capacitive_Touch/Getting_Started_Cap_Sense/SLAA491/Examples/RO_PINOSC_TA0_WDTp_Wheel_Buttons" --include_path="C:/Documents and Settings/a0133022/My Documents/Joshi/MSP430/Projects/Capacitive_Touch/Getting_Started_Cap_Sense/SLAA491/Library" --include_path="C:/Program Files/Texas Instruments/CCS_4.2.1.00004/ccsv4/msp430/include" --include_path="C:/Program Files/Texas Instruments/CCS_4.2.1.00004/ccsv4/tools/compiler/MSP430 Code Generation Tools 3.3.3/include" --diag_warning=225 --printf_support=minimal --preproc_with_compile --preproc_dependency="Application/main.pp" --obj_directory="Application" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

Application/structure.obj: C:/Documents\ and\ Settings/a0133022/My\ Documents/Joshi/MSP430/Projects/Capacitive_Touch/Getting_Started_Cap_Sense/SLAA491/Examples/RO_PINOSC_TA0_WDTp_Wheel_Buttons/structure.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/CCS_4.2.1.00004/ccsv4/tools/compiler/MSP430 Code Generation Tools 3.3.3/bin/cl430" -vmsp -g -O0 --gcc --define=__MSP430G2452__ --include_path="C:/Documents and Settings/a0133022/My Documents/Joshi/MSP430/Projects/Capacitive_Touch/Getting_Started_Cap_Sense/SLAA491/Examples/RO_PINOSC_TA0_WDTp_Wheel_Buttons" --include_path="C:/Documents and Settings/a0133022/My Documents/Joshi/MSP430/Projects/Capacitive_Touch/Getting_Started_Cap_Sense/SLAA491/Library" --include_path="C:/Program Files/Texas Instruments/CCS_4.2.1.00004/ccsv4/msp430/include" --include_path="C:/Program Files/Texas Instruments/CCS_4.2.1.00004/ccsv4/tools/compiler/MSP430 Code Generation Tools 3.3.3/include" --diag_warning=225 --printf_support=minimal --preproc_with_compile --preproc_dependency="Application/structure.pp" --obj_directory="Application" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


