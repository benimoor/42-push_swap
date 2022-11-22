/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 22:53:28 by ergrigor          #+#    #+#             */
/*   Updated: 2022/11/22 23:06:40 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	index;
	size_t	slen;

	index = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		ptr = malloc(sizeof(char));
		ptr[0] = '\0';
		return (ptr);
	}
	slen = ft_strlen(s + start);
	if (slen < len)
		len = slen;
	ptr = (char *)malloc(len);
	if (!ptr)
		return (0);
	while (index < len)
		ptr[index++] = s[start++];
	ptr[index] = '\0';
	return (ptr);
}
