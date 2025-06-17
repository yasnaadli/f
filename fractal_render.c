/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamohamm <yasnaadli21@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:36:41 by yamohamm          #+#    #+#             */
/*   Updated: 2025/06/17 14:46:39 by yamohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	fractal_render(t_fractal *f)
{
	int			x;
	int			y;
	static int	zoom_frame = 0;

	if (zoom_frame++ % 5 == 0)
	{
		if (f->is_zooming_in)
			f->zoom *= 1.01;
		if (f->is_zooming_out)
			f->zoom *= 0.99;
	}
	if (f->img.img_ptr)
		mlx_destroy_image(f->mlx_connection, f->img.img_ptr);
	f->img.img_ptr = mlx_new_image(f->mlx_connection, WIDTH, HEIGHT);
	f->img.pixels_ptr = mlx_get_data_addr(f->img.img_ptr,
			&f->img.bpp, &f->img.line_len, &f->img.endian);
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			handle_pixel(x, y, f);
	}
	mlx_put_image_to_window(f->mlx_connection, f->mlx_window,
		f->img.img_ptr, 0, 0);
}
