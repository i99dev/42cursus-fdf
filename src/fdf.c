/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:07:25 by oal-tena          #+#    #+#             */
/*   Updated: 2021/11/24 12:11:12 by oal-tena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	read_file(t_fdf *fdf)
{
	int			fd;
	int			size;
	static char	*line;

	fd = open(fdf->filepath, O_RDONLY);
	printf("file fd is:%d\n", fd);
	get_next_line(fd);
}
