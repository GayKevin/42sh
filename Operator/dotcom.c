/*
** dotcom.c for 42sh in /home/limone_m/rendu/42sh
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Wed May 14 14:23:56 2014 Maxime Limone
** Last update Fri May 23 19:39:23 2014 Kevin Gay
*/

#include <stdio.h>
#include "operator.h"
#include "main.h"
#include "tree.h"
#include "pars.h"
#include "my_free.h"
#include "path.h"

int	dotcom(t_node *tree, t_shell *sh)
{
  if (check_err_dotcom(tree, sh) == -1)
    return (-1);
  gere_operator(tree->left, sh);
  my_free(sh->path);
  if (find_path(sh) == -1)
    return (-1);
  gere_operator(tree->right, sh);
  return (0);
}

int		check_err_dotcom(t_node *tree, t_shell *sh)
{
  int		t;

  t = -1;
  if (tree->left->str[0] == '\0')
    {
      fprintf(stderr, "Syntax error: about the symbol ';'\n");
      return (-1);
    }
  while ((tree->right->str[0] != sh->op_char[++t]) && sh->op_char[t] != '\0');
  if (sh->op_char[t] != '\0' && sh->op_char[t] != '<' && sh->op_char[t] != '>')
    {
      fprintf(stderr, "Syntax error: about the symbol '%c'\n", sh->op_char[t]);
      return (-1);
    }
  return (0);
}
