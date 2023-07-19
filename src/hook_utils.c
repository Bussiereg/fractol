/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:08:45 by gbussier          #+#    #+#             */
/*   Updated: 2023/05/31 17:08:47 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	if (ydelta)
	{
		screen_zoom((t_fractol *)param, ydelta);
		if (((t_fractol *)param)->mandelbrot == 1)
			ft_mandelbrot(*((t_fractol *)param));
		else if (((t_fractol *)param)->julia == 1)
			ft_julia(*((t_fractol *)param));
	}
	else if (xdelta)
		ft_printf ("Use the vertical scroll in order to zoom");
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		win_close((t_fractol *)param);
}

void	win_close(void *param)
{
	mlx_delete_image(((t_fractol *)param)->mlx, ((t_fractol *)param)->image);
	mlx_terminate(((t_fractol *)param)->mlx);
	free (((t_fractol *)param));
	exit (EXIT_SUCCESS);
}

void	ft_kill(mlx_t *mlx, mlx_image_t *img, t_fractol *fractol, char *str)
{
	if (img)
		mlx_delete_image(mlx, img);
	if (mlx)
		mlx_terminate(mlx);
	if (fractol)
	{
		free (fractol);
	}
	if (errno == 0)
		ft_putendl_fd(str, 2);
	else
		perror(str);
	exit (EXIT_FAILURE);
}
