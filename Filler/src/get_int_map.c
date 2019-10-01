#include "../includes/filler.h"

int init_map(t_arg_filler *arg)
{
	int x;
	int y;

	x = -1;
	while (++x < arg->map_size_x)
	{
		if (!(arg->special_map[x] = ft_memalloc(sizeof(int) * arg->map_size_y)))
			return (-1);
		y = -1;
		while (++y < arg->map_size_y)
		{
			arg->special_map[x][y] = 666;
			if (arg->map[x][y] == (arg->enemy))
				arg->special_map[x][y] = 0;
		}
	}
	return (1);
}

void	change(t_arg_filler *arg, int count, int x, int y)
{
	if (x + 1 < arg->map_size_x && arg->special_map[x + 1][y] == count)
		arg->special_map[x][y] = count + 1;
	if (y + 1 < arg->map_size_y && arg->special_map[x][y + 1] == count)
		arg->special_map[x][y] = count + 1;
	if (x + 1 < arg->map_size_x && y + 1 < arg->map_size_y && arg->special_map[x + 1][y + 1] == count)
		arg->special_map[x][y] = count + 1;
	if (x + 1 < arg->map_size_x && y - 1 >= 0 && arg->special_map[x + 1][y - 1] == count)
		arg->special_map[x][y] = count + 1;
	if (x - 1 >= 0 && arg->special_map[x - 1][y] == count)
		arg->special_map[x][y] = count + 1;
	if (y - 1 >= 0 && arg->special_map[x][y - 1] == count)
		arg->special_map[x][y] = count + 1;
	if (x - 1 >= 0 && y - 1 >= 0 && arg->special_map[x - 1][y - 1] == count)
		arg->special_map[x][y] = count + 1;
	if (x - 1 >= 0 && y + 1 < arg->map_size_y && arg->special_map[x - 1][y + 1] == count)
		arg->special_map[x][y] = count + 1;
}

void		transform_rest(t_arg_filler *arg)
{
	int	x;
	int	y;
	int	count;

	x = 0;
	y = 0;
	count = 1;
	while (count < arg->map_size_y)
	{
		while (x < arg->map_size_x)
		{
			while (y < arg->map_size_y)
			{
				if (arg->special_map[x][y] == 666)
					change(arg, count, x, y);
				y++;
			}
			y = 0;
			x++;
		}
		x = 0;
		y = 0;
		count++;
	}
}

void transform_map(t_arg_filler *arg)
{
	int x;
	int y;

	x = -1;
    // print_special_map(arg);
    // fprintf(stderr, "\n");
	while (++x < arg->map_size_x)
	{
		y = -1;
		while (++y < arg->map_size_y)
		{
			if (arg->special_map[x][y] == 0)
			{
				if (x + 1 < arg->map_size_x && arg->special_map[x + 1][y] == 666)
					arg->special_map[x + 1][y] = 1;
				if (x - 1 >= 0 && arg->special_map[x - 1][y] == 666)
					arg->special_map[x - 1][y] = 1;
				if (y + 1 < arg->map_size_y && arg->special_map[x][y + 1] == 666)
					arg->special_map[x][y + 1] = 1;
				if (y - 1 >= 0 && arg->special_map[x][y - 1] == 666)
					arg->special_map[x][y - 1] = 1;
				if (y - 1 >= 0 && x - 1 >= 0 && arg->special_map[x - 1][y - 1] == 666)
					arg->special_map[x - 1][y - 1] = 1;
				if (y + 1 < arg->map_size_y && x + 1 < arg->map_size_x && arg->special_map[x + 1][y + 1] == 666)
					arg->special_map[x + 1][y + 1] = 1;
				if (y - 1 >= 0 && x + 1 < arg->map_size_x && arg->special_map[x + 1][y - 1] == 666)
					arg->special_map[x + 1][y - 1] = 1;
				if (x - 1 >= 0 && y + 1 < arg->map_size_y && arg->special_map[x - 1][y + 1] == 666)
					arg->special_map[x - 1][y + 1] = 1;
			}
		}
	}
	transform_rest(arg);
    // print_special_map(arg);
    // fprintf(stderr, "\n");
}
