/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:05:40 by oal-tena          #+#    #+#             */
/*   Updated: 2021/11/16 14:15:16 by oal-tena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	app_init(char *file_path, t_fdf *fdf)
{
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, \
	SCREEN_WIDTH, SCREEN_HEIGHT, "FDF");
	regsiter_hooks(fdf);
	ft_read_file(file_path, fdf);
    printf_map(fdf);
	mlx_loop(fdf->mlx_ptr);
}

int	main(int argv, char **arg)
{
	t_fdf	fdf;

	if (argv == 2)
	{
		app_init(arg[1], &fdf);
		return (0);
	}
	ft_putstr_fd("usage: ./fdf map.fdf\n", 1);
	return (0);

}
