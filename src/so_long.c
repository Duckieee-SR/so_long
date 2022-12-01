/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaro-l <gamaro-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:13:19 by gamaro-l          #+#    #+#             */
/*   Updated: 2022/12/01 19:19:21 by gamaro-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//O pato 
//Vinha cantando alegremente 
//Quack quack

void	create_images(t_game *game)
{
	int	i;

	i = 0;
	game->floor = mlx_xpm_file_to_image(game->mlx, \
	"textures/Chao.xpm", &i, &i);
	game->wall = mlx_xpm_file_to_image(game->mlx, \
	"textures/wall.xpm", &i, &i);
	game->exit = mlx_xpm_file_to_image(game->mlx, \
	"textures/EXIT.xpm", &i, &i);
	game->collect = mlx_xpm_file_to_image(game->mlx, \
	"textures/collectible.xpm", &i, &i);
	game->player1 = mlx_xpm_file_to_image(game->mlx, \
	"textures/player_1.xpm", &i, &i);
	game->player2 = mlx_xpm_file_to_image(game->mlx, \
	"textures/player_2.xpm", &i, &i);
	game->enemy = mlx_xpm_file_to_image(game->mlx, \
	"textures/enemy.xpm", &i, &i);
}

//Quando o marreco sorridente pediu
//Para entrar tambem no samba no samba no samba.

t_coord	get_player(char **map)
{
	t_coord	c;

	c.y = 0;
	while (map[c.y])
	{
		c.x = 0;
		while (map[c.y][c.x])
		{
			if (map[c.y][c.x] == 'P')
				return (c);
			c.x++;
		}
		c.y++;
	}
	return (c);
}

//O ganso gostou da dupla e fez também 
//Quack, quack, quack

int	count_collec(char **map)
{
	t_coord	c;
	int		count;

	count = 0;
	c.y = 0;
	while (map[c.y])
	{
		c.x = 0;
		while (map[c.y][c.x])
		{
			if (map[c.y][c.x] == 'C')
				count++;
			c.x++;
		}
		c.y++;
	}
	return (count);
}
//Olhou pro cisne e disse assim, vem vem
//Que o quarteto ficará bem, muito bom, muito bem

int	num_size(int n)
{
	int	size;

	size = 0;
	if (n < 0)
	{
		size++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

int	main(int ac, char **av)
{
	t_cenas	cenas;
	t_game	game;
	int		i;

	i = 0;
	game.steps = 0;
	getmap(m(), av[1]);
	call_checkers();
	game.width = maplength((*m())[1]) - 1;
	game.height = mapsize(av[1]);
	game.ps = 250;
	game.c = count_collec(*m());
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.width * game.ps, \
	game.height * game.ps, "O.O UWU O.O");
	create_images(&game);
	game.player = game.player1;
	mlx_hook(game.win, 17, 0, window_close, &game);
	mlx_key_hook(game.win, key_actions, &game);
	print_map(*m(), &game);
	mlx_loop(game.mlx);
	free_images(&game);
}
