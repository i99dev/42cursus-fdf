/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 06:59:03 by oal-tena          #+#    #+#             */
/*   Updated: 2021/12/12 10:03:53 by oal-tena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

/**
 * @brief e_fdf struct for all fdf project data.
 * 
 * @param mlx_ptr pointer to the mlx library.
 * @param win_ptr pointer to the window.
 * @param mouse pointer to the mouse.
 * 
 */
typedef struct e_fdf
{
	char	*filepath;
	void	*mlx_ptr;
	void	*win_ptr;
	t_moues	mouse;
	t_image	img;
}				t_fdf;
#endif