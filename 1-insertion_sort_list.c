#include "sort.h"
/**
 * insertion_sort_list - function that sorts a doubly linked list
 * of integers in ascending order using the Insertion sort algorithm
 * @list: Dobule linked list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node, *j;

	if (list == NULL || !*list || (*list)->next == NULL)
		return;

	node = (*list)->next;
	while (node)
	{
		j = node;
		node = node->next;
		while (j && j->prev)
		{
			if (j->prev->n > j->n)
			{
				swap_node(j->prev, j);
				if (!j->prev)
					*list = j;
				print_list(*list);
			}
			else
				j = j->prev;
		}
	}

}
/**
 *swap_node - swap a node for his previous one
 *@node: node
 *@list: node list
 *Return: return a pointer to a node which was enter it
 */
void swap_node(listint_t *c, listint_t *n)
{
	if (c->prev)
		c->prev->next = n;
	if (n->next)
		n->next->prev = c;
	c->next = n->next;
	n->prev = c->prev;
	c->prev = n;
	n->next = c;
}
