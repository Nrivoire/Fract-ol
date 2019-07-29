/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   horizontal_kind.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/29 07:03:13 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/29 07:04:19 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	horizontal_kind(t_cplx c1, t_cplx c2, t_env *v, t_rgb color)
{
	double		dy;
	double		dx;
	int			tmp;
	double		p;

	if (c1.reel > c2.reel)
		swap_cplx(&c1, &c2);
	tmp = c1.reel - 1;
	dy = ft_absolu(c2.im - c1.im);
	dx = ft_absolu(c2.reel - c1.reel);
	p = c1.im - (c1.reel * (dy / dx));
	while (++tmp <= c2.reel)
		ft_pixel_put(v->mlx->img, tmp, (dy / dx) * tmp + p, color);
}
