#include "fractol.h"

static	int	check_fractal_set(t_complex *z, t_complex *c, t_fractal *fractal)
{
	int	i;

	i = 0;
	if (!ft_strncmp(fractal->name, "mandelbrot", 10))
	{
		rescale_and_set(c, c, fractal);
		i = mandelbrot(*z, *c, fractal->iteration_count,
				fractal->escape_value);
	}
	else if (!ft_strncmp(fractal->name, "julia", 5))
	{
		rescale_and_set(z, c, fractal);
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
		i = julia(*z, *c, fractal->iteration_count, fractal->escape_value);
	}
	return (i);
}

static	void	handle_pixel(int x, int y, t_fractal *fractal)
{
    t_complex	z;
    t_complex	c;
    int			i;

    i = 0;
    c.x = x;
    c.y = y;
    i = check_fractal_set(&z, &c, fractal);
    if (i < fractal->iteration_count)
        paint_pixel(x, y, &fractal->img,
            rescale(i, COLOR_DEEP_NAVY,
                COLOR_MAJESTIC_BLUE,
                fractal->iteration_count));
    else
        paint_pixel(x, y, &fractal->img, COLOR_POWDER_SHIMMER);
}

void	fractal_render(t_fractal *fractal)
{
    int	x;
    int	y;
    static int zoom_frame = 0;

    if (zoom_frame++ % 5 == 0) 
    {
        if (fractal->is_zooming_in)
            fractal->zoom *= 1.01;
        if (fractal->is_zooming_out)
            fractal->zoom *= 0.99;
    }

    if (fractal->img.img_ptr)
        mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
    fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection,
            WIDTH, HEIGHT);
    fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,
            &fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
    y = -1;
    while (++y < HEIGHT)
    {
        x = -1;
        while (++x < WIDTH)
            handle_pixel(x, y, fractal);
    }
    mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window,
        fractal->img.img_ptr, 0, 0);
}
