#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "Header/print.h"
#include "Header/logic.h"
#include "Header/file_management.h"

int	ft_atoi(char *str)
{
	int	i;
	unsigned int	result;

	i = 0;
	result = 0;
	while (str[i] != '\0')
	{

		if (!(str[i] >= 48 && str[i] <= 57))
			return (-1);
		if (result >= 4294967295 || (str[i] != '\0' && (result > (result * 10 + str[i] - '0'))))
			return(-1);		
		result = result * 10 + str[i] - '0';

		i++;

	}
	return (result);
}

int	main(int argc, char *argv[])
{
	int		pos;
	int		i;
	char	*value;
	int		nb;
	int		total_pos;
	int		tens;

	if (argc == 2)
		value = argv[1];
	else if (argc == 3)
		value = argv[2];
	nb = ft_atoi(value);
	total_pos = total_pos_check(value);
	pos = check_pos(total_pos);
	tens = check_tens(total_pos);
	i = 0;
	if (nb == -1)
	{
		put_str("Error\n");
		return (0);
	}
	print_number(total_pos, value, pos, tens);
	if (argc == 3)
		manage_dict(argv[1]);
}
////////
