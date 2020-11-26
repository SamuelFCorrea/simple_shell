#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

/**
 * struct string_list - Singly linked list.
 * @string: String.
 * @next: Pointer to the next node in the linked list.
 *
 * Description: Singly linked list.
 */
typedef struct string_list
{
	char *string;
	struct string_list *next;
} list_t;

/**
 * struct env_list - Singly linked list
 * @token: String tokenized.
 * @value: Value of the tokenized string.
 * @next: Pointer to the next node in the linked list.
 *
 * Description: Singly linked list.
 */
typedef struct env_list
{
	char *token;
	char *value;
	struct env_list *next;

} env_t;

int _strlen(const char *s);
int _strcmp(const char *s1, const char *s2);
char *_strdup(const char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);

extern char **environ;
char **get_argv(char *input);
char *get_commands(void);
char *get_env(const char *name);
char **handle_path(char *commands);

list_t *add_node_at_end(list_t **head, const char *str);
env_t *add_node_env(env_t **head, char *str);

void free_list(list_t *head);
void free_list_env(env_t *head);
void free_array(char **arr);
void execute_builtin(char **vector);

#endif
