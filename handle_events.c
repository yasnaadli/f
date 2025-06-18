/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamohamm <yasnaadli21@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:37:45 by yamohamm          #+#    #+#             */
/*   Updated: 2025/06/18 10:23:19 by yamohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

int	key_handler(int keycode, t_fractal *fractal)
{
	if (keycode == KEY_ESC)
		close_handler(fractal);
	if (keycode == KEY_LEFT)
		fractal->offset_x -= (0.5 * fractal->zoom);
	else if (keycode == KEY_RIGHT)
		fractal->offset_x += (0.5 * fractal->zoom);
	else if (keycode == KEY_UP)
		fractal->offset_y += (0.5 * fractal->zoom);
	else if (keycode == KEY_DOWN)
		fractal->offset_y -= (0.5 * fractal->zoom);
	else if (keycode == KEY_ASTERISK)
	{
		fractal->iteration_count += 10;
		if (fractal->iteration_count > 1000)
			fractal->iteration_count = 1000;
	}
	else if (keycode == KEY_MINUS)
	{
		fractal->iteration_count -= 10;
		if (fractal->iteration_count < 20)
			fractal->iteration_count = 20;
	}
	fractal_render(fractal);
	return (0);
}

static void	update_zoom_and_iterations(int button, t_fractal *fractal)
{
	double	zoom_factor;

	if (button == 4)
	{
		zoom_factor = 0.8;
		fractal->iteration_count += 5;
		if (fractal->iteration_count > 1000)
			fractal->iteration_count = 1000;
	}
	else if (button == 5)
	{
		zoom_factor = 1.2;
		fractal->iteration_count -= 5;
		if (fractal->iteration_count < 42)
			fractal->iteration_count = 42;
	}
	else
		return ;
	fractal->zoom *= zoom_factor;
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	double	old_zoom;
	double	mouse_re_before_zoom;
	double	mouse_im_before_zoom;

	old_zoom = fractal->zoom;
	mouse_re_before_zoom = (rescale(x, -2.0, 2.0, WIDTH) * old_zoom) \
+ fractal->offset_x;
	mouse_im_before_zoom = (rescale(y, 2.0, -2.0, HEIGHT) * old_zoom) \
+ fractal->offset_y;
	update_zoom_and_iterations(button, fractal);
	fractal->offset_x = mouse_re_before_zoom - \
(rescale(x, -2.0, 2.0, WIDTH) * fractal->zoom);
	fractal->offset_y = mouse_im_before_zoom - \
(rescale(y, 2.0, -2.0, HEIGHT) * fractal->zoom);
	fractal_render(fractal);
	return (0);
}
