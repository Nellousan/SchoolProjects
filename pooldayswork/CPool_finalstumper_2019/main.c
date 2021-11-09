/*
** EPITECH PROJECT, 2019
** main finalstumper
** File description:
** 
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "my.h"

char sec_corn(char *buffer);
char frth_corn(char *buffer);
int print_rush_one(char *buffer);
int print_rush_two(char *buffer);
int print_rush_three(char *buffer);
int print_rush_four(char *buffer);
int print_rush_five(char *buffer);
int print_rush_three_four_five(char *buffer);

int first_len(char *buffer)
{
    int i = 0;
    for (i; buffer[i] != '\n'; i++);
    return i;
}

int count_ret(char *buffer)
{
    int j = 0;
    for (int i = 0; buffer[i] != '\0'; i++)
        if (buffer[i] == '\n')
            j++;
    return j;
}

int reco_type(char *str)
{
    if (str[0] == 'o')
        print_rush_one(str);
    else if (str[0] == '/' || str[0] == '*')
        print_rush_two(str);
    else if (str[0] == 'B')
        print_rush_three_four_five(str);
    else if (str[0] == 'A' && sec_corn(str) == 'A' && frth_corn(str) == 'C')
        print_rush_three(str);
    else if (str[0] == 'A' && sec_corn(str) == 'C' && frth_corn(str) == 'C')
        print_rush_four(str);
    else if (str[0] == 'A' && sec_corn(str) == 'C' && frth_corn(str) == 'A')
        print_rush_five(str);
    return 0;
}

int main(int argc, char **argv)
{
    char buffer[2048];
    int size = read(0, buffer, 2048);
    if (!my_strcmp(buffer, "Invalid size\n")) {
        write(2, "Invalid size\n", my_strlen("Invalid size\n"));
        return 84;
    }
    reco_type(buffer);
    return 0;
}
