/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:19:51 by ismherna          #+#    #+#             */
/*   Updated: 2024/01/16 19:20:10 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <libft.h>

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		sign;

	sign = (n < 0) ? -1 : 1;
	len = 1;
	while (n / 10)
	{
		len++;
		n /= 10;
	}
	str = (char *)malloc(sizeof(char) * (len + 1 + (sign == -1)));
	if (!str)
		return (NULL);
	str[len + (sign == -1)] = '\0';
	while (len--)
	{
		str[len + (sign == -1)] = (n % 10) * sign + '0';
		n /= 10;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}