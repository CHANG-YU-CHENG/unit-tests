EXEC = bin-swap bin-bubble
.PHONY: all
all: $(EXEC)
# CC means C language compile procudure
CC ?= gcc
# CFLAGES means C language compiler flags
CFLAGS = -std=gnu99 -Wall -O2 -g
# LDFLAGS means loader flags
LDFLAGS =

# macro variable OBJS contains all of files like xxx.o
OBJS := \
	swap.o \
	bubble.o \
	stub.o
# $@ means %.o  ,  $< means %.c  , compile statement(xxx.c -> xxx.o)
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<
# $@ means bin-%  ,  loader statement(xxx.o, yyy.o -> xxx )
bin-%: %.o stub.o
	$(CC) -o $@ $^ $(LDFLAGS)

# execute test-swap.sh  ,  test-bubble.sh
check: $(EXEC)
	bash test-swap.sh data-swap.in result-swap
	bash test-bubble.sh data-bubble.in result-bubble
# RM means remove file procudure( default = rm -f )
clean:
	$(RM) $(EXEC) $(OBJS)
