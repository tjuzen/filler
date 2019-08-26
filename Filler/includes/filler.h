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
	int			map_size_x;
	int			map_size_y;
	int			piece_x;
	int			piece_y;
	int			*last_piece;
  char    **map;
  char    **piece;
}				t_arg_filler;

/*
** MAIN.C
*/
int main();

/*
** TOOLS.C
*/
void ft_free_stringtab(char **element);
void free_all(t_arg_filler *arg);
void init_arg(t_arg_filler *arg);
void print_map(t_arg_filler *arg);
void print_piece(t_arg_filler *arg);
void get_players(t_arg_filler *arg);

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


#endif
