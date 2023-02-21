#include <stdio.h>
#include <stdlib.h>

char	**ft_split(char const *s);
int **ft_atoi(char **s);
char *ft_strjoin(char **argv, int argc);

int main(int argc, char **argv)
{
    char *join_result;
    char **result;
    char *print;
    int **int_result;
    int int_print;

    printf("--------------- join_test ---------------\n");
    
    join_result = ft_strjoin(argv, argc);
    printf("%s\n", join_result);

    printf("--------------- split_test ---------------\n");

    result = ft_split(join_result);
    for(int i = 0; i < 7; i++)
    {
        print = result[i];
        printf("%d번째 :  %s\n", i, print);
    }
    printf("--------------- atoi_test ---------------\n");
    int_result = ft_atoi(result);
    for(int i = 0; i < 7; i++)
    {
        int_print = int_result[i][0];
        printf("%d번째 :  %d\n", i, int_print);
    }
    system("leaks a.out");
    return (0);
}