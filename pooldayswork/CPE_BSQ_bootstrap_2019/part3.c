/*
** EPITECH PROJECT, 2019
** bsq bootstrap part 3
** File description:
** 
*/

char *mem_alloc(char const *a, char const *b)
{
    char *buffer = malloc(sizeof(char) * (my_strlen(a) + my_strlen(b)) + 1);
    int i = 0;
    for (; a[i] != '\0'; i++)
        buffer[i] = a[i];
    for (int j = 0; b[j] != '\0'; i++, j++)
        buffer[i] = b[j];
    return buffer;
}

char **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    char **buffer = malloc(sizeof(char *) * nb_rows);
    for (int i = 0; i < nb_rows; i++)
        buffer[i] = malloc(sizeof(char) * nb_cols);
    return buffer;
}

char **mem_dup_2d_array(char **arr, int nb_rows, int nb_cols)
{
    char **buffer = mem_alloc_2d_array(nb_rows, nb_cols);
    for (int i = 0; i < nb_rows; i++)
        for (int j = 0; j < nb_cols; j++)
            buffer[i][j] = arr[i][j];
    return buffer;
}
