/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   burning_ship.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/27 11:32:20 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/03 18:18:58 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

int				make_burning_ship(t_env *v, double o_r, double o_i, t_cplx cplx)
{
	int			n;
	double		pos;
	int			color;
	double		new_im;
	double		new_real;

	n = -1;
	new_real = 0;
	new_im = 0;
	while (++n < v->max_i && fabs(new_real * new_real + new_im * new_im) < 16)
	{
		o_r = new_real;
		o_i = new_im;
		new_real = fabs(o_i * o_i - o_r * o_r + cplx.real);
		new_im = fabs(2 * o_r * o_i + cplx.im);
	}
	pos = map(n, data_mapping(0, v->max_i, 0, 1));
	color = map(sqrt(pos), data_mapping(0, 1, 0, 255));
	color = color * v->gradient_scale + v->gradient_shift % v->color_lenght;
	if (n == v->max_i)
		color = 0;
	return (color);
}

void			burning_ship(t_env *v)
{
	int			x;
	int			y;
	int			color;
	t_cplx		cplx;

	x = -1;
	v->fractal = 2;
	refresh_display(v);
	while (x++ < HEIGHT)
	{
		y = -1;
		while (y++ < WIDTH)
		{
			cplx = ft_cplx(v, x, y);
			color = make_burning_ship(v, cplx.real, cplx.im, cplx);
			ft_pixel_put(v->mlx->img, x, y, color);
		}
	}
	mlx_put_image_to_window(v->mlx, v->mlx->win_ptr, v->mlx->img.ptr, 0, 0);
}
