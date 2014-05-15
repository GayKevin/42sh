/*
** and_and.c for and_simple in /home/gay_k/42sh
** 
** Made by Kevin Gay
** Login   <gay_k@epitech.net>
** 
** Started on  Tue May 13 22:37:47 2014 Kevin Gay
** Last update Thu May 15 11:53:27 2014 Maxime Limone
*/

#include "main.h"
#include "tree.h"
#include "pars.h"

int	and_and(t_node *tree, t_shell *sh)
{
  gere_operator(tree->left, sh);
  if (sh->ok_cmd == 1)
    gere_operator(tree->right, sh);
  return (0);
}
