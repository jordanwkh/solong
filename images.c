/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   images.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhoekstr <jhoekstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/23 16:14:04 by jhoekstr      #+#    #+#                 */
/*   Updated: 2023/04/28 15:33:53 by jhoekstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

bool	set_images(t_game *info)
{
	t_imgs	*imgs;

	imgs = &info->imgs;
	imgs->backg_tx = mlx_load_png("imgs/grass.png");
	imgs->collec_tx = mlx_load_png("imgs/apple.png");
	imgs->wall_tx = mlx_load_png("imgs/wall.png");
	imgs->exit_tx = mlx_load_png("imgs/door.png");
	imgs->hero_tx = mlx_load_png("imgs/char2.png");
	if (!imgs->backg_tx || !imgs->collec_tx || \
	!imgs->hero_tx || !imgs->wall_tx || !imgs->exit_tx)
		exit (EXIT_FAILURE);
	imgs->backg_img = mlx_texture_to_image (info->mlx, imgs->backg_tx);
	imgs->collec_img = mlx_texture_to_image (info->mlx, imgs->collec_tx);
	imgs->wall_img = mlx_texture_to_image (info->mlx, imgs->wall_tx);
	imgs->exit_img = mlx_texture_to_image (info->mlx, imgs->exit_tx);
	info->myhero.hero_img = mlx_texture_to_image (info->mlx, imgs->hero_tx);
	if (!imgs->backg_img || !imgs->collec_img || \
	!info->myhero.hero_img || !imgs->wall_img || !imgs->exit_img)
		exit (EXIT_FAILURE);
	return (true);
}		

bool	put_backg(t_game *info)
{
	int				x;
	int				y;
	const t_imgs	*imgs = &info->imgs;

	info->gamelen = info->maplen * 100;
	info->gamewidth = info->mapwidth * 100;
	y = 0;
	while (y < info->gamelen)
	{
		x = 0;
		while (x < info->gamewidth)
		{
			mlx_image_to_window(info->mlx, imgs->backg_img, x * 100, y * 100);
			if (! mlx_image_to_window(info->mlx, \
			imgs->backg_img, x * 100, y * 100))
				return (false);
			x++;
		}		
		y++;
		x = 0;
	}
	return (true);
}

static bool	img_2_win(t_game *info, int x, int y)
{
	if (info->map[y][x] == '1')
		mlx_image_to_window(info->mlx, \
			info->imgs.wall_img, x * 100, y * 100);
	else if (info->map[y][x] == 'E')
		mlx_image_to_window(info->mlx, \
			info->imgs.exit_img, x * 100, y * 100);
	else if (info->map[y][x] == 'C')
		mlx_image_to_window(info->mlx, \
			info->imgs.collec_img, x * 100, y * 100);
	else if (info->map[y][x] == 'P')
		mlx_image_to_window(info->mlx, \
			info->myhero.hero_img, x * 100, y * 100);
	return (true);
}

bool	putimg(t_game *info)
{
	int				y;
	int				x;

	y = 0;
	while (info->map[y])
	{
		x = 0;
		while (info->map[y][x])
		{
			if (!img_2_win(info, x, y))
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}
