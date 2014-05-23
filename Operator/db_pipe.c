/*
** db_pipe.c for db_pipe in /home/gay_k/42sh
** 
** Made by Kevin Gay
** Login   <gay_k@epitech.net>
** 
** Started on  Tue May 13 22:36:10 2014 Kevin Gay
** Last update Fri May 23 19:39:37 2014 Kevin Gay
*/

#include <string.h>
#include <stdio.h>
#include "main.h"
#include "my_putstr.h"
#include "operator.h"
#include "tree.h"
#include "pars.h"
#include "path.h"
#include "my_free.h"

int	db_pipe(t_node *tree, t_shell *sh)
{
  if (check_err_op(tree, sh) == -1)
    return (-1);
  gere_operator(tree->left, sh);
  if (sh->ok_cmd == -1)
    {
      my_free(sh->path);
      if (find_path(sh) == -1)
	return (-1);
      gere_operator(tree->right, sh);
    }
  return (0);
}

int		check_err_op(t_node *tree, t_shell *sh)
{
  int		t;

  t = -1;
  if (tree->left->str[0] == '\0')
    {
      if (tree->op == '*')
	fprintf(stderr, "Syntax error: about the symbol '||'\n");
      else
	fprintf(stderr, "Syntax error: about the symbol '&&'\n");
      return (-1);
    }
  if (tree->right->str[0] == '\0')
    if (read_cmd_op(tree, sh) == -1)
      return (-1);
  while ((tree->right->str[0] != sh->op_char[++t]) && sh->op_char[t] != '\0');
  if (sh->op_char[t] != '\0' && sh->op_char[t] != '<' && sh->op_char[t] != '>')
    {
      if (tree->op == '*')
	fprintf(stderr, "Syntax error: about the symbol '||'\n");
      else
	fprintf(stderr, "Syntax error: about the symbol '&&'\n");
      return (-1);
    }
  return (0);
}

int		read_cmd_op(t_node *tree, t_shell *sh)
{
  char		buff[512];
  int		ret;

  my_putstr("> ");
  while ((ret = read(0, buff, 512)) == 512);
  if (ret == -1)
    return (-1);
  buff[ret -1] = '\0';
  strcpy(tree->right->str, buff);
  return (0);
}
