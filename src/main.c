/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:03:48 by vdecleir          #+#    #+#             */
/*   Updated: 2024/08/30 16:45:35 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_null(t_data *data)
{
	int i;

	i = -1;
	while (++i < 4)
		data->path[i] = NULL;
	i = -1;
	while (++i < 4)
		data->txtr[i].img = NULL;
	data->all_file = NULL;
	data->map = NULL;
	data->ptr = NULL;
	data->win = NULL;
	data->img = NULL;
	data->rc = NULL;
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	init_null(data);
	parsing(ac, av, data);
	create_window(data);
	return (0);
}
