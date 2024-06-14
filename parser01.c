#include "cubed.h"

static int	ft_check_images(char **image, char *string, char *check)
{
	if (ft_strncmp(string, check, 3) == 0)
		*image = ft_strdup(&string[3]);
	if (!*image)
	{
		ft_printf_fd(2, "Error allocating memory Image name\n");
		return (2);
	}
	return (0);
}

static int	ft_check_colers(char **coler_string, char *string, char *check)
{
	if (ft_strncmp(string, check, 2))
		*coler_string = ft_strdup(&string[2]);
	if (!*coler_string)
	{
		ft_printf_fd(2, "Error allocating memory Coler string\n");
		return (2);
	}
	return (0);
}

int	ft_parse_map(t_cubed *info)
{
	int	error;

	error = 0;
	error += ft_check_images(&info->textures.north_texture.file_name,
			info->map.content[0], "NO ");
	error += ft_check_images(&info->textures.south_texture.file_name,
			info->map.content[1], "SO ");
	error += ft_check_images(&info->textures.west_texture.file_name,
			info->map.content[2], "WE ");
	error += ft_check_images(&info->textures.east_texture.file_name,
			info->map.content[3], "EA ");
	error += ft_check_colers(&info->colors.floor_string,
			info->map.content[5], "F ");
	error += ft_check_colers(&info->colors.ceiling_string,
			info->map.content[6], "C ");
	if (error)
		return (2);
	if (ft_strlen(info->map.content[4]) != 1)
		return (4);
	error = ft_parse_map_2(info);
	return (error);
}
