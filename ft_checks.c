/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-berr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:14:49 by ple-berr          #+#    #+#             */
/*   Updated: 2022/01/14 15:13:40 by ple-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_pipex.h"

int	check_files(char *argv)
{
	if ((access(argv, F_OK)) == 0 && (access(argv, W_OK)) == -1)
	{
		ft_errors(3, argv);
		return (-1);
	}
	return (0);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(2, &str[i++], 1);
}

void	ft_puterror(char *cmd, char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
		write(2, &msg[i++], 1);
	i = 0;
	while (cmd[i])
		write(2, &cmd[i++], 1);
	write(2, "\n", 1);
}

void	ft_errors(int err_nb, char *cmd)
{
	if (err_nb == 0)
		ft_puterror(cmd, "Pipex: no such file or directory: ");
	if (err_nb == 1)
		ft_puterror(cmd, "Pipex: command not found: ");
	if (err_nb == 2)
		ft_putstr("Pipex: permission denied: \n");
	if (err_nb == 3)
		ft_puterror(cmd, "Pipex: permission denied: ");
}
