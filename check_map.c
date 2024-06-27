#include "cubed.h"

static int	ft_create_map(t_cubed *info, int i)
{
	int	j;

	j = ft_check_length(&info->map.content[i]);
	if (DEBUG == 1)
		ft_printf("j = %i\n", j);
	info->map.map = (char **)ft_calloc(j + 1, sizeof(char *));
	if (!info->map.map)
	{
		ft_printf_fd(2, "Error-Malloc create map\n");
		return (2);
	}
	info->map.copy_map = (char **)ft_calloc(j + 1, sizeof(char *));
	if (!info->map.copy_map)
	{
		ft_printf_fd(2, "Error-Malloc create copy map\n");
		return (2);
	}
	return (0);
}

static int	ft_copy_values(t_cubed *info, int i)
{
	int x;
	int	j;

	ft_create_map(info, i);
	j = 0;
	x = ft_check_length(&info->map.content[i]);
	while (j < x)
	{
		info->map.map[j] = ft_strdup_no_ln(info->map.content[i]);
		if (!info->map.map[j])
		{
			ft_printf_fd(2, "Error-Malloc copying map values %i\n", j);
			return (2);
		}
		info->map.copy_map[j] = ft_strdup_no_ln(info->map.content[i]);
		if (!info->map.copy_map[j])
		{
			ft_printf_fd(2, "Error-Malloc copying copy_map values %i\n", j);
			return (2);
		}
		i++;
		j++;
	}
	return (0);
}

static void	ft_print_map(char **map, char *msg)
{
	int	i;

	if (map && DEBUG == 1)
	{
		ft_printf("printing %s\n", msg);
		i = 0;
		while (map[i])
		{
			ft_printf("%s\n", map[i]);
			i++;
		}
		ft_printf("\n");
	}
	return ;
}

int	ft_check_map(t_cubed *info, int i)
{
	int	error;

	error = 0;
	while (info->map.content[i][0] == '\n' && info->map.content[i][1] == '\0')
		i++;
	if (DEBUG == 1)
		ft_printf("the value of i = %i\n", i);
	ft_copy_values(info, i);
	ft_print_map(info->map.map, "original");
	ft_print_map(info->map.copy_map, "copy");
	error = ft_find_entrance(info);
	if (error)
		return (error);
	if (ft_flooder < 0)
		return (4);
	return (0);
}
