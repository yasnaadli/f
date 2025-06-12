#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if ((argc == 2 && (!ft_strncmp(argv[1], "mandelbrot", 10)))
		|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
	{
		fractal.name = argv[1];
		if (!ft_strncmp(argv[1], "julia", 5))
		{
			fractal.julia_x = ft_atodbl(argv[2]);
			fractal.julia_y = ft_atodbl(argv[3]);
		}
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		ft_putstr_fd("Usage: ./fractol [mandelbrot | julia <x> <y>]\n", STDERR_FILENO);
		return (1);
	}
	return (0);
}
