/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 20:18:36 by otlacerd          #+#    #+#             */
/*   Updated: 2025/05/22 19:24:29 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <stdlib.h>

#include "libft.h"

static int	checkset(const char a, char const *set)
{
	int	count;

	count = 0;
	while (set[count])
	{
		if (a == set[count])
			return (1);
		count++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	int		end;
	int		count;

	if (!s1)
		return (NULL);
	while (checkset(*s1, set) == 1)
		s1++;
	end = 0;
	while (s1[end])
		end++;
	if (end == 0)
		return (ft_strdup(""));
	end--;
	while (end >= 0 && checkset(s1[end], set) == 1)
		end--;
	trimmed = (char *) malloc((end + 2) * sizeof(char));
	if (!trimmed)
		return (NULL);
	count = 0;
	while (end-- >= 0)
		trimmed[count++] = *s1++;
	trimmed[count] = '\0';
	return (trimmed);
}

// int	main(void)
// {
// 	char const	s1[] = "bbddabacatebbbd";
// 	char const set[] = "bd";
// 	char	*result = ft_strtrim(s1, set);

// 	printf("String antes: %s\n", s1);
// 	printf("String depois: %s\n", result);
// 	free(result);
// }