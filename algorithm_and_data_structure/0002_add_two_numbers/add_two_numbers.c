/*
** LeetCode 2 - Add Two Numbers
** File description:
** Digits are stored least-significant-first so this is just grade
** school addition walking both lists in lockstep with a carry
*/

#include <stdlib.h>
#include "add_two_numbers.h"

list_node_t *add_two_numbers(list_node_t *l1, list_node_t *l2)
{
    list_node_t dummy = {0, NULL};
    list_node_t *tail = &dummy;
    int carry = 0;
    int sum;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        sum = carry;
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }
        carry = sum / 10;
        tail->next = malloc(sizeof(list_node_t));
        tail->next->val = sum % 10;
        tail->next->next = NULL;
        tail = tail->next;
    }
    return (dummy.next);
}
