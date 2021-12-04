/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 03:20:29 by oal-tena          #+#    #+#             */
/*   Updated: 2021/12/04 06:17:39 by oal-tena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/**
 * @brief 
 * 
 * @param line 
 * @param c 
 * @return int 
 */
int	ft_count_split(char *line, char c)
{
	int		count;
	char	**split;
	int		i;

	split = ft_split(line, c);
	count = -1;
	while (1)
	{
		if (!split[i])
			break ;
		count += ft_strlen(split[i]);
		i++;
	}
	return (count);
}

/**
 * @brief return minume number between two int;
 * 
 * @param a 
 * @param b 
 * @return int 
 */
int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
