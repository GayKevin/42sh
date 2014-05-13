/*
** parsing.c for 42sh in /home/limone_m/rendu/42sh
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Thu May  8 15:12:42 2014 Maxime Limone
** Last update Tue May 13 11:23:56 2014 Kevin Gay
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"
#include "pars.h"
#include "tree.h"
#include "epur_str.h"

int             init_op_tab(char *buff, t_shell *sh)
{
  t_node	*tree;

  if ((sh->op_char = malloc(sizeof(char) * 6)) == NULL)
    return (-1);
  memset(sh->op_char, 0, 6);
  sh->c_ch = 1;
  sh->op_char[0] = '|';
  sh->op_char[1] = '&';
  sh->op_char[2] = '>';
  sh->op_char[3] = '<';
  sh->op_char[4] = ';';
  sh->op_char[5] = '\0';
  sh->op_fnd = NULL;
  sh->op_fnd_i = NULL;
  if ((tree = malloc(sizeof(t_node))) == NULL)
    return (-1);
  memset(tree, 0, sizeof(t_node));
  tree->left = NULL;
  tree->right = NULL;
  if (check_op(buff, sh, tree) == 1)
    return (0);
  display_tree(tree);
  free(tree->left);
  free(tree->right);
  free(tree->str);
  free(tree);
  return (0);
}

int		check_op(char *buff, t_shell *sh, t_node *tree)
{
  int		i;
  char		op_f;

  i = -1;
  sh->r = 0;
  sh->db_op = 0;
  while (buff[++i] != '\0')
    i = check_op_st(buff, i, sh);
  if (sh->r == 0)
    return (1);
  printf("%s\n", sh->op_fnd);
  sh->op_fnd[sh->r] = '\0';
  sh->op_fnd_i[sh->r] = '\0';
  op_f = prio_op(buff, sh);
  stock_tree(buff, sh);
  tree->op = op_f;
  add_node(tree, epur_str(sh->left), epur_str(sh->right));
  printf("left -> %s \t right -> %s\n", tree->left->str, tree->right->str);
  check_op(tree->left->str, sh, tree->left);
  check_op(tree->right->str, sh, tree->right);
  return (0);
}

int		check_op_st(char *buff, int i, t_shell *sh)
{
  int		t;

  t = -1;
  while ((buff[i] != sh->op_char[++t]) && sh->op_char[t] != '\0');
  if (sh->op_char[t] != '\0')
    {
      if ((sh->op_fnd = realloc(sh->op_fnd, sizeof(char) * ++sh->r)) == NULL)
	return (-1);
      if ((sh->op_fnd_i = realloc(sh->op_fnd_i, sizeof(int) * sh->r)) == NULL)
	return (-1);
      if (buff[i + 1] == sh->op_char[t] && t < 4)
	return(change_double_char(sh->op_char[t], i, t, sh));
      else
	{
	  sh->op_fnd[sh->r - 1] = sh->op_char[t];
          sh->op_fnd_i[sh->r - 1] = i;
	}
    }
  return (i);
}

int		change_double_char(char op, int i, int t, t_shell *sh)
{
  if (op == '|')
    sh->op_fnd[sh->r - 1] = '-';
  else
    sh->op_fnd[sh->r - 1] = sh->op_char[t] + 5;
  sh->op_fnd_i[sh->r - 1] = i++;
  return (i++);
}

char		prio_op(char *buff, t_shell *sh)
{
  int		i;
  char		op_f;
  char		brk;

  i = -1;
  sh->op_i = -1;
  brk = 0;
  ++sh->i_tree;
  op_f = '~';
  while (brk == 0 && (sh->op_fnd[++i] != '\0'))
    if (sh->op_fnd[i] == ';')
      {
	op_f = sh->op_fnd[i];
	sh->op_i = i;
	brk = 1;
      }
    else
      if (sh->op_fnd[i] < op_f && sh->op_fnd[i] != '\0')
	{
	  op_f = sh->op_fnd[i];
	  sh->op_i = i;
	}
  if (op_f == '-' || op_f == '+' || op_f == 'A' || op_f == 'C')
    sh->db_op = 2;
  return (op_f);
}
