/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mandelbrot.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/06 04:31:43 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/27 13:50:11 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

int				make_color(int n, t_env *v)
{
	long		longue;
	int			red;
	int			blue;
	int			green;

	red = sin(v->frequency * (n % 16) + 0) * 127 + 128;
	green = sin(v->frequency * (n % 16) + 2) * 127 + 128;
	blue = sin(v->frequency * (n % 16) + 4) * 127 + 128;
	longue = blue * 65536 + green * 256 + red;
	return (longue);
}

int				make_mandel(t_env *v, double real, double im, t_cplx cplx)
{
	int			n;
	t_scaling	scale;
	int			max_iteration;
	double		pos;
	int			color;

	n = -1;
	max_iteration = 100;
	while (++n < max_iteration)
	{
		scale = ft_scaling(real, im);
		real = scale.a + cplx.real;
		im = scale.b + cplx.im;
		if (ft_absolu((real * real) + (im * im)) > 16)
			break ;
	}
	pos = ft_map(n, data_mapping(0, max_iteration, 0, 1));
	color = ft_map(sqrt(pos), data_mapping(0, 1, 0, 255));
	color = color * v->gradient_scale + v->gradient_shift % v->color_lenght;
	color = make_color(n, v);
	if (n == max_iteration)
		color = 0;
	return (color);
}

void			mandelbrot(t_env *v)
{
	int			x;
	int			y;
	int			color;
	t_cplx		cplx;

	x = -1;
	v->fractal = 0;
	refresh_display(v);
	while (x++ < HEIGHT)
	{
		y = -1;
		while (y++ < WIDTH)
		{
			cplx = ft_cplx(v, x, y);
			color = make_mandel(v, cplx.real, cplx.im, cplx);
			ft_pixel_put(v->mlx->img, x, y, color);
		}
	}
	mlx_put_image_to_window(v->mlx, v->mlx->win_ptr, v->mlx->img.ptr, 0, 0);
}
