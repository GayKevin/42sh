/*
** ps1.c for ps1 in /home/gay_k/rendu/42sh
** 
** Made by Kevin Gay
** Login   <gay_k@epitech.net>
** 
** Started on  Wed May 14 01:35:25 2014 Kevin Gay
** Last update Wed May 14 02:32:55 2014 Kevin Gay
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"
#include "dollar.h"
#include "my_strncpy.h"

int	*find_ps1(t_shell *sh)
{
  int	p;
  int	l;

  l = -1;
  p = -1;
  sh->ps_1 = malloc(sizeof(char) * 1024);
  memset(sh->ps_1, 0, 1024);
  sh->ps_1[0] = 'P';
  sh->ps_1[1] = 'S';
  sh->ps_1[2] = '1';
  while (sh->env[++p] != NULL)
    if ((compare_env_dollar(sh->ps_1, sh, p)) == 0)
      {
	while (sh->env[p][++l] != '=');
	memset(sh->ps_1, 0, 1024);
	my_strncpy(sh->ps_1, sh->env[p], (l + 1));
	return (0);
      }
  if (sh->env[p] == NULL)
    {
      memset(sh->ps_1, 0, 1024);
      sh->ps_1 = "$>";
      /* sh->ps_1[0] = '$'; */
      /* sh->ps_1[1] = '>'; */
    }
}
