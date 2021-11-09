/*
** EPITECH PROJECT, 2020
** ls line
** File description:
** 
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <dirent.h>
#include <grp.h>
#include <pwd.h>
#include "my.h"
#include "my_ls.h"

int my_ls_line_type(unsigned char d_type)
{
    my_printf((d_type == DT_REG) ? "-" : "");
    my_printf((d_type == DT_DIR) ? "d" : "");
    my_printf((d_type == DT_CHR) ? "c" : "");
    my_printf((d_type == DT_BLK) ? "b" : "");
    my_printf((d_type == DT_FIFO) ? "p" : "");
    my_printf((d_type == DT_LNK) ? "l" : "");
    my_printf((d_type == DT_SOCK) ? "s" : "");
    return 0;
}

int my_ls_line_perms(mode_t mode)
{
    my_printf((mode & S_IRUSR) ? "r" : "-");
    my_printf((mode & S_IWUSR) ? "w" : "-");
    my_printf((mode & S_IXUSR) ? "x" : "-");
    my_printf((mode & S_IRGRP) ? "r" : "-");
    my_printf((mode & S_IWGRP) ? "w" : "-");
    my_printf((mode & S_IXGRP) ? "x" : "-");
    my_printf((mode & S_IROTH) ? "r" : "-");
    my_printf((mode & S_IWOTH) ? "w" : "-");
    my_printf((mode & S_IXOTH) ? "x" : "-");
    my_printf(". ");
    return 0;
}

int my_ls_line_user_group(uid_t uid, gid_t gid, struct stat stats)
{
    char *time;
    struct group *grp = getgrgid(gid);
    struct passwd *pwd = getpwuid(uid);
    my_printf("%s %s ", pwd->pw_name, grp->gr_name);
    time = ctime(&stats.st_mtime) + 4;
    time[12] = '\0';
    my_printf("%d\t%s ", stats.st_size, time);
    return 0;
}
