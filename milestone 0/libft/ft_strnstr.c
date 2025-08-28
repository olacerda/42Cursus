/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 22:43:09 by otlacerd          #+#    #+#             */
/*   Updated: 2025/04/18 17:30:13 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
*/

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	cntbig;
	size_t	cntlittle;

	cntbig = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (cntbig < len && big[cntbig] != '\0')
	{
		cntlittle = 0;
		while (big[cntbig + cntlittle] == little[cntlittle] \
				&& (cntbig + cntlittle < len) && little[cntlittle] != '\0')
			cntlittle++;
		if (little[cntlittle] == '\0')
			return ((char *)&big[cntbig]);
		cntbig++;
	}
	return (NULL);
}

/*
int	main(void)
{
	const char	big[] = "abcdef";
	const char	little[] = "cde";
	size_t	len;

	len = 5;
	printf("%s", ft_strnstr(big, little, len));
}
*/