/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvangene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:43:19 by bvangene          #+#    #+#             */
/*   Updated: 2024/08/08 12:43:21 by bvangene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int	ft_check_color_string(char *string)
{
	int	number;
	int	i;

	i = 0;
	number = 0;
	if (!string)
		return (0);
	while (string[i])
	{
		if (string[i] == ',')
			number++;
		i++;
	}
	if (DEBUG == 1)
		ft_printf("number == %i", number);
	if (number != 2)
		return (1);
	return (0);
}
