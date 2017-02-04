#include "fdf.h"

void	draw_triangle(t_window *screen, int x1, int y1, int x2, int y2, int x3, int y3)
{
	t_line	*line;

	line = init_line();
	//1st line of triangle
	fill_line(line, x1, y1, x2, y2);
	draw_line(screen, line);
	//second line of triangle
	fill_line(line, x2, y2, x3, y3);
	draw_line(screen, line);
	//third line of triangle
	fill_line(line, x1, y1, x3, y3);
	draw_line(screen, line);
}