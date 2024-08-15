/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:31:31 by kcheung           #+#    #+#             */
/*   Updated: 2024/06/28 14:46:40 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

static void	init_vectors(t_cubed *info, int x, int y)
{
	if (info->map.map[y][x] == 'N')
	{
		info->raydata.dir_y = -1;
		info->raydata.plane_x = 0.66;
		info->raydata.plane_y = 0;
	}
	else if (info->map.map[y][x] == 'S')
	{
		info->raydata.dir_y = 1;
		info->raydata.plane_x = -0.66;
		info->raydata.plane_y = 0;
	}
	else if (info->map.map[y][x] == 'E')
	{
		info->raydata.dir_x = 1;
		info->raydata.plane_x = 0;
		info->raydata.plane_y = 0.66;
	}
	else if (info->map.map[y][x] == 'W')
	{
		info->raydata.dir_x = -1;
		info->raydata.plane_x = 0;
		info->raydata.plane_y = -0.66;
	}
}

static int	key_press(int keycode, t_cubed *info)
{
	if (keycode == ESC)
		destroy_success(info);
	else if (keycode == W)
		info->key.w = 1;
	else if (keycode == S)
		info->key.s = 1;
	else if (keycode == A)
		info->key.a = 1;
	else if (keycode == D)
		info->key.d = 1;
	else if (keycode == LEFT)
		info->key.left = 1;
	else if (keycode == RIGHT)
		info->key.right = 1;
	return (0);
}

static int	key_release(int keycode, t_cubed *info)
{
	if (keycode == W)
		info->key.w = 0;
	else if (keycode == S)
		info->key.s = 0;
	else if (keycode == A)
		info->key.a = 0;
	else if (keycode == D)
		info->key.d = 0;
	else if (keycode == LEFT)
		info->key.left = 0;
	else if (keycode == RIGHT)
		info->key.right = 0;
	return (0);
}

static void	init_basic_value(t_cubed *info, int i, int j)
{
	while (info->map.map[i])
	{
		j = 0;
		while (info->map.map[i][j])
		{
			if (ft_check_entrance(info->map.map[i][j]))
			{
				info->raydata.pos_x = j + 0.5;
				info->raydata.pos_y = i + 0.5;
				info->raydata.dir_x = 0;
				info->raydata.dir_y = 0;
				init_vectors(info, j, i);
				break ;
			}
			j++;
		}
		i++;
	}
	info->colors.floor_rgb = (info->colors.floor_color[0] << 16)
		+ (info->colors.floor_color[1] << 8) + info->colors.floor_color[2];
	info->colors.ceiling_rgb = (info->colors.ceiling_color[0] << 16)
		+ (info->colors.ceiling_color[1] << 8) + info->colors.ceiling_color[2];
	info->textures.tex_h = TEX_HEIGHT;
	info->textures.tex_w = TEX_WIDTH;
}

void	start_mlx(t_cubed *info)
{
	info->key.w = 0;
	info->key.s = 0;
	info->key.a = 0;
	info->key.d = 0;
	info->key.left = 0;
	info->key.right = 0;
	info->textures.ptr_full_img = NULL;
	init_basic_value(info, 0, 0);
	info->mlx = mlx_init();
	init_xpm(info, 0, 0, 0);
	if (!info->mlx)
		return (destroy_error(info, 1));
	info->win = mlx_new_window(info->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (!info->win)
		return (destroy_error(info, 2));
	mlx_loop_hook(info->mlx, game_loop, info);
	mlx_hook(info->win, KeyPress, KeyPressMask, &key_press, info);
	mlx_hook(info->win, KeyRelease, KeyReleaseMask, &key_release, info);
	mlx_hook(info->win, MotionNotify, PointerMotionMask, &mouse_turn, info);
	mlx_hook(info->win, 17, 0, &destroy_success, info);
	mlx_loop(info->mlx);
}
