/*
** pipe_simple.c for 42sh in /home/limone_m/rendu/42sh/Operator
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Tue May 13 23:59:52 2014 Maxime Limone
** Last update Thu May 22 16:36:54 2014 Maxime Limone
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "main.h"
#include "tree.h"
#include "operator.h"
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

  if (check_err_pipe(tree, sh) == -1)
    return (-1);
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

int		check_err_pipe(t_node *tree, t_shell *sh)
{
  int		t;

  t = -1;
  if (tree->left->str[0] == '\0' || tree->right->str[0] == '\0')
    {
      fprintf(stderr, "Syntax error: about the symbol '|'\n");
      return (-1);
    }
  while ((tree->left->str[0] != sh->op_char[++t]) && sh->op_char[t] != '\0');
  if (sh->op_char[t] != '\0' && sh->op_char[t] != '<' && sh->op_char[t] != '>')
    {
      fprintf(stderr, "Syntax error: about the symbol '%c'\n", sh->op_char[t]);
      return (-1);
    }
  t = -1;
  while ((tree->right->str[0] != sh->op_char[++t]) && sh->op_char[t] != '\0');
  if (sh->op_char[t] != '\0' && sh->op_char[t] != '<' && sh->op_char[t] != '>')
    {
      fprintf(stderr, "Syntax error: about the symbol '%c'\n", sh->op_char[t]);
      return (-1);
    }
  return (0);
}
