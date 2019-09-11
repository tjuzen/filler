#include "../includes/filler.h"

void ft_free_stringtab(char **element)
{
	int i;

	i = -1;
	if (!element)
		return ;
	while (element[++i])
		free(element[i]);
	free(element);
}

void ft_free_intab(int *element)
{
	int i;

	i = -1;
	if (!element)
		return ;
	while (element[++i])
		free(&element[i]);
	free(element);
}

void free_all(t_arg_filler *arg)
{
	ft_free_stringtab(arg->map);
	ft_free_stringtab(arg->piece);
}

void init_arg(t_arg_filler *arg)
{
	arg->player = 0;
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

void print_ret(t_arg_filler *arg)
{
	ft_printf("%i %i\n", arg->ret_x, arg->ret_y);
}

void print_map(t_arg_filler *arg)
{
	int i;

	i = 0;
	while (arg->map[i])
	{
		ft_printf("%s\n", arg->map[i]);
		i++;
	}
}

void print_piece(t_arg_filler *arg)
{
	int i;

	i = 0;
	while (arg->piece[i])
	{
		ft_printf("%s\n", arg->piece[i]);
		i++;
	}
}

void get_players(t_arg_filler *arg)
{
		char	*line;

		get_next_line(0, &line);
		if (ft_strstr(line, "p1"))
			arg->player = 'O';
		else if (ft_strstr(line, "p2"))
	    	arg->player = 'X';
	  	ft_strdel(&line);
}
