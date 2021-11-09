#include <string.h>

char **my_str_to_word_array(char const *str);

int main (int argc, char **argv)
{
    char *str = strdup("_717hello-world543 -(you--dddd_654bonjour");
    char **tab = my_str_to_word_array(str);
    my_show_word_array(tab);
}
