/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:27:02 by eoh               #+#    #+#             */
/*   Updated: 2022/12/06 15:35:43 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	print_char(va_list ap);
int	print_str(va_list ap);
int	print_pointer(va_list ap);
int	print_decimal(va_list ap);
int print_integer(va_list ap);
int print_unsigned(va_list ap);
int print_hexadecimal(va_list ap);
int write_arg(const char *arg, va_list ap);
int	find_type(const char *arg, va_list ap);
char	*ft_itoa(int n);
#endif