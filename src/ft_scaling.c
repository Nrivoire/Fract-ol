/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_scaling.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/06 04:52:31 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/06 05:05:28 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

t_scaling		ft_scaling(t_env *v, int x, int y)
{
	t_scaling	map;

	map.a = ft_map(x, data_mapping(0, WIDTH, v->min, v->max));
	map.b = ft_map(y, data_mapping(0, HEIGHT, v->min, v->max));
	return (map);
}
