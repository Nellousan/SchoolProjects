/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** prototype header of libmy
*/

void my_putchar(char c);
int my_putnbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_pow(int nb, int power);
int my_sqrt(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
int my_showstr(char const *str);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);

char **my_str_to_word_array(char const *str);
int how_many_words(char const *str);
char word_cut(char const *str, int nb);
int is_alphanum(char c);

char *my_strdup(char const *str);
int my_show_word_array(char * const *tab);
int my_malloc(int type_size, int amount, int p);
