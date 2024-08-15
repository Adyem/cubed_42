/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:16:47 by kcheung           #+#    #+#             */
/*   Updated: 2024/06/27 13:34:18 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int	destroy_success(t_cubed *info)
{
	ft_free_info(info);
	exit(0);
	return (0);
}

void	vertical_height(t_cubed *info)
{
	if (info->raydata.side == 0)
		info->raydata.perp_dist
			= (info->raydata.sidedist_x - info->raydata.deltadist_x);
	else
		info->raydata.perp_dist
			= (info->raydata.sidedist_y - info->raydata.deltadist_y);
	info->raydata.line_height = (int)(WIN_HEIGHT / info->raydata.perp_dist);
}

void	draw_line_start_end(t_cubed *info)
{
	info->raydata.draw_start
		= -1 * info->raydata.line_height / 2 + WIN_HEIGHT / 2;
	if (info->raydata.draw_start < 0)
		info->raydata.draw_start = 0;
	info->raydata.draw_end = info->raydata.line_height / 2 + WIN_HEIGHT / 2;
	if (info->raydata.draw_end >= WIN_HEIGHT)
		info->raydata.draw_end = WIN_HEIGHT - 1;
}

void	get_tex_x(t_cubed *info)
{
	if (info->raydata.side == 0)
		info->raydata.wall_x = info->raydata.pos_y
			+ info->raydata.perp_dist * info->raydata.raydir_y;
	else
		info->raydata.wall_x = info->raydata.pos_x
			+ info->raydata.perp_dist * info->raydata.raydir_x;
	info->raydata.wall_x -= floor((info->raydata.wall_x));
	info->raydata.tex_x = (int)(info->raydata.wall_x * (double)TEX_WIDTH);
	if (info->raydata.side == 0 && info->raydata.raydir_x < 0)
		info->raydata.tex_x = TEX_WIDTH - info->raydata.tex_x - 1;
	if (info->raydata.side == 1 && info->raydata.raydir_y > 0)
		info->raydata.tex_x = TEX_WIDTH - info->raydata.tex_x - 1;
}

void	draw_vertical_tex(t_cubed *info, int x)
{
	double	step;
	double	tex_pos;
	int		y;

	step = 1.0 * TEX_HEIGHT / info->raydata.line_height;
	tex_pos = (info->raydata.draw_start
			- WIN_HEIGHT / 2 + info->raydata.line_height / 2) * step;
	y = info->raydata.draw_start;
	while (y < info->raydata.draw_end)
	{
		info->raydata.tex_y = (int)tex_pos & (TEX_HEIGHT - 1);
		tex_pos += step;
		info->raydata.color = info->textures.texture[info->raydata.tex_num]
		[TEX_HEIGHT * info->raydata.tex_y + info->raydata.tex_x];
		if (info->raydata.side == 1)
			info->raydata.color = (info->raydata.color >> 1) & 8355711;
		mlx_assign_pixel(x, y, info->raydata.color, info);
		y++;
	}
}
