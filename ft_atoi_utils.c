/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamohamm <yasnaadli21@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:48:46 by yamohamm          #+#    #+#             */
/*   Updated: 2025/06/18 10:29:52 by yamohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	check_overflow(long digit, long result, long sign)
{
	if (sign == -1 && result > (2147483648 - digit) / 10)
		exit(EXIT_FAILURE);
	else if (sign == 1 && result > (2147483647 - digit) / 10)
		exit(EXIT_FAILURE);
}

static int	parse_sign_and_skip_spaces(char **s)
{
	int	sign;

	sign = 1;
	while ((**s >= 9 && **s <= 13) || **s == 32)
		(*s)++;
	if (**s == '+' || **s == '-')
		if (*((*s)++) == '-')
			sign = -1;
	return (sign);
}

double	ft_atodbl(char *s)
{
	long	integer_part;
	double	fractional_part;
	double	pow;
	int		sign;

	integer_part = 0;
	fractional_part = 0;
	pow = 1;
	sign = parse_sign_and_skip_spaces(&s);
	while (*s != '.' && *s)
	{
		check_overflow(*s - 48, integer_part, sign);
		integer_part = (integer_part * 10) + (*s++ - 48);
	}
	if ('.' == *s)
		++s;
	while (*s && (*s >= '0' && *s <= '9'))
	{
		pow /= 10;
		fractional_part = fractional_part + (*s++ - 48) * pow;
	}
	return ((integer_part + fractional_part) * sign);
}

int	ft_atoi(const char *str)
{
	char	*s;
	long	result;
	long	sign;
	long	digit;

	s = (char *)str;
	result = 0;
	sign = parse_sign_and_skip_spaces(&s);
	while (*s >= '0' && *s <= '9')
	{
		digit = *s - '0';
		check_overflow(digit, result, sign);
		result = result * 10 + digit;
		s++;
	}
	return (result * sign);
}
