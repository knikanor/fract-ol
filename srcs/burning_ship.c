/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knikanor <knikanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 20:09:07 by knikanor          #+#    #+#             */
/*   Updated: 2018/04/01 14:53:47 by knikanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		burning_ship_formula(int x, int y, t_frctl *f)
{
	int		iter;
	double	a;
	double	b;
	double	re_z;
	double	im_z;

	iter = 0;
	a = 0.0;
	b = 0.0;
	re_z = ((x - W / 2) * f->zoom) / W + f->shift_x;
	im_z = ((y - H / 2) * f->zoom) / H + f->shift_y;
	while (iter < f->iter_max && (a * a + b * b < 4.0))
	{
		f->tmp = a * a - b * b + re_z;
		b = fabs(2 * a * b) + im_z;
		a = f->tmp;
		iter++;
	}
	if (iter < f->iter_max)
		put_pixel_to_img(f, x, y, color_mix(iter, f));
	else
		put_pixel_to_img(f, x, y, 0);
}

void		burning_ship(t_frctl *f)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x <= W)
	{
		while (y <= H)
		{
			burning_ship_formula(x, y, f);
			y++;
		}
		x++;
		y = 0;
	}
}
