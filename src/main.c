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
	mlx_pixel_put(vars->mlx_ptr, vars->win_ptr, 100, 50, 14525265);
	mlx_pixel_put(vars->mlx_ptr, vars->win_ptr, 105, 150, 14525265);
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
