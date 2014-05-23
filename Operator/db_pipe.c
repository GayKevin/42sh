/*
** db_pipe.c for db_pipe in /home/gay_k/42sh
** 
** Made by Kevin Gay
** Login   <gay_k@epitech.net>
** 
** Started on  Tue May 13 22:36:10 2014 Kevin Gay
** Last update Thu May 22 14:17:17 2014 Maxime Limone
*/

#include "main.h"
#include "tree.h"
#include "pars.h"
#include "path.h"
#include "my_free.h"

int	db_pipe(t_node *tree, t_shell *sh)
{
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
