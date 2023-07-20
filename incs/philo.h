/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larra <larra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:07:21 by larra             #+#    #+#             */
/*   Updated: 2023/07/19 21:22:41 by larra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <sys/time.h>

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
	t_philo			*left;
	t_philo			*right;
	unsigned int	last_meal;
	int				meal_count;
	int				pos;
	t_param			*param;
}	t_philo

typedef struct s_all
{
	struct s_param *param;
}   t_all;

int check_args(int argc, char **argv, t_param *param);