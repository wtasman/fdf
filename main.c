#include "fdf.h"

int main(void)
{
	window_data	*screen;
	line_data	*line;
	int x1;
	int y1;
	int x2;
	int y2;

	x1 = 500;
	x2 = 500;
	y1 = 500;
	y2 = 800;
	line = init_line();
	screen = make_window();
	while (y2 >= 500)
	{	
		fill_line(line, x1, y1, x2, y2);
		draw_line(screen, line);
		x2 -= 100;
		y2 -= 100;
	}
	//draw_rect(screen, 50, 50, 100, 900);
	//draw_circle(screen, 500, 500, 250);
	//draw_triangle(screen, 500, 500, 550, 500, 550, 550);

	mlx_loop(screen->mlx);
	return (0);
}
