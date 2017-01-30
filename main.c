#include "fdf.h"
#include <stdio.h>
int main(void)
{
	window_data	*screen;
	line_data	*line;

	line = init_line();
	screen = make_window();
	fill_line(line, 500, 500, 200, 500);
	draw_line(screen, line);
	fill_line(line, 500, 500, 300, 600);
	draw_line(screen, line);
	fill_line(line, 500, 500, 400, 700);
	printf("%i", line->y2);
	draw_line(screen, line);
	fill_line(line, 500, 500, 500, 800);
	draw_line(screen, line);
	fill_line(line, 500, 500, 600, 700);
	draw_line(screen, line);
	fill_line(line, 500, 500, 700, 600);
	draw_line(screen, line);
	fill_line(line, 500, 500, 800, 500);
	draw_line(screen, line);
	fill_line(line, 500, 500, 700, 400);
	draw_line(screen, line);
	fill_line(line, 500, 500, 600, 300);
	draw_line(screen, line);
	fill_line(line, 500, 200, 500, 500);
	draw_line(screen, line);
	fill_line(line, 500, 500, 400, 300);
	draw_line(screen, line);
	fill_line(line, 500, 500, 300, 400);
	draw_line(screen, line);
	
	//draw_rect(screen, 50, 50, 100, 900);
	//draw_circle(screen, 500, 500, 250);
	//draw_triangle(screen, 500, 500, 550, 500, 550, 550);

	mlx_loop(screen->mlx);
	return (0);
}
