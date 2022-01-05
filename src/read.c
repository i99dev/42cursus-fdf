/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:10:57 by oal-tena          #+#    #+#             */
/*   Updated: 2022/01/05 13:33:43 by oal-tena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/**
 * @brief ft_strlen_c is coustom strlen function to 
 * count the number of char space in a string
 * 
 * @param c *line of the map
 * @return int 
 */
int	ft_strlen_c(const char *c )
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (c[i] != '\0')
	{
		if (c[i] == ' ' && c[i + 1] != ' ')
			j++;
		i++;
	}
	return (j + 1);
}

int	*convert_to_matrix(char *line)
{
	int		i;
	int		*matrix;
	char	**split;

	i = 0;
	matrix = (int *)malloc(sizeof(int) * (ft_strlen_c(line) + 1));
	split = ft_split(line, ' ');
	while (split[i])
	{
		matrix[i] = ft_atoi(split[i]);
		i++;
	}
	matrix[i] = 0;
	return (matrix);
}

void	ft_read_file(char *file_path, t_fdf *fdf)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fdf->map_height = 0;
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		ft_putstr_fd("Error can't read file", 1);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (i == 0)
			fdf->map_width = ft_strlen_c(line);
		fdf->map_height++;
		i++;
	}
	close(fd);
	fdf->map = (int **)malloc(sizeof(int *) * fdf->map_height);
	fd = open(file_path, O_RDONLY);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		fdf->map[i] = convert_to_matrix(line);
		i++;
	}
	close(fd);
}
