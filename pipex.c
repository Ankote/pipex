/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:49:59 by aankote           #+#    #+#             */
/*   Updated: 2023/02/14 08:58:40 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "unistd.h"

char	**get_paths(char **env)
{
	while (env)
	{
		if (!ft_strncmp(*env, "PATH", 4))
			return (ft_split(*env + 5, ':'));
		env++;
	}
	return (0);
}

char	*get_cmd(char **env, char *cmd)
{
	int		i;
	char	*command;
	char	**paths;

	i = -1;
	paths = get_paths(env);
	command = ft_calloc(1, 1);
	while (paths[++i])
	{
		command = ft_strjoin(paths[i], cmd);
		if (!access(command, X_OK))
			return (ft_free_dub(paths), command);
	}
	ft_free_dub(paths);
	return (NULL);
}

int	first_child(char **av, int fd[2], char **path)
{
	char	**sp_arg;
	char	*cm;
	char	*cmd;
	int		i;
	int		fd_in;

	i = -1;
	sp_arg = ft_split(av[2], ' ');
	cm = ft_strjoin("/", sp_arg[0]);
	close(fd[0]);
	fd_in = open(av[1], O_RDONLY);
	execve(av[2], sp_arg, NULL);
	dup2(fd_in, 0);
	dup2(fd[1], 1);
	while (path[++i])
	{
		cmd = ft_strjoin(path[i], cm);
		execve(cmd, sp_arg, path);
		free(cmd);
	}
	close(fd_in);
	return (free(cm), ft_free_dub(sp_arg), 0);
}

int	second_chiled(char **av, int fd[2], char **path)
{
	char	**sp_arg;
	char	*cm;
	char	*cmd;
	int		i;
	int		fd_out;

	i = -1;
	fd_out = open(av[4], O_CREAT | O_TRUNC | O_RDWR, 0777);
	close(fd[1]);
	dup2(fd_out, 1);
	dup2(fd[0], 0);
	sp_arg = ft_split(av[3], ' ');
	cm = ft_strjoin("/", sp_arg[0]);
	execve(av[3], sp_arg, NULL);
	while (path[++i])
	{
		cmd = ft_strjoin(path[i], cm);
		execve(cmd, sp_arg, path);
		free(cmd);
	}
	close(fd_out);
	return (free(cm), ft_free_dub(sp_arg), 0);
}

int	main(int argc, char **argv, char **env)
{
	int		id1;
	int		id2;
	int		fd[2];
	char	**paths;

	paths = get_paths(env);
	if (argc == 5)
	{
		if (access(argv[1], R_OK) == -1)
			ft_error(argv[1], ": No such file or directory");
		pipe(fd);
		id1 = fork();
		if (!id1)
		{
			first_child(argv, fd, paths);
			ft_error("command not found : ", argv[2]);
		}
		id2 = fork();
		if (!id2)
		{
			second_chiled(argv, fd, paths);
			ft_error("command not found : ", argv[3]);
		}
		ft_exit(fd, id1, id2, paths);
	}
}
