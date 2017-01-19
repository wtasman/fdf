#include "fdf.h"

int main(void)
{
	window_data	*screen;
	line_data	*line;

	line = init_line();
	screen = make_window();
	fill_line(line, 20, 20, 950, 950);
	draw_line(screen, line);

	mlx_loop(screen->mlx);
	return (0);
}
