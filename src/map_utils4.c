/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaro-l <gamaro-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:19:53 by gamaro-l          #+#    #+#             */
/*   Updated: 2022/12/01 18:51:31 by gamaro-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_matrix(char ***map)
{
	int	i;

	i = 0;
	while ((*map)[i])
	{
		free((*map)[i]);
		i++;
	}
	free(*map);
}

void	free_images(t_game *game)
{
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->floor);
	mlx_destroy_image(game->mlx, game->collect);
	mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_image(game->mlx, game->player1);
	mlx_destroy_image(game->mlx, game->player2);
	mlx_destroy_image(game->mlx, game->enemy);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_matrix(m());
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		size;
	int		i;

	size = 0;
	while (s1[size])
		size++;
	ptr = malloc(size + 1);
	if (!ptr)
		return (0);
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}

char	**copy_map(char **map)
{
	char	**new_map;
	int		i;

	i = 0;
	while (map[i])
		i++;
	new_map = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (map[i])
	{
		new_map[i] = ft_strdup(map[i]);
		i++;
	}
	new_map[i] = 0;
	return (new_map);
}

int	window_close(t_game *game)
{
	free_images(game);
	exit(0);
}
