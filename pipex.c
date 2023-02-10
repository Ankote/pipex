/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:49:59 by aankote           #+#    #+#             */
/*   Updated: 2023/02/10 18:14:39 by aankote          ###   ########.fr       */
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
        if (!access(command, X_OK))
            return (ft_free_dub(paths), command);
    }
    ft_free_dub(paths);
    return (NULL);
}

int do_cmd_parent(char **env,char **av,int intcmd)
{
    char **argVes;
    char *cm;
    char **path;
    char *cmd;
    int vl;
    int i;
    
    i = 0;
    argVes = ft_split(av[intcmd], ' ');
    cm = ft_strjoin("/", argVes[0]);
    path = get_paths(env);
    while (path[i])
    {
        cmd = ft_strjoin(path[i],cm);
        vl = execve(cmd, argVes, path);
        i ++;
    }
    if (vl == -1)
    {
        perror(av[intcmd]);
        ft_free_dub(path);
        return (ft_free_dub(argVes), free(cm), free(cmd), 0);
    }
    return (1);
}

// int do_cmd_child(char **env,char **av,int cmda)
// {
//     char **argVes;
//     char *cm;
//     char **path;
//     char *cmd;
//     int vl;
//     int i;
    
//     i = 0;
//     argVes = ft_split(av[cmda], ' ');
//     cm = ft_strjoin("/", argVes[0]);
//     path = get_paths(env);
//     while (path[i])
//     {
//         cmd = ft_strjoin(path[i],cm);
//         vl = execve(cmd, argVes, path);
//         i ++;
//     }
//     if (vl == -1)
//     {
//         perror(av[cmda]);
//         ft_free_dub(path);
//         return (ft_free_dub(argVes), free(cm), free(cmd), 0);
//     }
//     return (1);
// }

// int do_cmd_child(int fd)
// {
//     char *p;
//     char *res;
//     res = ft_calloc(1, 1);
//     while(1)
//     {
//         p = get_next_line(fd);
//         if (!p)
//             break ;
//         res = ft_join_free(res, p);
//         free(p);
//     }
//     free (p);
//     printf("%s\n", res);
//     return (0);
// }

int main(int argc, char **argv, char **env)
{   
    int fd_in;
    int fd_out;
    int id;
    int vl;
    int fd[2];
    
    vl = 0;
    id = fork();
    pipe (fd);
    if (id)
    {
        fd_out = open (argv[argc - 1],O_CREAT | O_TRUNC | O_RDWR , 0777);
        fd_in = open (argv[1], O_RDWR);
        dup2(fd[0], 0);
        dup2(fd[1], 1);
        if (access(argv[1], R_OK) == -1)
            ft_error("ERROR!\nCan't open file");
        vl = do_cmd_parent(env, argv, 2);
        close(fd_in);
        close (fd_out);
    }
    else if (argc > 4){
            
            fd_out = open (argv[argc - 1],O_CREAT | O_TRUNC | O_RDWR , 0777);
            fd_in = open (argv[1], O_RDWR);
            dup2(fd[0], 0);
            dup2(fd[0], fd_in);
            dup2(fd[1], 1);
            dup2(fd[1], fd_out);
            do_cmd_parent(env, argv, argc - 2);
            close(fd_in);
            close (fd_out);
    }
}
