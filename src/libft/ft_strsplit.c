/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deremia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 13:35:22 by deremia           #+#    #+#             */
/*   Updated: 2018/03/15 13:35:23 by deremia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_wordlen(char const *s, char c)
{
	int		len;

	len = 0;
	while (*s == c && *s)
		s++;
	while (*s != c && *s)
	{
		s++;
		len++;
	}
	return (len);
}

static	void	ft_wordcpy(char *str, char const *s, char c, int *i)
{
	while (*s == c && *s)
	{
		s++;
		(*i)++;
	}
	while (*s != c && *s)
	{
		*str++ = *s++;
		(*i)++;
	}
}

char			**ft_strsplit(char const *s, char c)
{
	char			**str;
	unsigned int	words;
	int				index;
	int				i;

	i = 0;
	index = 0;
	if (!s)
		return (0);
	words = ft_countwords(s, c);
	if ((str = (char **)malloc(sizeof(char *) * (words + 1))) == 0)
		return (0);
	while (s[index])
	{
		if ((str[i] = ft_strnew(ft_wordlen(s + index, c))) == 0)
		{
			ft_free_map(str);
			return (0);
		}
		ft_wordcpy(str[i], s + index, c, &index);
		i++;
	}
	str[words] = 0;
	return (str);
}
