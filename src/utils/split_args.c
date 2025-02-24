/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenisse <agenisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:41:45 by agenisse          #+#    #+#             */
/*   Updated: 2025/02/24 17:41:46 by agenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	count_words(char *str)
{
	int	count;
	int	i;

	count = 1;
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' && str[i + 1] && str[i + 1] != ' ')
			count++;
		i++;
	}
	return (count);
}

static char	*extract_word(char **str)
{
	char	*word;
	char	*start;
	int		len;

	while (**str == ' ')
		(*str)++;
	start = *str;
	len = 0;
	while (**str && **str != ' ')
	{
		len++;
		(*str)++;
	}
	word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	strncpy(word, start, len);
	word[len] = '\0';
	return (word);
}

static void	free_args_array(char **args, int size)
{
	while (size > 0)
		free(args[--size]);
	free(args);
}

char	**split_args(char *str)
{
	char	**args;
	int		word_count;
	int		i;

	word_count = count_words(str);
	args = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!args)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		args[i] = extract_word(&str);
		if (!args[i])
		{
			free_args_array(args, i);
			return (NULL);
		}
		i++;
	}
	args[i] = NULL;
	return (args);
}
