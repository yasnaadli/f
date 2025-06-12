#include "fractol.h"


static void data_init(t_fractal *fractal)
{
    fractal->escape_value = 9;
    fractal->iteration_count = 500;
    fractal->offset_x = 0.0;
    fractal->offset_y = 0.0;
    fractal->zoom = 1.0;
    fractal->theme_index = 0;
//     fractal->theme_color.outside_min_color = COLOR_DEEP_NAVY;
//     fractal->theme_color.outside_max_color = COLOR_MAJESTIC_BLUE;
//     fractal->theme_color.inside_color = COLOR_POWDER_SHIMMER;  
}

static void mlx_destroy_all(t_fractal *fractal)
{
    mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
    mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
    mlx_destroy_display(fractal->mlx_connection);
    free(fractal->mlx_connection);
}

void fractal_init(t_fractal *fractal)
{
    fractal->mlx_connection = mlx_init();
    if (fractal->mlx_connection == NULL)
    {
        mlx_destroy_all(fractal);
        malloc_error();
    }
    fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH, HEIGHT,
            fractal->name);
    if (fractal->mlx_window == NULL)
    {
        mlx_destroy_all(fractal);
        malloc_error();
    }
    fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection,
            WIDTH, HEIGHT);
    if (fractal->img.img_ptr == NULL)
    {
        mlx_destroy_all(fractal);
        malloc_error();
    }
    fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,
            &fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
    events_init(fractal);
    data_init(fractal);
}