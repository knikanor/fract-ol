/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sieprinski_triangle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knikanor <knikanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 20:09:07 by knikanor          #+#    #+#             */
/*   Updated: 2018/04/01 15:03:10 by knikanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_serp		trngl(t_point p1, t_point p2, t_point p3)
{
	t_serp	tr;

	tr.p1 = p1;
	tr.p2 = p2;
	tr.p3 = p3;
	return (tr);
}

t_point		median(t_point p1, t_point p2)
{
	t_point		m;

	m.x = round((p1.x + p2.x) / 2);
	m.y = round((p1.y + p2.y) / 2);
	return (m);
}

void		draw_serp(int iter, t_serp tr, t_frctl *f)
{
	t_serp	m;

	if (iter > 0)
	{
		m = trngl(median(tr.p1, tr.p2), median(tr.p2, tr.p3),
										median(tr.p3, tr.p1));
		plotline_miami(f, tr.p1, tr.p2);
		plotline_miami(f, tr.p1, tr.p3);
		plotline_miami(f, tr.p3, tr.p2);
		plotline_miami(f, m.p1, m.p2);
		plotline_miami(f, m.p1, m.p3);
		plotline_miami(f, m.p3, m.p2);
		draw_serp(iter - 1, trngl(tr.p1, m.p1, m.p3), f);
		draw_serp(iter - 1, trngl(tr.p2, m.p2, m.p1), f);
		draw_serp(iter - 1, trngl(tr.p3, m.p3, m.p2), f);
	}
}

void		sierpinski_triangle(t_frctl *f)
{
	t_point		p1;
	t_point		p2;
	t_point		p3;

	p1 = new_point(((0.0) * f->win_h * f->key_zoom) / 4 + (f->win_w / 2) -
			((f->shift_x / f->iter_max * 3) * f->win_w * f->key_zoom) / 4,
			((-0.5) * f->win_h * f->key_zoom) / 4 + (f->win_h / 2) -
			((f->shift_y / f->iter_max * 3) * f->win_h * f->key_zoom) / 4);
	p2 = new_point(((-0.5) * f->win_w * f->key_zoom) / 4 + (f->win_w / 2) -
			((f->shift_x / f->iter_max * 3) * f->win_w * f->key_zoom) / 4,
			((0.5) * f->win_h * f->key_zoom) / 4 + (f->win_h / 2) -
			((f->shift_y / f->iter_max * 3) * f->win_h * f->key_zoom) / 4);
	p3 = new_point(((0.5) * f->win_w * f->key_zoom) / 4 + (f->win_w / 2) -
			((f->shift_x / f->iter_max * 3) * f->win_w * f->key_zoom) / 4,
			((0.5) * f->win_h * f->key_zoom) / 4 + (f->win_h / 2) -
			((f->shift_y / f->iter_max * 3) * f->win_h * f->key_zoom) / 4);
	draw_serp(f->iter_max / 4, trngl(p1, p2, p3), f);
}
