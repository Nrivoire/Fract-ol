/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_make_cplx.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/29 07:01:53 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/29 07:02:12 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

t_cplx	ft_make_cplx(double x, double y)
{
	t_cplx		cplx;

	cplx.reel = x;
	cplx.im = y;
	return (cplx);
}
