/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:26:33 by oal-tena          #+#    #+#             */
/*   Updated: 2022/01/06 04:16:29 by oal-tena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	put_pixel(t_fdf *fdf, int x, int y, int color)
{
	int		i;
	int		xyl;
	int		xyd;

	i = (x * 4 * (fdf->img_width / fdf->map_width)) + \
	(y * fdf->size_line * (fdf->img_height / fdf->map_height));
	fdf->img_data[i] = color;
	fdf->img_data[i + 1] = color >> 8;
	fdf->img_data[i + 2] = color >> 16;
}

//https://aurelienbrabant.fr/blog/pixel-drawing-with-the-minilibx

void	draw_line(t_fdf *fdf, int x, int y, int color)
{
	char    *pixel;
	int		i;

	i = fdf->bpp - 8;
    pixel = fdf->img_data + (y * fdf->size_line + x * (fdf->bpp / 32));
	while (i >= 0)
	{
		if (fdf->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (fdf->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

void	put_map_image(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < fdf->map_height)
	{
		j = 0;
		while (j < fdf->map_width)
		{
			if (fdf->map[i][j] == 0)
				put_pixel(fdf, j, i, 0xFFFFFF);
			else if (fdf->map[i][j] < 0)
				put_pixel(fdf, j, i, 0x042FFF);
			else if (fdf->map[i][j] > 0)
				put_pixel(fdf, j, i, 0xFF0000);
			draw_line(fdf, i, j, 0xFFFFFF);
			j++;
			draw_line(fdf, i, j, 0xFFFFFF);
		}
		printf("\n");

		i++;
	}
}
