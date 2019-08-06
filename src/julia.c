/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   julia.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/06 04:50:23 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/06 05:04:47 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

double		make_julia(double a, double b, t_scaling tmp, double color)
{
	int			n;
	t_cplx		cplx;
	int			max_iteration;

	n = 0;
	max_iteration = 30;
	while (n < max_iteration)
	{
		cplx = ft_cplx(a, b);
		a = cplx.reel + (-0.8);
		b = cplx.im + 0.156;
		if (ft_absolu((a * a) + (b * b)) > 16) //est-ce nos cplx se rapprochent de l'infini?
			break;
		n++;
	}
	color = ft_map(n, data_mapping(0, max_iteration, 0, 1));
	color = ft_map(sqrt(color), data_mapping(0, 1, 0, 255));
	if (n == max_iteration)
		color = 0;
	return (color);
}

void			julia(t_env *v)
{
	int			x;
	int			y;
	double		color;
	t_scaling	map;

	x = -1;
	ft_create_img(v->mlx->mlx_ptr, &v->mlx->img, WIDTH, HEIGHT);
	while(x++ < HEIGHT)
	{
		y = -1;
		while (y++ < WIDTH)
		{
			map = ft_scaling(v, x, y);
			color = make_julia(map.a, map.b, map, color);
			ft_pixel_put(v->mlx->img, x, y, make_rgb(color, color, color, 1));
		}
	}
	mlx_put_image_to_window(v->mlx, v->mlx->win_ptr, v->mlx->img.ptr, 0, 0);
}
