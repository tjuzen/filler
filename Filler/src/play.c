#include "../includes/filler.h"

void	reset(t_arg_filler *arg)
{
	arg->flag = 0;
	arg->piece_size_x = 0;
	arg->piece_size_y = 0;
	arg->map = NULL;
	arg->piece = NULL;
	arg->ret_x = 0;
	arg->ret_y = 0;
}

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

int check_others(t_arg_filler *arg, int x, int y)
{
	int		i;
	int		j;
	int		tmp;

	i = -1;
	tmp = y;

	while (arg->piece[++i])
	{
		j = -1;
		y = tmp;
		while (arg->piece[i][++j])
		{
			if (arg->piece[i][j] == '*' && (arg->map[x][y] == 'O' || arg->map[x][y] == 'o'))
				return (0);
				if (arg->piece[i][j] == '*' && (x < 0 || y < 0))
					return (0);
			y++;
		}
		x++;
	}
	return (1);
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
			if (check_others(arg, x - i, y - j) == 1)
			{
  				arg->ret_x = x - i;
  				arg->ret_y = y - j;
  				return (1);
			}
  		}
		return (0);
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

int place_piece_bot(t_arg_filler *arg)
{
  int x;
  int y;

  x = arg->map_size_x;
  while (arg->map[--x])
  {
    y = arg->map_size_y;
    while (arg->map[x][--y])
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
	// place_piece_bot(arg);
  	print_ret(arg);
	reset(arg);
  	return (0);
}
