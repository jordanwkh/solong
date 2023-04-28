/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   floodfill.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhoekstr <jhoekstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/31 15:58:27 by jhoekstr      #+#    #+#                 */
/*   Updated: 2023/04/28 18:10:17 by jhoekstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include <unistd.h>

void	free_2d(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (array[i])
			free(array[i]);
		i++;
	}
	free(array);
	array = NULL;
}

bool	checkingthemap(t_game *info)
{
	int				x;
	int				y;
	char			**copymap;

	y = info->myhero.y;
	x = info->myhero.x;
	copymap = copyingmap(info);
	floodfill(info, copymap, x, y);
	if (info->exit_reach == false)
	{
		write(2, "Could not exit\n", 16);
		exit(EXIT_FAILURE);
	}
	if (info->collect_reach == false)
	{
		write(2, "Could not collect all\n", 23);
		exit(EXIT_FAILURE);
	}
	if (info->exit_reach == false || info->collect_reach == false)
		exit(EXIT_FAILURE);
	free_2d(copymap);
	return (true);
}

void	floodfill(t_game *info, char **copymap, int x, int y)
{
	static int	collect;

	if (copymap[y][x] == '1')
		return ;
	else if (copymap[y][x] == 'E')
		info->exit_reach = true;
	else if (copymap[y][x] == 'C')
	{
		collect++;
		if (collect == info->collectable)
			info->collect_reach = true;
	}
	copymap[y][x] = '1';
	floodfill (info, copymap, (x + 1), y);
	floodfill (info, copymap, (x - 1), y);
	floodfill (info, copymap, x, (y + 1));
	floodfill (info, copymap, x, (y - 1));
}
