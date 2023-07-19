/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:00:28 by gbussier          #+#    #+#             */
/*   Updated: 2023/06/01 14:57:54 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}

double	ft_atod(const char *str)
{
	double	result;
	double	fraction;
	int		sign;

	result = 0.0;
	sign = 1;
	fraction = 0.1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		result = result * 10 + (*str++ - '0');
	if (*str == '.')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result + (*str - '0') * fraction;
		fraction *= 0.1;
		str++;
	}
	return (result * sign);
}

int	check_float(char **argv)
{
	int	i;
	int	j;
	int	check_point;

	i = 2;
	while (i <= 3)
	{
		j = 0;
		check_point = 0;
		if (argv[i][j] == '+' || argv[i][j] == '-')
			j++;
		while (argv[i][j])
		{
			if (argv[i][j] == '.')
				check_point++;
			if ((argv[i][j] >= '0' && argv[i][j] <= '9') || argv[i][j] == '.')
				j++;
			else
				return (0);
			if (check_point > 1)
				return (0);
		}
		i++;
	}
	return (1);
}

void	instruction(void)
{
	ft_printf("The program takes a max of 3 args and a min of 1 arg.\n");
	ft_printf("As 1st arg you need to choose the type of fractal you want.");
	ft_printf(" You can choose between:\n- Mandelbrot\n- Julia\n");
	ft_printf("If you choose Julia, you need to add 2 more args.");
	ft_printf("These args are decimal numbers between -10 and 10.\n");
	exit (EXIT_FAILURE);
}

void	check_arguments(int argc, char **argv)
{
	if (argc <= 1 || argc >= 5 || argc == 3)
		instruction();
	else if (argc == 2 && ft_strcmp(argv[1], "Mandelbrot") != 0)
		instruction();
	else if (argc == 4 && (ft_strcmp(argv[1], "Julia") != 0
			|| check_float(argv) == 0 || (ft_atod(argv[2]) >= 10
				|| ft_atod(argv[2]) <= -10 || ft_atod(argv[3]) >= 10
				|| ft_atod(argv[3]) <= -10)))
		instruction();
}
