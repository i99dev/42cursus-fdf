/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:05:40 by oal-tena          #+#    #+#             */
/*   Updated: 2021/11/16 14:15:16 by oal-tena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	init_img(t_fdf *fdf)
{
	fdf->x = 0;
	fdf->y = 0;
	fdf->x0 = 0;
	fdf->y0 = 0;
	fdf->x1 = fdf->x0;
	fdf->y1 = fdf->y0;
	fdf->camera = 0;
	fdf->x_shift = 0;
	fdf->y_shift = 0;
	fdf->camera = 0;
	fdf->degree_angle = 30;
	fdf->xy_zoom = 0.5;
	fdf->z_zoom = 0.03;
	fdf->x_axis = 0;
	fdf->y_axis = 0;
	fdf->z_axis = 0;
	fdf->color = 0xff000;
	create_new_img(fdf);
}

void	app_init(char *file_path, t_fdf *fdf)
{
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, \
	SCREEN_WIDTH, SCREEN_HEIGHT, "FDF");
	ft_read_file(file_path, fdf);
	init_img(fdf);
	put_map_image(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 300, 50);
	regsiter_hooks(fdf);
	mlx_loop(fdf->mlx_ptr);
}

int	main(int argv, char **arg)
{
	t_fdf	fdf;

	if (argv == 2)
	{
		app_init(arg[1], &fdf);
		return (0);
	}
	ft_putstr_fd("usage: ./fdf map.fdf\n", 1);
	return (0);

}
