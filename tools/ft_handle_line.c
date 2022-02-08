/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 05:35:27 by oal-tena          #+#    #+#             */
/*   Updated: 2022/01/10 06:07:06 by oal-tena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	rotate_vertical_line(t_fdf *fdf)
{
	int	normalize;

	normalize = ft_normalize(fdf);
	if (fdf->y < fdf->map_height)
	{
		fdf->z0 = fdf->map[fdf->y][fdf->x] * fdf->z_zoom * normalize;
		fdf->z1 = fdf->map[fdf->y + 1][fdf->x] * fdf->z_zoom * normalize;
	}
	fdf->x1 = fdf->x0;
	fdf->y1 = fdf->y0 + 1;
	implement_transformations(fdf, normalize);
}

void	rotate_horizontal_line(t_fdf *fdf)
{
	int	normalize;

	normalize = ft_normalize(fdf);
	if (fdf->x < fdf->map_width)
	{
		fdf->z0 = fdf->map[fdf->y][fdf->x] * fdf->z_zoom * normalize;
		fdf->z1 = fdf->map[fdf->y][fdf->x + 1] * fdf->z_zoom * normalize;
	}
	fdf->x1 = fdf->x0 + 1;
	fdf->y1 = fdf->y0;
	implement_transformations(fdf, normalize);
}

void	ft_y(t_fdf *fdf)
{
	fdf->x0 = fdf->x;
	fdf->y0 = fdf->y;
	rotate_vertical_line(fdf);
	if (fdf->y < fdf->map_height)
		ft_drwa_line(fdf);
}

void	ft_x(t_fdf *fdf)
{
	fdf->x0 = fdf->x;
	fdf->y0 = fdf->y;
	rotate_horizontal_line(fdf);
	if (fdf->x < fdf->map_width)
		ft_drwa_line(fdf);
}
