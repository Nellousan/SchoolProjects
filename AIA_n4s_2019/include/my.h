/*
** EPITECH PROJECT, 2019
** my
** File description:
** Day09 task02
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int my_getnbr(char const *str);
int my_isneg(int nb);
int my_is_prime(int nb);
void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
char *my_revstr(char *str);
int my_showmem(char const *str, int size);
int my_showstr(char const *str);
int my_sort_int_array(int *tab, int size);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int n);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);
void my_put_nbr_pos(int nb);
int strlenmy(char const *dest);
char *my_strdup(char const *dest);
int sum_stdarg(int i, int nb , ...);
int disp_stdarg(char *s, ...);
int my_printf(char *s, ...);
int my_put_long_long(long long int nb);
void my_put_long_long_pos(long long int nb);
int disp_long(char *s, int i, va_list ap);
char *my_int_to_str(int nb);
int my_putnbr_base(int nbr, char *base);
char *my_itoa(int nb, char *str);
int my_atoi(char const *str);
char **my_str_to_array(char *str);
