/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:26:33 by oal-tena          #+#    #+#             */
/*   Updated: 2022/01/07 07:05:26 by oal-tena         ###   ########.fr       */
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

	fdf->map_dx = (fdf->img_width * 0.2) / fdf->map_width;
	fdf->map_dy = (fdf->img_height * 0.2) / fdf->map_height;
	y = 0;
	while (y < fdf->map_height)
	{
		x = 0;
		while (x < fdf->map_width)
		{
			printf("%-4d", fdf->map[y][x]);
			if (fdf->map[y][x] == 0)
				pix_put_img(fdf, x, y, 0xFFFFFF);
			else if (fdf->map[y][x] < 0)
				pix_put_img(fdf, x, y, 0xFFFFFF);
			else if (fdf->map[y][x] > 0)
				pix_put_img(fdf, x, y, 0xFF0404);
			x++;
		}
		printf("\n");
		y++;
	}
}
