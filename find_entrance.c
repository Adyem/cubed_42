/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_entrance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:36:40 by bvangene          #+#    #+#             */
/*   Updated: 2024/07/26 10:57:07 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int	ft_check_entrance(char character)
{
	if (character == 'N')
		return (1);
	if (character == 'S')
		return (1);
	if (character == 'E')
		return (1);
	if (character == 'W')
		return (1);
	return (0);
}

int	ft_find_entrance(t_cubed *info)
{
	int	i;
	int	j;

	if (!info->map.map || !info->map.copy_map)
		return (-1);
	i = 0;
	while (info->map.map[i])
	{
		j = 0;
		while (info->map.map[i][j])
		{
			if (ft_check_entrance(info->map.map[i][j]))
			{
				info->map.player_start_amount++;
				info->map.copy_map[i][j] = '2';
			}
			j++;
		}
		i++;
	}
	if (DEBUG == 1 && info->map.player_start_amount != 1)
		ft_printf_fd(2, "Unable to find player start\n");
	if (info->map.player_start_amount != 1)
		return (4);
	return (0);
}
