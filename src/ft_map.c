/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_map.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/06 04:34:35 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/21 16:22:03 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

t_scaling		ft_scaling(double x, double y)
{
	t_scaling	scale;

	scale.a = x * x - y * y;
	scale.b = 2 * x * y;
	return (scale);
}

t_mapping		data_mapping(double s1, double st1, double s2, double st2)
{
	t_mapping	scale;

	scale.start1 = s1;
	scale.stop1 = st1;
	scale.start2 = s2;
	scale.stop2 = st2;
	return (scale);
}

double			ft_map(double var, t_mapping s)
{
	double		result;

	result = s.start2 + (s.stop2 - s.start2) * ((var - s.start1) /
			(s.stop1 - s.start1));
	return (result);
}
