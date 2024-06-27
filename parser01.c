#include "cubed.h"

/*replaced ft_strdup with ft_strdup_no_ln, because strdup copied the line break
at the end of each line, which makes the color code and path incorrect*/

int ft_check_images(char **image, char *string, char *check)
{
	static int	i;
	char		*temp;

	if (*image)
		return (4);
	temp = &string[ft_strlen(check)];
	if (*temp == ' ')
		temp++;
	i++;
	*image = ft_strdup_no_ln(temp);
	if (!*image)
	{
		ft_printf_fd(2, "Error-%i Allocating memory Image name\n", i);
		return (2);
	}
	return (0);
}

int ft_check_colors(char **color_string, char *string, char *check)
{
	static int	i;
	char		*temp;

	if (*color_string)
		return (4);
	temp = &string[ft_strlen(check)];
	while (*temp == ' ')
		temp++;
	i++;
	*color_string = ft_strdup_no_ln(temp);
	if (!*color_string)
	{
		ft_printf_fd(2, "Error-%i Allocating memory Color string\n", i);
		return (2);
	}
	return (0);
}

static int ft_parse_map_2(t_cubed *info, int index)
{
	int i;

	info->colors.ceiling_array = ft_split(info->colors.ceiling_string, ',');
	info->colors.floor_array = ft_split(info->colors.floor_string, ',');
	if (!info->colors.ceiling_array || !info->colors.floor_array)
	{
		ft_printf_fd(2, "Error-Allocating memory color arrays");
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
	return ft_check_map(info, index);
}

static void	ft_parse_value(t_cubed *info, int *i, int *error)
{
	if (info->map.content[*i][0] == '\n' && info->map.content[*i][1] == '\0')
	{
		(*i)++;
		return ;
	}
	*error = ft_check_textures_and_colors(info, info->map.content[*i]);
	(*i)++;
	return ;
}

int ft_parse_map(t_cubed *info)
{
	int error;
	int i;

	if (ft_check_length(info->map.content) < 8)
        return (4);
	error = 0;
	i = 0;
	while (info->map.content[i])
	{
		ft_parse_value(info, &i, &error);
		if (error)
			return (error);
		if (ft_all_found(info) == 0)
			break ;
	}
	if (ft_check_malloc_texture(info))
		return (2);
	error = ft_parse_map_2(info, i);
	return (error);
}
