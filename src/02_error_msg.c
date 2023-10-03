/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_error_msg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <lagonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:08:03 by lagonzal          #+#    #+#             */
/*   Updated: 2023/10/03 16:09:07 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	ft_putstr_fd(char *s, int fd);
static int	ft_strlen(char *s);

void	ft_error_msg(char *error_msg)
{
	ft_putstr_fd("Error. Invalid ", 2);
	ft_putstr_fd(error_msg, 2);
	ft_putstr_fd("\n", 2);
}

static void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

static int	ft_strlen(char *s)
{
	int	n;

	n = 0;
	while (s && s[n])
		n++;
	return (n);
}
