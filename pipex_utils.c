/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:30:47 by aankote           #+#    #+#             */
/*   Updated: 2023/02/10 09:34:15 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void ft_free_dub(char **p)
{
    int i;

    i = -1;
    if (p)
    {
        while (p[++i])
            free(p[i]);
        free (p);
    }
}

char *ft_join_free(char *res, char *p)
{
    char *temp;

    temp = ft_strjoin(res, p);
    free (res);
    return (temp);
}

void ft_error(char *s)
{
    ft_putendl_fd(s, 1);
    exit (0);
}