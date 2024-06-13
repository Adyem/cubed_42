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

typedef struct	s_map
{
	char	**content;
} t_map;

typedef struct	s_cubed
{
	void	*mlx;
	void	*win;
	t_map	map;
} t_cubed;

/*open map*/
char	**ft_open_and_read(char *file);

/*free memory*/
void	ft_free_info(t_cubed *info);

# ifndef DEBUG
#  define DEBUG 0
# endif

#endif
