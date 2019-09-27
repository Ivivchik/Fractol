/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 16:17:41 by hkuhic            #+#    #+#             */
/*   Updated: 2019/09/27 20:49:19 by hkuhic           ###   ########.fr       */
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

void		put_pixcel(t_fractol *fr, int x, int y, int color)
{
	if (x < WIDTH && y < HEIHGT)
	{
		color = mlx_get_color_value(fr->mlx, color);
		ft_memcpy(fr->imag + 4 * WIDTH * y + x * 4,
			&color, sizeof(int));
	}
}
