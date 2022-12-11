/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_management.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 17:22:43 by acouture          #+#    #+#             */
/*   Updated: 2022/12/11 17:24:11 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_MANAGEMENT_H
# define FILE_MANAGEMENT_H
# include "logic.h"
# include "print.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

void	manage_dict(char *quote);
char	*open_file(char *c);
int		ft_strlen(char *ch);

void	put_str(char *ch)
{
	int	i;

	i = 0;
	while (ch[i])
	{
		write(1, &ch[i], 1);
		i++;
	}
}

void	manage_dict(char *quote)
{
	int		file;
	int		len;
	char	*c;

	len = ft_strlen(quote);
	c = (char *)malloc(sizeof(char *) * (692 + len));
	file = open("Header/numbers.dict", O_WRONLY | O_APPEND);
	write(file, "\n", 1);
	write(file, quote, len);
	close(file);
	free(c);
}

char	*open_file(char *c)
{
	int		file;
	size_t	rd;

	file = open("Header/numbers.dict", O_RDWR | O_CREAT);
	rd = read(file, c, 691);
	return (c);
	close(file);
}

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

#endif