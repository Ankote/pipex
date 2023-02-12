/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:30:47 by aankote           #+#    #+#             */
/*   Updated: 2023/02/12 17:53:46 by aankote          ###   ########.fr       */
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

void ft_error(char *s1, char *s2)
{
    if (s1)
        ft_putstr_fd(s1, 2);
    if (s2)
        ft_putendl_fd(s2, 2);
    exit (0);
}