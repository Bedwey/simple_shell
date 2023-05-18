#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdarg.h>
#include <errno.h>

int _execute(char *buff, char *argv[], char *env[]);

/* String Manager */
bool char_finder(char c, char *array);
int words_count(char *str, char *separators, unsigned int *p_array);
char **split_string(char *str, char *separators, size_t *word_count);

/* Memmory Manager */
void init_int_array(unsigned int *p_array, size_t size);

#endif
