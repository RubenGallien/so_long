/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallien <rgallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:26:32 by rgallien          #+#    #+#             */
/*   Updated: 2024/04/19 14:04:38 by rgallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	what_letters(char *_file, int e, int p, int c)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(_file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		i = -1;
		while (line[++i])
		{
			if (line[i] == 'E')
				e++;
			else if (line[i] == 'P')
				p++;
			else if (line[i] == 'C')
				c++;
		}
		free(line);
		line = get_next_line(fd);
	}
	if (e != 1 || p != 1 || c < 1)
		print_error(e, p, c, line);
	return (free(line), close(fd), c);
}

void	are_walls_aux(int fd, char *line, int last, int i)
{
	while (i++ < last)
	{
		if (line && line[0] == '1' && line[ft_strlen(line) - 2] == '1')
		{
			free(line);
			line = get_next_line(fd);
		}
		else
		{
			free(line);
			ft_printf("Error\nThe map isn't surrounded by walls\n");
			exit(EXIT_FAILURE);
		}
	}
	i = 0;
	while (line[i] != '\n')
	{
		if (line[i++] != '1')
		{
			free(line);
			ft_printf("Error\nThe map isn't surrounded by walls\n");
			exit(EXIT_FAILURE);
		}
	}
	free(line);
}

void	are_walls(char	*_file, int last)
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	fd = open(_file, O_RDONLY);
	line = get_next_line(fd);
	while (line && line[i] != '\n')
	{
		if (line[i] != '1')
		{
			free(line);
			ft_printf("Error\nThe map isn't surrounded by walls\n");
			exit(EXIT_SUCCESS);
		}
		i++;
	}
	free(line);
	line = get_next_line(fd);
	are_walls_aux(fd, line, last - 1, 1);
	close(fd);
}

void	is_rectangular(int fd)
{
	char	*line;
	int		ln;
	int		tmp;

	line = get_next_line(fd);
	ln = ft_strlen(line);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line)
			tmp = ft_strlen(line);
		else
			return ;
		if (tmp != ln || ln == 0)
		{
			free(line);
			ft_printf("Error\nThe map isn't rectangular\n");
			exit(EXIT_FAILURE);
		}
	}
	close(fd);
	free(line);
}

int	verif_map(char *_file, t_data *data)
{
	int	fd;
	int	last_line;

	fd = open(_file, O_RDONLY);
	if (fd == -1)
		return (perror(0), 0);
	last_line = get_last_line(fd, _file);
	is_rectangular(fd);
	are_walls(_file, last_line);
	data->player.c_max = what_letters(_file, 0, 0, 0);
	is_possible(data);
	close(fd);
	return (0);
}
