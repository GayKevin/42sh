/*
** right_chevron.c for right_chevron in /home/gay_k/42sh
** 
** Made by Kevin Gay
** Login   <gay_k@epitech.net>
** 
** Started on  Tue May 13 22:38:59 2014 Kevin Gay
** Last update Wed May 14 02:13:44 2014 Maxime Limone
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "main.h"
#include "tree.h"
#include "pars.h"
#include "epur_str.h"

int		right_chevron(t_node *tree, t_shell *sh)
{
  int		dup_fd[2];
  pid_t		pid;

  if ((dup_fd[0] = open(epur_str(tree->right->str)
		    , O_TRUNC | O_RDWR | O_CREAT, 0644)) == -1)
    return (-1);
  if ((pid = fork()) == -1)
    return (-1);
  if (pid == 0)
    {
      if ((dup_fd[1] = dup(1)) == -1)
	return (-1);
      if ((dup2(dup_fd[0], 1)) == -1)
	return (-1);
      gere_operator(tree->left, sh);
      exit(1);
    }
  else
    {
      if ((wait(NULL)) == -1)
	exit(0);
      if ((dup2(dup_fd[1], 1)) == -1)
	return (-1);
    }
  return (0);
}
