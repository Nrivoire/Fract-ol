/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mouse_event.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/03 17:20:45 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/04 15:58:32 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

int			motion_notify(int x, int y, t_env *v)
{
	double	real;
	double	im;

	if (x >= 0 && y >= 0 && x <= WIDTH && y <= HEIGHT &&
			v->fractal == 1 && v->j == 0)
	{
		real = map(x, data_mapping(0, WIDTH, -2, 2));
		im = map(y, data_mapping(0, HEIGHT, -2, 2));
		v->const_im = im;
		v->const_real = real;
		julia(v);
	}
	return (0);
}

void		zoom_wheel(int button, int x, int y, t_env *v)
{
	double	ratio_x;
	double	ratio_y;
	t_cplx	cplx;
	double	tmp_z;

	ratio_x = (double)x / WIDTH;
	ratio_y = (double)y / HEIGHT;
	cplx = ft_cplx(v, x, y);
	tmp_z = v->zoom;
	if (button == 5 && x >= 0 && x <= WIDTH && y >= 0 && y <= HEIGHT)
	{
		v->zoom *= 2;
		v->max_i += 20;
	}
	else if (v->max_i > 40)
	{
		v->zoom *= 0.5;
		v->max_i -= 20;
	}
	v->zoom = v->zoom < 0.25 ? tmp_z : v->zoom;
	v->x = cplx.real - ratio_x * 4 / v->zoom;
	v->y = cplx.im - ratio_y * 4 / v->zoom;
}

int			button_event(int button, int x, int y, t_env *v)
{
	if (button == 2)
		return (0);
	if (button == 4 || button == 5)
		zoom_wheel(button, x, y, v);
	if (button == 1)
		v->j = v->j ? 0 : 1;
	if (v->fractal == 0)
		mandelbrot(v);
	else if (v->fractal == 1)
		julia(v);
	else if (v->fractal == 2)
		burning_ship(v);
	return (0);
}
