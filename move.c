/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhoekstr <jhoekstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/22 16:08:21 by jhoekstr      #+#    #+#                 */
/*   Updated: 2022/11/18 15:46:39 by jhoekstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	my_keyhook(mlx_key_data_t keydata, t_game *info)
{
	mlx_instance_t	*justtheinstance;

	justtheinstance = info->myhero.hero_img->instances;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS && \
	nowallmove(info, 0, -1))
		justtheinstance->y = justtheinstance->y - 100;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE && \
	nowallmove(info, 1, 0))
		justtheinstance->x = justtheinstance->x + 100;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE && \
	nowallmove(info, -1, 0))
		justtheinstance->x = justtheinstance->x - 100;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE && \
	nowallmove(info, 0, 1))
		justtheinstance->y = justtheinstance->y + 100;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(info->mlx);
}

static void	move_count(t_game *info)
{
	info->move++;
	ft_printf("You have moved %d steps\n", info->move);
}

bool	nowallmove(t_game *info, int x_direction, int y_direction)
{
	int				px;
	int				py;
	int				i;
	const t_imgs	*imgs = &info->imgs;

	i = 0;
	px = info->myhero.x + x_direction;
	py = info->myhero.y + y_direction;
	if (info->map[py][px] == '1')
		return (false);
	else if (info->map[py][px] == 'C')
	{	
		while (i < info->collectable)
		{
			if (imgs->collec_img->instances[i].x == px * 100 && \
			imgs->collec_img->instances[i].y == py * 100)
				imgs->collec_img->instances[i].enabled = false;
			i++;
		}
	}
	doing_exit(info, x_direction, y_direction);
	info->myhero.x += x_direction;
	info->myhero.y += y_direction;
	move_count(info);
	return (true);
}

bool	doing_exit(t_game *info, int x_direction, int y_direction)
{
	int				px;
	int				py;

	px = info->myhero.x + x_direction;
	py = info->myhero.y + y_direction;
	if (info->map[py][px] == 'E' && info->collected != 0)
		return (false);
	if (info->map[py][px] == 'C')
	{
		info->collected--;
		info->map[py][px] = '0';
	}	
	if (info->map[py][px] == 'E' && info->collected == 0)
		mlx_close_window(info->mlx);
	return (true);
}
