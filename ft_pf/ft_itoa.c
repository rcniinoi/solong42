/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 01:15:41 by rchiewli          #+#    #+#             */
/*   Updated: 2022/06/20 04:22:56 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_intlen(long int n)
{
	int	len;

	len = 0;
	if (n < 0)
		n *= -1;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*ft_putminus(long int n, char *buffer, size_t srcl)
{
	if (n < 0)
		buffer[srcl] = '-';
	return (buffer);
}

char	*ft_itoa(long int n)
{
	size_t			srcl;
	char			*buffer;
	long int		nn;

	srcl = ft_intlen(n);
	if (n <= 0)
	{
		nn = -n;
		srcl += 1;
	}
	else
		nn = n;
	buffer = (char *)malloc(srcl + 1);
	if (!buffer)
		return (NULL);
	if (n == 0)
		buffer[0] = '0';
	buffer[srcl--] = '\0';
	while (nn > 0)
	{
		buffer[srcl--] = nn % 10 + '0';
		nn /= 10;
	}
	ft_putminus(n, buffer, srcl);
	return (buffer);
}

int	ft_intlenhex(unsigned long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n *= -1;
	while (n != 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

/*int main()
{
        //printf("%s\n",ft_itoa(-12315));
	//printf("%lld\n",-2147483648LL);
}*/
