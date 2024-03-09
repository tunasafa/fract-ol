/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stuna <stuna@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:17:16 by stuna             #+#    #+#             */
/*   Updated: 2024/03/06 12:59:55 by stuna            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_params	inti_mandel(char **argv)
{
	t_params	m;

	m.x_min = -4;
	m.x_max = 4;
	m.y_min = -3;
	m.y_max = 3;
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
		m.type = 'm';
	else if (ft_strcmp(argv[1], "julia") == 0)
	{
		m.type = 'j';
		m.cx = ft_atod(argv[2]);
		m.cy = ft_atod(argv[3]);
	}
	else
		m.type = 's';
	return (m);
}

static unsigned int	calculate_color(int iterations)
{
	unsigned int	color;
	double			t;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	if (iterations < MAX_ITERATIONS)
	{
		t = (double)iterations / MAX_ITERATIONS;
		r = (unsigned char)(255 * t);
		g = (unsigned char)(255 * t);
		b = (unsigned char)(128 * (1 - t));
		color = (r << 28) | (g << 16) | b;
	}
	else
		color = 0x000764;
	return (color);
}

static void	render_temp(t_params *m, double zoom)
{
	double			temp_x;
	double			temp_y;
	unsigned int	color;
	int				iterations;

	while (m->x < m->g_img->width)
	{
		temp_x = m->x_min + (m->x / (double)m->g_img->width)
			* (m->x_max - m->x_min) * zoom;
		temp_y = m->y_min + (m->y / (double)m->g_img->height)
			* (m->y_max - m->y_min) * zoom;
		if (m->type == 'j')
			iterations = julia(temp_x, temp_y, m->cx, m->cy);
		else if (m->type == 'm')
			iterations = mandelbrot(temp_x, temp_y);
		else
			iterations = burning_ship(temp_x, temp_y);
		color = calculate_color(iterations);
		mlx_put_pixel(m->g_img, m->x, m->y, color);
		m->x++;
	}
}

void	render(t_params m, double zoom)
{
	m.y = 0;
	while (m.y < m.g_img->height)
	{
		m.x = 0;
		render_temp(&m, zoom);
		m.y++;
	}
}

int	main(int argc, char **argv)
{
	t_params	m;

	input_errors(argc, argv);
	m = inti_mandel(argv);
	m.mlx = mlx_init(800, 600, "FRACTOL", false);
	m.g_img = mlx_new_image(m.mlx, 800, 600);
	render(m, 1);
	mlx_image_to_window(m.mlx, m.g_img, 0, 0);
	mlx_scroll_hook(m.mlx, &my_scrollhook, &m);
	mlx_key_hook(m.mlx, key_press, &m);
	mlx_loop(m.mlx);
	mlx_delete_image(m.mlx, m.g_img);
	mlx_terminate(m.mlx);
	return (EXIT_SUCCESS);
}
