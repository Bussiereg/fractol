/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: gbussier <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/05/30 13:31:38 by gbussier		  #+#	#+#			 */
/*   Updated: 2023/05/30 13:36:21 by gbussier         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "fractol.h"

void	ft_color_mandelbrot(int abs, int ord, t_fractol fractol)
{
	t_complex	point_z;
	t_complex	point_c;
	int			i;

	i = 1;
	point_z = give_point_to_plan(abs, ord, fractol);
	point_c = point_z;
	while (i < ITERATION)
	{
		point_z = ft_add_cpx(ft_mult_cpx(point_z, point_z), point_c);
		if (diverge_complex(point_z))
		{
			mlx_put_pixel(fractol.image, abs, ord,
				0xFF0000FF - 9 * i * 0x00090100);
			break ;
		}
		i++;
	}
	if (i == ITERATION)
		mlx_put_pixel(fractol.image, abs, ord, 0x000000FF);
}

void	ft_mandelbrot(t_fractol fractol)
{
	int	abs;
	int	ord;

	ord = 0;
	while (ord < HEIGHT)
	{
		abs = 0;
		while ((abs < WIDTH))
		{
			ft_color_mandelbrot(abs, ord, fractol);
			abs++;
		}
		ord++;
	}
}
