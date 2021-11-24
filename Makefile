SRCS = $(shell find -name '*.c')
OBJS = $(addsuffix .o, $(basename $(SRCS)))

CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
OBJCOPY = arm-none-eabi-objcopy

CFLAGS = -nostdlib
LDFLAGS = -Tlinking.ld

firmware: $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $^
	$(OBJCOPY) -O ihex $@ $(addsuffix .hex, $@)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm firmware
	rm *.o

.PHONY: clean
