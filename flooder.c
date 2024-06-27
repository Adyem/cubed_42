#include "cubed.h"

static void	ft_update_change(int *change, int new_value)
{
	if (*change < 0)
		return ;
	else if (*change == 0)
		*change = new_value;
	return ;
}

static int ft_is_walled(t_cubed *info, int i, int j, int *change)
{
	(void)change;
	if (i == 0 || j == 0 || !info->map.copy_map[i + 1]
			|| !info->map.copy_map[i][j + 1])
		return (1);
	if (info->map.copy_map[i - 1][j] != '1'
			&& info->map.copy_map[i - 1][j] != '0')
		return (1);
	if (info->map.copy_map[i][j - 1] != '1'
			&& info->map.copy_map[i][j - 1] != '0')
		return (1);
	if (info->map.copy_map[i + 1][j] != '1'
			&& info->map.copy_map[i + 1][j] != '0')
		return (1);
	if (info->map.copy_map[i][j + 1] != '1'
			&& info->map.copy_map[i][j + 1] != '0')
		return (1);
	return (0);
}

static void	ft_check_tile(t_cubed *info, int i, int j, int *change)
{
	if (ft_is_walled(info, i, j, change))
		return (ft_update_change(change, -1));
	if (i > 0 && info->map.copy_map[i - 1][j] == '0') 
	{
		info->map.copy_map[i - 1][j] = '2';
		ft_update_change(change, 1);
	}
	if (j > 0 && info->map.copy_map[i][j - 1] == '0') 
	{
		info->map.copy_map[i][j - 1] = '2';
		ft_update_change(change, 1);
	}
	if (info->map.copy_map[i + 1] && info->map.copy_map[i + 1][j]
			&& info->map.copy_map[i + 1][j] == '0') 
	{
		info->map.copy_map[i + 1][j] = '2';
		ft_update_change(change, 1);
	}
	if (info->map.copy_map[i][j + 1] && info->map.copy_map[i][j + 1] == '0') 
	{
		info->map.copy_map[i][j + 1] = '2';
		ft_update_change(change, 1);
	}
	return ;
}

int	ft_floooder(t_cubed *info)
{
	int	change;
	int	i;
	int	j;

	while (1)
	{
		i = 0;
		change = 0;
		while (info->map.copy_map[i])
		{
			j = 0;
			while (info->map.copy_map[i][j])
			{
				if (!change && info->map.copy_map[i][j] == '2')
					ft_check_tile(info, i, j, &change);
				if (change < 0)
					break ;
				j++;
			}
			i++;
		}
		if (change <= 0)
			break ;
	}
	return (change);
}
