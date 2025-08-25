/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 23:53:38 by otlacerd          #+#    #+#             */
/*   Updated: 2025/08/17 00:31:17 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// 	else if (argc > 3)
// 		string = ft_stringjoin(argc, argv);
// int	joinsize(int size, char **string)
// {
// 	int	result;
// 	int	big;
// 	int	small;

// 	big = 1;
// 	result = 0;
// 	while (big < size)
// 	{
// 		small = -1;
// 		while (string[big][++small] != '\0')
// 			result++;
// 		big++;
// 	}
// 	return (result);
// }

// char	*ft_stringjoin(int size, char **string)
// {
// 	char	*result;
// 	int		resultsize;
// 	int		resultindex;
// 	int		big;
// 	int		small;

// 	resultsize = joinsize(size, string);
// 	resultindex = 0;
// 	result = malloc((resultsize + ((size - 2) * 3) + 1) * sizeof(char));
// 	if (!result || size < 3)
// 		return (NULL);
// 	big = 2;
// 	while (big < size)
// 	{
// 		small = -1;
// 		result[resultindex++] = '"';
// 		while (string[big][++small] != '\0')
// 			result[resultindex++] = string[big][small];
// 		result[resultindex++] = '"';
// 		if (++big < size)
// 			result[resultindex++] = ' ';
// 	}
// 	result[resultindex] = '\0';
// 	return (result);
// }

int	ft_atoi(char *string)
{
	int	result;
	int	index;
	int	minus;

	minus = 0;
	result = 0;
	index = 0;
	if (string == NULL)
		return (0);
	if (string[index] == '-')
	{
		minus = 1;
		index++;
	}
	index -= 1;
	while (string[++index] != '\0')
		result = result * 10 + (string[index] - 48);
	if (minus > 0)
		result = -result;
	return (result);
}

void	sbits(char *string, int charcount, int pid, int killcheck)
{
	int	index;

	index = 0;
	while (string[index] != '\0')
	{
		charcount = 0;
		while (charcount < 8)
		{
			if (((string[index]) >> charcount) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			if (killcheck < 0)
				exit (1);
			charcount++;
			usleep(350);
		}
		index++;
	}
}

void	bitworker(int pid, char *string)
{
	int	charcount;
	int	intcount;
	int	size;
	int	killcheck;

	charcount = 0;
	intcount = 0;
	size = 0;
	killcheck = 0;
	if (string == NULL)
		return ;
	while (string[size])
		size++;
	while (intcount < 32)
	{
		if ((size >> intcount) & 1)
			killcheck = kill(pid, SIGUSR1);
		else
			killcheck = kill(pid, SIGUSR2);
		if (killcheck < 0)
			exit(1);
		intcount++;
		usleep(350);
	}
	sbits(string, charcount, pid, killcheck);
}

int	main(int argc, char *argv[])
{
	char	*string;
	int		pid;

	pid = ft_atoi(argv[1]);
	string = NULL;
	if (pid <= 0)
	{
		write(2, "Dangerous PID for this project!!! Try another.\n", 47);
		return (1);
	}
	if (argc == 3)
		string = argv[2];
	else if (argc != 3)
	{
		write(2, "Wrong amount of arguments!!!\n", 29);
		return (1);
	}
	bitworker((unsigned int)pid, string);
}
