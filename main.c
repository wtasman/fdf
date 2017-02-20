#include "fdf.h"
#include <stdio.h>

void	init_map(t_map *map)
{
	map->width = 0;
	map->height = 0;
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		t_map	*map;
		t_pnt	*verti;

		map = (t_map *)malloc(sizeof(t_map));
		init_map(map);
		verti = read_map(map, argv[1]);
		connect_dots(verti, map);
	}
	else
		write(1, "usage: ./fdf map_file.fdf", 25);
	return (0);
}

/*int	main()
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

	//draw shapes
	draw_rect(screen, 50, 50, 100, 900);
	draw_circle(screen, 500, 500, 250);
	draw_triangle(screen, 100, 100, 900, 100, 900, 900);

	mlx_loop(screen->mlx);
	return(0);
}*/