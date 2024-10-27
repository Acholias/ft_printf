/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:53:03 by lumugot           #+#    #+#             */
/*   Updated: 2024/10/24 13:51:22 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	my_putchar(char c);
int	my_putstr(char *str);
int	my_putnbr(int nb);
int	my_put_usgd_nbr(unsigned int nb);
int	my_putnbr_hexa_lower(unsigned int nb);
int	my_putnbr_hexa_upper(unsigned int nb);
int	my_put_adress_temp(unsigned long nb);
int	my_put_adress(void *nb);
int	my_check_format(va_list args, char c);
int	ft_printf(const char *str, ...);

#endif
