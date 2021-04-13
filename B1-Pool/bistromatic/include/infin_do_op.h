/*
** EPITECH PROJECT, 2020
** infin_do_op
** File description:
** .h
*/

#ifndef INFIN_DO_OP
#define INFIN_DO_OP

char *infin_do_op_setup(char *exp1, char *exp2, char op);
char *infin_do_op(char **exptab, int sign_exp1, int sign_exp2);
char *infinadd(char **exptab, int sign_exp1, int sign_exp2);
char *infinsub(char **exptab, int sign_exp1, int sign_exp2);
char *infinmul(char **exptab, int sign_exp1, int sign_exp2);
char *infindiv(char **exptab, int sign_exp1, int sign_exp2);
char *initialise_result(char *result, int len_nb);
char *my_strncpyspe(char *dest, char *src, int n);
int verifsign(char *str);

#endif /* INFIN_DO_OP */