#include "fdf.h"

#define abs(x) ((x)<0 ? -(x) : (x))

void	swap(int a, int b)
{
	int	tmp;

	tmp = a;
	a = b;
	b = tmp;
}

line_data	*init_line(void)
{
	line_data	*line;

	line = (line_data *)malloc(sizeof(line_data));
	line->x1 = 0;
	line->y1 = 0;
	line->x2 = 0;
	line->y2 = 0;
	return (line);
}

void	fill_line(line_data *line, int x1, int y1, int x2, int y2)
{
	line->x1 = x1;
	line->y1 = y1;
	line->x2 = x2;
	line->y2 = y2;
}

void	draw_vertical_line(window_data *screen, line_data *line, int dy)
{
	while (dy > 0)
	{
		mlx_pixel_put(screen->mlx, screen->window, line->x1, line->y1 + dy, 0x00FFFFFF);
		dy--;
	}
}

void	draw_horizontal_line(window_data *screen, line_data *line, int dx)
{
	while (dx > 0)
	{
		mlx_pixel_put(screen->mlx, screen->window, line->x1 + dx, line->y1, 0x00FFFFFF);
		dx--;
	}
}

void	draw_line(window_data *screen, line_data *line)
{
	int	dx;
	int dy;
	float	e;
	float	d;
	int y;
	int	x;
	int flag;


	flag = 0;
	if (abs(line->x1 - line->x2) < abs(line->y1 - line->y2))
	{
		swap(line->x1, line->x2);
		swap(line->y1, line->y2);
		flag = 1;
	}
	// if (line->x1 > line->x2)
	// {
	// 	swap(line->x1, line->x2);
	// 	swap(line->y1, line->y2);
	// }
	dx = line->x2 - line->x1;
	dy = line->y2 - line->y1;
	if (dx == 0)
		draw_vertical_line(screen, line, dy);
	if (dy == 0)
		draw_horizontal_line(screen, line, dx);
	y = line->y1;
	x = line->x1;
	d = abs(dy) * 2;
	e = 0;
	while (x <= line->x2)
	{
		if (flag)
			mlx_pixel_put(screen->mlx, screen->window, y, x, 0x00FFFFFF);
		else
			mlx_pixel_put(screen->mlx, screen->window, x, y, 0x00FFFFFF);
		e += d;
		if (e > dx)
		{
			y += line->y2 > line->y1 ? 1 : -1;
			e -= dx * 2;
		}
		x++;
	}
}