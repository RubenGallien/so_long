/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallien <rgallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:12:22 by rgallien          #+#    #+#             */
/*   Updated: 2024/03/19 13:26:49 by rgallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_final(char **map, int i, int j, t_data *data)
{
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'E')
			{
				ft_free_tab(map);
				ft_free_tab(data->map);
				ft_printf("Error\nThe exit is unreachable\n");
				exit(EXIT_SUCCESS);
			}
			if (map[j][i] == 'C')
			{
				ft_free_tab(map);
				ft_free_tab(data->map);
				ft_printf("Error\nAll items need to be reachable\n");
				exit(EXIT_SUCCESS);
			}
			i++;
		}
		j++;
	}
}

int	exec(char **map, int j, int i)
{
	if (map[j][i - 1] == '0' || map[j][i - 1] == 'C' || \
	map[j][i - 1] == 'E')
		return (1);
	else if (map[j][i + 1] == '0' || map[j][i + 1] == 'C' || \
	map[j][i + 1] == 'E')
		return (1);
	else if (map[j + 1][i] == '0' || map[j + 1][i] == 'C' || \
	map[j + 1][i] == 'E')
		return (1);
	else if (map[j - 1][i] == '0' || map[j - 1][i] == 'C' || \
	map[j - 1][i] == 'E')
		return (1);
	else
		return (0);
}

void	full_path(char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'x' && exec(map, j, i))
			{
				fill_left(map, i, j);
				fill_right(map, i, j);
				fill_up(map, i, j);
				fill_down(map, i, j);
				i = 0;
				j = 0;
			}
			else
				i++;
		}
		j++;
	}
}

char	**cpy_map(t_data *data)
{
	int		i;
	int		j;
	int		nb;
	char	**copy_map;

	i = 0;
	j = 0;
	nb = 0;
	while (data->map[nb])
		nb++;
	copy_map = malloc(sizeof(char *) * (nb + 1));
	if (!copy_map)
		return (NULL);
	while (data->map[i])
	{
		copy_map[j] = ft_strdup(data->map[i]);
		i++;
		j++;
	}
	copy_map[i] = 0;
	return (copy_map);
}

void	is_possible(t_data *data)
{
	t_pos	pos;
	char	**map;

	map = cpy_map(data);
	find_p(map, &pos);
	fill_left(map, pos.x, pos.y);
	fill_right(map, pos.x, pos.y);
	fill_up(map, pos.x, pos.y);
	fill_down(map, pos.x, pos.y);
	full_path(map);
	check_final(map, 0, 0, data);
	ft_free_tab(map);
}
