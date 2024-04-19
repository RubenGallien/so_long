/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallien <rgallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 20:15:30 by rgallien          #+#    #+#             */
/*   Updated: 2024/04/19 14:44:56 by rgallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	other_letters(char **map)
{
	int	i;
	int	j;
	int	u;

	i = -1;
	u = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'P' && \
			map[i][j] != 'C' && map[i][j] != '\n' && map[i][j] != 'E')
			{
				while (map[++u])
					free(map[u]);
				free(map);
				printf("Lettre incorrect\n");
				exit(EXIT_SUCCESS);
			}
		}
	}
}

void	init_data(t_data *data)
{
	data->player.step = 0;
	data->player.c = 0;
	data->player.finish = 0;
	data->time = 0;
	data->monster.active = 0;
	init_assets(data);
	init_monster(data);
}

int	main(int ac, char **av, char **env)
{
	t_data	data;
	int		width;
	int		height;

	if (!env[0] || ac != 2)
		return (0);
	data.map = ft_mapping(av[1]);
	other_letters(data.map);
	verif_map(av[1], &data);
	data.tab = get_x_y(av[1], WATER);
	width = data.tab[0];
	height = data.tab[1];
	data.mlx_ptr = mlx_init();
	init_data(&data);
	main_display(&data, width, height);
	return (0);
}
