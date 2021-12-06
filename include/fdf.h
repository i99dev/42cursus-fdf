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
#  include "../lib/mlx_linux/mlx.h"
#  define ESCAPE_KEY 65307
# endif

# ifdef __APPLE__
#  include "key_macos.h"
#  include   "../lib/macos/mlx.h"
#  define ESCAPE_KEY 53
# endif

// INCLUDE OUTSIDE
# include "../lib/libft/libft.h"

// c libery
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

// INCLUDE INSIDE
# include "get_next_line.h"
# include "geometry.h"
# include "moues.h"
# include "image.h"
# include "utils.h"
# include "tools.h"
# include "window.h"

// massega color
# define INFO		"\x1b[1m"
# define WARNING	"\x1b[33m"
# define ERROR		"\x1b[31m"
# define SUCCESS	"\x1b[32m"
# define END		"\x1b[0m"

// color 
# define WHITE		0xFFFFFF
# define BLACK		0x000000
# define RED		0xFF0000
# define GREEN		0x00FF00
# define BLUE		0x0000FF
# define YELLOW		0xFFFF00
# define CYAN		0x00FFFF
# define MAGENTA	0xFF00FF

// screen size
# define SCREEN_WIDTH 1080
# define SCREEN_HEIGHT 600

void	ft_read_file(t_fdf *fdf);

#endif