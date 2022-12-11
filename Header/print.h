
#ifndef PRINT_H
#define PRINT_H

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "logic.h"
#include "file_management.h"

void	print_hundreds(char *nb);
void	print_tens(char *nb);
void	print_units(char *nb);
void	print_tens_one(char *nb, char *nb2);
void	print_thousands(int tens);


void	print_hundreds(char *nb)
{
	int i;
	i = 0;
	char *c;
	c = (char *)malloc(691);
	open_file(c);

	while (c[i] != '\0')
	{
		while (c[i] != nb[0])
			i++;
		while (c[i] == 32 || c[i] == 58)
			i++;
		while (c[i] != '\n')
		{
			if (c[i] >= 97 && c[i] <= 122)
				write(1, &c[i], 1);
			i++;
		}
		write(1, " hundred", 8);
		break ;
		i++;
	}
	free(c);
}

void	print_tens(char *nb)
{
	int i;
	i = 0;
	char *c;
	c = (char *)malloc(691);
	open_file(c);

	while (c[i] != '\0')
	{
		while (!(c[i] == nb[0] && c[i + 1] == 48))
			i++;
		i++;
		while (c[i] == 32 || c[i] == 58 || c[i] == 48)
			i++;
		while (c[i] != '\n')
		{
			write(1, &c[i], 1);
			i++;
		}
		break ;
		i++;
	} 
	free(c);
}

void	print_units(char *nb)
{
	int i;
	i = 0;
	char *c;
	c = (char *)malloc(691);
	open_file(c);
	while (c[i] != '\0')
	{
		while (c[i] != nb[0])
			i++;
		while (c[i] == 32 || c[i] == 58)
			i++;
		while (c[i] != '\n')
		{
			if (c[i] >= 97 && c[i] <= 122)
				write(1, &c[i], 1);
			i++;
		}
		break ;
		i++;
	}
	free(c);
}

void	print_tens_one(char *nb, char *nb2)
{
	int i;
	i = 0;
	char *c;
	c = (char *)malloc(691);
	open_file(c);
	while (c[i] != '\0')
	{
		while (!(c[i] == nb[0] && c[i + 1] == nb2[0]))
			i++;
		while (c[i + 1] == 32 || c[i + 1] == 58)
			i++;
		while (c[i] != '\n')
		{
			if (c[i] >= 97 && c[i] <= 122)
				write(1, &c[i], 1);
			i++;
		}
		break ;
		i++;
	} 
	free(c);
}

void	print_thousands(int tens)
{
	int i;
	int base;
	char *c;
	c = (char *)malloc(691);
	open_file(c);
	i = 0;
	base = 1;
	while (c[i] != '\0')
	{
		write(1, " ", 1);
        while (!(c[i] == 49 && c[i + 1] == 48 && c[i + 2] == 48 && c[i + 3] == 48))
            i++;
		while (base < tens)
		{
			while(c[i] != '\n')
				i++;
			base++;
			i++;
		}
		while (c[i] == 32 || c[i] == 58 || c[i] == 48)
			i++;
		while (c[i] != '\n')
		{
			if (c[i] >= 97 && c[i] <= 122)
				write(1, &c[i], 1);
			i++;
		}

		
		break ;
		i++;
	} 
	free(c);
}

#endif