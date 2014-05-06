##
## Makefile for 42sh in /home/limone_m/rendu/PSU_2013_42sh
## 
## Made by Maxime Limone
## Login   <limone_m@epitech.net>
##  		  gere_cmd.c \
		  gere_pipes.c \
		  gere_pipes2.c \

## Started on  Mon May  5 14:54:13 2014 Maxime Limone
## Last update Tue May  6 15:25:09 2014 Kevin Gay
##

SRC		= Print_error/function_tab.c \
		  Print_error/my_printf_error.c \
		  Print_error/my_put_error.c \
		  Shell/shell.c \
		  Shell/env.c \
		  Shell/clean_str.c \
		  Shell/path.c \
		  Shell/execve.c\
		  Builtins/find.c \
		  Builtins/cd.c \
		  Builtins/built_in.c \
		  Builtins/unsetenv.c \
		  Builtins/setenv.c \
		  Builtins/pwd.c \
		  Builtins/old_pwd.c \
		  SRC/my_strcat.c \
		  SRC/my_free.c \
		  SRC/str_to_wordtab.c \
		  SRC/my_malloc_pwd.c \
		  SRC/my_show_tab.c \
		  SRC/main.c

NAME		= 42sh

CC		= cc

OBJ		= $(SRC:.c=.o)

CFLAGS		= -IInclude -Wall -g

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(CFLAG) -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
