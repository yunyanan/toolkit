# Makefile
#
#

# TODO !
ifneq ($(MAKESINGLE),)

EXTRA_CFLAGS :=
CFLAGS_toolkit_common.o :=

obj-y += toolkit_common.o

else

all:
	$(MAKE) -C $(RDIR) M=$(PWD) single

clean:
	rm *.o
endif
