/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:07:25 by oal-tena          #+#    #+#             */
/*   Updated: 2021/12/04 04:12:02 by oal-tena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/**
 * @brief these functions help us to know how many pixels
 * by x and reservation Space on memory, if success return True
 * if failed return false. 
 * 
 * @return Bool 
 */
t_bool	ft_geo_alloc(int fd)
{
	char	*line;
	int		s;
	int		sedag;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		s = ft_count_split(line, ' ');
	}
	return (1);
}

/**
 * @brief  
 * 
 * @param fdf 
 */
void	ft_read_file(t_fdf *fdf)
{
	int	fd;
	int	r;

	fd = open(fdf->filepath, O_RDONLY);
	r = read(fd, NULL, BUFFER_SIZE);
	if (!ft_geo_alloc(fd))
	{
		close(fd);
		ft_putstr_fd(ERROR"No file open\n"END, 1);
	}
	close(fd);
}
