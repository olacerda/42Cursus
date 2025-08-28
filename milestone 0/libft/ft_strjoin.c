/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:17:08 by otlacerd          #+#    #+#             */
/*   Updated: 2025/05/22 18:40:49 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		count1;
	int		count2;

	count1 = 0;
	count2 = 0;
	if (!s1 || !s2)
		return (NULL);
	str = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[count1] != '\0')
	{
		str[count1] = s1[count1];
		count1++;
	}
	while (s2[count2] != '\0')
	{
		str[count1] = s2[count2];
		count1++;
		count2++;
	}
	str[count1] = '\0';
	return (str);
}

// int	main(void)
// {
// 	char const	s1[] = "Isso, ";
// 	char const	s2[] = "e um teste.";
// 	char	*result;

// 	result = ft_strjoin(s1, s2);
// 	printf("%s", result);
// 	free(result);
// }