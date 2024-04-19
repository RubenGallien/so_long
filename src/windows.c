/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallien <rgallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 01:12:58 by rgallien          #+#    #+#             */
/*   Updated: 2024/03/17 22:01:56 by rgallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(char **strs)
{
	int	j;

	j = 0;
	while (strs[j])
		j++;
	if (strs)
	{
		while (--j >= 0)
		{
			if (strs[j])
			{
				free(strs[j]);
				strs[j] = NULL;
			}
		}
		free(strs);
	}
}

int	ft_atoii(const char *str)
{
	int	i;
	int	result;
	int	signe;

	result = 0;
	i = 0;
	signe = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32 || str[i] == '"')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			signe = -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	return (result * signe);
}

int	*get_bg_size(char *asset, char *str, int i)
{
	int		fd;
	int		*tab;
	char	**img_ln;

	tab = malloc(sizeof(int) * 2);
	if (!tab)
		return (NULL);
	fd = open(asset, O_RDONLY);
	str = get_next_line(fd);
	while (str && ++i < 4)
	{
		free(str);
		str = get_next_line(fd);
	}
	img_ln = ft_split(str, ' ');
	tab[0] = ft_atoii(img_ln[0]);
	tab[1] = ft_atoii(img_ln[1]);
	return (free(str), ft_free(img_ln), close(fd), tab);
}

int	*get_map_size(char *_file, char *str)
{
	int		fd;
	int		*tab;
	int		x;
	int		y;

	x = 0;
	fd = open(_file, O_RDONLY);
	tab = malloc(sizeof(int) * 2);
	if (!tab)
		return (NULL);
	str = get_next_line(fd);
	while (str[x] && str[x] != '\n')
		x++;
	y = 1;
	free(str);
	str = get_next_line(fd);
	while (str)
	{
		y++;
		free(str);
		str = get_next_line(fd);
	}
	tab[0] = x;
	tab[1] = y;
	return (free(str), close(fd), tab);
}

int	*get_x_y(char *_file, char *asset)
{
	int		*map_size;
	int		*bg_size;
	int		*win_size;

	win_size = malloc(sizeof(int) * 4);
	if (!win_size)
		return (NULL);
	map_size = get_map_size(_file, NULL);
	bg_size = get_bg_size(asset, NULL, 0);
	win_size[0] = (map_size[0] * bg_size[0]);
	win_size[1] = (map_size[1] * bg_size[1]);
	win_size[2] = map_size[0];
	win_size[3] = map_size[1];
	return (free(map_size), free(bg_size), win_size);
}
