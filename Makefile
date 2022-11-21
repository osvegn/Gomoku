##
## EPITECH PROJECT, 2022
## gomoku
## File description:
## Makefile
##

NAME	=	pbrain-gomoku-ai

RM		=	rm -rf

BUILD	=	./build

${NAME}: all

all:
	mkdir -p build
	cd build && cmake .. && cmake --build .

clean:
	${RM} ${BUILD}

fclean: clean
	${RM} ${NAME}
	${RM} ${NAME}_tests

re: fclean all

debug: fclean
	mkdir -p build
	cd build && cmake .. -DCMAKE_BUILD_TYPE=Debug && cmake --build .

unit_test: fclean
	mkdir -p build
	cd build && cmake cmake .. -DTESTING=On && cmake --build .

run_tests: unit_test
	cd build && ctest --output-on-failure
#	./${NAME}_tests