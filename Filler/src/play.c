#include "../includes/filler.h"

void	reset(t_arg_filler *arg)
{
	arg->flag = 0;
	arg->piece_size_x = 0;
	arg->piece_size_y = 0;
	arg->ret_x = 0;
	arg->ret_y = 0;
	arg->previous_x = 0;
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
		{
			arg->previous_x = x;
			my_x = x;
		}
		else if (arg->map[x][y] == arg->enemy)
			ennemy_x = x;
    }
  }
  if (my_x > ennemy_x)
  	arg->start = 1;
  else
  	arg->start = -1;
}

int place_piece_bot(t_arg_filler *arg)
{
  int x;
  int y;
  int score;
  int previous_score;

  previous_score = 0;
  score = 0;
  x = arg->map_size_x;
  while (--x > 0 - arg->piece_size_x)
  {
    y = arg->map_size_y;
    while (--y > 0 - arg->piece_size_y)
    {
        previous_score = is_placable_krusty(arg, x, y);
		if (previous_score > score)
		{
			arg->ret_x = x;
	  		arg->ret_y = y;
			score = previous_score;
		}
    }
  }
  return (0);
}

int check_score_down(t_arg_filler *arg, int x, int y)
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
      {
		if (x + i == 0 || y + j == 0)
			score++;
		score++;
      }
    }
  }
  return (score);
}

int get_contact(t_arg_filler *arg, int x, int y)
{
  int i;
  int j;
  int score;

  score = 0;
  i = -1;
  while (arg->piece[++i])
  {
    j = -1;
    while (arg->piece[i][++j])
    {
      if (arg->piece[i][j] == '*')
      {
		  if (x + i + 1 > arg->map_size_x && arg->map[x + i + 1][y + j] == arg->enemy)
		  	score++;
		  if (y + j - 1 >= 0 && arg->map[x + i][y + j - 1] == arg->enemy)
		  	score += 2;
      }
    }
  }
  fprintf(stderr, "Mon score %i\n", score);
  return (score);
}

















int choose_strategy(t_arg_filler *arg, int x, int y)
{
  	int myx;
  	int otx;

	myx = 0;
	otx = 0;
  	x = -1;
  	while (++x < arg->map_size_x)
  	{
    	y = -1;
    	while (++y < arg->map_size_y)
    	{
			if (arg->map[x][y] == arg->enemy && otx == 0)
				otx = x;
			else if (arg->map[x][y] == arg->player && myx == 0)
				myx = x;
    	}
  	}
  	if (otx <= myx)
	{
		arg->strategy = 0;
		fprintf(stderr, "ici %i\n", arg->strategy);
	}
	else
	{
		arg->strategy = 1;
		fprintf(stderr, "ici %i\n", arg->strategy);
	}
	return (0);
}

int strategy_zero(t_arg_filler *arg, int x, int y)
{
  int i;
  int j;
  int score;

  score = 1;
  i = -1;
  arg->strategy = 0;
  while (arg->piece[++i])
  {
    j = -1;
    while (arg->piece[i][++j])
    {
      if (arg->piece[i][j] == '*')
      {
		if (x + i == 0 && y + j == 0)
			score += 3;
		if (y + j == 0)
			score += 2;
      }
    }
  }
  return (score);
}

int strategy_one(t_arg_filler *arg, int x, int y)
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
      {
		if (y + j - 1 >= 0 && y + j - 1 < arg->map_size_y && arg->map[x + i][y + j - 1] == '.' && x + i <= arg->previous_x)
		{
			fprintf(stderr, "Ici a\n%i + %i et %i", x, i, arg->previous_x);
			score += 3;
		}
		if (y + j - 2 >= 0 && y + j - 2 < arg->map_size_y && arg->map[x + i][y + j - 2] == '.' && x + i <= arg->previous_x)
		{
			fprintf(stderr, "Ici b\n%i + %i et %i", x, i, arg->previous_x);
			score++;
		}
		if (y + j - 3 >= 0 && y + j - 3 < arg->map_size_y && arg->map[x + i][y + j - 3] == '.' && x + i <= arg->previous_x)
		{
			fprintf(stderr, "Ici c\n%i + %i et %i", x, i, arg->previous_x);
			score++;
		}
      }
    }
  }
  return (score);
}

int strategy_two(t_arg_filler *arg, int x, int y)
{
	return (1);
}
int strategy_three(t_arg_filler *arg, int x, int y)
{
	return (1);
}
int strategy_four(t_arg_filler *arg, int x, int y)
{
	return (1);
}

// int strategy_special_theo(t_arg_filler *arg, int x, int y)
// {
//   int i;
//   int j;
//   int score;
//
//   score = 1;
//   i = -1;
//   arg->strategy = 0;
//   while (arg->piece[++i])
//   {
//     j = -1;
//     while (arg->piece[i][++j])
//     {
//       if (arg->piece[i][j] == '*')
//       {
// 		  if (x )
// 		  if (arg->map[x + i][y + j])
//       }
//     }
//   }
//   return (score);
// }

int check_score_up(t_arg_filler *arg, int x, int y)
{
	int score;

	choose_strategy(arg, x, y);
	// if (arg->strategy != 0)
	// 	score = get_contact(arg, x, y);
	// score += check_cut(arg, x, y);
	if (arg->strategy == 0)
	{
		return (10);
	}
	if (arg->strategy == 1)
		score += strategy_one(arg, x, y);
	// else if (arg->strategy == 1)
	// 	score += strategy_one(arg, x, y);
	// else if (arg->strategy == 2)
	// 	score += strategy_two(arg, x, y);
	// else if (arg->strategy == 3)
	// 	score += strategy_three(arg, x, y);
	// else
	// 	score += strategy_four(arg, x, y);
	// score = strategy_special_theo(arg, x, y);
	return (score);
}

int is_placable_krusty(t_arg_filler *arg, int x, int y)
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
		if (arg->old_map[x + i][y + j] == arg->enemy || arg->old_map[x + i][y + j] == ft_tolower(arg->enemy))
			return (0);
		if (arg->old_map[x + i][y + j] == arg->player || arg->old_map[x + i][y + j] == ft_tolower(arg->player))
			compt_star++;
      }
    }
  }
  if (compt_star != 1)
  	return (0);
  if (arg->start == 1)
  	return (check_score_up(arg, x, y));
  else
  	return (check_score_down(arg, x, y));
}

int place_piece_top(t_arg_filler *arg)
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
        previous_score = is_placable_krusty(arg, x, y);
		if (previous_score > score && arg->strategy == 0)
		{
			arg->ret_x = x;
	  		arg->ret_y = y;
			return (0);
		}
		if (previous_score > score)
		{
			arg->ret_x = x;
	  		arg->ret_y = y;
			score = previous_score;
		}
    }
  }
  return (0);
}

void get_high_x(t_arg_filler *arg)
{
  int x;
  int y;

  x = -1;
  while (++x < arg->map_size_x)
  {
    y = -1;
    while (++y < arg->map_size_y)
    {
        if (arg->map[x][y] == arg->player)
		{
			arg->previous_x = x;
			return ;
		}
    }
  }
}

int play(t_arg_filler *arg)
{
	if (arg->start == 0)
		get_start(arg);
	get_high_x(arg);
	arg->old_map = arg->map;
	if (arg->start == 1)
		place_piece_top(arg);
	else if (arg->start == -1)
		place_piece_bot(arg);
  	print_ret(arg);
	reset(arg);
  	return (0);
}
