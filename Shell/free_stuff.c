/*
** free_stuff.c for free_stuff in /home/gay_k/rendu/42sh
** 
** Made by Kevin Gay
** Login   <gay_k@epitech.net>
** 
** Started on  Thu May 15 13:01:37 2014 Kevin Gay
** Last update Thu May 15 13:26:04 2014 Kevin Gay
*/

#include <stdlib.h>
#include "main.h"
#include "tree.h"

void	free_stuff(t_shell *sh, t_node *tree)
{
  clearTree(&tree);
  if (sh->check_l == 1)
    {
      free(sh->left);
      free(sh->right);
    }
  free(sh->op_char);
  free(sh->op_fnd);
  free(sh->op_fnd_i);
}
