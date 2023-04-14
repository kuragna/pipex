/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <aabourri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:48:13 by aabourri          #+#    #+#             */
/*   Updated: 2023/04/14 14:08:00 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <string.h>
# include <stdarg.h>
# include <errno.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct s_pipex
{
	char	**envp;
	char	**paths;
	char	**argv;
	int		fd[2];
	int		pipes[2];
	pid_t	pid;
}	t_pipex;

void	print_err(char *fmt, ...);
void	print_error(char *cmd, int err);
char	*get_cmd_path(char **paths, char *cmd);
char	**get_paths(char **envp);
void	*get_freed(char **s);
void	first_cmd(t_pipex *p);
void	second_cmd(t_pipex *p);
int		check_sh(char *cmd);
#endif
