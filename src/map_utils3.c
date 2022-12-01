/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaro-l <gamaro-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:18:20 by gamaro-l          #+#    #+#             */
/*   Updated: 2022/12/01 18:51:25 by gamaro-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	retmap(void)
{
	int	i;
	int	length;

	i = -1;
	length = maplength((*m())[0]);
	while ((*m())[++i])
	{
		if (!(*m())[i + 1] && (*m())[i][maplength((*m())[i]) - 1] != '\n' \
			&& maplength((*m())[i]) == length)
			return (0);
		if (maplength((*m())[i]) != length)
			return (1);
	}
	return (0);
}

int	maplength(char *map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	init_list(char **map)
{
	t_pipu	*pipu;
	t_cenas	cenas;

	pipu = NULL;
	cenas.clist = &pipu;
	cenas.collecc = count_collec(map);
	cenas.exit = 1;
	if (validpath(map, get_player(map).x, get_player(map).y, &cenas))
	{
		write(2, "There has been an error", 23);
		free_matrix(m());
		free_matrix(&map);
		ft_lstclear(&pipu);
		exit(0);
	}
	ft_lstclear(&pipu);
	free_matrix(&map);
}

int	collectcount(void)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 0;
	while ((*m())[++i])
	{
		j = -1;
		while ((*m())[i][++j])
			if ((*m())[i][j] == 'C')
				count++;
	}
	return (count);
}

void	check_collect(t_cenas *cenas, int x, int y)
{
	t_pipu	*ptr;

	ptr = *(cenas->clist);
	while (ptr)
	{
		if (ptr->x == x && ptr->y == y)
			return ;
		ptr = ptr->next;
	}
	pupiadd_back(cenas->clist, new_module(x, y));
	cenas->collecc--;
}
