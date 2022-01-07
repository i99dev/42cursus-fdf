/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:26:33 by oal-tena          #+#    #+#             */
/*   Updated: 2022/01/07 07:16:06 by oal-tena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	down_line(t_fdf *fdf, int x, int y, int color)
{
	float	dy;
	char	*pixel;
	int		is_last;

	is_last = fdf->map_dy * fdf->map_height;
	dy = fdf->map_dy + y;
	while (y < dy && dy < is_last)
	{
		pixel = fdf->img_data + (y * fdf->size_line) + (x * 4);
		pixel[0] = color;
		pixel[1] = color >> 8;
		pixel[2] = color >> 16;
		y++;
	}
}

void	left_line(t_fdf *fdf, int x, int y, int color)
{
	float	dx;
	char	*pixel;
	int		is_last;

	is_last = fdf->map_dx * fdf->map_width - 1;
	dx = fdf->map_dx + x;
	while (x < dx && dx < is_last)
	{
		pixel = fdf->img_data + (y * fdf->size_line) + (x * 4);
		pixel[0] = color;
		pixel[1] = color >> 8;
		pixel[2] = color >> 16;
		x++;
	}
}

void	pix_put_img(t_fdf *fdf, int x, int y, int color)
{
	char			*pixel;

	x = x * fdf->map_dx;
	y = y * fdf->map_dy;
	pixel = fdf->img_data + (y * fdf->size_line) + (x * 4);
	*pixel = color;
	left_line(fdf, x, y, color);
	down_line(fdf, x, y, color);
}

void	put_map_image(t_fdf *fdf)
{
	int		y;
	int		x;

	fdf->map_dx = (fdf->img_width * 0.8) / fdf->map_width;
	fdf->map_dy = (fdf->img_height * 0.8) / fdf->map_height;
	y = 0;
	while (y < fdf->map_height)
	{
		x = 0;
		while (x < fdf->map_width)
		{
			if (fdf->map[y][x] == 0)
				pix_put_img(fdf, x, y, 0xFFFFFF);
			else if (fdf->map[y][x] == 1)
				pix_put_img(fdf, x, y, 0xFF0000);
			else if (fdf->map[y][x] == 2)
				pix_put_img(fdf, x, y, 0x00FF00);
			else if (fdf->map[y][x] == 3)
				pix_put_img(fdf, x, y, 0x0000FF);
			else if (fdf->map[y][x] == 4)
				pix_put_img(fdf, x, y, 0xFFFF00);
			else if (fdf->map[y][x] == 5)
				pix_put_img(fdf, x, y, 0x00FFFF);
			else if (fdf->map[y][x] == 6)
				pix_put_img(fdf, x, y, 0xFF00FF);
			else if (fdf->map[y][x] == 7)
				pix_put_img(fdf, x, y, 0x00FFFF);
			else if (fdf->map[y][x] == 8)
				pix_put_img(fdf, x, y, 0xFFFFFF);
			else if (fdf->map[y][x] == 9)
				pix_put_img(fdf, x, y, 0xFFFFFF);
			else if (fdf->map[y][x] == 10)
				pix_put_img(fdf, x, y, 0xFFFFFF);
			else if (fdf->map[y][x] == 11)
				pix_put_img(fdf, x, y, 0xFFFFFF);
			else if (fdf->map[y][x] == 12)
				pix_put_img(fdf, x, y, 0xFFFFFF);
			else if (fdf->map[y][x] == 13)
				pix_put_img(fdf, x, y, 0xFFFFFF);
			else if (fdf->map[y][x] == 14)
				pix_put_img(fdf, x, y, 0xFFFFFF);
			else if (fdf->map[y][x] == 15)
				pix_put_img(fdf, x, y, 0xFFFFFF);
			else if (fdf->map[y][x] == 16)
				pix_put_img(fdf, x, y, 0xFFFFFF);
			else if (fdf->map[y][x] == 17)
				pix_put_img(fdf, x, y, 0xFFFFFF);
			else if (fdf->map[y][x] == 18)
				pix_put_img(fdf, x, y, 0xFFFFFF);
			else if (fdf->map[y][x] == 19)
				pix_put_img(fdf, x, y, 0xFFFFFF);
			x++;
		}
		y++;
	}
}
