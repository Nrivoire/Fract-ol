/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/29 04:56:21 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/29 06:30:09 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

int				key_press(int key)//, t_env *v)
{
	if (key == ESC)
	{
		//free_env(v);
		exit(0);
	}
}

int			red_cross(t_env *v)
{
	//free_env(v);
	exit(0);
	return (0);
}

void			fractol()
{
	//entre -2 et 2 les chiffres se comportent de facons speciales:
	//si on fait une fonction iterative entre deux chiffres entre -2 et 0
	// le resultat sera de plus en plus petit f(x) = x^2 + c

	//un chiffre complex = real(x) + imaginary(y)
	//Madelbrot -> f(x) = x^2 - c if x is between 
	//pour changer la forme, il faut changer les c -> le c represente la structure de la windows qui est par rapport
	// au centre de -2 a 2 que ce soit sur les x (reels) ou les y (imaginaires)
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
	if (!(v->mlx = ft_memalloc(sizeof(t_mlx))))
		ft_error("struct t_mlx ft_memalloc error");
	v->mlx->mlx_ptr = mlx_init();
	v->mlx->win_ptr = mlx_new_window(v->mlx->mlx_ptr, WIDTH, HEIGHT, "fdf");
	//mlx_key_hook(v->mlx->win_ptr, key_press, v);
	mlx_hook(v->mlx->win_ptr, 17, (1L << 17), &red_cross, v);
	mlx_loop(v->mlx->mlx_ptr);
	return (0);
}