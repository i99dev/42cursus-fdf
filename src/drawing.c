/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:26:33 by oal-tena          #+#    #+#             */
/*   Updated: 2022/01/06 16:36:38 by oal-tena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//https://aurelienbrabant.fr/blog/pixel-drawing-with-the-minilibx

void	pix_put_img(t_fdf *fdf, int x, int y, int color)
{
	char	*pixel;
	float	dx;
	float	dy;

	dx = fdf->img_width / fdf->map_width;
	dy = fdf->img_height / fdf->map_height;
	pixel = fdf->img_data + (y * fdf->size_line) + (x * 4);
	*pixel = color;
	while (++x < fdf->img_width)
	{
		pixel = fdf->img_data + (y * fdf->size_line) + (x * 4);
		*pixel = color;
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
				pix_put_img(fdf, x * dx, y * dy, 0x042FFF);
			else if (fdf->map[y][x] > 0)
				pix_put_img(fdf, x * dx, y * dy, 0xFF0000);
			x++;
		}
		y++;
	}
}
