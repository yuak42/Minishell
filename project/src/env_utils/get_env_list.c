#include "prompt.h"


static char	*get_key(char *env);
static char	*get_value(char *env);

t_env	*get_env_list(char **env)
{
	t_env	*head;
	t_env	*ev_node;
	t_env	*last;

	head = NULL;
	while (*env)
	{
		ev_node = (t_env *) malloc(sizeof(t_env)); // add error check later
		ev_node->key = get_key(*env);
		ev_node->value = get_value(*env);
		ev_node->next = NULL;
		if (head == NULL)
		{
			head = ev_node;
			head->prev = NULL;
			last = ev_node;
		}
		else
		{
			last->next = ev_node;
			ev_node->prev = last;
			last = last->next;
		}
		env++;
	}
	return (head);
}

static char	*get_key(char *env)
{
	// '=' e kadar olan kısmı kopyalayacak
	char	*str;
	char	*key;
	size_t	i;

	str = env;
	i = 0;
	while (str[i] != '=')
		i++;
	key = (char *) malloc(sizeof(char) * (i + 1)); // add error check later
	i = 0;
	while (str[i] != '=') //buralara belki string sonu kosulu eklenebilir sonra
	{
		key[i] = str[i];
		i++;
	}
	key[i] = '\0';
	return key;
}

static char	*get_value(char *env)
{
	// '=' den sona kadar olan kısmı kopyalayacak
	char	*str;
	char	*value;
	size_t	i;

	str = env;
	i = 0;
	while (*str != '=')
		str++;
	str++;
	while (str[i])
		i++;
	value = (char *) malloc(sizeof(char) * (i + 1)); // add error check later
	i = 0;
	while (str[i])
	{
		value[i] = str[i];
		i++;
	}
	value[i] = '\0';
	return value;
}