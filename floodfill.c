/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   floodfill.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhoekstr <jhoekstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/31 15:58:27 by jhoekstr      #+#    #+#                 */
/*   Updated: 2022/10/31 16:11:20 by jhoekstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

bool	checkingthemap(t_game *info)
{
	int				x;
	int				y;
	char			**copymap;

	y = info->myhero.y;
	x = info->myhero.x;
	copymap = copyingmap(info);
	floodfill(info, copymap, x, y);
	if (info->exit_reach == false || info->collect_reach == false)
		return (false);
	return (true);
}

void	floodfill(t_game *info, char **copymap, int x, int y)
{
	static int	collect;

	if (copymap[y][x] == '1')
		return ;
	else if (copymap[y][x] == 'E')
	{
		info->exit_reach = true;
		return ;
	}	
	else if (copymap[y][x] == 'C')
	{
		collect++;
		if (collect == info->collectable)
		{
			info->collect_reach = true;
			return ;
		}	
	}
	copymap[y][x] = '1';
	floodfill (info, copymap, (x + 1), y);
	floodfill (info, copymap, (x - 1), y);
	floodfill (info, copymap, x, (y + 1));
	floodfill (info, copymap, x, (y - 1));
}
