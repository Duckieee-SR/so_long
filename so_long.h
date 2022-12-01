/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaro-l <gamaro-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:16:04 by gamaro-l          #+#    #+#             */
/*   Updated: 2022/12/01 19:15:10 by gamaro-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx_linux/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include "src/get_next_line.h"

typedef struct s_check
{
	int	c;
	int	e;
	int	p;
	int	i;
	int	j;
}	t_check;

typedef struct s_coord
{
	int	x;
	int	y;
	int	l;
	int	h;
}	t_coord;

typedef struct s_pipu
{
	int				x;
	int				y;
	struct s_pipu	*next;
}	t_pipu;

typedef struct s_cenas
{
	t_pipu	**clist;
	int		exit;
	int		collecc;
}	t_cenas;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*player;
	void	*player1;
	void	*player2;
	void	*enemy;
	void	*wall;
	void	*exit;
	void	*floor;
	void	*collect;
	int		steps;
	int		c;
	int		ps;
	int		width;
	int		height;
}	t_game;

char	***m(void);
int		mapsize(char *name);
void	getmap(char ***mapa, char *nome);
int		maplength(char *map);
void	free_images(t_game *game);
int		checkchar(void);
int		isclosed(char **mapa);
int		retmap(void);
int		maplength(char *map);
int		collectcount(void);
void	create_images(t_game *game);
t_coord	get_player(char **map);
int		count_collec(char **map);
void	move_player(char ***map, int x, int y, t_game *game);
void	print_map(char **map, t_game *game);
int		key_actions(int key, t_game *game);
void	free_matrix(char ***map);
void	free_images(t_game *game);
void	call_checkers(void);
void	check_collect(t_cenas *cenas, int x, int y);
int		validpath(char **mapa, int x, int y, t_cenas *cenas);
void	ft_lstclear(t_pipu **pupi);
void	pupiadd_back(t_pipu **pupi, t_pipu *new);
t_pipu	*new_module(int x, int y);
void	init_list(char **map);
char	*ft_strdup(const char *s1);
char	**copy_map(char **map);
int		window_close(t_game *game);
void	print_map2(char **map, t_game *game, int x, int y);
void	move_player2(char ***map, t_coord c, t_game *game);
char	*ft_itoa(int n);
char	*converter(int n, char *result, int size);
int		num_size(int n);
int		check_char2(t_check *c);
#endif