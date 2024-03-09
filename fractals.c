/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stuna <stuna@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:52:45 by stuna             #+#    #+#             */
/*   Updated: 2024/03/04 12:59:15 by stuna            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	mandelbrot(double x, double y)
{
	int		iterations;
	double	real;
	double	imag;
	double	real_temp;

	iterations = 0;
	real = 0.0;
	imag = 0.0;
	while (iterations < MAX_ITERATIONS && (real * real + imag * imag) < 4.0)
	{
		real_temp = real * real - imag * imag + x;
		imag = 2.0 * real * imag + y;
		real = real_temp;
		iterations++;
	}
	return (iterations);
}

int	julia(double x, double y, double cx, double cy)
{
	int		iterations;
	double	real;
	double	imag;
	double	real_temp;

	real = x;
	imag = -y;
	iterations = 0;
	while (iterations < MAX_ITERATIONS && (real * real + imag * imag) < 4.0)
	{
		real_temp = real * real - imag * imag + cx;
		imag = 2.0 * real * imag + cy;
		real = real_temp;
		iterations++;
	}
	return (iterations);
}

int	burning_ship(double x, double y)
{
	int		iterations;
	double	real;
	double	imag;
	double	real_temp;

	iterations = 0;
	real = x;
	imag = y;
	while (iterations < MAX_ITERATIONS && (real * real + imag * imag) < 4.0)
	{
		real_temp = real * real - imag * imag + x;
		imag = 2.0 * fabs(real * imag) + y;
		real = real_temp;
		iterations++;
	}
	return (iterations);
}
