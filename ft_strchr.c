/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschetti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:18:24 by tschetti          #+#    #+#             */
/*   Updated: 2023/11/07 17:26:43 by tschetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;
	char			*chr;

	uc = (unsigned char)c;
	chr = (char *)s;
	while (*chr != uc)
	{
		if (!*chr)
			return (NULL);
		chr++;
	}
	return (chr);
}
