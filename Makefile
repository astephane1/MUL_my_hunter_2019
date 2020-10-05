##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## make
##

SRC	=	*.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_hunter


all:	$(NAME)

$(NAME):	 $(OBJ)
	gcc -o $(NAME) $(SRC)  -lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system


clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
