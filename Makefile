## Makefile for Makefil in /home/gay_k/rendu/Piscine-C-lib
## 
## Made by Kévin Gay
## Login   <gay_k@epitech.net>
## 
## Started on  Mon Oct 21 09:25:09 2013 Kévin Gay
## Last update Thu Mar 13 22:03:57 2014 Kevin Gay
##

SRC	= Print_error/function_tab.c \
	  Print_error/my_printf.c \
	  Print_error/my_put_error.c \
	  Shell/shell.c \
	  Shell/env.c \
	  Shell/clean_str.c \
	  Shell/path.c \
	  Shell/execve.c\
	  Builtins/find.c \
	  Builtins/built_in.c \
	  Builtins/unsetenv.c \
	  Builtins/setenv.c \
	  SRC/my_strcat.c \
	  SRC/my_free.c \
	  SRC/my_strcpy.c \
	  SRC/str_to_wordtab.c \
	  SRC/my_show_tab.c \
	  SRC/my_put_tool.c \
	  SRC/my_strcmp.c \
	  SRC/main.c \
	  SRC/test.c \

NAME	= 42sh

CC	= cc

OBJ	= $(SRC:.c=.o)

CFLAGS	= -IInclude -Wall -Wextra -g

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CFLAG) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:		clean
	rm -f $(NAME)

re:		fclean all
