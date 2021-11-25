/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:02:18 by oal-tena          #+#    #+#             */
/*   Updated: 2021/11/25 01:42:49 by oal-tena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

/**
 * @brief image structer for store all pixel data on the screen
 * @param imag for onlu use somthing like a pointer to the image
 * 
 */
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