/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_x_5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knikanor <knikanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 20:09:07 by knikanor          #+#    #+#             */
/*   Updated: 2018/04/01 02:55:39 by knikanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_x_5_formula(int x, int y, t_frctl *f)
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
		f->tmp = (a * a * a * a * a - 10 * b * b * a * a * a +
			5 * b * b * b * b * a + re_z);
		b = 5 * a * a * a * a * b - 10 * b * b * b * a * a +
		b * b * b * b * b + im_z;
		a = f->tmp;
		iter++;
	}
	if (iter < f->iter_max)
		put_pixel_to_img(f, x, y, color_mix(iter, f));
	else
		put_pixel_to_img(f, x, y, 0);
}

void	mandelbrot_x_5(t_frctl *f)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x <= f->win_w)
	{
		while (y <= f->win_h)
		{
			mandelbrot_x_5_formula(x, y, f);
			y++;
		}
		x++;
		y = 0;
	}
}
