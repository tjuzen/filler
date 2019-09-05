#include "../includes/filler.h"

void reset_args(t_arg_filler *arg)
{
	arg->flag = 0;
	arg->ret_x = 0;
	arg->ret_y = 0;
	free_all(arg);
}

int get_updated(t_arg_filler *arg)
{
	if (arg->flag_for_debug == 1)
	{
		char	*line;
		int	i;
		int	nb_line;
		int fd = open("./maptest", O_RDONLY);

		nb_line = 0;
		i = 0;
	  	reset_args(arg);
	  	while (get_next_line(fd, &line) > 0)
	  	{
	    	if (ft_strstr(line, "Plateau") || arg->flag == 1)
	      		i = get_map_prout(arg, line, i);
	    	if (ft_strstr(line, "Piece") || arg->flag == 2)
	      		i = get_piece_prout(arg, line, i);
	    	ft_strdel(&line);
	    	nb_line++;
	    	if (nb_line == arg->map_size_x + arg->piece_size_x + 3)
	      		break ;
	  	}
	  	return (0);
	}
	else
	{
		char	*line;
		int	i;
		int	nb_line;

		nb_line = 0;
		i = 0;
	  	reset_args(arg);
	  	while (get_next_line(0, &line) > 0)
	  	{
	    	if (ft_strstr(line, "Plateau") || arg->flag == 1)
	      		i = get_map_prout(arg, line, i);
	    	if (ft_strstr(line, "Piece") || arg->flag == 2)
	      		i = get_piece_prout(arg, line, i);
	    	ft_strdel(&line);
	    	nb_line++;
	    	if (nb_line == arg->map_size_x + arg->piece_size_x + 3)
	      		break ;
	  	}
	  	return (0);
	}
}

int main()
{
	t_arg_filler	arg;

	arg.flag_for_debug = 1;
	init_arg(&arg);
	get_players(&arg);
	while (1)
	{
		get_updated(&arg);
		play(&arg);
	}
	return (0);
}
