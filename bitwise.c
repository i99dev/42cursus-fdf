/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwise.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 06:05:20 by oal-tena          #+#    #+#             */
/*   Updated: 2021/12/06 07:59:55 by oal-tena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "./lib/libft/libft.h"

int	*convert_to_bainery(int c);

int	main(int argv, char **arg)
{
	char	*d;
	char	**split;
	int		i;

	d = "0 1 0 1 0 1 0 1 0 1 0 1 0";
	split = ft_split(d, ' ');
	while (1)
	{
		if (!split[i])
			break ;
		printf("%s", split[i]);
		i++;
	}
	return (0);
}

int	*convert_to_bainery(int c)
{
	int		binary[7];
	int		i;

	i = 0;
	while (c > 0)
	{
		binary[i] = c % 2;
		c = c / 2;
		printf("%d\n", binary[i]);
		i++;
	}
	binary[i] = '\0';
	printf("index -> %d\n", i);
	printf("%x\n", binary);
	i = 0;
	while (i < 7)
	{
		printf("%d", binary[i]);
		i++;
		i++;
	}
}
