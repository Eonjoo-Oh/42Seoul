/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:53:48 by eoh               #+#    #+#             */
/*   Updated: 2023/02/25 17:51:29 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int **ft_atoi(char **s);
char	**ft_split(char const *s);
char *ft_strjoin(char **argv, int argc);

void push_swap(int argc, char **argv)
{
    int **int_av;
    int int_print;
    char *new_argv;

    if (check_error(argv) == -1)
        return ;
    new_argv = ft_strjoin(argv, argc);
    argv = (ft_split(new_argv));
    int_av = ft_atoi(argv);
    stack_a = ft_lstnew(int_av);
    
    system("leaks a.out");
}