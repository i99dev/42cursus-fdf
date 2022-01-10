/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:26:33 by oal-tena          #+#    #+#             */
/*   Updated: 2022/01/10 06:43:31 by oal-tena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	render_map(t_fdf *fdf)
{
	if (fdf->camera == 0 || fdf->camera == 1)
	{
		if (fdf->y < fdf->map_height)
			ft_y(fdf);
		ft_x(fdf);
	}
}

void	put_map_image(t_fdf *fdf)
{

	while (fdf->y <= fdf->map_height)
	{
		fdf->x = 0;
		while (fdf->x <= fdf->map_width)
		{
			render_map(fdf);
			fdf->x++;
		}
		fdf->y++;
	}
	fdf->x = 0;
	fdf->y = 0;
    mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 300, 50);
}
