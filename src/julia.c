/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   julia.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/06 04:50:23 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/21 15:23:52 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

double		make_julia(t_env *v, double real, double im, double color)
{
	int			n;
	t_scaling	scale;

	n = 0;
	while (n < v->max_i)
	{
		scale = ft_scaling(real, im);
		real = scale.a + v->const_real;
		im = scale.b + v->const_im;
		if (ft_absolu((real * real) + (im * im)) > 100)
			break;
		n++;
	}
	color = ft_map(n, data_mapping(0, v->max_i, 0, 1));
	color = ft_map(sqrt((double)n / v->max_i), data_mapping(0, 1, 0, 255));
	if (n == v->max_i)
		color = 0;
	return (color);
}

void			julia(t_env *v)
{
	int			x;
	int			y;
	double		color;
	t_cplx		cplx;

	x = -1;
	while(x++ < HEIGHT)
	{
		y = -1;
		while (y++ < WIDTH)
		{
			cplx = ft_cplx(v, x, y);
			color = make_julia(v, cplx.real, cplx.im, color);
			ft_pixel_put(v->mlx->img, x, y, color);
		}
	}
	mlx_put_image_to_window(v->mlx, v->mlx->win_ptr, v->mlx->img.ptr, 0, 0);
}
