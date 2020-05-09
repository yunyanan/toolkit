# Makefile

ifeq ($(CROSS_COMPILE),)
# $(error Please initialize the Cross-compilation environment)
endif
ifeq ($(AS),)
AS			  = $(CROSS_COMPILE)as
endif
ifeq ($(LD),)
LD			  = $(CROSS_COMPILE)ld
endif
ifeq ($(CC),)
CC			  = $(CROSS_COMPILE)gcc
endif
ifeq ($(CPP),)
CPP			  = $(CC) -E
endif
ifeq ($(AR),)
AR			  = $(CROSS_COMPILE)ar
endif
ifeq ($(NM),)
NM			  = $(CROSS_COMPILE)nm
endif

ifeq ($(STRIP),)
STRIP		  = $(CROSS_COMPILE)strip
endif
ifeq ($(OBJCOPY),)
OBJCOPY		  = $(CROSS_COMPILE)objcopy
endif
ifeq ($(OBJDUMP),)
OBJDUMP		  = $(CROSS_COMPILE)objdump
endif

export AS LD CC CPP AR NM
export STRIP OBJCOPY OBJDUMP

ifeq ("$(origin V)", "command line")
  VERBOSE = $(V)
endif
ifndef VERBOSE
  VERBOSE = 0
endif

ifeq ($(VERBOSE),1)
  Q =
else
  Q = @
  MAKEFLAGS += --no-print-directory
endif
export Q VERBOSE

TOPDIR = $(shell pwd)
export TOPDIR

CFLAGS := -Wall -O0 -g
CFLAGS += -I $(TOPDIR)				\
		  -I $(TOPDIR)/example/inc

LDFLAGS := -pthread

export CFLAGS LDFLAGS

TARGET := toolkit

obj-y += example/src/

all: recursive $(TARGET)
	$(Q)echo ================================
	$(Q)echo Target $(TARGET) has been built!
	$(Q)echo ================================

recursive:
	$(Q)$(MAKE) -C ./ -f $(TOPDIR)/Makefile.build

$(TARGET): built-in.o
	$(Q)echo CC $^
	$(Q)$(CC) -o $(TARGET) built-in.o $(LDFLAGS)

.PHONY: clean distclean
clean:
	$(Q)rm -f $(shell find -name "*.o")
	$(Q)rm -f $(TARGET)

distclean:
	$(Q)rm -f $(shell find -name "*.o")
	$(Q)rm -f $(shell find -name "*.d")
	$(Q)rm -f $(TARGET)
