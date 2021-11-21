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
#include <stdlib.h>

int	mouse_hook(int key_code, t_vars *var)
{
	printf("%d\n", key_code);
	printf("%d %d\n", &var->mouse.x, &var->mouse.y);
	if (key_code == M_CLK_R)
	{
		mlx_pixel_put(var->mlx_ptr, var->win_ptr, 100, 50, 14525265);
	}
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx_ptr = mlx_init();
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, HIGH_SCREEN_WIDTH,
			HIGH_SCREEN_HEIGHT, "Hello World!");
	mlx_mouse_hook(vars.win_ptr, &mouse_hook, &vars);
	mlx_loop(vars.mlx_ptr);
	return (0);
}
