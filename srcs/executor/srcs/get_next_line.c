/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 14:56:41 by sahafid           #+#    #+#             */
/*   Updated: 2022/08/21 15:04:45 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../executor.h"

char    *get_next_line1(int fd)
{
    static char    *buffer_reminder; // hada rah mohim wakha makhdmnahch walakin rah khass ikon chi static variable
    char        buff[1];
    char        line[1000000];
    int            i;
    int            n;

    buffer_reminder = 0;
    if (fd < 0)
        return (NULL);
    line[0] = 0;
    i = 0;
    while ((n = read(fd, buff, 1)) && n > 0)
    {
        line[i++] = buff[0];
        line[i] = '\0';
        if (!buff[0])
            return (ft_strdup(line));
    }
    if (!line[0])
        return (NULL);
    return (ft_strdup(line));
}