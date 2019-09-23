/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 19:18:51 by hkuhic            #+#    #+#             */
/*   Updated: 2019/09/23 20:12:52 by hkuhic           ###   ########.fr       */
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

int		ft_close(void)
{
	exit(1);
	return (0);
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
		if ((fract_comp(av, fr)) == 0)
			return (0);
		fract_init(fr);
		if (fr->fract == 1)
			mlx_hook(fr->win, 6, 1L << 6, mouse_for_julia, fr);
		mlx_hook(fr->win, 17, 0L, ft_close, fr);
		mlx_key_hook(fr->win, key_hook, fr);
		mlx_mouse_hook(fr->win, mouse_hook, fr);
		mlx_loop(fr->mlx);
	}
}
