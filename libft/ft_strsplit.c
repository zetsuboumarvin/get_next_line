/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 13:24:57 by jflorent          #+#    #+#             */
/*   Updated: 2019/09/10 12:26:14 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int		words;

	words = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
			words++;
		while (*s != c && *s)
			s++;
	}
	return (words);
}

static char	*create_word(char const *s, char c)
{
	char	*word;
	int		len;
	char	*temp;

	temp = (char*)s;
	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	word = (char*)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	ft_strncpy(word, temp, len);
	word[len] = '\0';
	return (word);
}

static void	free_all(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
}

static int	create_array(char **arr, char const *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			arr[j] = create_word(&s[i], c);
			if (arr[j] == NULL)
			{
				free_all(arr);
				return (0);
			}
			j++;
		}
		while (s[i] != c && s[i])
			i++;
	}
	arr[j] = NULL;
	return (1);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = (char**)malloc(sizeof(char*) * (count_words(s, c) + 1));
	if (!arr)
		return (NULL);
	if (!create_array(arr, s, c))
	{
		free(arr);
		arr = NULL;
	}
	return (arr);
}
