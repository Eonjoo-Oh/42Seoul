#include <stdio.h>

int is_digit_sp(char *str);

int main(int argc, char **argv)
{
    int i;

    i = 0;
    if (argc == 1)
        return (0);
    while (argv[i] != 0)
    {
        if (is_digit_sp(argv[i]) == -1)
        {
            printf("%s is not digit or white space\n", argv[i]);
        }
        else
            printf("%s is digit or white space\n", argv[i]);
        i++;
    }
    return (0);
}

/*
int main(void)
{
    char *str1 = "123 45";
    char *str2 = "123   ";
    char *str3 = "123ab";

    printf("%d\n", is_digit_sp(str1));
    printf("%d\n", is_digit_sp(str2));
    printf("%d\n", is_digit_sp(str3));

    return (0);   
}
*/