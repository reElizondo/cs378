FILES :=  \
    Quiz3 \
    Quiz5 \
    Quiz6 \
    Quiz7 \
    Quiz8 \
    Quiz9 \
    Quiz11

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

.PRECIOUS: %.appx %.appy

%.appx: %.c++
	$(CXX) $(GCOVFLAGS) $(CXXFLAGS) $< -o $@ $(LDFLAGS)

%.appy: %.c++
	$(CXX) -pg $(CXXFLAGS) $< -o $@ $(LDFLAGS)

%.c++x: %.appx %.appy
	echo
	./$<

%.c++y: %.appx %.appy
	echo
	$(VALGRIND) ./$<
	$(GCOV) -b $(<:.appx=.c++) > $(<:.appx=.appx.gcov) 2>&1
ifdef GPROF
	./$(<:.appx=.appy)
	$(GPROF) $(<:.appx=.appy) > $(<:.appx=.appy.gprof) 2>&1
endif

clean:
	rm -f *.appx
	rm -f *.appy
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.gcov
	rm -f *.gprof

sync:
	make clean
	@echo `pwd`
	@rsync -r -t -u -v --delete \
    --include "*.c++"           \
    --include "*.h"             \
    --include "makefile"        \
    --exclude "*"               \
    . downing@$(CS):cs/cs378/github/c++/quizzes/

test: $(FILES:=.c++y)

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
