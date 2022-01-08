/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 10:02:54 by oal-tena          #+#    #+#             */
/*   Updated: 2022/01/08 10:04:44 by oal-tena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	create_new_img(t_fdf *fdf)
{
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, fdf->img_width, fdf->img_height);
	fdf->img_data = mlx_get_data_addr(fdf->img_ptr, &fdf->bpp, \
	&fdf->size_line, &fdf->endian);
}