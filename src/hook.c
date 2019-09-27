/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 20:00:26 by tglandai          #+#    #+#             */
/*   Updated: 2019/09/27 20:54:51 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_hook(int keycode, t_fractol *fr)
{
	if (keycode == 53)
		exit(1);
	else if (keycode == 69)
		fr->max_iteration += 50;
	else if (keycode == 78)
		fr->max_iteration -= 50;
	else if (keycode == 123)
		fr->x1 += 30 / fr->zoom;
	else if (keycode == 124)
		fr->x1 -= 30 / fr->zoom;
	else if (keycode == 125)
		fr->y1 -= 30 / fr->zoom;
	else if (keycode == 126)
		fr->y1 += 30 / fr->zoom;
	else if (keycode == 49)
		fract_init(fr);
	else if (keycode == 18)
		fr->color = 167;
	else if (keycode == 46)
	{
		srand(time(NULL));
		fr->color_fr = (rand() % (1100000));
	}
	fract_calc(fr);
	return (0);
}

void	ft_zoom(int x, int y, t_fractol *fr)
{
	fr->x1 = (x / fr->zoom + fr->x1) - (x / (fr->zoom * 1.3));
	fr->y1 = (y / fr->zoom + fr->y1) - (y / (fr->zoom * 1.3));
	fr->zoom *= 1.3;
	fr->max_iteration++;
}

void	ft_dezoom(int x, int y, t_fractol *fr)
{
	fr->x1 = (x / fr->zoom + fr->x1) - (x / (fr->zoom / 1.3));
	fr->y1 = (y / fr->zoom + fr->y1) - (y / (fr->zoom / 1.3));
	fr->zoom /= 1.3;
	fr->max_iteration--;
}

int		mouse_for_julia(int x, int y, t_fractol *fr)
{
	if (x < WIDTH && y < HEIHGT)
	{
		if (x < WIDTH / 2 && y < HEIHGT / 2)
			fr->c.re += 0.004;
		if (x > WIDTH / 2 && y < HEIHGT / 2)
			fr->c.re -= 0.004;
		if (x < WIDTH / 2 && y > HEIHGT / 2)
			fr->c.im -= 0.004;
		if (x > WIDTH / 2 && y > HEIHGT / 2)
			fr->c.im -= 0.004;
		fract_calc(fr);
	}
	return (0);
}

int		mouse_hook(int mousecode, int x, int y, t_fractol *fr)
{
	if (mousecode == 4)
		ft_zoom(x, y, fr);
	else if (mousecode == 5)
		ft_dezoom(x, y, fr);
	fract_calc(fr);
	return (0);
}
