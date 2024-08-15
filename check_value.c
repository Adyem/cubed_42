/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:36:40 by bvangene          #+#    #+#             */
/*   Updated: 2024/07/26 10:56:42 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	ft_initialize_values_rgb(long *check, int *i, int *sign)
{
	*check = 0;
	*i = 0;
	*sign = 1;
}

int	ft_check_value_rgb(char *input)
{
	long	check;
	int		i;
	int		sign;

	ft_initialize_values_rgb(&check, &i, &sign);
	if (input && (input[i] == '+' || input[i] == '-'))
		i++;
	if (!input || !input[i])
		return (1);
	if (input[0] == '-')
		sign = -1;
	while (input[i])
	{
		if (input[i] >= '0' && input[i] <= '9')
		{
			check = (check * 10) + input[i] - '0';
			if (sign * check < 0 || sign * check > 255)
				return (1);
			i++;
		}
		else
			return (1);
	}
	return (0);
}
