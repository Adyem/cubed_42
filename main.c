/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:36:40 by bvangene          #+#    #+#             */
/*   Updated: 2024/07/26 10:57:20 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

static void	ft_more_initializing(t_cubed *info)
{
	info->colors.floor_array = NULL;
	info->colors.floor_string = NULL;
	info->colors.ceiling_array = NULL;
	info->colors.ceiling_string = NULL;
}

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
	info->map.map = NULL;
	info->map.copy_map = NULL;
	info->map.player_start_amount = 0;
	ft_more_initializing(info);
	return ;
}

static int	ft_check_extension(char *filename)
{
	char	*ext;
	int		len;
	int		ext_len;
	int		returnv;

	returnv = 0;
	ext = ".cub";
	len = ft_strlen(filename);
	ext_len = ft_strlen(ext);
	if (len <= ext_len)
		returnv = 1;
	returnv = ft_strcmp_cubed(filename + len - ext_len, ext);
	if (returnv)
		ft_printf_fd(2, "Error\n-Extension file incorrect\n");
	return (returnv);
}

int	main(int argc, char **argv)
{
	int		error;
	t_cubed	*info;

	if (argc != 2)
		return (ft_printf_fd(2, "Error\n-Incorrect amount of arguments\n"), 1);
	if (ft_check_extension(argv[1]))
		return (1);
	info = (t_cubed *)malloc(sizeof(t_cubed));
	if (!info)
		return (ft_printf_fd(2, "Error\n-Allocating memory for info\n"), 2);
	ft_initialize_info(info);
	info->map.content = ft_open_and_read(argv[1]);
	if (!info->map.content)
		return (ft_free_info(info), 2);
	error = ft_parse_map(info);
	if (error)
		return (ft_write_error(info, error), error);
	start_mlx(info);
	ft_free_info(info);
	return (0);
}
