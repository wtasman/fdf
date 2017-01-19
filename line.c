#include "fdf.h"

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

void	draw_line(window_data *screen, line_data *line)
{
	int dx;
	int dy;
	int m;
	int j;
	float e;
	int i;

	dx = line->x2 - line->x1;
	dy = line->y2 - line->y1;
	m = dy / dx;
	j = line->y1;
	e = m - 1;
	i = line->x1;
	while (line->x1 < line->x2 - 1)
	{
		mlx_pixel_put(screen->mlx, screen->window, i, j, 0x00FFFFFF);
		if (e >= 0)
		{
			j += 1;
			e -= 1.0;
		}
		i += 1;
		e += m;
		line->x1++;
	}
}