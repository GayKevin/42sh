/*
** parsing_check.c for 42sh in /home/limone_m/rendu/42sh
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Thu May 15 21:42:10 2014 Maxime Limone
** Last update Fri May 23 14:35:05 2014 Maxime Limone
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "tree.h"
#include "epur_str.h"

int		init_op_tab(t_shell *sh)
{
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
  return (0);
}
