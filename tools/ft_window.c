/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 06:22:45 by oal-tena          #+#    #+#             */
/*   Updated: 2021/11/24 03:31:55 by oal-tena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/**
 * @brief register the event for the window to add your event.
 * 
 * @param fdf its pointer to the fdf struct
 * @return int 
 */

int	registered_hook(t_fdf *fdf)
{
	ft_putstr_fd(SUCCESS"Hook registered.\n"END, 1);
	mlx_key_hook(fdf->win_ptr, close_window, fdf);
}

t_bool	window_init(t_fdf fdf)
{
	fdf.mlx_ptr = mlx_init();
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, \
	HIGH_SCREEN_WIDTH, HIGH_SCREEN_WIDTH, "FDF 3D Maps application");
	if (fdf.mlx_ptr == NULL || fdf.win_ptr == NULL)
		return (false);
	registered_hook(&fdf);
	mlx_loop(fdf.mlx_ptr);
	return (true);
}
