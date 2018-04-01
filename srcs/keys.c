/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knikanor <knikanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 20:09:07 by knikanor          #+#    #+#             */
/*   Updated: 2018/04/01 15:05:45 by knikanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_hook_add(t_frctl *f)
{
	if (f->key.up == 1)
		f->shift_y += 0.05;
	if (f->key.down == 1)
		f->shift_y -= 0.05;
	if (f->key.right == 1)
		f->shift_x -= 0.05;
	if (f->key.left == 1)
		f->shift_x += 0.05;
	if (f->key.p_zoom == 1)
		f->key_zoom += 0.1;
	if (f->key.m_zoom == -1)
		f->key_zoom -= 0.1;
	if (f->key_zoom <= 0)
		f->key_zoom = 0.01;
	return (0);
}

int		key_hook(t_frctl *f)
{
	key_hook_add(f);
	if (f->key.iter == 1)
		f->iter_max += 1;
	if (f->key.iter == -1 && f->iter_max > 2)
		f->iter_max -= 1;
	if (f->key.cc == 1)
	{
		if (f->ccr <= 1000)
		{
			f->ccr++;
			f->ccg++;
			f->ccb++;
		}
		else
		{
			f->ccr = 20;
			f->ccg = 1;
			f->ccb = 5;
		}
	}
	return (0);
}

int		key_press_add(int keycode, t_frctl *f)
{
	if (keycode == 126)
		f->key.up = 1;
	if (keycode == 125)
		f->key.down = 1;
	if (keycode == 124)
		f->key.right = 1;
	if (keycode == 123)
		f->key.left = 1;
	if (keycode == 8 && f->key.cc == 1)
		f->key.cc = 0;
	else if (keycode == 8 && f->key.cc == 0)
		f->key.cc = 1;
	return (0);
}

int		key_press(int keycode, t_frctl *f)
{
	key_press_add(keycode, f);
	if (keycode == 24)
		f->key.iter = 1;
	if (keycode == 27)
		f->key.iter = -1;
	if (keycode == 69)
		f->key.p_zoom = 1;
	if (keycode == 78)
		f->key.m_zoom = -1;
	if (keycode == 51)
		default_values(f);
	if (keycode == 53)
	{
		mlx_destroy_window(f->mlx, f->win);
		exit(1);
	}
	return (1);
}

int		key_release(int keycode, t_frctl *f)
{
	if (keycode == 126)
		f->key.up = 0;
	if (keycode == 125)
		f->key.down = 0;
	if (keycode == 124)
		f->key.right = 0;
	if (keycode == 123)
		f->key.left = 0;
	if (keycode == 24)
		f->key.iter = 0;
	if (keycode == 27)
		f->key.iter = 0;
	if (keycode == 69)
		f->key.p_zoom = 0;
	if (keycode == 78)
		f->key.m_zoom = 0;
	return (1);
}
