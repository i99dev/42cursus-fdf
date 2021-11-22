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
#  include "key_linux.h"
#  define ESCAPE_KEY 65307
# endif

# ifdef __APPLE__
#  include "key_macos.h"
#  define ESCAPE_KEY 53
# endif

# include "mlx.h"
# include "tools.h"
# include <stdio.h>

# define HIGH_SCREEN_WIDTH 640
# define HIGH_SCREEN_HEIGHT 480

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

typedef enum bool
{
	false,
	true
}	t_bool;

#endif