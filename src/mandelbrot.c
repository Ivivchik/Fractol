/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 19:43:36 by hkuhic            #+#    #+#             */
/*   Updated: 2019/09/23 18:09:35 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixcel(t_fractol *fr, int x, int y, int color)
{
	if (fr->x < WIDTH && fr->y < HEIHGT)
	{
		color = mlx_get_color_value(fr->mlx, color);
		ft_memcpy(fr->imag + 4 * WIDTH * y + x * 4,
			&color, sizeof(int));
	}
}

void	mandelbrot_init(t_fractol *fr)
{
	fr->max_iteration = 50;
	fr->zoom = 100;
	fr->x1 = -2.05;
	fr->y1 = -1.3;
	fr->color = 255;
}

void	calculate_coor_for_mandelbrot(t_fractol *fr)
{
	fr->c = complex(fr->x / fr->zoom + fr->x1, fr->y / fr->zoom + fr->y1);
	fr->z = complex(0, 0);
	fr->interation = 0;
	while (pow(fr->z.re, 2) + pow(fr->z.im, 2) <= 4 &&
		fr->interation < fr->max_iteration)
	{
		fr->z = complex(pow(fr->z.re, 2) - pow(fr->z.im, 2) + fr->c.re,
		2 * fr->z.re * fr->z.im + fr->c.im);
		fr->interation++;
	}
	if (fr->interation == fr->max_iteration)
		put_pixcel(fr, fr->x, fr->y, 0);
	else if (fr->interation < fr->max_iteration / 4)
		put_pixcel(fr, fr->x, fr->y, fr->interation * 11100);
	else if (fr->interation < fr->max_iteration / 2 &&
			fr->interation > fr->max_iteration / 4)
		put_pixcel(fr, fr->x, fr->y, fr->interation * 1110000);
	else
		put_pixcel(fr, fr->x, fr->y, fr->interation * 111000000);
}

void	*mandelbrot(void *tmp)
{
	t_fractol	*fr;
	int			tab;

	fr = (t_fractol *)tmp;
	fr->x = 0;
	tab = fr->y;
	while (fr->x < WIDTH)
	{
		fr->y = tab;
		while (fr->y < fr->y_max)
		{
			calculate_coor_for_mandelbrot(fr);
			fr->y++;
		}
		fr->x++;
	}
	fr->y = 0;
	fr->x = 0;
	return (tmp);
}

void	mandelbrot_pthread(t_fractol *fr)
{
	t_fractol	tab[150];
	pthread_t	t[150];
	int			i;

	i = 0;
	while (i < 150)
	{
		ft_memcpy((void*)&tab[i], (void*)fr, sizeof(t_fractol));
		tab[i].y = 10 * i;
		tab[i].y_max = 10 * (i + 1);
		pthread_create(&t[i], NULL, mandelbrot, &tab[i]);
		i++;
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(fr->mlx, fr->win, fr->img, 0, 0);
}
