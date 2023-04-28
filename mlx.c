/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhoekstr <jhoekstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/29 16:39:14 by jhoekstr      #+#    #+#                 */
/*   Updated: 2023/04/28 18:14:53 by jhoekstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

bool	start_mlx(t_game *info)
{
	info->mlx = mlx_init((info->mapwidth * 100),
			(info->maplen * 100), "so_long", true);
	if (!info->mlx)
		exit(EXIT_FAILURE);
	set_images(info);
	put_backg(info);
	putimg(info);
	mlx_key_hook(info->mlx, (mlx_keyfunc)my_keyhook, info);
	mlx_loop(info->mlx);
	exit(EXIT_FAILURE);
}
