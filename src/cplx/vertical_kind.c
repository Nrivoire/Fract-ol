/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   vertical_kind.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/29 07:07:49 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/29 07:08:03 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	vertical_kind(t_cplx c1, t_cplx c2, t_env *v, t_rgb color)
{
	double		dy;
	double		dx;
	double		p;
	int			tmp;

	if (c1.im > c2.im)
		swap_cplx(&c1, &c2);
	tmp = c1.im - 1;
	dy = ft_absolu(c2.im - c1.im);
	dx = ft_absolu(c2.reel - c1.reel);
	p = c1.im - (c1.reel * (dy / dx));
	while (++tmp <= c2.im)
		ft_pixel_put(v->mlx->img, (tmp - p) * (dx / dy), tmp, color);
}
