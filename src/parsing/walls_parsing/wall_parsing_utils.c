/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_parsing_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:06:04 by lbirloue          #+#    #+#             */
/*   Updated: 2024/08/28 17:06:06 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	check_after_word(t_data *data, char *str)
{
	int	i;

	i = 0;
	while (str[i] || is_white_space(str[i]) || str[i] == '\n')
	{
		if (!is_white_space(str[i]) && str[i] != '\n')
			free_all(data, ERR ERR_WALL_NO_DATA, 1);
		i++;
	}
}

int	get_len_of_word(char *str)
{
	int	i;

	i = 0;
	while (str[i] && !is_white_space(str[i]) && str[i] != '\n')
		i++;
	return (i);
}
