################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccs1260/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./sources/DSP2833x_ADC_cal.obj" \
"./sources/DSP2833x_Adc.obj" \
"./sources/DSP2833x_CSMPasswords.obj" \
"./sources/DSP2833x_CodeStartBranch.obj" \
"./sources/DSP2833x_CpuTimers.obj" \
"./sources/DSP2833x_DBGIER.obj" \
"./sources/DSP2833x_DMA.obj" \
"./sources/DSP2833x_DefaultIsr.obj" \
"./sources/DSP2833x_DisInt.obj" \
"./sources/DSP2833x_ECan.obj" \
"./sources/DSP2833x_ECap.obj" \
"./sources/DSP2833x_EPwm.obj" \
"./sources/DSP2833x_EQep.obj" \
"./sources/DSP2833x_GlobalVariableDefs.obj" \
"./sources/DSP2833x_Gpio.obj" \
"./sources/DSP2833x_I2C.obj" \
"./sources/DSP2833x_Mcbsp.obj" \
"./sources/DSP2833x_MemCopy.obj" \
"./sources/DSP2833x_PieCtrl.obj" \
"./sources/DSP2833x_PieVect.obj" \
"./sources/DSP2833x_Sci.obj" \
"./sources/DSP2833x_Spi.obj" \
"./sources/DSP2833x_SysCtrl.obj" \
"./sources/DSP2833x_Xintf.obj" \
"./sources/DSP2833x_usDelay.obj" \
"./sources/main.obj" \
$(GEN_CMDS__FLAG) \
-l"C:/Users/Danial/workspace_v12/header_files/common/cmd/28335_RAM_lnk.cmd" \
-l"C:/Users/Danial/workspace_v12/header_files/headers/cmd/DSP2833x_Headers_nonBIOS.cmd" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include sources/subdir_vars.mk
-include sources/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
project2.out 

EXE_OUTPUTS__QUOTED += \
"project2.out" 


# All Target
all: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "project2.out"

# Tool invocations
project2.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: C2000 Linker'
	"C:/ti/ccs1260/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -g --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi -z -m"project2.map" --stack_size=0x300 --warn_sections -i"C:/ti/ccs1260/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/lib" -i"C:/ti/ccs1260/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/include" --reread_libs --diag_wrap=off --display_error_number --xml_link_info="project2_linkInfo.xml" --rom_model -o "project2.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)
	-$(RM) "sources\DSP2833x_ADC_cal.obj" "sources\DSP2833x_Adc.obj" "sources\DSP2833x_CSMPasswords.obj" "sources\DSP2833x_CodeStartBranch.obj" "sources\DSP2833x_CpuTimers.obj" "sources\DSP2833x_DBGIER.obj" "sources\DSP2833x_DMA.obj" "sources\DSP2833x_DefaultIsr.obj" "sources\DSP2833x_DisInt.obj" "sources\DSP2833x_ECan.obj" "sources\DSP2833x_ECap.obj" "sources\DSP2833x_EPwm.obj" "sources\DSP2833x_EQep.obj" "sources\DSP2833x_GlobalVariableDefs.obj" "sources\DSP2833x_Gpio.obj" "sources\DSP2833x_I2C.obj" "sources\DSP2833x_Mcbsp.obj" "sources\DSP2833x_MemCopy.obj" "sources\DSP2833x_PieCtrl.obj" "sources\DSP2833x_PieVect.obj" "sources\DSP2833x_Sci.obj" "sources\DSP2833x_Spi.obj" "sources\DSP2833x_SysCtrl.obj" "sources\DSP2833x_Xintf.obj" "sources\DSP2833x_usDelay.obj" "sources\main.obj" 
	-$(RM) "sources\DSP2833x_Adc.d" "sources\DSP2833x_CpuTimers.d" "sources\DSP2833x_DMA.d" "sources\DSP2833x_DefaultIsr.d" "sources\DSP2833x_ECan.d" "sources\DSP2833x_ECap.d" "sources\DSP2833x_EPwm.d" "sources\DSP2833x_EQep.d" "sources\DSP2833x_GlobalVariableDefs.d" "sources\DSP2833x_Gpio.d" "sources\DSP2833x_I2C.d" "sources\DSP2833x_Mcbsp.d" "sources\DSP2833x_MemCopy.d" "sources\DSP2833x_PieCtrl.d" "sources\DSP2833x_PieVect.d" "sources\DSP2833x_Sci.d" "sources\DSP2833x_Spi.d" "sources\DSP2833x_SysCtrl.d" "sources\DSP2833x_Xintf.d" "sources\main.d" 
	-$(RM) "sources\DSP2833x_ADC_cal.d" "sources\DSP2833x_CSMPasswords.d" "sources\DSP2833x_CodeStartBranch.d" "sources\DSP2833x_DBGIER.d" "sources\DSP2833x_DisInt.d" "sources\DSP2833x_usDelay.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

