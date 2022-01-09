/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:26:33 by oal-tena          #+#    #+#             */
/*   Updated: 2022/01/09 15:14:40 by oal-tena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

double	degree_to_radian(double degrees)
{
	double radian;

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
void	rotate_x_axis(t_fdf *fdf, int *y, int *z, double x_axis)
{
	int temp_y;
	int temp_z;

	temp_y = (*y * cos(x_axis)) - (*z * sin(x_axis));
	temp_z = (*y * sin(x_axis)) + (*z * cos(x_axis));
	*y = temp_y;
	*z = temp_z;
}
void	rotate_y_axis(t_fdf *fdf, int *x, int *z, double y_axis)
{
	int temp_x;
	int temp_z;

	temp_x = (*x * cos(y_axis)) - (*z * sin(y_axis));
	temp_z = (*x * sin(y_axis)) + (*z * cos(y_axis));
	*x = temp_x;
	*z = temp_z;
}
void	rotate_z_axis(t_fdf *fdf, int *x, int *y, double z_axis)
{
	int temp_x;
	int temp_y;

	temp_x = (*x * cos(z_axis)) - (*y * sin(z_axis));
	temp_y = (*x * sin(z_axis)) + (*y * cos(z_axis));
	*x = temp_x;
	*y = temp_y;
}
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

int		ft_normalize(t_fdf *fdf)
{
	int height;
	int width;

	height = P_HEIGHT / fdf->map_height;
	width = P_WIDTH / fdf->map_width;
	if (height < width)
		return (height);
	else if (width <= height)
		return (width);
	return (0);
}

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
	int normalize;

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
}
