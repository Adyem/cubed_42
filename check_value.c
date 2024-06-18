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
	if (input[i] == '+' || input[i] == '-')
		i++;
	if (!input[i])
		return (3);
	if (input[0] == '-')
		sign = -1;
	while (input[i])
	{
		if (input[i] >= '0' && input[i] <= '9')
		{
			check = (check * 10) + input[i] - '0';
			if (sign * check < 0 || sign * check > 255)
				return (3);
			i++;
		}
		else
			return (3);
	}
	return (0);
}
