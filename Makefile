CC=g++
CFLAGS=-Wall -Werror -Wextra -std=c++17
COV=--coverage
GTESTF=-lgtest -pthread
SRC=s21_*.cc
OBJ=s21_*.o

LIB=s21_matrix_oop.a

TEST_SRC=unit_test/*.cc
TEST_EXEC=matrix_test
all: test

s21_matrix_oop.a: ${SRC}
	${CC} -c ${CFLAGS} ${SRC}
	ar rcs ${LIB} ${OBJ}

test: clean ${LIB}
	${CC} -g ${CFLAGS} ${COV} ${SRC} ${TEST_SRC} -o ${TEST_EXEC} ${GTESTF}
	./${TEST_EXEC}

gcov_report: clean test
	rm -f *_test.gcda *_test.gcno
	lcov -t "matrix_test" -o matrix_test.info -c -d .
	genhtml -o report matrix_test.info
	open report/index.html

clean:
	@rm -f *.out *.o *.a *.gch
	@rm -f *.gcno *.gcda *.gcov *.info
	@rm -f ${TEST_EXEC}
	@rm -rf report
	@rm -rf *.dSYM

valgrind: test
	CK_FORK=no valgrind --vgdb=no --leak-check=full --show-reachable=yes --show-leak-kinds=all --track-origins=yes --verbose ./${TEST_EXEC}

leaks: test
	leaks -atExit -- ./${TEST_EXEC}

style:
	clang-format -style=Google -n *.cc *.h */*.cc */*.h
