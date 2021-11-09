/*
** EPITECH PROJECT, 2019
** emacs
** File description:
** my.h
*/

#ifndef MY_H
#define MY_H

#include "../new.h"
#include <stdbool.h>

int isop(char ch, char **argv);
void push(stack_t **head, char x);
bool is_empty(stack_t *head);
char peek(stack_t *head);
char pop(stack_t **head);
int priority(char ch, char **argv);
void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char *my_revstrdup(char *str);
int my_pow(int nb, int p);
char *my_strdup(char *str);

#endif
