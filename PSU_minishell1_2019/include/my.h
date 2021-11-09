/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** libmy prototype header
*/

#ifndef MY_H
#define MY_H

void my_putchar(char c);
int my_putnbr(int nb);
int my_putllnbr(long long nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_pow(int nb, int power);
int my_sqrt(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
int my_showstr(char const *str);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);

char **my_str_to_array(char *str);
int my_array_size(char **array);

char *my_strdup(char const *str);
char *my_astrdup(char const *str, int list);
char *my_revstrdup(char const *str);
int my_show_word_array(char * const *tab);

int my_sort_word_array(char **tab);
char **my_arraydup(char * const *tab);
int my_arraylen(char const **tab);

int my_add(int a, int b);
int my_sub(int a, int b);
int my_div(int a, int b);
int my_mul(int a, int b);
int my_mod(int a, int b);

int my_printf(char *str, ...);

char *my_convert_base(char *nb, char *nb_base, char *res_base);
char *my_int_to_char(int nb);
char *my_llint_to_char(long long nb);

/******** printf funcs, don't use ********/

typedef struct printf_flag_struct
{
    char c;
    void (*fptr)();
} flag_t;

int alternate_print(char *str);
int long_flag_check_redirect(char *str, long long nb);
int is_int_flag(char c);

void printf_flag_cc(long long nb);
void printf_flag_o(long long nb);
void printf_flag_u(long long nb);
void printf_flag_x(long long nb);
void printf_flag_cx(long long nb);
void printf_flag_b(long long nb);
void printf_flag_d(long long nb);
void printf_flag_cs(char *str);
void printf_flag_p(long long nb);

/*****************************************/

#endif
