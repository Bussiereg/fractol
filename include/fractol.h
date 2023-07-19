/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:39:11 by gbussier          #+#    #+#             */
/*   Updated: 2023/06/01 14:58:39 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <unistd.h>
# include "libft.h"
# include "MLX42.h"
# define ITERATION 250
# define WIDTH 500
# define HEIGHT 500


typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

typedef struct mouse_zoom_s
{
	double	up;
	double	down;
	double	left;
	double	right;
	double	increment_x;
	double	increment_y;
}	t_mouse_zoom;

typedef struct fractol_s
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	t_complex	julia_const;
	double		xmin;
	double		xmax;
	double		ymin;
	double		ymax;
	int			mandelbrot;
	int			julia;
	int32_t		x_p_mos;
	int32_t		y_p_mos;
}	t_fractol;

// zoom & screen
void		screen_init(t_fractol *fractol);
void		screen_zoom(t_fractol *fractol, double ydelta);

// Mandelbrot
int			diverge_complex(t_complex nb_complex);
void		ft_mandelbrot(t_fractol fractol);

// Julia
void		ft_julia(t_fractol fractol);

// Fractol_utils
t_complex	give_point_to_plan(int abs, int ord, t_fractol fractol);
int			diverge_complex(t_complex nb_complex);
t_complex	ft_mult_cpx(t_complex a, t_complex b);
t_complex	ft_add_cpx(t_complex a, t_complex b);
int			fractol_init(char **argv, t_fractol *fractol);

// hook_utils

void		win_close(void *param);
void		my_scrollhook(double xdelta, double ydelta, void *param);
void		my_keyhook(mlx_key_data_t keydata, void *param);
void		ft_kill(mlx_t *mlx, mlx_image_t *img,
				t_fractol *fractol, char *str);

// Check_utils

void		check_arguments(int argc, char **argv);
int			ft_strcmp(const char *str1, const char *str2);
double		ft_atod(const char *str);
void		instruction(void);

#endif
