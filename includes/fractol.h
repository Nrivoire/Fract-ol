/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractol.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/29 04:56:43 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/07 03:07:36 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 1000
# define HEIGHT 1000
# include "keys.h"
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include "get_next_line.h"
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_mlx_img
{
	void			*ptr;
	char			*img;
	char			*img_tmp;
	int				width;
	int				height;
	int				bpp;
	int				s_l;
	int				endian;
}					t_mlx_img;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_mlx_img		img;
}					t_mlx;

typedef struct		s_rgb
{
	int				r;
	int				g;
	int				b;
	int				a;
}					t_rgb;

typedef struct		s_mapping
{
	double			start1;
	double			stop1;
	double			start2;
	double			stop2;
}					t_mapping;

typedef	struct		s_cplx
{
	double			reel;
	double			im;
}					t_cplx;

typedef struct		s_scaling
{
	double			a;
	double			b;
}					t_scaling;

typedef struct		s_env
{
	double			min;
	double			max;
	double			const_reel;
	double			const_im;
	int				key[269];
	t_mlx			*mlx;
	t_mlx_img		*img;
}					t_env;

int					ft_absolu(int nb);
void				ft_error(char *str);
void				ft_create_img(void *ptr, t_mlx_img *img, int w, int h);
void				ft_pixel_put(t_mlx_img img, int x, int y, t_rgb color);
t_rgb				make_rgb(int r, int g, int b, int a);
t_scaling			ft_scaling(double x, double y);
t_mapping			data_mapping(double s1, double st1, double s2, double st2);
double				ft_map(double var, t_mapping s);
t_cplx				ft_cplx(t_env *v, int x, int y);
double				make_julia(t_env *v, double a, double b, double color);

void				julia(t_env *v);
void				mandelbrot(t_env *v);

#endif
