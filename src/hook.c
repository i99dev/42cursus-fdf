/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:40:28 by oal-tena          #+#    #+#             */
/*   Updated: 2022/02/07 12:40:03 by oal-tena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	hook(t_fdf *fdf, int key)
{
	if (key == ESCAPE_KEY)
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	else if (key == K_I)
		fdf->x_axis = fdf->x_axis + 0.02;
	else if (key == K_K)
		fdf->x_axis = fdf->x_axis - 0.02;
	else if (key == K_J)
		fdf->y_axis = fdf->y_axis + 0.02;
	else if (key == K_L)
		fdf->y_axis = fdf->y_axis - 0.02;
	else if (key == K_U)
		fdf->z_axis = fdf->z_axis + 0.02;
	else if (key == K_O)
		fdf->z_axis = fdf->z_axis - 0.02;
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 300, 50);
	mlx_destroy_image(fdf->mlx_ptr, fdf->img_ptr);
	create_new_img(fdf);
	put_map_image(fdf);
}

void	regsiter_hooks(t_fdf *fdf)
{
	mlx_key_hook(fdf->win_ptr, hook, fdf);
}
