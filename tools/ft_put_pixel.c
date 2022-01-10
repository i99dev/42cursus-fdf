/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 06:09:12 by oal-tena          #+#    #+#             */
/*   Updated: 2022/01/10 06:09:25 by oal-tena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_put_pixel_image(t_fdf *fdf, int x, int y, int color)
{
	char	*pixel;

	if (x > fdf->img_width || y > fdf->img_height || x < 0 || y < 0)
		return ;
	pixel = fdf->img_data + (y * fdf->size_line) + (x * 4);
	pixel[0] = color;
	pixel[1] = color >> 8;
	pixel[2] = color >> 16;
}
