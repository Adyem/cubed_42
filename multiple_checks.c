#include "cubed.h"

int	ft_check_malloc_texture(t_cubed *info)
{
	if (!info->textures.north_texture.file_name)
		return (2);
	if (!info->textures.south_texture.file_name)
		return (2);
	if (!info->textures.west_texture.file_name)
		return (2);
	if (!info->textures.east_texture.file_name)
		return (2);
	if (!info->colors.floor_string)
		return (2);
	if (!info->colors.ceiling_string)
		return (2);
	return (0);
}

/*The" == 0 in the return is removed. ft_check_images returns 0 if successful,
the == 0 in return makes 0 from ft_check_images 1 (0 == 0, so it is one), and
all other returns from ft_check_images become 0 (because 4 != 0 and 2 != 0)*/

int	ft_check_textures_and_colors(t_cubed *info, char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (ft_check_images(&info->textures.north_texture.file_name,
				line, "NO "));
	else if (ft_strncmp(line, "SO ", 3) == 0)
		return (ft_check_images(&info->textures.south_texture.file_name,
				line, "SO "));
	else if (ft_strncmp(line, "WE ", 3) == 0)
		return (ft_check_images(&info->textures.west_texture.file_name,
				line, "WE "));
	else if	(ft_strncmp(line, "EA ", 3) == 0)
		return (ft_check_images(&info->textures.east_texture.file_name,
				line, "EA "));
	else if (ft_strncmp(line, "F ", 2) == 0)
		return (ft_check_colors(&info->colors.floor_string,
				line, "F "));
	else if (ft_strncmp(line, "C ", 2) == 0)
		return (ft_check_colors(&info->colors.ceiling_string,
				line, "C "));
	return (4);
}

int	ft_all_found(t_cubed *info)
{
	int	i;

	i = 0;
	if (info->textures.east_texture.file_name)
		i++;
	if (info->textures.west_texture.file_name)
		i++;
	if (info->textures.north_texture.file_name)
		i++;
	if (info->textures.south_texture.file_name)
		i++;
	if (info->colors.floor_string)
		i++;
	if (info->colors.ceiling_string)
		i++;
	if (i == 6)
		return (0);
	return (1);
}
