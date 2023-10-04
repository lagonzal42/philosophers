/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_watcher_routine.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larra <larra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:37:03 by larra             #+#    #+#             */
/*   Updated: 2023/10/04 12:38:16 by larra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void    watcher_routine(void *watcher_info)
{
    t_watcher   *watcher;

    watcher = (t_watcher *)watcher_info;
    watcher->start = 1;
    while (1)
    {
        if (check_end(watcher))
            return (0);
    }
}