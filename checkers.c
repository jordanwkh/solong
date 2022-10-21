/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checkers.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhoekstr <jhoekstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 13:06:39 by jhoekstr      #+#    #+#                 */
/*   Updated: 2022/10/21 17:10:37 by jhoekstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

bool	xwall_checker(t_game *info)
{
	int	x;

	x = 0;
	while (info->map[0][x] != '\0')
	{
		if (info->map[0][x] != '1')
			return (false);
		x++;
	}
	x = 0;
	while (info->map[info->maplen -1][x] != '\0')
	{	
		if (info->map[info->maplen -1][x] != '1')
			return (false);
		x++;
	}
	return (true);
}

bool	ywall_checker(t_game *info)
{
	int	y;

	y = 0;
	while (info->map[y])
	{
		if (info->map[y][0] != '1' || info->map[y][info->mapwidth -1] != '1')
			return (false);
		y++;
	}
	return (true);
}

bool	map_form_check(t_game *info)
{
	int	y;
	int	x;

	y = 0;
	while (info->map[y])
	{
		x = 0;
		while (info->map[y][x])
			x++;
		if (x != info->mapwidth)
			return (false);
		y++;
	}
	return (true);
}

bool	checkers(t_game *info)
{
	int				x;
	int				y;
	char	**copymap;

	if (map_form_check(info) == false)
	{
		ft_printf("%s\n", "Map is not sqaure, or rectangular");
		return (false);
	}	
	if (xwall_checker(info) == false)
	{
		ft_printf("%s\n", "Top or bottom wall is not closed off");
		return (false);
	}	
	if (ywall_checker(info) == false)
	{
		ft_printf("%s\n", "Left or right wall is not closed off");
		return (false);
	}	
	y = 0;
	x = 0;
	copymap = info->map;
	floodfill(info, x, y);
	// {
	// 	ft_printf("%s\n", "Map can not be completed");
	// 	return (false);
	// }
	return (true);
}	

void	floodfill(t_game *info, int x, int y)
{
	int	collect;

	collect = 0;
	if (info->map[y][x] == 'E')
	{
		ft_printf("%s\n", "test E");
		info->exit_reach = true;
		return ;
	}	
	else if (info->map[y][x] == '1')
	{
		ft_printf("%s\n", "test 1");
		return ;
	}	
	else if (info->map[y][x] == 'C')
	{
		ft_printf("%s\n", "test C");
		collect++;
		if (collect == info->collectable)
		{
			info->collect_reach = true;
			return ;
		}	
	}
	info->map[y][x] = 1;
	floodfill (info, x, (y - 1));
	floodfill (info, (x + 1), y);
	floodfill (info, x, (y + 1));
	floodfill (info, (x - 1), y);
}