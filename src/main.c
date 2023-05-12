/*
** EPITECH PROJECT, 2022
** undefined
** File description:
** main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "../lib/my/my.h"

int strcmp(const char *s1, const char *s2)
{
    while (*s1 == *s2) {
        if (*s1 == '\0') {
            return 0;
        }
        s1++;
        s2++;
    }
    return (*s1 < *s2) ? -1 : 1;
}

char* read_command(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    read = getline(&line, &len, stdin);
    if (read == -1) {
        free(line);
        return NULL;
    }
    return line;
}

int execute_command(char* command)
{
    char *argv[] = { "/bin/sh", "-c", command, NULL };
    execve("/bin/sh", argv, NULL);
    perror("execve() a échoué");
    return 84;
}

int run_command(char* command)
{
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork() a échoué");
        return 84;
    }
    if (pid == 0) {
        return execute_command(command);
    }
    int status;
    pid_t wpid = waitpid(pid, &status, 0);
    if (wpid == -1) {
        perror("waitpid() a échoué");
        return 84;
    }
    return 0;
}

int main(void)
{
    char cwd[MAX_PATH_LEN];
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("getcwd() a échoué");
        return 84;
    }
    while (1) {
        my_printf("$> ");
        char* command = read_command();
        if (command == NULL) {
            break;
        }
        if (strcmp(command, "exit\n") == 0) {
            free(command);
            break;
        }
        run_command(command);
        free(command);
    }
    return 0;
}
