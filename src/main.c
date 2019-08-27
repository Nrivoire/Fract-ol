/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/29 04:56:21 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/27 11:33:51 by nrivoire    ###    #+. /#+    ###.fr     */
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
	v->const_real += c;
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
		v->max_i = 100;
	mlx_clear_window(v->mlx->mlx_ptr, v->mlx->win_ptr);
	ft_create_img(v->mlx->mlx_ptr, &v->mlx->img, WIDTH, HEIGHT);
	julia(v);
	mlx_put_image_to_window(v->mlx, v->mlx->win_ptr, v->mlx->img.ptr, 0, 0);
}

void			change_color(t_env *v, int keycode)
{
	if (keycode == NB_1)
		v->frequency += 0.1;
	else
		v->frequency -= .01;
	if (v->fractal == 0)
		mandelbrot(v);
	else if (v->fractal == 1)
		julia(v);
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
	if ((keycode == MORE && ft_strcmp(v->arg, "Julia") == 0) || 
			(keycode == LESS && ft_strcmp(v->arg, "Julia") == 0))
		mouv_julia(v, keycode);
	if ((keycode == I && ft_strcmp(v->arg, "Julia") == 0) || 
			(keycode == O && ft_strcmp(v->arg, "Julia") == 0))
		more_iteration(v, keycode);
	if (keycode == NB_1 || keycode == NB_2)
		change_color(v, keycode);
	return (0);
}

void		refresh_display(t_env *v)
{
	int		i;
	int		j;

	i = -1;
	while (++i < HEIGHT)
	{
		j = -1;
		while (++j < WIDTH)
			ft_pixel_put(v->mlx->img, j, i, 0);
	}
}

int				key_release(int keycode, t_env *v)
{
	if (keycode)
		v->key[keycode] = 0;
	return (0);
}

int				red_cross(t_env *v)
{
	free_env(v);
	exit(0);
	return (0);
}

int				motion_notify(int x, int y, t_env *v)
{
	double		real;
	double		im;

	if (x >= 0 && y >= 0 && x <= WIDTH && y <= HEIGHT && 
			ft_strcmp(v->arg, "Julia") == 0)
	{
		real = ft_map(x, data_mapping(0, WIDTH, -2, 2));
		im = ft_map(y, data_mapping(0, HEIGHT, -2, 2));
		v->const_im = im;
		v->const_real = real;
		julia(v);
	}
	return (0);
}

void			initialisation(t_env *v)
{
	v->min = -2;
	v->max = 2;
	v->const_real = 0.285;
	v->const_im = 0;
	v->max_i = 100;
	v->gradient_scale = 256;
	v->gradient_shift = 0;
	v->color_lenght = 2048;
	v->frequency = 7.12;
}

int				main(int av, char **ac)
{
	t_env		*v;
	int			fd;

	if (av != 2)
		ft_error("usage : ./fractol [fractal : Mandelbrot , Julia, Burning_ship]");
	fd = open(ac[1], O_RDONLY);
	if (!(v = ft_memalloc(sizeof(t_env))))
		ft_error("struct t_env ft_memalloc error");
	initialisation(v);
	v->arg = ac[1];
	if (!(v->mlx = ft_memalloc(sizeof(t_mlx))))
		ft_error("struct t_mlx ft_memalloc error");
	v->mlx->mlx_ptr = mlx_init();
	v->mlx->win_ptr = mlx_new_window(v->mlx->mlx_ptr, WIDTH, HEIGHT, "fractol");
	ft_create_img(v->mlx->mlx_ptr, &v->mlx->img, WIDTH, HEIGHT);
	if (ft_strcmp(ac[1], "Julia") == 0)
		julia(v);
	else if (ft_strcmp(ac[1], "Mandelbrot") == 0)
		mandelbrot(v);
	else if (ft_strcmp(ac[1], "Burning_ship") == 0)
		burning_ship(v);
	else
		ft_error("usage : ./fractol [fractal : Mandelbrot , Julia, Burning_ship]");
	mlx_hook(v->mlx->win_ptr, 2, 0, key_press, v);
	mlx_key_hook(v->mlx->win_ptr, key_release, v);
	mlx_hook(v->mlx->win_ptr, 6, (1L<<6), motion_notify, v);
	mlx_hook(v->mlx->win_ptr, 17, (1L << 17), red_cross, v);
	mlx_loop(v->mlx->mlx_ptr);
	return (0);
}
