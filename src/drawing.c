/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:26:33 by oal-tena          #+#    #+#             */
/*   Updated: 2022/01/08 16:14:38 by oal-tena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	pix_put_img(t_fdf *fdf, unsigned int x, unsigned int y, int color)
{
	char					*pixel;

	fdf->color = color;
	fdf->x0 = (x * fdf->map_x_size) + fdf->move_x;
	fdf->y0 = (y * fdf->map_y_size) + fdf->move_y;
	fdf->x1 = (x * fdf->map_x_size) + fdf->move_x + fdf->map_x_size;
	fdf->y1 = (y * fdf->map_y_size) + fdf->move_y + fdf->map_y_size;
	fdf->map_dx = (fdf->x1 - fdf->x0);
	fdf->map_dy = (fdf->y1 - fdf->y0);
	printf("(%d,%d)->%d %d %d %d\n",y,x, fdf->x0, fdf->y0, fdf->x1, fdf->y1);
	ft_drwa_line(fdf);
}

void	put_map_image(t_fdf *fdf)
{
	int		y;
	int		x;

	fdf->map_x_size = (fdf->img_width / fdf->map_width) * 0.8;
	fdf->map_y_size = (fdf->img_height / fdf->map_height) * 0.8;
	y = 0;
	while (y < fdf->map_height)
	{
		x = 0;
		while (x < fdf->map_width)
		{
			if (fdf->map[y][x] == 0)
				pix_put_img(fdf, x, y, 0xFFFFFF);
			else if (fdf->map[y][x] > 0)
				pix_put_img(fdf, x, y, 0xFF0000);
			else if (fdf->map[y][x] < 0)
				pix_put_img(fdf, x, y, 0x00FF00);

			x++;
		}
		y++;
	}
}
