/*
** EPITECH PROJECT, 2020
** minishell header
** File description:
** a
*/

#ifndef MINISHELL_H
#define MINISHELL_H

/************* DEFINES ****************/

#define CMD shell->cmd
#define ENV shell->env
#define ENVP shell->env->envp
#define PATH shell->path
#define EXIT shell->exit_status

#define UNUSED __attribute__((unused))

#define SIGFPEMSG "Floating exception"

/************* STRUCTS ****************/

typedef struct shell shell_t;

typedef struct cmd {
    char *cmd;
    int (*fptr)(shell_t *shell, char **cmd);
}cmd_t;

typedef struct env {
    char **envp;
    char *user;
    char *hostname;
    char *prompt_str;
}env_t;

typedef struct shell {
    env_t *env;
    cmd_t **cmd;
    char **path;
    int exit_status;
}shell_t;

/************** LOAD ******************/

shell_t *shell_load(char **envp);
env_t *env_load(char **envp);
cmd_t **cmd_load(void);
char **path_load(char **envp);

/*************** MISC. ****************/

char *shell_strcat(char *str1, char *str2);
char *copy_until(char **str, char c);
char *env_getvar(char **envp, char *var);
int env_checkvar(char **envp, char *var);
int get_occurences(char *str, char c);
int is_alphanum(char *str);

/*************** SHELL ****************/

int shell_cmd(shell_t *shell, char **cmd);
int shell_prompt(shell_t *shell);

/*************** CMDs *****************/

int shell_exit(shell_t *shell, char **cmd);
int shell_env(shell_t *shell, char **cmd);
int shell_setenv(shell_t *shell, char **cmd);
int shell_unsetenv(shell_t *shell, char **cmd);
int shell_cd(shell_t *shell, char **cmd);
int shell_exec(shell_t *shell, char **cmd);

/**************************************/

#endif
