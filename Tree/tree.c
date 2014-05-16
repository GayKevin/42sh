/*
** tree.c for 42sh in /home/limone_m/rendu/42sh/Tree
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Wed May  7 13:22:59 2014 Maxime Limone
** Last update Fri May 16 14:29:28 2014 Maxime Limone
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tree.h"

int		add_node(t_node *node, char *str_lf, char *str_rg)
{
  if ((node->left = malloc(sizeof(t_node))) == NULL)
    return (-1);
  memset(node->left, 0, sizeof(t_node));
  node->left->str = str_lf;
  node->left->left = NULL;
  node->left->right = NULL;
  if ((node->right = malloc(sizeof(t_node))) == NULL)
    return (-1);
  memset(node->right, 0, sizeof(t_node));
  node->right->str = str_rg;
  node->right->left = NULL;
  node->right->right = NULL;
  return (0);
}

void		display_tree(t_node *root)
{
  static int	i = -1;

  i = -1;
  if (root != NULL)
    {
      printf("%d\t ## String ==> %s \t## Op ==> %c\n"
      	     , ++i, root->str, root->op);
      display_tree(root->left);
      display_tree(root->right);
    }
}
