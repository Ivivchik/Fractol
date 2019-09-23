/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 16:17:41 by hkuhic            #+#    #+#             */
/*   Updated: 2019/09/23 18:08:30 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	complex(double re, double im)
{
	t_complex	comp;

	comp.im = im;
	comp.re = re;
	return (comp);
}

void		fract_calc(t_fractol *fr)
{
	if (fr->max_iteration < 0)
		fr->max_iteration = 0;
	if (fr->fract == 0)
		mandelbrot_pthread(fr);
}

void		fract_init(t_fractol *fr)
{
	if (fr->fract == 0)
		mandelbrot_init(fr);
	fract_calc(fr);
}

void		mlx_win_init(t_fractol *fr)
{
	fr->mlx = mlx_init();
	fr->win = mlx_new_window(fr->mlx, WIDTH, HEIHGT, "Fractol");
	fr->img = mlx_new_image(fr->mlx, WIDTH, HEIHGT);
	fr->imag = mlx_get_data_addr(fr->img, &fr->bpp, &fr->size, &fr->endian);
}

int			fract_comp(char **av, t_fractol *fr)
{
	if (ft_strcmp(av[1], "mandelbrot") == 0)
		fr->fract = 0;
	return (1);
}
