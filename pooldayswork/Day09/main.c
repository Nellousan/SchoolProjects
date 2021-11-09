#include <stdlib.h>
#include "my_macro_abs.h"
#include "my.h"

struct info_param
{
    int length;
    char *str;
    char *copy;
    char **word_array;
};

struct info_param *my_params_to_array(int ac, char **av);

int main(int argc, char **argv)
{
    //struct info_param *param_struct = my_params_to_array(argc, argv);
    //my_show_param_array(param_struct);
    my_putnbr(get_color(255, 255, 255));
}
