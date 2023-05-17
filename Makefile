##
## EPITECH PROJECT, 2023
## Raytracer Project: Makefile file
## File description:
## Makefile
##

CC 			=		g++

CFLAGS 		=		-Wall -Wextra -std=c++17 -g3 -Iinclude

LDFLAGS 	= 		-lconfig++

SRC 		= 		$(wildcard src/*.cpp)

OBJ 		= 		$(SRC:.cpp=.o)

NAME 		= 		raytracer

all: 				$(NAME)

$(NAME): 			$(OBJ)
					$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS)
					rm -f $(OBJ)
					@echo "|| compilation done => ${NAME} ||"

clean:
					rm -f $(OBJ)
					rm -f *~

fclean:				clean
					rm -f $(NAME)

re: 				fclean all

.PHONY: 			all clean fclean re
