/*
** EPITECH PROJECT, 2019
** Getnextline
** File description:
** main
*/

#include "get_next_line.h"
#include "my.h"

char *read_reader(int fd, int *size)
{
    char *reader = malloc(sizeof(char) * READ_SIZE + 1);

    if (reader == NULL)
        return NULL;
    (*size) = read(fd, reader, READ_SIZE);
    reader[(*size)] = '\0';
    return reader;
}

int reader_in_buffer(int *index, int *size, char *reader, char *buffer)
{
    int l_buf = my_strlen(buffer);
    int i = 0;

    for (i = 0; reader[i + (*index)] != '\0'; i++) {
        if (reader[i + (*index)] == '\n' || *size == 0) {
            buffer[i + l_buf] = '\0';
            (*index) = i + (*index) + 1;
            (*index) = ((*index) == READ_SIZE) ? 0 : (*index);
            return 1;
        }
        buffer[i + l_buf] = reader[i + (*index)];
    }
    buffer[i + l_buf] = '\0';
    (*index) = 0;
    return 0;
}

char *get_next_line(int fd)
{
    static char *reader;
    static int index = 0;
    char *buffer = malloc(sizeof(char) * 2048);
    static int size = 0;
    int loop = 0;

    buffer[0] = '\0';
    while (loop != 1) {
        if (index == 0)
            reader = read_reader(fd, &size);
        if (size <= 0 || reader == NULL)
            return NULL;
        loop = reader_in_buffer(&index, &size, reader, buffer);
        if (loop != 0 || (size < READ_SIZE && my_strlen(buffer) != 0))
            return buffer;
    }
    free(reader);
    return buffer;
}
