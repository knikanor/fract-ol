/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   koch_snowflake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knikanor <knikanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 20:09:07 by knikanor          #+#    #+#             */
/*   Updated: 2018/04/01 15:48:58 by knikanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			segment_recursion(t_frctl *f, int iter, t_point p1, t_point p2)
{
	t_point		l;
	t_point		a;
	t_point		b;
	t_point		tip;
	double		sin_60;

	sin_60 = -0.866025403;
	if (iter == 0)
		plotline_miami(f, p1, p2);
	if (iter >= 1)
	{
		l = new_point((p2.x - p1.x) / 3, (p2.y - p1.y) / 3);
		a = new_point(p1.x + l.x, p1.y + l.y);
		b = new_point(p2.x - l.x, p2.y - l.y);
		tip = new_point(a.x + (int)(l.x * 0.5 + l.y * sin_60),
			a.y + (int)(l.y * 0.5 - l.x * sin_60));
		segment_recursion(f, iter - 1, p1, a);
		segment_recursion(f, iter - 1, a, tip);
		segment_recursion(f, iter - 1, tip, b);
		segment_recursion(f, iter - 1, b, p2);
	}
}

void			koch_snowflake(t_frctl *f)
{
	t_point		p1;
	t_point		p2;
	t_point		p3;

	p1 = new_point(((0.0) * f->win_h * f->key_zoom) / 4 +
			(f->win_w / 2) - (f->shift_x * f->win_w * f->key_zoom) / 4,
			((-0.5) * f->win_h * f->key_zoom) / 4 +
			(f->win_h / 2) - (f->shift_y * f->win_h * f->key_zoom) / 4);
	p2 = new_point(((-0.5) * f->win_w * f->key_zoom) / 4 +
			(f->win_w / 2) - (f->shift_x * f->win_w * f->key_zoom) / 4,
			((0.5) * f->win_h * f->key_zoom) / 4 +
			(f->win_h / 2) - (f->shift_y * f->win_h * f->key_zoom) / 4);
	p3 = new_point(((0.5) * f->win_w * f->key_zoom) / 4 +
			(f->win_w / 2) - (f->shift_x * f->win_w * f->key_zoom) / 4,
			((0.5) * f->win_h * f->key_zoom) / 4 +
			(f->win_h / 2) - (f->shift_y * f->win_h * f->key_zoom) / 4);
	segment_recursion(f, f->iter_max / 10, p1, p2);
	segment_recursion(f, f->iter_max / 10, p2, p3);
	segment_recursion(f, f->iter_max / 10, p3, p1);
}
