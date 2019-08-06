/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/29 04:56:21 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/06 04:37:44 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

// int				key_press(int key)//, t_env *v)
// {
// 	if (key == ESC)
// 	{
// 		//free_env(v);
// 		exit(0);
// 	}
// }

int			red_cross()//t_env *v)
{
	//free_env(v);
	exit(0);
	return (0);
}

int				main(int av, char **ac)
{
	t_env		*v;
	int			fd;

	av = 2;
	//if (av != 2)
	//	ft_error("usage : ./fractol sample_fractal");
	fd = open(ac[1], O_RDONLY);
	if (!(v = ft_memalloc(sizeof(t_env))))
		ft_error("struct t_env ft_memalloc error");
	v->min = -2;
	v->max = 2;
	if (!(v->mlx = ft_memalloc(sizeof(t_mlx))))
		ft_error("struct t_mlx ft_memalloc error");
	v->mlx->mlx_ptr = mlx_init();
	v->mlx->win_ptr = mlx_new_window(v->mlx->mlx_ptr, WIDTH, HEIGHT, "fractol");
	mandelbrot(v);
	//mlx_key_hook(v->mlx->win_ptr, key_press, v);
	mlx_hook(v->mlx->win_ptr, 17, (1L << 17), &red_cross, v);
	mlx_loop(v->mlx->mlx_ptr);
	return (0);
}
