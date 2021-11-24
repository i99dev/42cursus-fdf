/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:07:25 by oal-tena          #+#    #+#             */
/*   Updated: 2021/11/24 16:37:39 by oal-tena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	read_file(t_fdf *fdf)
{
	char	*temp;
	int		fd;

	fd = open(fdf->filepath, O_RDONLY);
	while (1)
	{
		temp = get_next_line(fd);
		if (!temp)
			break ;
		printf("%s", temp);
		free(temp);
	}
}
