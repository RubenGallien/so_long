/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallien <rgallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:10:25 by rgallien          #+#    #+#             */
/*   Updated: 2024/04/15 12:03:08 by rgallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_char(t_data *data)
{
	int		i;
	int		c;
	char	*style[8];

	style[0] = CHAR_DOWN_0;
	style[1] = CHAR_DOWN_1;
	style[2] = CHAR_LEFT_0;
	style[3] = CHAR_LEFT_1;
	style[4] = CHAR_RIGHT_0;
	style[5] = CHAR_RIGHT_1;
	style[6] = CHAR_UP_0;
	style[7] = CHAR_UP_1;
	c = -1;
	i = -1;
	while (++i < 2)
		set_data_assets(data, style[++c], &data->asset.char_down_tab[i]);
	i = -1;
	while (++i < 2)
		set_data_assets(data, style[++c], &data->asset.char_left_tab[i]);
	i = -1;
	while (++i < 2)
		set_data_assets(data, style[++c], &data->asset.char_right_tab[i]);
	i = -1;
	while (++i < 2)
		set_data_assets(data, style[++c], &data->asset.char_up_tab[i]);
}
