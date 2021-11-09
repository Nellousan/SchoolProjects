char *my_strcat(char *dest, char const *src);
int my_putstr(char const *str);
char *my_strncat(char *dest, char const *src , int n);

int main(void)
{

    char dest[50] = "Hello";
    my_putstr(my_strncat(dest, "World", 3));
}
