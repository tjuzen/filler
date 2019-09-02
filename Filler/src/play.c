#include "../includes/filler.h"

int ft_checkplace_piece(t_arg_filler *arg, int x, int y)
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
	int		i;
	int		j;

	i = arg->piece_size_x - 1;
	while (i >= 0)
	{
		j = arg->piece_size_y - 1;
		while (j >= 0)
		{
			if (arg->piece[i][j] == '*')
			{
				if (ft_checkplace_piece(arg, x - i, y - j))
				{
          // ft_printf("ici : i %i j %i x %i y %i\n", i, j, x, y);
          // ft_printf("ici = %i %i\n", x - i, y - j);
          arg->ret_x = x - i;
          arg->ret_y = y - j;
					return (1);
				}
			}
			j--;
		}
		i--;
	}
	return (0);
}

// int is_placable(t_arg_filler *arg, int x, int y)
// {
//   int i;
//   int j;
//   int touch;
//   int tmp;
//   int no_symb;
//
//   tmp = y;
//   touch = 0;
//   i = -1;
//   no_symb = 0;
//
//   while (arg->piece[++i])
//   {
//     j = -1;
//     y = tmp;
//     while (arg->piece[i][++j])
//     {
//       if (arg->piece[i][j] == '*')
//       {
//         no_symb = 0;
//         ft_printf("i = %i j = %i x = %i y = %i\n", i, j, x, y);
//         if (arg->map[x - 1][y - 1] == arg->player)
//         {
//           ft_printf("ICI ICI i = %i j = %i x = %i y = %i\n", i, j, x, y);
//           touch++;
//         }
//       }
//       y++;
//     }
//     x++;
//   }
//
//   if (touch <= 1)
//   {
//     arg->ret_x = x - arg->piece_size_x;
//     arg->ret_y = y - arg->piece_size_y;
//   }
//
//   return (touch > 1 ? -1 : 1);
// }

int place_piece(t_arg_filler *arg)
{
  int x;
  int y;

  x = 0;
  while (arg->map[x])
  {
    y = 0;
    while (arg->map[x][y])
    {
      if (arg->map[x][y] == arg->player)
      {
        if (is_placable(arg, x, y) == 1)
          return (1);
      }
      y++;
    }
    x++;
  }
  return (0);
}

int play(t_arg_filler *arg)
{
  place_piece(arg);
  print_ret(arg);
  return (0);
}
