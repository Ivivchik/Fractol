/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 20:34:04 by hkuhic            #+#    #+#             */
/*   Updated: 2019/09/27 21:19:47 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	burnindship_init(t_fractol *fr)
{
	fr->max_iteration = 100;
	fr->zoom = 300;
	fr->x1 = -2.7;
	fr->y1 = -1.7;
	fr->x = 0;
	fr->y = 0;
	fr->color = 255;
	fr->interation = 0;
}

void	calculate_coor_for_burningship(t_fractol *fr)
{
	while (fr->z.re * fr->z.re + fr->z.im * fr->z.im <= 4 &&
		fr->interation < fr->max_iteration)
	{
		fr->z = complex(fr->z.re * fr->z.re - fr->z.im * fr->z.im + fr->c.re,
		-2 * fabs(fr->z.re * fr->z.im) - fr->c.im);
		fr->interation++;
	}
	if (fr->interation == fr->max_iteration)
		put_pixcel(fr, fr->x, fr->y, 0);
	else
		put_pixcel(fr, fr->x, fr->y, fr->interation * fr->color_fr);
	fr->interation = 0;
}

void	burningship(t_fractol *fr)
{
	while (fr->y < HEIHGT)
	{
		fr->x = 0;
		while (fr->x < WIDTH)
		{
			fr->c = complex(fr->x / fr->zoom + fr->x1,
			fr->y / fr->zoom + fr->y1);
			fr->z = complex(0, 0);
			calculate_coor_for_burningship(fr);
			fr->x++;
		}
		fr->y++;
	}
	fr->y = 0;
	fr->x = 0;
	mlx_put_image_to_window(fr->mlx, fr->win, fr->img, 0, 0);
}
