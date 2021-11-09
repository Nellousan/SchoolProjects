/*
** EPITECH PROJECT, 2019
** bistro header
** File description:
**
*/

#ifndef BISTRO_H
#define BISTRO_H
#define DEC(chara) ((chara) - ('0'))
#define SYNTAX_ERROR_MSG "syntax error"
#define ERROR_MSG "error"

char *disp_result(char **argv, char *expr);

/************* BASE CONVERTER ***************/

int get_base_number(char digit, char *nb_base);
void res_increment(char *res, char *res_base, int increment);
char *convert_base(char *nb, char *nb_base, char *res_base, char *sym_base);

/*************** INFINOPS *******************/

char *infinadd(char *nb1, char *nb2);
char *infinsub(char *nb1, char *nb2, int neg);
char *infindiv(char *nb1, char *nb2, int mod);

/**************** SEND OPS ******************/

char *send_add(char *nb1, char *nb2);
char *send_sub(char *nb1, char *nb2);
char *send_div(char *nb1, char *nb2, int mod);

/***************** MISC. ********************/

char *len_equalize(char *str1, char *str2);
void fill_res(char *res, char *res_base);
void add_end(char *res, char *res_base);
void fill_zero(char *str);
void rm_zero(char *str);
int is_higher(char *nb1, char *nb2);
int is_higher_sp(char *nb1, char *nb2);
int char_to_int(char *str);
char *int_to_char(int nb);

/************** SYNTAX CHECK ****************/

void fill_bzero(char *str, int size);
int check_char_base(char c, char *base);
int base_validity_check(char *nb_base, char *sym_base);
int check_expr_base(char *expr, char **argv);
int syntax_check(int argc, char **argv, char *expr);

/*********** EVALEXPR (TEMP) ****************/

int is_charbase(char c, char *nb_base);
char *number(char **str, char *sym_base, char *nb_base);
char *summands(char **str, char *sym_base, char *nb_base);
char *factors(char **str, char *sym_base, char *nb_base);
char *eval_expr(char *expr, char *sym_base, char *nb_base);

/********************************************/

#endif
