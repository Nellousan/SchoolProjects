/*
** EPITECH PROJECT, 2020
** miscellaneous
** File description:
** functions 
*/

#include <SFML/Graphics.h>
#include "defender.h"
#include "my.h"

button_t button_init(sfIntRect rect, void (*fptr)(game_t *game))
{
    button_t button;
    button.rect = rect;
    button.fptr = fptr;
    return button;
}
