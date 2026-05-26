
PROJ_NAME := stm32f307xxx_driver

PRO_DIR   := .
OUT_DIR   := $(PRO_DIR)/output
OBJ_DIR   := $(OUT_DIR)/obj

COMPILER_DIR := C:/GCC_Toolchain

CC      := $(COMPILER_DIR)/bin/arm-none-eabi-gcc
OBJCOPY := $(COMPILER_DIR)/bin/arm-none-eabi-objcopy
SIZE    := $(COMPILER_DIR)/bin/arm-none-eabi-size


CPU := cortex-m4

LINKER_FILE := $(PRO_DIR)/linker/stm32f4xx_linker.ld

SRC_DIRS :=                        \
$(PRO_DIR)/app/Src 			       \
$(PRO_DIR)/app/Src/Components/Src  \
$(PRO_DIR)/core/Src          	   \
$(PRO_DIR)/startup/                \
$(PRO_DIR)/drivers/gpio/Src 	   \
$(PRO_DIR)/drivers/rcc/Src         \
$(PRO_DIR)/drivers/flash/Src       \
$(PRO_DIR)/drivers/exti/Src        \
$(PRO_DIR)/drivers/uart/Src        \
$(PRO_DIR)/drivers/can/Src         \


INC_DIRS := 						\
$(PRO_DIR)/app/Inc 					\
$(PRO_DIR)/app/Components/Inc		\
$(PRO_DIR)/core/Inc				    \
$(PRO_DIR)/drivers/gpio/Inc         \
$(PRO_DIR)/drivers/rcc/Inc          \
$(PRO_DIR)/drivers/flash/Inc        \
$(PRO_DIR)/drivers/exti/Inc			\
$(PRO_DIR)/drivers/uart/Inc         \
$(PRO_DIR)/drivers/can/Inc          \


SRC_FILES := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))

VPATH := $(SRC_DIRS)

OBJ_FILES := $(addprefix $(OBJ_DIR)/,$(notdir $(SRC_FILES:.c=.o)))

DEP_FILES := $(OBJ_FILES:.o=.d)

INCLUDE_FLAGS := $(foreach dir,$(INC_DIRS),-I$(dir))

CFLAGS := \
-mcpu=$(CPU) \
-mthumb \
-std=gnu11 \
-O0 \
-g3 \
-Wall \
-Wextra \
-ffunction-sections \
-fdata-sections \
-MMD \
-MP \
$(INCLUDE_FLAGS)

LDFLAGS := \
-T $(LINKER_FILE) \
-mcpu=$(CPU) \
-mthumb \
-Wl,-Map=$(OUT_DIR)/$(PROJ_NAME).map \
-Wl,--gc-sections \
--specs=nano.specs \
--specs=nosys.specs

all: build

build: $(OUT_DIR)/$(PROJ_NAME).elf

# 

$(OUT_DIR)/$(PROJ_NAME).elf: $(OBJ_FILES)
	mkdir -p $(OUT_DIR)
	$(CC) $(OBJ_FILES) $(LDFLAGS) -o $@
	$(OBJCOPY) -O binary $@ $(OUT_DIR)/$(PROJ_NAME).bin
	$(OBJCOPY) -O ihex   $@ $(OUT_DIR)/$(PROJ_NAME).hex

	$(SIZE) $@

	@echo ""
	@echo "========== BUILD SUCCESS =========="

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OUT_DIR)

run:
	$(PRO_DIR)/ST_LINK/ST-LINK_CLI -p "$(OUT_DIR)/$(PROJ_NAME).hex" 0x08000000
	$(PRO_DIR)/ST_LINK/ST-LINK_CLI -rst


print-%:
	@echo '$*=$($*)'

-include $(DEP_FILES)