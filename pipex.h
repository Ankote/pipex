/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:50:58 by aankote           #+#    #+#             */
/*   Updated: 2023/02/15 11:03:28 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include "unistd.h"

void	ft_free_dub(char **p);
char	*ft_join_free(char *res, char *p);
void	ft_error(char *s1, char *s2);
void	ft_exit(int fd[2], int id1, int id2, char **p);
char	**get_paths(char **env);
#endif