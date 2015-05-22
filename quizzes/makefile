FILES :=

ifeq ($(shell uname), Darwin)
    CXX      := g++
    COVFLAGS := -fprofile-arcs -ftest-coverage
    LDFLAGS  := /usr/local/lib/gtest_main.a
    GCOV     := gcov
    VALGRIND :=
else ifeq ($(CXX), clang++)
    COVFLAGS := --coverage
    LDFLAGS  := -lgtest -lgtest_main -pthread
    GCOV     := gcov-4.6
    VALGRIND := valgrind
else
    CXX      := g++-4.8
    COVFLAGS := -fprofile-arcs -ftest-coverage
    LDFLAGS  := -lgtest -lgtest_main -pthread
    GCOV     := gcov-4.8
    VALGRIND := valgrind
endif

CXXFLAGS := -pedantic -std=c++11 -Wall

.PRECIOUS: %.app

%.app: %.c++
	@echo
	$(CXX) $(COVFLAGS) $(CXXFLAGS) $< -o $@ $(LDFLAGS)

%.c++.gcov: %.app
	$(VALGRIND) ./$<
	-$(GCOV) -b $(<:.app=.c++) | grep -A 5 "File './$(<:.app=.h)'"
	$(GCOV) -b $(<:.app=.c++) | grep -A 5 "File '$(<:.app=.c++)'"

clean:
	rm -f *.app
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.gcov

sync:
	make clean
	@echo `pwd`
	@rsync -r -t -u -v --delete \
    --include "*.c++"           \
    --include "*.h"             \
    --include "makefile"        \
    --exclude "*"               \
    . downing@$(CS):cs/cs378/c++/quizzes/

test: $(FILES:=.c++.gcov)
