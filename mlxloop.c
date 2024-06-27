/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxloop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:32:51 by kcheung           #+#    #+#             */
/*   Updated: 2024/06/26 11:06:42 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	destroy_error(t_cubed *info, int err)
{
	if (err == 0)
		ft_putendl_fd("Error creating mlx images", 2);
	else if (err == 1)
		ft_putendl_fd("Error initialising mlx", 2);
	else if (err == 2)
		ft_putendl_fd("Error creating mlx window", 2);
	else if (err == 3)
		ft_putendl_fd("Error creating mlx image", 2);
	ft_free_info(info);
	exit(1);
}

static void	key_move(t_cubed *info)
{
	if (info->key.w == 1)
		move_forward(info);
	if (info->key.s == 1)
		move_backward(info);
	if (info->key.a == 1)
		move_left(info);
	if (info->key.d == 1)
		move_right(info);
	if (info->key.left == 1)
		turning(info, 0, info->raydata.dir_x, info->raydata.plane_x);
	if (info->key.right == 1)
		turning(info, 1, info->raydata.dir_x, info->raydata.plane_x);
}

void	mlx_assign_pixel(int x, int y, int color, t_cubed *info)
{
	char	*dist;

	dist = info->textures.address + (y * info->textures.size_line
			+ x * (info->textures.bits_per_pixel / 8));
	*(unsigned int *)dist = color;
}

static void	draw_ceiling_floor(t_cubed *info)
{
	int	i;
	int	j;

	j = 0;
	while (j < WIN_HEIGHT / 2)
	{
		i = 0;
		while (i < WIN_WIDTH)
		{
			mlx_assign_pixel(i, j, info->colors.ceiling_rgb, info);
			i++;
		}
		j++;
	}
	while (j < WIN_HEIGHT)
	{
		i = 0;
		while (i < WIN_WIDTH)
		{
			mlx_assign_pixel(i, j, info->colors.floor_rgb, info);
			i++;
		}
		j++;
	}
}

int	game_loop(t_cubed *info)
{
	char	*address;

	info->textures.ptr_full_img = mlx_new_image(info->mlx,
			WIN_WIDTH, WIN_HEIGHT);
	if (!info->textures.ptr_full_img)
		destroy_error(info, 0);
	address = mlx_get_data_addr(info->textures.ptr_full_img,
			&info->textures.bits_per_pixel, &info->textures.size_line,
			&info->textures.endian);
	if (!address)
	{
		mlx_destroy_image(info->mlx, info->textures.ptr_full_img);
		destroy_error(info, 0);
	}
	info->textures.address = address;
	draw_ceiling_floor(info);
	raycasting(info);
	key_move(info);
	mlx_put_image_to_window(info->mlx, info->win,
		info->textures.ptr_full_img, 0, 0);
	mlx_destroy_image(info->mlx, info->textures.ptr_full_img);
	return (0);
}
