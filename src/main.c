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

/*
init the window and the hook for the keyboard and mouse,
then call the function that will draw the map
*/
void	ft_fdf_init(t_fdf fdf)
{
	if (window_init(fdf) == false)
		ft_putstr_fd(ERROR"error window init\n"END, 1);
}

/*
entry point for application
you need two arguments to run the program :
1. the path to the file
2. the name of the file
example : ./fdf maps/map.fdf
if there is no file in the maps folder, 
you will get an error message and the program will exit.
*/

int	main(int argv, char **arg)
{
	t_fdf	fdf;

	if (argv == 2)
	{
		ft_putstr_fd(SUCCESS"Your app will work.\n", 1);
		ft_fdf_init(fdf);
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
