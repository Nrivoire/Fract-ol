/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/29 04:56:21 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/07 03:13:24 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

double		mouv_make_julia(t_env *v, double reel, double im, double color)
{
	int			n;
	t_scaling	scale;
	int			max_iteration;

	n = 0;
	max_iteration = 30;
	while (n < max_iteration)
	{
		scale = ft_scaling(reel, im);
		reel = scale.a + v->const_reel;
		im = scale.b + v->const_im;
		if (ft_absolu((reel * reel) + (im * im)) > 16)
			break;
		n++;
	}
	color = ft_map(n, data_mapping(0, max_iteration, 0, 1));
	color = ft_map(sqrt(color), data_mapping(0, 1, 0, 255));
	if (n == max_iteration)
		color = 0;
	return (color);
}

void			mouv_julia(t_env *v)
{
	int			x;
	int			y;
	double		color;
	t_cplx		cplx;

	x = -1;
	ft_create_img(v->mlx->mlx_ptr, &v->mlx->img, WIDTH, HEIGHT);
	while(x++ < HEIGHT)
	{
		y = -1;
		while (y++ < WIDTH)
		{
			cplx = ft_cplx(v, x, y);
			color = make_julia(v, cplx.reel, cplx.im, color);
			ft_pixel_put(v->mlx->img, x, y, make_rgb(color, color, color, 1));
		}
	}
	mlx_put_image_to_window(v->mlx, v->mlx->win_ptr, v->mlx->img.ptr, 0, 0);
}

void			key_mouv_julia(t_env *v, int keycode)
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
	mouv_julia(v);
	mlx_put_image_to_window(v->mlx, v->mlx->win_ptr, v->mlx->img.ptr, 0, 0);
}

int				key_press(int keycode, t_env *v)
{
	if (keycode == ESC)
	{
		//free_env(v);
		exit(0);
	}
	if (keycode)
		v->key[keycode] = 1;
	if (keycode == MORE || keycode == LESS)
		key_mouv_julia(v, keycode);
	return (0);
}

int			key_release(int keycode, t_env *v)
{
	if (keycode)
		v->key[keycode] = 0;
	return (0);
}

int			red_cross()//t_env *v)
{
	//free_env(v);
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
