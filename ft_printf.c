/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:32:21 by eoh               #+#    #+#             */
/*   Updated: 2022/12/08 15:20:42 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	ft_printf(const char *arg, ...)
{
	int		len;
	va_list	ap;

	va_start(ap, arg);
	len = write_arg(arg, ap);
	va_end(ap);
	return (len);
}

int	write_arg(const char *arg, va_list ap)
{
	int	temp;
	int	len;

	len = 0;
	while (*arg)
	{
		if (*arg == '%')
		{
			arg++;
			temp = find_type(arg, ap);
			if (temp == -1)
				return (-1);
			arg++;
			len += temp;
			continue ;
		}
		write(1, arg, 1);
		arg++;
		len++;
	}
	return (len);
}

int	find_type(const char *arg, va_list ap)
{
	int	len;

	len = -1;
	if (*arg == 'c')
		len = print_char(ap);
	else if (*arg == 's')
		len = print_str(ap);
	else if (*arg == 'p')
		len = print_pointer(ap);
	else if (*arg == 'd')
		len = print_decimal(ap);
	else if (*arg == 'i')
		len = print_integer(ap);
	else if (*arg == 'u')
		len = print_unsigned(ap);
	else if (*arg == 'x' || *arg == 'X')
		len = print_hexadecimal(ap, arg);
	else if (*arg == '%')
	{
		write (1, "%", 1);
		len = 1;
	}
	return (len);
}

int main(void)
{
    printf("Bt\t/l-s> l%dn0HU**%iEz7}%%pzR%s.Uj|5me%x?/`f%s5(<${YK;%dp%u%X_[\rHei%u9", 1228504768, 190156702, "G2za^}|[/P-nwwYmGjfNQ\"o\"RdG-*c+b@<2D&mM\\lrK>R)vpkdeyn!*lW{='F\r=>Ba=Bqso}IGCr\"@$R", 17036593, "7T2qcf-\v,+]Tje%\\*_\fA2pR.?:b#t\"CNYzV?*a:SvP T~dUg9cQ`TZr:lSokN1N>Mg", -152355607, 1735389943, 215164987, 1027577336);
    printf("\n--------------\n");
	ft_printf("Bt\t/l-s> l%dn0HU**%iEz7}%%pzR%s.Uj|5me%x?/`f%s5(<${YK;%dp%u%X_[\rHei%u9", 1228504768, 190156702, "G2za^}|[/P-nwwYmGjfNQ\"o\"RdG-*c+b@<2D&mM\\lrK>R)vpkdeyn!*lW{='F\r=>Ba=Bqso}IGCr\"@$R", 17036593, "7T2qcf-\v,+]Tje%\\*_\fA2pR.?:b#t\"CNYzV?*a:SvP T~dUg9cQ`TZr:lSokN1N>Mg", -152355607, 1735389943, 215164987, 1027577336);

    return (0);
}