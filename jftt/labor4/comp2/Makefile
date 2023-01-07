# SI 413 Fall 2018
# Lab 4
# Makefile for simple calculator

CXX = g++
CXXFLAGS = -Wall -Wextra -Wno-unused-function

# Since it is the first rule, it is what will get made if
# we call "make" with no arguments.
comp: comp.tab.o lex.yy.o
	$(CXX) $(CXXFLAGS) -o comp lex.yy.o comp.tab.o

# Bison generates a C++ source file and a C++ header file.
comp.tab.cpp comp.tab.hpp: comp.ypp
	bison -d comp.ypp

# Flex generates just a C++ source file.
lex.yy.cpp: comp.lpp
	flex -o lex.yy.cpp comp.lpp

# The lex file includes the header from Bison.
lex.yy.o: lex.yy.cpp comp.tab.hpp
	$(CXX) $(CXXFLAGS) -c lex.yy.cpp

comp.tab.o: comp.tab.cpp
	$(CXX) $(CXXFLAGS) -c comp.tab.cpp

# The following line makes "make" automatically clean up these
# files for you when they are no longer needed.
.INTERMEDIATE: comp.tab.o lex.yy.o lex.yy.cpp comp.tab.cpp comp.tab.hpp

# Run "make clean" to clear all extra files.
clean:
	-rm -f *.o *.yy.cpp *.tab.?pp comp

# Do "make run" to run your program... this is used in the submit system
run: comp
	@./comp

# This is how we tell make that these two targets aren't actual files.
.PHONY: clean run
