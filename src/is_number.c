#include "main.h"

int 	is_register(const char *str)
{
	int i;

	i = 0;
	if (str[i] != 'r')
		return (0);
	if (ft_atoi(str + 1) < 1 || ft_atoi(str + 1) > 16)
		return (0);
	if (ft_strlen(str + 1) > 2)
		return (0);
	return (1);
}

int 	is_link(const char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

int 	is_empty_line(const char *str)
{
	while (*str <= 32 && *str != 0)
		str++;
	if (*str == 0)
		return (1);
	return (0);
}

int 	is_number(const char *str)
{
	if (*str == '-' || *str == '+')
	{
		if (*(str + 1) >= '0' && *(str + 1) <= '9' && *(str + 1) != '\0')
			str++;
		else
			return (0);
	}
	while (*str >= '0' && *str <= '9' && *str != '\0')
		str++;
	if (*str == '\0')
		return (1);
	else
		return (0);
}
