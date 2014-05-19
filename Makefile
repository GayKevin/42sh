##
## Makefile for 42sh in /home/limone_m/rendu/PSU_2013_42sh
## 
## Made by Maxime Limone
## Login   <limone_m@epitech.net>
## Started on  Mon May  5 14:54:13 2014 Maxime Limone
## Last update Fri May 16 14:01:41 2014 Kevin Gay
##

SRC		= Print_error/function_tab.c \
		  Print_error/my_printf_error.c \
		  Print_error/my_put_error.c \
		  Operator/pipe_simple.c \
		  Operator/dotcom.c \
		  Operator/db_pipe.c \
		  Operator/and_simple.c \
		  Operator/and_and.c \
		  Operator/left_chevron.c \
	    	  Operator/right_chevron.c \
		  Operator/db_left.c \
		  Operator/db_right.c \
		  Shell/free_stuff.c \
		  Shell/shell.c \
		  Shell/ps1.c \
		  Shell/env.c \
		  Shell/clean_str.c \
		  Shell/path.c \
		  Shell/dollar.c \
		  Shell/parsing.c \
		  Shell/parsing_tree.c \
		  Shell/parsing_check.c \
		  Shell/execve.c\
		  Builtins/find.c \
		  Builtins/cd.c \
		  Builtins/built_in.c \
		  Builtins/unsetenv.c \
		  Builtins/setenv.c \
		  Builtins/pwd.c \
		  Builtins/old_pwd.c \
		  Tree/tree.c \
		  SRC/epur_str.c \
	 	  SRC/my_putstr.c \
		  SRC/my_strcat.c \
		  SRC/my_strncpy.c \
		  SRC/my_free.c \
		  SRC/str_to_wordtab.c \
		  SRC/my_malloc_pwd.c \
		  SRC/my_show_tab.c \
		  SRC/main.c
#	  	  move.c \
#	 	  termcaps.c

NAME		= 42sh

CC		= cc

OBJ		= $(SRC:.c=.o)

CFLAGS		= -g -IInclude -Wall

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -lncurses

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
