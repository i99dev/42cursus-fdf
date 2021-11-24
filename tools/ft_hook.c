/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 02:24:00 by oal-tena          #+#    #+#             */
/*   Updated: 2021/11/24 03:36:10 by oal-tena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	close_window(int keycode, t_fdf *fdf)
{
	if (keycode == K_ESC)
	{
		ft_putstr_fd(WARNING"Goodbye.\n", 1);
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
		exit(0);
	}
	return (0);
}

int	rezise_window(int keycode, t_fdf fdf);
