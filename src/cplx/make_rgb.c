/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   make_rgb.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/29 07:04:46 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/29 07:04:55 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

t_rgb	make_rgb(int r, int g, int b, int a)
{
	t_rgb	content;

	content.r = r;
	content.g = g;
	content.b = b;
	content.a = a;
	return (content);
}
