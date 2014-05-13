/*
** parsing_tree.c for 42sh in /home/limone_m/rendu/42sh
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Mon May 12 13:55:08 2014 Maxime Limone
** Last update Tue May 13 23:24:16 2014 Maxime Limone
*/

#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "tree.h"
#include "shell.h"
#include "operator.h"

int		clearTree(t_node **tree)
{
  t_node	*tmp;

  tmp = *tree;
  if(!tree)
    return (0);
  if(tmp->left)
    clearTree(&tmp->left);
  if(tmp->right)
    clearTree(&tmp->right);
  free(tmp);
  *tree = NULL;
  return (0);
}

int		stock_tree(char *buff, t_shell *sh)
{
  int		j;
  int		k;

  if (((sh->left = malloc(sizeof(char) * strlen(buff))) == NULL)
      || ((sh->right = malloc(sizeof(char) * strlen(buff))) == NULL))
    return (-1);
  memset(sh->left, 0, strlen(buff));
  memset(sh->right, 0, strlen(buff));
  j = -1;
  k = -1;
  while (++j != sh->op_fnd_i[sh->op_i])
    sh->left[j] = buff[j];
  if (sh->db_op != 0)
    j++;
  while (buff[++j] != '\0')
    sh->right[++k] = buff[j];
  sh->ch = 8;
  return (0);
}

int		gere_operator(t_node *tree, t_shell *sh)
{
  if (tree->chck_tree == 2)
    {
      pipe_simple(tree, sh);
    }
  else
    check_cmd(sh, tree);
  return (0);
}
