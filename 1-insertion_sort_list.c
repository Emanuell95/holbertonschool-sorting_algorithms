#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to the head of the list
 * @node1: The first node to swap
 * @node2: The second node to swap
 *
 * Description: This function updates the pointers of the surrounding nodes
 * to swap the position of node1 and node2 in the list.
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
    if (node1->prev)
        node1->prev->next = node2;
    if (node2->next)
        node2->next->prev = node1;

    node1->next = node2->next;
    node2->prev = node1->prev;

    node2->next = node1;
    node1->prev = node2;

    if (!node2->prev)
        *list = node2; /* Update head of the list */
}

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order
 *                       using the Insertion sort algorithm
 * @list: Double pointer to the head of the list
 *
 * Description: This function iterates through the list and swaps nodes
 * to sort them in ascending order. The list is printed after each swap.
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *temp;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    current = (*list)->next;

    while (current)
    {
        temp = current;

        /* Compare and swap with previous nodes if necessary */
        while (temp->prev && temp->n < temp->prev->n)
        {
            swap_nodes(list, temp->prev, temp);
            print_list(*list); /* Print list after each swap */
        }

        current = current->next;
    }
}
