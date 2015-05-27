PROJECT_NAME=hx8352a-lcd

BUILDDIR = build

LIBDIR = ../common
DEVICE = $(LIBDIR)/STM32F4xx
CORE = $(LIBDIR)/CMSIS
PERIPH = $(LIBDIR)/STM32F4xx_StdPeriph_Driver
PROJHEADERS = inc
PROJ_LIBDIR = lib
PROJ_LIBSRCDIR = $(PROJ_LIBDIR)/src


#SOURCES = src/main.cpp
SOURCES = startup_stm32f4xx.S
SOURCES += system_stm32f4xx.c
SOURCES += LibraryHacks.cpp

SOURCES += src/main.cpp
#SOURCES += $(PERIPH)/src/
#PROJECT SOURCES
SOURCES += $(PROJ_LIBSRCDIR)/stream/LinearBufferInputOutputStream.cpp
SOURCES += $(PROJ_LIBSRCDIR)/stream/LzgDecompressionInputStream.cpp



OBJECTS = $(addprefix $(BUILDDIR)/, $(addsuffix .o, $(abspath $(basename $(SOURCES)))))

C_INCLUDES += -I$(DEVICE) \
			-I$(PROJHEADERS) \
			-I$(CORE) \
			-I$(PERIPH)/inc \
			-I$(PROJ_LIBDIR)/inc \
			-Isrc \
			-I.
CXX_INCLUDES += $(C_INCLUDES) \
			-I$(PROJ_LIBDIR)/inc/stl 


ELF = $(BUILDDIR)/$(PROJECT_NAME).elf
HEX = $(BUILDDIR)/$(PROJECT_NAME).hex
BIN = $(BUILDDIR)/$(PROJECT_NAME).bin

CC = arm-none-eabi-gcc
CXX = arm-none-eabi-g++
LD = arm-none-eabi-g++
AR = arm-none-eabi-ar
OBJCOPY = arm-none-eabi-objcopy
GDB = arm-none-eabi-gdb
SIZE = arm-none-eabi-size

FLAGS = -O0 -g -Wall -I.\
   -std=c++11 -mlittle-endian -mthumb -mcpu=cortex-m4 -mthumb-interwork \
   -mfpu=fpv4-sp-d16 -mfloat-abi=hard \
    -DUSE_STDPERIPH_DRIVER -D"STM32PLUS_F407" -D"HSE_VALUE=8000000"

CFLAGS  = $(FLAGS) -std=c99 $(C_INCLUDES)
CXXFLAGS  = $(FLAGS) -std=gnu++0x  $(CXX_INCLUDES) -fabi-version=0 -fno-exceptions -fno-rtti -pedantic-errors -fno-threadsafe-statics

SEMIHOSTING_FLAGS = --specs=rdimon.specs -lc -lrdimon

LDSCRIPT = stm32_flash.ld
LDFLAGS += -T$(LDSCRIPT) -mthumb -mcpu=cortex-m4 

$(BIN): $(ELF)
	$(OBJCOPY) -O binary $< $@

$(HEX): $(ELF)
	$(OBJCOPY) -O ihex $< $@

$(ELF): $(OBJECTS)
	$(LD) $(LDFLAGS) $(CFLAGS) $(SEMIHOSTING_FLAGS) -o $@ $(OBJECTS) $(LDLIBS)
	$(SIZE) $@

$(BUILDDIR)/%.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) -c $(CXXFLAGS) $< -o $@

$(BUILDDIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) $< -o $@

$(BUILDDIR)/%.o: %.S
	mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) $< -o $@

flash: $(BIN)
	st-flash write $(BIN) 0x8000000

debug: $(ELF)
	$(GDB) -tui $(ELF)

openocd: $(ELF)
	openocd -f board/stm32f4discovery.cfg

all: $(HEX) $(BIN) $(ELF)

functions: all

.PHONY: clean
clean:
	rm -rf build
