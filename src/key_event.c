/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key_event.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/03 17:18:39 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/04 15:02:19 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

int				red_cross(t_env *v)
{
	free_env(v);
	exit(0);
	return (0);
}

void			more_iteration(int keycode, t_env *v)
{
	if (keycode == MORE)
		v->max_i += 20;
	else if (v->max_i > 20)
		v->max_i -= 20;
	if (v->fractal == 0)
		mandelbrot(v);
	else if (v->fractal == 1)
		julia(v);
	else if (v->fractal == 2)
		burning_ship(v);
}

int				key_press(int keycode, t_env *v)
{
	if (keycode == ESC)
	{
		free_env(v);
		exit(0);
	}
	if (keycode)
		v->key[keycode] = 1;
	if (keycode == MORE || keycode == LESS)
		more_iteration(keycode, v);
	return (0);
}

int				key_release(int keycode, t_env *v)
{
	if (keycode)
		v->key[keycode] = 0;
	return (0);
}
