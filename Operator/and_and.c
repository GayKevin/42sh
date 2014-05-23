/*
** and_and.c for and_simple in /home/gay_k/42sh
** 
** Made by Kevin Gay
** Login   <gay_k@epitech.net>
** 
** Started on  Tue May 13 22:37:47 2014 Kevin Gay
** Last update Fri May 23 19:39:46 2014 Kevin Gay
*/

#include <string.h>
#include <stdio.h>
#include "main.h"
#include "my_putstr.h"
#include "operator.h"
#include "tree.h"
#include "path.h"
#include "my_free.h"
#include "pars.h"
#include "path.h"
#include "my_free.h"

int	and_and(t_node *tree, t_shell *sh)
{
  if (check_err_op(tree, sh) == -1)
    return (-1);
  gere_operator(tree->left, sh);
  if (sh->ok_cmd == 1)
    {
      my_free(sh->path);
      if (find_path(sh) == -1)
	return (-1);
      gere_operator(tree->right, sh);
    }
  return (0);
}
