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
		fractal->iteration_count += 10;
	else if (keycode == KEY_MINUS)
		fractal->iteration_count -= 10;
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (button == 5)
	{
		fractal->zoom *= 0.7;
	}
	else if (button == 4)
	{
		fractal->zoom *= 1.3;
	}
	fractal_render(fractal);
	return (0);
}

// int key_press(int keycode, t_fractal *fractal)
// {
//     if (keycode == MOUSE_UP)
//         fractal->is_zooming_in = 1;
//     else if (keycode == MOUSE_DOWN)
//         fractal->is_zooming_out = 1;
//     return (0);
// }

// int key_release(int keycode, t_fractal *fractal)
// {
//     if (keycode == MOUSE_UP)
//         fractal->is_zooming_in = 0;
//     else if (keycode == MOUSE_DOWN)
//         fractal->is_zooming_out = 0;
//     return (0);
// }

// static void change_color_scheme(int keycode, t_fractal *fractal)
// {
// 	if (keycode == KEY_ONE)
// 	{
// 		fractal->theme_color.outside_min_color = COLOR_DEEP_NAVY;
// 		fractal->theme_color.outside_max_color = COLOR_MAJESTIC_BLUE;
// 		fractal->theme_color.inside_color = COLOR_POWDER_SHIMMER;
// 	}
// 	else if (keycode == KEY_TWO)
// 	{
// 		fractal->theme_color.outside_min_color = COLOR_INDIGO_BLUE;
// 		fractal->theme_color.outside_max_color = COLOR_ELECTRIC_BLUE;
// 		fractal->theme_color.inside_color = COLOR_FROST_BLUE;
// 	}
// 	else if (keycode == KEY_THREE)
// 	{
// 		fractal->theme_color.outside_min_color = COLOR_MAJESTIC_BLUE;
// 		fractal->theme_color.outside_max_color = COLOR_ICY_GLIMMER;
// 		fractal->theme_color.inside_color = COLOR_POWDER_SHIMMER;
// 	}
// 	else if (keycode == KEY_FOUR)
// 	{
// 		fractal->theme_color.outside_min_color = COLOR_COBALT_BLUE;
// 		fractal->theme_color.outside_max_color = COLOR_FROST_BLUE;
// 		fractal->theme_color.inside_color = COLOR_POWDER_SHIMMER;
// 	}
// }


	// else
	// 	change_color_scheme(keycode, fractal);
