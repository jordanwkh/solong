/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhoekstr <jhoekstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/29 16:39:14 by jhoekstr      #+#    #+#                 */
/*   Updated: 2022/11/01 13:19:09 by jhoekstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

bool	start_mlx(t_game *info)
{
	mlx_set_setting(MLX_MAXIMIZED, true);
	info->mlx = mlx_init((info->mapwidth * 100), \
	(info->maplen * 100), "so_long", false);
	if (!info->mlx)
		return (false);
	set_images(info);
	put_backg(info);
	putimg(info);
	mlx_key_hook(info->mlx, (mlx_keyfunc)my_keyhook, info);
	mlx_loop(info->mlx);
	return (true);
}
