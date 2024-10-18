/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenzel <tmenzel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 21:08:15 by tmenzel           #+#    #+#             */
/*   Updated: 2024/06/20 20:43:03 by tmenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractol	data_fractal;

	if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10))
		|| (ac == 4 && !ft_strncmp(av[1], "julia", 5)))
	{
		data_fractal.name = av[1];
		if (ac == 4)
		{
			data_fractal.julia_real = ft_atod(av[2]);
			data_fractal.julia_i = ft_atod(av[3]);
		}
		ft_fractal_initialize(&data_fractal);
		ft_fractal_render(&data_fractal);
		mlx_loop(data_fractal.mlx_connection);
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE_1, STDOUT_FILENO);
		ft_putstr_fd(ERROR_MESSAGE_2, STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
}

/* gcc *.c -Lminilibx-linux -lmlx_Linux -lX11 -lXext -o fractol && ./fractol */
