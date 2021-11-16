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

int	hook_example(int key_code, t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < 350)
	{
		j = 0;
		while (j < 250)
		{
			mlx_pixel_put(vars->mlx_ptr, vars->win_ptr, i, j, 14525265);
			j++;
		}
		i++;
	}
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx_ptr = mlx_init();
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, 640, 480, "Hello World!");
	mlx_get_color_value(vars.mlx_ptr, 0X00151522);
	mlx_key_hook(vars.win_ptr, hook_example, &vars);
	mlx_loop(vars.mlx_ptr);
	return (0);
}
