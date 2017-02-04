#include "fdf.h"

t_line	*init_line(void)
{
	t_line	*line;

	line = (t_line *)malloc(sizeof(t_line));
	line->x1 = 0;
	line->y1 = 0;
	line->x2 = 0;
	line->y2 = 0;
	line->dx = 0;
	line->dy = 0;
	line->y = 0;
	line->x = 0;
	line->offsetx = 0;
	line->offsety = 0;
	line->error = 0;
	return (line);
}

void	fill_line(t_line *line, int x1, int y1, int x2, int y2)
{
	line->x1 = x1;
	line->y1 = y1;
	line->x2 = x2;
	line->y2 = y2;
	line->dx = abs(x2 - x1);
	line->dy = abs(y2 - y1);
	line->y = y1;
	line->x = x1;
	line->offsetx = x1 > x2 && line->dx != 0 ? -1 : 1;
	line->offsety = y1 > y2 && line->dy != 0 ? -1 : 1;
}

void	draw_right(t_window *screen, t_line *line)
{
	line->error = line->dx / 2;
	while (line->x != line->x2)
	{
		line->error = line->error - line->dy;
		if (line->error < 0)
		{
			line->y = line->y + line->offsety;
			line->error = line->error + line->dx;
		}
		line->x = line->x + line->offsetx;
		mlx_pixel_put(screen->mlx, screen->window, line->x, line->y, 0x00FFFFFF);
	}
}

void	draw_up(t_window *screen, t_line *line)
{
	line->error = line->dy / 2;
	while (line->y != line->y2)
	{
		line->error = line->error - line->dx;
	
		if (line->error < 0)
		{
			line->x = line->x + line->offsetx;
			line->error = line->error + line->dy;
		}
		line->y = line->y + line->offsety;
		mlx_pixel_put(screen->mlx, screen->window, line->x, line->y, 0x00FFFFFF);
	}
}

void	draw_line(t_window *screen, t_line *line)
{
	mlx_pixel_put(screen->mlx, screen->window, line->x, line->y, 0x00FFFFFF);
	if (line->dx > line->dy)
		draw_right(screen, line);
	else if (line->dy > line->dx)
		draw_up(screen, line);
	else if (line->dy == line->dx)
	{
		while (line->x != line->x2)
		{
			line->x += line->offsetx;
			line->y += line->offsety;
			mlx_pixel_put(screen->mlx, screen->window, line->x, line->y, 0x00FFFFFF);
		}
	}
}