/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenzel <tmenzel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 20:40:59 by tmenzel           #+#    #+#             */
/*   Updated: 2024/06/20 20:55:38 by tmenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"

# define BLACK   0x000000
# define WHITE   0xFFFFFF
# define RED     0xFF0000
# define GREEN   0x00FF00
# define BLUE    0x0000FF

# define HEIGTH	900
# define WIDTH	900

# define KEY_PLUS	65451
# define KEY_MINUS	65453
# define KEY_LEFT	65361
# define KEY_RIGHT	65363
# define KEY_UP		65362
# define KEY_DOWN	65364
# define KEY_ESCAPE	65307
# define SCROLL_UP		4
# define SCROLL_DOWN	5

# define ERROR_MESSAGE_1 "To compile:\t\"./fractol mandelbrot\"\n"
# define ERROR_MESSAGE_2 "\t\t\"./fractol julia <real_value> <i_value>\"\n"

typedef struct s_complex
{
	double	real;
	double	i;
}	t_complex;

typedef struct s_min_max
{
	double	min;
	double	max;
}	t_min_max;

typedef struct s_data
{
	void	*img_ptr;
	char	*pixel_ptr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_fractol
{
	void	*mlx_connection;
	void	*mlx_window;
	t_data	img;
	char	*name;
	double	zoom;
	double	move_x;
	double	move_y;
	double	julia_real;
	double	julia_i;
}	t_fractol;

void		ft_fractal_initialize(t_fractol *data_fractal);
void		ft_fractal_render(t_fractol *data_fractal);

int			ft_handle_input_key(int inout, t_fractol *data_fractol);
int			ft_handle_input_mouse(int input, t_fractol *data_fractal);
int			ft_handle_input_close(t_fractol *data_fractal);

int			ft_strncmp(char *s1, char *s2, int n);
void		ft_putstr_fd(char *s, int fd);
double		ft_atod(char *str);

double		ft_scale_value(double value,
				t_min_max old, double new_min, double new_max);
t_complex	ft_add_complex(t_complex z1, t_complex z2);
t_complex	ft_square_complex(t_complex z);

#endif