/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   scaling.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/06 04:43:52 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/06 05:02:43 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

t_mapping			data_mapping(double s1, double st1, double s2, double st2)
{
	t_mapping		scale;

	scale.start1 = s1;
	scale.stop1 = st1;
	scale.start2 = s2;
	scale.stop2 = st2;
	return (scale);
}
