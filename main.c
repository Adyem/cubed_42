#include "cubed.h"

static void	ft_initialize_info(t_cubed *info)
{
	info->mlx = NULL;
	info->win = NULL;
	info->map.content = NULL;
}

int	main(int argc, char **argv)
{
	t_cubed	*info;

	(void)argv;
	if (argc != 2)
		return(ft_printf_fd(2, "Error: Incorrect amount of arguments\n"), 1);
	info = (t_cubed *)malloc(sizeof(t_cubed));
	if (!info)
		return (ft_printf_fd(2, "Error allocating memory for info"), 2);
	ft_initialize_info(info);
	info->map.content = ft_open_and_read(argv[1]);
	if (!info->map.content)
		return (ft_free_info(info), 2);
	ft_parse_map(info);
}
