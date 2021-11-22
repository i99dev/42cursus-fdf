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

int	main(int argv, char **arg)
{
	if (argv == 2)
		ft_putstr_fd(GREEN"Your app will work.\n"RESET, 1);
	else if (argv == 1)
	{
		ft_putstr_fd(YELLOW"Invalid arguments. Filename is missing.\n"RESET, 2);
		return (1);
	}
	else
	{
		ft_putstr_fd(YELLOW"Too many arguments.\n"RESET, 2);
		return (2);
	}
	return (0);
}
