/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:02:22 by kcheung           #+#    #+#             */
/*   Updated: 2024/06/26 14:40:20 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

static void	select_texture(t_cubed *info)
{
	if (info->raydata.side == 0)
	{
		if (info->raydata.map_x > info->raydata.pos_x)
			info->raydata.tex_num = 1;
		else
			info->raydata.tex_num = 3;
	}
	else
	{
		if (info->raydata.map_y > info->raydata.pos_y)
			info->raydata.tex_num = 2;
		else
			info->raydata.tex_num = 0;
	}
}

static void	dda(t_cubed *info)
{
	while (info->raydata.hit == 0)
	{
		if (info->raydata.sidedist_x < info->raydata.sidedist_y)
		{
			info->raydata.sidedist_x += info->raydata.deltadist_x;
			info->raydata.map_x += info->raydata.step_x;
			info->raydata.side = 0;
		}
		else
		{
			info->raydata.sidedist_y += info->raydata.deltadist_y;
			info->raydata.map_y += info->raydata.step_y;
			info->raydata.side = 1;
		}
// temp value as the map parser is not correct and caused crashing. it should be == '1' instead of > 0
		if (info->map.map[info->raydata.map_y][info->raydata.map_x] == '1')
		{
			info->raydata.hit = 1;
			select_texture(info);
		}
	}
}

static void	init_ray_sidedist(t_cubed *info)
{
	if (info->raydata.raydir_x < 0)
	{
		info->raydata.step_x = -1;
		info->raydata.sidedist_x = (info->raydata.pos_x
				- info->raydata.map_x) * info->raydata.deltadist_x;
	}
	else
	{
		info->raydata.step_x = 1;
		info->raydata.sidedist_x = (info->raydata.map_x + 1.0
				- info->raydata.pos_x) * info->raydata.deltadist_x;
	}
	if (info->raydata.raydir_y < 0)
	{
		info->raydata.step_y = -1;
		info->raydata.sidedist_y = (info->raydata.pos_y
				- info->raydata.map_y) * info->raydata.deltadist_y;
	}
	else
	{
		info->raydata.step_y = 1;
		info->raydata.sidedist_y = (info->raydata.map_y + 1.0
				- info->raydata.pos_y) * info->raydata.deltadist_y;
	}
}

static void	init_ray_value(t_cubed *info, int x)
{
	info->raydata.camera_x = 2 * x / (double)WIN_WIDTH - 1;
	info->raydata.raydir_x = info->raydata.dir_x
		+ info->raydata.plane_x * info->raydata.camera_x;
	info->raydata.raydir_y = info->raydata.dir_y
		+ info->raydata.plane_y * info->raydata.camera_x;
	info->raydata.map_x = (int)info->raydata.pos_x;
	info->raydata.map_y = (int)info->raydata.pos_y;
	info->raydata.hit = 0;
	if (info->raydata.raydir_x == 0)
		info->raydata.deltadist_x = 1e30;
	else
		info->raydata.deltadist_x = fabs(1 / info->raydata.raydir_x);
	if (info->raydata.raydir_y == 0)
		info->raydata.deltadist_y = 1e30;
	else
		info->raydata.deltadist_y = fabs(1 / info->raydata.raydir_y);
	init_ray_sidedist(info);
}

void	raycasting(t_cubed *info)
{
	int	x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		init_ray_value(info, x);
		dda(info);
		vertical_height(info);
		draw_line_start_end(info);
		get_tex_x(info);
		draw_vertical_tex(info, x);
		x++;
	}
}
