/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   julia.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/06 04:50:23 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/07 01:11:37 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

double		make_julia(t_env *v, double reel, double im, double color)
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

void			julia(t_env *v)
{
	int			x;
	int			y;
	double		color;
	t_cplx		cplx;

	x = -1;
	v->const_reel = -0.8;
	v->const_im = 0.156;
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
