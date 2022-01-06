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
	fdf->img_width = 600;
	fdf->img_height = 300;
	fdf->size_line = fdf->map_width * 4;
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, fdf->img_width, fdf->img_height);
	fdf->img_data = mlx_get_data_addr(fdf->img_ptr, &fdf->bpp, \
	&fdf->size_line, &fdf->endian);
}

void	app_init(char *file_path, t_fdf *fdf)
{
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, \
	SCREEN_WIDTH, SCREEN_HEIGHT, "FDF");
	regsiter_hooks(fdf);
	ft_read_file(file_path, fdf);
	init_img(fdf);
	put_map_image(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 300, 50);
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
