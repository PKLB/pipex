/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_pipex.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-berr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 11:35:23 by ple-berr          #+#    #+#             */
/*   Updated: 2022/01/14 14:17:05 by ple-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIB_PIPEX_H
# define LIB_PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <string.h>
# include <fcntl.h>

int		main(int argc, char *argv[], char **env);
void	ft_execve(char **env, char *typed_command, int n);
void	process_one(int file1, char *argv[], char **env);
void	process_two(int file2, char *argv[], char **env);
char	*ft_find(char **env, char *str);
int		pipex(char *argv[], char **env);
char	**ft_split(char const *s, char c);
char	**ft_split_args(char const *s, char c);
void	ft_putstr(char *str);
void	ft_errors(int err_nb, char *cmd);
int		check_files(char *argv);
int		check_access(char **env, char *typed_command, int n);
void	ft_puterror(char *cmd, char *msg);
char	*ft_strjoin(char const *s1, char const *s2, int n);
size_t	ft_strlen(const char *c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
#endif
