#include "cubed.h"

void	ft_free_double_char(char **content)
{
	int	i;

	i = 0;
	if (content)
	{
		while (content[i])
		{
			free(content[i]);
			i++;
		}
		free(content);
	}
	return ;
}

static void	ft_free_mlx(t_cubed *info)
{
	if (info->mlx && info->win)
		mlx_destroy_window(info->mlx, info->win);
	if (info->mlx)
		mlx_destroy_display(info->mlx);
}

void	ft_free_info(t_cubed *info)
{
	ft_free_double_char(info->map.content);
	ft_free_mlx(info);
	free(info);
}
