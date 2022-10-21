/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhoekstr <jhoekstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 17:45:38 by jhoekstr      #+#    #+#                 */
/*   Updated: 2022/02/01 17:18:25 by jhoekstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == ('\t') || c == ('\n') || c == ('\v')
		|| c == ('\f') || c == ('\r') || c == (' '))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	n;
	int		sign;

	n = 0;
	i = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
	}
	if (str[i] == ('-') || str[i] == ('+'))
		i++;
	while (ft_isdigit(str[i]))
	{
		n = (n * 10) + (str[i] - 48);
		i++;
	}
	return ((int)n * sign);
}
