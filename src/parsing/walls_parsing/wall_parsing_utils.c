#include "../../../include/cub3d.h"

void	check_after_word(t_data *data, char *str)
{
	int	i;

	i = 0;
	while (str[i] || is_white_space(str[i]) || str[i] == '\n')
	{
		if (!is_white_space(str[i]) && str[i] != '\n')
		{
			all_file_free(data);
			print_exit(ERR ERR_WALL_NO_DATA);
		}
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
