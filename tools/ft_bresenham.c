/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 13:30:26 by oal-tena          #+#    #+#             */
/*   Updated: 2022/01/10 06:10:38 by oal-tena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
	return (0);
}

void	calc_delta_xy(t_fdf *fdf)
{
	fdf->map_dx = fdf->x1 - fdf->x0;
	fdf->map_dy = fdf->y1 - fdf->y0;
}

void	plot_low_line(t_fdf *fdf)
{
	size_t	color;

	color = fdf->color;
	if (fdf->map[fdf->y][fdf->x] == 0)
		color = 0xFFFFFF;
	calc_delta_xy(fdf);
	fdf->step_y = 1;
	if (fdf->map_dy < 0)
	{
		fdf->step_y = -1;
		fdf->map_dy = -1 * fdf->map_dy;
	}
	fdf->del_error = (2 * fdf->map_dy) - fdf->map_dx;
	while (fdf->x0 < fdf->x1)
	{
		ft_put_pixel_image(fdf, fdf->x0, fdf->y0, color);
		if (fdf->del_error > 0)
		{
			fdf->y0 += fdf->step_y;
			fdf->del_error -= 2 * fdf->map_dx;
		}
		fdf->del_error += 2 * fdf->map_dy;
		fdf->x0++;
	}
}

void	plot_high_line(t_fdf *fdf)
{
	size_t	color;

	color = fdf->color;
	if (fdf->map[fdf->y][fdf->x] == 0)
		color = 0xFFFFFF;
	calc_delta_xy(fdf);
	fdf->step_x = 1;
	if (fdf->map_dx < 0)
	{
		fdf->step_x = -1;
		fdf->map_dx = -1 * fdf->map_dx;
	}
	fdf->del_error = (2 * fdf->map_dx) - fdf->map_dy;
	while (fdf->y0 < fdf->y1)
	{
		ft_put_pixel_image(fdf, fdf->x0, fdf->y0, color);
		if (fdf->del_error > 0)
		{
			fdf->x0 += fdf->step_x;
			fdf->del_error -= 2 * fdf->map_dy;
		}
		fdf->del_error += 2 * fdf->map_dx;
		fdf->y0++;
	}
}

void	ft_drwa_line(t_fdf *fdf)
{
	if (abs(fdf->y1 - fdf->y0) < abs(fdf->x1 - fdf->x0))
	{
		if (fdf->x0 > fdf->x1)
		{
			ft_swap(&fdf->x0, &fdf->x1);
			ft_swap(&fdf->y0, &fdf->y1);
			plot_low_line(fdf);
		}
		else
			plot_low_line(fdf);
	}
	else
	{
		if (fdf->y0 > fdf->y1)
		{
			ft_swap(&fdf->x0, &fdf->x1);
			ft_swap(&fdf->y0, &fdf->y1);
			plot_high_line(fdf);
		}
		else
			plot_high_line(fdf);
	}
}
