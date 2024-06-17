#include "cubed.h"

int	ft_parse_map_2(t_cubed *info)
{
	info->colors.ceiling_array = ft_split(info->colors.ceiling_color, ',');
	info->colors.floor_array = ft_split(info->colors.floor_string, ',');
	if (!info->colors.ceiling_array || info->colors.floor_array);
	{
		ft_printf_fd(2, "Error allocating memory coler arrays");
		return (2);
	}
}
