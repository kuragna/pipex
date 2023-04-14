/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <aabourri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:33:05 by aabourri          #+#    #+#             */
/*   Updated: 2023/04/14 14:06:01 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	process(t_pipex *p)
{
	p->fd[0] = open(p->argv[1], O_RDONLY);
	if (p->fd[0] == -1)
		print_err("pipex: %s: %s\n", p->argv[1], strerror(errno));
	p->fd[1] = open(p->argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (p->fd[1] == -1)
	{
		print_err("pipex: %s: %s\n", p->argv[4], strerror(errno));
		exit(EXIT_FAILURE);
	}
	if (pipe(p->pipes) == -1)
		print_err("pipex: %s\n", strerror(errno));
	p->pid = fork();
	if (p->pid == -1)
		print_err("%s\n", strerror(errno));
	if (p->pid == 0)
		first_cmd(p);
	if (p->pid > 0)
		second_cmd(p);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	p;

	if (argc != 5)
	{
		print_err("pipex: %s\n", strerror(EINVAL));
		exit(EXIT_FAILURE);
	}
	p.argv = argv;
	p.envp = envp;
	p.paths = get_paths(envp);
	process(&p);
	waitpid(p.pid, NULL, 0);
	get_freed(p.paths);
	return (0);
}
