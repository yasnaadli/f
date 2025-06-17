/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_logic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamohamm <yasnaadli21@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:36:30 by yamohamm          #+#    #+#             */
/*   Updated: 2025/06/17 14:34:40 by yamohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_complex z, t_complex c, int max_iter, double escape)
{
	int		i;
	double	x2;
	double	y2;

	i = 0;
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
	return (max_iter);
}

int	julia(t_complex z, t_complex c, int max_iter, double escape)
{
	int		i;
	double	x2;
	double	y2;

	i = 0;
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
	return (max_iter);
}
