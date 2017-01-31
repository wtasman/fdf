#include "fdf.h"
#include <stdio.h>
int main(void)
{
	window_data	*screen;
	line_data	*line;

	line = init_line();
	screen = make_window();
	fill_line(line, 200, 500, 500, 500);
	draw_line(screen, line);
	fill_line(line, 300, 600, 500, 500);
	draw_line(screen, line);
	fill_line(line, 400, 700, 500, 500);
	draw_line(screen, line);
	fill_line(line, 500, 800, 500, 500);
	draw_line(screen, line);
	fill_line(line, 600, 700, 500, 500);
	draw_line(screen, line);
	fill_line(line, 700, 600, 500, 500);
	draw_line(screen, line);
	fill_line(line, 800, 500, 500, 500);
	draw_line(screen, line);
	fill_line(line, 700, 400, 500, 500);
	 draw_line(screen, line);
	fill_line(line, 600, 300, 500, 500);
	draw_line(screen, line);
	fill_line(line, 500, 200, 500, 500);
	draw_line(screen, line);
	fill_line(line, 400, 300, 500, 500);
	draw_line(screen, line);
	fill_line(line, 500, 500, 300, 400);
	draw_line(screen, line);
		
	fill_line(line, 500, 500, 750, 750);
	draw_line(screen, line);
	fill_line(line, 500, 500, 250, 750);
	draw_line(screen, line);
	fill_line(line, 500, 500, 250, 250);
	draw_line(screen, line);
	fill_line(line, 500, 500, 750, 250);
	draw_line(screen, line);


	draw_rect(screen, 50, 50, 100, 900);
	draw_circle(screen, 500, 500, 250);
	draw_triangle(screen, 100, 100, 900, 100, 900, 900);

	mlx_loop(screen->mlx);
	return (0);
}
