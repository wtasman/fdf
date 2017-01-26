#include "fdf.h"

int main(void)
{
	window_data	*screen;
	line_data	*line;

	line = init_line();
	screen = make_window();
	//fill_line(line, 50, 50, 50, 100);
	//draw_line(screen, line);
	draw_rect(screen, 50, 50, 100, 900);

	mlx_loop(screen->mlx);
	return (0);
}
