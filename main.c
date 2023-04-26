/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhoekstr <jhoekstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/05 15:08:10 by jhoekstr      #+#    #+#                 */
/*   Updated: 2023/04/26 15:16:01 by jhoekstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <MLX42.h>
#include <libft.h>
#include <solong.h>

char	**copyingmap(t_game *info)
{
	int		i;
	char	**copymap;

	copymap = (char **) malloc(sizeof(char *) * (info->maplen + 1));
	if (!copymap)
		free(copymap);
	i = 0;
	while (info->map[i])
	{
		copymap[i] = ft_strdup(info->map[i]);
		printf("%s\n", copymap[i]);
		i++;
	}
	copymap[i] = NULL;
	return (copymap);
}

static char	*readingmap(int fd)
{
	char	*line;
	char	*readline;
	char	*tmp;

	line = get_next_line(fd);
	if (!line)
		return (false);
	readline = line;
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		tmp = readline;
		readline = ft_strjoin(readline, line);
		free(tmp);
		if (!readline)
			(free(line));
	}
	return (readline);
}

static bool	readfile(char **argv, t_game *info)
{
	int		fd;
	char	*readline;

	fd = open (argv[1], O_RDONLY);
	if (fd == -1)
		return (false);
	readline = readingmap(fd);
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
		ft_printf("%s\n", "can't load the map");
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
	mlx_terminate(info.mlx);
	return (0);
}
