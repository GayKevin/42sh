/*
** errno_cd.c for pointer errno in /home/gay_k/rendu/42sh
** 
** Made by Kevin Gay
** Login   <gay_k@epitech.net>
** 
** Started on  Fri May 16 17:10:01 2014 Kevin Gay
** Last update Mon May 19 11:22:40 2014 Kevin Gay
*/

void	tab_function_errno(int (*tab_fun[18])(t_node *tree, t_shell *sh))
{
  tab_fun[0] = "Permission Denied";
  tab_fun[1] = "Operation canceled";
  tab_fun[2] = "File existS";
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
}

int		*tab_errno(char *tab)
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
  tab[17] = ETIMEOUT;
  return (tab);
}

void		find_errno(t_shell *sh)
{
  void		(*tab_fun[18])(t_node *tree, t_shell *sh);
  int		*tab_tab[18];

  if ((tab_tab = malloc(sizeof(char) * 9)) == NULL)
    return (-1);
  tab_tab = tab_errno(tab_tab);
  tab_function_errno(tab_fun);
}
