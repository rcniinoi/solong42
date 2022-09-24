/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:15:17 by rchiewli          #+#    #+#             */
/*   Updated: 2022/06/20 04:26:55 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <ctype.h>
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_conditionpercent(const char *str, va_list args, int i);
int		ft_intputstr(char *s);
int		ft_puthexanbr(unsigned long nbr, char mode);
int		ft_putnbr_intret(int n);
int		ft_putnbr_uret(long int n);
int		ft_putchar_ret(char c);
char	*ft_itoa(long int n);
int		ft_intlen(long int n);
int		ft_intlenhex(unsigned long n);

#endif
