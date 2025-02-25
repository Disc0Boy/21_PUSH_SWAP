/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenisse <agenisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:14:46 by agenisse          #+#    #+#             */
/*   Updated: 2025/02/25 12:19:25 by agenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

static char	*read_input(void)
{
	char	buffer[5000];
	char	c;
	int		i;

	i = 0;
	while (read(0, &c, 1) > 0)
	{
		buffer[i++] = c;
		if (c == '\n' || i >= 4998)
			break ;
	}
	if (i == 0)
		return (NULL);
	buffer[i] = '\0';
	return (strdup(buffer));
}

char	*get_next_line(int fd)
{
	if (fd != 0)
		return (NULL);
	return (read_input());
}

// #include <stdio.h>
// #include <fcntl.h>

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("test1.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	close(fd);
// 	return (0);
// }