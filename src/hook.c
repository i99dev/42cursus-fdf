/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:40:28 by oal-tena          #+#    #+#             */
/*   Updated: 2022/01/03 13:10:17 by oal-tena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	close_windowa(int key, t_fdf *fdf)
{
	if (key == ESCAPE_KEY)
	{
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	}
	exit(0);
}

void	regsiter_hooks(t_fdf *fdf)
{
	mlx_key_hook(fdf->win_ptr, close_windowa, fdf);
}