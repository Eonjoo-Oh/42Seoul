/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:52:36 by eoh               #+#    #+#             */
/*   Updated: 2023/02/27 14:18:48 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>

typedef struct t_list
{
    int content;
    struct t_list *prev;
    struct t_list *next;
} t_list;
/*
typedef struct s_stack
{

}
*/
void push_swap(int argc, char **argv);
t_list *first_stack(char **argv);
void lstadd_back(t_list **lst, t_list *new_node);
t_list *make_lst(int data);
int check_range(long long n);
long long long_atoi(char *nptr);
int is_digit_sp(char *str);
char **ft_split(char const *s);

#endif