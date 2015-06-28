clean:
	cd examples; make --no-print-directory clean
	@echo
	cd exercises; make --no-print-directory clean
	@echo
	cd quizzes; make --no-print-directory clean
	@echo
	cd collatz; make --no-print-directory clean
	@echo
	cd integer; make --no-print-directory clean

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
    --include "Exceptions.c++"              \
    --include "Exceptions2.c++"             \
    --include "Exceptions3.c++"             \
    --include "Types.c++"                   \
    --include "Operators.c++"               \
    --include "StackVsHeap.c++"             \
    --include "Selection.c++"               \
    --include "Iteration.c++"               \
    --include "Variables.c++"               \
    --include "Lambdas.c++"                 \
    --include "Iterators.c++"               \
    --include "Consts.c++"                  \
    --exclude "*"                           \
    ../../../examples/c++/ examples
	@rsync -r -t -u -v --delete             \
    --include "IsPrime1.h"                  \
    --include "IsPrime1.c++"                \
    --include "IsPrime2.h"                  \
    --include "IsPrime2.c++"                \
    --include "StrCmp.h"                    \
    --include "StrCmp.c++"                  \
    --include "Factorial.h"                 \
    --include "Factorial.c++"               \
    --include "Equal.h"                     \
    --include "Equal.c++"                   \
    --include "Fill.h"                      \
    --include "Fill.c++"                    \
    --include "Copy.h"                      \
    --include "Copy.c++"                    \
    --exclude "*"                           \
    ../../../exercises/c++/ exercises
	@rsync -r -t -u -v --delete             \
    --include "Quiz3.c++"                   \
    --include "Quiz5.c++"                   \
    --include "Quiz6.c++"                   \
    --include "Quiz7.c++"                   \
    --include "Quiz8.c++"                   \
    --include "Quiz9.c++"                   \
    --exclude "*"                           \
    ../../quizzes/ quizzes
	@rsync -r -t -u -v --delete             \
    --include "Collatz.c++"                 \
    --include "Collatz.h"                   \
    --include "gitignore.sample"            \
    --include "makefile.sample"             \
    --include "RunCollatz.c++"              \
    --include "RunCollatz.in"               \
    --include "RunCollatz.sample.out"       \
    --include "TestCollatz.c++"             \
    --include "TestCollatz.sample.out"      \
    --exclude "*"                           \
    ../../../projects/c++/collatz/ collatz
	@rsync -r -t -u -v --delete             \
    --include "Integer.h"                   \
    --include "RunInteger.c++"              \
    --exclude "*"                           \
    ../../../projects/c++/integer/ integer

push:
	make clean
	@echo
	git add .travis.yml
	git add examples
	git add exercises
	git add makefile
	git add quizzes
	git add collatz
	git add integer
	git commit -m "another commit"
	git push
	git status

status:
	make clean
	@echo
	git add examples
	git add exercises
	git add quizzes
	git add collatz
	git add integer
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
	cd quizzes; make sync
	@echo
	cd collatz; make sync
	@echo
	cd integer; make sync

test:
	cd examples; make --no-print-directory test
	@echo
	cd exercises; make --no-print-directory test
	@echo
	cd quizzes; make --no-print-directory test
	@echo
	cd collatz; make --no-print-directory test
	@echo
	cd integer; make --no-print-directory test

versions:
	cd examples; make --no-print-directory versions
	@echo
	cd exercises; make --no-print-directory versions
	@echo
	cd quizzes; make --no-print-directory versions
	@echo
	cd collatz; make --no-print-directory versions
	@echo
	cd integer; make --no-print-directory versions
