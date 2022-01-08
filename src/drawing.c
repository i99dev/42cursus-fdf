/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:26:33 by oal-tena          #+#    #+#             */
/*   Updated: 2022/01/08 12:49:59 by oal-tena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_put_pixel(t_fdf *fdf, int x, int y, int color)
{
	char	*pixel;

	pixel = fdf->img_data + ((y) * fdf->size_line) + (x * 4);
	pixel[0] = color;
	pixel[1] = color >> 8;
	pixel[2] = color >> 16;
}

void	ft_check_merge(t_fdf *fdf, int x, int y, int color)
{
	if (x < 0 || y < 0 || x >= fdf->img_width || y >= fdf->img_height)
		return ;
	ft_put_pixel(fdf, x, y, color);
}

void	down_line(t_fdf *fdf, int x, int y, int color)
{
	float	dy;
	char	*pixel;
	int		is_last;
	int		p;

	is_last = fdf->map_dy * fdf->map_height;
	dy = fdf->map_dy + y;
	p = 2 * fdf->map_dx - fdf->map_dy;
	while (y < dy && dy < is_last)
	{
		if (p >= 0)
		{
			p += 2 * fdf->map_dx;
		}
		else
		{
			p += 2 * fdf->map_dx - 2 * fdf->map_dy;
			x--;
		}
		ft_check_merge(fdf, x, y, color);
		y++;
	}
}

void	left_line(t_fdf *fdf, int x, int y, int color)
{
	float	dx;
	char	*pixel;
	int		is_last;
	int		p;

	is_last = fdf->map_dx * fdf->map_width - 1;
	dx = fdf->map_dx + x;
	while (x < dx && dx < is_last)
	{
		ft_check_merge(fdf, x, y, color);
		x++;
	}
}

void	pix_put_img(t_fdf *fdf, unsigned int x, unsigned int y, int color)
{
	char					*pixel;
	unsigned int			px;
	unsigned int			py;

	x = (x * fdf->map_dx) + fdf->move_x;
	y = (y * fdf->map_dy) + fdf->move_y;
	px = (x - y) * cos(fdf->angle);
	py = (x + y) * sin(fdf->angle);
	if (px > fdf->img_width || py > fdf->img_height || px < 0 || py < 0)
		return ;
	left_line(fdf, px, py, color);
	down_line(fdf, px, py, color);
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
