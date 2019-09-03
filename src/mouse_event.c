/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mouse_event.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/03 17:20:45 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/03 18:22:30 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void			mouv_julia(t_env *v, int keycode)
{
	double		c;

	if (keycode == MORE)
		c = 0.001;
	else
		c = -0.001;
	v->const_real += c;
	v->const_im += c;
	mlx_clear_window(v->mlx->mlx_ptr, v->mlx->win_ptr);
	ft_create_img(v->mlx->mlx_ptr, &v->mlx->img, WIDTH, HEIGHT);
	julia(v);
	mlx_put_image_to_window(v->mlx, v->mlx->win_ptr, v->mlx->img.ptr, 0, 0);
}

int				motion_notify(int x, int y, t_env *v)
{
	double		real;
	double		im;

	if (x >= 0 && y >= 0 && x <= WIDTH && y <= HEIGHT &&
			ft_strcmp(v->arg, "Julia") == 0)
	{
		real = map(x, data_mapping(0, WIDTH, -2, 2));
		im = map(y, data_mapping(0, HEIGHT, -2, 2));
		v->const_im = im;
		v->const_real = real;
		julia(v);
	}
	return (0);
}

int				zoom_wheel(int button, int x, int y, t_env *v)
{
	double		ratio_x;
	double		ratio_y;
	t_cplx		cplx;
	double		tmp_z;

	ratio_x = (double)x / WIDTH;
	ratio_y = (double)y / HEIGHT;
	cplx = ft_cplx(v, x, y);
	tmp_z = v->zoom;
	if (button == 4 && x >= 0 && x <= WIDTH && y >= 0 && y <= HEIGHT)
		v->zoom *= 2;
	if (button == 5 && x >= 0 && x <= WIDTH && y >= 0 && y <= HEIGHT)
		v->zoom *= 0.5;
	v->zoom = v->zoom < 0.25 ? tmp_z : v->zoom;
	v->x = cplx.real - ratio_x * 4 / v->zoom;
	v->y = cplx.im - ratio_y * 4 / v->zoom;
	mlx_clear_window(v->mlx->mlx_ptr, v->mlx->win_ptr);
	if (v->fractal == 0)
		mandelbrot(v);
	else if (v->fractal == 1)
		julia(v);
	else if (v->fractal == 2)
		burning_ship(v);
	mlx_put_image_to_window(v->mlx, v->mlx->win_ptr, v->mlx->img.ptr, 0, 0);
	return (0);
}
