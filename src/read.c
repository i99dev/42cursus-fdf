/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:10:57 by oal-tena          #+#    #+#             */
/*   Updated: 2022/01/03 13:34:28 by oal-tena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void ft_read_file(char *file_path, t_fdf *fdf)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	if ((fd = open(file_path, O_RDONLY)) == -1)
		close(fd);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		fdf->map[i] = ft_split(line, ' ');
		i++;
	}
	fdf->map_height = i;
	fdf->map_width = ft_strlen(fdf->map[0]);
	close(fd);
}