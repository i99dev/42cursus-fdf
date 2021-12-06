/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:07:25 by oal-tena          #+#    #+#             */
/*   Updated: 2021/12/04 09:09:26 by oal-tena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/**
 * @brief these function help us to know how many pixels
 * by x and reservation Space on memory, if success return True
 * if failed return false. 
 * 
 * @return Bool 
 */
t_bool	ft_geo_alloc(int fd)
{
	char		*line;
	t_geometry	geo;
	int			xpxl_prv;
	int			xpxl;

	geo.xedges = 0;
	geo.xpxl = 0;
	xpxl_prv = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		xpxl = ft_count_word(line, ' ');
		printf("%d\n", xpxl);
		geo.xpxl += xpxl;
		if (xpxl)
			geo.xedges += xpxl - 1 + ft_min(xpxl, xpxl_prv);
		xpxl_prv = xpxl;
	}
	return (true);
}

//TODO remove printf line on function.

/**
 * @brief  
 * 
 * @param fdf 
 */
void	ft_read_file(t_fdf *fdf)
{
	int		fd;
	int		r;
	char	*line;

	fd = open(fdf->filepath, O_RDONLY);
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
	if (read(fd, NULL, 0) == -1 || !ft_geo_alloc(fd))
	{
		close(fd);
		ft_putstr_fd(ERROR"No file open\n"END, 1);
	}
	close(fd);
}
