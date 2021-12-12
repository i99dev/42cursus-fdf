/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_win_design.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:56:42 by oal-tena          #+#    #+#             */
/*   Updated: 2021/12/12 00:32:40 by oal-tena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <stdio.h>

void	split_windoes(t_fdf *fdf)
{
	int	screen_width;
	int	screen_height;
	int	line_height;
	int	menu_size;

	screen_height = SCREEN_HEIGHT;
	screen_width = SCREEN_HEIGHT;
	line_height = 0;
	menu_size = screen_width * 0.40;
	while (1)
	{
		if (line_height == screen_height)
			break ;
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, menu_size, \
			line_height, 0xFFFFFF);
		line_height++;
	}
}

void	type_titel(t_fdf *fdf)
{
	int	xp;
	int	yp;

	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 65, 30, \
		0xFFFFFF, "FDF Project!");
}


//more inf : https://awesomeopensource.com/project/keuhdall/images_example
void	image_init(t_fdf *fdf, t_image *img)
{
	int		x;
	int		y;

	img->height = 500;
	img->width = 500;
	img->img_ptr = mlx_new_image(fdf->mlx_ptr, img->width, img->height);
	img->img_addr = mlx_get_data_addr(img->img_ptr, &img->bpp, \
		&img->size_line, &img->endian);
}

t_bool	hook_windoes_layout(t_fdf *fdf)
{	
	int		i;

	split_windoes(fdf);
	type_titel(fdf);
	image_init(fdf, &fdf->img);
	return (true);
}
 