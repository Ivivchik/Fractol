/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 19:18:51 by hkuhic            #+#    #+#             */
/*   Updated: 2019/09/23 18:10:16 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
		mlx_hook(fr->win, 17, 0L, ft_close, fr);
		mlx_key_hook(fr->win, key_hook, fr);
		mlx_mouse_hook(fr->win, mouse_hook, fr);
		mlx_loop(fr->mlx);
	}
}
