/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:36:19 by vlow              #+#    #+#             */
/*   Updated: 2024/11/09 22:36:29 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isupper(int c);
static int	ft_islower(int c);

/// @brief Check if character is an alphabetic letter
/// 
/// This function checks whether the given 
/// character `c` is either an uppercase
/// or lowercase alphabetic character.
/// 
/// @param c The character to be checked
/// @return 1 if `c` is an alphabetic letter, 0 otherwise
int	ft_isalpha(int c)
{
	if (ft_isupper(c) || ft_islower(c))
		return (1);
	return (0);
}

static int	ft_isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

static int	ft_islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}
