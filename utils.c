/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stuna <stuna@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:29:29 by stuna             #+#    #+#             */
/*   Updated: 2024/03/02 12:54:51 by stuna            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != 0 && s2[i] != 0 && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static double	convert_to_double(char *str, int i)
{
	double	number;
	double	div;

	number = 0;
	div = 0.1;
	while (str[i] && ft_isdigit(str[i]) && str[i] != '.')
	{
		number = (number * 10.0) + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		number = number + ((str[i] - '0') * div);
		div *= 0.1;
		i++;
	}
	if (str[i] && !ft_isdigit(str[i]))
		return (-42);
	return (number);
}

double	ft_atod(char *str)
{
	double	number;
	int		negative;
	int		i;

	negative = 1;
	i = 0;
	if (str[i] == '-')
	{
		negative = -1;
		i++;
	}
	number = convert_to_double(str, i);
	if (number == -42)
		return (number);
	return (number * negative);
}
