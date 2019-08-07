/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mandelbrot.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/06 04:31:43 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/07 02:51:50 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

double		make_mandel(double reel, double im, t_cplx cplx, double color)
{
	int			n;
	t_scaling	scale;
	int			max_iteration;

	n = 0;
	max_iteration = 30;
	while (n < max_iteration)
	{
		scale = ft_scaling(reel, im);
		reel = scale.a + cplx.reel;
		im = scale.b + cplx.im;
		if (ft_absolu((reel * reel) + (im * im)) > 16) //est-ce nos cplx se rapprochent de l'infini?
			break;
		n++;
	}
	color = ft_map(n, data_mapping(0, max_iteration, 0, 255));
	color = ft_map(sqrt((float)n / max_iteration), data_mapping(0, 1, 0, 255));
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
	ft_create_img(v->mlx->mlx_ptr, &v->mlx->img, WIDTH, HEIGHT);
	while(x++ < HEIGHT)
	{
		y = -1;
		while (y++ < WIDTH)
		{
			cplx = ft_cplx(v, x, y);
			color = make_mandel(cplx.reel, cplx.im, cplx, color);
			ft_pixel_put(v->mlx->img, x, y, make_rgb(color, color, color, 1));
		}
	}
	mlx_put_image_to_window(v->mlx, v->mlx->win_ptr, v->mlx->img.ptr, 0, 0);
}
