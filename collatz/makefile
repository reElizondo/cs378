ifeq ($(shell uname), Darwin)
    CXX       := g++
    CXXVER    := --version 2>&1 | grep c++
    GTESTVER  := head -1 /usr/local/src/gtest-1.7.0/CHANGES
    GCOV      := gcov
    GCOVFLAGS := -fprofile-arcs -ftest-coverage
    GCOVVER   := -version | grep version
    GPROF     :=
    BOOST     := /usr/local/src/boost_1_57_0/boost
    LDFLAGS   := -lgtest_main
    VALGRIND  :=
else ifeq ($(CXX), clang++)
    CXXVER    := --version 2>&1 | grep clang
    GTESTVER  := dpkg -l libgtest-dev | grep libgtest
    GCOV      := gcov-4.6
    GCOVFLAGS := --coverage
    GCOVVER   := -v | grep gcov
    GPROF     := gprof
    GPROFFLAGS :- -pg
    BOOST     := /usr/include/boost
    LDFLAGS   := -lgtest -lgtest_main -pthread
    VALGRIND  := valgrind
else
    CXX       := g++-4.8
    CXXVER    := --version 2>&1 | grep g++
    GTESTVER  := dpkg -l libgtest-dev | grep libgtest
    GCOV      := gcov-4.8
    GCOVFLAGS := -fprofile-arcs -ftest-coverage
    GCOVVER   := -v | grep gcov
    GPROF     := gprof
    BOOST     := /usr/include/boost
    LDFLAGS   := -lgtest -lgtest_main -pthread
    VALGRIND  := valgrind
endif

CXXFLAGS := -pedantic -std=c++11 -Wall

clean:
	rm -f *.appx
	rm -f *.appy
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.gcov

sync:
	make clean
	@echo `pwd`
	@rsync -r -t -u -v --delete        \
    --include "Collatz.c++"            \
    --include "Collatz.h"              \
    --include "gitignore.sample"       \
    --include "makefile.sample"        \
    --include "makefile"               \
    --include "RunCollatz.c++"         \
    --include "RunCollatz.in"          \
    --include "RunCollatz.sample.out"  \
    --include "TestCollatz.c++"        \
    --include "TestCollatz.sample.out" \
    --exclude "*"                      \
    . downing@$(CS):cs/cs378/github/c++/collatz/

test: RunCollatz.c++x TestCollatz.c++x

versions:
	which $(CXX)
	@echo
	$(CXX) $(CXXVER)
	@echo
	$(GTESTVER)
	@echo
	which $(GCOV)
	@echo
	$(GCOV) $(GCOVVER)
	@echo
	grep "#define BOOST_VERSION " $(BOOST)/version.hpp
ifdef GPROF
	@echo
	which $(GPROF)
	@echo
	$(GPROF) --version
endif
ifdef VALGRIND
	@echo
	which $(VALGRIND)
	@echo
	$(VALGRIND) --version
endif
	@echo
	which doxygen
	@echo
	doxygen --version

RunCollatz.appx: Collatz.h Collatz.c++ RunCollatz.c++
	$(CXX) $(CXXFLAGS) Collatz.c++ RunCollatz.c++ -o RunCollatz

RunCollatz.c++x: RunCollatz.appx
	./RunCollatz < RunCollatz.in

TestCollatz.appx: Collatz.h Collatz.c++ TestCollatz.c++
	$(CXX) $(GCOVFLAGS) $(CXXFLAGS) Collatz.c++ TestCollatz.c++ -o TestCollatz.appx $(LDFLAGS)

TestCollatz.appy: Collatz.h Collatz.c++ TestCollatz.c++
	$(CXX) $(CXXFLAGS) Collatz.c++ TestCollatz.c++ -o TestCollatz.appy $(LDFLAGS) -pg

TestCollatz.c++x: TestCollatz.appx TestCollatz.appy
	$(VALGRIND) ./TestCollatz.appx
	$(GCOV) -b Collatz.c++     | grep -A 5 "File 'Collatz.c++'"
	$(GCOV) -b TestCollatz.c++ | grep -A 5 "File 'TestCollatz.c++'"
ifdef GPROF
	./TestCollatz.appy
	$(GPROF) TestCollatz.appy
endif
