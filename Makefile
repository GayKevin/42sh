SRC	= Print_error/function_tab.c \
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
	  SRC/my_getnbr.c \
	  SRC/my_free.c \
	  SRC/my_strcpy.c \
	  SRC/str_to_wordtab.c \
	  SRC/my_malloc_pwd.c \
	  SRC/my_show_tab.c \
	  SRC/my_put_tool.c \
	  SRC/my_strcmp.c \
	  SRC/main.c

NAME	= 42sh

CC	= cc

OBJ	= $(SRC:.c=.o)

CFLAGS	= -IInclude -Wall -g

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CFLAG) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:		clean
	rm -f $(NAME)

re:		fclean all
