/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moues.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 06:16:47 by oal-tena          #+#    #+#             */
/*   Updated: 2021/11/22 11:27:06 by oal-tena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOUES_H
# define MOUES_H

# include "fdf.h"

/**
 * @brief  mouse event handler function prototype
 * @param  x
 * @param  y
 * 
 */
typedef struct s_moues
{
	int			x;
	int			y;
}				t_moues;

#endif