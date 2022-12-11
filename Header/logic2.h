/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic2.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchouina <cchouina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 17:22:59 by acouture          #+#    #+#             */
/*   Updated: 2022/12/11 17:36:50 by cchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGIC2_H
# define LOGIC2_H
# include "file_management.h"
# include "logic.h"
# include "print.h"

void	print_thousands(int tens);

int	position_zero(int i, int tens, char *argv, int total_pos)
{
	if (tens >= 1)
	{
		if (total_pos > 6)
		{
			if (!(argv[i - 1] == 48 && argv[i - 2] == 48 && argv[i - 3] == 48))
				print_thousands(tens);
		}
		else
			print_thousands(tens);
		tens--;
	}
	return (tens);
}

void	write_space(int i, int total_pos)
{
	if (i != total_pos)
		write(1, " ", 1);
}

int	reset_pos(int pos)
{
	if (pos < 0)
		pos = 2;
	return (pos);
}

int write_thous(char *c, int i)
{
		while (c[i] != '\n')
		{
			if (c[i] >= 97 && c[i] <= 122)
				write(1, &c[i], 1);
			i++;
		}
		return(i);
}
#endif