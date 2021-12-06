/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bre_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 07:43:27 by oal-tena          #+#    #+#             */
/*   Updated: 2021/12/06 08:36:06 by oal-tena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fdf.h"

void	bersn_line(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (1)
	{
		if (y == 600)
			break ;
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, 150, y, 0xFFFFFF);
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
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, 600, 600, "FDF");
	bersn_line(fdf);
	mlx_loop(fdf->mlx_ptr);
	return (0);
}
