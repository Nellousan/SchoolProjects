/*
** EPITECH PROJECT, 2019
** my_str_to_word_array
** File description:
** fhzeufhz
*/

#include <stdlib.h>
#include <stddef.h>

int my_strlen(char *str);
int *my_strcpy(char *dest, char const *src);

int is_alpha(char c)
{
    if (c >= 'A' && c <= 'Z')
        return 1;
    else if (c >= 'a' && c <= 'z')
        return 1;
    else if (c >= '0' && c <= '9')
        return 1;
    return 0;
}

char *word_cut(char const *str, int nb)
{
    char *buffer = malloc(sizeof(char) * (my_strlen(str) + 1));
    int trigger = 0;
    size_t j = 0;
    for (size_t i = 0; str[i] != '\0'; i++) {
        if (nb == 1 && trigger == 0 && is_alpha(str[i]) == 1) {
            for (; is_alpha(str[i]) == 1; i++) {
                buffer[j] = str[i];
                j++;
            }
            buffer[j + 1] = '\0';
            return buffer;
        }
        if (trigger == 0 && is_alpha(str[i]) == 1) {
            trigger = 1;
            nb--;
        } else if (trigger == 1 && is_alpha(str[i]) == 0)
            trigger = 0;
    }
}

int how_many_words(char const *str)
{
    int words = 0;
    int trigger = 0;
    for (size_t i = 0; str[i] != '\0'; i++) {
        if (trigger == 0 && is_alpha(str[i]) == 1) {
            trigger = 1;
            words++;
        }
        if (trigger == 1 && is_alpha(str[i]) == 0)
            trigger = 0;
    }
    return words;
}

char **my_str_to_word_array(char const *str)
{
    size_t i = 0;
    char **tab = malloc(sizeof(char *) * (how_many_words(str) + 1));
    for (i = 0; i < how_many_words(str); i++) {
        tab[i] = malloc(sizeof(char) * (my_strlen(word_cut(str, i + 1))) + 1);
        my_strcpy(tab[i], word_cut(str, i + 1));
    }
    tab[i + 1] = NULL;
    return tab;
}
