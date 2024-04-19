/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   design_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallien <rgallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:56:18 by rgallien          #+#    #+#             */
/*   Updated: 2024/03/15 22:05:50 by rgallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_g(t_data *data, int i, int j)
{
	int	n;

	n = 0;
	if (data->map[j][i + 1] != '1')
		n++;
	if (data->map[j][i - 1] != '1')
		n++;
	if (data->map[j + 1][i] != '1')
		n++;
	if (data->map[j - 1][i] != '1')
		n++;
	return (n);
}

int	count_w(t_data *data, int i, int j)
{
	int	n;

	n = 0;
	if (data->map[j][i + 1] == '1')
		n++;
	if (data->map[j][i - 1] == '1')
		n++;
	if (data->map[j + 1][i] == '1')
		n++;
	if (data->map[j - 1][i] == '1')
		n++;
	return (n);
}

int	count_g2(t_data *data, int i, int j)
{
	int	n;

	n = 0;
	if (data->map[j + 1][i + 1] != '1')
		n++;
	if (data->map[j + 1][i - 1] != '1')
		n++;
	if (data->map[j - 1][i + 1] != '1')
		n++;
	if (data->map[j - 1][i - 1] != '1')
		n++;
	return (n);
}

int	count_w2(t_data *data, int i, int j)
{
	int	n;

	n = 0;
	if (data->map[j + 1][i + 1] == '1')
		n++;
	if (data->map[j + 1][i - 1] == '1')
		n++;
	if (data->map[j - 1][i + 1] == '1')
		n++;
	if (data->map[j - 1][i - 1] == '1')
		n++;
	return (n);
}

int	*get_tab(t_data *data, int i, int j)
{
	int	*tab;

	tab = malloc(sizeof(int) * 4);
	tab[0] = count_g(data, i, j);
	tab[1] = count_w(data, i, j);
	tab[2] = count_g2(data, i, j);
	tab[3] = count_w2(data, i, j);
	return (tab);
}
