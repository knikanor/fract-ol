/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knikanor <knikanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 20:09:07 by knikanor          #+#    #+#             */
/*   Updated: 2018/04/01 15:04:29 by knikanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				color_mix(int iter, t_frctl *f)
{
	int r;
	int g;
	int b;

	g = ((0xFF00FF >> 8) & 0xFF) * f->ccg;
	b = (0x0000FF & 0xFF) * f->ccb;
	r = iter * f->ccr;
	return ((r << 16) + (g << 8) + b);
}

void			put_pixel_to_img(t_frctl *f, int x, int y, int c)
{
	int				bpp;
	int				sl;
	int				en;
	char			*img;
	unsigned int	tmp;

	img = mlx_get_data_addr(f->img, &bpp, &sl, &en);
	tmp = (mlx_get_color_value(f->mlx, c));
	if (x > 0 && x < W && y > 0 && y < H)
		ft_memcpy((void *)((img + y * W * (bpp / 8) + x * (bpp / 8))),
				(void *)&tmp, 4);
}

void			plotline_miami(t_frctl *f, t_point p1, t_point p2)
{
	f->l.sign_x = p1.x < p2.x ? 1 : -1;
	f->l.sign_y = p1.y < p2.y ? 1 : -1;
	f->l.dx = abs(p2.x - p1.x);
	f->l.dy = -abs(p2.y - p1.y);
	f->l.err = f->l.dx + f->l.dy;
	while (p2.y != p1.y || p2.x != p1.x)
	{
		put_pixel_to_img(f, p1.x, p1.y, 0xae30ec + f->ccr);
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		f->l.err2 = 2 * f->l.err;
		if (f->l.err2 > f->l.dy)
		{
			f->l.err = f->l.err + f->l.dy;
			p1.x += f->l.sign_x;
		}
		if (f->l.err2 < f->l.dx)
		{
			f->l.err = f->l.err + f->l.dx;
			p1.y += f->l.sign_y;
		}
	}
}

t_point			new_point(int x, int y)
{
	t_point		p;

	p.x = x;
	p.y = y;
	return (p);
}
