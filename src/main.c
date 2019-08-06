/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/29 04:56:21 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/06 04:28:23 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

// int				key_press(int key)//, t_env *v)
// {
// 	if (key == ESC)
// 	{
// 		//free_env(v);
// 		exit(0);
// 	}
// }

int			red_cross()//t_env *v)
{
	//free_env(v);
	exit(0);
	return (0);
}

double		ft_map(double var, double start1, double stop1, double start2, double stop2)
{
	double	result;

	result = start2 + (stop2 - start2) * ((var - start1) / (stop1 - start1));
	return (result);
}

t_cplx		ft_cplx(double x, double y)
{
	t_cplx		cplx;

	cplx.reel = (x * x) - (y * y);
	cplx.im = 2 * x * y;
	return (cplx);
}

double		make_mandel(double a, double b, t_scale tmp, double color)
{
	int			n;
	t_cplx		cplx;
	int			max_iteration;

	n = 0;
	max_iteration = 30;
	while (n < max_iteration)
	{
		cplx = ft_cplx(a, b);
		a = cplx.reel + tmp.a;
		b = cplx.im + tmp.b;
		if (ft_absolu((a * a) + (b * b)) > 16) //est-ce nos cplx se rapprochent de l'infini?
			break;
		n++;
	}
	color = ft_map(n, 0, max_iteration, 0, 1);
	color = ft_map(sqrt(color), 0, 1, 0, 255);
	if (n == max_iteration)
		color = 0;
	return (color);
}

t_scale			ft_make_map(t_env *v, int x, int y)
{
	t_scale		map;

	map.a = ft_map(x, 0, WIDTH, v->min, v->max);
	map.b = ft_map(y, 0, HEIGHT, v->min, v->max);
	return (map);
}

void		mandelbrot(t_env *v)
{
	int			x;
	int			y;
	double		color;
	t_scale		map;

	x = -1;
	ft_create_img(v->mlx->mlx_ptr, &v->mlx->img, WIDTH, HEIGHT);
	while(x++ < HEIGHT)
	{
		y = -1;
		while (y++ < WIDTH)
		{
			map = ft_make_map(v, x, y);
			color = make_mandel(map.a, map.b, map, color);
			ft_pixel_put(v->mlx->img, x, y, make_rgb(color, color, color, 1));
		}
	}
	mlx_put_image_to_window(v->mlx, v->mlx->win_ptr, v->mlx->img.ptr, 0, 0);
}

int				main(int av, char **ac)
{
	t_env		*v;
	int			fd;

	av = 2;
	//if (av != 2)
	//	ft_error("usage : ./fractol sample_fractal");
	fd = open(ac[1], O_RDONLY);
	if (!(v = ft_memalloc(sizeof(t_env))))
		ft_error("struct t_env ft_memalloc error");
	v->min = -2;
	v->max = 2;
	if (!(v->mlx = ft_memalloc(sizeof(t_mlx))))
		ft_error("struct t_mlx ft_memalloc error");
	v->mlx->mlx_ptr = mlx_init();
	v->mlx->win_ptr = mlx_new_window(v->mlx->mlx_ptr, WIDTH, HEIGHT, "fractol");
	mandelbrot(v);
	//mlx_key_hook(v->mlx->win_ptr, key_press, v);
	mlx_hook(v->mlx->win_ptr, 17, (1L << 17), &red_cross, v);
	mlx_loop(v->mlx->mlx_ptr);
	return (0);
}
