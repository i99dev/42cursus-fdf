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

void	create_new_img(t_fdf *fdf)
{
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, fdf->img_width, fdf->img_height);
	fdf->img_data = mlx_get_data_addr(fdf->img_ptr, &fdf->bpp, \
	&fdf->size_line, &fdf->endian);
}

void	init(t_fdf *fdf)
{
	fdf->x = 0;
	fdf->y = 0;
	fdf->x0 = 0;
	fdf->y0 = 0;
	fdf->x1 = fdf->x0;
	fdf->y1 = fdf->y0;
	fdf->x_shift = -250;
	fdf->y_shift = -100;
	fdf->camera = 1;
	fdf->degree_angle = 50;
	fdf->xy_zoom = 0.4;
	fdf->z_zoom = 0.04;
	fdf->x_axis = 0;
	fdf->y_axis = 0;
	fdf->z_axis = 0;
	fdf->color = 0xff000;
    fdf->img_width= 800;
    fdf->img_height= 400;
	create_new_img(fdf);
}

int	app_init(char *file_path)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	if (fdf == NULL)
		return (0);
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, \
	SCREEN_WIDTH, SCREEN_HEIGHT, "FDF");
	ft_read_file(file_path, fdf);
	init(fdf);
	put_map_image(fdf);
	regsiter_hooks(fdf);
	mlx_loop(fdf->mlx_ptr);
	return (1);
}

int	main(int argv, char **arg)
{
	if (argv == 2)
	{
		app_init(arg[1]);
		return (0);
	}
	ft_putstr_fd("usage: ./fdf map.fdf\n", 1);
	return (0);
}
