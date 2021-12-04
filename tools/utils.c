/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 03:20:29 by oal-tena          #+#    #+#             */
/*   Updated: 2021/12/04 04:09:10 by oal-tena         ###   ########.fr       */
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

	split = ft_split(line, c);
	count = 0;
	while (1)
	{
		if (!split[count])
			break ;
		count++;
	}
	return (count);
}
