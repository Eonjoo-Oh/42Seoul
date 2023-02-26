#include "push_swap.h"

int is_digit_sp(char *str);
int check_range(long long n);
long long long_atoi(char *nptr);
t_list *make_lst(void);
t_list *lstadd_back(t_list *lst, int data);
char **ft_split(char const *s);

typedef struct t_list
{
    int content;
    struct t_list *prev;
    struct t_list *next;
} t_list;

t_list *first_stack(char **argv)
{
    int i;
    int j;
    char **splited;
    long long atoied;
    t_list *first_stack;

    i = 1;
    first_stack = (make_lst());
    while (argv[i])
    {
        if (is_digit_sp(argv[i]) == -1)
            return (0);
        splited = ft_split(argv[i]);
        while (splited[i])
        {
            j = 0;
            atoied = long_atoi(splited[i]);
            if (check_range(atoied == -1))
                return (0);
            atoied = (int)atoied;
            lstadd_back(&first_stack, atoied);
            j++;
        }
        i++;
    }
    return (first_stack);
}