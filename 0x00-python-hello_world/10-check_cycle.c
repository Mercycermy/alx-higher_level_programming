#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle
 * @list: pointer to the head of the list
 * Return: 0 in case of no cycle and 1 at the opposite
 */

int check_cycle(listint_t *list)
{
	listint_t *fast;
	listint_t *slow;

	fast = list;
	slow = list;
	while (list && fast && slow->next)
	{
		list = list->next;
		fast = fast->next->next;

		if (list == fast)
		{
			list = slow;
			slow = fast;
			while (1)
			{
				fast = slow;
				while (fast->next != list && fast->next != slow)
				{
					fast = fast->next;
				}
				if (fast->next == list)
					break;

				list = list->next;
			}
			return (1);
		}
	}

	return (0);
}
