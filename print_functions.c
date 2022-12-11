#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	print_hundreds(char *nb)
{
	int file;
	int i;
	i = 0;
	char *c;
	c = (char *)malloc(1024);
	file = open("Header/numbers.dict", O_RDWR | O_CREAT);
	size_t rd = read(file, c, 1024);
	while (c[i] != '\0')
	{
		while (c[i] != nb[0])
			i++;
		while (c[i] == 32 || c[i] == 58)
			i++;

		while (c[i] != '\n')
		{
			if (c[i] >= 97 && c[i] <= 122)
				printf("%c", c[i]);
			i++;
		}
        printf(" hundred ");

		break ;
		i++;
	}

	close(file);
}

void	print_tens(char *nb)
{
	int		file;
	int		i;
	char	*c;
	size_t	rd;

	i = 0;
	c = (char *)malloc(1024);
	file = open("Header/numbers.dict", O_RDWR | O_CREAT);
	rd = read(file, c, 1024);
	while (c[i] != '\0')
	{
		while (!(c[i] == nb[0] && c[i + 1] == 48))
		{
			i++;
		}

		while (c[i + 1] == 32 || c[i + 1] == 58 || c[i + 1] == 48)
			i++;
		while (c[i] != '\n')
		{
			
			printf("%c", c[i]);
			i++;
		}
        printf(" ");

		break ;
		i++;
	} 
	close(file);
}

void	print_units(char *nb)
{
	int file;
	int i;
	i = 0;
	char *c;
	c = (char *)malloc(1024);
	file = open("Header/numbers.dict", O_RDWR | O_CREAT);
	size_t rd = read(file, c, 1024);
	while (c[i] != '\0')
	{
		while (c[i] != nb[0])
			i++;
		while (c[i] == 32 || c[i] == 58)
			i++;

		while (c[i] != '\n')
		{
			if (c[i] >= 97 && c[i] <= 122)
				printf("%c", c[i]);
			i++;
		}
        printf(" ");
		break ;
		i++;
	}

	close(file);
}

void	print_tens_one(char *nb, char *nb2)
{
	int		file;
	int		i;
	char	*c;
	size_t	rd;

	i = 0;
	c = (char *)malloc(1024);
	file = open("Header/numbers.dict", O_RDWR | O_CREAT);
	rd = read(file, c, 1024);
	while (c[i] != '\0')
	{
		while (!(c[i] == nb[0] && c[i + 1] == nb2[0]))
		{
			i++;
		}

		while (c[i + 1] == 32 || c[i + 1] == 58)
			i++;
		while (c[i] != '\n')
		{
			if (c[i] >= 97 && c[i] <= 122)
			    printf("%c", c[i]);
			i++;
		}
        printf(" ");

		break ;
		i++;
	} 
	close(file);
}

void	print_thousands(int tens)
{
	int		file;
	int		i;
	char	*c;
	size_t	rd;

	i = 0;
	c = (char *)malloc(1024);
	file = open("Header/numbers.dict", O_RDWR | O_CREAT);
	rd = read(file, c, 1024);
	while (c[i] != '\0')
	{
        while (!(c[i] == 49 && c[i + tens + 2] == 48))
            i++;
		while (c[i] == 32 || c[i] == 58 || c[i] == 48)
			i++;
		while (c[i] != '\n')
		{
			if (c[i] >= 97 && c[i] <= 122)
				printf("%c", c[i]);
			i++;
		}
        printf(" ");
		break ;
		i++;
	} 
	close(file);
}