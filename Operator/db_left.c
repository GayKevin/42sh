/*
** db_left.c for left in /home/gay_k/42sh
** 
** Made by Kevin Gay
** Login   <gay_k@epitech.net>
** 
** Started on  Tue May 13 22:40:16 2014 Kevin Gay
** Last update Tue May 20 10:33:03 2014 Maxime Limone
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
  char		**tab;
  char		buff[512];
  int		ret;
  static int	i = -1;

  tab = NULL;
  my_putstr("> ");
  while ((ret = read(0, buff, 512)) == 512);
  if (ret == -1)
    return (-1);
  buff[ret - 1] = '\0';
  i++;
  if ((tab = realloc(tab, sizeof(buff) * i + 2)) == NULL)
    return (-1);
  tab[i] = buff;
  if (strcmp(tab[i], tree->right->str) == 0)
    db_left_afterpart(tree, sh);
  else
    {
      db_left(tree, sh);
      return (0);
    }
  return (0);
}

int		db_left_afterpart(t_node *tree, t_shell *sh)
{
  pid_t		pid;
  int		pipefd[2];
  int		dp;

  if ((pipe(pipefd)) == -1)
    return (-1);
  if ((pid = fork()) == -1)
    return (-1);
  if (pid == 0)
    {
      if ((dp = dup(0)) == -1)
	return (-1);
      close(pipefd[1]);
      if ((dup2(pipefd[0], 0)) == -1)
	return (-1);
      gere_operator(tree->left, sh);
      if ((dup2(dp, 0)) == -1)
	return (-1);
      exit(0);
    }
  else
    db_left_afterpart_master(pipefd, tree, sh);
  return (0);
}

int		db_left_afterpart_master(int pipefd[2], t_node *tree, t_shell *sh)
{
  int		dp;

  if ((wait(NULL)) == -1)
    exit(1);
  if ((dp = dup(1)) == -1)
    return (-1);
  close(pipefd[0]);
  if ((dup2(pipefd[1], 1)) == -1)
    return (-1);
  gere_operator(tree->right, sh);
  if ((dup2(dp, 1)) == -1)
    return (-1);
  return (0);
}
