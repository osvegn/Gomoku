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

re: fclean all