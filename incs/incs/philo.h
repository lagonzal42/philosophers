/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larra <larra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:07:21 by larra             #+#    #+#             */
/*   Updated: 2023/07/20 14:10:45 by larra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_param
{
	int	philo_num;
	int	t_to_die;
	int	t_to_slp;
	int	t_to_eat;
	int	eat_end;
}	t_param;

typedef struct s_philo
{
	struct s_philo	*left;
	struct s_philo	*right;
	unsigned int	last_meal;
	int				meal_count;
	int				pos;
	t_param			*param;
}	t_philo;

typedef struct s_all
{
	struct s_param	param;
	t_philo			*philos;
	pthread_t		*threads;
	pthread_mutex_t	*forks;
}   t_all;

int check_args(int argc, char **argv, struct s_param *param);
int	create_philos(t_all *all);
int ft_error(int ecode);
int		ft_free(t_all *all);

#endif