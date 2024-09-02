/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:09:25 by lbirloue          #+#    #+#             */
/*   Updated: 2024/08/28 17:09:26 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_map_exist(char *str, t_data *data)
{
	data->fd_map = open(str, O_RDONLY);
	if (data->fd_map == -1)
		return (1);
	return (0);
}

int	check_map_name(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = (int)ft_strlen(str);
	if (len <= 4)
		return (1);
	while (i < (len - 4))
		i++;
	if (str[i] != '.' || str[i + 1] != 'c' || str[i + 2] != 'u'
		|| str[i + 3] != 'b')
		return (1);
	return (0);
}

void	parsing_arg(int ac, char **av, t_data *data)
{
	if (ac < 2)
		free_all(data, ERR ERR_ARG_NB_FEW, 1);
	else if (ac > 2)
		free_all(data, ERR ERR_ARG_NB_MUCH, 1);
	else if (check_map_name(av[1]))
		free_all(data, ERR ERR_ARG_NOT_CUB, 1);
	else if (check_map_exist(av[1], data))
		free_all(data, ERR ERR_ARG_NOT_VALID_NAME, 1);
}

void	parsing(int ac, char **av, t_data *data)
{
	parsing_arg(ac, av, data);
	// printf("ok\n");
	copy_all_file(data, av[1]);
	init_pars_data(data);
	init_rc_struct(data);
	pars_map(data);
	convert_rgb_hex_cell(data);
	convert_rgb_hex_floor(data);
}
