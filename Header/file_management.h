#ifndef FILE_MANAGEMENT_H
#define FILE_MANAGEMENT_H
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "print.h"
#include "logic.h"

void	print_error(int error_code);
void	manage_dict(char *quote);
char *open_file(char *c);
int	ft_strlen(char *ch);


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
	c = (char *)malloc(sizeof(char*) * (692 + len));
	file = open("Header/numbers.dict", O_WRONLY | O_APPEND);
	write(file, "\n", 1);
	write(file, quote, len);
	close(file);
	free(c);
}

char *open_file(char *c)
{	
	int file;
	file = open("Header/numbers.dict", O_RDWR | O_CREAT);
	size_t rd = read(file, c, 691);
	return(c);
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