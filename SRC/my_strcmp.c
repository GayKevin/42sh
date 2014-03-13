/*
** my_strcmp.c for strcmp in /home/gay_k/rendu/PSU/PSU_2013_minishell1
** 
** Made by Kevin Gay
** Login   <gay_k@epitech.net>
** 
** Started on  Wed Feb 26 13:33:18 2014 Kevin Gay
** Last update Wed Mar 12 23:48:06 2014 Kevin Gay
*/

#include "struct.h"

int	my_strcmp(char *str1, char *str2)
{
  int	i;

  i = 0;
  while (str1[i] == str2[i] && str2[i + 1] != '\0')
      i++;
  if (str1[i] != str2[i])
    return (1);
  return (0);
}

int	my_strcmp_(char *str1, char *str2)
{
  int	i;

  i = 0;
  while (str1[i] == str2[i] && str2[i + 1] != '=')
    i++;
  if (str1[i] == '=' && str2[i] == '=')
    return (0);
  if (str1[i] != str2[i])
    return (1);
  return (0);
}
