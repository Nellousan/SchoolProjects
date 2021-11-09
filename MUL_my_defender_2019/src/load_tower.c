/*
** EPITECH PROJECT, 2020
** tower_data
** File description:
** 
*/

#include <stdlib.h>
#include "my.h"
#include "defender.h"
#include "a_malloc.h"

tower_t **tower_load(void)
{
    tower_t **tower_d;
    char *file = file_load("data/towers");
    int occ = get_occurences(file, '\n');
    int i = 0;
    tower_d = a_malloc(sizeof(tower_t *) * (occ + 1) | A_LIST(1));
    for (i = 0; i < occ; i++) {
        tower_d[i] = a_malloc(sizeof(tower_t) | A_LIST(1));
        tower_d[i]->id = char_to_int(copy_until(&file, ';'));
        tower_d[i]->sprsh = my_astrdup(copy_until(&file, ';'), 1);
        tower_d[i]->range = char_to_int(copy_until(&file, ';'));
        tower_d[i]->damage = char_to_int(copy_until(&file, ';'));
        tower_d[i]->price = char_to_int(copy_until(&file, ';'));
        tower_d[i]->evolve_id = char_to_int(copy_until(&file, ';'));
        file++;
    }
    tower_d[i] = NULL;
    return tower_d;
}
