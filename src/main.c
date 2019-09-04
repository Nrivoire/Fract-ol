/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/29 04:56:21 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/04 15:58:24 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void			free_env(t_env *v)
{
	if (v)
	{
		if (v->mlx)
		{
			if (v->mlx->mlx_ptr)
				free(v->mlx->mlx_ptr);
			if (v->mlx->win_ptr)
				free(v->mlx->win_ptr);
			free(v->mlx);
		}
		if (v->img)
		{
			if (v->img->ptr)
				free(v->img->ptr);
			if (v->img->img_tmp)
				free(v->img->img_tmp);
			if (v->img->img)
				free(v->img->img);
			free(v->img);
		}
	}
}

void			refresh_display(t_env *v)
{
	int			i;
	int			j;

	i = -1;
	while (++i < HEIGHT)
	{
		j = -1;
		while (++j < WIDTH)
			ft_pixel_put(v->mlx->img, j, i, 0);
	}
}

void			initialisation(t_env *v)
{
	v->const_real = 0.285;
	v->const_im = 0;
	v->max_i = 100;
	v->gradient_scale = 256;
	v->gradient_shift = 0;
	v->color_lenght = 2048;
	v->frequency = 7.12;
	v->zoom = 1;
	v->x = -2;
	v->y = -2;
	v->j = 0;
}

void			make_mlx_hook(t_env *v)
{
	mlx_hook(v->mlx->win_ptr, 2, 0, key_press, v);
	mlx_key_hook(v->mlx->win_ptr, key_release, v);
	mlx_hook(v->mlx->win_ptr, 6, (1L << 6), motion_notify, v);
	mlx_hook(v->mlx->win_ptr, 4, (1L << 2), button_event, v);
	mlx_hook(v->mlx->win_ptr, 17, (1L << 17), red_cross, v);
	mlx_loop(v->mlx->mlx_ptr);
}

int				main(int av, char **ac)
{
	t_env		*v;

	if (av != 2)
		ft_error("usage: ./fractol [fractal : mandelbrot,julia,burning_ship]");
	if (!(v = ft_memalloc(sizeof(t_env))))
		ft_error("struct t_env ft_memalloc error");
	initialisation(v);
	v->arg = ac[1];
	if (!(v->mlx = ft_memalloc(sizeof(t_mlx))))
		ft_error("struct t_mlx ft_memalloc error");
	v->mlx->mlx_ptr = mlx_init();
	v->mlx->win_ptr = mlx_new_window(v->mlx->mlx_ptr, WIDTH, HEIGHT, "fractol");
	ft_create_img(v->mlx->mlx_ptr, &v->mlx->img, WIDTH, HEIGHT);
	if (ft_strcmp(ac[1], "julia") == 0)
		julia(v);
	else if (ft_strcmp(ac[1], "mandelbrot") == 0)
		mandelbrot(v);
	else if (ft_strcmp(ac[1], "burning_ship") == 0)
		burning_ship(v);
	else
		ft_error("usage: ./fractol [fractal : mandelbrot,julia,burning_ship]");
	make_mlx_hook(v);
	return (0);
}
