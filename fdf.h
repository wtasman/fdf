#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx/mlx.h"

typedef	struct t_line
{
	int x1;
	int y1;
	int x2;
	int y2;
}	line_data;

typedef struct t_window
{
	void	*mlx;
	void	*window;
}	window_data;

window_data	*make_window(void);
void		draw_line(window_data *, line_data *);
line_data	*init_line(int x1, int y1, int x2, int y2);

#endif