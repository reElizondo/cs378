ifeq ($(shell uname), Darwin)
    CXX       := g++
    GTEST     := head -1 /usr/local/src/gtest-1.7.0/CHANGES
    GCOV      := gcov
    BOOST     := /usr/local/src/boost_1_57_0/boost
    VALGRIND1 :=
    VALGRIND2 :=
else ifeq ($(CXX), clang++)
    GTEST     := dpkg -l libgtest-dev
    GCOV      := gcov-4.6
    BOOST     := /usr/include/boost
    VALGRIND1 := which valgrind
    VALGRIND2 := valgrind --version
else
    CXX       := g++-4.8
    GTEST     := dpkg -l libgtest-dev
    GCOV      := gcov-4.8
    BOOST     := /usr/include/boost
    VALGRIND1 := which valgrind
    VALGRIND2 := valgrind --version
endif

clean:
	cd examples; make --no-print-directory clean
	@echo
	cd exercises; make --no-print-directory clean
	@echo
	cd projects/collatz; make --no-print-directory clean
	@echo
	cd quizzes; make --no-print-directory clean

config:
	git config -l

init:
	touch README
	git init
	git add README
	git commit -m 'first commit'
	git remote add origin git@github.com:gpdowning/cs378.git
	git push -u origin master

pull:
	@rsync -r -t -u -v --delete             \
    --include "Hello.c++"                   \
    --include "Assertions.c++"              \
    --include "Collatz1.h"                  \
    --include "Collatz2.h"                  \
    --include "UnitTests1.c++"              \
    --include "UnitTests2.c++"              \
    --include "UnitTests3.c++"              \
    --include "Coverage1.c++"               \
    --include "Coverage2.c++"               \
    --include "Coverage3.c++"               \
    --exclude "*"                           \
    ../../../examples/c++/ examples
	@echo
	@rsync -r -t -u -v --delete             \
    --include "collatz/"                    \
    --include "Collatz.c++"                 \
    --include "Collatz.h"                   \
    --include "gitignore.sample"            \
    --include "makefile"                    \
    --include "makefile.sample"             \
    --include "RunCollatz.c++"              \
    --include "RunCollatz.in"               \
    --include "RunCollatz.sample.out"       \
    --include "TestCollatz.c++"             \
    --include "TestCollatz.sample.out"      \
    --include "travis.sample.yml"           \
    --exclude "*"                           \
    ../../../projects/c++/ projects

push:
	make clean
	@echo
	git add .travis.yml
	git add examples
	git add exercises
	git add makefile
	git add projects
	git add quizzes
	git commit -m "another commit"
	git push
	git status

status:
	make clean
	@echo
	git add examples
	git add exercises
	git add projects
	git add quizzes
	git branch
	git remote -v
	git status

sync:
	@echo `pwd`
	@rsync -r -t -u -v --delete \
    --include "makefile"        \
    --exclude "*"               \
    . downing@$(CS):cs/cs378/github/c++/
	@echo
	cd examples; make sync
	@echo
	cd exercises; make sync
	@echo
	cd projects/collatz; make sync
	@echo
	cd quizzes; make sync

test:
	cd examples;                                    \
        make --no-print-directory test;             \
        make --no-print-directory clean;            \
        make --no-print-directory test CXX=clang++
	@echo
	cd exercises;                                   \
        make --no-print-directory test;             \
        make --no-print-directory clean;            \
        make --no-print-directory test CXX=clang++
	@echo
	cd projects/collatz;                            \
        make --no-print-directory collatz_tests;    \
        make --no-print-directory html;             \
        make --no-print-directory test;             \
        make --no-print-directory clean;            \
        make --no-print-directory test CXX=clang++; \
        make --no-print-directory check
	@echo
	cd quizzes;                                     \
        make --no-print-directory test;             \
        make --no-print-directory clean;            \
        make --no-print-directory test CXX=clang++

versions:
	uname -a
	@echo
	set
	@echo
	which $(CXX)
	@echo
	$(CXX) -v
	@echo
	$(GTEST)
	@echo
	which $(GCOV)
	@echo
	$(GCOV) -version
	@echo
	$(VALGRIND1)
	@echo
	$(VALGRIND2)
	@echo
	grep "#define BOOST_VERSION " $(BOOST)/version.hpp
	@echo
	which doxygen
	@echo
	doxygen --version
