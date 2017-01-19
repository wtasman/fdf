#include "fdf.h"

int main(void)
{
	window_data	*screen;
	line_data	*line;

	line = init_line(20, 20, 950, 950);
	screen = make_window();
	draw_line(screen, line);

	mlx_loop(screen->mlx);
	return (0);
}
