# version 0
# gcc main.c modules.c -o main

# #version 1
# main:main.c modules.c
# 	gcc -o main main.c mudules.c

# #version 2
# CXX = gcc
# TARGET = main
# OBJ = main.o modules.o

# $(TARGET): $(OBJ)
# 	$(CXX) -o $(TARGET) $(OBJ)

# main.o: main.c
# 	$(CXX) -c main.c

# modules.o: modules.c
# 	$(CXX) -c modules.c

#version 3
CXX = gcc
TARGET = main
OBJ = main.o modules.o

CXXFLAGS = -c -Wall

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^

%.o: %.c
	$(CXX) $(CXXFLAGS) $< -o $@

.PHONY: clean
clean:
	del $(OBJ)
#input command: make clean
#rm -f *.o $(TARGET)
#del $(OBJ)

# #version 4
# CXX = gcc
# TARGET = main
# SRC = $(wildcard *.c)
# OBJ = $(patsubst %.c, %.o, $(SRC))
# #SRC 满足条件的全放在一起
# #patsubst 路径替换，将.c替换成.o

# CXXFLAGS = -c -Wall

# $(TARGET): $(OBJ)
# 	$(CXX) -o $@ $^

# %.o: %.c
# 	$(CXX) $(CXXFLAGS) $< -o $@

# .PHONY: clean
# clean:
# 	del $(OBJ)