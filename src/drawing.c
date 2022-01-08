/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:26:33 by oal-tena          #+#    #+#             */
/*   Updated: 2022/01/08 09:54:30 by oal-tena         ###   ########.fr       */
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
		pixel = fdf->img_data + ((y) * fdf->size_line) + (x * 4);
		pixel[0] = color;
		pixel[1] = color >> 8;
		pixel[2] = color >> 16;
		x++;
	}
}

void	pix_put_img(t_fdf *fdf, unsigned int x, unsigned int y, int color)
{
	char					*pixel;
	unsigned int			dx;
	unsigned int			dy;

	printf("(%d, %d)", x, y);
	x = (x * fdf->map_dx) + fdf->move_x;
	y = (y * fdf->map_dy) + fdf->move_y;
	dx = (x - y) * cos(0.5);
	dy = (x + y) * sin(0.5);
	printf("(%d ,%d)\n", dx, dy);
	if (dx > fdf->img_width || dy > fdf->img_height || dx < 0 || dy < 0)
		return ;
	pixel = fdf->img_data + (dy * fdf->size_line) + (dx * 4);
	*pixel = color;
	left_line(fdf, dx, dy, color);
	down_line(fdf, dx, dy, color);
}

void	put_map_image(t_fdf *fdf)
{
	int		y;
	int		x;

	fdf->map_dx = (fdf->img_width / fdf->map_width) * 0.9;
	fdf->map_dy = (fdf->img_height / fdf->map_height) * 0.9;
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
