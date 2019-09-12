#include "../includes/filler.h"

int get_piece(t_arg_filler *arg, char *line, int i)
{
    if (!(arg->piece[i] = ft_strdup(line)))
      return (-1);
    return (0);
}

int get_piece_size(t_arg_filler *arg, char *line)
{
  int i;
  int tmp;

  i = 0;
  tmp = 0;
  while (line[i])
  {
    while (line[i] && ft_isdigit(line[i]))
    {
      tmp += line[i] - 48;
      tmp *= 10;
      i++;
    }
    if (arg->piece_size_x == 0 && tmp != 0)
    {
      arg->piece_size_x = tmp / 10;
      tmp = 0;
    }
    if (arg->piece_size_y == 0 && tmp != 0)
    {
      arg->piece_size_y = tmp / 10;
      tmp = 0;
    }
    tmp = 0;
    i++;
  }
  if (!(arg->piece = (char **)ft_memalloc(sizeof(char *) * (arg->piece_size_x + 1))))
      return (-1);
  return (0);
}

int get_piece_prout(t_arg_filler *arg, char *line, int i)
{
  if (arg->flag != 2)
  {
    if (get_piece_size(arg, line) == -1)
		return (-1);
    arg->flag = 2;
  }
  else
  {
    if (get_piece(arg, line, i) == -1)
		return (-1);
    i++;
  }
  return (i);
}
