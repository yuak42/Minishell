#include "prompt.h"

void	add_last_node(t_node **head, t_node *node)
{
	t_node *tmp;

	if (!*head)
	{
		*head = node;
		return ;
	}
	tmp = *head;	
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}