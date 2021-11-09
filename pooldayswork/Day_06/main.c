#include <string.h>

int my_putnbr(int nb);
int my_putstr(char *str);
void my_putchar(char c);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);

int main(void)
{
//    int nb = 0;
//    nb = my_strncmp("fallo", "Hello", 3);
//    my_putnbr(nb);
//    my_putchar('\n');
    char str[] = "HELLO hello";

    my_putstr(my_strcapitalize(str));
}
