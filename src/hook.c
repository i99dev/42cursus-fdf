/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:40:28 by oal-tena          #+#    #+#             */
/*   Updated: 2022/02/08 10:20:08 by oal-tena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	re(t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	mlx_destroy_image(fdf->mlx_ptr, fdf->img_ptr);
	create_new_img(fdf);
	put_map_image(fdf);
}

int	zoom(int key, t_fdf *fdf)
{
	if ((key == K_NP_PLU || key == M_SCR_U) && fdf->xy_zoom < 0.55)
		fdf->xy_zoom += 0.01;
	else if (key == K_NP_MIN || key == M_SCR_D)
		fdf->xy_zoom -= 0.01;
	re(fdf);
	return (0);
}

void	z_zoom(int key, t_fdf *fdf)
{
	if (key == K_A)
		fdf->z_zoom += 0.01;
	else if (key == K_B)
		fdf->z_zoom -= 0.01;
	re(fdf);
}

int	hook(int key, t_fdf *fdf)
{
	if (key == ESCAPE_KEY)
		exit(0);
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
	re(fdf);
	zoom(key, fdf);
	z_zoom(key, fdf);
	return (0);
}

void	regsiter_hooks(t_fdf *fdf)
{
	mlx_key_hook(fdf->win_ptr, hook, fdf);
}
