FILES :=

cs:
	make clean
	@echo `pwd`
	@rsync -r -t -u -v --delete           \
	--include "*.c++"                     \
	--include "*.h"                       \
	--include "makefile"                  \
	--exclude "*"                         \
	. downing@$(CS):cs/cs378/c++/quizzes/

ifeq ($(shell uname), Darwin)
    CXX      := g++
    GCOV     := gcov -b
    LDFLAGS  := /usr/local/lib/gtest_main.a
    VALGRIND :=
else
    CXX      := g++-4.8
    GCOV     := gcov-4.8 -b
    LDFLAGS  := -lgtest -lgtest_main -pthread
    VALGRIND := valgrind
endif

CXXFLAGS := -fprofile-arcs -ftest-coverage -pedantic -std=c++11 -Wall

%: %.c++
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)

all: $(FILES)

clean:
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.gcov
	@for i in $(FILES); \
	do                  \
        echo rm -f $$i; \
             rm -f $$i; \
    done

testx: all
	@for i in $(FILES); \
	do                  \
        echo ./$$i;     \
             ./$$i;     \
    done

testy: all
	@for i in $(FILES); \
	do                  \
        echo $(VALGRIND) ./$$i;                               \
             $(VALGRIND) ./$$i;                               \
        echo $(GCOV) ./$$i.c++ \| grep -A 5 "File './$$i.h'"; \
             $(GCOV) ./$$i.c++  | grep -A 5 "File './$$i.h'"; \
        echo $(GCOV) ./$$i.c++ \| grep -A 5 "File '$$i.c++'"; \
             $(GCOV) ./$$i.c++  | grep -A 5 "File '$$i.c++'"; \
    done
