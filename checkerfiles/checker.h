/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 22:06:31 by bpace             #+#    #+#             */
/*   Updated: 2019/09/25 19:21:16 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct		s_stack
{
	int				i;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

void				r(t_stack **begin);
void				s(t_stack **begin);
void				rr(t_stack **begin);
void				freestack(t_stack **begin);
int					checkbegin(t_stack *begin, int i);
void				p(t_stack **stack1, t_stack **stack2);
int					parser(t_stack **begin, int v, int *fd);
int					makestack(char **argc, t_stack **begin, int v);
void				printstack(t_stack *stacka, t_stack *stackb);

#endif
