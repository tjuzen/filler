#include "../includes/filler.h"

void	reset(t_arg_filler *arg)
{
	arg->flag = 0;
	arg->piece_size_x = 0;
	arg->piece_size_y = 0;
	//arg->map = NULL;
	//arg->piece = NULL;
	arg->ret_x = 0;
	arg->ret_y = 0;
}

// si je sors de la map exit
// si je suis sur un ennemi exit
// si j'ai 1 contact OK

int is_placable_krusty(t_arg_filler *arg, int x, int y)
{
  int i;
  int j;
  int compt_star;
  int score;

  score = 1;
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
		if (compt_star > 1)
			return (0);
		score++;
      }
    }
  }
  if (compt_star == 0)
  	return (0);
  return (score);
}

// void check_score(t_arg_filler *arg,int x,int y)
// {
//
// }

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
		//fprintf(stderr, "\nx = %i\ny = %i\n", x, y);
        previous_score = is_placable_krusty(arg, x, y);
		//fprintf(stderr, "score %i\n", previous_score);
		if (previous_score > score)
		{
			fprintf(stderr, "%s\n", "Je suis ici");
			fprintf(stderr, "x et y %i %i\n", x, y);
			arg->ret_x = x;
	  		arg->ret_y = y;
			score = previous_score;
		}
    }
  }
  return (0);
}

int place_piece_bot(t_arg_filler *arg)
{
  int x;
  int y;

  x = 1 - arg->piece_size_x;
  while (++x < arg->map_size_x + arg->piece_size_x)
  {
    y = 1 - arg->piece_size_y;
    while (++y < arg->piece_size_y + arg->map_size_y)
    {
        if (is_placable_krusty(arg, x, y) == 1)
		{
			arg->ret_x = x;
	  		arg->ret_y = y;
	  		return (1);
		}
    }
  }
  return (0);
}

int play(t_arg_filler *arg)
{
	// if (arg->piece)
	// 	print_piece(arg);
	// if (arg->map)
	// 	print_map(arg);
	arg->old_map = arg->map;
	if (arg->player == 'X')
		place_piece_top(arg);
	else if (arg->player == 'O')
	{
		if (place_piece_bot(arg) == 0)
			return (-1);
	}
  	print_ret(arg);
	reset(arg);
  	return (0);
}
