#include "fdf.h"
#include <stdio.h>
void	draw_rect(t_window *screen, int x1, int y1, int h, int w)
{
	t_line *line;

	line = init_line();
	//top of rectangle
	fill_line(line, x1, y1, x1 + w, y1);
	draw_line(screen, line);
	//right side of rectangle
	fill_line(line, x1 + w, y1, x1 + w, y1 + h);
	draw_line(screen, line);
	//bottome of rectangle
	fill_line(line, x1, y1 + h, x1 + w, y1 + h);
	draw_line(screen, line);
	//left side of rectangle
	fill_line(line, x1, y1, x1, y1 + h);
	draw_line(screen, line);
}