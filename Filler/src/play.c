#include "../includes/filler.h"

void	reset(t_arg_filler *arg)
{
	arg->flag = 0;
	arg->piece_size_x = 0;
	arg->piece_size_y = 0;
	arg->ret_x = 0;
	arg->ret_y = 0;
}

void get_start(t_arg_filler *arg)
{
  int x;
  int y;
  int my_x;
  int ennemy_x;

  x = -1;
  while (++x < arg->map_size_x)
  {
    y = -1;
    while (++y < arg->map_size_y)
    {
        if (arg->map[x][y] == arg->player)
			my_x = x;
		else if (arg->map[x][y] == arg->enemy)
			ennemy_x = x;
    }
  }
  if (my_x > ennemy_x)
  	arg->start = 1;
  else
  	arg->start = -1;
}

int strategy_one(t_arg_filler *arg, int x,  int y)
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
      if (arg->piece[i][j] == '*' && arg->map[x + i][y + j] != arg->player)
      {
		score += arg->map_size_x - (x + i);
		score += arg->map_size_y - (y + j);
      }
    }
  }
  return (score);
}

int strategy_two(t_arg_filler *arg, int x,  int y)
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
      if (arg->piece[i][j] == '*' && arg->map[x + i][y + j] != arg->player)
      {
		score += x + i;
		// score += arg->map_size_y - (y + j);
      }
    }
  }
  return (score);
}

int strategy_three(t_arg_filler *arg, int x,  int y)
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
      if (arg->piece[i][j] == '*' && arg->map[x + i][y + j] != arg->player)
      {
		score += arg->map_size_y - (y + j);
		// score += arg->map_size_y - (y + j);
      }
    }
  }
  return (score);
}

/*
// strategy one = foncer x0 ou y0
// strategy two = si je suis en dessous, cut a la verticale (vers x0)
				  si je suis au dessus, cut à l'horizontale (vers y0)
   strategy three = fill du coté enemi
*/
int		strategy(t_arg_filler *arg, int x, int y)
{
	if (arg->strategy == 1)
		return (strategy_one(arg, x, y));
	else if(arg->strategy == 2)
		return (strategy_two(arg, x, y));
	else
		return (strategy_three(arg, x, y));
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
		if (arg->map[x + i][y + j] == arg->player
			|| arg->map[x + i][y + j] == ft_tolower(arg->player))
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

	previous_score = 0;
	score = 0;
	x = 0 - arg->piece_size_x;
	while (++x < arg->map_size_x)
	{
		y = 0 - arg->piece_size_y;
		while (++y < arg->map_size_y)
		{
			if (is_placable(arg, x, y) == 1)
			{
				score = strategy(arg, x, y);
				if (score > previous_score)
				{
					arg->ret_x = x;
		  			arg->ret_y = y;
					previous_score = score;
				}
			}
    	}
  	}
}

void choose_strategy(t_arg_filler *arg)
{
	int x;
	int y;
	int score;
	int previous_score;

	previous_score = 0;
	score = 0;
	x = -1;
	arg->strategy = 1;
	while (++x < arg->map_size_x)
	{
		y = -1;
		while (++y < arg->map_size_y)
		{
			if (arg->map[x][y] == arg->player && x == 0)
				arg->strategy = 2;
			if (arg->strategy == 2 && arg->map[x][y] == arg->player && x == arg->map_size_x - 1)
				arg->strategy = 3;
			if (arg->map[x][y] == arg->player && y == 0)
    	}
  	}

int play(t_arg_filler *arg)
{
	if (arg->start == 0)
		get_start(arg);
	choose_strategy(arg);
	fprintf(stderr, "Ma strategie = %i\n", arg->strategy);
	find_best_piece(arg);
  	print_ret(arg);
	reset(arg);
  	return (0);
}
