/*
** EPITECH PROJECT, 2020
** GNL
** File description:
** 
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "my.h"

int gnl_cat(char *buffer, char *read, int *index)
{
    int blen = my_strlen(buffer);
    int i = 0;
    if (read[(*index)] == '\0') {
        (*index) = 0;
        return 0;
    }
    for (; read[(*index) + i] != '\0'; i++) {
        if (read[(*index) + i] == '\n') {
            buffer[blen + i] = '\0';
            (*index) += i + 1;
            (*index) = ((*index) == READ_SIZE) ? 0 : (*index);
            return 0;
        }
        buffer[blen + i] = read[(*index) + i];
    }
    buffer[blen + i] = '\0';
    (*index) = 0;
    free(read);
    return 1;
}

char *read_n(int fd, int *size)
{
    char *buffer = malloc(sizeof(char) * (READ_SIZE + 1));
    if (buffer == NULL)
        return NULL;
    (*size) = read(fd, buffer, READ_SIZE);
    if ((*size) == 0 || (*size) == -1)
        return NULL;
    buffer[(*size)] = '\0';
    return buffer;
}

char *get_next_line(int fd)
{
    static int index = 0;
    static char *read;
    static int endfile = 0;
    static int size;
    char *buffer = malloc(sizeof(char) * 2048);
    int status = 1;
    buffer[0] = '\0';
    if (endfile || READ_SIZE <= 0)
        return NULL;
    if (index != 0)
        status = gnl_cat(buffer, read, &index);
    while (status) {
        read = read_n(fd, &size);
        if (read == NULL) {
            endfile = 1;
            return buffer;
        } status = gnl_cat(buffer, read, &index);
        if (size < READ_SIZE && my_strlen(buffer))
            return buffer;
    }
    return buffer;
}
