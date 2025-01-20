/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschetti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:50:14 by tschetti          #+#    #+#             */
/*   Updated: 2023/11/06 17:59:42 by tschetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dest_ptr;
	const char	*src_ptr;

	if (dest == NULL && src == NULL)
		return (NULL);
	dest_ptr = (char *)dest;
	src_ptr = (const char *)src;
	if (dest_ptr > src_ptr && dest_ptr < src_ptr + n)
	{
		dest_ptr += n;
		src_ptr += n;
		while (n--)
		{
			*(--dest_ptr) = *(--src_ptr);
		}
	}
	else
	{
		while (n--)
		{
			*dest_ptr++ = *src_ptr++;
		}
	}
	return (dest);
}
