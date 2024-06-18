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

# ifndef DEBUG
#  define DEBUG 0
# endif

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
}	t_textures;

typedef struct s_colors
{
	char	*floor_string;
	char	**floor_array;
	char	*ceiling_string;
	char	**ceiling_array;
	int		floor_color[3];
	int		ceiling_color[3];
}	t_colors;

typedef struct s_cubed
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_textures	textures;
	t_colors	colors;
}	t_cubed;

/*error managment*/
void	ft_write_error(t_cubed *info, int error);

/*parse map*/
int		ft_parse_map(t_cubed *info);
int		ft_check_map(t_cubed *info);

/*open map*/
char	**ft_open_and_read(char *file);

/*free memory*/
void	ft_free_info(t_cubed *info);

/*utils*/
int		ft_strcmp_cubed(char *string1, char *string2);
int		ft_check_value_rgb(char *input);
int		ft_check_length(char **pointer);

#endif
