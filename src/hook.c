/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:40:28 by oal-tena          #+#    #+#             */
/*   Updated: 2022/01/09 13:58:20 by oal-tena         ###   ########.fr       */
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
		fdf->move_y += 10;
	}
	else if (key == K_AR_U)
	{
		fdf->move_y -= 10;
	}
	else if ( key == K_A)
	{
		fdf->angle += 0.1;
	}
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 300, 50);
	mlx_destroy_image(fdf->mlx_ptr, fdf->img_ptr);
	create_new_img(fdf);
	put_map_image(fdf);

}

int	rotate_axis(t_fdf *fdf, int key)
{
	if (key == K_B)
		fdf->x_axis += 0.02;
	else if (key == K_N)
		fdf->y_axis += 0.02;
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 300, 50);
	mlx_destroy_image(fdf->mlx_ptr, fdf->img_ptr);
	create_new_img(fdf);
	put_map_image(fdf);
}

void	regsiter_hooks(t_fdf *fdf)
{
	mlx_key_hook(fdf->win_ptr, close_windowa, fdf);
	// mlx_key_hook(fdf->win_ptr, rotate_axis, fdf);

}