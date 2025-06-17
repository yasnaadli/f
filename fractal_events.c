/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamohamm <yasnaadli21@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:36:23 by yamohamm          #+#    #+#             */
/*   Updated: 2025/06/17 12:50:54 by yamohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	events_init(t_fractal *fractal)
{
	mlx_key_hook(fractal->mlx_window, key_handler, fractal);
	mlx_mouse_hook(fractal->mlx_window, mouse_handler, fractal);
	mlx_hook(fractal->mlx_window, EVENT_CLOSE_BTN, 0, close_handler, fractal);
}
