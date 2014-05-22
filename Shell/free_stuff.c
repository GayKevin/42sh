/*
** free_stuff.c for free_stuff in /home/gay_k/rendu/42sh
** 
** Made by Kevin Gay
** Login   <gay_k@epitech.net>
** 
** Started on  Thu May 15 15:41:45 2014 Kevin Gay
** Last update Thu May 22 15:57:09 2014 Kevin Gay
*/

#include <stdlib.h>
#include "main.h"
#include "tree.h"

void	free_stuff(t_shell *sh, t_node *tree)
{
  clearTree(&tree);
  if (sh->check == 8)
    {
      free(sh->left);
      free(sh->right);
    }
  free(sh->op_fnd);
  free(sh->op_fnd_i);
  free(sh->op_char);
}
