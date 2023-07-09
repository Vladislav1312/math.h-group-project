CLANG_FORMAT = clang-format -i *.c *.h
FLAGS = -Wall -Wextra -Werror -Wuninitialized -std=c11
TESTFLAGS = -lcheck --coverage
SOURCES_FUN:=$(shell find . -not -name "s21_check.c" -name "*.c")

ifeq ($(shell uname), Linux)
TESTFLAGS += -lm -lsubunit
else
TESTFLAGS += -fprofile-arcs -ftest-coverage
endif

all: s21_math.a test gcov_report
	@$(CLANG_FORMAT)
	rm -rf *.o testing.c testing *.a *.gcno *.gcda *.gcov *.info

s21_math.a:
	gcc $(FLAGS) -c $(SOURCES_FUN)
	ar rcs s21_math.a *.o
	@ranlib s21_math.a

test: s21_math.a
	@gcc s21_check.c s21_math.a $(TESTFLAGS) -o testing 
	./testing

gcov_report:
	@gcc $(TESTFLAGS) *.c -o s21_lib_test $(TESTFLAGS)
	./s21_lib_test
	@gcov -f $(SOURCES_FUN)
	@lcov --no-external -t test -o coverage.info -c -d . 
	@genhtml -o html_report coverage.info
	@open html_report/index.html

clean:
	@rm -rf *.o testing.c testing *.a *.gcno *.gcda *.gcov *.info
	@rm -rf html_report s21_math s21_lib_test
