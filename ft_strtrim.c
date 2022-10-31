/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 21:04:43 by araji-af          #+#    #+#             */
/*   Updated: 2022/10/28 19:28:18 by araji-af         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t			start;
	size_t			end;
	char			*new;

	start = 0;
	if (s1 == NULL)
		return (NULL);
	end = ft_strlen(s1);
	if (set == NULL)
		return ((char *)s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (ft_strchr(set, (s1[end - 1])) && end - start > 0)
		end--;
	new = (char *)malloc(sizeof (char) * (end - start + 1));
	if (!new)
		return (NULL);
	ft_strlcpy(new, &s1[start], end - start + 1);
	return (new);
}
