/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:04:36 by lumugot           #+#    #+#             */
/*   Updated: 2024/10/24 13:35:07 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	my_check_format(va_list args, char c)
{
	int	value;

	value = 0;
	if (c == 'd' || c == 'i')
		value += my_putnbr(va_arg(args, int));
	else if (c == 'c')
		value += my_putchar(va_arg(args, int));
	else if (c == 's')
		value += my_putstr(va_arg(args, char *));
	else if (c == 'x')
		value += my_putnbr_hexa_lower(va_arg(args, unsigned int));
	else if (c == 'X')
		value += my_putnbr_hexa_upper(va_arg(args, unsigned int));
	else if (c == 'p')
		value += my_put_adress(va_arg(args, void *));
	else if (c == 'u')
		value += my_put_usgd_nbr(va_arg(args, unsigned int));
	else if (c == '%')
		return (my_putchar('%'));
	return (value);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		value;
	int		index;

	va_start(args, str);
	value = 0;
	index = 0;
	if (!str)
		return (-1);
	while (str[index])
	{
		if (str[index] == '%' && str[index + 1] != '\0')
		{
			index++;
			value += my_check_format(args, str[index]);
		}
		else
			value += my_putchar(str[index]);
		index++;
	}
	va_end(args);
	return (value);
}
