# An admittedly primitive Makefile
# To compile, type "make" or make "all"
# To remove files, type "make clean"

CC = gcc
CFLAGS = -g -Wall -Wextra -fsanitize={address,undefined} # -Werror  # -fsanitize=thread # -O0
OBJS = wserver.o wclient.o request.o io_helper.o thread_pool.o scheduler.o

.SUFFIXES: .c .o 

all: wserver wclient

wserver: wserver.o request.o io_helper.o thread_pool.o scheduler.o
	$(CC) $(CFLAGS) -o wserver wserver.o request.o io_helper.o thread_pool.o scheduler.o

wclient: wclient.o io_helper.o
	$(CC) $(CFLAGS) -o wclient wclient.o io_helper.o

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	-rm -f $(OBJS) wserver wclient
