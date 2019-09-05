#include "../includes/filler.h"

int check_one_touch(t_arg_filler *arg, int x, int y)
{
	int		i;
	int		j;
	int		tmp;
	int		compt;

	i = -1;
	tmp = y;
	compt = 0;

	while (arg->piece[++i])
	{
		j = -1;
		y = tmp;
		while (arg->piece[i][++j])
		{
			if (arg->piece[i][j] == '*' && arg->map[x][y] == arg->player)
				compt++;
			y++;
		}
		x++;
	}
	return ((compt > 1) ? 0 : 1);
}

int is_placable(t_arg_filler *arg, int x, int y)
{
  int i;
  int j;

  i = -1;
  while (arg->piece[++i])
  {
    j = -1;
    while (arg->piece[i][++j])
    {
      if (arg->piece[i][j] == '*')
      {
		if (check_one_touch(arg, x - i, y - j) == 1)
  		{
  			arg->ret_x = x - i;
  			arg->ret_y = y - j;
  			return (1);
  		}
      }
    }
  }
  return (0);
}

int place_piece_top(t_arg_filler *arg)
{
  int x;
  int y;

  x = -1;
  while (arg->map[++x])
  {
    y = -1;
    while (arg->map[x][++y])
    {
      if (arg->map[x][y] == arg->player)
      {
        if (is_placable(arg, x, y) == 1)
          return (1);
      }
    }
  }
  return (0);
}

int play(t_arg_filler *arg)
{
	if (arg->map == NULL || arg->piece == NULL)
		return (-1);
	place_piece_top(arg);
  	print_ret(arg);
  	return (0);
}
