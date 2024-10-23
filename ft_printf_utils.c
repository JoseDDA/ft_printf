/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorazio <jdorazio@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 08:59:27 by jdorazio          #+#    #+#             */
/*   Updated: 2024/10/01 11:14:47 by jdorazio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
	return (1);
}

int	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (!s)
	{
		ft_putstr_fd("(null)", fd);
		return (6);
	}
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr_fd(long n, int fd)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		count++;
		n = -n;
	}
	if (n > 9)
	{
		count += ft_putnbr_fd(n / 10, fd);
	}
	ft_putchar_fd((n % 10 + '0'), fd);
	count++;
	return (count);
}

int	ft_putnbr_base(unsigned long n, char *base)
{
	unsigned int	base_len;
	int				count;

	count = 0;
	base_len = ft_strlen(base);
	if (n >= base_len)
		count += ft_putnbr_base(n / base_len, base);
	ft_putchar_fd((base[n % base_len]), 1);
	count++;
	return (count);
}
