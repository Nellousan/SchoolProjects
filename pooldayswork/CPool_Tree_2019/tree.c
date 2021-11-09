/*
** EPITECH PROJECT, 2019
** firtree
** File description:
** print param_sized tree
*/

void my_putchar(char c);


int print_trunk(int par, int maxw)
{
    int prty = 0;
    if (par % 2 == 0)
        prty = 1;
    for (int i = 1; i <= par; i++)
    {
        for (int i2 = 0; i2 <= ((maxw - par) / 2) + (par / 2) - prty; i2++)
            my_putchar(' ');
        for (int i2 = 0; i2 <= par - 1 + prty; i2++)
            my_putchar('|');
        my_putchar('\n');
    }
}

int print_layer(int layerw, int maxw, int par)
{
    int prty = 0;
    if (par % 2 == 1)
        prty = 1;
    for (int i = 0; i <= ((maxw - layerw + prty) / 2) + ((par / 2) - 1); i++)
        my_putchar(' ');
    for (int i = 0; i <= layerw; i++)
        my_putchar('*');
    my_putchar('\n');
}

int max_width(int par, int maxw)
{
    int parity_control = 0;
    int current_layer_width = 0;
    int layer_width_reduction = 2;
    int layer_amount = 4;
    for (int i = 0; i != par; i++) {
        for (int i2 = 0; i2 != layer_amount; i2++) {
            if (maxw != 0)
                print_layer(current_layer_width, maxw, par);
            current_layer_width += 2;
        }
        if (i % 2 == 0) {
            layer_width_reduction += 2;
            parity_control = 1;
        }
        else
            parity_control = 0;
        current_layer_width -= layer_width_reduction;
        layer_amount++;
    }
    return current_layer_width + parity_control; 
}

void tree(int size)
{
    if (size <= 0)
        return;
    int maxw = 0;
    maxw = max_width(size, maxw);
    max_width(size, maxw);
    print_trunk(size, maxw);
}
