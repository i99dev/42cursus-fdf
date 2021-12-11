/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_win_design.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:56:42 by oal-tena          #+#    #+#             */
/*   Updated: 2021/12/11 06:08:46 by oal-tena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	split_windoes(t_fdf *fdf)
{
	int	screen_width;
	int	screen_height;
	int	line_height;
	int	menu_size;

	screen_height = SCREEN_HEIGHT;
	screen_width = SCREEN_HEIGHT;
	line_height = 0;
	menu_size = screen_width * 0.40;
	while (1)
	{
		if (line_height == screen_height)
			break ;
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, menu_size, \
			line_height, 0xFFFFFF);
		line_height++;
	}
}

void	type_titel(t_fdf *fdf)
{
	int	xp;
	int	yp;

	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 65, 30, \
		0xFFFFFF, "FDF Project!");
}

t_bool	hook_windoes_layout(t_fdf *fdf)
{	
	void	*img_ptr;
	char	*plx;
	int		i;
	int		X;

	split_windoes(fdf);
	type_titel(fdf);
	img_ptr = mlx_new_image(fdf->mlx_ptr, 500, 250);
	plx = mlx_get_data_addr(img_ptr, &fdf->img.bpp, \
		&fdf->img.size_line, &fdf->img.endian);
	X = 0;
	while (X <= 1000)
	{
		plx[X+=2] = 255;
		X++;
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, img_ptr, 200, 200);
	return (true);
}
