#include "fdf.h"
#include <stdio.h>

void	connect_dots(t_pnt	*verti, t_map *map)
{
	t_window	*screen;
	t_line	*line;
	t_pnt	*temp;
	int		i;
	t_pnt	*next_y;

	line = init_line();
	screen = make_window();
	temp = verti;
	
	while (temp->next != NULL)
	{
		if (temp->x < map->width - 1)
		{
			//mlx_pixel_put(screen->mlx, screen->window, temp->x * 10, temp->y * 10, 0x00FFFFFF);
			fill_line(line, temp->x * 10, temp->y * 10, temp->next->x * 10, temp->next->y * 10);
			draw_line(screen, line);
		}
		temp = temp->next;
	}

	temp = verti;
	while (temp->next != NULL)
	{
		if (temp->y < map->height - 1)
		{
			//mlx_pixel_put(screen->mlx, screen->window, temp->x * 10, temp->y * 10, 0x00FFFFFF);
			next_y = temp;
			i = 0;
			while (i < map->width)
			{
				next_y = next_y->next;
				i++;
			}
			fill_line(line, temp->x * 10, temp->y * 10, next_y->x * 10, next_y->y * 10);
			draw_line(screen, line);
		}
		temp = temp->next;
	}



	mlx_loop(screen->mlx);
}

	// //draw star (shows I can draw all lines in all quadrants from all directions)
	// fill_line(line, 200, 500, 500, 500);
	// draw_line(screen, line);
	// fill_line(line, 300, 600, 500, 500);
	// draw_line(screen, line);
	// fill_line(line, 400, 700, 500, 500);
	// draw_line(screen, line);
	// fill_line(line, 500, 800, 500, 500);
	// draw_line(screen, line);
	// fill_line(line, 600, 700, 500, 500);
	// draw_line(screen, line);
	// fill_line(line, 700, 600, 500, 500);
	// draw_line(screen, line);
	// fill_line(line, 800, 500, 500, 500);
	// draw_line(screen, line);
	// fill_line(line, 700, 400, 500, 500);
	//  draw_line(screen, line);
	// fill_line(line, 600, 300, 500, 500);
	// draw_line(screen, line);
	// fill_line(line, 500, 200, 500, 500);
	// draw_line(screen, line);
	// fill_line(line, 400, 300, 500, 500);
	// draw_line(screen, line);
	// fill_line(line, 500, 500, 300, 400);
	// draw_line(screen, line);	
	// fill_line(line, 500, 500, 750, 750);
	// draw_line(screen, line);
	// fill_line(line, 500, 500, 250, 750);
	// draw_line(screen, line);
	// fill_line(line, 500, 500, 250, 250);
	// draw_line(screen, line);
	// fill_line(line, 500, 500, 750, 250);
	// draw_line(screen, line);