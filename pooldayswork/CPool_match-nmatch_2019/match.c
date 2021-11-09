/*
** EPITECH PROJECT, 2019
** match
** File description:
** check if strings matches
*/

char *star(char *s1, char *s2)
{
    int i = 0;
    for (i = 0; s1[i] != s2[1]; i++) {
        if (s1[i] == '\0' && s2[1] != '\0')
            return s1 + i;        
    }
    my_putstr(s1 + i);
    return s1 + i;
}

int match(char const *s1, char const *s2)
{
    int j = 0;
    for (int i = 0; s1[i] != '\0'; i++) {
        if (s2[i] == '*') {
            for (j = i; s2[j] != '\0' || s2[j] != '*'; j++)
            
                }
        if (s1[i] != s2[i])
            return 0;
    }
    return 1;
}
