/*
** EPITECH PROJECT, 2020
** CPE_duostumper_2019
** File description:
** fractals
*/

#include "unistd.h"
#include "my.h"

void my_putstr_error(char *str)
{
    write(2, str, my_strlen(str));
}
