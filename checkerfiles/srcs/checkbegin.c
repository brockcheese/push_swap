/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkbegin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:15:37 by bpace             #+#    #+#             */
/*   Updated: 2019/09/16 00:52:29 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int		checkbegin(t_stack *begin, int i)
{
	t_stack		*temp;
	int			count;

	count = 1;
	temp = begin;
	temp->prev->next = NULL;
	while (temp->next)
	{
		if (temp->next->i < temp->i)
		{
			begin->prev->next = begin;
			return (0);
		}
		count++;
		temp = temp->next;
	}
	count = (count == i) ? 1 : 0;
	begin->prev->next = begin;
	return (count);
}
