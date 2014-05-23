/*
** right_chevron.c for 42sh in /home/limone_m/rendu/42sh/Operator
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Wed May 14 14:24:39 2014 Maxime Limone
** Last update Fri May 23 19:39:11 2014 Kevin Gay
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

char		*stock_name(char *str)
{
  char		*tmp;
  int		i;

  i = -1;
  while (str[++i] != ' ' && str[i] != '\t' && str[i] != '\0');
  if ((tmp = malloc(sizeof(char) * i)) == NULL)
    return (NULL);
  i = -1;
  while (str[++i] != ' ' && str[i] != '\t' && str[i] != '\0')
    tmp[i] = str[i];
  tmp[i] = '\0';
  return (tmp);
}

int		right_chevron(t_node *tree, t_shell *sh)
{
  int		dup_fd[2];
  pid_t		pid;

  if (check_err_chevron(tree, sh) == -1)
    return (-1);
  if ((dup_fd[0] = open(stock_name(epur_str(tree->right->str))
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
