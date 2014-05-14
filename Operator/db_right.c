/*
** db_right.c for db_right in /home/gay_k/42sh
** 
** Made by Kevin Gay
** Login   <gay_k@epitech.net>
** 
** Started on  Tue May 13 22:39:53 2014 Kevin Gay
** Last update Wed May 14 13:50:11 2014 Maxime Limone
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

int		db_right(t_node *tree, t_shell *sh)
{
  int		dup_fd[2];
  pid_t		pid;

  if ((dup_fd[0] = open(stock_name(epur_str(tree->right->str)),
			O_APPEND | O_RDWR | O_CREAT, 0644)) == -1)
    return (-1);
  if ((pid = fork()) == -1)
    return (-1);
  if (pid == 0)
    {
      if ((dup_fd[1] = dup(1)) == -1)
	return (-1);
      if ((dup2(dup_fd[1], 1)) == -1)
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
