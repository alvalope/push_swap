/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:50:02 by alvalope          #+#    #+#             */
/*   Updated: 2023/04/18 19:20:03 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	int	isdigit;

	if (c < '0' || c > '9')
		isdigit = 0;
	else
		isdigit = 1;
	return (isdigit);
}
