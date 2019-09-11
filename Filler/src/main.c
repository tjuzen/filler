#include "../includes/filler.h"

int get_updated(t_arg_filler *arg)
{
		char	*line;
		int	i;
		int	nb_line;

		nb_line = 0;
		i = 0;
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

int main()
{
	t_arg_filler	arg;

	init_arg(&arg);
	get_players(&arg);
	while (1)
	{
		get_updated(&arg);
		play(&arg);
	}
	return (0);
}
