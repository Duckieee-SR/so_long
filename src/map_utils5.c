/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaro-l <gamaro-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:21:03 by gamaro-l          #+#    #+#             */
/*   Updated: 2022/12/01 19:07:00 by gamaro-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_itoa(int n)
{
	char	*result;
	int		num;
	int		size;

	num = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == -0)
		return (ft_strdup("0"));
	size = (num_size(num) + 1);
	result = malloc((size) * 1);
	if (!result)
		return (0);
	return (converter(n, result, size));
}

void	move_player(char ***map, int x, int y, t_game *game)
{
	t_coord	c;

	c = get_player(*map);
	if ((*map)[c.y + y][c.x + x] != '1')
	{
		if ((*map)[c.y + y][c.x + x] == 'E' || (*map)[c.y + y][c.x + x] == 'X')
		{
			if (!game->c || (*map)[c.y + y][c.x + x] == 'X')
			{
				free_images(game);
				exit(0);
			}
		}
		else
		{
			c.l = x;
			c.h = y;
			move_player2(map, c, game);
		}
	}
}

void	print_map(char **map, t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall, \
				x * game->ps, y * game->ps);
			else if (map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->floor, \
				x * game->ps, y * game->ps);
			else
				print_map2(map, game, x, y);
			x++;
		}
		y++;
	}
}

int	key_actions(int key, t_game *game)
{
	if (key == 65307)
	{	
		free_images(game);
		exit(0);
	}
	if (key == 119)
		move_player(m(), 0, -1, game);
	if (key == 115)
		move_player(m(), 0, 1, game);
	if (key == 97)
		move_player(m(), -1, 0, game);
	if (key == 100)
		move_player(m(), 1, 0, game);
	mlx_clear_window(game->mlx, game->win);
	print_map(*m(), game);
	return (0);
}

char	*converter(int n, char *result, int size)
{
	if (n < 0)
	{
		result[0] = '-';
		n *= -1;
	}
	result[size - 1] = '\0';
	while (n > 0)
	{
		result[size - 2] = n % 10 + '0';
		n /= 10;
		size--;
	}
	return (result);
}
