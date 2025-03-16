/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhrif <aakhrif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 20:35:17 by aakhrif           #+#    #+#             */
/*   Updated: 2025/03/14 15:27:21 by aakhrif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*get_data(void)
{
	static t_data	data;

	return (&data);
}

void	*get_game(void)
{
	static t_game	game;

	return (&game);
}

int	main(int ac, char **av)
{
	t_data	*data;
	t_game	*game;

	data = get_data();
	game = get_game();
	if (ac != 2)
		ft_error("Wrong number of arguments");
	check_path(av[1]);
	init_data(data);
	ft_check_file(av[1], data);
	check_valid_map(av[1], data);
	store_texture(data->map_lines);
	convert_fc_to_rgb(data);
	game->view_height = 2.5;
	game->map = data->map;
	game->map_width = ft_strlen(game->map[0]);
	game->map_len = map_len(game->map);
	game->c_color = r_g_b(data->ceiling->r, data->ceiling->g, data->ceiling->b);
	game->f_color = r_g_b(data->floor->r, data->floor->g, data->floor->b);
	find_player(game);
	init_keys(game);
	ft_mlx(game, data);
	return (0);
}
