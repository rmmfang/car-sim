CC = g++
INCLUDE_DIR := $(CAR_ROOT)/include
SRC := car
CFLAGS := -shared -std=c++11 -g
LIB_DARA := libdata.so

all : $(LIB_DATA)

$(LIB_DATA) : libdir objdir obj/car.o obj/tick.o
	$(CC) $(CFLAGS) -o $(CAR_ROOT)/lib/$(LIB_DATA) obj/*.o
	rm -r $(CAR_ROOT)/obj

libdir :
	mkdir -p $(CAR_ROOT)

objdir :



