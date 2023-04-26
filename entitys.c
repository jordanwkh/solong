/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   entitys.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhoekstr <jhoekstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 13:05:23 by jhoekstr      #+#    #+#                 */
/*   Updated: 2023/04/26 14:58:19 by jhoekstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <solong.h>

static bool	check(t_game *info, int x, int y)
{
	if (info->map[y][x] == 'C')
		info->collectable++;
	else if (info->map[y][x] == 'E')
		info->exit++;
	else if (info->map[y][x] == 'P')
	{
		info->myhero.x = x;
		info->myhero.y = y;
		info->player++;
	}			
	else if (info->map[y][x] != '1' && info->map[y][x] != '0')
		return (false);
	return (true);
}

static bool	check_printer(t_game *info)
{
	if (info->exit < 1)
	{
		ft_printf("%s\n", "There must be atleast 1 exit");
		return (false);
	}
	if (info->player != 1)
	{
		ft_printf("%s\n", "There has to be atleast and max 1 player");
		return (false);
	}
	if (info->collectable < 1)
	{
		ft_printf("%s\n", "There has to be atleast 1 collectable");
		return (false);
	}
	return (true);
}

bool	entity_checker(t_game *info)
{
	int	x;
	int	y;

	info->collectable = 0;
	info->exit = 0;
	info->player = 0;
	y = 0;
	while (info->map[y])
	{
		x = 0;
		while (info->map[y][x])
		{	
			if (!check (info, x, y))
				return (false);
			x++;
		}
		y++;
	}
	info->collected = info->collectable;
	if (!check_printer(info))
		return (false);
	return (true);
}
