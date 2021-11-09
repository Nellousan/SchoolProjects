/*
** EPITECH PROJECT, 2020
** mob loading
** File description:
** a
*/

#include <stdlib.h>
#include "my.h"
#include "defender.h"
#include "a_malloc.h"

mob_d_t **mob_load(void)
{
    char *file = file_load("data/mob_data");
    int occ = get_occurences(file, '\n');
    mob_d_t **mob_d = a_malloc(sizeof(mob_d_t *) * (occ + 1) | A_LIST(1));
    int i = 0;
    for (i = 0; i < occ; i++) {
        mob_d[i] = a_malloc(sizeof(mob_d_t) | A_LIST(1));
        mob_d[i]->id = char_to_int(copy_until(&file, ';'));
        mob_d[i]->sprsh = my_astrdup(copy_until(&file, ';'), 1);
        mob_d[i]->type = char_to_int(copy_until(&file, ';'));
        mob_d[i]->hp = char_to_int(copy_until(&file, ';'));
        mob_d[i]->damage = char_to_int(copy_until(&file, ';'));
    }
    mob_d[i] = NULL;
    return mob_d;
}
