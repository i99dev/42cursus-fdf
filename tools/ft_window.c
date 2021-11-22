/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 06:22:45 by oal-tena          #+#    #+#             */
/*   Updated: 2021/11/22 06:53:33 by oal-tena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_bool	window_init(t_fdf fdf)
{
	fdf.mlx_ptr = mlx_init();
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, \
	HIGH_SCREEN_WIDTH, HIGH_SCREEN_WIDTH, "Welcome To My App");
	mlx_loop(fdf.mlx_ptr);
	if (fdf.mlx_ptr == NULL || fdf.win_ptr == NULL)
		return (false);
	return (true);
}
