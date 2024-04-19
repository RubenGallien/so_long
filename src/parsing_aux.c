/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallien <rgallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:39:47 by rgallien          #+#    #+#             */
/*   Updated: 2024/04/19 15:25:54 by rgallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	not_ber(char *_file)
{
	char	*str;
	int		comp;

	str = ft_strrchr(_file, '.');
	if (!str)
		return (0);
	comp = ft_strncmp(str, ".ber", 5);
	if (comp != 0)
		return (0);
	return (1);
}

void	print_error(int e, int p, int c, char *line)
{
	free(line);
	if (e != 1)
		ft_printf("Error\nThe number of exit should be 1\n");
	if (p != 1)
		ft_printf("Error\nThe number of player should be one\n");
	if (c < 1)
		ft_printf("Error\nThere is not enough collectibles\n");
	exit(EXIT_SUCCESS);
}

int	get_last_line(int fd, char *_file)
{
	int		last;
	char	*ligne;

	last = 0;
	fd = open(_file, O_RDONLY);
	if (fd > 0)
	{
		ligne = get_next_line(fd);
		while (ligne)
		{
			last++;
			free(ligne);
			ligne = get_next_line(fd);
		}
		free(ligne);
	}
	close(fd);
	return (last);
}

char	*check_fd(char *_file, int fd)
{
	char	*tmp;

	if (fd == -1 || !not_ber(_file))
	{
		ft_printf("Error\nIncorrect File\n");
		exit(EXIT_SUCCESS);
	}
	tmp = get_next_line(fd);
	if (!tmp)
	{
		ft_printf("Error\nFichier incomplet\n");
		exit(EXIT_SUCCESS);
	}
	return (tmp);
}

char	**ft_mapping(char *_file)
{
	int		fd;
	char	**map;
	char	*str;
	char	*tmp;

	fd = open(_file, O_RDONLY);
	tmp = check_fd(_file, fd);
	str = ft_strdup(tmp);
	while (tmp)
	{
		free(tmp);
		tmp = get_next_line(fd);
		if (tmp)
			str = ft_strjoin(str, tmp);
	}
	map = ft_split(str, '\n');
	return (close(fd), free(str), map);
}
