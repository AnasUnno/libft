/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 09:17:37 by araji-af          #+#    #+#             */
/*   Updated: 2022/10/28 18:08:20 by araji-af         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			lend;
	size_t			res;
	size_t			lens;
	size_t			i;

	lens = ft_strlen(src);
	res = 0;
	i = 0;
	if (dst == NULL && size == 0)
	{
		return (lens);
	}
	lend = ft_strlen(dst);
	if (size > lend)
		res = lens + lend;
	else
		res = lens + size;
	while (src[i] && (lend + 1) < size)
	{
		dst[lend] = src[i];
		lend++;
		i++;
	}
	dst[lend] = '\0';
	return (res);
}
