/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:50:58 by aankote           #+#    #+#             */
/*   Updated: 2023/02/11 11:38:19 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define  PIPEX_H
# include <stdio.h>
# include <fcntl.h>

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

void ft_free_dub(char **p);
char *ft_join_free(char *res, char *p);
void ft_error(char *s1, char *s2);
# endif