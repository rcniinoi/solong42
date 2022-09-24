/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:15:06 by rchiewli          #+#    #+#             */
/*   Updated: 2022/06/20 22:41:48 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexanbr(unsigned long nbr, char mode)
{
	char			*base;
	unsigned long	nbbuffer;
	int				ret;

	ret = 0;
	nbbuffer = nbr;
	ret += ft_intlenhex(nbbuffer);
	if (mode == 'x')
		base = "0123456789abcdef";
	if (mode == 'X')
		base = "0123456789ABCDEF";
	if (nbbuffer < 16)
		write(1, &base[nbbuffer], 1);
	if (nbbuffer >= 16)
	{
		ft_puthexanbr(nbbuffer / 16, mode);
		ft_puthexanbr(nbbuffer % 16, mode);
	}
	return (ret);
}

int	ft_intputstr(char *s)
{
	size_t	i;
	int		ret;

	i = 0;
	ret = 0;
	if (!s)
		return (write (1, "(null)", 6));
	while (s[i])
		ret += write(1, &s[i++], 1);
	return (ret);
}

int	ft_conditionpercent(const char *str, va_list args, int i)
{
	int		ret;

	ret = 0;
	while (str[i] != '%' && str[i] != '\0')
		i++;
	if (str[i + 1] == 'c')
		ret += ft_putchar_ret(va_arg(args, int));
	if (str[i + 1] == 's')
		ret += ft_intputstr(va_arg(args, char *));
	if (str[i + 1] == 'p')
	{
		ret += ft_intputstr("0x");
		ret += ft_puthexanbr(va_arg(args, unsigned long), 'x');
	}
	if (str[i + 1] == 'd' || str[i + 1] == 'i')
		ret += ft_putnbr_intret(va_arg(args, int));
	if (str[i + 1] == 'u')
		ret += ft_putnbr_uret(va_arg(args, unsigned int));
	if (str[i + 1] == 'x')
		ret += ft_puthexanbr(va_arg(args, unsigned int), 'x');
	if (str[i + 1] == 'X')
		ret += ft_puthexanbr(va_arg(args, unsigned int), 'X');
	if (str[i + 1] == '%')
		ret += write(1, "%", 1);
	return (ret);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			ret += ft_conditionpercent(str, args, i);
			i += 1;
		}
		else
			ret += write(1, &str[i], 1);
		i++;
	}
	return (ret);
}

// int	main(void)
// {
// 	char *bbb;
// 	// int nbr = 796;
// 	// int	real = 0;
// 	// int	my = 0;

// 	bbb = "kjhkj";
// 	// char	*aaa= NULL;
// 	// ft_printf("%s%slklklkl\n", "kkdk", "asdf");
// 	// ft_printf("%c%skjkjkjkjj\n", 'a', "gggg");
// 	// ft_printf("%d\n",nbr);
// 	// printf("%d\n",nbr);
// 	// ft_printf("%%");
// 	// write(1, "Hello World\n", 12);
// 	// ft_printf("%c-%s-%p-%i-%u-%d-%x-%X-%%\n", 'd',
//  "string", bbb, nbr, INT_MIN, nbr, 256, -256);
// 	// printf("%c-%s-%p-%i-%u-%d-%x-%X-%%", 'd',
//  "string", bbb, nbr, INT_MIN, nbr, 256, -256);
// 	printf("%d\n",ft_printf("%x\n", 1));
// 	printf("%d\n",printf("%x\n", 1));
// }
