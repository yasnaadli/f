
#include "fractol.h"

void	events_init(t_fractal *fractal)
{
	mlx_key_hook(fractal->mlx_window, key_handler, fractal);
	mlx_mouse_hook(fractal->mlx_window, mouse_handler, fractal);
	mlx_hook(fractal->mlx_window, EVENT_CLOSE_BTN, 0, close_handler, fractal);
}