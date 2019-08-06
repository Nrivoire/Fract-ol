/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_mapping.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/06 04:34:35 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/06 04:44:08 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

double		ft_map(double var, t_scale s)
{
	double	result;

	result = s.start2 + (s.stop2 - s.start2) * \
			((var - s.start1) / (s.stop1 - s.start1));
	return (result);
}
