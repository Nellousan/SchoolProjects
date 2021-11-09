/*
** EPITECH PROJECT, 2019
** my_strstr
** File description:
** search string in other string
*/

int my_strlen(char const *str);

int *my_strstr(char *str, char const *to_find)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == to_find[0])
            for (int j = 0; str[i+j] == to_find[j];) {
                j++;
                if (to_find[j] == '\0')
                    return str + i;
            }
    }

}
