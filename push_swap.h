/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonjoo <eonjoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:52:36 by eoh               #+#    #+#             */
/*   Updated: 2023/02/26 18:56:57 by eonjoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>

typedef struct t_list
{
    int content;
    struct t_list *prev;
    struct t_list *next;
} t_list;

void new_push_swap(int argc, char **argv);
t_list *first_stack(char **argv);
void lstadd_back(t_list **lst, int data);
t_list *make_lst(void);
int check_range(long long n);
long long long_atoi(char *nptr);
int is_digit_sp(char *str);
char **ft_split(char const *s);