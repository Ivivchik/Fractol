/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 19:21:27 by hkuhic            #+#    #+#             */
/*   Updated: 2019/09/27 21:13:17 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <math.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include <mlx.h>

# define WIDTH 1600
# define HEIHGT 1000
# define THREAD_WIDTH 5;
# define THREAD_NUMBER 100;

typedef struct	s_complex
{
	double		re;
	double		im;
}				t_complex;

typedef	struct	s_fractol
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*imag;
	int			endian;
	int			bpp;
	int			max_iteration;
	int			interation;
	int			color;
	int			x;
	int			y;
	int			size;
	int			y_max;
	int			fract;
	int			color_fr;
	t_complex	k;
	t_complex	l;
	t_complex	m;
	double		x1;
	double		y1;
	double		zoom;
	double		tmp;
	t_complex	z;
	t_complex	c;
}				t_fractol;

t_complex		complex(double re, double im);
void			mandelbrot(t_fractol *fr);
void			calculate_coor_for_mandelbrot(t_fractol *fr);
void			mandelbrot_init(t_fractol *fr);
void			put_pixcel(t_fractol *fr, int x, int y, int color);
void			mlx_win_init(t_fractol *fr);
void			julia(t_fractol *e);
int				key_hook(int keycode, t_fractol *fr);
void			ft_zoom(int x, int y, t_fractol *fr);
void			ft_dezoom(int x, int y, t_fractol *fr);
int				mouse_hook(int mousecode, int x, int y, t_fractol *fr);
int				fract_comp(char **av, t_fractol *fr);
void			fract_init(t_fractol *fr);
void			fract_calc(t_fractol *fr);
void			julia_pthread(t_fractol *fr);
void			calculate_coor_for_julia(t_fractol *fr);
void			init_julia(t_fractol *e);
int				mouse_for_julia(int x, int y, t_fractol *fr);
void			calculate_coor_for_burningship(t_fractol *fr);
void			burnindship_init(t_fractol *fr);
void			burningship(t_fractol *fr);
void			myfractol_init(t_fractol *fr);
void			calculate_coor_for_myfractol(t_fractol *fr);
void			myfractol(t_fractol *fr);
void			gradient(t_fractol *fr);
void			mandelbar_init(t_fractol *fr);
void			calculate_coor_for_mandelbar(t_fractol *fr);
void			mandelbar(t_fractol *fr);

#endif
