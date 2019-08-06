/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mandelbrot.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/06 04:31:43 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/06 04:46:19 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

double		make_mandel(double a, double b, t_mapping tmp, double color)
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
	color = ft_map(n, scaling(0, max_iteration, 0, 1));
	color = ft_map(sqrt(color), scaling(0, 1, 0, 255));
	if (n == max_iteration)
		color = 0;
	return (color);
}

t_mapping		ft_make_map(t_env *v, int x, int y)
{
	t_mapping	map;

	map.a = ft_map(x, scaling(0, WIDTH, v->min, v->max));
	map.b = ft_map(y, scaling(0, HEIGHT, v->min, v->max));
	return (map);
}

void		mandelbrot(t_env *v)
{
	int			x;
	int			y;
	double		color;
	t_mapping	map;

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
