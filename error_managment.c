/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_managment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:36:40 by bvangene          #+#    #+#             */
/*   Updated: 2024/07/26 10:57:03 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int	mouse_turn(int x, int y, t_cubed *info)
{
	int			x1;
	int			y1;
	static int	old_x;

	x1 = 0;
	y1 = 0;
	(void)y;
	if (!old_x)
		old_x = WIN_WIDTH / 2;
	mlx_mouse_get_pos(info->mlx, info->win, &x1, &y1);
	if (x1 < WIN_WIDTH && x1 > 0 && y1 > 0 && y1 < WIN_HEIGHT)
	{
		if (x < old_x)
			turning(info, 0, info->raydata.dir_x, info->raydata.plane_x);
		else if (x > old_x)
			turning(info, 1, info->raydata.dir_x, info->raydata.plane_x);
	}
	old_x = x;
	return (0);
}

void	ft_write_error(t_cubed *info, int error)
{
	if (error == 4)
		ft_printf_fd(2, "Error\n-parsing the map\n");
	if (error == 5)
		ft_printf_fd(2, "Error\n-parsing the map: Color values\n");
	ft_free_info(info);
	return ;
}
