#include "fractol.h"

void	paint_pixel(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

double	rescale(double unscaled_num, double new_min, double new_max,
			double old_max)
{
	return ((new_max - new_min) * (unscaled_num - 0)
		/ (old_max - 0) + new_min);
}

void	rescale_and_set(t_complex *complex1,
		t_complex *complex2, t_fractal *fractal)
{
	complex1->x = (rescale(complex2->x, -2, 2, WIDTH)
			* fractal->zoom) + fractal->offset_x;
	complex1->y = (rescale(complex2->y, 2, -2, HEIGHT)
			* fractal->zoom) + fractal->offset_y;
}
