/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_error_msg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <lagonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:08:03 by lagonzal          #+#    #+#             */
/*   Updated: 2023/10/03 19:25:30 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	ft_putstr_fd(char *s, int fd);
static int	ft_strlen(char *s);

/*
Throws a message to the STD_ERR fd.
ARGS:
	- error_msg: The type of error in a string.
RETURN VALUES:
	void
*/

void	ft_error_msg(char *error_msg)
{
	ft_putstr_fd("Error. Invalid ", 2);
	ft_putstr_fd(error_msg, 2);
	ft_putstr_fd("\n", 2);
}

/*
Writes an string to the indicated fd.
ARGS:
	- s: the string to be written.
	- fd: fd where it will be written.
RETURN VALUES
	void.
*/

static void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

/*
Measures the length of a string
ARGS:
	- s: the string to be measuared
RETURN VALUES
	An integer, the size of the string.
*/

static int	ft_strlen(char *s)
{
	int	n;

	n = 0;
	while (s && s[n])
		n++;
	return (n);
}
