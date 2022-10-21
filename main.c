/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhoekstr <jhoekstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/05 15:08:10 by jhoekstr      #+#    #+#                 */
/*   Updated: 2022/10/19 14:27:27 by jhoekstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "MLX42.h"
#include "solong.h"
#include "libft.h"

static bool	readfile(char **argv, t_game *info)
{
	int		fd;
	char	*line;
	char	*readline;

	fd = open (argv[1], O_RDONLY);
	if (fd == -1)
		return (false);
	line = get_next_line(fd);
	readline = ft_strdup(line);
	if (!readline || !line)
	{
		free(line);
		free (readline);
		return (false);
	}	
	while (line)
	{
		free (line);
		line = get_next_line(fd);
		if (!line)
			break ;
		readline = ft_strjoin(readline, line);
		if (!readline)
			return (free(line), false);
	}
	info->map = ft_split(readline, '\n');
	free (readline);
	if (!info->map)
		return (false);
	return (true);
}

static bool	parse_map(char **argv, t_game *info)
{
	if (!readfile(argv, info))
	{
		printf("test\n");
		return (false);
	}
	info->maplen = 0;
	while (info->map[info->maplen] != NULL)
		info->maplen = info->maplen + 1;
	info->mapwidth = 0;
	while (info->map[0][info->mapwidth] != '\0')
		info->mapwidth = info->mapwidth + 1;
	return (entity_checker(info));
}

int	main(int argc, char **argv)
{
	t_game	info;

	info.move = 0;
	if (argc != 2)
		return (ft_printf("%s\n", "error1"));
	if (!parse_map(argv, &info))
		return (false);
	if (checkers(&info) == false)
		return (false);
	start_mlx(&info);
	mlx_loop(info.mlx);
	return (0);
}
