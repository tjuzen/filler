#include "../includes/filler.h"

void init_arg(t_arg_filler *arg)
{
  arg->player = 0;
  arg->map_size_x = 0;
  arg->map_size_y = 0;
}

int get_players(t_arg_filler *arg)
{
  char *line;

  get_next_line(0, &line);
  if (ft_strstr(line, "p1"))
    arg->player = 1;
  else if (ft_strstr(line, "p2"))
    arg->player = 2;
  ft_strdel(&line);
  return (0);
}

int get_piece(char *line, t_arg_filler *arg)
{
  return (0);
}

int get_map_size(t_arg_filler *arg)
{
  char *line;
  int i;
  int tmp;

  i = 0;
  tmp = 0;
  get_next_line(0, &line);
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
  ft_strdel(&line);
  return (0);
}

int get_map(char *line, t_arg_filler *arg)
{
  return (0);
}

int get_input(t_arg_filler *arg)
{
  char *line;

  while (get_next_line(0, &line) > 0)
  {
    if (ft_strstr(line, "Plateau"))
      get_map(line, arg);
    else if (ft_strstr(line, "Piece"))
      get_piece(line, arg);
    ft_strdel(&line);
  }
  return (0);
}

int create_map(t_arg_filler *arg)
{
  int i;
  int j;
  int x;
  int y;
  char *tmp;
  char *str;

  j = 0;
  i = 0;
  x = -2;
  y = 0;
  if (!(arg->map = (char **)ft_memalloc(sizeof(char *) * arg->map_size_x + 3)))
    return (-1);

  i = 0;
  while (get_next_line(0, &str) > 0 && j <= 8)
  {
    arg->map[i] = ft_strdup(str);
    i++;
    j++;
    ft_strdel(&str);
  }
  arg->map[i] = NULL;
  return 0;
}

int main(int argc, char **argv)
{
  t_arg_filler arg;
  int i;

  i = 0;
  init_arg(&arg);
  get_players(&arg);
  get_map_size(&arg);

  while (1)
  {
    create_map(&arg);
    while (arg.map[i])
    {
      ft_printf("%s\n", arg.map[i]);
      i++;
    }
    i = 0;
    ft_printf("\n\n");
  }
  return 0;
}
