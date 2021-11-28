/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:07:25 by oal-tena          #+#    #+#             */
/*   Updated: 2021/11/28 09:28:18 by oal-tena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/**
 * @brief set image size 
 * 
 * @param width the width for image and type is int.
 * @param height the height for image and type is int.
 */
void	set_image_size(int width, int height)
{
	t_image	img;

	img.width = width;
	img.height = height;
}

void	drawing_line(void)
{
}

/**
 * @brief read_file function to read fdf file and convert all data to int
 * and save on image data struct. 
 * 
 * @param fdf 
 */
void	read_file(t_fdf *fdf)
{
	char		*temp;
	int			fd;
	int			width;
	int			height;

	fd = open(fdf->filepath, O_RDONLY);
	if (fd == -1)
		ft_putstr_fd(ERROR"Error: File not found\n"END, 1);
	width = 0;
	height = 0;
	while (1)
	{
		temp = get_next_line(fd);
		if (width == 0)
			width = ft_strlen(temp);
		if (!temp)
			break ;
		height++;
		printf("%s", temp);
		free(temp);
	}
	set_image_size(width, height);
}
