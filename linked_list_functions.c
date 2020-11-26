#include "functions.h"

/**
 * add_node_at_end - Adds a new node at the end of a linked list.
 * @head: Head.
 * @str: String.
 *
 * Return: Pointer to the new node.
 */
list_t *add_node_at_end(list_t **head, const char *str)
{
	list_t *new, *temp;

	new = malloc(sizeof(list_t));
	if (!new)
		return (NULL);
	temp = *head;
	new->string = _strdup(str);
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
	return (new);
}

/**
 * add_node_env - Adds a new at the end of an environment linked list.
 * @head: Head.
 * @str: String.
 *
 * Return: Pointer to the new node.
 */
env_t *add_node_env(env_t **head, char *str)
{
	env_t *new, *tmp;
	char *first_token, *second_token;

	first_token = strtok(str, "=");
	second_token = strtok(NULL, "\0");
	new = malloc(sizeof(env_t));
	if (!new)
		return (NULL);
	tmp = *head;
	new->token = _strdup(first_token);
	new->value = _strdup(second_token);
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	return (new);
}

/**
 * free_list - Frees a linked list.
 * @head: Head.
 *
 * Return: Nothing.
 */
void free_list(list_t *head)
{

	while (head != NULL)
	{
		free(head->string);
		free(head);
		head = head->next;
	}
}

/**
 * free_list_env - Frees an environment linked list.
 * @head: Head.
 *
 * Return: Nothing.
 */
void free_list_env(env_t *head)
{
	while (head != NULL)
	{
		free(head->token);
		free(head->value);
		free(head);
		head = head->next;
	}
}

/**
 * free_array - Frees an arry of string.
 * @arr: Array of strings.
 *
 * Return: Nothing.
 */
void free_array(char **arr)
{
	int i = 0;

	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
