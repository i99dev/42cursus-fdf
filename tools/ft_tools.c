/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 10:02:54 by oal-tena          #+#    #+#             */
/*   Updated: 2022/01/10 06:08:52 by oal-tena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	shift_and_centeralize_map(t_fdf *fdf)
{
	fdf->x0 = fdf->x0 + fdf->x_shift + (P_WIDTH / 2.5);
	fdf->x1 = fdf->x1 + fdf->x_shift + (P_WIDTH / 2.5);
	fdf->y0 = fdf->y0 + fdf->y_shift + (P_HEIGHT / 4);
	fdf->y1 = fdf->y1 + fdf->y_shift + (P_HEIGHT / 4);
}

void	adjust_zoom(t_fdf *fdf, int normalize)
{
	fdf->x0 = fdf->x0 * fdf->xy_zoom * normalize;
	fdf->x1 = fdf->x1 * fdf->xy_zoom * normalize;
	fdf->y0 = fdf->y0 * fdf->xy_zoom * normalize;
	fdf->y1 = fdf->y1 * fdf->xy_zoom * normalize;
}

void	rotate_xyz_axis(t_fdf *fdf)
{
	rotate_x_axis(fdf, &fdf->y0, &fdf->z0, fdf->x_axis);
	rotate_x_axis(fdf, &fdf->y1, &fdf->z1, fdf->x_axis);
	rotate_y_axis(fdf, &fdf->x0, &fdf->y0, fdf->y_axis);
	rotate_y_axis(fdf, &fdf->x1, &fdf->y1, fdf->y_axis);
	rotate_z_axis(fdf, &fdf->x0, &fdf->y0, fdf->z_axis);
	rotate_z_axis(fdf, &fdf->x1, &fdf->y1, fdf->z_axis);
}

void	implement_transformations(t_fdf *fdf, int normalize)
{
	adjust_zoom(fdf, normalize);
	rotate_xyz_axis(fdf);
	change_projection_view(fdf);
	shift_and_centeralize_map(fdf);
}

int	ft_normalize(t_fdf *fdf)
{
	int	height;
	int	width;

	height = P_HEIGHT / fdf->map_height;
	width = P_WIDTH / fdf->map_width;
	if (height < width)
		return (height);
	else if (width <= height)
		return (width);
	return (0);
}
