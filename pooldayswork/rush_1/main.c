int my_putstr(char const *str);
void rush(int x, int y);
void my_putchar(char c);

int main(void)
{
    my_putstr("\n\ntesting rush with 5,6\n");
    rush(5, 6);
    my_putstr("\n\ntesting rush with 8,3\n");
    rush(8, 3);
    my_putstr("\n\ntesting rush with 2, 10\n");
    rush(2, 10);
    my_putstr("\n\ntesting rush with 15, 1\n");
    rush(15, 1);
    my_putstr("\n\ntesting rush with 1, 5\n");
    rush(1, 5);
    my_putstr("\n\ntesting rush with 20, 2\n");
    rush(20, 2);
    my_putstr("\n\ntesting rush with 1, 1\n");
    rush(1, 1);
    my_putstr("\n\ntesting rush with 2, 2\n");
    rush(2, 2);
    
}
