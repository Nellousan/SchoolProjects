int my_compute_factorial_rec(int nb);
int my_compute_factorial_it(int nb);
void my_putchar(char c);
int my_putnbr(int nb);
int my_putstr(char *str);
int my_compute_power_it(int nb, int p);
int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_is_prime_sup(int nb);

int display_prime(int nb)
{
    for(int i = 0; i <= nb; i++)
    {
        if(my_is_prime(i) == 1)
        {
            my_putnbr(i);
            my_putstr(", ");
        }
    }
}

int main(void)
{
    my_putstr("test factorial it with -10, 0, 5, 13:\n");
    my_putnbr(my_compute_factorial_it(-10));
    my_putchar('\n');
    my_putnbr(my_compute_factorial_it(0));
    my_putchar('\n');
    my_putnbr(my_compute_factorial_it(5));
    my_putchar('\n');
    my_putnbr(my_compute_factorial_it(13));
    my_putchar('\n');
    my_putchar('\n');
    my_putstr("test factorial rec with -10, 0, 5, 13:\n");
    my_putnbr(my_compute_factorial_rec(-10));
    my_putchar('\n');
    my_putnbr(my_compute_factorial_rec(0));
    my_putchar('\n');
    my_putnbr(my_compute_factorial_rec(5));
    my_putchar('\n');
    my_putnbr(my_compute_factorial_rec(13));
    my_putchar('\n');
    my_putchar('\n');
    my_putstr("test pow it with  -5^3, 3^-3, 6^0\n");
    my_putnbr(my_compute_power_it(-5, 3));
    my_putchar('\n');
    my_putnbr(my_compute_power_it(3, -3));
    my_putchar('\n');
    my_putnbr(my_compute_power_it(6, 0));
    my_putchar('\n');
    my_putchar('\n');
    my_putstr("test pow rec with  5^3, 3^-3, 6^0\n");
    my_putnbr(my_compute_power_rec(5, 3));
    my_putchar('\n');
    my_putnbr(my_compute_power_rec(3, -3));
    my_putchar('\n');
    my_putnbr(my_compute_power_rec(6, 0));
    my_putchar('\n');
    my_putchar('\n');
    my_putstr("test sqrt with 2147395600, 0, -4, 36, 27\n");
    my_putnbr(my_compute_square_root(2147395600));
    my_putchar('\n');
    my_putnbr(my_compute_square_root(-4));
    my_putchar('\n');
    my_putnbr(my_compute_square_root(36));
    my_putchar('\n');
    my_putnbr(my_compute_square_root(27));
    my_putchar('\n');
    my_putchar('\n');
    my_putstr("test my_is_prime with 5, 6, -1, 0, 2147483647\n");
    my_putchar('\n');
    my_putnbr(my_is_prime(5));
    my_putchar('\n');
    my_putnbr(my_is_prime(6));
    my_putchar('\n');
    my_putnbr(my_is_prime(-1));
    my_putchar('\n');
    my_putnbr(my_is_prime(0));
    my_putchar('\n');
    my_putnbr(my_is_prime(2147483647));
    my_putchar('\n');
    my_putstr("now displaying every prime number between 0 & 1000:\n");
    display_prime(1000);
    my_putchar('\n');
    my_putstr("test my_is_prime_sup with 14, 0, 1, 2147483646, -10:\n");
    my_putnbr(my_is_prime_sup(14));
    my_putchar('\n');
    my_putnbr(my_is_prime_sup(0));
    my_putchar('\n');
    my_putnbr(my_is_prime_sup(1));
    my_putchar('\n');
    my_putnbr(my_is_prime_sup(2147483646));
    my_putchar('\n');
    my_putnbr(my_is_prime_sup(-10));
    my_putchar('\n');
    my_putchar('\n');
}
