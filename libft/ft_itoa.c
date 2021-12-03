/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 12:07:40 by msanjuan          #+#    #+#             */
/*   Updated: 2021/06/26 12:17:35 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int long	ft_howmanydigits(int long number)
{
	int long	i;

	i = 0;
	if (number <= 0)
		i++;
	while (number)
	{
		number = number / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*converted_string;
	int long	i;
	int long	length;
	int long	nb;

	nb = (int long)n;
	length = ft_howmanydigits(nb);
	converted_string = (char *)malloc(sizeof(char) * (length + 1));
	if (!converted_string)
		return (NULL);
	i = 0;
	converted_string[length] = '\0';
	if (nb < 0)
	{
		nb = -nb;
		converted_string[i] = '-';
		i++;
	}
	while (i < length)
	{
		converted_string[--length] = (nb % 10) + 48;
		nb = nb / 10;
	}
	return (converted_string);
}
