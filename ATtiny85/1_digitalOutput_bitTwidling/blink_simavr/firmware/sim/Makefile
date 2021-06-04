
CPPFLAGS += -I..
OFLAG ?= -Og
DEBUG ?= -g

VPATH = ..

DESTDIR = /usr/local/Cellar
PREFIX = ${DESTDIR}

simavr 		= ..

IPATH 		+= ${simavr}/include
IPATH 		+= ${simavr}/simavr/sim/avr

# Ensure malloc is available when debugging
OBJS += force_malloc.o

ifeq ($(TRACE), 1)
OBJS += simavr.o
endif

%.svg: %.dot
	dot -T svg -o $@ $<

include ../Makefile

.PHONY: simavr
simavr:
	simavr -m attiny85 -f 1000000 blink.elf -t -g


