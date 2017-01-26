#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx/mlx.h"

typedef	struct line_struct
{
	int x1;
	int y1;
	int x2;
	int y2;
}	line_data;

typedef struct window_struct
{
	void	*mlx;
	void	*window;
}	window_data;

window_data	*make_window(void);
void		draw_line(window_data *, line_data *);
line_data	*init_line();
void		fill_line(line_data *line, int x1, int y1, int x2, int y2);
void		draw_rect(window_data *screen, int x1, int y1, int h, int w);

#endif