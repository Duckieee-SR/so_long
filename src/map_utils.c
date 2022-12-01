/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaro-l <gamaro-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:44:36 by gamaro-l          #+#    #+#             */
/*   Updated: 2022/12/01 19:13:05 by gamaro-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	***m(void)
{
	static char	**hipopotomonstroesquipedliofobia;

	return (&hipopotomonstroesquipedliofobia);
}

int	mapsize(char *name)
{
	int		i;
	int		fd;
	char	c[1];

	i = 0;
	fd = open(name, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (read (fd, c, 1))
	{
		if (c[0] == '\n')
			i++;
	}
	if (c[0] != '\n')
		i++;
	close (fd);
	return (i);
}

void	getmap(char ***mapa, char *nome)
{
	int	df;
	int	y;
	int	i;

	i = 0;
	y = mapsize(nome);
	if (y < 3)
		write (2, "There has been an error", 24);
	*mapa = (char **)malloc(sizeof(char *) * (y + 1));
	df = open(nome, O_RDONLY);
	(*mapa)[i] = get_next_line(df);
	while ((*mapa)[i])
	{
		i++;
		(*mapa)[i] = get_next_line(df);
	}
	(*mapa)[i] = NULL;
	close(df);
}

int	checkchar(void)
{
	t_check	c;

	c.i = -1;
	c.c = 0;
	c.e = 0;
	c.p = 0;
	while ((*m())[++c.i])
	{
		c.j = -1;
		while ((*m())[c.i][++c.j])
			if (check_char2(&c))
				return (1);
	}
	if (c.p != 1 || c.e != 1 || !c.c)
		return (1);
	return (0);
}

int	isclosed(char **mapa)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (mapa[0][++j])
		if (mapa[0][j] != '1' && mapa[0][j] != '\n')
			return (1);
	while (mapa[++i])
		if (mapa[i][0] != '1' || mapa[i][maplength(mapa[i]) - 2] != '1')
			return (1);
	j = -1;
	while (mapa[i - 1][++j])
		if (mapa[i - 1][j] != '1' && mapa[i - 1][j] != '\n')
			return (1);
	return (0);
}
