/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 21:55:09 by bpace             #+#    #+#             */
/*   Updated: 2019/09/25 01:25:44 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

char		**checkerinit(int *fd, int argv, char ***argc)
{
	char	**ans;

	if (argv == 2)
		*argc = ft_strsplit((*argc)[0], ' ');
	fd[0] = open((*argc)[0], O_RDWR);
	if (fd[0] == -1)
	{
		fd[0] = 0;
		fd[1] = 1;
		ans = *argc;
	}
	else
	{
		fd[1] = fd[0];
		ans = (*argc) + 1;
	}
	return (ans);
}

int			checkerparse(t_stack **begin, int *iv, int *fd)
{
	if (!(parser(begin, iv[1], fd)))
	{
		write(fd[1], "Error\n", 6);
		close(fd[0]);
		return (0);
	}
	if (checkbegin(*begin, iv[0]))
		write(fd[1], "OK\n", 3);
	else
		write(fd[1], "KO\n", 3);
	freestack(begin);
	close(fd[0]);
	return (1);
}

void		freeargc(int argv, char **argc)
{
	int		i;

	if (argv == 2)
	{
		i = -1;
		while (argc[++i])
			ft_strdel(&argc[i]);
		free(argc);
	}
}

int			checker(int argv, char **argc)
{
	t_stack		*begin;
	int			iv[2];
	int			fd[2];
	char		**argctemp;

	begin = NULL;
	iv[1] = 0;
	argctemp = checkerinit(fd, argv, &argc);
	if (!(ft_strcmp(argctemp[0], "-v")))
		iv[1]++;
	if (!(iv[0] = makestack(argctemp, &begin, iv[1])))
	{
		freestack(&begin);
		freeargc(argv, argc);
		write(fd[1], "Error\n", 6);
		close(fd[0]);
		return (0);
	}
	freeargc(argv, argc);
	return (checkerparse(&begin, iv, fd));
}

int			main(int argv, char **argc)
{
	if (argv > 1)
		checker(argv, argc + 1);
	return (0);
}
