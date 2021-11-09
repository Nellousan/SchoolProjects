int my_putstr(char *str);
void my_putchar(char c);

int line(int x, int y, char *data)
{
    if (y == 1) {
        for (int i = 1; i <= x; i++) {
            my_putchar(data[4]);
        }
        return 0;
    }
    my_putchar(data[0]);
    for (int i = 1; i <= x - 2; i++)
        my_putchar(data[4]);
    my_putchar(data[1]);        
}

int columns(int x, int y, char *data)
{
    if (x == 1){
        for (int i = 1; i <= y; i++) {
            my_putchar(data[5]);
            if (i != y)
                my_putchar('\n');
            }
        return 0;
    }
    my_putchar('\n');
    for (int i = 1; i <= y - 2; i++) {
        my_putchar(data[5]);
        for (int i2 = 1; i2 <= x - 2; i2++)
            my_putchar(' ');
        if (x > 1)
            my_putchar(data[5]);
        my_putchar('\n');
    }
}

void rush(int x, int y)
{
    char data[7] = "ACACBB";
    if (x <= 0 || y <= 0) {
        my_putstr("Invalid size \n");
        return;
    } else if (x == 1 && y == 1) {
        my_putchar(data[4]);
        return;
    }
    if (x > 1)
        line(x, y, data);
    data[0] = data[2];
    data[1] = data[3];
    if (y > 1)
        columns(x, y, data);
    if (x > 1 && y > 1)
        line(x, y, data);
}
