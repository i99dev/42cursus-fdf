/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 06:22:45 by oal-tena          #+#    #+#             */
/*   Updated: 2021/11/22 11:36:10 by oal-tena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	close_window(key_t key, t_fdf *fdf)
{
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 10, 0xFFFFFF, fdf->filepath);
	if (key == K_ESC)
	{
		ft_putstr_fd(SUCCESS"Goodbye.\n", 1);
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
		exit(0);
	}
	return (0);
}

t_bool	window_init(t_fdf fdf)
{
	fdf.mlx_ptr = mlx_init();
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, \
	HIGH_SCREEN_WIDTH, HIGH_SCREEN_WIDTH, "FDF 3D Maps application");
	mlx_key_hook(fdf.win_ptr, close_window, &fdf);
	mlx_loop(fdf.mlx_ptr);
	if (fdf.mlx_ptr == NULL || fdf.win_ptr == NULL)
		return (false);
	return (true);
}
