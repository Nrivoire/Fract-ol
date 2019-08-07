/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_scaling.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/07 00:59:37 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/07 01:00:04 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

t_scaling		ft_scaling(double x, double y)
{
	t_scaling	scale;

	scale.a = (x * x) - (y * y);
	scale.b = 2 * x * y;
	return (scale);
}
