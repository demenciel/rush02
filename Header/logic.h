#ifndef LOGIC_H
#define LOGIC_H
#include "print.h"
#include "file_management.h"


void	print_hundreds(char *nb);
void	print_tens(char *nb);
void	print_units(char *nb);
void	print_tens_one(char *nb, char *nb2);
void	print_thousands(int tens);

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
		if (i != total_pos)
			write(1, " ", 1);
	}
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
		i++;
	return (i);
}

#endif