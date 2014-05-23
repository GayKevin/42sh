/*
** my_errno.c for 42sh in /home/limone_m/rendu/42sh/Builtins
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Mon May 19 14:00:47 2014 Maxime Limone
** Last update Fri May 23 19:44:25 2014 Maxime Limone
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "tree.h"
#include "my_free.h"
#include "main.h"
#include "my_errno.h"

void		tab_function_errno(t_erno *sh)
{
  sh->erno[0] = strdup("Permission Denied");
  sh->erno[1] = strdup("Operation canceled");
  sh->erno[2] = strdup("File exists");
  sh->erno[3] = strdup("File too large");
  sh->erno[4] = strdup("Interrupted function call");
  sh->erno[5] = strdup("Invalid argument");
  sh->erno[6] = strdup("An I/O error occurred");
  sh->erno[7] = strdup("Is a directory");
  sh->erno[8] = strdup("No such file or directory");
  sh->erno[9] = strdup("Exec format error");
  sh->erno[10] = strdup("Not a directory");
  sh->erno[11] = strdup("Directory not empty");
  sh->erno[12] = strdup("Operation not supported");
  sh->erno[13] = strdup("Operation not permitted");
  sh->erno[14] = strdup("Broken pipe");
  sh->erno[15] = strdup("Read-only file system");
  sh->erno[16] = strdup("No such process");
  sh->erno[17] = strdup("Connection timed out");
  sh->erno[18] = NULL;
}

int		*tab_errno(int *tab)
{
  tab[0] = EACCES;
  tab[1] = ECANCELED;
  tab[2] = EEXIST;
  tab[3] = EFBIG;
  tab[4] = EINTR;
  tab[5] = EINVAL;
  tab[6] = EIO;
  tab[7] = EISDIR;
  tab[8] = ENOENT;
  tab[9] = ENOEXEC;
  tab[10] = ENOTDIR;
  tab[11] = ENOTEMPTY;
  tab[12] = ENOTSUP;
  tab[13] = EPERM;
  tab[14] = EPIPE;
  tab[15] = EROFS;
  tab[16] = ESRCH;
  tab[17] = ETIMEDOUT;
  tab[18] = 0;
  return (tab);
}

int		find_errno(t_shell *sh)
{
  t_erno	er;
  int		*tab_tab;
  int		i;

  i = -1;
  if ((tab_tab = malloc(sizeof(int) * 19)) == NULL)
    return (-1);
  if ((er.erno = malloc(sizeof(char *) * 20)) == NULL)
    return (-1);
  memset(er.erno, 0, 20);
  tab_function_errno(&er);
  i = -1;
  tab_tab = tab_errno(tab_tab);
  while (errno != tab_tab[++i] && tab_tab[i] != 0);
  if (tab_tab[i] == 0)
    {
      my_free(er.erno);
      return (-1);
    }
  else
    {
      fprintf(stderr, "Error: %s\n", er.erno[i]);
      my_free(er.erno);
    }
  return (0);
}
