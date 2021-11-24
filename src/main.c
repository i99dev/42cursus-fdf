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

/**
 * @brief initialise window for fdf
 * 
 * @param filepath path of the file 
 */
void	ft_fdf_init(char *filepath)
{
	t_fdf	fdf;

	fdf.filepath = filepath;
	read_file(&fdf);
	if (window_init(fdf) == false)
		return (ft_putstr_fd(ERROR"error window init\n"END, 1));
}

/**
 * @brief entry point for application
 * 
 * @param argv 
 * @param arg 
 * @return int 
 */

int	main(int argv, char **arg)
{
	if (argv == 2)
	{
		ft_putstr_fd(SUCCESS"Your app will work.\n", 1);
		ft_fdf_init(arg[1]);
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
