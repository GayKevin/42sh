/*
** tree.c for 42sh in /home/limone_m/rendu/42sh/Tree
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Wed May  7 13:22:59 2014 Maxime Limone
** Last update Mon May 12 20:10:54 2014 Maxime Limone
*/

#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

t_node		*create_r(char op_r)
{
  t_node	*root;

  if ((root = malloc(sizeof(t_node))) == NULL)
    return (NULL);
  root->op = op_r;
  root->str = NULL;
  root->left = NULL;
  root->right = NULL;
  return (root);
}

int		add_node(t_node *node, char *str_lf, char *str_rg)
{
  if ((node->left = malloc(sizeof(t_node))) == NULL)
    return (-1);

  node->left->str = str_lf;
  node->left->left = NULL;
  node->left->right = NULL;
  if ((node->right = malloc(sizeof(t_node))) == NULL)
    return (-1);
  node->right->str = str_rg;
  node->right->left = NULL;
  node->right->right = NULL;
  return (0);
}

void		display_tree(t_node *root)
{
  static int	i = -1;

  if (root != NULL)
    {
      printf("%d\t ## String ==> %s \t## Op ==> %c\n"
	     , ++i, root->str, root->op);
      display_tree(root->left);
      display_tree(root->right);
    }
}
