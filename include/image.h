/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:02:18 by oal-tena          #+#    #+#             */
/*   Updated: 2021/11/24 09:16:39 by oal-tena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

typedef struct e_image
{
	void	*img;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
}				t_image;

#endif