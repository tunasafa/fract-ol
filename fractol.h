/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stuna <stuna@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:19:25 by stuna             #+#    #+#             */
/*   Updated: 2024/03/04 16:39:34 by stuna            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <math.h>
# include <unistd.h>

typedef struct params
{
	mlx_image_t	*g_img;
	mlx_t		*mlx;
	double		x_min;
	double		x_max;
	double		y_min;
	double		y_max;
	uint32_t	x;
	uint32_t	y;
	double		cx;
	double		cy;
	char		type;
}	t_params;

# define MAX_ITERATIONS 500

void		my_scrollhook(double xdelta, double ydelta, void *param);
void		zoom_in(t_params *m);
void		zoom_out(t_params *m);
t_params	inti_mandel(char **argv);
void		render(t_params m, double zoom);
void		mlx_put_pixel(mlx_image_t *image, uint32_t x,
				uint32_t y, uint32_t color);
int			mandelbrot(double x, double y);
int			julia(double x, double y, double cx, double cy);
void		key_press(mlx_key_data_t keydata, void *param);
void		error_message(char *s, char *t);
void		input_errors(int argc, char **argv);
void		setup_errors(t_params *m);
size_t		ft_strlen(const char *str);
int			ft_strcmp(char *s1, char *s2);
double		ft_atod(char *str);
int			burning_ship(double x, double y);

#endif
