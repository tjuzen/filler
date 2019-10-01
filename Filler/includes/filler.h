#ifndef FILLER_H
# define FILLER_H

# include "../libft/includes/libft.h"

/*
** Définition de ma structure
*/

typedef	struct	s_arg_filler
{
	int 		flag;
	char		player;
	char		enemy;
	int			map_size_x;
	int			map_size_y;
	int			piece_size_x;
	int			piece_size_y;
  	char  	    **map;
	int			**special_map;
  	char   	    **piece;
	int			ret_x;
	int			ret_y;
}				t_arg_filler;

/*
** MAIN.C
*/

int get_updated(t_arg_filler *arg);

/*
** TOOLS.C
*/

void ft_free_map(char **element, t_arg_filler *arg);
void ft_free_piece(char **element, t_arg_filler *arg);
void ft_free_intab(int **element, t_arg_filler *arg);
void init_arg(t_arg_filler *arg);
void get_players(t_arg_filler *arg);
void print_special_map(t_arg_filler *arg);
void print_map(t_arg_filler *arg);
void print_piece(t_arg_filler *arg);

/*
** GET_PIECE.C
*/

int get_piece(t_arg_filler *arg, char *line, int i);
int get_piece_size(t_arg_filler *arg, char *line);
int get_piece_prout(t_arg_filler *arg, char *line, int i);

/*
** GET_MAP.C
*/

int get_map_size(t_arg_filler *arg, char *line);
int get_map(t_arg_filler *arg, char *line, int i);
int get_map_prout(t_arg_filler *arg, char *line, int i);

/*
** PLAY.C
*/

int play(t_arg_filler *arg);
int is_placable(t_arg_filler *arg, int x, int y);

/*
** GET_INT_MAP.C
*/

int		init_map(t_arg_filler *arg);
void	transform_map(t_arg_filler *arg);
void	transform_rest(t_arg_filler *arg);
void	change(t_arg_filler *arg, int count, int x, int y);




#endif
