/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenisse <agenisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:13:36 by agenisse          #+#    #+#             */
/*   Updated: 2025/02/16 14:11:54 by agenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_convert_hex(const char *str, int i, int n)
{
	long	dest;

	dest = 0;
	while ((str[i] >= '0' && str[i] <= '9')
		|| (str[i] >= 'a' && str[i] <= 'f')
		|| (str[i] >= 'A' && str[i] <= 'F'))
	{
		if (str[i] >= '0' && str[i] <= '9')
			dest = ((dest * 16) + (str[i] - '0'));
		else if (str[i] >= 'a' && str[i] <= 'f')
			dest = ((dest * 16) + (str[i] - 'a' + 10));
		else if (str[i] >= 'A' && str[i] <= 'F')
			dest = ((dest * 16) + (str[i] - 'A' + 10));
		i++;
	}
	return (dest * n);
}

int	ft_atoi_hex(const char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = n * -1;
		i++;
	}
	return (ft_convert_hex(str, i, n));
}

// #include <stdio.h>
// int main (int argc,char ** argv)
// {
// 	if (argc == 2)
// 	{
// 		printf("%d\n", ft_atoi_hex(argv[1]));
// 	}
// 	if (argc != 2)
// 		return (0);
// }