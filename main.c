#include <mlx.h>

void	draw_line(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2)
{

}

int main(void)
{
	void *mlx;
	void *window;
	int		x1;
	int		x2;
	int		y1;
	int		y2;
	int		dx;
	int		dy;
	int		m;
	int		j;
	int		e;
	int		i;

	x1 = 20;
	x2 = 380;
	y1 = 20;
	y2 = 380;
	mlx = mlx_init();
	window = mlx_new_window(mlx, 400, 400, "Screen");
	mlx_pixel_put(mlx, window, 20, 20, 0x00FFFFFF); 
	mlx_pixel_put(mlx, window, 21, 20, 0x00FFFFFF);
	mlx_pixel_put(mlx, window, 20, 21, 0x00FFFFFF);
	mlx_pixel_put(mlx, window, 21, 21, 0x00FFFFFF);
	mlx_string_put(mlx, window, 100, 100, 0x00FFFFFF, "Torrey");
	//pt1 = (x1, y1)
	//pt2 = (x2, y2)
	dx = x2 - x1;
	dy = y2 - y1;
	m = dy / dx;
	j = y1;
	e = m - 1;
	i = x1;
	while (x1 < x2 - 1)
	{
		mlx_pixel_put(mlx, window, i, j, 0x00FFFFFF);
		if (e >= 0)
		{
			j += 1;
			e -= 1.0;
		}
		i += 1;
		e += m;
	}
	mlx_loop(mlx);
	return (0);
}
