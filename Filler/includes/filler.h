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
  	char   	    **piece;
	int			ret_x;
	int			ret_y;
	int			strategy;
	int			start;
	int			obj;
}				t_arg_filler;

/*
** MAIN.C
*/

int main();
void reset_args(t_arg_filler *arg);
int get_updated(t_arg_filler *arg);

/*
** TOOLS.C
*/

void ft_free_stringtab(char **element);
void ft_free_intab(int *element);
void free_all(t_arg_filler *arg);
void init_arg(t_arg_filler *arg);
void print_map(t_arg_filler *arg);
void print_piece(t_arg_filler *arg);
void get_players(t_arg_filler *arg);
void print_ret(t_arg_filler *arg);

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
int place_piece_top(t_arg_filler *arg);
int check_one_touch(t_arg_filler *arg, int x, int y);
int is_placable_krusty(t_arg_filler *arg, int x, int y);

#endif
