FILES :=       \
	Hello      \
	UnitTests3 \
	Coverage1  \
	Coverage2  \
	Coverage3

ifeq ($(shell uname), Darwin)
    CXX      := g++
    GCOV     := gcov
    LDFLAGS  := /usr/local/lib/gtest_main.a
    VALGRIND :=
else
    CXX      := g++-4.8
    GCOV     := gcov-4.8
    LDFLAGS  := -lgtest -lgtest_main -pthread
    VALGRIND := valgrind
endif

COVFLAGS := -fprofile-arcs -ftest-coverage
CXXFLAGS := -pedantic -std=c++11 -Wall

.PRECIOUS: %.app

%.app: %.c++
	$(CXX) $(COVFLAGS) $(CXXFLAGS) $< -o $@ $(LDFLAGS)

%.c++.gcov: %.app
	$(VALGRIND) ./$<
	-$(GCOV) -b $(<:.app=.c++) | grep -A 5 "File './$(<:.app=.h)'"
	$(GCOV) -b $(<:.app=.c++) | grep -A 5 "File '$(<:.app=.c++)'"

all: $(FILES:=.app)

clean:
	rm -f *.app
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.gcov

sync:
	make clean
	@echo `pwd`
	@rsync -r -t -u -v --delete            \
	--include "*.c++"                      \
	--include "*.h"                        \
	--include "makefile"                   \
	--exclude "*"                          \
	. downing@$(CS):cs/cs378/c++/examples/

test: $(FILES:=.c++.gcov)
