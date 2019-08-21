/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mandelbrot.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/06 04:31:43 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/21 15:23:39 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

double		make_mandel(double real, double im, t_cplx cplx, double color)
{
	int			n;
	t_scaling	scale;
	int			max_iteration;

	n = 0;
	max_iteration = 30;
	while (n < max_iteration)
	{
		scale = ft_scaling(real, im);
		real = scale.a + cplx.real;
		im = scale.b + cplx.im;
		if (ft_absolu((real * real) + (im * im)) > 110)
			break;
		n++;
	}
	color = ft_map(n, data_mapping(0, max_iteration, 0, 1));
	color = ft_map(sqrt(color), data_mapping(0, 1, 0, 255));
	if (n == max_iteration)
		color = 0;
	return (color);
}

void			mandelbrot(t_env *v)
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
			color = make_mandel(cplx.real, cplx.im, cplx, color);
			ft_pixel_put(v->mlx->img, x, y, color);
		}
	}
	mlx_put_image_to_window(v->mlx, v->mlx->win_ptr, v->mlx->img.ptr, 0, 0);
}
