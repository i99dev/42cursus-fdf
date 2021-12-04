/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 06:20:04 by oal-tena          #+#    #+#             */
/*   Updated: 2021/12/04 06:04:58 by oal-tena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "fdf.h"
# include "window.h"

int		ft_count_split(char *line, char c);
int		ft_min(int a, int b);

typedef enum e_bool
{
	false,
	true
}				t_bool;
#endif