##
## EPITECH PROJECT, 2021
## bsdefender
## File description:
## Makefile
##

SRC 	=	move_rect.c			\
			my_putchar.c		\
			my_putstr.c			\
			create_clock.c		\
			create_music.c		\
			create_sprite.c		\
			create_buttons.c	\

OBJ		=	$(SRC:.c=.o)

NAME	=	libmy.a

CPPFLAGS += -W -Werror -Wall -Wextra

all:		$(NAME) clean

$(NAME):	$(OBJ)
			ar rc libmy.a $(OBJ)

clean:
			rm -f $(OBJ)

fclean: 	clean
			rm -f $(NAME)

re:			fclean all