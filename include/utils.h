/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 06:20:04 by oal-tena          #+#    #+#             */
/*   Updated: 2021/12/06 12:15:50 by oal-tena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "fdf.h"
# include "window.h"

typedef enum e_bool
{
	false,
	true
}				t_bool;

int		ft_count_word(char *line, char c);
int		ft_min(int a, int b);
t_bool	hook_windoes_layout(t_fdf *fdf);

#endif