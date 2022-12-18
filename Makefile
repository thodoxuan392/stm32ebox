##########################################################################################################################
# File automatically-generated by tool: [projectgenerator] version: [3.7.1] date: [Mon Apr 13 10:53:27 ICT 2020]
##########################################################################################################################

# ------------------------------------------------
# Generic Makefile (based on gcc)
#
# ChangeLog :
#   2022-11-10 - Update flow for remote deployment
#	2017-02-10 - Several enhancements + project update mode
#   2015-07-22 - first version
# ------------------------------------------------

##################################################
# Edited by Xuan Tho Do
##################################################
include toolchain.mk
include board.mk
######################################
# target
######################################
TARGET = stm32


######################################
# building variables
######################################
# debug build?
DEBUG = 1
# optimization
OPT = -Os


#######################################
# paths
#######################################
# Build path
BUILD_DIR = build

######################################
# source
######################################
# C sources

C_SOURCES =  ${shell find .  -type f -name "*.c"}

# ASM sources
ASM_SOURCES =  ${shell find ./ -type f -name "*.s"}



 
#######################################
# CFLAGS
#######################################
# cpu
CPU = -mcpu=cortex-m3

# fpu
# NONE for Cortex-M0/M0+/M3

# float-abi
FLOAT-ABI = -mfloat-abi=soft

GCC_STD = -std=gnu11


# mcu
MCU = $(CPU) -mthumb $(FPU) $(FLOAT-ABI)

# macros for gcc
# AS defines
AS_DEFS = 

# C defines
C_DEFS =  \
-DDEBUG \
-D$(BOARD_DEFINE)\
-DUSE_HAL_DRVIER


# AS includes
AS_INCLUDES = 

# C includes
C_INCLUDES = $(GCC_INCLUDE_PATH)  \
-IInc \
-IDrivers/$(BOARD_FAMILY)_HAL_Driver/Inc/Legacy \
-IDrivers/$(BOARD_FAMILY)_HAL_Driver/Inc \
-IDrivers/CMSIS/Device/ST/$(BOARD_FAMILY)/Include \
-IDrivers/CMSIS/Include \
-ILib/netif/inc


# compile gcc flags
ASFLAGS = $(MCU) $(GCC_STD) $(AS_DEFS) $(AS_INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections  -fstack-usage 

CFLAGS = $(MCU) $(GCC_STD) $(C_DEFS) $(C_INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections  -fstack-usage

#DEBUG LEVEL
CFLAGS += -g3


# Generate dependency information
CFLAGS += -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)"


#######################################
# LDFLAGS
#######################################
# link script
LDSCRIPT = STM32F103RBTX_FLASHre.ld

# libraries
LIBS = -lc -lm -lnosys 
LIBDIR = 
LDFLAGS = $(MCU) -specs=nano.specs -T$(LDSCRIPT) $(LIBDIR) $(LIBS) -Wl,-Map=$(BUILD_DIR)/$(TARGET).map,--cref -Wl,--gc-sections -Wl,--print-memory-usage

# default action: build all
all: $(BUILD_DIR)/$(TARGET).elf $(BUILD_DIR)/$(TARGET).hex $(BUILD_DIR)/$(TARGET).bin


#######################################
# build the application
#######################################
# list of objects
OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(C_SOURCES:.c=.o)))
vpath %.c $(sort $(dir $(C_SOURCES)))
# list of ASM program objects
OBJECTS += $(addprefix $(BUILD_DIR)/,$(notdir $(ASM_SOURCES:.s=.o)))
vpath %.s $(sort $(dir $(ASM_SOURCES)))

$(BUILD_DIR)/%.o: %.c Makefile | $(BUILD_DIR) 
	$(CC) -c $(CFLAGS) -Wa,-a,-ad,-alms=$(BUILD_DIR)/$(notdir $(<:.c=.lst)) $< -o $@

$(BUILD_DIR)/%.o: %.s Makefile | $(BUILD_DIR)
	$(AS) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/$(TARGET).elf: $(OBJECTS) Makefile
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@
	$(SZ) $@

$(BUILD_DIR)/%.hex: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(HEX) $< $@
	
$(BUILD_DIR)/%.bin: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(BIN) $< $@	
	
$(BUILD_DIR):
	mkdir $@

#######################################
# Local Deploy
#######################################		
flash-local: $(BUILD_DIR)/$(TARGET).bin
ifeq ($(OS),Windows_NT)
	@ST-LINK_CLI.exe -ME -P $< 0x08000000
else  
	@st-flash write $< 0x08000000
endif
	

#######################################
# Remote Deploy
#######################################		
flash-remote: $(BUILD_DIR)/$(TARGET).bin
ifeq ($(OS),Windows_NT)
	@echo "Copy file to Remote Server $(USER) $(PASSWD) $(SERVER):$(PORT)" 
	@scp -o StrictHostKeyChecking=no  -P $(PORT)  $(BUILD_DIR)/$(TARGET).bin $(USER)@$(SERVER):~/
	@echo "Flash file to remote target device"
	@ssh -o StrictHostKeyChecking=no -p $(PORT)  $(USER)@$(SERVER) "st-flash write ~/$(TARGET).bin 0x08000000"
else  
	@echo "Copy file to Remote Server $(USER) $(PASSWD) $(SERVER):$(PORT)" 
	@sshpass -p "$(PASSWD)"  scp -o StrictHostKeyChecking=no   -P $(PORT)  $(BUILD_DIR)/$(TARGET).bin $(USER)@$(SERVER):~/
	@echo "Flash file to remote target device"
	@sshpass -p "$(PASSWD)" ssh -o StrictHostKeyChecking=no  -p $(PORT)  $(USER)@$(SERVER) "st-flash write ~/$(TARGET).bin 0x08000000"
endif

	

#######################################
# clean up
#######################################
clean:
	-rm -fR $(BUILD_DIR)
  
#######################################
# dependencies
#######################################
-include $(wildcard $(BUILD_DIR)/*.d)

# *** EOF ***