/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractol.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/29 04:56:43 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/21 16:17:21 by nrivoire    ###    #+. /#+    ###.fr     */
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
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>

# define KEYPRESS					2
# define KEYRELEASE					3
# define BUTTONPRESS				4
# define BUTTONRELEASE				5
# define MOTIONNOTIFY				6
# define ENTERNOTIFY				7
# define LEAVENOTIFY				8
# define FOCUSIN					9
# define FOCUSOUT					10
# define KEYMAPNOTIFY				11
# define EXPOSE						12
# define GRAPHICSEXPOSE				13
# define NOEXPOSE					14
# define VISIBILITYNOTIFY			15
# define CREATENOTIFY				16
# define DESTROYNOTIFY				17
# define UNMAPNOTIFY				18
# define MAPNOTIFY					19
# define MAPREQUEST					20
# define REPARENTNOTIFY				21
# define CONFIGURENOTIFY			22
# define CONFIGUREREQUEST			23
# define GRAVITYNOTIFY				24
# define RESIZEREQUEST				25
# define CIRCULATENOTIFY			26
# define CIRCULATEREQUEST			27
# define PROPERTYNOTIFY				28
# define SELECTIONCLEAR				29
# define SELECTIONREQUEST			30
# define SELECTIONNOTIFY			31
# define COLORMAPNOTIFY				32
# define CLIENTMESSAGE				33
# define MAPPINGNOTIFY				34
# define LASTEVENTS					35
# define NOEVENTMASK				0L
# define KEYPRESSMASK				(1L<<0)
# define KEYRELEASEMASK				(1L<<1)
# define BUTTONPRESSMASK			(1L<<2)
# define BUTTONRELEASEMASK			(1L<<3)
# define ENTERWINDOWMASK			(1L<<4)
# define LEAVEWINDOWMASK			(1L<<5)
# define POINTERMOTIONMASK			(1L<<6)
# define POINTERMOTIONHINTMASK		(1L<<7)
# define BUTTON1MOTIONMASK			(1L<<8)
# define BUTTON2MOTIONMASK			(1L<<9)
# define BUTTON3MOTIONMASK			(1L<<10)
# define BUTTON4MOTIONMASK			(1L<<11)
# define BUTTON5MOTIONMASK			(1L<<12)
# define BUTTONMOTIONMASK			(1L<<13)
# define KRYMAPSTATEMASK			(1L<<14)
# define EXPOSUREMASK				(1L<<15)
# define VISIBILITYCHANGEMASK		(1L<<16)
# define STRUCTURENOTIFYMASK		(1L<<17)
# define RESIZEREDIRECTMASK			(1L<<18)
# define SUBSTRUCTURENOTIFYMASK		(1L<<19)
# define SUBSTRUCTUREREDIRECTMASK	(1L<<20)
# define FOCUSCHANGEMASK			(1L<<21)
# define PROPERTYCHANGEMASK			(1L<<22)
# define COLORMAPCHANGEMASK			(1L<<23)
# define OWNERGRABBUTTONMASK		(1L<<24)

typedef struct		s_mlx_img
{
	void			*ptr;
	unsigned int	*img;
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

typedef struct		s_mapping
{
	double			start1;
	double			stop1;
	double			start2;
	double			stop2;
}					t_mapping;

typedef	struct		s_cplx
{
	double			real;
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
	double			const_real;
	double			const_im;
	int				key[269];
	int				max_i;
	int				rgb;
	char			*arg;
	t_mlx			*mlx;
	t_mlx_img		*img;
}					t_env;

void				ft_error(char *str);
void				ft_create_img(void *ptr, t_mlx_img *img, int w, int h);
void				ft_pixel_put(t_mlx_img img, int x, int y, int color);
t_scaling			ft_scaling(double x, double y);
t_mapping			data_mapping(double s1, double st1, double s2, double st2);
double				ft_map(double var, t_mapping s);
t_cplx				ft_cplx(t_env *v, int x, int y);

double				make_julia(t_env *v, double a, double b, double color);
void				julia(t_env *v);
void				mandelbrot(t_env *v);

#endif
