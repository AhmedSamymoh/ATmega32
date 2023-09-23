################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/EXTI/subdir.mk
-include MCAL/DIO/subdir.mk
-include HAL/SEVEN_SEGMENTS/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/KEYPAD/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Atmega32_Drivers.lss \

FLASH_IMAGE += \
Atmega32_Drivers.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: Atmega32_Drivers.elf secondary-outputs

# Tool invocations
Atmega32_Drivers.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Atmega32_Drivers.map -mmcu=atmega32 -o "Atmega32_Drivers.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Atmega32_Drivers.lss: Atmega32_Drivers.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Atmega32_Drivers.elf  >"Atmega32_Drivers.lss"
	@echo 'Finished building: $@'
	@echo ' '

Atmega32_Drivers.hex: Atmega32_Drivers.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Atmega32_Drivers.elf  "Atmega32_Drivers.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Atmega32_Drivers.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Atmega32_Drivers.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: Atmega32_Drivers.elf
	@echo 'Invoking: AVRDude'
	E:\IMT_Course\Tools\IMT_SDK_Win_64\WinAVR\bin\avrdude -pm32 -cusbasp -Uflash:w:Atmega32_Drivers.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Atmega32_Drivers.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
