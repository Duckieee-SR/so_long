/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaro-l <gamaro-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:15:29 by gamaro-l          #+#    #+#             */
/*   Updated: 2022/12/01 18:51:19 by gamaro-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	validpath(char **mapa, int x, int y, t_cenas *cenas)
{
	if (mapa[y][x] == 'C')
		check_collect(cenas, x, y);
	mapa[y][x] = '2';
	if (mapa[y][x - 1] == 'E' || mapa[y][x + 1] == 'E' \
		|| mapa[y - 1][x] == 'E' || mapa[y + 1][x] == 'E' && cenas->exit)
		cenas->exit--;
	if (mapa[y][x - 1] != '1' && mapa[y][x - 1] != '2' \
	&& mapa[y][x - 1] != 'E' && mapa[y][x - 1] != 'X')
		validpath(mapa, x - 1, y, cenas);
	if (mapa[y][x + 1] != '1' && mapa[y][x + 1] != '2' \
	&& mapa[y][x + 1] != 'E' && mapa[y][x + 1] != 'X')
		validpath(mapa, x + 1, y, cenas);
	if (mapa[y - 1][x] != '1' && mapa[y - 1][x] != '2' \
	&& mapa[y - 1][x] != 'E' && mapa[y - 1][x] != 'X')
		validpath(mapa, x, y - 1, cenas);
	if (mapa[y + 1][x] != '1' && mapa[y + 1][x] != '2' \
	&& mapa[y + 1][x] != 'E' && mapa[y + 1][x] != 'X')
		validpath(mapa, x, y + 1, cenas);
	if (!cenas->collecc && cenas->exit <= 0)
		return (0);
	return (1);
}

void	call_checkers(void)
{
	if (checkchar() == 1 || isclosed(*m()) == 1 || retmap() == 1)
	{
		write(2, "There has been an error", 24);
		free_matrix(m());
		exit(0);
	}
	init_list(copy_map(*m()));
}

t_pipu	*new_module(int x, int y)
{		
	t_pipu	*linker;

	linker = (t_pipu *)malloc(sizeof(*linker));
	if (linker == NULL)
		return (0);
	linker->x = x;
	linker->y = y;
	linker->next = NULL;
	return (linker);
}

void	pupiadd_back(t_pipu **pupi, t_pipu *new)
{
	t_pipu	*ptr;

	ptr = *pupi;
	if (!new)
	{
		ft_lstclear(pupi);
		write(1, "ERROR: malloc = NULL\n", 21);
		exit(1);
	}
	if (!(*pupi))
	{
		*pupi = new;
		return ;
	}
	if (ptr == NULL)
		ptr = new;
	while (ptr -> next != NULL)
		ptr = ptr -> next;
	ptr -> next = new;
}

void	ft_lstclear(t_pipu **pupi)
{
	t_pipu	*ptr;

	if (!pupi || !*pupi)
		return ;
	while (pupi && *pupi)
	{
		ptr = (*pupi)->next;
		free(*pupi);
		*pupi = ptr;
	}
}
