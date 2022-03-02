/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-berr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:22:35 by ple-berr          #+#    #+#             */
/*   Updated: 2022/01/13 16:30:45 by ple-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_pipex.h"

int	main(int argc, char *argv[], char **envp)
{
	if (argc == 5)
	{
		pipex(argv, envp);
		return (0);
	}
	ft_putstr("Wrong number of arguments !\n");
	return (1);
}
