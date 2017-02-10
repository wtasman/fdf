#include "fdf.h"

void	connect_dots(t_pnt	*verti)
{
	t_window	*screen;
	t_line	*line;

	line = init_line();
	screen = make_window();

	//draw star (shows I can draw all lines in all quadrants from all directions)
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

	while (verti != NULL)
	{
		mlx_pixel_put(screen->mlx, screen->window, verti->x * 10, verti->y * 10, 0x00FFFFFF);
		verti = verti->next;
	}

	mlx_loop(screen->mlx);
}