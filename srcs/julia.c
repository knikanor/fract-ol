/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knikanor <knikanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 20:09:07 by knikanor          #+#    #+#             */
/*   Updated: 2018/04/01 15:13:18 by knikanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_formula(int x, int y, t_frctl *f)
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
	while (iter < f->iter_max && (a * a + b * b < 4.0))
	{
		f->tmp = a * a - b * b - f->m_x;
		b = 2 * a * b + f->m_y;
		a = f->tmp;
		iter++;
	}
	if (iter < f->iter_max)
		put_pixel_to_img(f, x, y, color_mix(iter, f));
	else
		put_pixel_to_img(f, x, y, 0);
}

void	julia(t_frctl *f)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x <= f->win_w)
	{
		while (y <= f->win_h)
		{
			julia_formula(x, y, f);
			y++;
		}
		x++;
		y = 0;
	}
}
