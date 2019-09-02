#include "../includes/filler.h"

int get_updated(t_arg_filler *arg)
{
  char          *line;
  int           i;
  int nb_line;

  nb_line = 0;
  i = 0;
  // int fd = open("./maptest", O_RDONLY);

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
  // close(fd);
  return (0);
}

int main()
{
  t_arg_filler  arg;
  int i = 4;

  init_arg(&arg);
  get_players(&arg);
  while (1)
  {
    // ft_printf("player = %c\n", arg.player);
    get_updated(&arg);
    play(&arg);

    // print_map(&arg);
    // print_piece(&arg);
    // free_all(&arg);
  }

  return (0);
}
