/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 11:09:29 by bzmuda            #+#    #+#             */
/*   Updated: 2019/09/27 20:46:49 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_julia(t_fractol *fr)
{
	fr->x = 0;
	fr->y = 0;
	fr->interation = 0;
	fr->x1 = -4;
	fr->y1 = -2.5;
	fr->max_iteration = 100;
	fr->zoom = 200;
	fr->c = complex(-0.5, -0.5);
}

void	exten_julia(t_fractol *fr)
{
	while (fr->z.re * fr->z.re + fr->z.im * fr->z.im <= 4
		&& fr->interation < fr->max_iteration)
	{
		fr->z = complex(fr->z.re * fr->z.re - fr->z.im * fr->z.im + fr->c.re,
		2 * fr->z.im * fr->z.re + fr->c.im);
		fr->interation++;
	}
	if (fr->interation == fr->max_iteration)
		put_pixcel(fr, fr->x, fr->y, 0);
	else
		put_pixcel(fr, fr->x, fr->y, fr->interation * fr->color_fr);
	fr->interation = 50;
}

void	julia(t_fractol *fr)
{
	while (fr->y < HEIHGT)
	{
		fr->x = 0;
		while (fr->x < WIDTH)
		{
			fr->c = complex(fr->c.re, fr->c.im);
			fr->z = complex(fr->x / fr->zoom + fr->x1,
			fr->y / fr->zoom + fr->y1);
			exten_julia(fr);
			fr->x++;
		}
		fr->y++;
	}
	fr->x = 0;
	fr->y = 0;
	mlx_put_image_to_window(fr->mlx, fr->win, fr->img, 0, 0);
}
