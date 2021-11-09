/*
** EPITECH PROJECT, 2019
** count letter
** File description:
** explicit name
*/

int my_char_isalpha(char c);

int count_letters(char const *str)
{
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++)
        if (my_char_isalpha(str[i]))
            j++;
    return j;
}
