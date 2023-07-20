/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_create_philos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larra <larra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:23:47 by larra             #+#    #+#             */
/*   Updated: 2023/07/20 14:10:41 by larra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void	philo_init(struct s_philo *philo, t_all *all, int n);

int	create_philos(t_all *all)
{
	int	n;

	n = 0;
	all->philos = malloc((all->param.philo_num) * sizeof(t_philo));
	if (!all->philos)
		return (1);
	while (n < all->param.philo_num)
	{
		philo_init(&all->philos[n], all, n);
		n++;
	}
	all->forks = malloc(all->param.philo_num * sizeof(pthread_mutex_t));
	if (!all->forks)
		return (ft_free(all));
	return (0);
}

void	philo_init(struct s_philo *philo, t_all *all, int n)
{
	philo->last_meal = 0;
	philo->meal_count = 0;
	philo->pos = n + 1;
	philo->param = &all->param;
	if (n == 0)
	{
		philo->left = &all->philos[all->param.philo_num - 1];
		philo->right =  &all->philos[n + 1];
	}
	else if (n == all->param.philo_num - 1)
	{	
		philo->left = &all->philos[n - 1];
		philo->right =  &all->philos[0];
	}
	else
	{
		philo->left = &all->philos[n - 1];
		philo->right =  &all->philos[n + 1];
	}
}

int	ft_free(t_all *all)
{
	if (all->philos)
		free(all->philos);
	if (all->forks)
		free(all->forks);
	if (all->threads)
		free (all->threads);
	return (1);
}