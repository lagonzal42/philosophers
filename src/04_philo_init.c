/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_philo_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larra <larra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:23:02 by larra             #+#    #+#             */
/*   Updated: 2023/08/10 18:57:25 by larra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void	action(void *arg);

int	thread_creation(t_all *all)
{
	int             n;
	struct timeval  now;

	n = 0;
	all->threads = malloc(all->param.philo_num * sizeof(pthread_t));
	while (n < all->param.philo_num)
	{
		if (pthread_create(&all->threads[n], NULL,
			(void *)action, &all->philos[n]))
			return (1);
		if (pthread_mutex_init(&all->forks[n], NULL))
			return (1);
		n++;
	}
	gettimeofday(&now, NULL);
	all->go = now.tv_sec * 1000 + now.tv_usec / 1000;
	all->dead = 0;
	/*while (!dead_check(all))
		;
	*/
	return (0);
}

void    action(void *arg)
{
	t_philo	*philo;

	philo = ((t_philo *) arg);
	while (philo->all->dead == 0 && (philo->param->eatend != philo->meal || philo->param->eatend == -1))
	{
		
	}

}