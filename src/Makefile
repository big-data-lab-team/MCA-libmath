# Makefile for the instrumented shared library

CC = verificarlo
CFLAGS = -fPIC   # C flags
LDFLAGS = -shared   # linking flags
RM = rm -f 

TARGET_LIB = libpreload.so  # target lib

SRCS = wrapping_script.c  # source files
OBJS = $(SRCS:.c=.o)

$(TARGET_LIB): $(OBJS)
	$(CC) ${LDFLAGS} -ldl -o $@ $^

clean:
	-${RM} ${TARGET_LIB} ${OBJS} $(SRCS:.c=.d)

