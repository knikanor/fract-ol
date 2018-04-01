/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biomorph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knikanor <knikanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 20:09:07 by knikanor          #+#    #+#             */
/*   Updated: 2018/04/01 15:45:56 by knikanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		biomorph_formula(int x, int y, t_frctl *f)
{
	int		iter;
	double	a;
	double	b;
	double	re_z;
	double	im_z;

	iter = 0;
	re_z = ((x - W / 2) * f->zoom) / W + f->shift_x;
	im_z = ((y - H / 2) * f->zoom) / H + f->shift_y;
	a = re_z;
	b = im_z;
	while (iter < f->iter_max && (a * a < 70.0 && b * b < 70.0))
	{
		f->tmp = a * a * a * a - b * b * b * b - 6 * a * a * a * a + 1;
		b = 4 * a * a * a * b - 4 * a * b * b * b + 1;
		a = f->tmp;
		iter++;
	}
	if (fabs(a) > 10 * f->iter_max / 50 || fabs(b) > 1000 * f->iter_max / 50)
		put_pixel_to_img(f, x, y, color_mix(iter, f) * iter);
	else
		put_pixel_to_img(f, x, y, 0);
}

void		biomorph(t_frctl *f)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x <= f->win_w)
	{
		while (y <= f->win_h)
		{
			biomorph_formula(x, y, f);
			y++;
		}
		x++;
		y = 0;
	}
}
