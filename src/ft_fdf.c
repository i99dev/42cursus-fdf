/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:07:25 by oal-tena          #+#    #+#             */
/*   Updated: 2021/12/12 13:03:51 by oal-tena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_bool	add_pixel(t_fdf *fdf)
{
	// !->let us check the pixel maps.
}

/**
 * @brief  
 * 
 * @param fdf 
 */
void	ft_read_file(t_fdf *fdf, t_image *img)
{
	int		fd;
	int		r;
	int		x;
	char	*line;

	fd = open(fdf->filepath, O_RDONLY);
	x = 0;
	printf("Maps for app is ->\n");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			close(fd);
			break ;
		}
		printf("%s", line);
	}
	fd = open(fdf->filepath, O_RDONLY);
	if (read(fd, NULL, 0) == -1)
	{
		close(fd);
		ft_putstr_fd(ERROR"No file open\n"END, 1);
	}
	close(fd);
}
