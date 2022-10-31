/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:42:04 by araji-af          #+#    #+#             */
/*   Updated: 2022/10/22 10:01:22 by araji-af         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	countnumb(long i)
{
	unsigned int	count;

	count = 0;
	if (i == 0)
		count++;
	else if (i < 0 && i >= -2147483648)
	{
		i *= -1;
		count++;
	}
	while (i > 0)
	{
		i /= 10;
		count++;
	}
	return (count);
}

static char	*putnbr(char *ptr, long n, unsigned int size)
{
	if (n < 0)
	{
		n *= -1;
		ptr[0] = '-';
	}
	while (n > 0)
	{
		ptr[size--] = 48 + (n % 10);
		n /= 10;
	}
	return (ptr);
}

char	*ft_itoa(int n)
{
	char			*new;
	unsigned int	lenght;

	lenght = countnumb(n);
	new = malloc(sizeof (char) * (lenght + 1));
	if (!new)
		return (NULL);
	new[lenght--] = '\0';
	if (n == 0)
		new[0] = '0';
	putnbr(new, n, lenght);
	return (new);
}
