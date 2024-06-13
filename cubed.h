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
	int		width;
	int		height;
}	t_map;

typedef struct s_textures
{
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
}	t_textures;

typedef struct s_colors
{
	int	floor_color[3];
	int	ceiling_color[3];
}	t_colors;

typedef struct s_cubed
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_textures	textures;
	t_colors	colors;
}	t_cubed;


/*parse map*/
void	ft_parse_map(t_cubed *info);

/*open map*/
char	**ft_open_and_read(char *file);

/*free memory*/
void	ft_free_info(t_cubed *info);

#endif
