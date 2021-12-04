/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 03:20:29 by oal-tena          #+#    #+#             */
/*   Updated: 2021/12/04 08:55:20 by oal-tena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/**
 * @brief function to help us count word number on line
 * 
 * @param line get_next_line return.
 * @param c char will check and split from it.
 * @return count of word
 */
int	ft_count_word(char *line, char c)
{
	int		count;
	char	**split;
	int		i;

	split = ft_split(line, c);
	count = 0;
	while (1)
	{
		if (!split[i])
			break ;
		count++;
		i++;
	}
	return (count);
}

/**
 * @brief function to select number for calculator xedga amount 
 * 
 * @param a current number for pixel
 * @param b previous number for pixel
 * @return int 
 */
int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

/**
 * @brief to resvrtion of memory for new map.
 * 
 * @param ptr pointer to map 
 * @param n number of lines
 * @return t_bool 
 */
t_bool	ft_malloc(void **ptr, int n)
{
	*ptr = malloc(n);
	if (*ptr)
		return (true);
	return (false);
}
