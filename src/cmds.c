/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <aabourri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:00:50 by aabourri          #+#    #+#             */
/*   Updated: 2023/04/14 13:01:11 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	close_fd(int *fd, int *pipes)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		close(fd[i]);
		close(pipes[i]);
		i++;
	}
}

static int	get_char(char *cmd)
{
	if (ft_strchr(cmd, '\''))
		return (39);
	else if (ft_strchr(cmd, '\"'))
		return (34);
	return (32);
}

void	first_cmd(t_pipex *p)
{
	char	**args;
	char	*cmd;

	if (p->fd[0] == -1 || check_sh(p->argv[2]) == -1)
		return ;
	cmd = get_cmd_path(p->paths, p->argv[2]);
	if (access(cmd, X_OK) == -1)
	{
		print_error(p->argv[2], errno);
		return ;
	}
	args = ft_split(p->argv[2], get_char(p->argv[2]));
	if (!args)
		return ;
	dup2(p->fd[0], 0);
	dup2(p->pipes[1], 1);
	close_fd(p->fd, p->pipes);
	execve(cmd, args, p->envp);
}

void	second_cmd(t_pipex *p)
{
	char	**args;
	char	*cmd;

	if (check_sh(p->argv[3]) == -1)
		exit(127);
	cmd = get_cmd_path(p->paths, p->argv[3]);
	if (access(cmd, X_OK) == -1)
	{
		print_error(p->argv[3], errno);
		if (errno == 13)
			exit(126);
		exit(127);
	}
	args = ft_split(p->argv[3], get_char(p->argv[3]));
	if (!args)
		exit(EXIT_FAILURE);
	dup2(p->pipes[0], 0);
	dup2(p->fd[1], 1);
	close_fd(p->fd, p->pipes);
	execve(cmd, args, p->envp);
}
