FILES :=

ifeq ($(CXX), clang++)
    GCOV     := gcov-4.6
    COVFLAGS := --coverage
else
    CXX      := g++-4.8
    COVFLAGS := -fprofile-arcs -ftest-coverage
    GCOV     := gcov-4.8
endif

CXXFLAGS := -pedantic -std=c++11 -Wall
LDFLAGS  := -lgtest -lgtest_main -pthread
VALGRIND := valgrind

.PRECIOUS: %.app

%.app: %.c++
	@echo
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
	@rsync -r -t -u -v --delete             \
	--include "*.c++"                       \
	--include "*.h"                         \
	--include "makefile"                    \
	--exclude "*"                           \
	. downing@$(CS):cs/cs378/c++/exercises/

test: $(FILES:=.c++.gcov)
