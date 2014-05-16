/*
** free_stuff.c for free_stuff in /home/gay_k/rendu/42sh
** 
** Made by Kevin Gay
** Login   <gay_k@epitech.net>
** 
** Started on  Thu May 15 15:41:45 2014 Kevin Gay
** Last update Thu May 15 16:17:06 2014 Kevin Gay
*/

#include "main.h"
#include "tree.h"

void	free_stuff(t_shell *sh, t_node *tree)
{
  printf("%d\n", sh->check);
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
