/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:20:29 by aabourri          #+#    #+#             */
/*   Updated: 2023/04/14 13:21:28 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	check_sh(char *cmd)
{
	if (ft_strnstr(cmd, ".sh", ft_strlen(cmd)))
	{
		if (ft_strchr(cmd, ' '))
			return (-1);
		if (!ft_strnstr(cmd, "./", 2) && !ft_strchr(cmd, '/'))
		{
			print_err("pipex: %s: command not found\n", cmd);
			return (-1);
		}
	}
	return (0);
}
