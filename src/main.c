/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/29 04:56:21 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/08 05:45:50 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void		free_env(t_env *v)
{
	if (v)
	{
		if (v->mlx)
		{
			if (v->mlx->mlx_ptr)
				free(v->mlx->mlx_ptr);
			if (v->mlx->win_ptr)
				free(v->mlx->win_ptr);
			free(v->mlx);
		}
		if (v->img)
		{
			if (v->img->ptr)
				free(v->img->ptr);
			if (v->img->img_tmp)
				free(v->img->img_tmp);
			if (v->img->img)
				free(v->img->img);
			free(v->img);
		}
	}
}

void			mouv_julia(t_env *v, int keycode)
{
	double		c;

	if (keycode == MORE)
		c = 0.001;
	else
		c = -0.001;
	v->const_reel += c;
	v->const_im += c;
	mlx_clear_window(v->mlx->mlx_ptr, v->mlx->win_ptr);
	ft_create_img(v->mlx->mlx_ptr, &v->mlx->img, WIDTH, HEIGHT);
	julia(v);
	mlx_put_image_to_window(v->mlx, v->mlx->win_ptr, v->mlx->img.ptr, 0, 0);
}

void			more_iteration(t_env *v, int keycode)
{
	int			i;

	if (keycode == I)
		i = 20;
	else
		i = -20;
	v->max_i += i;
	if (v->max_i == 0)
		v->max_i = 20;
	mlx_clear_window(v->mlx->mlx_ptr, v->mlx->win_ptr);
	ft_create_img(v->mlx->mlx_ptr, &v->mlx->img, WIDTH, HEIGHT);
	julia(v);
	mlx_put_image_to_window(v->mlx, v->mlx->win_ptr, v->mlx->img.ptr, 0, 0);
}

int				key_press(int keycode, t_env *v)
{
	if (keycode == ESC)
	{
		free_env(v);
		exit(0);
	}
	if (keycode)
		v->key[keycode] = 1;
	if (keycode == MORE || keycode == LESS)
		mouv_julia(v, keycode);
	if (keycode == I || keycode == O)
		more_iteration(v, keycode);
	return (0);
}

int			key_release(int keycode, t_env *v)
{
	if (keycode)
		v->key[keycode] = 0;
	return (0);
}

int			red_cross(t_env *v)
{
	free_env(v);
	exit(0);
	return (0);
}

int				main(int av, char **ac)
{
	t_env		*v;
	int			fd;

	if (av != 2)
		ft_error("usage : ./fractol [fractal : Mandelbrot , Julia]");
	fd = open(ac[1], O_RDONLY);
	if (!(v = ft_memalloc(sizeof(t_env))))
		ft_error("struct t_env ft_memalloc error");
	v->min = -2;
	v->max = 2;
	v->const_reel = -0.4;
	v->const_im = 0.6;
	v->max_i = 100;
	if (!(v->mlx = ft_memalloc(sizeof(t_mlx))))
		ft_error("struct t_mlx ft_memalloc error");
	v->mlx->mlx_ptr = mlx_init();
	v->mlx->win_ptr = mlx_new_window(v->mlx->mlx_ptr, WIDTH, HEIGHT, "fractol");
	if (ft_strcmp(ac[1], "Julia") == 0)
		julia(v);
	else if (ft_strcmp(ac[1], "Mandelbrot") == 0)
		mandelbrot(v);
	else
		ft_error("usage : ./fractol [fractal : Mandelbrot , Julia]");
	mlx_hook(v->mlx->win_ptr, 2, 0, key_press, v);
	mlx_key_hook(v->mlx->win_ptr, key_release, v);
	mlx_hook(v->mlx->win_ptr, 17, (1L << 17), red_cross, v);
	mlx_loop(v->mlx->mlx_ptr);
	return (0);
}
