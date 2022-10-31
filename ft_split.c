/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:27:28 by araji-af          #+#    #+#             */
/*   Updated: 2022/10/28 18:34:51 by araji-af         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	del(char **str, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(str[j]);
		j++;
	}
	free(str);
	*str = NULL;
}

static int	word_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s != c && *s)
	{
		s++;
		len++;
	}
	return (len);
}

static int	countword(char const *s, char c)
{
	int			i;
	int			isword;

	i = 0;
	isword = 0;
	while (*s == c)
		s++;
	while (*s)
	{
		if (*s != c && isword == 0)
		{
			isword = 1;
			i++;
		}
		else if (*s == c && *(s + 1) != c)
			isword = 0;
		s++;
	}
	return (i);
}

static void	putword(char **splited, char const *s, char c)
{
	int	i;
	int	word;

	i = 0;
	while (*s)
	{
		while (*s == c && *s)
				s++;
		if (!*s)
			break ;
		word = word_len(s, c);
		splited[i] = ft_substr(s, 0, word);
		if (splited[i] == NULL)
		{
			del(splited, i);
			return ;
		}
		s += word;
		i++;
	}
	splited[i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**splited;

	if (s == NULL)
		return (NULL);
	splited = (char **)malloc(sizeof(char *) * (countword(s, c) + 1));
	if (!splited)
		return (NULL);
	putword(splited, s, c);
	return (splited);
}
