/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Print_map_extra.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaro-l <gamaro-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:39:33 by gamaro-l          #+#    #+#             */
/*   Updated: 2022/12/01 19:14:58 by gamaro-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_char2(t_check *c)
{
	if ((*m())[c->i][c->j] != '1' && (*m())[c->i][c->j] != '0' \
		&& (*m())[c->i][c->j] != 'C' && (*m())[c->i][c->j] != 'E' \
		&& (*m())[c->i][c->j] != 'P' && (*m())[c->i][c->j] != 'X' \
		&& (*m())[c->i][c->j] != '\n')
		return (1);
	if ((*m())[c->i][c->j] == 'P')
		(c->p)++;
	if ((*m())[c->i][c->j] == 'E')
		(c->e)++;
	if ((*m())[c->i][c->j] == 'C')
		(c->c)++;
	return (0);
}

void	print_map2(char **map, t_game *game, int x, int y)
{
	if (map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->collect, \
		x * game->ps, y * game->ps);
	else if (map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->exit, \
		x * game->ps, y * game->ps);
	else if (map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->player, \
		x * game->ps, y * game->ps);
	else if (map[y][x] == 'X')
		mlx_put_image_to_window(game->mlx, game->win, game->enemy, \
		x * game->ps, y * game->ps);
}

void	move_player2(char ***map, t_coord c, t_game *game)
{
	char	*print;

	if ((*map)[c.y + c.h][c.x + c.l] == 'C')
		game->c--;
	if (game->player == game->player1)
		game->player = game->player2;
	else
		game->player = game->player1;
	game->steps++;
	print = ft_itoa(game->steps);
	write(1, "Steps: ", 7);
	write(1, print, ft_strlen(print));
	write(1, "\n", 1);
	free(print);
	(*map)[c.y][c.x] = '0';
	(*map)[c.y + c.h][c.x + c.l] = 'P';
}
