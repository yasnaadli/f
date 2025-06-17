/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamohamm <yasnaadli21@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:37:21 by yamohamm          #+#    #+#             */
/*   Updated: 2025/06/17 12:37:24 by yamohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "minilibx/mlx.h"
# include "keys.h"

# define COLOR_THEME_BLACK       0x0A0A1A
# define COLOR_DEEP_NAVY         0x111144
# define COLOR_INDIGO_BLUE       0x222288
# define COLOR_MAJESTIC_BLUE     0x3333AA
# define COLOR_COBALT_BLUE       0x4444CC
# define COLOR_ELECTRIC_BLUE     0x5555FF
# define COLOR_VIVID_SKY         0x7777FF
# define COLOR_FROST_BLUE        0x9999FF
# define COLOR_ICY_GLIMMER       0xBBBBFF
# define COLOR_POWDER_SHIMMER    0xDDDDFF
# define COLOR_SNOWY_HIGHLIGHT   0xEEEEFF
# define COLOR_WHITE_GLINT       0xFFFFFF 

# define WIDTH 800
# define HEIGHT 800

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	double	escape_value;
	int		iteration_count;
	double	offset_x;
	double	offset_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
	int		theme_index;
	int		is_zooming_in;
	int		is_zooming_out;
	double  zoom_speed; 
}	t_fractal;

int	ft_strncmp(const char *s1, const char *s2, size_t n);
int			key_handler(int keycode, t_fractal *fractal);
int			close_handler(t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);
int			mandelbrot(t_complex z, t_complex c,
				int max_iterations, double escape_value);
int			julia(t_complex z, t_complex c,
				int max_iterations, double escape_value);
int			tricorn(t_complex z, t_complex c,
				int max_iterations, double escape_value);

void		ft_putstr_fd(char *str, int fd);
void		malloc_error(void);
void		fractal_init(t_fractal *fractal);
void		fractal_render(t_fractal *fractal);
void		events_init(t_fractal *fractal);
void		paint_pixel(int x, int y, t_img *img, int color);
void		rescale_and_set(t_complex *complex1,
				t_complex *complex2, t_fractal *fractal);

double		ft_atodbl(char *s);
double		rescale(double unscaled_num,
				double new_min, double new_max, double old_max);

#endif
