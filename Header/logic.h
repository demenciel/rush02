/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchouina <cchouina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 17:22:50 by acouture          #+#    #+#             */
/*   Updated: 2022/12/11 18:08:45 by cchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGIC_H
# define LOGIC_H
# include "file_management.h"
# include "logic2.h"
# include "print.h"

void	print_hundreds(char *nb);
void	print_tens(char *nb);
void	print_units(char *nb);
int		print_tens_one(char *nb, char *nb2, int external_count);
void	print_thousands(int tens);
int		position_zero(int i, int tens, char *argv, int total_pos);
int		reset_pos(int pos);
int check_file(void);


int	select_print_function(char *ch, int pos, int external_count)
{
	if (pos == 0)
		print_units(&ch[0]);
	else if (pos == 1)
		print_tens(&ch[0]);
	else if (pos == 2)
		print_hundreds(&ch[0]);
	return (external_count + 1);
}

void	print_number(int total_pos, char *argv, int pos, int tens)
{
	int	i;
	
	i = 0;
	while (i < total_pos && check_file())
	{
		if (argv[i] == 49 && pos == 1)
		{
			i = print_tens_one(&argv[i], &argv[i + 1], i);
			pos -= 2;
		}
		else if (argv[i] == 48 && total_pos != 1)
		{
			i++;
			pos--;
		}
		else
		{
			i = select_print_function(&argv[i], pos, i);
			pos--;
		}
		if (pos < 0)
			tens = position_zero(i, tens, argv, total_pos);
		pos = reset_pos(pos);
		write_space(i, total_pos);
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