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
	@rsync -r -t -u -v --delete \
    --include "Deque.h"         \
    --include "makefile"        \
    --include "TestDeque.c++"   \
    --exclude "*"               \
    . downing@$(CS):cs/cs378/github/c++/deque/

test: TestDeque.c++x

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

TestDeque.appx: Deque.h Deque.c++ TestDeque.c++
	$(CXX) $(GCOVFLAGS) $(CXXFLAGS) Deque.c++ TestDeque.c++ -o TestDeque.appx $(LDFLAGS)

TestDeque.appy: Deque.h Deque.c++ TestDeque.c++
	$(CXX) $(CXXFLAGS) Deque.c++ TestDeque.c++ -o TestDeque.appy $(LDFLAGS) -pg

TestDeque.c++x: TestDeque.appx TestDeque.appy
	$(VALGRIND) ./TestDeque.appx
	$(GCOV) -b TestDeque.c++ | grep -A 5 "File 'TestDeque.c++'"
ifdef GPROF
	./TestDeque.appy
	$(GPROF) TestDeque.appy
endif
