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

void	ft_fdf_init(void)
{
	t_vars	fdf;

	fdf.mlx_ptr = mlx_init();
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, \
	HIGH_SCREEN_WIDTH, HIGH_SCREEN_WIDTH, "Welcome To My App");
	mlx_loop(fdf.mlx_ptr);
}

int	main(int argv, char **arg)
{
	if (argv == 2)
	{
		ft_putstr_fd(SUCCESS"Your app will work.\n", 1);
		ft_fdf_init();
	}
	else if (argv == 1)
	{
		ft_putstr_fd(WARNING"Invalid arguments. Filename is missing.\n", 2);
		return (1);
	}
	else
	{
		ft_putstr_fd(WARNING"Too many arguments.\n", 2);
		return (2);
	}
	return (0);
}
