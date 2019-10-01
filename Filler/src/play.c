#include "../includes/filler.h"

void	reset(t_arg_filler *arg)
{
	arg->flag = 0;
	arg->piece_size_x = 0;
	arg->piece_size_y = 0;
	arg->ret_x = 0;
	arg->ret_y = 0;
}

int go_contact(t_arg_filler *arg, int x,  int y)
{
  int i;
  int j;
  int score;

  score = 1;
  i = -1;
  while (arg->piece[++i])
  {
    j = -1;
    while (arg->piece[i][++j])
    {
      if (arg->piece[i][j] == '*')
		score += arg->special_map[x + i][y + j];
    }
  }
  return (score);
}

int is_placable(t_arg_filler *arg, int x, int y)
{
  int i;
  int j;
  int compt_star;

  compt_star = 0;
  i = -1;
  while (arg->piece[++i])
  {
    j = -1;
    while (arg->piece[i][++j])
    {
      if (arg->piece[i][j] == '*')
      {
		if (x + i < 0 || x + i > arg->map_size_x - 1
			|| y + j < 0 || y + j > arg->map_size_y - 1)
		  	return (0);
		if (arg->map[x + i][y + j] == arg->enemy
			|| arg->map[x + i][y + j] == ft_tolower(arg->enemy))
			return (0);
		if (arg->map[x + i][y + j] == arg->player)
			compt_star++;
      }
    }
  }
  return (compt_star);
}

void find_best_piece(t_arg_filler *arg)
{
	int x;
	int y;
	int score;
	int previous_score;

	previous_score = 10000000;
	score = 0;
	x = 0 - arg->piece_size_x;
	while (++x < arg->map_size_x)
	{
		y = 0 - arg->piece_size_y;
		while (++y < arg->map_size_y)
		{
			if (is_placable(arg, x, y) == 1)
			{
				score = go_contact(arg, x, y);
				if (score < previous_score)
				{
					arg->ret_x = x;
		  			arg->ret_y = y;
					previous_score = score;
				}
			}
    	}
  	}
}

int play(t_arg_filler *arg)
{
	int count;

	count = 1;
	if (init_map(arg) == -1)
		return (-1);
	transform_map(arg);
	find_best_piece(arg);
  	ft_printf("%i %i\n", arg->ret_x, arg->ret_y);
	reset(arg);
  	return (0);
}
