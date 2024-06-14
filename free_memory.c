#include "cubed.h"
#include "minilibx-linux/mlx.h"

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
	if (info->textures.east_texture.img_ptr && info->mlx)
		mlx_destroy_image(info->mlx, info->textures.east_texture.img_ptr);
	if (info->textures.west_texture.img_ptr && info->mlx)
		mlx_destroy_image(info->mlx, info->textures.west_texture.img_ptr);
	if (info->textures.north_texture.img_ptr && info->mlx)
		mlx_destroy_image(info->mlx, info->textures.north_texture.img_ptr);
	if (info->textures.south_texture.img_ptr && info->mlx)
		mlx_destroy_image(info->mlx, info->textures.south_texture.img_ptr);
	if (info->mlx && info->win)
		mlx_destroy_window(info->mlx, info->win);
	if (info->mlx)
		mlx_destroy_display(info->mlx);
	free(info->mlx);
}

void	ft_free_info(t_cubed *info)
{
	free(info->textures.south_texture.file_name);
	free(info->textures.north_texture.file_name);
	free(info->textures.east_texture.file_name);
	free(info->textures.west_texture.file_name);
	ft_free_double_char(info->map.content);
	ft_free_double_char(info->map.map);
	ft_free_double_char(info->map.copy_map);
	ft_free_mlx(info);
	free(info);
}
