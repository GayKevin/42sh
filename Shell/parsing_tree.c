/*
** parsing_tree.c for 42sh in /home/limone_m/rendu/42sh
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Mon May 12 13:55:08 2014 Maxime Limone
** Last update Mon May 12 21:52:37 2014 Maxime Limone
*/

#include <stdlib.h>
#include <string.h>
#include "main.h"

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
  return (0);
}
