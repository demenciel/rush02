#include "print_functions.c"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *ch)
{
	int	i;

	i = 0;
	while (ch[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_atoi(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 48 && str[i] <= 57))
			return (-1);
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result);
}

int	check_pos(int len)
{
	int	pos;

	pos = 0;
	while (len > 1)
	{
		len--;
		pos++;
		if (pos == 3)
			pos = 0;
	}
	return (pos);
}

int	check_tens(int len)
{
	int	tens;
	int	i;

	if (len <= 3)
		return (0);
	tens = 0;
	i = 0;
	while (len > 1)
	{
		len--;
		i++;
		if (i == 3)
		{
			tens++;
			i = 0;
		}
	}
	return (tens);
}

int	total_pos_check(char *nb)
{
	int	i;

	i = 0;
	while (nb[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	select_print_function(char *ch, int pos)
{
	if (pos == 0)
		print_units(&ch[0]);
	else if (pos == 1)
		print_tens(&ch[0]);
	else if (pos == 2)
		print_hundreds(&ch[0]);
}

void	print_number(int total_pos, char *argv, int pos, int tens)
{
	int	i;

	i = 0;
	while (i < total_pos)
	{
		//si notre chiffre a la position des disaines est 1;
		if (argv[i] == 49 && pos == 1)
		{
			print_tens_one(&argv[i], &argv[i + 1]);
			i += 2;
			pos -= 2;
		}
		//si notre chiffre est 0 mais que le chiffre passe en argument n'est pas seulement 0;
		else if (argv[i] == 48 && total_pos != 1)
		{
			i++;
			pos--;
		}
		else
		{
			select_print_function(&argv[i], pos);
			i++;
			pos--;
		}
		//si notre chiffre est 0 mais que le chiffre passe en argument n'est pas seulement 0;
		if (pos < 0)
		{
			if (tens >= 1)
			{
				if (total_pos > 6)
				{
					if (!(argv[i - 1] == 48 && argv[i - 2] == 48 && argv[i
							- 3] == 48))
						print_thousands(tens);
				}
				else
				{
					print_thousands(tens);
				}
				tens--;
			}
			pos = 2;
		}
	}
}

void	print_error(int error_code)
{
	int		i;
	char	errors[2][16] = {"Error", "Dict Error"};
	i = 0;
	while (errors[error_code][i] != '\0')
	{
		write(1, &errors[error_code][i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	manage_dict(char *quote)
{
	int		file;
	int		len;
	char	*c;
	size_t	rd;

	len = ft_strlen(quote);
	c = (char *)malloc(1024);
	file = open("Header/numbers.dict", O_WRONLY | O_APPEND);
	write(file, quote, len);
	close(file);
	free(c);
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
		print_error(0);
		return (0);
	}
	print_number(total_pos, value, pos, tens);
	if (argc == 3)
		manage_dict(argv[1]);
}
////////
