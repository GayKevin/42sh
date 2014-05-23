/*
** ps1.c for ps1 in /home/gay_k/rendu/42sh
** 
** Made by Kevin Gay
** Login   <gay_k@epitech.net>
** 
** Started on  Wed May 14 01:35:25 2014 Kevin Gay
** Last update Fri May 23 19:47:24 2014 Maxime Limone
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"
#include "dollar.h"
#include "my_strncpy.h"
#include "my_strcmp.h"
#include "date.h"
#include "ascii.h"
#include "get_stuff.h"


void		tab_ps1(t_shell *sh)
{
  sh->tab_ps1[0] = "\\e";
  sh->tab_ps1[1] = "\\033";
  sh->tab_ps1[2] = "\\d";
  sh->tab_ps1[3] = "\\H";
  sh->tab_ps1[4] = "\\h";
  sh->tab_ps1[5] = "\\#";
  sh->tab_ps1[6] = "\\u";
  sh->tab_ps1[7] = "\\n";
  sh->tab_ps1[8] = "111";
}
void	tab_function_ps1(int (*tab_func[10])(t_shell *sh, int i))
{
  tab_func[0] = ascii_ps1;
  tab_func[1] = ascii_ps1;
  tab_func[2] = date_ps1;
  tab_func[3] = get_full_hostname_ps1;
  tab_func[4] = get_half_hostname_ps1;
  tab_func[5] = get_nbr;
  tab_func[6] = get_username_ps1;
  tab_func[7] = get_username_ps1;
  tab_func[8] = get_print_letter;
}

int	find_ps1_stuff(t_shell *sh)
{
  int	i;
  int	o;
  int	(*tab_func[10])(t_shell *sh, int i);

  tab_ps1(sh);
  tab_function_ps1(tab_func);
  i = -1;
  while (sh->ps_1[++i] != '\0')
    {
      o = -1;
      while (++o != 10)
	{
	  if ((my_strncmp_nbr(sh->ps_1, sh->tab_ps1[o], (i + 1), i)) == 0)
	    i = tab_func[o](sh, i);
	  else if (o == 8)
	    i = tab_func[8](sh, i);
	}
    }
  return (0);
}


void	env_null(t_shell *sh, int p)
{
  if (sh->env[p] == NULL)
    {
      memset(sh->ps_1, 0, 1024);
      sh->ps1[0] = '$';
      sh->ps1[1] = '>';
      sh->ps1[2] = '\0';
    }
}

int	find_ps1(t_shell *sh)
{
  int	p;
  int	l;

  l = -1;
  p = -1;
  sh->ps_1 = malloc(sizeof(char) * 1024);
  sh->ps1 = malloc(sizeof(char) * 1025);
  memset(sh->ps_1, 0, 1024);
  memset(sh->ps1, 0, 1024);
  sh->ps_1[0] = 'P';
  sh->ps_1[1] = 'S';
  sh->ps_1[2] = '1';
  while (sh->env[++p] != NULL)
    if ((compare_env_dollar(sh->ps_1, sh, p)) == 0)
      {
	while (sh->env[p][++l] != '=');
	memset(sh->ps_1, 0, 1024);
	my_strncpy(sh->ps_1, sh->env[p], (l + 1));
	find_ps1_stuff(sh);
	return (0);
      }
  env_null(sh, p);
  return (0);
}
