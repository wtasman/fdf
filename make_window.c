#include "fdf.h"

window_data	*init_window(void)
{
	window_data	*screen;

	screen = (window_data *)malloc(sizeof(window_data));
	screen->mlx = NULL;
	screen->window = NULL;
	return (screen);
}

window_data	*make_window(void)
{
	void	*mlx;
	void	*window;
	window_data	*screen;

	screen = init_window();
	mlx = mlx_init();
	window = mlx_new_window(mlx, 1000, 1000, "Screen");
	screen->mlx = mlx;
	screen->window = window;
	return (screen);
}