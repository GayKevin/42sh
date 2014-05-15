/*
** dotcom.c for 42sh in /home/limone_m/rendu/42sh
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Wed May 14 14:23:56 2014 Maxime Limone
** Last update Wed May 14 14:28:08 2014 Maxime Limone
*/

#include "main.h"
#include "tree.h"
#include "pars.h"

int	dotcom(t_node *tree, t_shell *sh)
{
  gere_operator(tree->left, sh);
  gere_operator(tree->right, sh);
  return (0);
}
