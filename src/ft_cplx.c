/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cplx.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/07 00:59:28 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/08 01:13:25 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

t_cplx		ft_cplx(t_env *v, int x, int y)
{
	t_cplx	cplx;

	cplx.reel = ft_map(x, data_mapping(0, WIDTH, v->min, v->max));
	cplx.im = ft_map(y, data_mapping(0, HEIGHT, v->min, v->max));
	return (cplx);
}
