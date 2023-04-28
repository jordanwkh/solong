/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checkers.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhoekstr <jhoekstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 13:06:39 by jhoekstr      #+#    #+#                 */
/*   Updated: 2023/04/28 16:44:20 by jhoekstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	check_ber_map(char *arg)
{
	int	i;

	i = 0;
	if (!arg)
		return (0);
	while (arg[i])
		i++;
	i = i - 1;
	if (arg[i] == 'r' && arg[i - 1] == 'e' && \
			arg[i - 2] == 'b' && arg[i - 3] == '.')
		return (1);
	return (0);
}

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
	if (checkingthemap(info) == false)
	{
		ft_printf("%s\n", "Map can not be completed");
		return (false);
	}
	return (true);
}	
