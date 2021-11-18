/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 01:28:56 by oal-tena          #+#    #+#             */
/*   Updated: 2021/11/17 15:55:36 by oal-tena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/fdf.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_t(int trgb)
{
	return (trgb & (0XFF << 24));
}

int	get_r(int trgb)
{
	return (trgb & (0XFF << 16));
}

int	get_g(int trgb)
{
	return (trgb & (0XFF << 8));
}

int	get_b(int trgb)
{
	return (trgb & 0XFF);
}
