/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftmodified.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 04:31:04 by rchiewli          #+#    #+#             */
/*   Updated: 2022/06/20 04:33:19 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_intret(int n)
{
	int		ret;
	char	*str;

	ret = 0;
	str = ft_itoa(n);
	ret += ft_intputstr(str);
	free (str);
	return (ret);
}

int	ft_putnbr_uret(long int n)
{
	int		ret;
	char	*str;

	ret = 0;
	str = ft_itoa(n);
	ret += ft_intputstr(str);
	free (str);
	return (ret);
}

int	ft_putchar_ret(char c)
{
	int	ret;

	ret = 0;
	ret += write(1, &c, 1);
	return (ret);
}
