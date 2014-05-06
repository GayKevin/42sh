/*
** my_malloc_pwd.c for 42sh in /home/limone_m/rendu/PSU_2013_42sh/SRC
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Mon May  5 17:28:40 2014 Maxime Limone
** Last update Mon May  5 19:36:25 2014 Maxime Limone
*/

#include <string.h>
#include <stdlib.h>
#include "main.h"

int	my_malloc_pwd(t_shell *sh, int d, char *cmd)
{
  sh->l = strlen(sh->env[d]);
  sh->en = malloc(sizeof(char) * (strlen(sh->env[d]) + strlen(cmd) + 2));
  if (sh->en == NULL)
    return (1);
  memset(sh->en, 0, (strlen(sh->env[d]) + strlen(cmd) + 2));
  strcpy(sh->en, sh->env[d]);
  free(sh->env[d]);
  sh->env[d] = malloc(sizeof(char) * (strlen(sh->en)) + 10);
  if (sh->env[d] == NULL)
    return (1);
  memset(sh->env[d], 0, strlen(sh->en) + 10);
  return (0);
}
