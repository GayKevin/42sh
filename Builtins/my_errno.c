/*
** my_errno.c for 42sh in /home/limone_m/rendu/42sh/Builtins
** 
** Made by Maxime Limone
** Login   <limone_m@epitech.net>
** 
** Started on  Mon May 19 14:00:47 2014 Maxime Limone
** Last update Mon May 19 14:20:03 2014 Maxime Limone
*/

#include <stdlib.h>
#include <errno.h>
#include "tree.h"
#include "my_printf_error.h"
#include "main.h"

char	**tab_function_errno(char *tab_fun[19])
{
  tab_fun[0] = "Permission Denied";
  tab_fun[1] = "Operation canceled";
  tab_fun[2] = "File exists";
  tab_fun[3] = "File too large";
  tab_fun[4] = "Interrupted function call";
  tab_fun[5] = "Invalid argument";
  tab_fun[6] = "An I/O error occurred";
  tab_fun[7] = "Is a directory";
  tab_fun[8] = "No such file or directory";
  tab_fun[9] = "Exec format error";
  tab_fun[10] = "Not a directory";
  tab_fun[11] = "Directory not empty";
  tab_fun[12] = "Operation not supported";
  tab_fun[13] = "Operation not permitted";
  tab_fun[14] = "Broken pipe";
  tab_fun[15] = "Read-only file system";
  tab_fun[16] = "No such process";
  tab_fun[17] = "Connection timed out";
  tab_fun[18] = NULL;
  return (tab_fun);
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
  char		**tab_fun;
  int		*tab_tab;
  int		i;

  i = -1;
  if ((tab_tab = malloc(sizeof(int) * 19)) == NULL)
    return (-1);
  if ((tab_fun = malloc(sizeof(char) * 19)) == NULL)
    return (-1);
  tab_tab = tab_errno(tab_tab);
  tab_fun = tab_function_errno(tab_fun);
  while (errno != tab_tab[++i] && tab_tab[i] != 0);
  if (tab_tab[i] == 0)
    return (-1);
  else
    printf_err("%s\n", tab_fun[i]);
  return (0);
}
