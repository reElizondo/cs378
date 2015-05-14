FILES :=                              \
    .gitignore                        \
    .travis.yml                       \
    collatz-tests/EID-RunCollatz.in   \
    collatz-tests/EID-RunCollatz.out  \
    collatz-tests/EID-TestCollatz.c++ \
    collatz-tests/EID-TestCollatz.out \
    Collatz.c++                       \
    Collatz.h                         \
    Collatz.log                       \
    html                              \
    RunCollatz.c++                    \
    RunCollatz.in                     \
    RunCollatz.out                    \
    TestCollatz.c++                   \
    TestCollatz.out

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

all: RunCollatz TestCollatz

collatz-tests:
	git clone https://github.com/cs378-summer-2015/collatz-tests.git

html: Doxyfile Collatz.h Collatz.c++ RunCollatz.c++ TestCollatz.c++
	doxygen Doxyfile

check:
	@for i in $(FILES);                                         \
	do                                                          \
		[ -e $$i ] && echo "$$i found" || echo "$$i NOT FOUND"; \
	done

clean:
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.gcov
	rm -f RunCollatz
	rm -f RunCollatz.out
	rm -f TestCollatz
	rm -f TestCollatz.out

test: RunCollatz.out TestCollatz.out

Collatz.log:
	git log > Collatz.log

Doxyfile:
	doxygen -g

RunCollatz: Collatz.h Collatz.c++ RunCollatz.c++
	@echo
	$(CXX) $(CXXFLAGS) Collatz.c++ RunCollatz.c++ -o RunCollatz

RunCollatz.out: RunCollatz
	./RunCollatz < RunCollatz.in > RunCollatz.out

TestCollatz: Collatz.h Collatz.c++ TestCollatz.c++
	@echo
	$(CXX) $(COVFLAGS) $(CXXFLAGS) Collatz.c++ TestCollatz.c++ -o TestCollatz $(LDFLAGS)

TestCollatz.out: TestCollatz
	valgrind ./TestCollatz      >  TestCollatz.out 2>&1
	$(GCOV) -b TestCollatz.c++ >> TestCollatz.out
