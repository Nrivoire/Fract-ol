/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/03 18:19:21 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/03 18:19:22 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

t_mapping		data_mapping(double s1, double st1, double s2, double st2)
{
	t_mapping	map;

	map.start1 = s1;
	map.stop1 = st1;
	map.start2 = s2;
	map.stop2 = st2;
	return (map);
}

double			map(double var, t_mapping s)
{
	double		result;

	result = s.start2 + (s.stop2 - s.start2) * ((var - s.start1) /
			(s.stop1 - s.start1));
	return (result);
}
