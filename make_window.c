#include "fdf.h"

t_window	*init_window(void)
{
	t_window	*screen;

	screen = (t_window *)malloc(sizeof(t_window));
	screen->mlx = NULL;
	screen->window = NULL;
	return (screen);
}

t_window	*make_window(void)
{
	void	*mlx;
	void	*window;
	t_window	*screen;

	screen = init_window();
	mlx = mlx_init();
	window = mlx_new_window(mlx, 1000, 1000, "Screen");
	screen->mlx = mlx;
	screen->window = window;
	return (screen);
}