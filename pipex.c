/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:49:59 by aankote           #+#    #+#             */
/*   Updated: 2023/02/14 08:30:05 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "unistd.h"

char **get_paths(char **env)
{
    while (env)
    {
        if (!ft_strncmp(*env, "PATH", 4))
            return (ft_split(*env + 5, ':'));
        env++;
    }
    return (0);
}

char *get_cmd(char **env, char *cmd)
{
    int i;
    char *command;
    char **paths;

    i = -1;
    paths = get_paths(env);
    command = ft_calloc (1, 1);
    while (paths[++i])
    {
        command = ft_strjoin(paths[i], cmd);
        if(!access(command, X_OK))
            return (ft_free_dub(paths), command);
    }
    ft_free_dub(paths);
    return (NULL);
}

int first_child(char **env,char **av, int fd[2])
{
    char **argVes;
    char *cm;
    char **path;
    char *cmd;
    int vl;
    int i;
    int fd_in;
    
    i = -1;
    argVes = ft_split(av[2], ' ');
    cm = ft_strjoin("/", argVes[0]);
    path = get_paths(env);
    close(fd[0]);
    fd_in = open (av[1], O_RDONLY);
    vl = execve(av[2], argVes, NULL);
    dup2(fd_in, 0);
    dup2(fd[1], 1);
    while (path[++i])
    {
        cmd = ft_strjoin(path[i],cm);
        vl = execve(cmd, argVes, path);
        free (cmd);
    }
    close(fd_in);
    return (free(cm), ft_free_dub(argVes),  vl);
}

int second_chiled(char **env,char **av, int fd[2])
{
    char **argVes;
    char *cm;
    char **path;
    char *cmd;
    int vl;
    int i;
    int fd_out;
    
    i = -1;
    fd_out = open (av[4],O_CREAT | O_TRUNC | O_RDWR , 0777);
    close (fd[1]);
    dup2(fd_out, 1);
    dup2(fd[0], 0);
    argVes = ft_split(av[3], ' ');
    cm = ft_strjoin("/", argVes[0]);
    path = get_paths(env);
    vl = execve(av[3], argVes, NULL);
    while (path[++i])
    {
        cmd = ft_strjoin(path[i],cm);
        vl = execve(cmd, argVes, path);
        free (cmd);
    }
    close (fd_out);
    return (free(cm), ft_free_dub(argVes), vl);
}

int main(int argc, char **argv, char **env)
{  
    int id1;
    int id2;
    int fd[2];
    
    if (argc == 5)
    {
        if (access(argv[1], R_OK) == -1)
            ft_error(argv[1], ": No such file or directory");
        pipe (fd);
        id1 = fork();
        if (!id1)
        {
            first_child(env, argv, fd); 
            ft_error ("command not found : ", argv[2]);
        }
        id2 = fork();
        if(!id2)
        {
            second_chiled(env, argv, fd);
            ft_error ("command not found : ", argv[3]);
        }
        ft_exit(fd, id1, id2);
    }
}

