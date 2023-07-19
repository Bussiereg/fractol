/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:10:20 by gbussier          #+#    #+#             */
/*   Updated: 2023/05/30 13:13:42 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	fractol_init(char **argv, t_fractol *fractol)
{
	t_complex	julia_const;

	if (ft_strcmp(argv[1], "Mandelbrot") == 0)
	{
		fractol->mandelbrot = 1;
		ft_mandelbrot(*fractol);
	}
	else if (ft_strcmp(argv[1], "Julia") == 0)
	{
		fractol->julia = 1;
		julia_const.x = ft_atod(argv[2]);
		julia_const.y = ft_atod(argv[3]);
		fractol->julia_const = julia_const;
		ft_julia(*fractol);
	}
	return (0);
}

int	diverge_complex(t_complex	nb_complex)
{
	if (nb_complex.x >= 2 || nb_complex.y >= 2
		|| nb_complex.x <= -2 || nb_complex.y <= -2)
		return (1);
	return (0);
}

t_complex	give_point_to_plan(int abs, int ord, t_fractol plan)
{
	t_complex	result;
	double		increment_x;
	double		increment_y;

	increment_x = (plan.xmax - plan.xmin) / WIDTH;
	increment_y = (plan.ymax - plan.ymin) / HEIGHT;
	result.x = plan.xmin + (abs * increment_x);
	result.y = plan.ymax - (ord * increment_y);
	return (result);
}

t_complex	ft_add_cpx(t_complex a, t_complex b)
{
	t_complex	added;

	added.x = a.x + b.x;
	added.y = a.y + b.y;
	return (added);
}

t_complex	ft_mult_cpx(t_complex a, t_complex b)
{
	t_complex	mult;

	mult.x = (a.x * b.x) - (a.y * b.y);
	mult.y = (a.x * b.y) + (a.y * b.x);
	return (mult);
}
