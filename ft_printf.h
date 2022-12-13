/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:27:02 by eoh               #+#    #+#             */
/*   Updated: 2022/12/13 18:02:12 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *arg, ...);
int	print_char(va_list ap);
int	print_str(va_list ap);
int	print_pointer(va_list ap);
int	print_decimal(va_list ap);
int	print_integer(va_list ap);
int	print_unsigned(va_list ap);
int	print_hexadecimal(va_list ap, const char *arg);
int	write_arg(const char *arg, va_list ap);
int	find_type(const char *arg, va_list ap);
int	write_hex(unsigned long long num, const char *arg);
int	ft_putnbr(int n);
int	putnbr_unsigned(unsigned int n);
int	unsigned_zero(void);
#endif