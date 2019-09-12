#include "../includes/filler.h"

int get_map_size(t_arg_filler *arg, char *line)
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
    if (arg->map_size_x == 0 && tmp != 0)
    {
      arg->map_size_x = tmp / 10;
      tmp = 0;
    }
    if (arg->map_size_y == 0 && tmp != 0)
    {
      arg->map_size_y = tmp / 10;
      tmp = 0;
    }
    tmp = 0;
    i++;
  }
  if (!(arg->map = (char **)ft_memalloc(sizeof(char *) * (arg->map_size_x + 1))))
      return (-1);
  return (0);
}

int get_map(t_arg_filler *arg, char *line, int i)
{
  if (!(arg->map[i] = ft_strsub(line, 4, arg->map_size_y)))
    return (-1);
  return (0);
}

int get_map_prout(t_arg_filler *arg, char *line, int i)
{
  if (ft_strstr(line, "Piece"))
  {
    arg->flag = 0;
    return (0);
  }
  if (arg->flag != 1)
  {
    if (get_map_size(arg, line) == -1)
		return (-1);
    arg->flag = 1;
  }
  else
  {
    if (ft_strstr(line, "   012"))
      return (i);
    if (get_map(arg, line, i) == -1)
		return (-1);
    i++;
  }
  return (i);
}
