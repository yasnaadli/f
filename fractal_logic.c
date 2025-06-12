

#include "fractol.h"

int mandelbrot(t_complex z, t_complex c, int max_iter, double escape)
{
    int i = 0;
    double x2, y2; 
    while (i < max_iter)
    {
        x2 = z.x * z.x; 
        y2 = z.y * z.y;
        if (x2 + y2 > escape)
        {
            return (i);
        }
        z.y = 2 * z.x * z.y + c.y;
        z.x = x2 - y2 + c.x;
        i++;
    }
    return max_iter;
}

int julia(t_complex z, t_complex c, int max_iter, double escape)
{
    int i = 0;
    double x2, y2;
    while (i < max_iter)
    {
        x2 = z.x * z.x; 
        y2 = z.y * z.y;
        if (x2 + y2 > escape)
        {
            return (i);
        }
        z.y = 2 * z.x * z.y + c.y;
        z.x = x2 - y2 + c.x;
        i++;
    }
    return max_iter;
}

// int	mandelbrot(t_complex z, t_complex c,
// 			int max_iterations, double escape_value)
// {
// 	int		i;
// 	double	zx2;
// 	double	zy2;
// 	double	temp_x;

// 	i = 0;
// 	while (i < max_iterations)
// 	{
// 		zx2 = z.x * z.x;
// 		zy2 = z.y * z.y;
// 		if (zx2 + zy2 > escape_value)
// 			return (i);
// 		temp_x = (zx2 - zy2);
// 		z.y = 2 * z.x * z.y;
// 		z.x = temp_x;
// 		z.x += c.x;
// 		z.y += c.y;
// 		++i;
// 	}
// 	return (max_iterations);
// }

// int	julia(t_complex z, t_complex c, int max_iterations, double escape_value)
// {
// 	int		i;
// 	double	zx2;
// 	double	zy2;
// 	double	temp_x;

// 	i = 0;
// 	while (i < max_iterations)
// 	{
// 		zx2 = z.x * z.x;
// 		zy2 = z.y * z.y;
// 		if (zx2 + zy2 > escape_value)
// 			return (i);
// 		temp_x = (zx2 - zy2);
// 		z.y = 2 * z.x * z.y;
// 		z.x = temp_x;
// 		z.x += c.x;
// 		z.y += c.y;
// 		++i;
// 	}
// 	return (max_iterations);
// }

