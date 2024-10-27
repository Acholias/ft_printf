/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_utils_bis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:17:53 by lumugot           #+#    #+#             */
/*   Updated: 2024/10/24 13:31:16 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	my_putnbr_hexa_lower(unsigned int nb)
{
	int		value;
	char	*base;

	value = 0;
	base = "0123456789abcdef";
	if (nb >= 16)
	{
		value += my_putnbr_hexa_lower(nb / 16);
		value += my_putnbr_hexa_lower(nb % 16);
	}
	else
		value += my_putchar(base[nb % 16]);
	return (value);
}

int	my_putnbr_hexa_upper(unsigned int nb)
{
	int		value;
	char	*base;

	value = 0;
	base = "0123456789ABCDEF";
	if (nb >= 16)
	{
		value += my_putnbr_hexa_upper(nb / 16);
		value += my_putnbr_hexa_upper(nb % 16);
	}
	else
		value += my_putchar(base[nb % 16]);
	return (value);
}

int	my_put_adress_temp(unsigned long nb)
{
	int		value;
	char	*base;

	value = 0;
	base = "0123456789abcdef";
	if (nb >= 16)
	{
		value += my_put_adress_temp(nb / 16);
		value += my_put_adress_temp(nb % 16);
	}
	else
		value += my_putchar(base[nb % 16]);
	return (value);
}

int	my_put_adress(void *nb)
{
	unsigned long	temp;
	int				value;

	temp = (unsigned long)nb;
	value = 0;
	if (nb == 0)
		return (my_putstr("(nil)"));
	value += my_putstr("0x");
	value += my_put_adress_temp((unsigned long) nb);
	return (value);
}
