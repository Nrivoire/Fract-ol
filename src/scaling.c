/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   scaling.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/06 04:43:52 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/06 04:45:17 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

t_scale			scaling(double s1, double st1, double s2, double st2)
{
	t_scale		scale;

	scale.start1 = s1;
	scale.stop1 = st1;
	scale.start2 = s2;
	scale.stop2 = st2;
	return (scale);
}
