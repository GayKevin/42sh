/*
** ps1.c for ps1 in /home/gay_k/rendu/42sh
** 
** Made by Kevin Gay
** Login   <gay_k@epitech.net>
** 
** Started on  Wed May 14 01:35:25 2014 Kevin Gay
** Last update Thu May 22 20:29:48 2014 Kevin Gay
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

void		get_half_hostname_ps1(t_shell *sh)
{
  char		str[512];
  char		str1[512];
  int		i;

  i = -1;
  gethostname(str, 512);
  while (str[++i] != '.')
    str1[i] = str[i];
  strcat(sh->ps1, str1);
}

/* void	my_putnbr(int nb, t_shell *sh) */
/* { */
/*   int	a; */

/*   a = 0; */
/*   if (nb >= 10) */
/*     my_putnbr(nb / 10, sh); */
/*   if (a == 1) */
/*     { */
/*       a = 0; */
/*       str = (nb % 10 + '1'); */
/*       strcat(sh->ps1, str); */
/*     } */
/*   else */
/*     { */
/*       str = (nb % 10 + '0'); */
/*       strcat(sh->ps1, str); */
/*     } */
/* } */

void		get_full_hostname_ps1(t_shell *sh)
{
  char		str[512];

  gethostname(str, 512);
  strcat(sh->ps1, str);
}


int	get_print_letter(t_shell *sh, int i)
{
  char	str[2];

  str[0] = sh->ps_1[i++];
  str[1] = '\0';
  strcat(sh->ps1, str);
  return (i - 1);
}

/* void	get_nbr(t_shell *sh) */
/* { */
/*   static int i = 0; */

/*   my_putnbr(i, sh); */
/* } */

void	find_ps1_stuff(t_shell *sh)
{
  int	i;
  i = -1;
  while(sh->ps_1[++i] != '\0')
    {
      if ((my_strncmp_nbr(sh->ps_1, "\e", (i + 1), i)) == 0)
	i = ascii_ps1(sh, i);
      else if ((my_strncmp_nbr(sh->ps_1, "\\033", (i + 1), i)) == 0)
	i = ascii_ps1(sh, i);
      else if ((my_strncmp_nbr(sh->ps_1, "\\d" , (i + 1), i)) == 0)
	{
	  date_ps1(sh, i);
	  ++i;
	}
      else if ((my_strncmp_nbr(sh->ps_1, "\\h" , (i + 1), i)) == 0)
	{
	  get_half_hostname_ps1(sh);
	  ++i;
	}
      else if ((my_strncmp_nbr(sh->ps_1, "\\H" , (i + 1), i)) == 0)
	{
	  get_full_hostname_ps1(sh);
	  ++i;
	}
      else if ((my_strncmp_nbr(sh->ps_1, "\\u" , (i + 1), i)) == 0)
	{
	  ++i;
	}
      else if ((my_strncmp_nbr(sh->ps_1, "\\#" , (i + 1), i)) == 0)
	{
	  /* get_nbr(sh); */
	  ++i;
	}
      else if ((my_strncmp_nbr(sh->ps_1, "\\n" , (i + 1), i)) == 0)
	{
	  strcat(sh->ps1, "\n");
	  ++i;
	}
      else if (sh->ps_1[i] != '\\')
	i = get_print_letter(sh, i);
    }
}

int	*find_ps1(t_shell *sh)
{
  int	p;
  int	l;

  l = -1;
  p = -1;
  sh->ps_1 = malloc(sizeof(char) * 1024);
  sh->ps1 = malloc(sizeof(char) * 1024);
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
	find_ps1_stuff(sh);
	/* printf("%s", sh->ps1); */
	return (0);
      }
  if (sh->env[p] == NULL)
    {
      memset(sh->ps_1, 0, 1024);
      sh->ps1[0] = '$';
      sh->ps1[1] = '>';
      sh->ps1[2] = '\0';
    }
  return (0);
}
