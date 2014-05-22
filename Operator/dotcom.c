/*
** dotcom.c for 42sh in /home/limone_m/rendu/42sh
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Wed May 14 14:23:56 2014 Maxime Limone
** Last update Thu May 22 14:16:59 2014 Maxime Limone
*/

#include "main.h"
#include "tree.h"
#include "pars.h"
#include "my_free.h"
#include "path.h"

int	dotcom(t_node *tree, t_shell *sh)
{
  gere_operator(tree->left, sh);
  my_free(sh->path);
  if (find_path(sh) == -1)
    return (-1);
  gere_operator(tree->right, sh);
  return (0);
}
