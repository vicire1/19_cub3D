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
		print_exit(ERR ERR_ARG_NB_FEW);
	else if (ac > 2)
		print_exit(ERR ERR_ARG_NB_MUCH);
	else if (check_map_name(av[1]))
		print_exit(ERR ERR_ARG_NOT_CUB);
	else if (check_map_exist(av[1], data))
		print_exit(ERR ERR_ARG_NOT_VALID_NAME);
}

void	print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
}

void	parsing(int ac, char **av, t_data *data)
{
	parsing_arg(ac, av, data);
	copy_all_file(data, av[1]);
	print_tab(data->all_file);
	(void)data;
}
