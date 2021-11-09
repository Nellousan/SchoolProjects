/*
** EPITECH PROJECT, 2019
** priority
** File description:
** priority check
*/

int priority(char ch, char **argv)
{
	if (ch == argv[2][2] || ch == argv[2][3])
		return 1;
	if (ch == argv[2][4] || ch == argv[2][5] || ch == argv[2][6])
        return 2;
    return -1;
}
