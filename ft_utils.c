/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamohamm <yasnaadli21@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:37:57 by yamohamm          #+#    #+#             */
/*   Updated: 2025/06/18 10:32:54 by yamohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] == s2[i]) && (s1[i] != '\0') && (i < n - 1))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

// static void	check_overflow(long digit, long result, long sign)
// {
// 	if (sign == -1 && result > (2147483648 - digit) / 10)
// 		exit(EXIT_FAILURE);
// 	else if (sign == 1 && result > (2147483647 - digit) / 10)
// 		exit(EXIT_FAILURE);
// }

// static int	parse_sign_and_skip_spaces(char **s)
// {
// 	int	sign;

// 	sign = 1;
// 	while ((**s >= 9 && **s <= 13) || **s == 32)
// 		(*s)++;
// 	if (**s == '+' || **s == '-')
// 		if (*((*s)++) == '-')
// 			sign = -1;
// 	return (sign);
// }

// double	ft_atodbl(char *s)
// {
// 	long	integer_part;
// 	double	fractional_part;
// 	double	pow;
// 	int		sign;

// 	integer_part = 0;
// 	fractional_part = 0;
// 	pow = 1;
// 	sign = parse_sign_and_skip_spaces(&s);
// 	while (*s != '.' && *s)
// 	{
// 		check_overflow(*s - 48, integer_part, sign);
// 		integer_part = (integer_part * 10) + (*s++ - 48);
// 	}
// 	if ('.' == *s)
// 		++s;
// 	while (*s && (*s >= '0' && *s <= '9'))
// 	{
// 		pow /= 10;
// 		fractional_part = fractional_part + (*s++ - 48) * pow;
// 	}
// 	return ((integer_part + fractional_part) * sign);
// }
