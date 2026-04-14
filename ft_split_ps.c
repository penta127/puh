/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_ps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koito <koito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:54:58 by koito             #+#    #+#             */
/*   Updated: 2025/12/15 22:52:13 by koito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t		len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

size_t	col_malloc_len(char const *s, char c)
{
	size_t	i;
	size_t	s_len;
	size_t	result_len;

	if (s == NULL)
		return (0);
	s_len = ft_strlen(s);
	i = 0;
	result_len = 0;
	while (i < s_len)
	{
		if ((s[i] != c) && (i == 0 || s[i - 1] == c))
			result_len++;
		i++;
	}
	return (result_len);
}

char	*ft_strdup_sp(const char *src, char c, size_t i)
{
	char	*out;
	size_t	start;
	size_t	j;

	start = i;
	while (src[i] != '\0' && src[i] != c)
		i++;
	out = malloc(i - start + 1);
	if (out == NULL)
		return (NULL);
	j = 0;
	while (start < i)
	{
		out[j] = src[start];
		j++;
		start++;
	}
	out[j] = '\0';
	return (out);
}

char	**resu_sp(t_stacks *st, char **out, char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			out[j] = ft_strdup_sp(s, c, i);
			if (out[j] == NULL)
				free_split_stacks(st, out);
			j++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
		else
			i++;
	}
	out[j] = NULL;
	return (out);
}

char	**ft_split_ps(t_stacks *stacks, char const *s, char c)
{
	char	**out;

	if (s == NULL)
		free_split_stacks(stacks, NULL);
	out = malloc((sizeof(char *)) * (col_malloc_len(s, c) + 1));
	if (out == NULL)
		free_split_stacks(stacks, NULL);
	resu_sp(stacks, out, s, c);
	return (out);
}
