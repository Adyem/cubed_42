#include "cubed.h"

void	ft_write_error(t_cubed *info, int error)
{
	if (error == 4)
		ft_printf_fd(2, "Error-parsing the map\n");
	if (error == 5)
		ft_printf_fd(2, "Error-parsing the map: Color values\n");
	ft_free_info(info);
	return ;
}
