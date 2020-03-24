##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC		=	src/main.c		\

NAME	=	lem_in

LIBRARY = 	make -C lib/my

CFLAGS	=	-W -Wall -Wextra -I./include

all:		$(NAME)

$(NAME):
			$(LIBRARY)
			gcc -o $(NAME) $(CFLAGS) $(SRC)  -L ./lib/my/ -lmy -lm
clean:
			$(LIBRARY) clean

fclean:		clean
			rm -f $(NAME)
			$(LIBRARY) fclean

re:			fclean all