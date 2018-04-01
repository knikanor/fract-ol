/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knikanor <knikanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 20:09:07 by knikanor          #+#    #+#             */
/*   Updated: 2018/04/01 14:27:48 by knikanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		init_keys(t_frctl *f)
{
	f->key.up = 0;
	f->key.down = 0;
	f->key.left = 0;
	f->key.right = 0;
	f->key.iter = 0;
	f->key.cc = 1;
	f->key.p_zoom = 0;
	f->key.m_zoom = 0;
}

t_frctl		*init_frctl(t_frctl *f, char *str)
{
	t_point p;

	f->win_w = W;
	f->win_h = H;
	f->iter_max = 30;
	f->shift_x = 0.0;
	f->shift_y = 0.0;
	f->mouse_sh_x = 0.0;
	f->mouse_sh_y = 0.0;
	f->m_x = 0.35;
	f->m_y = 0.01;
	f->zoom = 5.0;
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, f->win_w, f->win_h, str);
	f->img = mlx_new_image(f->mlx, W, H);
	init_keys(f);
	f->ccr = 20;
	f->ccb = 5;
	f->ccg = 1;
	f->key_zoom = 1;
	p.c = 0x00FF00;
	return (f);
}

int			default_values(t_frctl *f)
{
	f->iter_max = 20;
	f->shift_x = 0.0;
	f->shift_y = 0.0;
	f->mouse_sh_y = 0.0;
	f->mouse_sh_x = 0.0;
	f->m_x = 0.35;
	f->m_y = 0.01;
	f->zoom = 5.0;
	f->key_zoom = 1;
	return (0);
}
