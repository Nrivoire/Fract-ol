/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cplx.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/06 04:33:23 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/06 04:33:37 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

t_cplx		ft_cplx(double x, double y)
{
	t_cplx		cplx;

	cplx.reel = (x * x) - (y * y);
	cplx.im = 2 * x * y;
	return (cplx);
}
