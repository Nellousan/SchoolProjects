/*
** EPITECH PROJECT, 2020
** shell cd
** File description:
** a
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include "a_malloc.h"
#include "minishell.h"
#include "my.h"

char **shell_cd_cmd_maker(char *var, char *cwd)
{
    char **cmd = a_malloc(sizeof(char *) * 4);
    cmd[0] = my_strdup("setenv");
    cmd[1] = var;
    cmd[2] = cwd;
    cmd[3] = NULL;
    return cmd;
}

int shell_cd_setenv_pwd_sender(shell_t *shell, char *oldcwd)
{
    char cwd[256];
    char **cmd;
    getcwd(cwd, 256);
    cmd = shell_cd_cmd_maker("OLDPWD", oldcwd);
    shell_setenv(shell, cmd);
    cmd = shell_cd_cmd_maker("PWD", cwd);
    shell_setenv(shell, cmd);
    return 0;
}

int shell_cd_chdir(shell_t *shell, char **oldcwd, char *newcwd)
{
    char cwd[256];
    int status;
    struct stat stats;
    status = stat(newcwd, &stats);
    if (status) {
        my_printf("%s: No such file or directory.\n", newcwd);
        return 1;
    }
    getcwd(cwd, 256);
    status = chdir(newcwd);
    if (status) {
        my_printf("%s: Not a directory.\n", newcwd);
        return 1;
    }
    a_malloc(A_MALLOC_FREE | A_LIST(2));
    (*oldcwd) = my_astrdup(cwd, 2);
    shell_cd_setenv_pwd_sender(shell, (*oldcwd));
    return 0;
}

int shell_cd_change_dir(shell_t *shell, char **cmd)
{
    static char *oldcwd = "";
    if (my_array_size(cmd) == 1) {
        if (env_checkvar(ENVP, "HOME") != -1)
            shell_cd_chdir(shell, &oldcwd, env_getvar(ENVP, "HOME"));
        else
            my_printf("cd: No home directory.\n");
    } else if (!my_strcmp(cmd[1], "-"))
        shell_cd_chdir(shell, &oldcwd, oldcwd);
    else
        shell_cd_chdir(shell, &oldcwd, cmd[1]);
    return 0;
}

int shell_cd(shell_t *shell, char **cmd)
{
    if (my_array_size(cmd) > 2) {
        my_printf("cd: Too many arguments.\n");
        return 1;
    } else
        shell_cd_change_dir(shell, cmd);
    return 0;
}
