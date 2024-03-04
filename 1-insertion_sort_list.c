#include "sort.h"
/**
 * insertion_sort_list - function that sorts a doubly linked list
 * of integers in ascending order using the Insertion sort algorithm
 * @list: Dobule linked list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node;

	if (list == NULL || (*list)->next == NULL)
		return;

}
/**
 *swap_node - swap a node for his previous one
 *@node: node
 *@list: node list
 *Return: return a pointer to a node which was enter it
 */
void swap_node(listint_t *c, listint_t *n)
{
	n->next = c;
	if (n->next)
		n->next->prev = c;
	c->next = n->next;
	n->prev = c->prev;
	c->prev = n;
	if (c->prev)
		c->prev->next = n;
	else
		*list = current;
	return (current);
}
