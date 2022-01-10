/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 05:59:16 by oal-tena          #+#    #+#             */
/*   Updated: 2022/01/10 06:06:36 by oal-tena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	rotate_x_axis(t_fdf *fdf, int *y, int *z, double x_axis)
{
	int	temp_y;
	int	temp_z;

	temp_y = (*y * cos(x_axis)) - (*z * sin(x_axis));
	temp_z = (*y * sin(x_axis)) + (*z * cos(x_axis));
	*y = temp_y;
	*z = temp_z;
}

void	rotate_y_axis(t_fdf *fdf, int *x, int *z, double y_axis)
{
	int	temp_x;
	int	temp_z;

	temp_x = (*x * cos(y_axis)) - (*z * sin(y_axis));
	temp_z = (*x * sin(y_axis)) + (*z * cos(y_axis));
	*x = temp_x;
	*z = temp_z;
}

void	rotate_z_axis(t_fdf *fdf, int *x, int *y, double z_axis)
{
	int	temp_x;
	int	temp_y;

	temp_x = (*x * cos(z_axis)) - (*y * sin(z_axis));
	temp_y = (*x * sin(z_axis)) + (*y * cos(z_axis));
	*x = temp_x;
	*y = temp_y;
}
