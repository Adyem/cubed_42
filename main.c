#include "cubed.h"

static void	ft_initialize_info(t_cubed *info)
{
	info->mlx = NULL;
	info->win = NULL;
	info->map.content = NULL;
	info->textures.east_texture.file_name = NULL;
	info->textures.east_texture.img_ptr = NULL;
	info->textures.west_texture.file_name = NULL;
	info->textures.west_texture.img_ptr = NULL;
	info->textures.north_texture.file_name = NULL;
	info->textures.north_texture.img_ptr = NULL;
	info->textures.south_texture.file_name = NULL;
	info->textures.south_texture.img_ptr = NULL;
	info->map.width = 0;
	info->map.height = 0;
	info->colors.floor_color[0] = -1;
	info->colors.floor_color[1] = -1;
	info->colors.floor_color[2] = -1;
	info->colors.ceiling_color[0] = -1;
	info->colors.ceiling_color[1] = -1;
	info->colors.ceiling_color[2] = -1;
}

int	main(int argc, char **argv)
{
	t_cubed	*info;

	(void)argv;
	if (argc != 2)
		return(ft_printf_fd(2, "Error: Incorrect amount of arguments\n"), 1);
	info = (t_cubed *)malloc(sizeof(t_cubed));
	if (!info)
		return (ft_printf_fd(2, "Error allocating memory for info"), 2);
	ft_initialize_info(info);
	info->map.content = ft_open_and_read(argv[1]);
	if (!info->map.content)
		return (ft_free_info(info), 2);
	ft_parse_map(info);
}
