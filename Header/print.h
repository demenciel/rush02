/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchouina <cchouina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 17:23:03 by acouture          #+#    #+#             */
/*   Updated: 2022/12/11 18:12:17 by cchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include "file_management.h"
# include "logic.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char	*open_file(char *c);
int		write_thous(char *c, int i);

void	print_hundreds(char *nb)
{
	int		i;
	char	*c;

	i = 0;
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
	int		i;
	char	*c;

	i = 0;
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
	int		i;
	char	*c;

	i = 0;
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

int	print_tens_one(char *nb, char *nb2, int external_count)
{
	int		i;
	char	*c;

	i = 0;
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
	return (external_count + 2);
}

void	print_thousands(int tens)
{
	int		i;
	char	*c;

	c = (char *)malloc(691);
	open_file(c);
	i = 0;
	while (c[i] != '\0')
	{
		write(1, " ", 1);
		while (!(c[i] == 49 && c[i + 1] == 48 && c[i + 2] == 48
				&& c[i + 3] == 48))
			i++;
		while (tens > 1)
		{
			while (c[i] != '\n')
				i++;
			tens--;
			i++;
		}
		while (c[i] == 32 || c[i] == 58 || c[i] == 48)
			i++;
		i = write_thous(c, i);
		break ;
	}
	free(c);
}

#endif