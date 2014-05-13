/*
** pipe.c for 42sh in /home/limone_m/rendu/42sh/Operator
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Tue May 13 14:43:24 2014 Maxime Limone
** Last update Tue May 13 21:52:43 2014 Maxime Limone
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "main.h"
#include "tree.h"
#include "pars.h"

int		master_pipe(int pipefd[2], t_node *tree, t_shell *sh)
{
  int		dp;

  if ((wait(NULL)) == -1)
    exit(0);
  if ((dp = dup(0)) == -1)
    return (-1);
  close(pipefd[1]);
  if ((dup2(pipefd[0], 0)) == -1)
    return (-1);
  gere_operator(tree->right, sh);
  if ((dup2(dp, 0)) == -1)
    return (-1);
  return (0);
}

int		pipe_simple(t_node *tree, t_shell *sh)
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
      if ((dp = dup(1)) == -1)
	return (-1);
      close(pipefd[0]);
      if ((dup2(pipefd[1], 1)) == -1)
	return (-1);
      gere_operator(tree->left, sh);
      if ((dup2(dp, 1)) == -1)
	return (-1);
      exit(1);
    }
  else
    master_pipe(pipefd, tree, sh);
  return (0);
}
