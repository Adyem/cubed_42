/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:11:08 by kcheung           #+#    #+#             */
/*   Updated: 2024/06/27 13:13:48 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	move_forward(t_cubed *info)
{
	if (info->map.map[(int)(info->raydata.pos_y)]
		[(int)(info->raydata.pos_x + info->raydata.dir_x * 0.08)] != '1')
		info->raydata.pos_x += info->raydata.dir_x * 0.08;
	if (info->map.map[(int)(info->raydata.pos_y + info->raydata.dir_y * 0.08)]
		[(int)(info->raydata.pos_x)] != '1')
		info->raydata.pos_y += info->raydata.dir_y * 0.08;
}

void	move_backward(t_cubed *info)
{
	if (info->map.map[(int)(info->raydata.pos_y)]
		[(int)(info->raydata.pos_x - info->raydata.dir_x * 0.08)] != '1')
		info->raydata.pos_x -= info->raydata.dir_x * 0.08;
	if (info->map.map[(int)(info->raydata.pos_y - info->raydata.dir_y * 0.08)]
		[(int)(info->raydata.pos_x)] != '1')
		info->raydata.pos_y -= info->raydata.dir_y * 0.08;
}

void	turning(t_cubed *info, int dir, double olddirx, double oldplanex)
{
	if (dir == 0)
	{
		info->raydata.dir_x = info->raydata.dir_x * cos(-0.048)
			- info->raydata.dir_y * sin(-0.048);
		info->raydata.dir_y = olddirx * sin(-0.048)
			+ info->raydata.dir_y * cos(-0.048);
		info->raydata.plane_x = info->raydata.plane_x * cos(-0.048)
			- info->raydata.plane_y * sin(-0.048);
		info->raydata.plane_y = oldplanex * sin(-0.048)
			+ info->raydata.plane_y * cos(-0.048);
	}
	else if (dir == 1)
	{
		info->raydata.dir_x = info->raydata.dir_x * cos(0.048)
			- info->raydata.dir_y * sin(0.048);
		info->raydata.dir_y = olddirx * sin(0.048)
			+ info->raydata.dir_y * cos(0.048);
		info->raydata.plane_x = info->raydata.plane_x * cos(0.048)
			- info->raydata.plane_y * sin(0.048);
		info->raydata.plane_y = oldplanex * sin(0.048)
			+ info->raydata.plane_y * cos(0.048);
	}
}

void	move_left(t_cubed *info)
{
	if (info->map.map[(int)(info->raydata.pos_y)]
		[(int)(info->raydata.pos_x + info->raydata.dir_y * 0.08)] != '1')
		info->raydata.pos_x += info->raydata.dir_y * 0.08;
	if (info->map.map[(int)(info->raydata.pos_y - info->raydata.dir_x * 0.08)]
		[(int)info->raydata.pos_x] != '1')
		info->raydata.pos_y -= info->raydata.dir_x * 0.08;
}

void	move_right(t_cubed *info)
{
	if (info->map.map[(int)(info->raydata.pos_y)]
		[(int)(info->raydata.pos_x - info->raydata.dir_y * 0.08)] != '1')
		info->raydata.pos_x -= info->raydata.dir_y * 0.08;
	if (info->map.map[(int)(info->raydata.pos_y + info->raydata.dir_x * 0.08)]
		[(int)info->raydata.pos_x] != '1')
		info->raydata.pos_y += info->raydata.dir_x * 0.08;
}
