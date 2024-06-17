#include "cubed.h"

int	ft_parse_map_2(t_cubed *info)
{
	int	i;

	info->colors.ceiling_array = ft_split(info->colors.ceiling_string, ',');
	info->colors.floor_array = ft_split(info->colors.floor_string, ',');
	if (!info->colors.ceiling_array || info->colors.floor_array)
	{
		ft_printf_fd(2, "Error allocating memory coler arrays");
		return (2);
	}
	i = 0;
	while (i < 3)
	{
		if (ft_check_value_rgb(info->colors.ceiling_array[i]))
			return (5);
		if (ft_check_value_rgb(info->colors.floor_array[i]))
			return (5);
		info->colors.ceiling_color[i] = ft_atoi(info->colors.ceiling_array[i]);
		info->colors.floor_color[i] = ft_atoi(info->colors.floor_array[i]);
		i++;
	}
	return (0);
}
