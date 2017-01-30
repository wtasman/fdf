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
	int	w;
	int	h;
	int	dx1;
	int	dy1;
	int	dx2;
	int	dy2;
	int	longest;
	int	shortest;
	int	numerator;
	int	i;

	w = line->x2 - line->x1;
	h = line->y2 - line->y1;
	dx1 = 0;
	dx2 = 0;
	dy1 = 0;
	dy2 = 0;
	dx1 = w < 0 && w != 0 ? -1 : 1;
	dy1 = h < 0 && h != 0 ? -1 : 1;
	dx2 = w < 0 && w != 0 ? -1 : 1;
	longest = abs(w);
	shortest = abs(h);

	if (!(longest > shortest))
	{
		longest = abs(h);
		longest = abs(w);
		if (h < 0)
			dy2 = -1;
		else if (h > 0)
			dy2 = 1;
		dx2 = 0;
	}
	numerator = longest >> 1;
	i = 0;
	while (i <= longest)
	{
		mlx_pixel_put(screen->mlx, screen->window, line->x1, line->y1, 0x00FFFFFF);
		numerator += shortest;
		if (!(numerator < longest))
		{
			numerator -= longest;
			line->x1 += dx1;
			line->y1 += dy1;
		}
		else 
		{
			line->x1 += dx2;
			line->y1 += dy2;
		}
		i++;
	}
}