/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:36:40 by bvangene          #+#    #+#             */
/*   Updated: 2024/07/26 10:56:50 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBED_H
# define CUBED_H

# include "minilibx-linux/mlx.h"
# include "libft/libft/libft.h"
# include "libft/printf/ft_printf.h"
# include "libft/printf_fd/ft_printf_fd.h"
# include "libft/get_next_line/get_next_line.h"
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <stdlib.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdbool.h>

# ifndef DEBUG
#  define DEBUG 0
# endif

# define WIN_HEIGHT			900
# define WIN_WIDTH			1440
# define TEX_HEIGHT 		64
# define TEX_WIDTH 			64

/*keycode*/
# define ESC 					65307
# define W 						119
# define A 						97
# define S 						115
# define D 						100
# define UP 					65362
# define DOWN 					65364
# define LEFT 					65361
# define RIGHT 					65363

typedef struct s_raydata
{
	double			pos_x;
	double			pos_y;
	int				map_x;
	int				map_y;
	double			dir_x;
	double			dir_y;
	double			camera_x;
	double			raydir_x;
	double			raydir_y;
	double			plane_x;
	double			plane_y;
	int				hit;
	int				tex_num;
	double			deltadist_x;
	double			deltadist_y;
	int				step_x;
	int				step_y;
	double			sidedist_x;
	double			sidedist_y;
	int				side;
	double			perp_dist;
	int				line_height;
	int				draw_start;
	int				draw_end;
	double			wall_x;
	int				tex_x;
	int				tex_y;
	unsigned int	color;
}	t_raydata;

typedef struct s_key
{
	int	w;
	int	s;
	int	a;
	int	d;
	int	right;
	int	left;
}				t_key;

typedef struct s_map
{
	char	**content;
	char	**map;
	char	**copy_map;
	int		width;
	int		height;
	int		player_start_amount;
}	t_map;

typedef struct s_texture_data
{
	char	*file_name;
	void	*img_ptr;
}	t_texture_data;

typedef struct s_textures
{
	t_texture_data	north_texture;
	t_texture_data	south_texture;
	t_texture_data	west_texture;
	t_texture_data	east_texture;
	void			*ptr_full_img;
	char			*address;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				texture[4][TEX_HEIGHT * TEX_WIDTH];
	int				tex_h;
	int				tex_w;
}	t_textures;

typedef struct s_colors
{
	char	*floor_string;
	char	**floor_array;
	char	*ceiling_string;
	char	**ceiling_array;
	int		floor_color[3];
	int		ceiling_color[3];
	int		floor_rgb;
	int		ceiling_rgb;
}	t_colors;

typedef struct s_cubed
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_textures	textures;
	t_colors	colors;
	t_raydata	raydata;
	t_key		key;
}	t_cubed;

/*error managment*/
void	ft_write_error(t_cubed *info, int error);
int		mouse_turn(int x, int y, t_cubed *info);

/*parse map*/
int		ft_parse_map(t_cubed *info);
int		ft_check_map(t_cubed *info, int i);
int		ft_check_images(char **image, char *string, char *check);
int		ft_check_colors(char **color_string, char *string, char *check);
int		ft_check_malloc_texture(t_cubed *info);
int		ft_check_textures_and_colors(t_cubed *info, char *line);
int		ft_all_found(t_cubed *info);

/*open map*/
char	**ft_open_and_read(char *file);

/*check map*/
int		ft_find_entrance(t_cubed *info);
int		ft_check_entrance(char character);

/*free memory*/
void	ft_free_info(t_cubed *info);

/*flooder*/
int		ft_flooder(t_cubed *info);

/*utils*/
int		ft_strcmp_cubed(char *string1, char *string2);
int		ft_check_value_rgb(char *input);
int		ft_check_length(char **pointer);
char	*ft_strdup_no_ln(const char *s1);
int		ft_check_color_string(char *string);

/*start_mlx*/
void	start_mlx(t_cubed *info);

/*mlxloop*/
int		game_loop(t_cubed *info);
void	mlx_assign_pixel(int x, int y, int color, t_cubed *info);
void	destroy_error(t_cubed *info, int err);

/*raycasting*/
void	raycasting(t_cubed *info);

/*ray_draw*/
void	draw_vertical_tex(t_cubed *info, int x);
void	get_tex_x(t_cubed *info);
void	draw_line_start_end(t_cubed *info);
void	vertical_height(t_cubed *info);
int		destroy_success(t_cubed *info);

/*movement*/
void	move_forward(t_cubed *info);
void	move_backward(t_cubed *info);
void	turning(t_cubed *info, int dir, double olddirx, double oldplanex);
void	move_left(t_cubed *info);
void	move_right(t_cubed *info);

/*init_xpm*/
void	init_xpm(t_cubed *info, int tmp_bit, int tmp_len, int tmp_end);

#endif
