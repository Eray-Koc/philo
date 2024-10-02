/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erkoc <erkoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:29:07 by erkoc             #+#    #+#             */
/*   Updated: 2024/09/28 15:26:48 by erkoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h" // bi işe yaramıcak galiba

int	count_num(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	else if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(long long n)
{
	char	*str;
	int		length;

	if (n == 0)
		return (ft_strdup("0"));
	length = count_num(n);
	str = malloc(sizeof(char) * length + 1);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	str[length--] = '\0';
	while (n > 0)
	{
		str[length] = '0' + (n % 10);
		n /= 10;
		length--;
	}
	return (str);
}