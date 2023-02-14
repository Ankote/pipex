/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:39:51 by aankote           #+#    #+#             */
/*   Updated: 2022/10/25 01:59:35 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	len;
	unsigned int	init_len;

	if (!dstsize && !dst)
		return (ft_strlen(src));
	i = 0;
	init_len = ft_strlen(dst);
	len = init_len;
	if (dstsize > len)
	{
		while (src[i] && len < dstsize - 1)
		{
			dst[len] = src[i];
			i++;
			len++;
		}
		dst[len] = '\0';
	}
	if (dstsize > init_len)
		return (ft_strlen(src) + init_len);
	return (ft_strlen(src) + dstsize);
}
