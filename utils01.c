#include "cubed.h"

int	ft_strcmp_cubed(char *string1, char *string2)
{
	if (!string1 || !string2)
		return (-1);
	while (*string1 && (*string1) == (*string2))
	{
		string1++;
		string2++;
	}
	return ((int)(*string1) - (int)(*string2));
}
