/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knikanor <knikanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 20:09:07 by knikanor          #+#    #+#             */
/*   Updated: 2018/04/01 14:47:19 by knikanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_release(int keycode, int x, int y, t_frctl *f)
{
	if (keycode == 1 && f->name != 4 && f->name != 5)
		f->key.mv++;
	if (keycode == 5 && f->name != 4 && f->name != 5)
	{
		f->mouse_sh_x = ((x - 500.0) / 1000.0) * f->zoom;
		f->shift_x = f->shift_x + f->mouse_sh_x;
		f->mouse_sh_y = ((y - 500.0) / 1000.0) * f->zoom;
		f->shift_y = f->shift_y + f->mouse_sh_y;
		f->zoom = f->zoom / 1.1;
		f->shift_x = f->shift_x - ((x - 500.0) / 1000.0) * f->zoom;
		f->shift_y = f->shift_y - ((y - 500.0) / 1000.0) * f->zoom;
	}
	if (keycode == 4 && f->name != 4 && f->name != 5)
	{
		f->mouse_sh_x = ((x - 500.0) / 1000.0) * f->zoom;
		f->shift_x = f->shift_x + f->mouse_sh_x;
		f->mouse_sh_y = ((y - 500.0) / 1000.0) * f->zoom;
		f->shift_y = f->shift_y + f->mouse_sh_y;
		f->zoom = f->zoom * 1.1;
		f->shift_x = f->shift_x - ((x - 500.0) / 1000.0) * f->zoom;
		f->shift_y = f->shift_x - ((y - 500.0) / 1000.0) * f->zoom;
	}
	return (0);
}

int		mouse_move(int x, int y, t_frctl *f)
{
	if (f->key.mv % 2 == 0)
	{
		f->m_x = (x * 1.0 - 1000 / 2) / 1000 + 0.834;
		f->m_y = (y * 1.0 - 1000 / 2) / 1000 + 0.239;
	}
	return (0);
}
