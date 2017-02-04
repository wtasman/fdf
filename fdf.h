#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx/mlx.h"

typedef	struct s_line
{
	int x1;
	int y1;
	int x2;
	int y2;
	int dx;
	int dy;
	int y;
	int x;
	int	offsetx;
	int	offsety;
	int error;
}	t_line;

typedef struct s_window
{
	void	*mlx;
	void	*window;
}	t_window;

typedef struct s_map
{
	int		fd;
	int		width;
	int		height;
	int		**tab;
}	t_map;

t_window	*make_window(void);
void		draw_line(t_window *, t_line *);
t_line	*init_line();
void		fill_line(t_line *line, int x1, int y1, int x2, int y2);
void		draw_rect(t_window *screen, int x1, int y1, int h, int w);
void 		draw_circle(t_window *screen, int x0, int y0, int radius);
void	draw_triangle(t_window *screen, int x1, int y1, int x2, int y2, int x3, int y3);
t_map	*read_map(char *file);

#endif