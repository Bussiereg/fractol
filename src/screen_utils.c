/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:14:29 by gbussier          #+#    #+#             */
/*   Updated: 2023/05/31 17:14:28 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	screen_init(t_fractol *fractol)
{
	fractol->mandelbrot = 0;
	fractol->julia = 0;
	fractol->xmin = -2;
	fractol->xmax = 2;
	fractol->ymin = -2;
	fractol->ymax = 2;
}

void	effective_zoom(double ydelta, t_mouse_zoom pos, t_fractol *fractol)
{
	if (ydelta > 0)
	{
		mlx_delete_image(fractol->mlx, fractol->image);
		fractol->xmin = fractol->xmin + ((pos.increment_x) * pos.left);
		fractol->xmax = fractol->xmax - ((pos.increment_x) * pos.right);
		fractol->ymin = fractol->ymin + ((pos.increment_y) * pos.down);
		fractol->ymax = fractol->ymax - ((pos.increment_y) * pos.up);
	}
	else
	{
		mlx_delete_image(fractol->mlx, fractol->image);
		fractol->xmin = fractol->xmin - (pos.increment_x) * pos.left;
		fractol->xmax = fractol->xmax + (pos.increment_x) * pos.right;
		fractol->ymin = fractol->ymin - (pos.increment_y) * pos.down;
		fractol->ymax = fractol->ymax + (pos.increment_y) * pos.up;
	}
}

void	screen_zoom(t_fractol *fractol, double ydelta)
{
	t_mouse_zoom	pos;
	mlx_image_t		*img;

	img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	if (!img)
		ft_kill(fractol->mlx, fractol->image, fractol, "Error mlx new image");
	mlx_get_mouse_pos(fractol->mlx, &(fractol->x_p_mos), &(fractol->y_p_mos));
	pos.increment_x = (fractol->xmax - fractol->xmin) * 0.2;
	pos.increment_y = (fractol->ymax - fractol->ymin) * 0.2;
	pos.up = (double)(fractol->y_p_mos) / (double)HEIGHT;
	pos.down = ((double)(HEIGHT - fractol->y_p_mos) / (double)HEIGHT);
	pos.left = (double)(fractol->x_p_mos) / (double)WIDTH;
	pos.right = ((double)(WIDTH - fractol->x_p_mos) / (double)WIDTH);
	effective_zoom(ydelta, pos, fractol);
	fractol->image = img;
	if ((mlx_image_to_window(fractol->mlx, fractol->image, 0, 0) < 0))
		ft_kill(fractol->mlx, fractol->image, fractol, "Error mlx img to win");
}
