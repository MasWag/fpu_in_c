CC = gcc
LD = gcc
PRODUCTS = finv_table_gen floor fsqrt_table_gen fsqrt_table_interactive fsqrt i2f fadd fsub fmul finv f2i
OBJS = $(PRODUCTS:%=%.o)
DEPS = $(OBJS:.o=.d)
CFLAGS = -std=c99 -O0 -g -I.. -I../src -Wall -W
LDFLAGS = -L.. -lm -lfpu

all:$(OBJS) $(PRODUCTS)

%:%.o ../libfpu.a
	$(LD) $^ -o $@ $(LDFLAGS)

%.o:%.c %.d
	$(CC) -c $(CFLAGS) -o $@ $<

%.d:%.c
	rm -f $@
	$(CC) -c -MM $(CFLAGS) $< > $@

clean:
	rm -f $(PRODUCTS) *.d *.o

check-syntax:
	$(CC) $(CFLAGS) -fsyntax-only $(CHK_SOURCES)

.PHONY: all test clean check-syntax

-include $(DEPS)
