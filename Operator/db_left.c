/*
** db_left.c for 42sh in /home/limone_m/rendu/42sh
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Tue May 20 10:51:02 2014 Maxime Limone
** Last update Wed May 21 17:54:47 2014 Maxime Limone
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "main.h"
#include "operator.h"
#include "pars.h"
#include "my_putstr.h"
#include "tree.h"

int		db_left(t_node *tree, t_shell *sh)
{
  char		*buff_w;
  int		pipefd[2];
  int		dp;

  if ((buff_w = malloc(sizeof(char) * 1)) == NULL)
    return (-1);
  db_left_afterpart(buff_w, tree, sh);
  if ((pipe(pipefd)) == -1)
    return (-1);
  write(pipefd[1], buff_w, strlen(buff_w));
  if ((dp = dup(0)) == -1)
    return (-1);
  if ((dup2(pipefd[0], 0)) == -1)
    return (-1);
  gere_operator(tree->left, sh);
  close(pipefd[1]);
  free(buff_w);
  return (0);
}

int		db_left_afterpart(char *buff_w, t_node *tree, t_shell *sh)
{
  char		buff[512];
  int		ret;
  static int	size;
  static int	i = -1;
  int		b;

  b = -1;
  my_putstr("> ");
  while ((ret = read(0, buff, 512)) == 512);
  if (ret == -1)
    return (-1);
  buff[ret - 1] = '\0';
  size += strlen(buff);
  if (strcmp(buff, tree->right->str) == 0)
    {
      buff_w[i] = '\0';
      return (0);
    }
  if ((buff_w = realloc(buff_w, sizeof(buff) * size + 1)) == NULL)
    return (-1);
  while (buff[++b] != '\0')
    buff_w[++i] = buff[b];
  buff_w[++i] = '\n';
  db_left_afterpart(buff_w, tree, sh);
  return (0);
}
