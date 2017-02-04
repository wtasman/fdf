#include "fdf.h"

void draw_circle(t_window *screen, int x0, int y0, int radius)
{
    int x = radius;
    int y = 0;
    int err = 0;

    while (x >= y)
    {
        mlx_pixel_put(screen->mlx, screen->window, x0 + x, y0 + y, 0x00FFFFFF);
        mlx_pixel_put(screen->mlx, screen->window, x0 + y, y0 + x, 0x00FFFFFF);
        mlx_pixel_put(screen->mlx, screen->window, x0 - y, y0 + x, 0x00FFFFFF);
        mlx_pixel_put(screen->mlx, screen->window, x0 - x, y0 + y, 0x00FFFFFF);
        mlx_pixel_put(screen->mlx, screen->window, x0 - x, y0 - y, 0x00FFFFFF);
        mlx_pixel_put(screen->mlx, screen->window, x0 - y, y0 - x, 0x00FFFFFF);
        mlx_pixel_put(screen->mlx, screen->window, x0 + y, y0 - x, 0x00FFFFFF);
        mlx_pixel_put(screen->mlx, screen->window, x0 + x, y0 - y, 0x00FFFFFF);

        if (err <= 0)
        {
            y += 1;
            err += 2*y + 1;
        }
        if (err > 0)
        {
            x -= 1;
            err -= 2*x + 1;
        }
    }
}