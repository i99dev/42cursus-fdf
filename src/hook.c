/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:40:28 by oal-tena          #+#    #+#             */
/*   Updated: 2022/01/08 09:59:42 by oal-tena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"



int	close_windowa(int key, t_fdf *fdf)
{
	if (key == ESCAPE_KEY)
	{
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	}
	else if (key == K_AR_D)
	{
		fdf->move_y += 1;
	}
	else if (key == K_AR_U)
	{
		fdf->move_y -= 1;
	}
	put_map_image(fdf);

}

void	regsiter_hooks(t_fdf *fdf)
{
	mlx_key_hook(fdf->win_ptr, close_windowa, fdf);
}