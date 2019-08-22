#ifndef FILLER_H
# define FILLER_H

# include "../libft/includes/libft.h"

/*
** Définition de ma structure
*/

typedef	struct	s_arg_filler
{
	int    player;
	int    map_size_x;
	int    map_size_y;
  char    **map;
  char    **piece;
}				t_arg_filler;



#endif
