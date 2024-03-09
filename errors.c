/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stuna <stuna@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:24:55 by stuna             #+#    #+#             */
/*   Updated: 2024/03/05 17:14:31 by stuna            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_message(char *s, char *t)
{
	write(2, "Error: ", 7);
	if (s)
		write(2, s, ft_strlen(s));
	write(1, "\n", 1);
	if (t)
		write(2, t, ft_strlen(t));
	write(1, "\n", 1);
	exit(EXIT_FAILURE);
}

static void	julia_error(char **argv)
{
	double	num1;
	double	num2;

	num1 = ft_atod(argv[2]);
	num2 = ft_atod(argv[3]);
	if (num1 == -42 || num2 == -42)
		error_message("Invalid form of arguments!",
			"Example: ./fractol julia -0.5  0.5");
	else if (num1 > 2.0 || num1 < -2.0 || num2 > 2.0 || num2 < -2.0)
		error_message("Invalid range for Julia!",
			"Range should be between -2.0 and 2.0");
	else
		return ;
}

void	input_errors(int argc, char **argv)
{
	if (argc < 2)
		error_message("Too few arguments!", 0);
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
	{
		if (argc > 2)
			error_message("Too many arguments!",
				"Input should be: ./fractol mandelbrot");
	}
	else if (ft_strcmp(argv[1], "julia") == 0)
	{
		if (argc != 4)
			error_message("Invalid number of arguments!",
				"Input should be for example: ./fractol julia -0.5 0.5");
		else
			julia_error(argv);
	}
	else if (ft_strcmp(argv[1], "ship") == 0)
	{
		if (argc > 2)
			error_message("Too many arguments!",
				"Input should be: ./fractol ship");
	}
	else
		error_message("Wrong name!  Options: mandelbrot / julia / ship", 0);
}

void	setup_errors(t_params *m)
{
	if (m->mlx == NULL)
		error_message("Could not initialize a new MLX instance", 0);
	if (m->g_img == NULL)
		error_message("Could not allocate new image buffer", 0);
}
