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

extern char **environ;

void handle_builtin(char **args, size_t count);
bool _file_finder(char *args[], struct stat statbuf, int args_count);
int _execute(char *args[], char *envp[]);

/* String Manager */
int _strlen(char *s);
bool char_finder(char c, char *array);
int words_count(char *str, char *separators, unsigned int *p_array);
char **split_string(char *str, char *separators, size_t *word_count);

/* String Manager 2 */
char *_concat(int count, ...);
int _strncmp(char *s1, char *s2, int n);

/* Memmory Manager */
void init_int_array(unsigned int *p_array, size_t size);
void free_string_array(char **array, int len);

/* Environment Manager */
char *_getenv(char *key);

/* File Checker */
bool _file_status(char *pathname, struct stat *statbuf);
char *_file_path(char *filename, struct stat *statbuf);

/* Custom Handler */
void handle_exit(char **exit_args, size_t count);

/* Converter */
int _atoi(char *s);

#endif
