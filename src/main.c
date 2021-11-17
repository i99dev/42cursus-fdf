/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:05:40 by oal-tena          #+#    #+#             */
/*   Updated: 2021/11/16 14:15:16 by oal-tena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	drwing_length(int key_code, t_vars *vars)
{
	return (0);
}

int	add_shade(int key_code, t_vars *vars)
{
	int	color;
	int	i;
	int	g;

	color = create_trgb(99, 99, 80, 80);
	i = 0;
	while (i < 500)
	{
		mlx_pixel_put(vars->mlx_ptr, vars->win_ptr, i, 250, color);
		i++;
	}
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx_ptr = mlx_init();
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, 640, 480, "Hello World!");
	mlx_key_hook(vars.win_ptr, add_shade, &vars);
	mlx_loop(vars.mlx_ptr);
	return (0);
}
