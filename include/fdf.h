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

# define P_WIDTH 1280
# define P_HEIGHT 720
# define XY_ZOOM 0.005
# define Z_ZOOM 0.005

typedef struct t_fdf
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*img_data;
	char		*file_path;
	char		*data_addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			bpp;
	int			width;
	int			img_width;
	int			img_height;
	int			height;
	float		zoom;
	float		move_x;
	float		move_y;
	int			color;
	int			**map;
	int			map_width;
	int			map_height;
	int			map_dx;
	int			map_dy;
	int			x0;
	int			y0;
	int			x1;
	int			y1;
	int			x;
	int			y;
	int			step_x;
	int			step_y;
	int			del_error;
	int			max_z;
	int			min_z;
	int			map_x_size;
	int			map_y_size;
	double		xy_zoom;
	int			iso;
	double		angle;
	int			camera;
	int			x_shift;
	int			y_shift;
	double		z_zoom;
	int			z1;
	int			z0;
	double		x_axis;
	double		y_axis;
	double		z_axis;
	double		degree_angle;

}				t_fdf;

void	regsiter_hooks(t_fdf *fdf);
void	ft_read_file(char *file_path, t_fdf *fdf);
void	put_map_image(t_fdf *fdf);
void	create_new_img(t_fdf *fdf);
void	ft_drwa_line(t_fdf *fdf);

// camera function 
double	degree_to_radian(double degrees);
void	rotation_matrix(t_fdf *fdf, int *x, int *y, int z);
void	change_projection_view(t_fdf *fdf);
void	rotate_x_axis(t_fdf *fdf, int *y, int *z, double x_axis);
void	rotate_y_axis(t_fdf *fdf, int *x, int *z, double y_axis);
void	rotate_z_axis(t_fdf *fdf, int *x, int *y, double z_axis);
void	shift_and_centeralize_map(t_fdf *fdf);
void	adjust_zoom(t_fdf *fdf, int normalize);
void	rotate_xyz_axis(t_fdf *fdf);
void	implement_transformations(t_fdf *fdf, int normalize);
int		ft_normalize(t_fdf *fdf);

//handle_line
void	rotate_vertical_line(t_fdf *fdf);
void	rotate_horizontal_line(t_fdf *fdf);
void	ft_y(t_fdf *fdf);
void	ft_x(t_fdf *fdf);

//ft_put_pixel
void	ft_put_pixel_image(t_fdf *fdf, int x, int y, int color);

#endif