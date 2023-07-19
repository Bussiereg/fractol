/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:21:23 by gbussier          #+#    #+#             */
/*   Updated: 2023/05/31 17:11:37 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_color_julia(int abs, int ord, t_fractol fractol)
{
	t_complex	point_z;
	int			i;

	i = 1;
	point_z = give_point_to_plan(abs, ord, fractol);
	while (i < ITERATION)
	{
		point_z = ft_mult_cpx(point_z, point_z);
		point_z = ft_add_cpx(point_z, fractol.julia_const);
		if (diverge_complex(point_z))
		{
			mlx_put_pixel(fractol.image, abs, ord,
				0xFF0000FF - 5 * i * 0x00090100);
			break ;
		}
		i++;
	}
	if (i == ITERATION)
		mlx_put_pixel(fractol.image, abs, ord, 0xFF0000FF - i * 0x00090100);
}

void	ft_julia(t_fractol fractol)
{
	int	abs;
	int	ord;

	ord = 0;
	while (ord < HEIGHT)
	{
		abs = 0;
		while ((abs < WIDTH))
		{
			ft_color_julia(abs, ord, fractol);
			abs++;
		}
		ord++;
	}
}
