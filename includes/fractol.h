/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knikanor <knikanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 19:55:22 by knikanor          #+#    #+#             */
/*   Updated: 2018/04/01 15:47:33 by knikanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <stdlib.h>

# define END "\033[0;0m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define CYAN "\033[1;36m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;35m"
# define YELLOW "\033[1;33m"
# define H 1000
# define W 1000
# define RAD 57

typedef struct		s_point
{
	int				x;
	int				y;
	int				c;
}					t_point;

typedef struct		s_clr
{
	int				r;
	int				g;
	int				b;
	int				c;
}					t_clr;

typedef struct		s_img
{
	char			*pixel;
	int				bpp;
	int				lin;
	int				endn;
}					t_img;

typedef struct		s_alg
{
	int				dx;
	int				dy;
	int				sign_x;
	int				sign_y;
	int				err;
	int				err2;
}					t_alg;

typedef struct		s_serp
{
	t_point			p1;
	t_point			p2;
	t_point			p3;
}					t_serp;

typedef struct		s_key
{
	int				up;
	int				down;
	int				left;
	int				right;
	int				cc;
	int				iter;
	int				mv;
	int				p_zoom;
	int				m_zoom;
}					t_key;

typedef struct		s_frctl
{
	void			*mlx;
	void			*win;
	void			*img;
	int				win_w;
	int				win_h;
	int				name;
	int				iter_max;
	float			shift_x;
	float			shift_y;
	float			mouse_sh_x;
	float			mouse_sh_y;
	float			zoom;
	float			key_zoom;
	float			m_x;
	float			m_y;
	double			a;
	double			b;
	double			tmp;
	int				ccr;
	int				ccb;
	int				ccg;
	int				nb;
	int				bl;
	int				x;
	int				y;
	int				z;
	t_clr			clr;
	t_key			key;
	t_alg			l;

	char			*argv;

}					t_frctl;

t_frctl				*init_frctl(t_frctl *f, char *str);
t_point				new_point(int x, int y);
int					default_values(t_frctl *f);
void				info_box(t_frctl *f);
int					color_mix(int iter, t_frctl *f);
void				put_pixel_to_img(t_frctl *f, int x, int y, int c);
void				plotline_miami(t_frctl *f, t_point p1, t_point p2);
int					key_hook(t_frctl *f);
int					key_press(int keycode, t_frctl *f);
int					key_release(int keycode, t_frctl *f);
int					mouse_move(int x, int y, t_frctl *f);
int					mouse_release(int x, int y, int keycode, t_frctl *f);
void				julia(t_frctl *f);
void				mandelbrot(t_frctl *f);
void				mandelbrot_x_5(t_frctl *f);
void				koch_snowflake(t_frctl *f);
void				sierpinski_triangle(t_frctl *f);
void				fractol_name(t_frctl *f);
void				burning_ship(t_frctl *f);
void				biomorph(t_frctl *f);
void				microbs(t_frctl *f);

#endif
