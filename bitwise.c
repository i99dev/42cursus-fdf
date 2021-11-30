/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwise.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 06:05:20 by oal-tena          #+#    #+#             */
/*   Updated: 2021/11/30 08:01:55 by oal-tena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	convert_to_bainery(int number);

int	main(int argv, char **arg)
{
	convert_to_bainery(50);
	return (0);
}

void	convert_to_bainery(int number)
{
	int		a;
	int		b;
	int		c;
	int		d;

	a = 1 + 1 + '0';
	b = 49;
	c = a + b;
	d = 97;
	write(1, &d, 1);
}
