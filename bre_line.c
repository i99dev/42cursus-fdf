/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bre_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 07:43:27 by oal-tena          #+#    #+#             */
/*   Updated: 2021/12/06 11:44:03 by oal-tena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fdf.h"

#define H_SCREEN 600
#define W_SCREEN 1080

void	bersn_line(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (1)
	{
		if (y == H_SCREEN)
			break ;
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, 250, y, 0xFFFFFF);
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 65, 45, 0xFFFFFF, \
			"FDF Project!");
		y++;
	}
}

int	main(int arg, char **argv)
{
	t_fdf	*fdf;

	if (arg != 2)
		return (0);
	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, W_SCREEN, H_SCREEN, "FDF");
	bersn_line(fdf);
	mlx_loop(fdf->mlx_ptr);
	return (0);
}
