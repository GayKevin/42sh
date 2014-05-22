/*
** left_chevron.c for left_chevron in /home/gay_k/42sh
** 
** Made by Kevin Gay
** Login   <gay_k@epitech.net>
** 
** Started on  Tue May 13 22:38:27 2014 Kevin Gay
** Last update Thu May 22 10:20:51 2014 Maxime Limone
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "main.h"
#include "operator.h"
#include "tree.h"
#include "pars.h"
#include "epur_str.h"

int		left_chevron(t_node *tree, t_shell *sh)
{
  int		dup_fd[2];
  pid_t		pid;

  if ((dup_fd[0] = open(tree->right->str, O_RDONLY)) == -1)
    return (-1);
  if ((pid = fork()) == -1)
    return (-1);
  if (pid == 0)
    {
      if ((dup_fd[1] = dup(0)) == -1)
	return (-1);
      if ((dup2(dup_fd[0], 0)) == -1)
	return (-1);
      gere_operator(tree->left, sh);
      exit(1);
    }
  else
    left_chevron_afterpart(dup_fd, tree, sh);
  return (0);
}

int		left_chevron_afterpart(int dup_fd[2], t_node *tree, t_shell *sh)
{
  if ((wait(NULL)) == -1)
    exit(0);
  if ((dup2(dup_fd[1], 0)) == -1)
    return (0);
  return (0);
}
