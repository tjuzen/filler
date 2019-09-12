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

	i = 0;
	tmp = y;
	compt = 0;

	// ft_printf("\n\npos = %i %i\n\n", x, y);
	//
	// print_map(arg);
	// print_piece(arg);

	while (arg->piece[i])
	{
		j = 0;
		y = tmp;
		while (arg->piece[i][j])
		{
			// ft_printf("mon x = %i mon y = %i\nma piece = %c ma map = %c\n", x, y, arg->piece[i][j], arg->map[x][y]);
			// ft_printf("p = %c m = %c\n", arg->piece[i][j], arg->map[x][y]);
			if (x >= 0 && x < arg->map_size_x && y >= 0 && y < arg->map_size_y)
			{
				// ft_printf("oui\n");
				if (arg->map[x][y] == arg->player)
				{
					// ft_printf("\ncheck\n\n");
					compt++;
				}
			}
			y++;
			j++;
		}
		x++;
		i++;
	}
	// ft_printf("ici\n");
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
			if (arg->piece[i][j] == '*')
			{
				if (x >= 0 && x < arg->map_size_x && y >= 0 && y < arg->map_size_y)
				{
					if ((arg->map[x][y] == 'O' || arg->map[x][y] == 'o'))
						return (0);
					// if (arg->piece[i][j] == '*' && (x < 0 || y < 0 || x > arg->map_size_x || y > arg->map_size_y))
					// 	return (0);
				}
			}
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
		// else
		// 	return (0);
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
	if (place_piece_top(arg) == 0)
	{
		ft_printf("0 0\n");
		return (-1);
	}
	// place_piece_bot(arg);
  	print_ret(arg);
	reset(arg);
  	return (0);
}
