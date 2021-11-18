/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 16:23:11 by oal-tena          #+#    #+#             */
/*   Updated: 2021/11/16 11:12:02 by oal-tena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifdef __linux__
#  include "../include/key_linux.h"
#  define ESCAPE_KEY 65307
# endif

# ifdef __APPLE__
#  include "../include/key_macos.h"
#  define ESCAPE_KEY 53
# endif

# include "mlx.h"
# include "../tools/tools.h"
# include <stdio.h>

typedef struct moues
{
	int		x;
	int		y;
}				t_moues;

typedef struct vars
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_moues	mouse;
}				t_vars;

typedef struct t_data
{
	void	*image;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
}	t_data;

#endif