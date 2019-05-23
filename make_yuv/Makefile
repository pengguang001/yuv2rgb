#
# (C) Copyleft 2011 2012 2013
# Late Lee from http://www.latelee.org
# 
# A simple Makefile for *ONE* project(c or/and cpp file) in *ONE*  directory
#
# note: 
# you can put head file(s) in 'include' directory, so it looks 
# a little neat.
#
# usage: $ make
#        $ make debug=y
#
# log
#       2013-05-14 sth about debug...
###############################################################################

# !!!=== cross compile...
CROSS_COMPILE = 

CC = $(CROSS_COMPILE)gcc
CXX = $(CROSS_COMPILE)g++
AR = $(CROSS_COMPILE)ar

ARFLAGS = cr
RM = -rm -rf
MAKE = make

CFLAGS := -Wall

#****************************************************************************
# debug can be set to y to include debugging info, or n otherwise
debug          := n

#****************************************************************************

ifeq ($(debug), y)
CFLAGS += -ggdb -rdynamic
else
CFLAGS += -O2
endif

# !!!===
DEFS = 

CFLAGS += $(DEFS)

LDFLAGS := $(LIBS)

# !!!===
INCDIRS := -I./

# !!!===
CFLAGS += $(INCDIRS)

# !!!===
LDFLAGS += 

# !!!===
# source file(s), including c file(s) cpp file(s)
# you can also use $(wildcard *.c), etc.
SRC_C   := $(wildcard *.c)
SRC_CPP := $(wildcard *.cpp)

SRC_COMMON :=  file_utils.c   fill_yuvdata.c
SRC_NV21 := $(SRC_COMMON) nv21.c
OBJ_NV21 := $(patsubst %.c,%.o,$(SRC_NV21))
SRC_YUV420P := $(SRC_COMMON) yuv420p.c
OBJ_YUV420P := $(patsubst %.c,%.o,$(SRC_YUV420P))

# object file(s)
OBJ_C   := $(patsubst %.c,%.o,$(SRC_C))
OBJ_CPP := $(patsubst %.cpp,%.o,$(SRC_CPP))

# !!!===
# executable file
target = nv21 yuv420p

###############################################################################

all: $(target)

nv21: $(OBJ_NV21)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "Generating:" $@

yuv420p: $(OBJ_YUV420P)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "Generating:" $@

# make all .c or .cpp
%.o: %.c
	@echo "Compiling: " $(addsuffix .c, $(basename $(notdir $@)))
	@$(CC) $(CFLAGS) -c $^ -o $@

%.o: %.cpp
	@echo "Compiling: " $(addsuffix .cpp, $(basename $(notdir $@)))
	@$(CC) $(CFLAGS) -c $^ -o $@

clean:
	@echo "Cleaning..."
	@$(RM) $(target)
	@$(RM) *.o *.back *~

.PHONY: all clean
