/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   julia.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/06 04:50:23 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/08 05:40:30 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

// // double		make_julia(t_env *v, double reel, double im, double color)
// // {
// // 	int			n;
// // 	t_scaling	scale;
// // 	int			max_iteration;

// // 	n = 0;
// // 	max_iteration = 100;
// // 	while (n < max_iteration)
// // 	{
// // 		scale = ft_scaling(reel, im);
// // 		if (ft_absolu(reel * reel) + ft_absolu(im * im) > 110)
// // 			break;
// // 		reel = scale.a + 0.285;
// // 		im = scale.b + 0.01;
// // 		n++;
// // 	}
// // 	color = ft_map(n, data_mapping(0, max_iteration, 0, 1));
// // 	color = ft_map(sqrt(color), data_mapping(0, 1, 0, 255));
// // 	if (n == max_iteration)
// // 		color = 0;
// // 	return (color);
// // }

// void			julia(t_env *v)
// {
// 	int 		x;
// 	int 		y;
// 	double		color;
// 	t_cplx		cplx;

// 	y = -1;
// 	ft_create_img(v->mlx->mlx_ptr, &v->mlx->img, WIDTH, HEIGHT);
// 	while(y++ < HEIGHT)
// 	{
// 		x = -1;
// 		while (x++ < WIDTH)
// 		{
// 			double	zoom = 1;
// 			double	moveX = 0;
// 			double	moveY = 0;
// 			double	new_reel = 1.5 * (x - WIDTH / 2) / (0.5 * zoom * WIDTH) + moveX;
// 			double	new_im = (y - HEIGHT / 2) / (0.5 * zoom * HEIGHT) + moveY;

// 			double	c_reel = -0.7;
// 			double	c_im = 0.27015;

// 			int n = -1;
// 			int	max_iteration = 100;
// 			while (++n < max_iteration)
// 			{
// 				double old_reel = new_reel;
// 				double old_im = new_im;
// 				new_reel = old_reel * old_reel - old_im * old_im + c_reel;
// 				new_im = 2 * old_reel * old_im + c_im;
// 				if ((new_reel * new_reel + new_im * new_im) > 4)
// 					break;
// 			}
// 			//cplx = ft_cplx(v, x, y);
// 			//color = make_julia(v, cplx.reel, cplx.im, color);

// 			color = ft_map(n, data_mapping(0, max_iteration, 0, 1));
// 			color = ft_map(sqrt(color), data_mapping(0, 1, 0, 255));
// 			ft_pixel_put(v->mlx->img, x, y, make_rgb(color, color, color, 1));
// 		}
// 	}
// 	mlx_put_image_to_window(v->mlx, v->mlx->win_ptr, v->mlx->img.ptr, 0, 0);
// }

double		make_julia(t_env *v, double reel, double im, double color)
{
	int			n;
	t_scaling	scale;

	n = 0;
	while (n < v->max_i)
	{
		scale = ft_scaling(reel, im);
		reel = scale.a + v->const_reel;
		im = scale.b + v->const_im;
		if (ft_absolu((reel * reel) + (im * im)) > 100)
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
	ft_create_img(v->mlx->mlx_ptr, &v->mlx->img, WIDTH, HEIGHT);
	while(x++ < HEIGHT)
	{
		y = -1;
		while (y++ < WIDTH)
		{
			cplx = ft_cplx(v, x, y);
			color = make_julia(v, cplx.reel, cplx.im, color);
			//ft_pixel_put(v->mlx->img, x, y, make_rgb(color * 16, color * 2, color * 2, 1));
			ft_pixel_put(v->mlx->img, x, y, make_rgb(color, color, color / 16, 1));
			//ft_pixel_put(v->mlx->img, x, y, make_rgb(color * 4, color * 16, color * 4, 1));
			//ft_pixel_put(v->mlx->img, x, y, make_rgb(color * 3, color * 3, color * 16, 1));
		}
	}
	mlx_put_image_to_window(v->mlx, v->mlx->win_ptr, v->mlx->img.ptr, 0, 0);
}
