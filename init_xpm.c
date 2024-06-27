/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_xpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:19:46 by kcheung           #+#    #+#             */
/*   Updated: 2024/06/25 11:48:16 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	texture_to_array(int *address, int i, t_cubed *info)
{
	int	x;
	int	y;

	y = 0;
	while (y < TEX_HEIGHT)
	{
		x = 0;
		while (x < TEX_WIDTH)
		{
			info->textures.texture[i][TEX_HEIGHT * y + x]
				= (address[TEX_HEIGHT * y + x]);
			x++;
		}
		y++;
	}
}

void	init_xpm_b(t_cubed *info, int tmp_bit, int tmp_len, int tmp_end)
{
	int		*address;

	info->textures.south_texture.img_ptr = mlx_xpm_file_to_image(info->mlx,
			info->textures.south_texture.file_name,
			&(info->textures.tex_w), &(info->textures.tex_h));
	if (!info->textures.south_texture.img_ptr)
		destroy_error(info, 3);
	address = (int *)mlx_get_data_addr(info->textures.south_texture.img_ptr,
			&tmp_bit, &tmp_len, &tmp_end);
	if (!address)
		destroy_error(info, 3);
	texture_to_array(address, 2, info);
	info->textures.west_texture.img_ptr = mlx_xpm_file_to_image(info->mlx,
			info->textures.west_texture.file_name,
			&(info->textures.tex_w), &(info->textures.tex_h));
	if (!info->textures.west_texture.img_ptr)
		destroy_error(info, 3);
	address = (int *)mlx_get_data_addr(info->textures.west_texture.img_ptr,
			&tmp_bit, &tmp_len, &tmp_end);
	if (!address)
		destroy_error(info, 3);
	texture_to_array(address, 3, info);
}

void	init_xpm(t_cubed *info, int tmp_bit, int tmp_len, int tmp_end)
{
	int		*address;

	info->textures.north_texture.img_ptr = mlx_xpm_file_to_image(info->mlx,
			info->textures.north_texture.file_name,
			&(info->textures.tex_w), &(info->textures.tex_h));
	if (!info->textures.north_texture.img_ptr)
		destroy_error(info, 3);
	address = (int *)mlx_get_data_addr(info->textures.north_texture.img_ptr,
			&tmp_bit, &tmp_len, &tmp_end);
	if (!address)
		destroy_error(info, 3);
	texture_to_array(address, 0, info);
	info->textures.east_texture.img_ptr = mlx_xpm_file_to_image(info->mlx,
			info->textures.east_texture.file_name,
			&(info->textures.tex_w), &(info->textures.tex_h));
	if (!info->textures.east_texture.img_ptr)
		destroy_error(info, 3);
	address = (int *)mlx_get_data_addr(info->textures.east_texture.img_ptr,
			&tmp_bit, &tmp_len, &tmp_end);
	if (!address)
		destroy_error(info, 3);
	texture_to_array(address, 1, info);
	init_xpm_b(info, 0, 0, 0);
}
