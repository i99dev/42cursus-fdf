/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:02:18 by oal-tena          #+#    #+#             */
/*   Updated: 2021/12/12 09:57:30 by oal-tena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include "fdf.h"

/**
 * @brief image structer for store all pixel data on the screen
 * @param imag for onlu use somthing like a pointer to the image
 *
 */
typedef struct e_image
{
	void	*img_ptr;
	char	*img_addr;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
}	t_image;

#endif