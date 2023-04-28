/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solong.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhoekstr <jhoekstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/05 15:20:09 by jhoekstr      #+#    #+#                 */
/*   Updated: 2023/04/28 18:02:13 by jhoekstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include "MLX42.h"
# include "libft.h"
# include <stdbool.h>
# include <fcntl.h>
# include <stddef.h>
# include <string.h>
# include <limits.h>
# define WIDTH 2000
# define HEIGHT 1000

typedef struct s_mycharacter
{
	mlx_image_t		*hero_img;
	int				x;
	int				y;

}	t_mycharacter;

typedef struct s_imgs
{
	mlx_texture_t	*backg_tx;
	mlx_texture_t	*collec_tx;
	mlx_texture_t	*hero_tx;
	mlx_texture_t	*wall_tx;
	mlx_texture_t	*exit_tx;
	mlx_image_t		*backg_img;
	mlx_image_t		*collec_img;
	mlx_image_t		*wall_img;
	mlx_image_t		*exit_img;

}	t_imgs;

typedef struct s_game
{
	char			**map;
	int				maplen;
	int				mapwidth;
	int				gamelen;
	int				gamewidth;
	t_mycharacter	myhero;
	mlx_t			*mlx;
	t_imgs			imgs;
	int				collectable;
	int				collected;
	int				player;
	int				exit;
	mlx_image_t		*image;
	int				move;
	char			**copymap;
	bool			exit_reach;
	bool			collect_reach;
	char			*readline;

}	t_game;

char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
char	*get_next_line(int fd);
bool	xwall_checker(t_game *info);
bool	ywall_checker(t_game *info);
bool	entity_checker(t_game *info);
bool	map_form_check(t_game *info);
bool	put_backg(t_game *info);
bool	putimg(t_game *info);
void	my_keyhook(mlx_key_data_t keydata, t_game *info);
bool	start_mlx(t_game *info);
int		ft_printf(const char *str, ...);
bool	checkers(t_game *info);
bool	set_images(t_game *info);
bool	nowallmove(t_game *info, int x_direction, int y_direction);
bool	doing_exit(t_game *info, int x_direction, int y_direction);
void	floodfill(t_game *info, char **copymap, int x, int y);
char	**copyingmap(t_game *info);
bool	checkingthemap(t_game *info);
int		check_ber_map(char *arg);
void	free_2d(char **array);
#endif
