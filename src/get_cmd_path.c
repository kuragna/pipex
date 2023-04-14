/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <aabourri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:05:22 by aabourri          #+#    #+#             */
/*   Updated: 2023/04/14 14:07:57 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*get_cmd_path(char **paths, char *cmd)
{
	char	**args;
	char	*slash;
	char	*path;
	int		i;

	i = -1;
	args = ft_split(cmd, ' ');
	while (paths[++i] != NULL)
	{
		slash = ft_strjoin(paths[i], "/");
		path = ft_strjoin(slash, args[0]);
		free(slash);
		if (access(path, X_OK) == 0)
		{
			get_freed(args);
			return (path);
		}
		free(path);
	}
	get_freed(args);
	return (cmd);
}
