/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key_event.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/03 17:18:39 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/03 17:36:46 by nrivoire    ###    #+. /#+    ###.fr     */
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

int				key_press(int keycode, t_env *v)
{
	if (keycode == ESC)
	{
		free_env(v);
		exit(0);
	}
	if (keycode)
		v->key[keycode] = 1;
	return (0);
}

int				key_release(int keycode, t_env *v)
{
	if (keycode)
		v->key[keycode] = 0;
	return (0);
}
