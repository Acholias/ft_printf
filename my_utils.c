/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:15:08 by lumugot           #+#    #+#             */
/*   Updated: 2024/10/24 13:29:07 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	my_putchar(char c)
{
	return (write(1, &c, 1));
}

int	my_putstr(char *str)
{
	int	index;

	index = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[index])
	{
		write(1, &str[index], 1);
		index++;
	}
	return (index);
}

int	my_putnbr(int nb)
{
	int	value;

	value = 0;
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	else if (nb < 0)
	{
		value += write(1, "-", 1);
		nb = nb * -1;
	}
	if (nb > 9)
	{
		value += my_putnbr(nb / 10);
		value += my_putnbr(nb % 10);
	}
	else
		value += my_putchar(nb + '0');
	return (value);
}

int	my_put_usgd_nbr(unsigned int nb)
{
	unsigned int	value;

	value = 0;
	if (nb > 9)
	{
		value += my_put_usgd_nbr(nb / 10);
		value += my_put_usgd_nbr(nb % 10);
	}
	else
		value += my_putchar(nb + '0');
	return (value);
}
