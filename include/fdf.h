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

// INCLUDE
# include "../lib/mlx_linux/mlx.h"
# include "../lib/libft/libft.h"
# include "../tools/tools.h"
# include <stdio.h>

// COLOR
# define RED		"\x1b[31m"
# define GREEN		"\x1b[32m"
# define YELLOW		"\x1b[33m"
# define BLUE		"\x1b[34m"
# define MAGENTA	"\x1b[35m"
# define CYAN		"\x1b[36m"
# define RESET		"\x1b[0m"

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