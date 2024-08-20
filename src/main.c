#include "../include/cub3d.h"

void	init_null(t_data *data)
{
	data->path_N = NULL;
	data->path_S = NULL;
	data->path_W = NULL;
	data->path_E = NULL;
	data->all_file = NULL;
	data->map = NULL;
}

int	main(int ac, char **av)
{
	t_data	data;

	// parsing
	init_null(&data);
	parsing(ac, av, &data);
	printf("Go");
	return (0);
}
