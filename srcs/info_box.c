/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_box.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knikanor <knikanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 20:09:07 by knikanor          #+#    #+#             */
/*   Updated: 2018/04/01 16:02:45 by knikanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		string_put(char *str, int a, int b, t_frctl *f)
{
	mlx_string_put(f->mlx, f->win, a * 10, b * 15, 0x778899, str);
}

void			fractol_name(t_frctl *f)
{
	if (f->name == 1)
		string_put("This is the Mandelbrot set", 2, 0, f);
	if (f->name == 2)
	{
		string_put("This is the Julia set", 2, 0, f);
		string_put("Press left mouse button to catch the moment", 2, 1, f);
	}
	if (f->name == 3)
		string_put("This is the 5th power Mandelbrot set", 2, 0, f);
	if (f->name == 4)
		string_put("This is Koch Snowflake", 2, 0, f);
	if (f->name == 5)
		string_put("This is Sierpinski Triangle", 2, 0, f);
	if (f->name == 6)
		string_put("This is Biomorph", 2, 0, f);
	if (f->name == 7)
		string_put("This is Burning Ship", 2, 0, f);
	if (f->name == 8)
		string_put("This is Microb", 2, 0, f);
}

void			info_box(t_frctl *f)
{
	char	*str;
	char	*itoa;

	fractol_name(f);
	itoa = ft_itoa((int)(f->zoom * 100.0));
	str = ft_strjoin("How deep is your fractol? ", itoa);
	string_put(str, 2, 2, f);
	free(str);
	free(itoa);
	string_put("Ask Katrin how to change the number of iterations", 2, 3, f);
	itoa = ft_itoa(f->iter_max);
	str = ft_strjoin("Iteration: ", itoa);
	string_put(str, 2, 4, f);
	free(str);
	free(itoa);
	string_put("Zoom                     MOUSE WHEEL", 2, 5, f);
	string_put("Zoom at center           + -", 2, 6, f);
	string_put("Move                     STRINGS", 2, 7, f);
	string_put("Reset default position   BACKSPACE", 2, 8, f);
	string_put("Quit                     ESC", 2, 9, f);
}
