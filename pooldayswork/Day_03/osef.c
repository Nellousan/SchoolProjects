#include <stdio.h>
#include <stdlib.h>

void my_putchar(char c);

int my_pow(int a, int turns)
{
    printf("turn:%d\n", turns);
    if (turns == 0)
    {
        return 1;
    }
        return (a * my_pow(a, --turns));
}

int main(void)
{
    int a = 50;
    a = 2 * my_pow(a, 3);
    printf("%d", a);
}
