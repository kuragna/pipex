/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <aabourri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:02:16 by aabourri          #+#    #+#             */
/*   Updated: 2023/04/12 13:26:36 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	print_err(char *fmt, ...)
{
	char	*s;
	va_list	ptr;
	int		i;

	i = 0;
	va_start(ptr, fmt);
	while (fmt[i])
	{
		if (fmt[i] == '%' && fmt[i + 1] == 's')
		{
			s = va_arg(ptr, char *);
			ft_putstr_fd(s, 2);
			i++;
		}
		else
			ft_putchar_fd(fmt[i], 2);
		i++;
	}
	va_end(ptr);
}

void	print_error(char *cmd, int err)
{
	if (err == 2)
		print_err("pipex: %s: command not found\n", cmd);
	else
		print_err("pipex: %s: %s\n", cmd, strerror(err));
}
