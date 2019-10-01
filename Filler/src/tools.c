#include "../includes/filler.h"

void ft_free_map(char **element, t_arg_filler *arg)
{
	int i;

	i = -1;
	if (!element)
		return ;
	while (++i < arg->map_size_x)
		ft_strdel(&element[i]);
	free(element);
}

void ft_free_piece(char **element, t_arg_filler *arg)
{
	int i;

	i = -1;
	if (!element)
		return ;
	while (++i < arg->piece_size_x)
		ft_strdel(&element[i]);
	free(element);
}

void ft_free_intab(int **element, t_arg_filler *arg)
{
	int i;

	i = -1;
	if (!element)
		return ;
	while (++i < arg->map_size_x)
		free(&element[i]);
	free(element);
}

void init_arg(t_arg_filler *arg)
{
	arg->player = 0;
	arg->enemy = 0;
	arg->map_size_x = 0;
	arg->map_size_y = 0;
	arg->map = NULL;
	arg->piece_size_x = 0;
	arg->piece_size_y = 0;
	arg->piece = NULL;
	arg->flag = 0;
	arg->ret_x = 0;
	arg->ret_y = 0;
}

void print_map(t_arg_filler *arg)
{
	int i;

	i = 0;
	while (arg->map[i])
	{
		fprintf(stderr, "--%s--\n", arg->map[i]);
		i++;
	}
}

void print_special_map(t_arg_filler *arg)
{
	int i;
	int j;

	i = -1;
	while (++i < arg->map_size_x)
	{
		j = -1;
		while (++j < arg->map_size_y)
		{
			fprintf(stderr, "|%*i|", 3, arg->special_map[i][j]);

		}
		fprintf(stderr, "\n");
	}
}

void print_piece(t_arg_filler *arg)
{
	int i;

	i = 0;
	while (arg->piece[i])
	{
		fprintf(stderr, "-%s\n", arg->piece[i]);
		i++;
	}
}

void get_players(t_arg_filler *arg)
{
		char	*line;

		get_next_line(0, &line);
		if (ft_strstr(line, "p1"))
		{
			arg->player = 'O';
			arg->enemy = 'X';
		}
		else if (ft_strstr(line, "p2"))
	    {
			arg->player = 'X';
			arg->enemy = 'O';
		}
	  	ft_strdel(&line);
}
