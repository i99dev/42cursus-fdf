/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:26:33 by oal-tena          #+#    #+#             */
/*   Updated: 2022/01/05 13:58:17 by oal-tena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	put_pixel(t_fdf *fdf, int x, int y, int color)
{
	int		i;

	i = (x * 4 * (fdf->img_width / fdf->map_width)) + \
	(y * fdf->size_line * (fdf->img_height / fdf->map_height));
	fdf->img_data[i] = color;
	fdf->img_data[i + 1] = color >> 8;
	fdf->img_data[i + 2] = color >> 16;	
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
			j++;
		}
		i++;
	}
}
