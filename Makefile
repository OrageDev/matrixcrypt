##
## EPITECH PROJECT, 2018
## makefile
## File description
## makefile
##

CFLAGS		+=	-W -Wall -Wextra -g -I include

LDFLAGS 	= 	-lm

DIR		=	./src

SRC		=	src/main.c
EXEC		=	cipher

OBJ		=	$(SRC:.c=.o)

all:			$(EXEC)

$(EXEC):		$(OBJ)
			$(CC) -o $(EXEC) $(OBJ) $(LDFLAGS) $(CFLAGS) 

clean:
			rm -f $(OBJ)

fclean:clean
			rm -f $(EXEC)

re:			fclean all

