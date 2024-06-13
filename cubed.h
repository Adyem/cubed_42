#ifndef CUBED_H
# define CUBED_H

# include "minilibx-linux/mlx.h"
# include "libft/libft/libft.h"
# include "libft/printf/ft_printf.h"
# include "libft/printf_fd/ft_printf_fd.h"
# include "libft/get_next_line/get_next_line.h"

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

# ifndef DEBUG
#  define DEBUG 0
# endif

#endif
