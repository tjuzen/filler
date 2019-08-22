#include "../includes/filler.h"

void init_arg(t_arg_filler *arg)
{
  arg->player = 1;
  arg->map_size_x = 24;
  arg->map_size_y = 40;
  arg->map = NULL;
  arg->piece_x = 4;
  arg->piece_y = 7;
  arg->piece = NULL;
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


// int get_input(t_arg_filler *arg)
// {
//   char *line;
//
//   while (get_next_line(0, &line) > 0)
//   {
//     if (ft_strstr(line, "Plateau"))
//       get_map(line, arg);
//     else if (ft_strstr(line, "Piece"))
//       get_piece(line, arg);
//     ft_strdel(&line);
//   }
//   return (0);
// }

int create_map(t_arg_filler *arg)
{
  int i;
  char *str;
	int fd;
  i = 0;

  if (!(arg->map = (char **)ft_memalloc(sizeof(char *) * (arg->map_size_x + 2))))
    return (-1);
  fd = open("./maptest", O_RDONLY);
  while (get_next_line(fd, &str) > 0)
  {
	// ft_printf("Ma str = %s\n", str);
    arg->map[i] = ft_strdup(str);
    i++;
    ft_strdel(&str);
  }
  close(fd);
  arg->map[arg->map_size_x + 2] = NULL;
  return 0;
}

int delete_map(t_arg_filler *arg)
{
	if (arg->map != NULL)
		ft_free_stringtab(arg->map);
	return (0);
}

int get_input(t_arg_filler *arg)
{
	int flag;
	int i;
	char *str;

	i = 0;
	flag = 0;
	int fd = open("./maptest", O_RDONLY);
	if (!(arg->map = (char **)ft_memalloc(sizeof(char *) * (arg->map_size_x + 3))))
      return (-1);
	while (get_next_line(fd, &str) > 0)
	{
		if (ft_strstr(str, "Plateau"))
			flag = 1;
		if (ft_strstr(str, "Piece"))
			flag = 2;
		if (flag == 1)
		{
			arg->map[i] = ft_strdup(str);
			i++;
		}
		ft_strdel(&str);
	}
	arg->map[i] = NULL;
	close(fd);
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
	// while (1)
	// {
		get_input(&arg);
		while (arg.map[i])
		{
			ft_printf("%s\n", arg.map[i]);
			i++;
		}
		i = 0;
		ft_strdel(arg.map);
		ft_printf("\n\n");
	// }

  	return 0;
}
