/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 05:33:21 by oal-tena          #+#    #+#             */
/*   Updated: 2022/01/10 06:07:24 by oal-tena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

double	degree_to_radian(double degrees)
{
	double	radian;

	radian = degrees * (M_PI / 180);
	return (radian);
}

void	rotation_matrix(t_fdf *fdf, int *x, int *y, int z)
{
	int		temp_x;
	int		temp_y;
	double	radian;

	temp_x = *x;
	temp_y = *y;
	if (fdf->camera == 0)
		fdf->degree_angle = 30;
	else if (fdf->camera == 1)
		fdf->degree_angle = 15;
	radian = degree_to_radian(fdf->degree_angle);
	*x = (temp_x - temp_y) * cos(radian);
	*y = -z + (temp_x + temp_y) * sin(radian);
}

void	change_projection_view(t_fdf *fdf)
{
	rotation_matrix(fdf, &fdf->x0, &fdf->y0, fdf->z0);
	rotation_matrix(fdf, &fdf->x1, &fdf->y1, fdf->z1);
}
