/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:26:33 by oal-tena          #+#    #+#             */
/*   Updated: 2022/01/06 17:35:32 by oal-tena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//https://aurelienbrabant.fr/blog/pixel-drawing-with-the-minilibx

void	pix_put_img(t_fdf *fdf, int x, int y, int color)
{
	char	*pixel;
	float	dx;
	float	dy;

	dx = fdf->img_width / fdf->map_width + x;
	dy = fdf->img_height / fdf->map_height + y;
	pixel = fdf->img_data + (y * fdf->size_line) + (x * 4);
	*pixel = color;
	while (y < dy && y < fdf->img_height)
	{
		pixel = fdf->img_data + (y * fdf->size_line) + (x * 4);
		pixel[0] = color;
		pixel[1] = color >> 8;
		pixel[2] = color >> 16;
		while (x < dx && x < fdf->img_width)
		{
			pixel = fdf->img_data + (y * fdf->size_line) + (x * 4);
			pixel[0] = color;
			pixel[1] = color >> 8;
			pixel[2] = color >> 16;
			x++;
		}
		y++;
	}
}



void	put_map_image(t_fdf *fdf)
{
	int		y;
	int		x;
	float	dx;
	float	dy;

	y = 0;
	dx = fdf->img_width / fdf->map_width;
	dy = fdf->img_height / fdf->map_height;
	while (y < fdf->map_height)
	{
		x = 0;
		while (x < fdf->map_width)
		{
			if (fdf->map[y][x] == 0)
				pix_put_img(fdf, x * dx, y * dy, 0xFFFFFF);
			else if (fdf->map[y][x] < 0)
				pix_put_img(fdf, x * dx, y * dy, 0xFFFFFF);
			else if (fdf->map[y][x] > 0)
				pix_put_img(fdf, x * dx, y * dy, 0xFF0404);
			x++;
		}
		y++;
	}
}
