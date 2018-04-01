/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knikanor <knikanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 20:09:07 by knikanor          #+#    #+#             */
/*   Updated: 2018/04/01 15:41:34 by knikanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	menu_frctl(void)
{
	ft_putendl(CYAN "\nWhich fractol will you choose?:\n" END);
	ft_putendl(GREEN "usage: ./fractol <number>\n" END);
	ft_putendl(RED "[1] - Mandelbrot" BLUE);
	ft_putendl(YELLOW "[2] - Julia" END);
	ft_putendl(PURPLE "[3] - 5th Power Mandelbrot");
	ft_putendl(CYAN "[4] - Koch Snowflake" END);
	ft_putendl(YELLOW "[5] - Sierpinski_Triangle" END);
	ft_putendl(RED "[6] - Biomorph" END);
	ft_putendl(BLUE "[7] - Burning Ship" END);
	ft_putendl(GREEN "[8] - Microbs\n" END);
	exit(0);
}

void	choose_fractol(char *argv, t_frctl *f)
{
	if (ft_strcmp(&argv[0], "1") == 0)
		f->name = 1;
	if (ft_strcmp(&argv[0], "2") == 0)
		f->name = 2;
	if (ft_strcmp(&argv[0], "3") == 0)
		f->name = 3;
	if (ft_strcmp(&argv[0], "4") == 0)
		f->name = 4;
	if (ft_strcmp(&argv[0], "5") == 0)
		f->name = 5;
	if (ft_strcmp(&argv[0], "6") == 0)
		f->name = 6;
	if (ft_strcmp(&argv[0], "7") == 0)
		f->name = 7;
	if (ft_strcmp(&argv[0], "8") == 0)
		f->name = 8;
}

void	display_fractol(t_frctl *f)
{
	choose_fractol(f->argv, f);
	if (f->name > 0 && f->name < 9)
	{
		if (f->name == 1)
			mandelbrot(f);
		if (f->name == 2)
			julia(f);
		if (f->name == 3)
			mandelbrot_x_5(f);
		if (f->name == 4)
			koch_snowflake(f);
		if (f->name == 5)
			sierpinski_triangle(f);
		if (f->name == 6)
			biomorph(f);
		if (f->name == 7)
			burning_ship(f);
		if (f->name == 8)
			microbs(f);
	}
	else
	{
		menu_frctl();
		exit(0);
	}
}

int		loop_hook(t_frctl *f)
{
	mlx_destroy_image(f->mlx, f->img);
	f->img = mlx_new_image(f->mlx, W, H);
	display_fractol(f);
	mlx_hook(f->win, 2, 1, key_press, f);
	mlx_hook(f->win, 3, 2, key_release, f);
	mlx_hook(f->win, 6, 65, mouse_move, f);
	mlx_mouse_hook(f->win, mouse_release, f);
	key_hook(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	info_box(f);
	return (0);
}

int		main(int argc, char **argv)
{
	t_frctl f;

	if (argc < 2 || argc > 2)
	{
		menu_frctl();
		return (0);
	}
	init_frctl(&f, "Fractol made by Katrin");
	f.argv = ft_strdup(argv[1]);
	mlx_loop_hook(f.mlx, loop_hook, &f);
	mlx_loop(f.mlx);
	return (0);
}
