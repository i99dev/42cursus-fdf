/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 06:22:45 by oal-tena          #+#    #+#             */
/*   Updated: 2021/12/12 10:05:44 by oal-tena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	data_init(t_fdf *fdf)
{
	ft_read_file(fdf, &fdf->img);
}

/**
 * @brief register the event for the window to add your event.
 * 
 * @param fdf its pointer to the fdf struct
 * @return int 
 */
void	registered_hook(t_fdf *fdf)
{
	ft_putstr_fd(SUCCESS"Hook registered.\n"END, 1);
	hook_windoes_layout(fdf);
	mlx_key_hook(fdf->win_ptr, close_window, fdf);
}

/**
 * @brief init windoes for project and rutern false if there any error.
 * 
 * @param fdf 
 * @return t_bool 
 */
t_bool	window_init(t_fdf fdf)
{
	fdf.mlx_ptr = mlx_init();
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, \
	SCREEN_WIDTH, SCREEN_HEIGHT, "FDF 3D Maps application");
	if (fdf.mlx_ptr == NULL || fdf.win_ptr == NULL)
		return (false);
	registered_hook(&fdf);
	data_init(&fdf);
	mlx_put_image_to_window(fdf.mlx_ptr, fdf.win_ptr, fdf.img.img_ptr, 450, 25);
	mlx_loop(fdf.mlx_ptr);
	return (true);
}
