/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 19:18:51 by hkuhic            #+#    #+#             */
/*   Updated: 2019/09/27 21:15:34 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mlx_win_init(t_fractol *fr)
{
	fr->mlx = mlx_init();
	fr->win = mlx_new_window(fr->mlx, WIDTH, HEIHGT, "Fractol");
	fr->img = mlx_new_image(fr->mlx, WIDTH, HEIHGT);
	fr->imag = mlx_get_data_addr(fr->img, &fr->bpp, &fr->size, &fr->endian);
}

int		fract_comp(char **av, t_fractol *fr)
{
	if (ft_strcmp(av[1], "mandelbrot") == 0)
		fr->fract = 1;
	else if (ft_strcmp(av[1], "julia") == 0)
		fr->fract = 2;
	else if (ft_strcmp(av[1], "burningship") == 0)
		fr->fract = 3;
	else if (ft_strcmp(av[1], "myfractol") == 0)
		fr->fract = 4;
	else if (ft_strcmp(av[1], "mandelbar") == 0)
		fr->fract = 5;
	else
		fr->fract = -1;
	return (1);
}

void	fract_init(t_fractol *fr)
{
	if (fr->fract == 1)
		mandelbrot_init(fr);
	else if (fr->fract == 2)
		init_julia(fr);
	else if (fr->fract == 3)
		burnindship_init(fr);
	else if (fr->fract == 4)
		myfractol_init(fr);
	else if (fr->fract == 5)
		mandelbar_init(fr);
	fract_calc(fr);
}

void	fract_calc(t_fractol *fr)
{
	if (fr->fract == 1)
		mandelbrot(fr);
	else if (fr->fract == 2)
		julia(fr);
	else if (fr->fract == 3)
		burningship(fr);
	else if (fr->fract == 4)
		myfractol(fr);
	else if (fr->fract == 5)
		mandelbar(fr);
}

int		main(int ac, char **av)
{
	t_fractol	*fr;

	(void)av;
	if (!(fr = (t_fractol *)malloc(sizeof(t_fractol))))
		return (-1);
	if (ac == 2)
	{
		mlx_win_init(fr);
		fract_comp(av, fr);
		fract_init(fr);
		fract_calc(fr);
		if (fr->fract == -1)
		{
			ft_putstr("Ups, I don't this fractol\n");
			exit(1);
		}
		if (fr->fract == 2)
			mlx_hook(fr->win, 6, 1L << 6, mouse_for_julia, fr);
		mlx_hook(fr->win, 2, 3, key_hook, fr);
		mlx_mouse_hook(fr->win, mouse_hook, fr);
		mlx_loop(fr->mlx);
	}
}
