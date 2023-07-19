/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:49:33 by gbussier          #+#    #+#             */
/*   Updated: 2023/05/31 17:10:14 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int32_t	main(int argc, char **argv)
{
	t_fractol	*fractol;
	mlx_t		*mlx;
	mlx_image_t	*img;

	check_arguments(argc, argv);
	mlx = mlx_init(WIDTH, HEIGHT, "FRACTOL", true);
	if (!mlx)
		ft_kill(mlx, NULL, NULL, "Error initializing MLX");
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_kill(mlx, img, NULL, "Error while initializing a new image");
	fractol = (t_fractol *)malloc(sizeof(*fractol));
	if (!fractol)
		ft_kill(mlx, img, fractol, "Error when mallocking t_fractol");
	fractol->image = img;
	fractol->mlx = mlx;
	screen_init(fractol);
	fractol_init(argv, fractol);
	mlx_scroll_hook(fractol->mlx, &my_scrollhook, fractol);
	mlx_key_hook(fractol->mlx, &my_keyhook, fractol);
	mlx_close_hook(fractol->mlx, &win_close, fractol);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
